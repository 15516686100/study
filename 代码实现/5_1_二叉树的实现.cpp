#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#include<algorithm>
#include<iostream>
#define TElemType int
using namespace std;

//链式二叉树的数据结构
typedef struct BiTNode
{
    TElemType data;      //数据域
    struct BiTNode *lchild, *rchile;
}BiTNode, *BiTree;

//*********************基本操作函数***************//
//创建二叉树 先序创建
void InitTree(BiTree &T)
{
    TElemType e;
    cin>>e;
    if(-1==e)
        T=NULL;
    else
        T=new BiTNode;
        T->data=e;
        InitTree(T->lchild);
        InitTree(T->rchile);
}