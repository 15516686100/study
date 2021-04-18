
/*
    Project: single_linked_queue (������)
    InitQueue(LinkQueue &Q)            ����������Q ���ܣ���ʼ��  ʱ�临�Ӷ�O(1)
    QueueEmpty(SqQueue Q)              ����������Q ���ܣ��ж϶ӿ���� ʱ�临�Ӷȣ�O(1)
    QueueLength(SqQueue Q)             ����������Q ���ܣ��������Ԫ�صĸ��� ʱ�临�Ӷ�O(1)
	EnQueue(LinkQueue &Q,QElemType e)  ����������Q,Ԫ��e ���ܣ���e��� ʱ�临�Ӷ�:O(1)
	DeQueue(LinkQueue &Q,QElemType &e) ����������Q,Ԫ��e ���ܣ���ͷ����,e���ճ���Ԫ��ֵ ʱ�临�Ӷ�O(1)
	GetHead(LinkQueue &Q,QElemType &e) ����������Q,Ԫ��e ���ܣ��õ��Ӷ�Ԫ�� ʱ�临�Ӷ�O(1)
	ע�⣺��ͷ���
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int

//��ʽ���н��
typedef struct QNode
{
    QElemType data;          //������
    struct QNode *next;      //ָ����
}QNode,*QueuePtr;

//��ʽ����
typedef struct
{
    QNode *front;           //��ͷָ��
    QNode *rear;            //��βָ��
}LinkQueue;

//**********************������������******************//
//��ʼ������
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=new QNode;               //��̬�����½��
    // Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    Q.front->next=NULL;
}

//�ж������Ƿ�Ϊ��
bool QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}

//������ʽ����
void DestoryQueue(LinkQueue &Q)
{
    QNode *p=new QNode;
    while(Q.front)
    {
        p=Q.front->next;
        delete(Q.front);
        Q.front=p;
    }
    delete p;
}

//�����Գ�
int QueueLength(LinkQueue Q)
{
    int n=0;
    while(Q.front!=Q.rear)                 //ѭ����ֹ��������ͷָ��ͱ�λָ���ط�
    {
        n++;
        Q.front=Q.front->next;             //��ͷָ��ָ���ͷָ�����һԪ��
    }
    return n;
}

//��Ӻ���
bool EnQueue(LinkQueue &Q, QElemType e)
{
    QNode *p;
    p=new QNode;           //�����½��
    if(!p)
        return false;       //����ʧ�� 
    p->data=e;             //��ֵ
    p->next=NULL;
    Q.rear->next=p;        //��p���뵽��β
    Q.rear=p;              //��βָ�����
    return true;
}

//���Ӻ���
bool DeQueue(LinkQueue &Q, QElemType &e)
{
    QNode *p;
    p=new QNode;
    if(QueueEmpty(Q))
        return false;           //�Կշ���false
    e=Q.front->next->data;      //e������Ԫ����������
    p=Q.front->next;            //pָ����Ԫ���  ��ʱ���棬�Ժ��ͷ�
    Q.front->next=p->next;      //����,ע��Q.front->next,����Q.front,����ͷ���
    if(Q.rear==p)
        Q.rear=Q.front;         //���һ��Ԫ�س��ӣ�β���ָ��ͷ���
    delete p;                   //�ͷ�p�ռ�
    return true;
}

//���ͷԪ��
bool GetHead(LinkQueue Q, QElemType &e)
{
    if(QueueEmpty(Q))
        return false;
    e=Q.front->next->data;
    return true;
}

//********************����ʵ�ֺ���*********************//
//��ӹ��ܺ��� ����EnQueue���� 
void EnterToQueue(LinkQueue &Q)
{
	int n;                  //�������Ԫ�صĸ���
    QElemType e;            //�������Ԫ�صĸ�ֵ
    bool flag;
	printf("���������Ԫ�ظ�����\n");
	cin>>n;
	for(int i=0;i<n;i++)
	{
	 printf("�������%d��Ԫ�ص�ֵ:",i+1);
	 cin>>e;
	 flag=EnQueue(Q,e);
	 if(flag)
        printf("%d�����!\n",e);
	}
}

//���ӹ��ܺ��� ����DeQueue����
void DeleteFromQueue(LinkQueue &Q)
{
	int n;
    QElemType e;
    int flag;
	printf("���������Ԫ�ظ�����\n");
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    flag=DeQueue(Q,e);
	    if(flag)
            printf("%d�ѳ���\n",e);
	    else 
        {
            printf("���ѿգ�����\n");
            break;
        }
	}
}

//ȡ�Ӷ����ܺ��� ����GetHead����
void GetHeadFromQueue(LinkQueue Q)
{
	QElemType e;
    bool flag; 
	flag=GetHead(Q,e);
	if(flag)
        printf("��ͷԪ��Ϊ:%d\n",e);
	else 
        printf("���ѿգ�����\n");
}

//��Գ�����
void GetQueueLength(LinkQueue Q)
{
    int n;
    n=QueueLength(Q);
    printf("��ʽ���еĳ���Ϊ��%d\n",n);
}
//�˵�
void menu()
{
   printf("********1.���         2.����***********\n");
   printf("********3.ȡ��ͷ       4.��Գ�*********\n");
   printf("************* 0.�˳� ******************\n");
}

//������

int main()
{
	LinkQueue Q;
    int choice;
	InitQueue(Q);
	while(1)
	{
	    menu();
	    printf("������˵���ţ�\n");
	    scanf("%d",&choice);
	    if(choice==0) break;
	    switch(choice)
	    {
	        case 1:EnterToQueue(Q);break;
	        case 2:DeleteFromQueue(Q);break;
	        case 3:GetHeadFromQueue(Q);break;
            case 4:GetQueueLength(Q);break;
	        default:printf("������󣡣���\n");
	    }
	}
	return 0;
}