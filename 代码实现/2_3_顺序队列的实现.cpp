/*
    Project: sequentially_cyclic_queue （顺序结构循环队列）
	InitQueue(SqQueue &Q)              参数：循环队列Q 功能：初始化循环队列Q 时间复杂度：O(1)
	QueueEmpty(SqQueue Q)              参数：循环队列Q 功能：判断队空与否 时间复杂度：O(1)
    QueueFull(SqQueue Q)               参数：循环队列Q 功能：判断对是否满 时间复杂度：O(1)
    QueueLength(SqQueue Q)             参数：循环队列Q 功能：求队列中元素的个数 时间复杂度O(1)
	EnQueue(SqQueue &Q,QElemType e)    参数：循环队列Q，元素e 功能：使元素e入队 时间复杂度：O(1)
	DeQueue(SqQueue &Q,QElemType &e)   参数：循环队列Q，元素e 功能：队头出队,用e返回值 时间复杂度：O(1)
	GetHead(SqQueue &Q,QElemType &e)   参数：循环队列Q，元素e 功能：获取队头元素e 时间复杂度：O(1)
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

//循环队列数据结构
typedef struct
{
    QElemType *data;               //动态分配数据储存空间
    int front,rear;                //定义头指针和尾指针：虽然定义为指针，但是是指为数组下标的整形常量 
}SqQueue;                          

//********************基本操作函数*********************//
//初始化函数
void InitQueue(SqQueue &Q)
{
    Q.data=new QElemType[MaxQSize];   //分配数组空间
    //Q.data=(QElemType*)malloc(MaxQSize*sizeof(QElemType));
    Q.front=Q.rear=0;     
}

//判断队空函数
bool QueueEmpyty(SqQueue Q)
{
    if(Q.rear==Q.front)            //头指针和尾指针相同，对空
        return true;
    else
        return false;
}

//判断对满函数
bool QueueFull(SqQueue Q)
{
    if((Q.rear+1)%MaxQSize==Q.front)     //对满，牺牲一个元素域判断
        return true;
    else
        return false;
}

//求队列长度函数
int QueueLength(SqQueue Q)
{   //循环队列，牺牲一个单元，入队时少入一个单元
    return (Q.rear+MaxQSize-Q.front)%MaxQSize;
}

//入队函数
bool EnQueue(SqQueue &Q, QElemType e)
{
    if(QueueFull(Q))
        return false;
    Q.data[Q.rear]=e;
    Q.rear=(Q.rear+1)%MaxQSize;       //尾指针加1，取模运算
    return true;
}

//出队函数
bool DeQueue(SqQueue &Q, QElemType &e)
{
    if(QueueEmpyty(Q))
        return false;
    e=Q.data[Q.front];              //取对头元素
    Q.front=(Q.front+1)%MaxQSize;   //头指针加1，取模
    return true;
}

//取对头元素
bool GetHead(SqQueue Q, QElemType &e)
{
    if(QueueEmpyty(Q))
        return false;
    e=Q.data[Q.front];
    return true;
}

//**************功能实现函数******************//
//入队功能
void EnterToQueue(SqQueue &Q)
{
    int n;                      //用于入队元素的个数
    QElemType e;                //用于入队元素的值
    bool flag;                  
    printf("请输入入队元素的个数：\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个元素的值：\n",i+1);
        cin>>e;
        flag=EnQueue(Q,e);
        if(flag)
            printf("%d已入队！\n",e);
        else
        {
            printf("对满！\n");
            break;
        }
    }
}

//出队功能
void DeleteFromQueue(SqQueue &Q)
{
    int n;                      //用于出队元素的个数
    QElemType e;                //用于出队元素的值
    bool flag;                  
    printf("请输入入队元素的个数：\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        flag=DeQueue(Q,e);
        if(flag)
            printf("%d已出队！\n",e);
        else
        {
            printf("对空！\n");
            break;
        }
    }
}

//取对头元素功能
void GetHeadFromQueue(SqQueue Q)
{
    QElemType e;
    bool flag;
    flag=GetHead(Q,e);
    if(flag)
        printf("对头元素为:%d\n",e);
    else
        printf("对空！\n");
}

//求对长功能
void GetQueueLength(SqQueue Q)
{
    int n;
    n=QueueLength(Q);
    printf("队列的长度为:%d\n",n);
}

//菜单
void menu()
{
   printf("********1.入队         2.出队***********\n");
   printf("********3.取队头       4.求对长*********\n");
   printf("************* 0.退出 ******************\n");
}

//主函数

int main()
{
	SqQueue Q;int choice;
	InitQueue(Q);
	while(1)
	{
	    menu();
	    printf("请输入菜单序号：\n");
	    scanf("%d",&choice);
	    if(choice==0) break;
	    switch(choice)
	    {
	        case 1:EnterToQueue(Q);break;
	        case 2:DeleteFromQueue(Q);break;
	        case 3:GetHeadFromQueue(Q);break;
            case 4:GetQueueLength(Q);break;
	        default:printf("输入错误！！！\n");
	    }
	}
	return 0;
}