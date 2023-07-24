#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*LinkList;

//初始化一个空的单链表（带头结点）
void InitList(LinkList &L);
//打印当前单链表
void Print_LinkList(LinkList L);
//在p结点后面插入元素e
void InsertNextNode(LNode* p,int e);
//在p结点前面插入元素e
void InsertPriorNode(LNode* p,int e);
//在第i个位置插入元素e
void ListInsert(LinkList &L,int i,int e);
//删除表中第i个元素并将其值放在e_deleted中
void ListDelete(LinkList &L,int i,int &e_deleted);
//删除指定结点p，这种写法无法适用于只剩一个结点的情况，但考试的时候可以这么写
void DeleteNode(LinkList &L,LNode* p);
//查找第i个结点，并返回该结点的指针
LNode* GetElem(LinkList L,int i);
//找到表中第一个值为e的结点，并返回该结点的指针
LNode* LocateElem(LinkList L,int e);
//求表长
int Length(LinkList L);
//尾插法建立单链表
void List_TailInsert(LinkList &L);
//头插法建立单链表
void List_HeadInsert(LinkList &L);
//单链表的逆置
LinkList Reverse_LinkList(LinkList L);
int main()
{
    LinkList L;
    //List_TailInsert(L);
    List_HeadInsert(L);
    int e_deleted=-1;
    ListDelete(L,3,e_deleted);
    //printf("%d\n",LocateElem(L,10000)->data);
    printf("逆置后的单链表为：");
    Print_LinkList(Reverse_LinkList(L));
    printf("当前表的长度为%d\n",Length(L));
    return 0;
 }

void InitList(LinkList &L)
{
    L=(LNode*)malloc(sizeof(LNode));//L是头指针，指向头节点
    L->next=NULL;//L指向的头节点的next为空，注意不是L.next（L的next）为空
}
void Print_LinkList(LinkList L)
{
    LNode* p=L->next;
    printf("当前单链表内容为：");
    while (p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
void InsertNextNode(LNode* p,int e)
{
    if (p==NULL)
    {
        printf("p为空，该结点不存在，无法在其后面插入\n");
        return;
    }
    LNode* temp=(LNode*)malloc(sizeof(LNode));
    temp->data=e;
    temp->next=p->next;
    p->next=temp;
}
void InsertPriorNode(LNode* p,int e)
{
    if (p==NULL)
    {
        printf("p为空，该结点不存在，无法在其前面插入\n");
        return;
    }
    LNode* temp=(LNode*)malloc(sizeof(LNode));
    temp->next=p->next;
    p->next=temp;
    temp->data=p->data;//p指向的data复制到temp指向的data
    p->data=e;//用e覆盖p指向的data
}
void ListInsert(LinkList &L,int i,int e)
{
    if (i<1)
    {
        printf("i的值非法！\n");
        return;
    }
    LNode* p=GetElem(L,i-1);//找到第i-1个结点
    if (p==NULL)//如果p指向的是空的，说明已经超过链表长度了
    {
        printf("i的值非法！\n");
        return;
    }
    InsertNextNode(p,e);
    printf("成功在第%d个位置插入元素%d\n",i,e);
    Print_LinkList(L);
}
void ListDelete(LinkList &L,int i,int &e_deleted)
{
    if (i<1)
    {
        printf("i的值非法！\n");
        return;
    }
    LNode* p=GetElem(L,i-1);//找到第i-1个结点
    if (p==NULL)//如果p指向的是空的，说明已经超过链表长度了
    {
        printf("i的值非法！\n");
        return;
    }
    LNode* q=p->next;//q为要删除的结点
    e_deleted=q->data;
    p->next=q->next;
    free(q);
    printf("成功删除第%d个元素%d\n",i,e_deleted);
    Print_LinkList(L);
    return;
}
void DeleteNode(LinkList &L,LNode* p)
{
    LNode* q=p->next;
    p->data=q->data;
    p->next=q->next;
    free(q);
}
LNode* GetElem(LinkList L,int i)
{
    if (i<0)
    {
        return NULL;
    }
    LNode* p=L;
    for (int j = 0; j < i; j++)
    {
        p=p->next;
        if (p==NULL)//如果p指向的是空的，说明已经超过链表长度了
        {
            return NULL;
        }
    }
    return p;
}
LNode* LocateElem(LinkList L,int e)
{
    LNode* p=L->next;//从第一个结点开始
    while (p!=NULL)
    {
        if (p->data==e)
        {
            return p;
        }
        p=p->next;
    }
    return NULL;
}
int Length(LinkList L)
{
    int count=0;
    LNode* p=L->next;
    while (p!=NULL)
    {
        p=p->next;
        count++;
    }
    return count;
}
void List_TailInsert(LinkList &L)
{
    InitList(L);
    int e=-1;
    int count=1;
    LNode* tail=L;//尾结点
    printf("请输入第1个元素的值：");
    scanf("%d",&e);
    while (e!=999)
    {
        InsertNextNode(tail,e);
        tail=tail->next;
        Print_LinkList(L);
        count++;
        printf("请输入第%d个元素的值：",count);
        scanf("%d",&e);
    }
    tail->next=NULL;
}
void List_HeadInsert(LinkList &L)
{
    InitList(L);
    LNode* Head=L;
    int e=-1;
    int count=1;
    printf("请输入第1个元素的值：");
    scanf("%d",&e);
    while (e!=999)
    {
        InsertNextNode(Head,e);
        Print_LinkList(L);
        count++;
        printf("请输入第%d个元素的值：",count);
        scanf("%d",&e);
    }
}
LinkList Reverse_LinkList(LinkList L)
{
    LNode* p;
    LNode* r;//防止断链
    p=L->next;
    L->next=NULL;//这一步把头结点单独拿出来并置空，置空很重要！
    while (p!=NULL)
    {
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;//注意不能写p=p->next
    }
    return L;
}