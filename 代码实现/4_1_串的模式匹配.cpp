/*
    Project: sequence_string (顺序串的模式匹配)
    InitString(String &S)                    参数：链队Q 功能：初始化  时间复杂度O(1)
    CreatString(String &S,int n)             参数：顺序串S 长度n 功能：创建顺序串 时间复杂度O(n)
    Index(String S,String T)                 参数：主串S，模式串T 功能：暴力匹配 时间复杂度O(mn)
    IndexKMP(String S,String T,int next[])   参数：主串S，模式串T，next数组 功能：KMP算法模式匹配 时间复杂度O(m+n)
    GetNext(String T,int &next[])            参数：模式串T,next数组 功能：求next数组 
    GetNextVal(String T,int &nextval[])      参数：模式串T，nextval数组 功能：求nextval数组，对kmp算法进一步改进
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;


//顺序串的数据结构
typedef struct
{
    char *ch;                //按串长分配储存取，动态分配
    int length;              //串的长度
}String;

//***********************基本操作函数**********************//
//初始化顺序串
int InitString(String &S)
{
    S.ch=NULL;                             //置空
    S.length=0;                            //初始化长度为0
    return 0;
}

//创建顺序串
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
