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

//��ʽ�����������ݽṹ
typedef struct BiTNode
{
    TElemType data;      //������
    struct BiTNode *lchild, *rchile;
}BiTNode, *BiTree;

//*********************������������***************//
//���������� ���򴴽�
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