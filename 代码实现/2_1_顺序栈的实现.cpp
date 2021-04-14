/*
    Project: sequence_stack (数据结构-顺序栈)
	InitStack(SqStack &S) 参数：顺序栈S 功能：初始化  时间复杂度O(1)
    StackEmpty(SqStack S) 参数：顺序栈S 功能：判断顺序栈是否为空 时间复杂度O(1)
    StackLength(SqStack S) 参数：顺序栈S 功能：获取顺序栈的长度 时间复杂度为O(1)
    ClearStack(SqStack &S) 参数：顺序栈S 功能：将顺序栈的所有元素清空 时间复杂度O(1)
    DestoryStack(SqStack &S) 参数：顺序栈S 功能：销毁栈，并释放栈s占用的储存空间 时间复杂度O(1)
	Push(SqStack &S,SElemType e) 参数：顺序栈S,元素e 功能：将e入栈 时间复杂度:O(1)
	Pop(SqStack &S,SElemType &e) 参数：顺序栈S,元素e 功能：出栈,e接收出栈元素值 时间复杂度O(1)
	GetTop(SqStack S,SElemType &e) 参数：顺序栈S,元素e 功能：得到栈顶元素 时间复杂度O(1)
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
#define MaxSize 100
#define Status int
#define SElemType int

//栈的数据结构
typedef struct 
{
    SElemType *base;        //栈底指针 始终保持不变
    SElemType *top;         //栈顶指针 始终指向栈顶元素的上一个位置
    int stacksize;          //栈可用的最大容量
}SqStack;

//*******************基本操作函数**********************//
//初始化函数
Status InitStack(SqStack &S)
{
    S.base=new SElemType[MaxSize];  //动态分配最大容量 C++的语法结构
    //s.base=(SElemType*)malloc(MaxSize*sizeof(SElemType));
    if(!S.base)
    {
        printf("分配失败!\n");
        return 0;
    }
    S.top=S.base;              //初始栈顶指针等于栈底指针
    S.stacksize=MaxSize;       //分配栈的最大可用容量
    return 1;
}

//判断栈是否为空
bool StackEmpty(SqStack S)
{
    if(S.top==S.base)         //栈空的标志栈顶指针等于栈底指针
        return true;
    else
        return false;
}

//求顺序栈的长度
int StackLength(SqStack S)
{
    return S.top-S.base;     //顺序栈的长度为栈顶指针减栈底指针
}

//清空顺序栈
void ClearStack(SqStack &S)
{
    if(S.base)              //栈底指针有指向元素
        S.top=S.base;       //栈顶指针指向栈底指针
}

//销毁顺序栈
void DestoryStack(SqStack &S)
{
    if(S.base)
    {
        delete S.base;
        S.stacksize=0;
        S.base=S.top=NULL;
    }
}

//入栈
bool Push(SqStack &S, SElemType e)
{
    if(S.top-S.base==S.stacksize)      //栈满条件
    {
        printf("栈已满！\n");
        return false;
    }
    *S.top++=e;                       //先赋值，后自增
    //等价于 *S.top=e; S.top++;
    return true;
}

//出栈
bool Pop(SqStack &S, SElemType &e)
{
    if(StackEmpty(S))               //判断栈空 等价于 if(S.top==S.base)
    {
        printf("栈空！\n");
        return false;
    }
    e=*--S.top;                    //先自减，后赋值 S.top是始终指向栈顶元素的上一位置的
    //等价于 --S.top; e=*S.top;
    return true;
}

//读栈顶元素
bool GetTop(SqStack S, SElemType &e)  //不修改指针
{                                     //注意！读栈顶元素和出栈代码相同
    if(StackEmpty(S))                 //区别在于出栈是Pop(Stack &S)  栈S被引用，所以*--S.top会修改栈S中的top指针
    {                                 //而读栈顶元素是GetTop(Stack S) 栈S只是被传入，*--S.top并不会修改原先栈S中的top指针
        printf("栈空！\n");
        return false;
    }
    e=*--S.top;
    return true;
}

//***********************功能实现函数****************************//
//入栈功能
void PushStack(SqStack &S)
{
    int n;                    //用于入栈元素的个数
    SElemType e;              //用于入栈元素
    bool flag;
    printf("请输入入栈元素的个数：\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        printf("请输入第%d个元素的值：",i+1);
        cin>>e;
        flag=Push(S,e);
        if(flag)
            printf("%d已入栈!\n", e);
    }
}

//出栈功能
void PopStack(SqStack &S)
{
    int n;                    //用于出栈元素的个数
    SElemType e;              //用于出栈元素
    bool flag;
    printf("请输入出栈元素的个数：\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        flag=Pop(S,e);
        if(flag)
            printf("%d已出栈!\n", e);
    }
}

//读取栈顶元素功能
void GetTopStack(SqStack S)
{
    SElemType e;           //用于栈顶元素
    bool flag;
    flag=GetTop(S,e);
    if(flag)
        printf("栈顶元素为：%d\n",e);
}

//求栈长度功能
void GetStackLength(SqStack S)
{
    int n;               //用于栈的长度
    n=StackLength(S);
    printf("栈的长度：%d\n",n);
}

//菜单
void menu()
{
    printf("********1.入栈      2.出栈*********\n");
    printf("********3.取栈顶    4.栈长*********\n");
    printf("********5.清空栈    6.销毁栈*******\n");
    printf("************  0.退出  *************\n");
}

//主函数
int main()
{
    SqStack S;
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
            case 5:ClearStack(S);break;
            case 6:DestoryStack(S);break;
            default:printf("输入错误！！！\n");
        }
    }
    return 0;
}