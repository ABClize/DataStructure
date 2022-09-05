#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct SqStack
{
    int data[MaxSize];//���ջ�е�Ԫ��
    int top;//ջ��ָ��
}SqStack;

//��ʼ��һ����ջS
void InitStack(SqStack &S);
//�ж�ջ�Ƿ�Ϊ��
bool StackEmpty(SqStack S);
//��ջ����ջδ������x�����Ϊջ��
void Push(SqStack &S,int x);
//��ջ����ջ�ǿգ��򵯳�ջ��Ԫ�ز���x_popped����
void Pop(SqStack &S,int &x_popped);
//��ջ��Ԫ�أ���ջ�ǿ�����x_top����ջ��Ԫ��
void GetTop(SqStack S,int &x_top);
//����ջ�����ͷ�ջSռ�õĴ洢�ռ�
void DestroyStack(SqStack &S);

int main()
{
    SqStack S;
    InitStack(S);
    for (int i = 0; i < MaxSize; i++)
    {
        Push(S,i);
    }
    int x_popped;
    int x_top;
    for (int i = 0; i < MaxSize-4; i++)
    {
        Pop(S,x_popped);
        printf("%d\n",x_popped);
    }
    GetTop(S,x_top);
    DestroyStack(S);
    return 0;
}

void InitStack(SqStack &S)
{
    S.top=-1;
}
bool StackEmpty(SqStack S)
{
    if (S.top==-1)
    {
        return true;
    }
    return false;
}
void Push(SqStack &S,int x)
{
    if (S.top>=MaxSize-1)
    {
        printf("ջ�������޷�ѹջ!\n");
        return;
    }
    S.top++;
    S.data[S.top]=x;
}
void Pop(SqStack &S,int &x_popped)
{
    if (StackEmpty(S))
    {
        printf("ջΪ�գ�\n");
        return;
    }
    x_popped=S.data[S.top];
    S.top--;//��ʱֻ�Ǵ��߼���ɾ���˸����ݣ���ʵ�����ݻ��������ڴ���
}
void GetTop(SqStack S,int &x_top)
{
    if (StackEmpty(S))
    {
        printf("ջΪ�գ�\n");
        return;
    }
    x_top=S.data[S.top];
}
void DestroyStack(SqStack &S)
{
    S.top=-1;
}