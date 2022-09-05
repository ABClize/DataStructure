#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode,*LinkList;

//��ʼ��һ���յĵ�������ͷ��㣩
void InitList(LinkList &L);
//��ӡ��ǰ������
void Print_LinkList(LinkList L);
//��p���������Ԫ��e
void InsertNextNode(LNode* p,int e);
//��p���ǰ�����Ԫ��e
void InsertPriorNode(LNode* p,int e);
//�ڵ�i��λ�ò���Ԫ��e
void ListInsert(LinkList &L,int i,int e);
//ɾ�����е�i��Ԫ�ز�����ֵ����e_deleted��
void ListDelete(LinkList &L,int i,int &e_deleted);
//ɾ��ָ�����p������д���޷�������ֻʣһ����������������Ե�ʱ�������ôд
void DeleteNode(LinkList &L,LNode* p);
//���ҵ�i����㣬�����ظý���ָ��
LNode* GetElem(LinkList L,int i);
//�ҵ����е�һ��ֵΪe�Ľ�㣬�����ظý���ָ��
LNode* LocateElem(LinkList L,int e);
//���
int Length(LinkList L);
//β�巨����������
void List_TailInsert(LinkList &L);
//ͷ�巨����������
void List_HeadInsert(LinkList &L);
//�����������
LinkList Reverse_LinkList(LinkList L);
int main()
{
    LinkList L;
    //List_TailInsert(L);
    List_HeadInsert(L);
    int e_deleted=-1;
    ListDelete(L,3,e_deleted);
    //printf("%d\n",LocateElem(L,10000)->data);
    printf("���ú�ĵ�����Ϊ��");
    Print_LinkList(Reverse_LinkList(L));
    printf("��ǰ��ĳ���Ϊ%d\n",Length(L));
    return 0;
 }

void InitList(LinkList &L)
{
    L=(LNode*)malloc(sizeof(LNode));//L��ͷָ�룬ָ��ͷ�ڵ�
    L->next=NULL;//Lָ���ͷ�ڵ��nextΪ�գ�ע�ⲻ��L.next��L��next��Ϊ��
}
void Print_LinkList(LinkList L)
{
    LNode* p=L->next;
    printf("��ǰ����������Ϊ��");
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
        printf("pΪ�գ��ý�㲻���ڣ��޷�����������\n");
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
        printf("pΪ�գ��ý�㲻���ڣ��޷�����ǰ�����\n");
        return;
    }
    LNode* temp=(LNode*)malloc(sizeof(LNode));
    temp->next=p->next;
    p->next=temp;
    temp->data=p->data;//pָ���data���Ƶ�tempָ���data
    p->data=e;//��e����pָ���data
}
void ListInsert(LinkList &L,int i,int e)
{
    if (i<1)
    {
        printf("i��ֵ�Ƿ���\n");
        return;
    }
    LNode* p=GetElem(L,i-1);//�ҵ���i-1�����
    if (p==NULL)//���pָ����ǿյģ�˵���Ѿ�������������
    {
        printf("i��ֵ�Ƿ���\n");
        return;
    }
    InsertNextNode(p,e);
    printf("�ɹ��ڵ�%d��λ�ò���Ԫ��%d\n",i,e);
    Print_LinkList(L);
}
void ListDelete(LinkList &L,int i,int &e_deleted)
{
    if (i<1)
    {
        printf("i��ֵ�Ƿ���\n");
        return;
    }
    LNode* p=GetElem(L,i-1);//�ҵ���i-1�����
    if (p==NULL)//���pָ����ǿյģ�˵���Ѿ�������������
    {
        printf("i��ֵ�Ƿ���\n");
        return;
    }
    LNode* q=p->next;//qΪҪɾ���Ľ��
    e_deleted=q->data;
    p->next=q->next;
    free(q);
    printf("�ɹ�ɾ����%d��Ԫ��%d\n",i,e_deleted);
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
        if (p==NULL)//���pָ����ǿյģ�˵���Ѿ�������������
        {
            return NULL;
        }
    }
    return p;
}
LNode* LocateElem(LinkList L,int e)
{
    LNode* p=L->next;//�ӵ�һ����㿪ʼ
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
    LNode* tail=L;//β���
    printf("�������1��Ԫ�ص�ֵ��");
    scanf("%d",&e);
    while (e!=999)
    {
        InsertNextNode(tail,e);
        tail=tail->next;
        Print_LinkList(L);
        count++;
        printf("�������%d��Ԫ�ص�ֵ��",count);
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
    printf("�������1��Ԫ�ص�ֵ��");
    scanf("%d",&e);
    while (e!=999)
    {
        InsertNextNode(Head,e);
        Print_LinkList(L);
        count++;
        printf("�������%d��Ԫ�ص�ֵ��",count);
        scanf("%d",&e);
    }
}
LinkList Reverse_LinkList(LinkList L)
{
    LNode* p;
    LNode* r;//��ֹ����
    p=L->next;
    L->next=NULL;//��һ����ͷ��㵥���ó������ÿգ��ÿպ���Ҫ��
    while (p!=NULL)
    {
        r=p->next;
        p->next=L->next;
        L->next=p;
        p=r;//ע�ⲻ��дp=p->next
    }
    return L;
}