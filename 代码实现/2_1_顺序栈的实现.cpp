/*
    Project: sequence_stack (���ݽṹ-˳��ջ)
	InitStack(SqStack &S) ������˳��ջS ���ܣ���ʼ��  ʱ�临�Ӷ�O(1)
    StackEmpty(SqStack S) ������˳��ջS ���ܣ��ж�˳��ջ�Ƿ�Ϊ�� ʱ�临�Ӷ�O(1)
    StackLength(SqStack S) ������˳��ջS ���ܣ���ȡ˳��ջ�ĳ��� ʱ�临�Ӷ�ΪO(1)
    ClearStack(SqStack &S) ������˳��ջS ���ܣ���˳��ջ������Ԫ����� ʱ�临�Ӷ�O(1)
    DestoryStack(SqStack &S) ������˳��ջS ���ܣ�����ջ�����ͷ�ջsռ�õĴ���ռ� ʱ�临�Ӷ�O(1)
	Push(SqStack &S,SElemType e) ������˳��ջS,Ԫ��e ���ܣ���e��ջ ʱ�临�Ӷ�:O(1)
	Pop(SqStack &S,SElemType &e) ������˳��ջS,Ԫ��e ���ܣ���ջ,e���ճ�ջԪ��ֵ ʱ�临�Ӷ�O(1)
	GetTop(SqStack S,SElemType &e) ������˳��ջS,Ԫ��e ���ܣ��õ�ջ��Ԫ�� ʱ�临�Ӷ�O(1)
*/
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
using namespace std;
#define MaxSize 100
#define Status int
#define SElemType int

//ջ�����ݽṹ
typedef struct 
{
    SElemType *base;        //ջ��ָ�� ʼ�ձ��ֲ���
    SElemType *top;         //ջ��ָ�� ʼ��ָ��ջ��Ԫ�ص���һ��λ��
    int stacksize;          //ջ���õ��������
}SqStack;

//*******************������������**********************//
//��ʼ������
Status InitStack(SqStack &S)
{
    S.base=new SElemType[MaxSize];  //��̬����������� C++���﷨�ṹ
    //s.base=(SElemType*)malloc(MaxSize*sizeof(SElemType));
    if(!S.base)
    {
        printf("����ʧ��!\n");
        return 0;
    }
    S.top=S.base;              //��ʼջ��ָ�����ջ��ָ��
    S.stacksize=MaxSize;       //����ջ������������
    return 1;
}

//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S)
{
    if(S.top==S.base)         //ջ�յı�־ջ��ָ�����ջ��ָ��
        return true;
    else
        return false;
}

//��˳��ջ�ĳ���
int StackLength(SqStack S)
{
    return S.top-S.base;     //˳��ջ�ĳ���Ϊջ��ָ���ջ��ָ��
}

//���˳��ջ
void ClearStack(SqStack &S)
{
    if(S.base)              //ջ��ָ����ָ��Ԫ��
        S.top=S.base;       //ջ��ָ��ָ��ջ��ָ��
}

//����˳��ջ
void DestoryStack(SqStack &S)
{
    if(S.base)
    {
        delete S.base;
        S.stacksize=0;
        S.base=S.top=NULL;
    }
}

//��ջ
bool Push(SqStack &S, SElemType e)
{
    if(S.top-S.base==S.stacksize)      //ջ������
    {
        printf("ջ������\n");
        return false;
    }
    *S.top++=e;                       //�ȸ�ֵ��������
    //�ȼ��� *S.top=e; S.top++;
    return true;
}

//��ջ
bool Pop(SqStack &S, SElemType &e)
{
    if(StackEmpty(S))               //�ж�ջ�� �ȼ��� if(S.top==S.base)
    {
        printf("ջ�գ�\n");
        return false;
    }
    e=*--S.top;                    //���Լ�����ֵ S.top��ʼ��ָ��ջ��Ԫ�ص���һλ�õ�
    //�ȼ��� --S.top; e=*S.top;
    return true;
}

//��ջ��Ԫ��
bool GetTop(SqStack S, SElemType &e)  //���޸�ָ��
{                                     //ע�⣡��ջ��Ԫ�غͳ�ջ������ͬ
    if(StackEmpty(S))                 //�������ڳ�ջ��Pop(Stack &S)  ջS�����ã�����*--S.top���޸�ջS�е�topָ��
    {                                 //����ջ��Ԫ����GetTop(Stack S) ջSֻ�Ǳ����룬*--S.top�������޸�ԭ��ջS�е�topָ��
        printf("ջ�գ�\n");
        return false;
    }
    e=*--S.top;
    return true;
}

//***********************����ʵ�ֺ���****************************//
//��ջ����
void PushStack(SqStack &S)
{
    int n;                    //������ջԪ�صĸ���
    SElemType e;              //������ջԪ��
    bool flag;
    printf("��������ջԪ�صĸ�����\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        printf("�������%d��Ԫ�ص�ֵ��",i+1);
        cin>>e;
        flag=Push(S,e);
        if(flag)
            printf("%d����ջ!\n", e);
    }
}

//��ջ����
void PopStack(SqStack &S)
{
    int n;                    //���ڳ�ջԪ�صĸ���
    SElemType e;              //���ڳ�ջԪ��
    bool flag;
    printf("�������ջԪ�صĸ�����\n");
    cin>>n;
    for(int i=0;i<n;i++)
    {
        flag=Pop(S,e);
        if(flag)
            printf("%d�ѳ�ջ!\n", e);
    }
}

//��ȡջ��Ԫ�ع���
void GetTopStack(SqStack S)
{
    SElemType e;           //����ջ��Ԫ��
    bool flag;
    flag=GetTop(S,e);
    if(flag)
        printf("ջ��Ԫ��Ϊ��%d\n",e);
}

//��ջ���ȹ���
void GetStackLength(SqStack S)
{
    int n;               //����ջ�ĳ���
    n=StackLength(S);
    printf("ջ�ĳ��ȣ�%d\n",n);
}

//�˵�
void menu()
{
    printf("********1.��ջ      2.��ջ*********\n");
    printf("********3.ȡջ��    4.ջ��*********\n");
    printf("********5.���ջ    6.����ջ*******\n");
    printf("************  0.�˳�  *************\n");
}

//������
int main()
{
    SqStack S;
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
            case 5:ClearStack(S);break;
            case 6:DestoryStack(S);break;
            default:printf("������󣡣���\n");
        }
    }
    return 0;
}