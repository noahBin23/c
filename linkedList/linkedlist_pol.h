#include<stdlib.h>
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef struct{
	float coef; //系数
	int expn;//指数
}ElemType,term;

typedef struct LNode{
	//节点类型
	ElemType data;
	struct LNode *next;
}*Link,*Position;

typedef struct{
	Link head,tail;
	int len; //指示线性链表中元素数据的个数
}LinkList;

typedef LinkList polynomial;

/*
 *分配由p指向的值为e的节点，并返回OK，分配失败返回ERROR
 * */
Status makeNode(Link *p,ElemType e);

int ListLength(LinkList L);  //指示线性表中元素的个数
/*
 *释放p所指的节点
 * */
void FreeNode(Link *p);

/**
 *构造一个空的线性链表L
 * */
Status InitList(LinkList *L);

/**
 *销毁线性链表L，L不再存在
 * */

Status DestoryList(LinkList *L);

/**
 *将线性链表L重置为空表，并释放原链表空间节点
 * */
Status ClearList(LinkList *L);

/**
 *已知h指向线性链表头节点，将s所指节点插入再第一个节点之前
 * */
Status InsFirst(Link h,Link q);  //TODO

/**
 *已知h指向线性表的头节点，删除连表中的第一个节点并以q返回
 * */
Status DelFirst(Link h,Link *q); //TODO

/*
 *将指针s所指的遗传节点连接在线性链表L的最后一个节点
 之后，并改变链表L的尾节点指向新的尾节点
 * **/
Status Append(LinkList *L,Link s); // TODO

/**
 *删除线性链表L中的尾节点并以q返回，改变链表Ｌ的尾指针指向新的尾节点
 * */
Status Remove(LinkList *L,Link q); 

/**
 *若线性链表Ｌ为空，则返回ＴＲＵＥ，否则返回ＦＡＬＳＥ
 * */
Status ListEmpty(LinkList L);


Status LocatePos(LinkList *L,int i,Link *p);

//《数据结构》 算法2.20
Status ListInsert(LinkList *L,int i,ElemType e); // 再带头节点的单链线性表L的第i个元素之前插入元素e

Position GetHead(LinkList L);  //返回线性表L中的头节点的位置

//已知p指向线性链表中的一个节点，用e更新p所指节点中的数据元素的值
Status SetCurElm(Link p,ElemType e);
