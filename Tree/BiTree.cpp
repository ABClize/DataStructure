#include<stdio.h>
#include<stdlib.h>

typedef struct BiTNode
{
    int data;
    struct BiTNode *lchild,*rchild; 
}BiTNode,*BiTree;

//初始化一个二叉树
void InitBiTree(BiTree &T,int root_data);
//为当前结点新增一个左孩子
void add_lchild(BiTNode* n,int data);
//为当前结点新增一个右孩子
void add_rchild(BiTNode* n,int data);
//访问结点
void visit(BiTNode* n);
//先序遍历
void PreOrder(BiTree T);
//中序遍历
void InOrder(BiTree T);
//后序遍历
void PostOrder(BiTree T);
//创建一个想要的二叉树
void CreatBiTree(BiTree &T);

int main()
{
    BiTree T;
    CreatBiTree(T);
    printf("先序遍历结果为：");
    PreOrder(T);
    printf("\n");
    printf("中序遍历结果为：");
    InOrder(T);
    printf("\n");
    printf("后序遍历结果为：");
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
    BiTNode* p=(BiTNode*)malloc(sizeof(BiTNode));//新结点
    p->data=data;
    p->lchild=NULL;
    p->rchild=NULL;
    n->lchild=p;
}
void add_rchild(BiTNode* n,int data)
{
    BiTNode* p=(BiTNode*)malloc(sizeof(BiTNode));//新结点
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