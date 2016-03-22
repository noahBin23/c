/**
 *链队列头文件
 * */

// 防止包含多个头文件

#ifndef COMDEF_H
#define COMDEF_H

#include<stdio.h>
#include<stdlib.h>

#endif
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW 2
typedef int Status;
typedef struct QEle{
	int i;
}QElemType;

typedef struct QNode{
	QElemType data;
	struct QNode *next;
}QNode,*QueuePtr;
typedef struct{
	QueuePtr front; //头节点
	QueuePtr rear;  //尾结点
}LinkQueue;

/**
 *构造一个空队列
 * */

Status InitQueue(LinkQueue *Q);
/**
 *销毁队列Q Q不再存在
 * */

Status DestroyQueue(LinkQueue *Q);

/**
 *将Q清空为空队列
 * */
Status ClearQueue(LinkQueue *Q);

/**
 *若队列为空队列，则返回TRUE，否则返回FALSE
 * */

Status QueueEmpty(LinkQueue Q);

int QueueLength(LinkQueue Q);

Status GetHead(LinkQueue Q,QElemType *e);

Status EnQueue(LinkQueue *Q,QElemType e);

Status DeQueue(LinkQueue *Q,QElemType *e);  //出队列 
/**
 *从队头到队尾一次对队列Q中每个元素调用函数visit（）。一旦出现失败，则操作失败;
 * */
//Status QueueTraverse(LinkQueue Q,visit());
