#include<stdio.h>
#include"linkedlist.h"

void showMenu();
void displayLinkedlist(LinkList L);
void initl(LinkList L);
void test(LinkList L);
int main(){
	LinkList L;
	if(InitList(&L)){
		printf("初始化成功\n");
	}
	showMenu();
	initl(L);
	displayLinkedlist(L);
	test(L);
	printf("nums is:%d\n",ListLength(L));
	if(DestoryList(&L)){
		printf("队列销毁成功\n");
	}
	return 0;
}

void test(LinkList L){
	//测试函数
	Link p;
	ElemType e_temp;
	e_temp.a = 100;
	LocatePos(&L,2,&p);
	printf("LocatePos[2]:%p\n",p);
	printf("test ListInsert(2):\n");
	ListInsert(&L,2,e_temp);
	displayLinkedlist(L);
}

void showMenu(){
	system("clear");
	printf("------------menu----------------\n");
}

void initl(LinkList L){
	Link la,lb,lc;
	ElemType e1,e2,e3;
	e1.a = 1;
	e2.a = 2;
	e3.a = 3;
	makeNode(&la,e1);
	makeNode(&lb,e2);
	makeNode(&lc,e3);
	InsFirst(L.head,la);
	InsFirst(L.head,lb);
	InsFirst(L.head,lc);
}


void displayLinkedlist(LinkList L){
	Link l;
	l = L.head->next;
	printf("-------the linked list content-------\n");
	printf("the head node pointer is:%p\n",L.head);
	printf("head->next:%p\n",L.head->next);
	printf("addr\t\tnum\tnext\n");
	while(l){
		printf("%p\t%d\t%p\n",l,l->data.a,l->next);
		l = l->next;
	}
}
