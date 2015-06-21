/*  this is a contacts manage system
    contacts data was saved in file "d:\Codes\C\contact_data.bin"
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define STARS "***************************"
#define QUIT 0
struct contact_tab{                             /*创建联系人的数据存储结构类型，并将结构类型命名为 contact_tab*/
    char name[20];
    char address[20];
    char phone[20];
    char email[20];
    struct contact_tab *next;
};
typedef struct contact_tab contact_tab;
int menu(void);                                 /*创建开始菜单，其中有10个选项，1到9分别对应9个功能，0为退出*/
void input_contacts(contact_tab **headp);       /*从键盘输入联系人信息，用链表存储，接受指向链表头指针head的二维指针headp为参数*/
void output_contacts(contact_tab **headp);      /*从文件中读取联系人信息并存储到链表中，接受指向链表头指针head的二维指针headp为参数*/
void save_contacts(contact_tab *head);          /*将链表中的联系人信息存储到文件中去，传入链表头指针head为参数*/
void change_one_contact(contact_tab **headp);   /*改变某一个联系人的某一项信息，传入指向链表头指针head的二维指针headp为参数*/
void insert_one_contact(contact_tab **headp);   /*插入一个联系人信息都链表的最后，传入指向链表头指针head的二维指针headp为参数*/
void delete_one_contact(contact_tab **headp);   /*删除一个联系人信息，传入指向链表头指针head的二维指针headp为参数*/
void print_contacts(void);                      /*将文件中的联系人信息全部打印出来*/
int find_one_contact(char *name);               /*通过联系人名字按二分查找找到联系人并打印出联系人的信息*/
void sort_contacts(contact_tab **headp);        /*按联系人名字升序进行排列，传入指向链表头指针head的二维指针headp为参数*/
int main(void)
{
    char name[20];
    int code,state=0;
    contact_tab *head,**headp=&head;                       /*声明contact_tab的头指针head和指向链表头指针head的二维指针headp，并将头指针赋值为NULL*/
    head=NULL;

    while((code=menu())!=QUIT)
    {
        switch(code)                                      /*1到9分别对应9个功能，0是退出*/
        {
        case 1: input_contacts(headp);
                printf("Succeed input!\n");
                break;
        case 2: output_contacts(headp);
                printf("Succeed output!\n");
                break;
        case 3: if(head==NULL)
                {
                    printf("No change to save!\n");
                    break;
                }
                save_contacts(head);
                printf("Succeed Saved!\n");
                break;
        case 4: if(head==NULL)
                {
                    printf("Please input contacts or output contacts first!\n");
                    break;
                }
                sort_contacts(headp);
                change_one_contact(headp);
                state=0;
                break;
        case 5: if(head==NULL)
                {
                    printf("Please input contacts or output contacts first!\n");
                    break;
                }
                insert_one_contact(headp);
                state=0;
                break;
        case 6: if(head==NULL)
                {
                    printf("Please input contacts or output contacts first!\n");
                    break;
                }
                delete_one_contact(headp);
                break;
        case 7: if(head==NULL)
                {
                    printf("Please input contacts or output contacts first!\n");
                    break;
                }
                print_contacts();
                break;
        case 8: if(head==NULL)
                {
                    printf("Please input contacts or output contacts first!\n");
                    break;
                }
                if(state==0)
                {
                    printf("Please sort contacts first!\n");
                    break;
                }
                printf("Please input the contact name that you want to find!\n");
                scanf("%s",name);
                find_one_contact(name);
                break;
        case 9: if(head==NULL)
                {
                    printf("Please input contacts or output contacts first!\n");
                    break;
                }
                sort_contacts(headp);
                state=1;
                printf("Succeed sorted!\n");
                break;
        default:
            break;
        }
    }
    printf("Goodbye!\n");
    return 0;
}
void output_contacts(contact_tab **headp)       /*从文件中读取联系人信息并存储到链表中*/
{
    FILE *fp;
    if((fp=fopen("d:\\Codes\\C\\contact_data.bin","rb+"))==NULL)
        exit(-1);
    contact_tab a,*head,*current,*prior;
    head=NULL;
    while(!feof(fp))
    {
        fread(&a,sizeof(contact_tab),1,fp);
        if(!feof(fp))
        {
            if(head==NULL)
            {
                head=(contact_tab *)malloc(sizeof(contact_tab));
                current=head;
            }
            strcpy(current->name,a.name);
            strcpy(current->address,a.address);
            strcpy(current->phone,a.phone);
            strcpy(current->email,a.email);
            current->next=(contact_tab *)malloc(sizeof(contact_tab));
            prior=current;
            current=current->next;
        }
    }
    prior->next=NULL;
    *headp=head;
    fclose(fp);
}
int menu(void)                      /*开始菜单*/
{
    int code,status;
    printf("%s%s\n",STARS,STARS);
    printf("input the number of the desired action:\n");
    printf("1)Input contacts    \t2)Output contacts\n");
    printf("3)Save contacts     \t4)Change one contact\n");
    printf("5)Insert one contact\t6)Delete one contact\n");
    printf("7)Print all contacts\t8)Find one contact\n");
    printf("9)Sort contacts     \t0)Quit\n");
    printf("%s%s\n",STARS,STARS);
    while((status=scanf("%d",&code))!=1||(code<0||code>9))
    {
        if(status!=1)
            scanf("%*s");
        printf("Enter an integer from 0 to 9,please.\n");
    }
    return code;
}
void delete_one_contact(contact_tab **headp)       /*删除一个联系人信息*/
{
    int state=0;
    contact_tab *head,*current,*prior;
    //output_contacts(headp);
    head=*headp;
    current=head;
    prior=current;
    char name[20];
    printf("input the name that you want to delete!\n");
    scanf("%s",name);
    while(current)
    {        if(strcmp(current->name,name)==0)
        {
            if(current==head)
            {
                head=current->next;
            }
            prior->next=current->next;
            printf("Succeed delete!\n");
            state=1;
            free(current);
            break;
        }
        else
        {
            prior=current;
            current=current->next;
        }
    }
    if(state==0)
        printf("Fail to delete!\n");
    *headp=head;
    head=*headp;
   // sort_contacts(headp);
    save_contacts(head);

}
void insert_one_contact(contact_tab **headp)            /*插入一个联系人信息都链表的最后*/
{
    contact_tab a,*head,*current,*prior;
   // output_contacts(headp);
    head=*headp;
    current=head;
    while(current)
    {
        prior=current;
        current=current->next;
    }
    prior->next=(contact_tab *)malloc(sizeof(contact_tab));
    prior->next->next=NULL;
    printf("input name address phone and email that you want to add!\n");
    scanf("%s%s%s%s",prior->next->name,prior->next->address,prior->next->phone,prior->next->email);
    printf("Succeed!\n");
    *headp=head;
    head=*headp;
   // sort_contacts(headp);
    save_contacts(head);
}
void input_contacts(contact_tab **headp)        /*初始化联系人信息列表*/
{
    int x=-1;
    contact_tab *current,*head,*prior;
    head=NULL;
    while(x)
    {
        if(head==NULL)
        {
            head=(contact_tab *)malloc(sizeof(contact_tab));
            current=head;
        }
        printf("input name address phone and email!\n");
        scanf("%s%s%s%s",current->name,current->address,current->phone,current->email);
        current->next=(contact_tab *)malloc(sizeof(contact_tab));
        prior=current;
        current=current->next;
        printf("input any number to continue(0 to quit):\n");
        scanf("%d",&x);
    }
    prior->next=NULL;
    *headp=head;
}
void save_contacts(contact_tab *head)                   /*将联系人信息存盘*/
{
    FILE *out;
    if((out=fopen("d:\\Codes\\C\\contact_data.bin","wb+"))==NULL)
        exit(-1);
    contact_tab a,*current;
    current=head;
    while(current)
    {
        strcpy(a.name,current->name);
        strcpy(a.address,current->address);
        strcpy(a.phone,current->phone);
        strcpy(a.email,current->email);
        fwrite(&a,sizeof(contact_tab),1,out);
        current=current->next;
    }
    fclose(out);
}
void print_contacts(void)                           /*将文件中的联系人信息全部打印出来*/
{
    FILE *in;
    char name[20]="name",address[20]="address",phone[20]="phone",email[20]="email";
    if((in=fopen("d:\\Codes\\C\\contact_data.bin","rb+"))==NULL)
        exit(-1);
    contact_tab a;
    printf("%-18s%-18s%-18s%-18s\n",name,address,phone,email);
    while(!feof(in))
    {
        fread(&a,sizeof(contact_tab),1,in);
        if(!feof(in))
        {
            printf("%-18s%-18s%-18s%-18s\n",a.name,a.address,a.phone,a.email);
        }
    }
    fclose(in);
}
void sort_contacts(contact_tab **headp)             /*通过链表进行排序*/
{                                                   /*并将结果存盘*/
    contact_tab *current,*p1,*p2,*head,a;
    int i=0,j=0,len=0;
    head=*headp;
    current=head;
    while(current)
    {
        len++;
        current=current->next;
    }
    for(i=0,p1=head;i<len-1;i++,p1=p1->next)
        for(j=i+1,p2=p1->next;j<len;j++,p2=p2->next)
            if(strcmp(p1->name,p2->name)>0)
            {
                strcpy(a.name,p1->name);
                strcpy(a.address,p1->address);
                strcpy(a.phone,p1->phone);
                strcpy(a.email,p1->email);
                strcpy(p1->name,p2->name);
                strcpy(p1->address,p2->address);
                strcpy(p1->phone,p2->phone);
                strcpy(p1->email,p2->email);
                strcpy(p2->name,a.name);
                strcpy(p2->address,a.address);
                strcpy(p2->phone,a.phone);
                strcpy(p2->email,a.email);
            }
    *headp=head;
    head=*headp;
    save_contacts(head);
}
void change_one_contact(contact_tab **headp)                /*先用find_one_contact()找到联系人*/
{                                                           /*再对联系人进行修改并存盘*/
    FILE *fp;
    fpos_t pos,*ptr=&pos;
    int num,code,status;
    char name1[20];
    contact_tab a;
    printf("Please input the contact name that you want to change!\n");
    scanf("%s",name1);
    num=find_one_contact(name1);
    if((fp=fopen("d:\\Codes\\C\\contact_data.bin","rb+"))==NULL)
        exit(-1);
    if(num>=0)
    {
        fseek(fp,num*sizeof(contact_tab),SEEK_SET);
        fgetpos(fp,ptr);
        fread(&a,sizeof(contact_tab),1,fp);
        printf("%s\n",STARS);
        printf("input the number of content\nyou want to change!\n");
        printf("1)name    2)address\n");
        printf("3)phone   4)email\n");
        printf("%s\n",STARS);
        while((status=scanf("%d",&code))!=1||(code<1||code>4))
        {
            if(status!=1)
                scanf("%*s");
            printf("Enter an integer from 1 to 4,please.\n");
        }
        switch(code)
        {
        case 1:printf("please input new name!\n");scanf("%s",&a.name);printf("Succeed!\n");break;
        case 2:printf("please input new address!\n");scanf("%s",&a.address);printf("Succeed!\n");break;
        case 3:printf("please input new phone!\n");scanf("%s",&a.phone);printf("Succeed!\n");break;
        case 4:printf("please input new email!\n");scanf("%s",&a.email);printf("Succeed!\n");break;
        default:break;
        }
        fsetpos(fp,ptr);
        fwrite(&a,sizeof(contact_tab),1,fp);
    }
    else
        printf("error!\n");
    fclose(fp);
    output_contacts(headp);
}
int find_one_contact(char *name)                     /*在打开的文件中通过fseek函数进行定位，按二分法进行查找，*/
{                                                     /*通过fread函数将联系人信息读取出来跟要找的联系人名字进行比对*/
    FILE *fp;
    if((fp=fopen("d:\\Codes\\C\\contact_data.bin","rb+"))==NULL)
        exit(-1);
    char name1[20]="name",address1[20]="address",phone1[20]="phone",email1[20]="email";
    int len=0,low=0,high=0,mid=0;
    contact_tab a;
    while(!feof(fp))
    {
        fread(&a,sizeof(contact_tab),1,fp);
        if(!feof(fp))
            len++;
    }
    high=(len-1);
    mid=(low+high)/2;
    fseek(fp,0,SEEK_SET);
    fread(&a,sizeof(contact_tab),1,fp);
    if(strcmp(a.name,name)>0)
    {
        printf("Can't find the contact!\n");
        return -1;
    }
    fseek(fp,high*sizeof(contact_tab),SEEK_SET);
    fread(&a,sizeof(contact_tab),1,fp);
    if(strcmp(a.name,name)<0)
    {
        printf("Can't find the contact!\n");
        return -1;
    }
    while(mid>=low)
    {
        fseek(fp,mid*sizeof(contact_tab),SEEK_SET);
        fread(&a,sizeof(contact_tab),1,fp);
        if(strcmp(a.name,name)==0)
        {
            printf("Find it!\n");
            printf("%-18s%-18s%-18s%-18s\n",name1,address1,phone1,email1);
            printf("%-18s%-18s%-18s%-18s\n",a.name,a.address,a.phone,a.email);
            return mid;
        }
        if(strcmp(a.name,name)>0)
        {
            high=mid-1;
            mid=(low+high)/2;
        }
        if(strcmp(a.name,name)<0)
        {
            low=mid+1;
            mid=(low+high)/2;
        }
    }
    printf("Can't find the contact!\n");
        return -1;
    fclose(fp);
}
