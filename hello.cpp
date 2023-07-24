#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sstream>
using namespace std;
//创建一个字符串流对象
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
//把一个线索二叉树转换成一个JSON对象字符串
string toJson(ThreadTree T);

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
    
    //在可视化窗口输入toJson(T)来展示线索二叉树
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

//定义一个辅助函数，用来遍历线索二叉树并写入结点信息
void writeNodes(ThreadNode *n, stringstream &ss)
{
    //如果结点为空，直接返回
    if (n == NULL)
        return;

    //写入当前结点的id，用它的data字段表示
    ss << "{ \"id\": \"" << n->data << "\" },";

    //如果当前结点有左孩子，递归遍历左子树
    if (n->ltag == 0)
        writeNodes(n->lchild, ss);

    //如果当前结点有右孩子，递归遍历右子树
    if (n->rtag == 0)
        writeNodes(n->rchild, ss);
}

//定义一个辅助函数，用来遍历线索二叉树并写入边信息
void writeEdges(ThreadNode *n, stringstream &ss)
{
    //如果结点为空，直接返回
    if (n == NULL)
        return;

    //如果当前结点有左孩子，写入一条从当前结点到左孩子的边，并递归遍历左子树
    if (n->ltag == 0)
    {
        ss << "{ \"from\": \"" << n->data << "\", \"to\": \"" << n->lchild->data << "\" },";
        writeEdges(n->lchild, ss);
    }

    //如果当前结点有右孩子，写入一条从当前结点到右孩子的边，并递归遍历右子树
    if (n->rtag == 0)
    {
        ss << "{ \"from\": \"" << n->data << "\", \"to\": \"" << n->rchild->data << "\" },";
        writeEdges(n->rchild, ss);
    }
}

//把一个线索二叉树转换成一个JSON对象字符串
string toJson(ThreadTree T)
{
    //如果树为空，返回空字符串
    if (T == NULL)
        return "";

    //创建一个字符串流对象
    stringstream ss;

    //写入JSON对象的开始符号
    ss << "{";

    //写入kind属性，表示这是一个graph可视化器
    ss << "\"kind\": { \"graph\": true },";

    //写入nodes属性，表示结点数组
    ss << "\"nodes\": [";

    //从根结点开始遍历线索二叉树并写入结点信息
    writeNodes(T, ss);

    //删除最后一个多余的逗号
    ss.seekp(-1, ss.cur);

    //写入nodes属性的结束符号
    ss << "],";

    //写入edges属性，表示边数组
    ss << "\"edges\": [";

    //从根结点开始遍历线索二叉树并写入边信息
    writeEdges(T, ss);

    //删除最后一个多余的逗号
    ss.seekp(-1, ss.cur);

    //写入edges属性的结束符号
    ss << "]";

    //写入JSON对象的结束符号
    ss << "}";

    //返回字符串流中的字符串
    return ss.str();
}
