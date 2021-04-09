/*
    Project: single linkeed list (数据结构 单链表)
	InitList(LinkList &L) 参数：单链表L 功能：初始化 时间复杂度 O(1)
	ListLength(LinkList L) 参数：单链表L 功能：获得单链表长度 时间复杂度O(n) 
	ListInsert(LinkList &L,int i,ElemType e) 参数：单链表L,位置i，元素e 功能：位置i后插 时间复杂度O(n)[加入了查找]若已知指针p指向的后插 O(1)
	ListDelete(LinkList &L,int i) 参数：单链表L，位置i 功能：删除位置i元素 时间复杂度O(n)[加入了查找] 
	                              若已知p指针指向的删除 最好是O(1),因为可以与后继结点交换数据域，然后删除后继结点。
								  最坏是O(n),即从头查找p之前的结点,然后删除p所指结点
	LocateElem(LinkList L,ElemType e) 参数：单链表L，元素e 功能：查找第一个等于e的元素，返回指针 时间复杂度O(n) 
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define ElemType int


//单链表结点数据结构
typedef struct LNode
{
    ElemType data;              //定义数据域
    struct LNode *next;         //定义指针域
}LNode,*LinkList;               //LinkList为指向结构体LNode的指针类型

//**********************基本操作函数*****************//
//初始化函数
void InitList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));       //C类型动态分配
    // L=new LNode;                          //C++类型动态分配
    L->next=NULL;
}

//判断链表是否为空
bool ListEmpty(LinkList L)
{
    if(L->next)        //非空
        return true;
    else
        return false;
}

//获取单链表的长度
int ListLength(LinkList L)
{
    LNode *p;                 //开辟新的结点
    p=new LNode;
    p=L->next;
    int sum=0;
    while(p)
    {
        sum++;
        p=p->next;
    }
    delete p;
    return sum;
}

//销毁单链表：单链表销毁后不存在
void DestoryList(LinkList &L)
{
    LNode *p;       //生成新结点
    while(L)
    {
        p=new LNode;    //<=>p=(LinkList)malloc(sizeof(LNode));
        p=L;
        L=L->next;
        delete p;
    }
}

//清空链表：链表仍存在，但表中无元素
void ClearList(LinkList &L)
{
    LNode *p,*q;
    p=L->next;
    q=new LNode;
    while(p)
    {
        p=new LNode;
        q=p->next;           //用q去指向p的下一结点
        delete p;            //释放p
        p=q;
    }
    L->next=NULL;
    delete q;             //释放空间
}

//头插法创建链表
void CreateListHead(LinkList &L, int n)
{
    InitList(L);               //初始化链表
    LNode* p;                  //创建结点p
//    p=(LinkList)malloc(sizeof(LNode));
    for(int i=n;i>0;--i)       //倒序插入
    {
        p=new LNode;           //p=(LNOde*)malloc(sizeof(LNode));
        printf("请输入需要插入的值:\n");
        cin>>p->data;          //输入元素值 C语言中为scanf(&p->data); 
        p->next=L->next;       //插入到表头
        L->next=p;
    }
//    free(p);                  //释放p空间
}

//尾插法创建链表
void CreateListTail(LinkList &L, int n)
{
    InitList(L);
    LNode* r;                       //创建尾指针
    LNode* p;                      //创建结点用于插入的新数据
//    r=(LNode*)malloc(sizeof(LNode));   //C方式生成新结点
    r=L;                           //尾指针指向头结点
    for(int i=0; i<n; i++)
    {
        p=new LNode;                //C++方式生成新结点 两者通用
        printf("请输入需要插入的值:\n");
        cin>>p->data;              //输入元素值
        p->next=NULL;        
        r->next=p;                //插入到表尾
        r=p;                     //尾指针指向新的结点
    }
//    free(r);                  //C方式释放空间
//    delete p;                //C++方式释放空间
}

//获取链表某个元素的内容，通过变量e返回
int GetElemList(LinkList L, int i)
{
    LNode *p;
    p=L->next;                //初始化，使p指向头结点
    int j=1;
    int e;                    //用于返回值
    while(p && j<i)           //向后扫描，直到p指向第i个元素或者p为空
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
    {
        printf("未找到该元素！\n");           //第i个元素不存在
        return 0;
    }
    e=p->data;
    return e;
}

//获取链表中值为e的地址
LNode *LocateElemList(LinkList L, int e)
{
    LNode *p;
    p=L->next;
    while(p && p->data != e)
    {
        p=p->next;
    }
    return p;
}

//按值查找 返回链表中值为e的位置序号
int IndexElemList(LinkList L, int e)
{
    LNode *p;
    p=new LNode;
    p=L->next;
    int j=1;
    while(p && p->data != e)
    {
        p=p->next;
        j++;
    }
    if(p)                         //如果p不为空，且上面的循环结束，说明找到了元素e
        return j;
    else
        return 0;
}

//插入新元素 在链表中第i个位置前插入新的元素e
bool InsertList(LinkList &L, int i, int e)
{
    LNode *p,*s;
//    p=new LNode;
    p=L;
    int j=0;
    while(p && j<i-1)                   //寻找第i个结点，使得p指向i结点的前驱结点 
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)                
    {
        return false;
        printf("输入位置无效！\n");
    }
    s=new LNode;                  //生成新的结点s
    s->data=e;                    //为结点s赋值e
    s->next=p->next;              //将结点s插入到p后
    p->next=s;
//    delete p;
//    delete s;
    return true;
}

//删除元素 将链表中第i个元素删除
bool DeleteList(LinkList &L, int i)
{
    LNode *p,*q;
    int j=1;
    p=(LNode*)malloc(sizeof(LNode));
    q=new LNode;                          //分配新结点
    p=L->next;
    while(p && j<=i-1)
    {                            //寻找第i个结点，并令p指针指向其前驱结点
        p=p->next;
        j++;
    }
    if(!p || j>i-1)
        return false;           //删除位置不合理
    q=p->next;                  //用q结点临时保存需要删除的结点
    p->next=q->next;            //将p结点的后继结点指向需要删除结点的后继结点
    delete q;                   //释放q的空间，等价于删除q
    free(p);                    //释放p的空间
}


//***********************功能实现函数*********************//
//遍历输出单链表的所有元素
void PrintList(LinkList L)
{
    LinkList p=L->next;                   //直接跳过头结点
    bool flag;                            //用于判断单链表是否为空
    int i;                                //用于查看单链表的长度
    flag=ListEmpty(L);
    if(flag)                             //链表非空时，输出链表元素
    {
        i=ListLength(L);
        printf("单链表的长度为:%d\n",i);
        printf("单链表的元素为：\n");
        while(p)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
        printf("\n");
    }
    else
        printf("单链表为空，没有元素！\n");
}

//头插法创建单链表
void CreateH(LinkList &L)
{
    int n;
    printf("请输入需要创建的单链表的长度：\n");
    scanf("%d",&n);
    CreateListHead(L,n);
}

//尾插法创建单链表
void CreateT(LinkList &L)
{
    int n;
    printf("请输入需要创建的单链表的长度：\n");
    scanf("%d",&n);
    CreateListTail(L,n);
}

//按序查值 根据元素的序号查找元素的值
void SearchElem(LinkList L)
{
    int n;                           //用于查找序号
    int e;                           //用于返回值
    int flag;
    printf("请输入需要查找的元素的序号:\n");
    scanf("%d",&n);
    e=GetElemList(L,n);
    if(e)                           //e不为0，说明找到该元素
        printf("该元素为%d!\n",e);
    else
        printf("查找序号非法！\n");
}

//按值查序 根据元素的值查找该元素在链表中的位置
void SearchIndex(LinkList L)
{
    int e;
    int index;
    int flag;
    printf("请输入需要查找的元素的值:\n");
    scanf("%d",&e);
    index=IndexElemList(L,e);
    if(index)
        printf("该元素所在链表中的位置为:%d\n",index);
    else
        printf("该元素不在链表中！\n");
}

//插入功能 在链表第i个位置插入新的元素
void Insert(LinkList &L)
{
    int i;
    int e;
    bool flag;
    printf("请输入需要插入的元素的值:\n");
    scanf("%d",&e);
    printf("请输入需要插入的元素的位置:\n");
    scanf("%d",&i);
    flag=InsertList(L, i, e);
    if(flag)
    {
        printf("插入成功！\n");
//        PrintList(L);
    }
    else
        printf("插入失败！\n");
}

//删除功能函数
void Delete(LinkList &L)
{
    int i;
    bool flag;
    printf("请输入需要删除元素的位置:\n");
    scanf("%d",&i);
    flag=DeleteList(L,i);
    if(flag)
    {
        printf("删除成功！\n");
        PrintList(L);
    }
    else
        printf("删除失败！\n");
}

//清空链表
void Clear(LinkList &L)
{
    ClearList(L);
    PrintList(L);
}

//销毁链表
void Destory(LinkList &L)
{
    DestoryList(L);
}

//菜单
void menu()
{
   printf("********1.头插创建    2.尾插创建*********\n");
   printf("********3.按序查值    4.按值查序*********\n");
   printf("********5.插入功能    6.删除功能*********\n");
   printf("********7.输出功能    8.清空链表*********\n");
   printf("********9.销毁链表    0.退出函数*********\n");
}
//主函数
int main()
{
    LinkList L;int choice;
    InitList(L);
    while(1)
    {
        menu();
        printf("请输入菜单序号：\n");
        scanf("%d",&choice);
        if(choice==0) break;
        switch(choice)
        {
            case 1:CreateH(L);break;
            case 2:CreateT(L);break;
            case 3:SearchElem(L);break;
            case 4:SearchIndex(L);break;
            case 5:Insert(L);break;
            case 6:Delete(L);break;
            case 7:PrintList(L);break;
            case 8:Clear(L);break;
            case 9:Destory(L);break;
            default:printf("输入错误！！！\n");
        }
    }
    return 0;
}