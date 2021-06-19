/*
    Project: sequence_string (˳�򴮵�ģʽƥ��)
    InitString(String &S)                    ����������Q ���ܣ���ʼ��  ʱ�临�Ӷ�O(1)
    CreatString(String &S,int n)             ������˳��S ����n ���ܣ�����˳�� ʱ�临�Ӷ�O(n)
    Index(String S,String T)                 ����������S��ģʽ��T ���ܣ�����ƥ�� ʱ�临�Ӷ�O(mn)
    IndexKMP(String S,String T,int next[])   ����������S��ģʽ��T��next���� ���ܣ�KMP�㷨ģʽƥ�� ʱ�临�Ӷ�O(m+n)
    GetNext(String T,int &next[])            ������ģʽ��T,next���� ���ܣ���next���� 
    GetNextVal(String T,int &nextval[])      ������ģʽ��T��nextval���� ���ܣ���nextval���飬��kmp�㷨��һ���Ľ�
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;


//˳�򴮵����ݽṹ
typedef struct
{
    char *ch;                //���������䴢��ȡ����̬����
    int length;              //���ĳ���
}String;

//***********************������������**********************//
//��ʼ��˳��
int InitString(String &S)
{
    S.ch=NULL;                             //�ÿ�
    S.length=0;                            //��ʼ������Ϊ0
    return 0;
}

//����˳��
bool CreatString(String &S, const char *chars)
{
    int i=0;
    if(chars==NULL)
        return false;
    while(chars[i]!='\0')
        i++;
    S.length=i;
    if(S.ch!=NULL)
        free(S.ch);
    S.ch=(char*)malloc(sizeof(char)*(S.length+1));
    if(S.ch==NULL)
        return false;
    for(int j=1;j<=S.length;j++)
        S.ch[j]=chars[j-1];
    return true;
}

int main()
{
    char *ch;
    cin>>ch;
    String S;
    InitString(S);
    bool flag;
    flag=CreatString(S,ch);
    if(flag)
        printf("Yes");
    else
        printf("No");
    return 0;
}
