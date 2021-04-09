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
//    p=(LinkList)malloc(sizeof(LNode));
    for(int i=n;i>0;--i)       //�������
    {
        p=new LNode;           //p=(LNOde*)malloc(sizeof(LNode));
        printf("��������Ҫ�����ֵ:\n");
        cin>>p->data;          //����Ԫ��ֵ C������Ϊscanf(&p->data); 
        p->next=L->next;       //���뵽��ͷ
        L->next=p;
    }
//    free(p);                  //�ͷ�p�ռ�
}

//β�巨��������
void CreateListTail(LinkList &L, int n)
{
    InitList(L);
    LNode* r;                       //����βָ��
    LNode* p;                      //����������ڲ����������
//    r=(LNode*)malloc(sizeof(LNode));   //C��ʽ�����½��
    r=L;                           //βָ��ָ��ͷ���
    for(int i=0; i<n; i++)
    {
        p=new LNode;                //C++��ʽ�����½�� ����ͨ��
        printf("��������Ҫ�����ֵ:\n");
        cin>>p->data;              //����Ԫ��ֵ
        p->next=NULL;        
        r->next=p;                //���뵽��β
        r=p;                     //βָ��ָ���µĽ��
    }
//    free(r);                  //C��ʽ�ͷſռ�
//    delete p;                //C++��ʽ�ͷſռ�
}

//��ȡ����ĳ��Ԫ�ص����ݣ�ͨ������e����
int GetElemList(LinkList L, int i)
{
    LNode *p;
    p=L->next;                //��ʼ����ʹpָ��ͷ���
    int j=1;
    int e;                    //���ڷ���ֵ
    while(p && j<i)           //���ɨ�裬ֱ��pָ���i��Ԫ�ػ���pΪ��
    {
        p=p->next;
        j++;
    }
    if(!p || j>i)
    {
        printf("δ�ҵ���Ԫ�أ�\n");           //��i��Ԫ�ز�����
        return 0;
    }
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
bool InsertList(LinkList &L, int i, int e)
{
    LNode *p,*s;
//    p=new LNode;
    p=L;
    int j=0;
    while(p && j<i-1)                   //Ѱ�ҵ�i����㣬ʹ��pָ��i����ǰ����� 
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
//    delete p;
//    delete s;
    return true;
}

//ɾ��Ԫ�� �������е�i��Ԫ��ɾ��
bool DeleteList(LinkList &L, int i)
{
    LNode *p,*q;
    int j=1;
    p=(LNode*)malloc(sizeof(LNode));
    q=new LNode;                          //�����½��
    p=L->next;
    while(p && j<=i-1)
    {                            //Ѱ�ҵ�i����㣬����pָ��ָ����ǰ�����
        p=p->next;
        j++;
    }
    if(!p || j>i-1)
        return false;           //ɾ��λ�ò�����
    q=p->next;                  //��q�����ʱ������Ҫɾ���Ľ��
    p->next=q->next;            //��p���ĺ�̽��ָ����Ҫɾ�����ĺ�̽��
    delete q;                   //�ͷ�q�Ŀռ䣬�ȼ���ɾ��q
    free(p);                    //�ͷ�p�Ŀռ�
}


//***********************����ʵ�ֺ���*********************//
//������������������Ԫ��
void PrintList(LinkList L)
{
    LinkList p=L->next;                   //ֱ������ͷ���
    bool flag;                            //�����жϵ������Ƿ�Ϊ��
    int i;                                //���ڲ鿴������ĳ���
    flag=ListEmpty(L);
    if(flag)                             //����ǿ�ʱ���������Ԫ��
    {
        i=ListLength(L);
        printf("������ĳ���Ϊ:%d\n",i);
        printf("�������Ԫ��Ϊ��\n");
        while(p)
        {
            printf("%d\t",p->data);
            p=p->next;
        }
        printf("\n");
    }
    else
        printf("������Ϊ�գ�û��Ԫ�أ�\n");
}

//ͷ�巨����������
void CreateH(LinkList &L)
{
    int n;
    printf("��������Ҫ�����ĵ�����ĳ��ȣ�\n");
    scanf("%d",&n);
    CreateListHead(L,n);
}

//β�巨����������
void CreateT(LinkList &L)
{
    int n;
    printf("��������Ҫ�����ĵ�����ĳ��ȣ�\n");
    scanf("%d",&n);
    CreateListTail(L,n);
}

//�����ֵ ����Ԫ�ص���Ų���Ԫ�ص�ֵ
void SearchElem(LinkList L)
{
    int n;                           //���ڲ������
    int e;                           //���ڷ���ֵ
    int flag;
    printf("��������Ҫ���ҵ�Ԫ�ص����:\n");
    scanf("%d",&n);
    e=GetElemList(L,n);
    if(e)                           //e��Ϊ0��˵���ҵ���Ԫ��
        printf("��Ԫ��Ϊ%d!\n",e);
    else
        printf("������ŷǷ���\n");
}

//��ֵ���� ����Ԫ�ص�ֵ���Ҹ�Ԫ���������е�λ��
void SearchIndex(LinkList L)
{
    int e;
    int index;
    int flag;
    printf("��������Ҫ���ҵ�Ԫ�ص�ֵ:\n");
    scanf("%d",&e);
    index=IndexElemList(L,e);
    if(index)
        printf("��Ԫ�����������е�λ��Ϊ:%d\n",index);
    else
        printf("��Ԫ�ز��������У�\n");
}

//���빦�� �������i��λ�ò����µ�Ԫ��
void Insert(LinkList &L)
{
    int i;
    int e;
    bool flag;
    printf("��������Ҫ�����Ԫ�ص�ֵ:\n");
    scanf("%d",&e);
    printf("��������Ҫ�����Ԫ�ص�λ��:\n");
    scanf("%d",&i);
    flag=InsertList(L, i, e);
    if(flag)
    {
        printf("����ɹ���\n");
//        PrintList(L);
    }
    else
        printf("����ʧ�ܣ�\n");
}

//ɾ�����ܺ���
void Delete(LinkList &L)
{
    int i;
    bool flag;
    printf("��������Ҫɾ��Ԫ�ص�λ��:\n");
    scanf("%d",&i);
    flag=DeleteList(L,i);
    if(flag)
    {
        printf("ɾ���ɹ���\n");
        PrintList(L);
    }
    else
        printf("ɾ��ʧ�ܣ�\n");
}

//�������
void Clear(LinkList &L)
{
    ClearList(L);
    PrintList(L);
}

//��������
void Destory(LinkList &L)
{
    DestoryList(L);
}

//�˵�
void menu()
{
   printf("********1.ͷ�崴��    2.β�崴��*********\n");
   printf("********3.�����ֵ    4.��ֵ����*********\n");
   printf("********5.���빦��    6.ɾ������*********\n");
   printf("********7.�������    8.�������*********\n");
   printf("********9.��������    0.�˳�����*********\n");
}
//������
int main()
{
    LinkList L;int choice;
    InitList(L);
    while(1)
    {
        menu();
        printf("������˵���ţ�\n");
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
            default:printf("������󣡣���\n");
        }
    }
    return 0;
}