/*
    Project: sequentially_cyclic_queue ��˳��ṹѭ�����У�
	InitQueue(SqQueue &Q)              ������ѭ������Q ���ܣ���ʼ��ѭ������Q ʱ�临�Ӷȣ�O(1)
	QueueEmpty(SqQueue Q)              ������ѭ������Q ���ܣ��ж϶ӿ���� ʱ�临�Ӷȣ�O(1)
    QueueFull(SqQueue Q)               ������ѭ������Q ���ܣ��ж϶��Ƿ��� ʱ�临�Ӷȣ�O(1)
    QueueLength(SqQueue Q)             ������ѭ������Q ���ܣ��������Ԫ�صĸ��� ʱ�临�Ӷ�O(1)
	EnQueue(SqQueue &Q,QElemType e)    ������ѭ������Q��Ԫ��e ���ܣ�ʹԪ��e��� ʱ�临�Ӷȣ�O(1)
	DeQueue(SqQueue &Q,QElemType &e)   ������ѭ������Q��Ԫ��e ���ܣ���ͷ����,��e����ֵ ʱ�临�Ӷȣ�O(1)
	GetHead(SqQueue &Q,QElemType &e)   ������ѭ������Q��Ԫ��e ���ܣ���ȡ��ͷԪ��e ʱ�临�Ӷȣ�O(1)
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int
#define MaxQSize 100

//ѭ���������ݽṹ
typedef struct
{
    QElemType *data;               //��̬�������ݴ���ռ�
    int front,rear;                //����ͷָ���βָ�룺��Ȼ����Ϊָ�룬������ָΪ�����±�����γ��� 
}SqQueue;                          

//********************������������*********************//
//��ʼ������
void InitQueue(SqQueue &Q)
{
    Q.data=new QElemType[MaxQSize];   //��������ռ�
    //Q.data=(QElemType*)malloc(MaxQSize*sizeof(QElemType));
    Q.front=Q.rear=0;     
}

//�ж϶ӿպ���
bool QueueEmpyty(SqQueue Q)
{
    if(Q.rear==Q.front)            //ͷָ���βָ����ͬ���Կ�
        return true;
    else
        return false;
}

//�ж϶�������
bool QueueFull(SqQueue Q)
{
    if((Q.rear+1)%MaxQSize==Q.front)     //����������һ��Ԫ�����ж�
        return true;
    else
        return false;
}

//����г��Ⱥ���
int QueueLength(SqQueue Q)
{   //ѭ�����У�����һ����Ԫ�����ʱ����һ����Ԫ
    return (Q.rear+MaxQSize-Q.front)%MaxQSize;
}

//��Ӻ���
bool EnQueue(SqQueue &Q, QElemType e)
{
    if(QueueFull(Q))
        return false;
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MaxQSize;       //βָ���1��ȡģ����
    return true;
}

//���Ӻ���
bool DeQueue(SqQueue &Q, QElemType &e)
{
    if(QueueEmpyty(Q))
        return false;
    e=Q.data[Q.front];              //ȡ��ͷԪ��
    Q.front=(Q.front+1)%MaxQSize;   //ͷָ���1��ȡģ
    return true;
}

//ȡ��ͷԪ��
bool GetHead(SqQueue Q, QElemType &e)
{
    if(QueueEmpyty(Q))
        return false;
    e=Q.data[Q.front];
    return true;
}

//**************����ʵ�ֺ���******************//
//��ӹ���
void EnterToQueue(SqQueue &Q)
{
    int n;                      //�������Ԫ�صĸ���
    QElemType e;                //�������Ԫ�ص�ֵ
    bool flag;                  
    printf("���������Ԫ�صĸ�����\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        printf("�������%d��Ԫ�ص�ֵ��\n",i+1);
        cin>>e;
        flag=EnQueue(Q,e);
        if(flag)
            printf("%d����ӣ�\n",e);
        else
        {
            printf("������\n");
            break;
        }
    }
}

//���ӹ���
void DeleteFromQueue(SqQueue &Q)
{
    int n;                      //���ڳ���Ԫ�صĸ���
    QElemType e;                //���ڳ���Ԫ�ص�ֵ
    bool flag;                  
    printf("���������Ԫ�صĸ�����\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        flag=DeQueue(Q,e);
        if(flag)
            printf("%d�ѳ��ӣ�\n",e);
        else
        {
            printf("�Կգ�\n");
            break;
        }
    }
}

//ȡ��ͷԪ�ع���
void GetHeadFromQueue(SqQueue Q)
{
    QElemType e;
    bool flag;
    flag=GetHead(Q,e);
    if(flag)
        printf("��ͷԪ��Ϊ:%d\n",e);
    else
        printf("�Կգ�\n");
}

//��Գ�����
void GetQueueLength(SqQueue Q)
{
    int n;
    n=QueueLength(Q);
    printf("���еĳ���Ϊ:%d\n",n);
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
	SqQueue Q;int choice;
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