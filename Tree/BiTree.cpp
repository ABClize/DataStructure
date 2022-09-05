#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree;

//��ʼ��һ��������
void InitBiTree(BiTree &T,int root_data);
//Ϊ��ǰ�������һ������
void add_lchild(BiTNode* n,int data);
//Ϊ��ǰ�������һ���Һ���
void add_rchild(BiTNode* n,int data);
//���ʽ��
void visit(BiTNode* n);
//�������
void PreOrder(BiTree T);
//�������
void InOrder(BiTree T);
//�������
void PostOrder(BiTree T);
//����һ����Ҫ�Ķ�����
void CreatBiTree(BiTree &T);

int main()
{
    BiTree T;
    CreatBiTree(T);
    printf("����������Ϊ��");
    PreOrder(T);
    printf("\n");
    printf("����������Ϊ��");
    InOrder(T);
    printf("\n");
    printf("����������Ϊ��");
    PostOrder(T);
    return 0;
}

void InitBiTree(BiTree &T,int root_data)
{
    BiTree root=(BiTNode*)malloc(sizeof(BiTNode));
    T=root;
    T->data=root_data;
    T->lchild=NULL;
    T->rchild=NULL;
}
void add_lchild(BiTNode* n,int data)
{
    BiTNode* p=(BiTNode*)malloc(sizeof(BiTNode));//�½��
    p->data=data;
    p->lchild=NULL;
    p->rchild=NULL;
    n->lchild=p;
}
void add_rchild(BiTNode* n,int data)
{
    BiTNode* p=(BiTNode*)malloc(sizeof(BiTNode));//�½��
    p->data=data;
    p->lchild=NULL;
    p->rchild=NULL;
    n->rchild=p;
}
void visit(BiTNode* n)
{
    printf("%d ",n->data);
}
void PreOrder(BiTree T)
{
    if (T!=NULL)
    {
        visit(T);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}
void InOrder(BiTree T)
{
    if (T!=NULL)
    {
        InOrder(T->lchild);
        visit(T);
        InOrder(T->rchild);
    }
}
void PostOrder(BiTree T)
{
    if (T!=NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
void CreatBiTree(BiTree &T)
{
    InitBiTree(T,1);
    add_lchild(T,2);
    add_rchild(T->lchild,4);
    add_lchild(T->lchild->rchild,6);
    add_rchild(T,3);
    add_rchild(T->rchild,5);
}