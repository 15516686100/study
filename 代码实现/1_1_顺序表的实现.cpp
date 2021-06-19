/*
Project: sequence_list(���ݽṹ-˳���)
CreateList(SqList &L,int n)            ������˳���L��˳�����n ���ܣ���������Ϊ��˳��� ʱ�临�Ӷȣ�O(n)
InitList(SqList &L)                    ������˳���L ���ܣ���ʼ�� ʱ�临�Ӷ�:O(1)
InsertList(SqList &L,int i,ElemType e) ����:˳���L,λ��i,Ԫ��e ���ܣ�λ��i������Ԫ��e ʱ�临�Ӷ�:O(n)
ListDelete(SqList &L,int i)            ����:˳���L,λ��i ���ܣ�ɾ��λ��i��Ԫ�� ʱ�临�Ӷ�:O(n)
LocateElem(SqList L,ElemType e)        ����:˳���L,Ԫ��e ���ܣ����ص�һ������e��Ԫ�ص�λ�� ʱ�临�Ӷ�:O(n)
Reverse(SqList &L)                     ������˳���L ���ú��� ��ԭ˳���ֱ�ӵ���
PrintList(SqList L)                    ����:˳���L ���ܣ�����L�������
SplitSort(SqList &L)                   ������˳���L ���ܣ��ֿ���ż�����ֿ�����
ClearList(SqList &L)                   ������˳���L ���ܣ����˳���
*/

#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#define MaxSize 100

using namespace std;
//˳������ݽṹ
typedef struct 
{
    int *data;                //����˳���Ԫ��
    int length;               //����˳�����
}SqList;

//************************������������*****************************//

//��ʼ��˳���
int InitList(SqList &L)
{
    L.data=(int*)malloc(sizeof(int)*MaxSize);    //��̬��������
    L.length=0;                                  //��ʼ������Ϊ0
    return 0;
}

//����˳�����ʼ��ǰn������
bool CreateList(SqList &L, int n)
{
    if(n<0 || n>MaxSize)
        return false;
    for(int i=0; i<n; i++)
    {
        printf("�������%dλ:\n", i+1); 
        scanf("%d", &L.data[i]);
        L.length++;
    }
}

//���뺯�� λ��i�������� i�Լ�i֮���Ԫ�غ���
bool InsertList(SqList &L, int i, int e)
{
    if(i<1 || i>L.length+1)                 //�жϲ���λ���Ƿ���Ч
    {
        printf("λ����Ч������\n");
        return false;
    }
    if(L.length>=MaxSize)                  //�жϴ���ռ��Ƿ�����
    {
        printf("��ǰ�ռ�����������\n");
        return false;
    }
    for(int j=L.length-1; j>=i-1; j--)   
    {//�����±��0��ʼ��˳����߼�λ�ô�1��ʼ��������1
        L.data[j+1]=L.data[j]; 
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

//ɾ������ ɾ��λ��i��Ԫ�� i֮���Ԫ������ǰ��
bool DeleteList(SqList &L, int i)
{
    if(i<1 || i>L.length)                 //�ж�ɾ��λ���Ƿ���Ч
    {
        printf("λ����Ч������\n");
        return false;
    }
    for(int j=i; j<=L.length-1; j++)
    {
        L.data[j-1]=L.data[j];
    }
    L.length--;
    return true;
}

//���Һ��� ��λ�ô�С������ң�����λ�ö����Ƿ����±�
int LocateData(SqList L, int e)
{
    for(int i=0; i<L.length; i++)
    {
        if(L.data[i]==e)
            return i+1;
    }
    return 0;
}

//���ú��� ��ԭ˳���ֱ�ӵ���
void Reverse(SqList &L)
{//��Ч�ʵĵ��ã��ռ临�Ӷ�ΪO(1)
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

//��ż�ֿ�����
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
            if(!flag)            //û�в�������
            {
                Even=L.length-1;   //ȫ����
                Odd=0;             //ȫż��
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

//������Ա�
void ClearList(SqList &L)
{
    L.length=0;
}


//***************************���ܺ���************************//
//������ܺ��� ��λ�ô�С�������˳�������Ԫ��
void PrintList(SqList L)
{
    printf("��ǰ˳�������Ԫ�أ�\n");
    for(int i=0;i<L.length;i++)
    {
        printf("%d  ", L.data[i]);
    }
    printf("\n");
}

//����˳�����
void Create(SqList &L)
{
    int n;
    bool flag;
    InitList(L);                   //��ʼ�����Ա�
    printf("������Ҫ������ѭ���ĳ���(>1):\n");
    scanf("%d",&n);
    flag=CreateList(L, n);
    if(flag)
    {
        printf("�����ɹ���\n");
        PrintList(L);
    }
    else
        printf("���볤�ȷǷ�\n");
}

//���빦�ܺ��� ����InserList���˳���Ԫ�ز��� ����PrintList�鿴�����Ľ��
void Insert(SqList &L)
{
    int index;
    int e;
    bool flag;
    printf("������Ҫ�����λ��:\n");
    scanf("%d", &index);
    printf("������Ҫ�����Ԫ��:\n");
    scanf("%d", &e);
    flag=InsertList(L, index, e);
    if (flag)
    {
        printf("����ɹ���\n");
        PrintList(L);
    }
    else
        printf("����Ƿ�");
}

//ɾ�����ܺ��� ɾ���ɹ������PrintList�鿴ɾ����Ľ��
void Delete(SqList &L)
{
    int index;
    bool flag;
    printf("��������Ҫɾ����λ��:\n");
    scanf("%d", &index);
    flag=DeleteList(L, index);
    if (flag)
    {
        printf("ɾ���ɹ���\n");
        PrintList(L);
    }
    else
        printf("λ�÷Ƿ���\n");
}

//���ҹ��ܺ��� 
void Search(SqList L)
{
    int e;
    int flag;
    printf("��������Ҫ���ҵ�ֵ:\n");
    scanf("%d", &e);
    flag=LocateData(L, e);
    if (flag)
    {
        printf("���ҳɹ���\n");
        printf("��Ԫ��λ��λ:%d\n", flag);
    }
    else
        printf("δ�ҵ���Ԫ�أ�\n");
}

//�˵�
void menu()
{
	printf("********1.����                        2.����*********\n");
	printf("********3.ɾ��                        4.����*********\n");
	printf("********5.����                        6.����ż����***\n");
	printf("********7.���                        8.���*********\n");
	printf("********9.�˳�                              *********\n");
}

int main()
{
	SqList L; int choice;
	InitList(L);
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
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
		default:printf("������󣡣���\n");
		}
	}
	return 0;
}