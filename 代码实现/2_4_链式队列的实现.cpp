
/*
    Project: single_linked_queue (链队列)
    InitQueue(LinkQueue &Q)            参数：链队Q 功能：初始化  时间复杂度O(1)
    QueueEmpty(SqQueue Q)              参数：链对Q 功能：判断队空与否 时间复杂度：O(1)
    QueueLength(SqQueue Q)             参数：链对Q 功能：求队列中元素的个数 时间复杂度O(1)
	EnQueue(LinkQueue &Q,QElemType e)  参数：链队Q,元素e 功能：将e入队 时间复杂度:O(1)
	DeQueue(LinkQueue &Q,QElemType &e) 参数：链队Q,元素e 功能：队头出队,e接收出队元素值 时间复杂度O(1)
	GetHead(LinkQueue &Q,QElemType &e) 参数：链队Q,元素e 功能：得到队顶元素 时间复杂度O(1)
	注意：有头结点
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define QElemType int

//链式队列结点
typedef struct QNode
{
    QElemType data;          //数据域
    struct QNode *next;      //指针域
}QNode,*QueuePtr;

//链式队列
typedef struct
{
    QNode *front;           //对头指针
    QNode *rear;            //队尾指针
}LinkQueue;

//**********************基本操作函数******************//
//初始化队列
void InitQueue(LinkQueue &Q)
{
    Q.front=Q.rear=new QNode;               //动态生成新结点
    // Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    Q.front->next=NULL;
}

//判断链对是否为空
bool QueueEmpty(LinkQueue Q)
{
    if(Q.front==Q.rear)
        return true;
    else
        return false;
}

//销毁链式队列
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

//求链对长
int QueueLength(LinkQueue Q)
{
    int n=0;
    while(Q.front!=Q.rear)                 //循环截止条件：表头指针和表位指针重逢
    {
        n++;
        Q.front=Q.front->next;             //表头指针指向表头指针的下一元素
    }
    return n;
}

//入队函数
bool EnQueue(LinkQueue &Q, QElemType e)
{
    QNode *p;
    p=new QNode;           //生成新结点
    if(!p)
        return false;       //分配失败 
    p->data=e;             //赋值
    p->next=NULL;
    Q.rear->next=p;        //将p加入到队尾
    Q.rear=p;              //队尾指针后移
    return true;
}

//出队函数
bool DeQueue(LinkQueue &Q, QElemType &e)
{
    QNode *p;
    p=new QNode;
    if(QueueEmpty(Q))
        return false;           //对空返回false
    e=Q.front->next->data;      //e保存首元结点的数据域
    p=Q.front->next;            //p指向首元结点  临时保存，稍后释放
    Q.front->next=p->next;      //出队,注意Q.front->next,不是Q.front,还有头结点
    if(Q.rear==p)
        Q.rear=Q.front;         //最后一个元素出队，尾结点指向头结点
    delete p;                   //释放p空间
    return true;
}

//求对头元素
bool GetHead(LinkQueue Q, QElemType &e)
{
    if(QueueEmpty(Q))
        return false;
    e=Q.front->next->data;
    return true;
}

//********************功能实现函数*********************//
//入队功能函数 调用EnQueue函数 
void EnterToQueue(LinkQueue &Q)
{
	int n;                  //用于入队元素的个数
    QElemType e;            //用于入队元素的赋值
    bool flag;
	printf("请输入入队元素个数：\n");
	cin>>n;
	for(int i=0;i<n;i++)
	{
	 printf("请输入第%d个元素的值:",i+1);
	 cin>>e;
	 flag=EnQueue(Q,e);
	 if(flag)
        printf("%d已入队!\n",e);
	}
}

//出队功能函数 调用DeQueue函数
void DeleteFromQueue(LinkQueue &Q)
{
	int n;
    QElemType e;
    int flag;
	printf("请输入出队元素个数：\n");
	cin>>n;
	for(int i=0;i<n;i++)
	{
	    flag=DeQueue(Q,e);
	    if(flag)
            printf("%d已出队\n",e);
	    else 
        {
            printf("队已空！！！\n");
            break;
        }
	}
}

//取队顶功能函数 调用GetHead函数
void GetHeadFromQueue(LinkQueue Q)
{
	QElemType e;
    bool flag; 
	flag=GetHead(Q,e);
	if(flag)
        printf("队头元素为:%d\n",e);
	else 
        printf("队已空！！！\n");
}

//求对长功能
void GetQueueLength(LinkQueue Q)
{
    int n;
    n=QueueLength(Q);
    printf("链式队列的长度为：%d\n",n);
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
	LinkQueue Q;
    int choice;
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