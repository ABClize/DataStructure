#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
//动态顺序表
typedef struct SqList
{
    int MaxSize;
    int length;
    int *data;
} SqList;

//输出当前顺序表
void Print_SqList(SqList L)
{
    printf("当前顺序表长度为：%d\n",L.length);
    printf("内容为：");
    for (int  i = 0; i < L.length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
//初始化
void InitList(SqList &L)
{
    L.data=(int*)malloc(InitSize*sizeof(int));
    L.MaxSize=InitSize;
    L.length=9;
    Print_SqList(L);
}
//增加最大容量
void IncreaseSize(SqList &L,int len)
{
    int *p=L.data;
    L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=p[i];//将数据复制到新区域
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
    Print_SqList(L);
}
//在第i个位置插入元素e
void ListInsert(SqList &L,int i,int e)
{
    if (L.length>=L.MaxSize)
    {
        printf("顺序表已满，无法插入!\n");
        Print_SqList(L);
        return;
    }
    if (i<=0||i>L.length+1)
    {
        printf("i的值不合法!\n");
        return;
    }
    else
    {
        for (int j = L.length; j >= i; j--)
        {
            L.data[j]=L.data[j-1];
        }
        L.data[i-1]=e;
        L.length++;
        Print_SqList(L);
        return;
    }
}
//删除第i个位置的元素e_deleted
void ListDelete(SqList L,int i,int &e_deleted)
{
    if (i<=0||i>L.length)
    {
        printf("i的值不合法!\n");
        return;
    }
    else
    {
        e_deleted=L.data[i-1];
        for (int j = i; j < L.length;j++)
        {
            L.data[j-1]=L.data[j];
        }
        L.length--;
        printf("成功删除第%d个元素，其值为%d\n",i,e_deleted);
        Print_SqList(L);
        return;
    }
}
//查找第i个元素
int GetElem(SqList L,int i)
{
    if (i<=0||i>L.length)
    {
        printf("i的值不合法!\n");
        return -1;
    }
    return L.data[i-1];
}
//查找表中第一个值为e的元素的位置
int LocateElem(SqList L,int e)
{
    for (int i = 0; i < L.length-1; i++)
    {
        if (L.data[i]==e)
        {
            return i+1;
        }
        
    }
    printf("表中没有值为%d的元素!\n",e);
    Print_SqList(L);
    return 0;
}
int main()
{
    SqList L;
    InitList(L);
    
    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=i;//全赋0
    }
    
    IncreaseSize(L,5);
    ListInsert(L,1,1);
    int e_deleted=-1;
    ListDelete(L,3,e_deleted);
    printf("元素为%d\n",GetElem(L,2));
    printf("位置为%d\n",LocateElem(L,5));
    return 0;
}