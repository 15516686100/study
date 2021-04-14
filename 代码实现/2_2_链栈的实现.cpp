/*
    Project: single_linked_stack (���ݽṹ ��ջ)
    InitStack(LinkStack &S) ��������ջS ���ܣ���ʼ��  ʱ�临�Ӷ�O(1)
    StackEmpty(LinkStack S) ��������ջS ���ܣ��ж���ջ�Ƿ�Ϊ�� ʱ�临�Ӷ�ΪO(1)
	StackLength(LinkStack S) ��������ջS ���ܣ�����ջ��Ԫ�صĸ��� ʱ�临�Ӷ�O(n) 
	Push(LinkStack &S,SElemType e) ��������ջS,Ԫ��e ���ܣ���e��ջ ʱ�临�Ӷ�:O(1)
	Pop(LinkStack &S,SElemType &e) ��������ջS,Ԫ��e ���ܣ�ջ����ջ,e���ճ�ջԪ��ֵ ʱ�临�Ӷ�O(1)
	GetTop(LinkStack &S,SElemType &e) ��������ջS,Ԫ��e ���ܣ��õ�ջ��Ԫ�� ʱ�临�Ӷ�O(1)
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
#define Status int
#define SElemType int

//��ջ�����ݽṹ
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStack;

//*****************������������*****************//
//��ʼ������
void InitStack(LinkStack &S)
{
    S=NULL;                   //���ɿ���ջ����ջû��ͷ��㣬ͷָ��ֱ��ָ��ջ��Ԫ��
}

//�ж���ջ�Ƿ�Ϊ��
bool StackEmpty(LinkStack S)
{
    if(S==NULL)             //ͷָ��ָ��գ�˵����ջ��û��Ԫ��
        return true;
    else
        return false;
}

//����ջ����
int StackLength(LinkStack S)
{
    int n=0;
    while(S!=NULL)
    {
        S=S->next;
        n++;
    }
    return n;          //n������ջ��Ԫ�صĸ��� 
}

//��ջ ��ջΪ��ʽ����ṹ��������ջ�����������ջû�н�ֹ����
int Push(LinkStack &S,SElemType e)
{
    StackNode *p;
    p=new StackNode;          //�����½�㲢���ٿռ�
    p->data=e;                //���½ڵ���ֵ����Ϊe
    p->next=S;                //�½�����ջ��
    S=p;                      //�޸�ջ��ָ��
    return 1;
}

//��ջ ջ��Ԫ����Ԫ��e����
bool Pop(LinkStack &S, SElemType &e)
{
    StackNode *p;
    p=new StackNode;
    if(StackEmpty(S))      //ջ�� 
        return false;
    e=S->data;            //S��ǰָ��ջ������e����ջ����Ԫ��ֵ
    p=S;                  //�ý��pָ��ջ����delete p֮��ջ������ͷţ��൱��ɾ����ʱ��ջ���ռ�
    S=S->next;            //�����Sָ����һ��㣬��Ϊ�µ�ջ�����
//    delete p;
    return true;
    
}

//��ȡջ��Ԫ��
bool GetTop(LinkStack S, SElemType &e)
{
    if(StackEmpty(S))
    {
        printf("ջ�գ�\n");
        return false;
    }
    e=S->data;
    return true;
}

//****************����ʵ�ֺ���******************//
//��ջ����
void PushStack(LinkStack &S)
{
    int n;              //���ڱ�ʾ��ջԪ�صĸ���
    SElemType e;        //���ڱ�ʾ��ջԪ�ص�ֵ
    bool flag;
    printf("��������Ҫ��ջԪ�صĸ���:\n");
    cin>>n;
    for(int i=0; i<n; i++)
    {
        printf("�������%d��Ԫ�ص�ֵ��",i+1);
        cin>>e;
        flag=Push(S,e);
        if(flag)
            printf("%d����ջ��\n",e);
    }
}

//��ջ����
void PopStack(LinkStack &S)
{
    int n;              //���ڱ�ʾ��ջԪ�صĸ���
    SElemType e;        //���ڱ�ʾ��ջԪ�ص�ֵ
    bool flag;
    printf("��������Ҫ��ջԪ�صĸ���:\n");
    cin>>n;
    for(int i=0; i<n; i++)
    {
        flag=Pop(S,e);
        if(flag)
            printf("%d�ѳ�ջ��\n",e);
        else
            break;
    }
}

//��ȡջ��Ԫ�ع���
void GetTopStack(LinkStack S)
{
    SElemType e;
    bool flag;
    flag=GetTop(S,e);
    if(flag)
        printf("ջ��Ԫ��Ϊ%d!\n",e);
}

//��ջ���ȹ���
void GetStackLength(LinkStack S)
{
    int n;               //���ڱ���ջ���ȵı���ֵ
    n=StackLength(S);
    printf("ջ�ĳ���Ϊ%d\n",n);
}

//�˵�
void menu()
{
   printf("********1.Ԫ����ջ      2.Ԫ�س�ջ*********\n");
   printf("********3.ȡջ��Ԫ��    4.��ջ����*********\n");
   printf("****************  0.�˳�  ****************\n");
}

//������
int main()
{
    LinkStack S;
    int choice;
    InitStack(S);
    while(1)
    {
        menu();
        printf("������˵���ţ�\n");
        scanf("%d",&choice);
        if(choice==0) break;
        switch(choice)
        {
            case 1:PushStack(S);break;
            case 2:PopStack(S);break;
            case 3:GetTopStack(S);break;
            case 4:GetStackLength(S);break;
            default:printf("������󣡣���\n");
        }
    }
    return 0;
}