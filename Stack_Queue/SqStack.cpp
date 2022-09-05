#include<stdio.h>
#include<stdlib.h>

#define MaxSize 10

typedef struct SqStack
{
    int data[MaxSize];//存放栈中的元素
    int top;//栈顶指针
}SqStack;

//初始化一个空栈S
void InitStack(SqStack &S);
//判断栈是否为空
bool StackEmpty(SqStack S);
//进栈，若栈未满，则将x加入成为栈顶
void Push(SqStack &S,int x);
//出栈，若栈非空，则弹出栈顶元素并用x_popped返回
void Pop(SqStack &S,int &x_popped);
//读栈顶元素，若栈非空则用x_top返回栈顶元素
void GetTop(SqStack S,int &x_top);
//销毁栈，并释放栈S占用的存储空间
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
        printf("栈已满，无法压栈!\n");
        return;
    }
    S.top++;
    S.data[S.top]=x;
}
void Pop(SqStack &S,int &x_popped)
{
    if (StackEmpty(S))
    {
        printf("栈为空！\n");
        return;
    }
    x_popped=S.data[S.top];
    S.top--;//此时只是从逻辑上删除了该数据，其实该数据还残留在内存中
}
void GetTop(SqStack S,int &x_top)
{
    if (StackEmpty(S))
    {
        printf("栈为空！\n");
        return;
    }
    x_top=S.data[S.top];
}
void DestroyStack(SqStack &S)
{
    S.top=-1;
}