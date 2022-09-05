#include<stdio.h>
#include<stdlib.h>
#define MaxSize 5

typedef struct SqQueue
{
    int front;//��ͷ
    int rear;//��β
    int data[MaxSize];
}SqQueue;

//��ʼ������Q
void InitQueue(SqQueue &Q);
//���ٶ���
void DestroyQueue(SqQueue &Q);
//��ӣ�������Qδ������x����ʹ֮��Ϊ�µĶ�β
void EnQueue(SqQueue &Q,int x);
//���ӣ�������Q�ǿգ�ɾ����ͷԪ�أ�����x����
void DeQueue(SqQueue &Q,int &x);
//����ͷԪ�أ���Q�ǿգ��򽫶�ͷԪ�ظ�ֵ��x
void GetHead(SqQueue Q,int &x);
//�ж϶����Ƿ�Ϊ��
bool QueueEmpty(SqQueue Q);
//�ж϶����Ƿ���
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
    if ((Q.rear+1)%MaxSize==Q.front)//���+1��Ϊ�˺��ж϶����Ƿ�Ϊ�ս������֣����������ɻ�ʹ�����˷�һ���ռ䵥Ԫ
    {
        return true;
    }
    return false;
}
void EnQueue(SqQueue &Q,int x)
{
    if (QueueFull(Q))
    {
        printf("�����������޷����룡\n");
        return;
    }
    Q.data[Q.rear]=x;
    Q.rear=(Q.rear+1)%MaxSize;//ģ�����Ա�Q����ʱ���ö�βָ��ص�0��
}
void DeQueue(SqQueue &Q,int &x)
{
    if (QueueEmpty(Q))
    {
        printf("������Ϊ�գ�\n");
        return;
    }
    x=Q.data[Q.front];
    Q.front=(Q.front+1)%MaxSize;
}