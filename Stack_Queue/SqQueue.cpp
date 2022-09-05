#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5

typedef struct SqQueue
{
    int front;//队头
    int rear;//队尾
    int data[MaxSize];
}SqQueue;

//初始化队列Q
void InitQueue(SqQueue &Q);
//销毁队列
void DestroyQueue(SqQueue &Q);
//入队，若队列Q未满，将x加入使之成为新的队尾
void EnQueue(SqQueue &Q,int x);
//出队，若队列Q非空，删除队头元素，并用x返回
void DeQueue(SqQueue &Q,int &x);
//读队头元素，若Q非空，则将对头元素赋值给x
void GetHead(SqQueue Q,int &x);
//判断队列是否为空
bool QueueEmpty(SqQueue Q);
//判断队列是否满
bool QueueFull(SqQueue Q);

int main()
{
    SqQueue Q;
    InitQueue(Q);
    for (int i = 0; i < MaxSize; i++)
    {
        EnQueue(Q,i);
    }
    int x=-1;
    for (int i = 0; i < MaxSize; i++)
    {
        DeQueue(Q,x);
    }
    
    return 0;
}

void InitQueue(SqQueue &Q)
{
    Q.front=Q.rear=0;
}
bool QueueEmpty(SqQueue Q)
{
    if (Q.front==Q.rear)
    {
        return true;
    }
    return false;
}
bool QueueFull(SqQueue Q)
{
    if ((Q.rear+1)%MaxSize==Q.front)//这个+1是为了和判断队列是否为空进行区分，但这样无疑会使队列浪费一个空间单元
    {
        return true;
    }
    return false;
}
void EnQueue(SqQueue &Q,int x)
{
    if (QueueFull(Q))
    {
        printf("队列已满，无法插入！\n");
        return;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;//模除，以便Q满的时候让队尾指针回到0处
}
void DeQueue(SqQueue &Q,int &x)
{
    if (QueueEmpty(Q))
    {
        printf("队列已为空！\n");
        return;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
}