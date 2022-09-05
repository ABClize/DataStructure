#include<stdio.h>
#include<stdlib.h>
#define InitSize 10
//��̬˳���
typedef struct SqList
{
    int MaxSize;
    int length;
    int *data;
} SqList;

//�����ǰ˳���
void Print_SqList(SqList L)
{
    printf("��ǰ˳�����Ϊ��%d\n",L.length);
    printf("����Ϊ��");
    for (int  i = 0; i < L.length; i++)
    {
        printf("%d ",L.data[i]);
    }
    printf("\n");
}
//��ʼ��
void InitList(SqList &L)
{
    L.data=(int*)malloc(InitSize*sizeof(int));
    L.MaxSize=InitSize;
    L.length=9;
    Print_SqList(L);
}
//�����������
void IncreaseSize(SqList &L,int len)
{
    int *p=L.data;
    L.data=(int*)malloc((L.MaxSize+len)*sizeof(int));
    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=p[i];//�����ݸ��Ƶ�������
    }
    L.MaxSize=L.MaxSize+len;
    free(p);
    Print_SqList(L);
}
//�ڵ�i��λ�ò���Ԫ��e
void ListInsert(SqList &L,int i,int e)
{
    if (L.length>=L.MaxSize)
    {
        printf("˳����������޷�����!\n");
        Print_SqList(L);
        return;
    }
    if (i<=0||i>L.length+1)
    {
        printf("i��ֵ���Ϸ�!\n");
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
//ɾ����i��λ�õ�Ԫ��e_deleted
void ListDelete(SqList L,int i,int &e_deleted)
{
    if (i<=0||i>L.length)
    {
        printf("i��ֵ���Ϸ�!\n");
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
        printf("�ɹ�ɾ����%d��Ԫ�أ���ֵΪ%d\n",i,e_deleted);
        Print_SqList(L);
        return;
    }
}
//���ҵ�i��Ԫ��
int GetElem(SqList L,int i)
{
    if (i<=0||i>L.length)
    {
        printf("i��ֵ���Ϸ�!\n");
        return -1;
    }
    return L.data[i-1];
}
//���ұ��е�һ��ֵΪe��Ԫ�ص�λ��
int LocateElem(SqList L,int e)
{
    for (int i = 0; i < L.length-1; i++)
    {
        if (L.data[i]==e)
        {
            return i+1;
        }
        
    }
    printf("����û��ֵΪ%d��Ԫ��!\n",e);
    Print_SqList(L);
    return 0;
}
int main()
{
    SqList L;
    InitList(L);
    
    for (int i = 0; i < L.length; i++)
    {
        L.data[i]=i;//ȫ��0
    }
    
    IncreaseSize(L,5);
    ListInsert(L,1,1);
    int e_deleted=-1;
    ListDelete(L,3,e_deleted);
    printf("Ԫ��Ϊ%d\n",GetElem(L,2));
    printf("λ��Ϊ%d\n",LocateElem(L,5));
    return 0;
}