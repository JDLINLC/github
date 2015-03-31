#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;

const int N = 50000 + 1;
const int WORDWIDTH = 256;

struct trie
{
  int count;
  bool is_wordend;
  struct trie * next[WORDWIDTH];
};

int n = 0, T = 0, result = 0;
// root node
struct trie root = {0, false, NULL};

int init();
int input();
int countword(struct trie * node);
int output();

int buildtree(char *str);
void deletetree(struct trie * node);
int printtree(struct trie * node);

int main(void)
{
	cin>>T;
	for(int t = 0; t != T; t++)
	{
		cin>>n;
		for(int i = 0; i != n; i++)
		{
		    char str[30];
		    cin>>str;
		    buildtree(str);
		}
		output();
		init();
	}
	
	return 0;
}

int init()
{
	struct trie *curr = &root;
	
	for(int i = 0; i != WORDWIDTH; i++)
	    if(curr->next[i] != NULL)
	    {
		deletetree(curr->next[i]);
		curr->next[i] = NULL;
	    }
	curr->count = 0;
	result = 0;
	
	return 0;
}

int input()
{
	for(int i = 0; i != n; i++);
	return 0;
}

int buildtree(char *str)
{
	if(str[0] == '\0')
	    return 0;
	
	struct trie *curr = &root;
	struct trie *newnode;
	
	for(int i = 0; ; i++)
	{
	    //cout<<"test"<<i+1<<endl;
	    curr->count++;
	    if(curr->next[str[i]]==NULL)
	    {
		// add new node
		newnode = (struct trie*)malloc(sizeof(struct trie));
		memset(newnode, 0, sizeof(struct trie));
		curr->next[str[i]] = newnode;
	    }
	    // curr->next[str[i]]->letter = str[i];
	    curr = curr->next[str[i]];
	    
	    if(str[i+1] == '\0')
	    {
		curr->is_wordend = true;
		curr->count++;
		return 0;
	    }
	}
	return 0;
}


void deletetree(struct trie * node)
{
	for(int i = 0; i != WORDWIDTH; i++)
	{
	    if(node->next[i])
	    {
		deletetree(node->next[i]);
		node->next[i] = NULL;
	    }
	}
	delete node;
	return;
}

int printtree(struct trie * node)
{
  
	return 0;
}

int countword(struct trie * node)
{
	for(int i = 0; i != WORDWIDTH; i++)
	{
	    if(node->next[i])
		countword(node->next[i]);
	}
	if(node->is_wordend)
	    result += (node->count)-1;
	return 0;
}

int output()
{
	countword(&root);
	cout<<(result%11519)<<endl;
	return 0;
}