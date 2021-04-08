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
    p=L->next;
    int sum=0;
    while(p)
    {
        sum++;
        p=p->next;
    }
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
    for(int i=n;i>0;--i)       //倒序插入
    {
        p=new LNode;           //p=(LNOde*)malloc(sizeof(LNode));
        cin>>p->data;          //输入元素值 C语言中为scanf(&p->data); 
        p->next=L->next;       //插入到表头
        L->next=p;
    }
    delete p;                  //释放p空间
}

//尾插法创建链表
void CreateListTail(LinkList &L, int n)
{
    InitList(L);
    LNode* r;                //创建尾指针
    LNode* p;                //创建结点用于插入的新数据
    r=L;                     //尾指针指向头结点
    for(int i=0; i<n; i++)
    {
        r=(LNode*)malloc(sizeof(LNode));   //C方式生成新结点
        p=new LNode;                //C++方式生成新结点 两者通用
        cin>>p->data;              //输入元素值
        p->next=NULL;        
        r->next=p;                //插入到表尾
        r=p;                     //尾指针指向新的结点
    }
    free(r);                  //C方式释放空间
    delete p;                //C++方式释放空间
}

//获取链表某个元素的内容，通过变量e返回
int GetElemList(LinkList L, int i, int &e)
{
    LNode *p;
    p=L->next;                //初始化，使p指向头结点
    int j=1;
    while(p && j<i)           //向后扫描，直到p指向第i个元素或者p为空
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
        printf("为找到该元素！\n");           //第i个元素不存在
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
bool Insertlist(LinkList &L, int i, int e)
{
    LNode *p,*s;
    p=new LNode;
    p=L->next;
    int j=1;
    while(p && j<i)                   //寻找第i个结点，使得p指向i结点
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
    delete p;
    return true;
}

//删除元素 将链表中第i个元素删除
bool DeleteList(LinkList &L, int i)
{
    LNode *p;
    int j=1;
    p=new LNode;
}