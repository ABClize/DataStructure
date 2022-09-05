#include<stdio.h>
#include<stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinklist;

//初始化双链表（带头结点）
void InitDLinklist(DLinklist &L);
//在p结点之后插入s结点
void InsertNextDNode(DNode* p,DNode* s);
//删除p结点的后继结点q
void DeleteNextDNode(DNode* p);

int main()
{
    DLinklist L;
    InitDLinklist(L);
    return 0;
}

void InitDLinklist(DLinklist &L)
{
    L=(DNode*)malloc(sizeof(DNode));
    L->prior=NULL;
    L->next=NULL;
}
void InsertNextDNode(DNode* p,DNode* s)
{
    s->next=p->next;
    p->next->prior=s;
    p->next=s;
    s->prior=p;
}
void DeleteNextDNode(DNode* p)
{
    DNode* q=p->next;
    p->next=q->next;
    q->next->prior=p;
    free(q);
}