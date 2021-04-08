/*
    Project: single linkeed list (���ݽṹ ������)
	InitList(LinkList &L) ������������L ���ܣ���ʼ�� ʱ�临�Ӷ� O(1)
	ListLength(LinkList L) ������������L ���ܣ���õ������� ʱ�临�Ӷ�O(n) 
	ListInsert(LinkList &L,int i,ElemType e) ������������L,λ��i��Ԫ��e ���ܣ�λ��i��� ʱ�临�Ӷ�O(n)[�����˲���]����ָ֪��pָ��ĺ�� O(1)
	ListDelete(LinkList &L,int i) ������������L��λ��i ���ܣ�ɾ��λ��iԪ�� ʱ�临�Ӷ�O(n)[�����˲���] 
	                              ����֪pָ��ָ���ɾ�� �����O(1),��Ϊ�������̽�㽻��������Ȼ��ɾ����̽�㡣
								  ���O(n),����ͷ����p֮ǰ�Ľ��,Ȼ��ɾ��p��ָ���
	LocateElem(LinkList L,ElemType e) ������������L��Ԫ��e ���ܣ����ҵ�һ������e��Ԫ�أ�����ָ�� ʱ�临�Ӷ�O(n) 
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define ElemType int


//�����������ݽṹ
typedef struct LNode
{
    ElemType data;              //����������
    struct LNode *next;         //����ָ����
}LNode,*LinkList;               //LinkListΪָ��ṹ��LNode��ָ������

//**********************������������*****************//
//��ʼ������
void InitList(LinkList &L)
{
    L=(LinkList)malloc(sizeof(LNode));       //C���Ͷ�̬����
    // L=new LNode;                          //C++���Ͷ�̬����
    L->next=NULL;
}

//�ж������Ƿ�Ϊ��
bool ListEmpty(LinkList L)
{
    if(L->next)        //�ǿ�
        return true;
    else
        return false;
}

//��ȡ������ĳ���
int ListLength(LinkList L)
{
    LNode *p;                 //�����µĽ��
    p=L->next;
    int sum=0;
    while(p)
    {
        sum++;
        p=p->next;
    }
    return sum;
}

//���ٵ��������������ٺ󲻴���
void DestoryList(LinkList &L)
{
    LNode *p;       //�����½��
    while(L)
    {
        p=new LNode;    //<=>p=(LinkList)malloc(sizeof(LNode));
        p=L;
        L=L->next;
        delete p;
    }
}

//������������Դ��ڣ���������Ԫ��
void ClearList(LinkList &L)
{
    LNode *p,*q;
    p=L->next;
    q=new LNode;
    while(p)
    {
        p=new LNode;
        q=p->next;           //��qȥָ��p����һ���
        delete p;            //�ͷ�p
        p=q;
    }
    L->next=NULL;
    delete q;             //�ͷſռ�
}

//ͷ�巨��������
void CreateListHead(LinkList &L, int n)
{
    InitList(L);               //��ʼ������
    LNode* p;                  //�������p
    for(int i=n;i>0;--i)       //�������
    {
        p=new LNode;           //p=(LNOde*)malloc(sizeof(LNode));
        cin>>p->data;          //����Ԫ��ֵ C������Ϊscanf(&p->data); 
        p->next=L->next;       //���뵽��ͷ
        L->next=p;
    }
    delete p;                  //�ͷ�p�ռ�
}

//β�巨��������
void CreateListTail(LinkList &L, int n)
{
    InitList(L);
    LNode* r;                //����βָ��
    LNode* p;                //����������ڲ����������
    r=L;                     //βָ��ָ��ͷ���
    for(int i=0; i<n; i++)
    {
        r=(LNode*)malloc(sizeof(LNode));   //C��ʽ�����½��
        p=new LNode;                //C++��ʽ�����½�� ����ͨ��
        cin>>p->data;              //����Ԫ��ֵ
        p->next=NULL;        
        r->next=p;                //���뵽��β
        r=p;                     //βָ��ָ���µĽ��
    }
    free(r);                  //C��ʽ�ͷſռ�
    delete p;                //C++��ʽ�ͷſռ�
}

//��ȡ����ĳ��Ԫ�ص����ݣ�ͨ������e����
int GetElemList(LinkList L, int i, int &e)
{
    LNode *p;
    p=L->next;                //��ʼ����ʹpָ��ͷ���
    int j=1;
    while(p && j<i)           //���ɨ�裬ֱ��pָ���i��Ԫ�ػ���pΪ��
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
        printf("Ϊ�ҵ���Ԫ�أ�\n");           //��i��Ԫ�ز�����
    e=p->data;
    return e;
}

//��ȡ������ֵΪe�ĵ�ַ
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

//��ֵ���� ����������ֵΪe��λ�����
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
    if(p)                         //���p��Ϊ�գ��������ѭ��������˵���ҵ���Ԫ��e
        return j;
    else
        return 0;
}

//������Ԫ�� �������е�i��λ��ǰ�����µ�Ԫ��e
bool Insertlist(LinkList &L, int i, int e)
{
    LNode *p,*s;
    p=new LNode;
    p=L->next;
    int j=1;
    while(p && j<i)                   //Ѱ�ҵ�i����㣬ʹ��pָ��i���
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)                
    {
        return false;
        printf("����λ����Ч��\n");
    }
    s=new LNode;                  //�����µĽ��s
    s->data=e;                    //Ϊ���s��ֵe
    s->next=p->next;              //�����s���뵽p��
    p->next=s;
    delete p;
    return true;
}

//ɾ��Ԫ�� �������е�i��Ԫ��ɾ��
bool DeleteList(LinkList &L, int i)
{
    LNode *p;
    int j=1;
    p=new LNode;
}