#ifndef COMDEF_A
#define COMDEF_A

#endif
#include"linkqueue.h"
Status InitQueue(LinkQueue *Q){
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if(!Q->front) exit(1);
	Q->front->next = NULL;    
	return OK;
}

Status DestroyQueue(LinkQueue *Q){
	while(Q->front){
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}

Status ClearQueue(LinkQueue *Q){
	QueuePtr p;
	if(QueueEmpty(*Q) == TRUE) return ERROR;
	p = Q->front->next;
	while(p){
		free(p);
		p = p->next;
	}
	return OK;
}

Status QueueEmpty(LinkQueue Q){
	if(Q.front == Q.rear) return TRUE;
	else return FALSE;
}

int QueueLength(LinkQueue Q){
	int n;
	QueuePtr p;
	p = Q.front->next;
	while(p){
		n ++;
		p = p->next;
	}
	return n;
}

Status GetHead(LinkQueue Q,QElemType *e){
	if(QueueEmpty(Q) == TRUE) return ERROR;
	*e = Q.front->data;
	return OK;
}

Status EnQueue(LinkQueue *Q,QElemType e){
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if(!p) exit(2);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return OK;
}

Status DeQueue(LinkQueue *Q,QElemType *e){
	QueuePtr p;
	if(Q->front == Q->rear) return ERROR;
	p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if(Q->rear == p) Q->rear = Q->front;
	free(p);
	return OK;
}
