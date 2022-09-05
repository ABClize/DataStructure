#include<stdio.h>
#include<stdlib.h>

typedef struct DNode
{
    int data;
    struct DNode *prior,*next;
}DNode,*DLinklist;

//��ʼ��˫������ͷ��㣩
void InitDLinklist(DLinklist &L);
//��p���֮�����s���
void InsertNextDNode(DNode* p,DNode* s);
//ɾ��p���ĺ�̽��q
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