#include <stdio.h>
#include <stdlib.h>

typedef struct ThreadNode
{
    char data;
    ThreadNode *lchild, *rchild;
    int ltag, rtag; // ltag=1表示指向前驱，rtag=1表示指向后继
} ThreadNode, *ThreadTree;

//初始化一个线索二叉树
void InitThreadTree(ThreadTree &T, char root_data);
//为当前结点新增一个左孩子
void add_lchild(ThreadNode *n, char data);
//为当前结点新增一个右孩子
void add_rchild(ThreadNode *n, char data);

int main()
{
    // string myGraphJson = "{\"kind\":{\"graph\":true},"
    //                      "\"nodes\":[{\"id\":\"12\"},{\"id\":\"2\"},{\"id\":\"T\"}],"
    //                      "\"edges\":[{\"from\":\"12\",\"to\":\"2\"}]}";

    ThreadTree T;
    InitThreadTree(T, 'A');
    add_lchild(T, 'B');
    add_rchild(T->lchild, 'D');
    add_rchild(T, 'C');
    add_lchild(T->rchild, 'E');
    return 0;
}
void InitThreadTree(ThreadTree &T, char root_data)
{
    T = (ThreadNode *)malloc(sizeof(ThreadNode));
    T->data = root_data;
    T->lchild = NULL;
    T->rchild = NULL;
    T->ltag = 0;
    T->rtag = 0;
}
void add_lchild(ThreadNode *n, char data)
{
    n->ltag = 0;
    ThreadNode *p = (ThreadNode *)malloc(sizeof(ThreadNode));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    n->lchild = p;
}
void add_rchild(ThreadNode *n, char data)
{
    n->rtag = 0;
    ThreadNode *p = (ThreadNode *)malloc(sizeof(ThreadNode));
    p->data = data;
    p->lchild = NULL;
    p->rchild = NULL;
    n->rchild = p;
}