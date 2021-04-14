/*
    Project: single_linked_stack (数据结构 链栈)
    InitStack(LinkStack &S) 参数：链栈S 功能：初始化  时间复杂度O(1)
    StackEmpty(LinkStack S) 参数：链栈S 功能：判断链栈是否为空 时间复杂度为O(1)
	StackLength(LinkStack S) 参数：链栈S 功能：求链栈中元素的个数 时间复杂度O(n) 
	Push(LinkStack &S,SElemType e) 参数：链栈S,元素e 功能：将e入栈 时间复杂度:O(1)
	Pop(LinkStack &S,SElemType &e) 参数：链栈S,元素e 功能：栈顶出栈,e接收出栈元素值 时间复杂度O(1)
	GetTop(LinkStack &S,SElemType &e) 参数：链栈S,元素e 功能：得到栈顶元素 时间复杂度O(1)
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define SElemType int

//链栈的数据结构
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;

//*****************基本操作函数*****************//
//初始化函数
void InitStack(LinkStack &S)
{
    S=NULL;                   //生成空链栈，链栈没有头结点，头指针直接指向栈顶元素
}

//判断链栈是否为空
bool StackEmpty(LinkStack S)
{
    if(S==NULL)             //头指针指向空，说明链栈中没有元素
        return true;
    else
        return false;
}

//求链栈长度
int StackLength(LinkStack S)
{
    int n=0;
    while(S!=NULL)
    {
        S=S->next;
        n++;
    }
    return n;          //n返回链栈中元素的个数 
}

//入栈 链栈为链式储存结构，不存在栈满情况，故入栈没有截止条件
int Push(LinkStack &S,SElemType e)
{
    StackNode *p;
    p=new StackNode;          //生成新结点并开辟空间
    p->data=e;                //将新节点数值域置为e
    p->next=S;                //新结点插入栈顶
    S=p;                      //修改栈顶指针
    return 1;
}

//出栈 栈顶元素用元素e返回
bool Pop(LinkStack &S, SElemType &e)
{
    StackNode *p;
    p=new StackNode;
    if(StackEmpty(S))      //栈空 
        return false;
    e=S->data;            //S当前指向栈顶，用e返回栈顶的元素值
    p=S;                  //用结点p指向栈顶，delete p之后栈顶结点释放，相当于删除此时的栈顶空间
    S=S->next;            //将结点S指向下一结点，作为新的栈顶结点
//    delete p;
    return true;
    
}

//读取栈顶元素
bool GetTop(LinkStack S, SElemType &e)
{
    if(StackEmpty(S))
    {
        printf("栈空！\n");
        return false;
    }
    e=S->data;
    return true;
}

//****************功能实现函数******************//
//入栈功能
void PushStack(LinkStack &S)
{
    int n;              //用于表示入栈元素的个数
    SElemType e;        //用于表示入栈元素的值
    bool flag;
    printf("请输入需要入栈元素的个数:\n");
    cin>>n;
    for(int i=0; i<n; i++)
    {
        printf("请输入第%d个元素的值：",i+1);
        cin>>e;
        flag=Push(S,e);
        if(flag)
            printf("%d已入栈！\n",e);
    }
}

//出栈功能
void PopStack(LinkStack &S)
{
    int n;              //用于表示出栈元素的个数
    SElemType e;        //用于表示出栈元素的值
    bool flag;
    printf("请输入需要出栈元素的个数:\n");
    cin>>n;
    for(int i=0; i<n; i++)
    {
        flag=Pop(S,e);
        if(flag)
            printf("%d已出栈！\n",e);
        else
            break;
    }
}

//读取栈顶元素功能
void GetTopStack(LinkStack S)
{
    SElemType e;
    bool flag;
    flag=GetTop(S,e);
    if(flag)
        printf("栈顶元素为%d!\n",e);
}

//求栈长度功能
void GetStackLength(LinkStack S)
{
    int n;               //用于保存栈长度的变量值
    n=StackLength(S);
    printf("栈的长度为%d\n",n);
}

//菜单
void menu()
{
   printf("********1.元素入栈      2.元素出栈*********\n");
   printf("********3.取栈顶元素    4.求栈长度*********\n");
   printf("****************  0.退出  ****************\n");
}

//主函数
int main()
{
    LinkStack S;
    int choice;
    InitStack(S);
    while(1)
    {
        menu();
        printf("请输入菜单序号：\n");
        scanf("%d",&choice);
        if(choice==0) break;
        switch(choice)
        {
            case 1:PushStack(S);break;
            case 2:PopStack(S);break;
            case 3:GetTopStack(S);break;
            case 4:GetStackLength(S);break;
            default:printf("输入错误！！！\n");
        }
    }
    return 0;
}