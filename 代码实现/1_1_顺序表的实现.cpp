/*
Project: sequence_list(数据结构-顺序表)
CreateList(SqList &L,int n)            参数：顺序表L，顺序表长度n 功能：创建长度为的顺序表 时间复杂度：O(n)
InitList(SqList &L)                    参数：顺序表L 功能：初始化 时间复杂度:O(1)
InsertList(SqList &L,int i,ElemType e) 参数:顺序表L,位置i,元素e 功能：位置i处插入元素e 时间复杂度:O(n)
ListDelete(SqList &L,int i)            参数:顺序表L,位置i 功能：删除位置i处元素 时间复杂度:O(n)
LocateElem(SqList L,ElemType e)        参数:顺序表L,元素e 功能：返回第一个等于e的元素的位置 时间复杂度:O(n)
Reverse(SqList &L)                     参数：顺序表L 倒置函数 将原顺序表直接倒置
PrintList(SqList L)                    参数:顺序表L 功能：遍历L，并输出
SplitSort(SqList &L)                   参数：顺序表L 功能：分开奇偶，并分开排序
ClearList(SqList &L)                   参数：顺序表L 功能：清空顺序表
*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MaxSize 100

using namespace std;
//顺序表数据结构
typedef struct 
{
    int *data;                //定义顺序表元素
    int length;               //定义顺序表长度
}SqList;

//************************基本操作函数*****************************//

//初始化顺序表
int InitList(SqList &L)
{
    L.data=(int*)malloc(sizeof(int)*MaxSize);    //动态分配数据
    L.length=0;                                  //初始化长度为0
    return 0;
}

//创建顺序表，初始化前n个数据
bool CreateList(SqList &L, int n)
{
    if(n<0 || n>MaxSize)
        return false;
    for(int i=0; i<n; i++)
    {
        printf("请输入第%d位:\n", i+1); 
        scanf("%d", &L.data[i]);
        L.length++;
    }
}

//插入函数 位置i插入数据 i以及i之后的元素后移
bool InsertList(SqList &L, int i, int e)
{
    if(i<1 || i>L.length+1)                 //判断插入位置是否有效
    {
        printf("位置无效！！！\n");
        return false;
    }
    if(L.length>=MaxSize)                  //判断储存空间是否已满
    {
        printf("当前空间已满！！！\n");
        return false;
    }
    for(int j=L.length-1; j>=i-1; j--)   
    {//数组下标从0开始，顺序表逻辑位置从1开始，因此相差1
        L.data[j+1]=L.data[j]; 
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

//删除函数 删除位置i的元素 i之后的元素依次前移
bool DeleteList(SqList &L, int i)
{
    if(i<1 || i>L.length)                 //判断删除位置是否有效
    {
        printf("位置无效！！！\n");
        return false;
    }
    for(int j=i; j<=L.length-1; j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

//查找函数 按位置从小到大查找，返回位置而不是返回下标
int LocateData(SqList L, int e)
{
    for(int i=0; i<L.length; i++)
    {
        if(L.data[i]==e)
            return i+1;
    }
    return 0;
}

//倒置函数 将原顺序表直接倒置
void Reverse(SqList &L)
{//高效率的倒置，空间复杂度为O(1)
    int temp;
    if(L.length)
    {
        for(int i=0; i<L.length/2; i++)
        {
            temp=L.data[i];
            L.data[i]=L.data[L.length-i-1];
            L.data[L.length-i-1]=temp;
        }
    }
}

//奇偶分开排序
void SplitSort(SqList &L)
{
    int Even=0;
    int Odd=L.length-1;
    int i;
    int j=L.length-1;
    bool flag=false;
    if(L.length)
    {
        for(i=0;i<j;i++,j--)
        {
            while(L.data[i] % 2 != 0)
                i++;
            while (L.data[j] % 2 != 0)
                j--;
            if(L.data[i] % 2 ==0 && L.data[j] % 2 != 0 && i<j)
            {
                int temp=L.data[i];
                L.data[i]=L.data[j];
                L.data[j]=temp;
                flag=true;
            }
            if(!flag)            //没有产生交换
            {
                Even=L.length-1;   //全奇数
                Odd=0;             //全偶数
            }
        }
    }
    if(flag)
    {
        for(int i=0;i<L.length;i++)
        {
            if(L.data[i] % 2 ==0)
            {
                Odd=i;
                Even=i-1;
                break;
            }
        }
    }
    sort(L.data, L.data+Even+1);
    sort(L.data+Odd, L.data+L.length);
}

//清空线性表
void ClearList(SqList &L)
{
    L.length=0;
}


//***************************功能函数************************//
//输出功能函数 按位置从小到大输出顺序表所有元素
void PrintList(SqList L)
{
    printf("当前顺序表所有元素：\n");
    for(int i=0;i<L.length;i++)
    {
        printf("%d  ", L.data[i]);
    }
    printf("\n");
}

//创建顺序表函数
void Create(SqList &L)
{
    int n;
    bool flag;
    InitList(L);                   //初始化线性表
    printf("请输入要创建的循序表的长度(>1):\n");
    scanf("%d",&n);
    flag=CreateList(L, n);
    if(flag)
    {
        printf("创建成功！\n");
        PrintList(L);
    }
    else
        printf("输入长度非法\n");
}

//插入功能函数 调用InserList完成顺序表元素插入 调用PrintList查看插入后的结果
void Insert(SqList &L)
{
    int index;
    int e;
    bool flag;
    printf("请输入要插入的位置:\n");
    scanf("%d", &index);
    printf("请输入要插入的元素:\n");
    scanf("%d", &e);
    flag=InsertList(L, index, e);
    if (flag)
    {
        printf("插入成功！\n");
        PrintList(L);
    }
    else
        printf("插入非法");
}

//删除功能函数 删除成功后调用PrintList查看删除后的结果
void Delete(SqList &L)
{
    int index;
    bool flag;
    printf("请输入需要删除的位置:\n");
    scanf("%d", &index);
    flag=DeleteList(L, index);
    if (flag)
    {
        printf("删除成功！\n");
        PrintList(L);
    }
    else
        printf("位置非法！\n");
}

//查找功能函数 
void Search(SqList L)
{
    int e;
    int flag;
    printf("请输入需要查找的值:\n");
    scanf("%d", &e);
    flag=LocateData(L, e);
    if (flag)
    {
        printf("查找成功！\n");
        printf("该元素位置位:%d\n", flag);
    }
    else
        printf("未找到该元素！\n");
}

//菜单
void menu()
{
	printf("********1.创建                        2.插入*********\n");
	printf("********3.删除                        4.查找*********\n");
	printf("********5.倒置                        6.分奇偶排序***\n");
	printf("********7.输出                        8.清空*********\n");
	printf("********9.退出                              *********\n");
}

int main()
{
	SqList L; int choice;
	InitList(L);
	while (1)
	{
		menu();
		printf("请输入菜单序号：\n");
		scanf("%d", &choice);
		if (9 == choice) break;
		switch (choice)
		{
		case 1:Create(L); break;
		case 2:Insert(L); break;
		case 3:Delete(L); break;
		case 4:Search(L); break;
		case 5:Reverse(L); break;
		case 6:SplitSort(L); break;
		case 7:PrintList(L); break;
		case 8:ClearList(L); break;
		default:printf("输入错误！！！\n");
		}
	}
	return 0;
}