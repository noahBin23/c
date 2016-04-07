#include<stdio.h>
#include"linerlist.h"
#include"platformdep.h"
void showListInfo();
void displayList(SqList L);
int showMenu();
void deleteNode();
void insertNode();
SqList sqlist;
int main(){
	ElemType e;
	int choice;
	e.ch = 'a';
	InitList_sq(&sqlist);
	ListInsert_sq(&sqlist,1,e);
	showListInfo();
	displayList(sqlist);
	//选择菜单
	while((choice = showMenu()) != 0){
		switch(choice){
			case 1:
				showListInfo();
				break;
			case 2:
				insertNode();
				break;
			case 3:
				displayList(sqlist);
				break;
			case 4:
				deleteNode();
				break;
			default:
				printf("选择有误，请重新输入\n");
				break;
		}
	}
	return 0;
}

//从表中删除一个元素
void deleteNode(){
	int i;
	ElemType e;
	printf("请输入删除位置：");
	scanf("%d",&i);
	if(ListDelete_sq(&sqlist,i,&e)){
		printf("删除成功，删除的元素是：[%d]:%c\n",i,e.ch);
	}else{
		printf("删除失败，请检查删除位置是否正确\n");
	}
}

void insertNode(){
	int i;
	ElemType e;
	printf("输入插入位置：");
	scanf("%d",&i);
	getchar();
	printf("输入插入元素（一个字符）：");
	scanf("%c",&e.ch);
	if(ListInsert_sq(&sqlist,i,e)){
		printf("插入成功\n");
	}else{
		printf("插入失败，插入位置不正确\n");
	}
}

int showMenu(){
	//显示菜单
	int choice;
	printf("------线性表的顺序表示和实现---------\n");
	printf("----------菜单---------------\n");
	printf("----1.显示表信息-------------\n");
	printf("----2.在线性表第i个位置之前插入一个新的元素\n");
	printf("----3.显示表信息------------\n");
	printf("----4.从表中第i个位置删除一个元素----\n");
	printf("----0.退出-------------------\n");
	printf("选择：");
	scanf("%d",&choice);
	//TODO 判断选择的正确性
	return choice;
}

void showListInfo(){
	printf("--------------sqlist info-----------------\n");
	printf("sqlist->length:%d\n",sqlist.length);
	printf("sqlist->listsize:%d\n",sqlist.listsize);
}

void displayList(SqList L){
	int i;
	if(L.length == 0){
		printf("The list is empty\n");
	}else{
		printf("-----the list content is:--------------\n");
		for(i=0;i<L.length;i++){
			printf("\t[%d]\t%c\n",i,(L.elem + i)->ch);
		}		
	}
}
