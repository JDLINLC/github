package com.ybook.app.ui.search

import android.widget.Adapter
import android.widget.AdapterView
import android.view.View
import com.ybook.app.net.PostHelper
import com.ybook.app.net.SearchRequest
import com.ybook.app.bean
import android.widget.ListView
import android.widget.AdapterView.OnItemClickListener
import com.ybook.app.util.BooksListUtil
import java.util.ArrayList
import com.ybook.app.bean.SearchResponse
import com.umeng.analytics.MobclickAgent
import android.util.Log
import android.os.Handler
import android.os.Message
import com.ybook.app.net
import android.content.Context
import android.widget.BaseAdapter
import android.view.ViewGroup
import android.view.LayoutInflater
import com.ybook.app.R
import com.ybook.app.id
import android.widget.TextView
import android.widget.ImageView
import com.squareup.picasso.Picasso
import com.ybook.app.bean.BookItem
import com.ybook.app
import android.widget.Toast
import android.app.ProgressDialog
import com.ybook.app.net.DetailRequest
import com.ybook.app.bean.DetailResponse
import android.view.MenuItem
import android.os.Bundle
import android.app.SearchManager
import android.content.Intent
import com.ybook.app.ui.BookDetailActivity
import java.io.Serializable
import com.ybook.app.util.ListEndToLoadUtil
import com.ybook.app.ui.search.SearchView.MessageType
import android.support.v7.widget.RecyclerView
import com.ybook.app.bean.SearchResponse.SearchObject
import android.view.animation.Animation
import android.view.animation.AnimationUtils
import android.view.Window
import android.provider.SearchRecentSuggestions
import com.ybook.app.data.SearchSuggestionProvider

/**
 * Created by Carlos on 2014/12/17.
 */
public class SearchPresenterImpl(val searchView: SearchView) : SearchPresenter, RecyclerView.OnScrollListener() {

    val SEARCH_BY_KEY = "key"
    val TAG = "SearchAct"
    val mUtil = BooksListUtil.getInstance(searchView)
    var mSearchStatus: SearchStatus? = null


    override fun getAdapter() = mRecyclerAdapter

    override fun onCreate(savedInstanceState: Bundle?) {
        searchView.getSupportActionBar() setDisplayShowTitleEnabled true
        searchView.getSupportActionBar() setDisplayHomeAsUpEnabled  true
        handleIntent(searchView.getIntent())
    }


    private fun handleIntent(intent: Intent) {
        mSearchStatus = SearchStatus(intent.getStringExtra(SearchManager.QUERY))
        val suggestions = SearchRecentSuggestions(searchView, SearchSuggestionProvider.AUTHORITY, SearchSuggestionProvider.MODE)
        suggestions.saveRecentQuery(mSearchStatus!!.key, null);
        searchView.setTitle(mSearchStatus!!.key)
        onScrollEnd()
    }

    private class SearchStatus(val key: String) {
        public val listItems: ArrayList<SearchResponse.SearchObject> = ArrayList()
        public var requestedPage: Int = -1
        public var nextPage: Int = 0
        public var previousTotal: Int = 0
        public var isLoading: Boolean = true

        public var visibleThreshold: Int = 5
        public var firstVisibleItem: Int = 0
        public var visibleItemCount: Int = 0
        public var totalItemCount: Int = 0
    }

    override fun onNewIntent(intent: Intent) {
        handleIntent(intent)
    }


    override fun onOptionsItemSelected(item: MenuItem?): Boolean {
        when (item?.getItemId()) {
            android.R.id.home -> searchView.onBackPressed()
        }
        return true
    }

    override fun onResume() {
        MobclickAgent.onResume(searchView);
    }

    override fun onPause() {
        MobclickAgent.onPause(searchView);
    }

    override fun onClick(v: View) {
        when (v.getId() ) {
            R.id.bookMarkBtn -> {
                val item = v.getTag() as SearchObject
                if (item.isMarked(mUtil)) {
                    BookItem.cancelMarked(mUtil, item)
                    (v as ImageView).setImageResource(R.drawable.ic_mark)
                    MobclickAgent.onEvent(searchView, app.util.EVENT_DELETE_FROM_SEARCH)
                    Toast.makeText(searchView, searchView getString R.string.toastCancelMark, Toast.LENGTH_SHORT).show()
                } else {
                    MobclickAgent.onEvent(searchView, app.util.EVENT_ADD_FROM_SEARCH)
                    val dialog = ProgressDialog(searchView)
                    dialog.setMessage(searchView getString R.string.loadingMessage)
                    dialog.setIndeterminate(true)
                    dialog.setCancelable(false)
                    dialog.show()
                    PostHelper.detail(DetailRequest(item.id, item.idType, bean.getLibCode()), object : Handler() {
                        override fun handleMessage(msg: Message) {
                            dialog.dismiss()
                            when (msg.what) {
                                net.MSG_SUCCESS -> {
                                    val book = (msg.obj as DetailResponse).toBookItem()
                                    book.markOrCancelMarked(mUtil)
                                    (v as ImageView).setImageResource(R.drawable.ic_marked)
                                    searchView.showMessage(searchView.getString(R.string.toastMarked), MessageType.INFO)
                                }
                                net.MSG_ERROR -> searchView.showMessage(searchView.getString(R.string.collectFailErrorHint) + item.title, MessageType.INFO)
                            }
                        }
                    })
                }
            }
            R.id.card_view -> searchView.startActivity(Intent(searchView, javaClass<BookDetailActivity>()).putExtra(BookDetailActivity.INTENT_SEARCH_OBJECT, v.getTag() as Serializable))
        }
    }

    fun setOnScrollEndListener() {

    }

    override fun onScrolled(recyclerView: RecyclerView, dx: Int, dy: Int) {
        mSearchStatus!!.visibleItemCount = recyclerView.getChildCount()
        mSearchStatus!!.totalItemCount = searchView.getLayoutManager().getItemCount()
        mSearchStatus!!.firstVisibleItem = searchView.getLayoutManager().findFirstVisibleItemPosition()
        if (mSearchStatus!!.isLoading) {
            if (mSearchStatus!!.totalItemCount > mSearchStatus!!.previousTotal) {
                mSearchStatus!!.isLoading = false;
                mSearchStatus!!.previousTotal = mSearchStatus!!.totalItemCount;
            }
        }
        if (!mSearchStatus!!.isLoading && (mSearchStatus!!.totalItemCount - mSearchStatus!!.visibleItemCount) <= (mSearchStatus!!.firstVisibleItem + mSearchStatus!!.visibleThreshold)) onScrollEnd()
    }

    fun onScrollEnd() {
        if (mSearchStatus!!.nextPage > mSearchStatus!!.requestedPage && mSearchStatus!!.nextPage * 10 == mSearchStatus!!.listItems.size()) {
            PostHelper.search(SearchRequest(mSearchStatus!!.key, mSearchStatus!!.nextPage, SEARCH_BY_KEY, bean.getLibCode()), mHandler)
            mSearchStatus!!.requestedPage++
            mSearchStatus!!.isLoading = true
            searchView.showLoadPageMessage(mSearchStatus!!.nextPage)
        }
    }

    private val mHandler = object : Handler() {
        override fun handleMessage(msg: Message) {
            when (msg.what) {
                net.MSG_SUCCESS -> {
                    val r = msg.obj as SearchResponse
                    mSearchStatus!!.listItems addAll r.objects
                    mSearchStatus!!.nextPage++
                    mRecyclerAdapter.notifyDataSetChanged()
                    if ((mSearchStatus!!.totalItemCount - mSearchStatus!!.visibleItemCount) <= (mSearchStatus!!.firstVisibleItem + mSearchStatus!!.visibleThreshold)) {
                        searchView.scrollTo(mSearchStatus!!.listItems.size() - r.objects.size() + 1)
                    }
                }
                net.MSG_ERROR -> searchView.showLoadErrorMessage()
                else -> searchView.showUnknownMessage()
            }
            mSearchStatus!!.isLoading = false;
        }
    }

    private val mRecyclerAdapter = object : RecyclerView.Adapter<SearchViewHolder>() {
        var lastPosition: Int = -1


        override fun onCreateViewHolder(parent: ViewGroup?, p1: Int): SearchViewHolder? {
            val holder = SearchViewHolder(LayoutInflater.from(parent?.getContext()).inflate(R.layout.search_result_item, parent, false))
            holder.view setOnClickListener this@SearchPresenterImpl
            holder.markBtn setOnClickListener this@SearchPresenterImpl
            return holder
        }

        var oldPaddingTop: Int? = null
        override fun onBindViewHolder(holder: SearchViewHolder, position: Int) {
            val item = mSearchStatus!!.listItems[position]
            holder.titleText setText item.title
            holder.idText setText item.id
            holder.authorText setText item.author
            holder.pressText setText item.press
            Picasso.with(searchView) load item.coverImgUrl error (searchView.getResources().getDrawable(R.drawable.ic_error)) into holder.coverImage

            holder.view setTag item
            holder.markBtn setTag item
            holder.markBtn setImageResource(if (item isMarked mUtil) R.drawable.ic_marked else R.drawable.ic_mark)
            //            setAnimation(holder.view, position)
            //            if (oldPaddingTop == null) {
            //                oldPaddingTop = holder.view.getPaddingTop()
            //            }
            //            if (position == 0) {
            //                holder.view.setPadding(holder.view.getPaddingLeft(), holder.view.getPaddingTop() + searchView.getSupportActionBar().getHeight(), holder.view.getPaddingRight(), holder.view.getPaddingBottom())
            //            } else holder.view.setPadding(holder.view.getPaddingLeft(), oldPaddingTop!!, holder.view.getPaddingRight(), holder.view.getPaddingBottom())
        }

        override fun getItemCount(): Int = mSearchStatus!!.listItems.size


        private fun setAnimation(viewToAnimate: View, position: Int) {
            // If the bound view wasn't previously displayed on screen, it's animated
            if (position > lastPosition) {
                val animation = AnimationUtils.loadAnimation(viewToAnimate.getContext(), android.R.anim.slide_in_left);
                viewToAnimate.startAnimation(animation);
                lastPosition = position;
            }
        }
    }

}

public class SearchViewHolder(val view: View) : RecyclerView.ViewHolder(view) {
    val titleText = (view id R.id.text_view_book_title) as TextView
    val idText = (view id R.id.text_view_book_query_id) as TextView
    val authorText = (view id R.id.text_view_book_author) as TextView
    val pressText = (view id R.id.text_view_book_publisher) as TextView
    val markBtn = (view id R.id.bookMarkBtn)  as ImageView
    val coverImage = (view id R.id.image_view_book_cover) as ImageView
}