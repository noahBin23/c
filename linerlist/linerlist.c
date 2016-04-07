#include<stdlib.h>

#include"linerlist.h"
// 算法2.3 《数据结构》
Status InitList_sq(SqList *L){
	//构造一个空的线性表L
	L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L->elem) exit(OVERFLOW);  // 存储分配失败
	L->length = 0;
	L->listsize = LIST_INIT_SIZE;
	return OK;
}

int ListLength(SqList L){
	return L.length;
}
//算法2.4 《数据结构》
Status ListInsert_sq(SqList *L,int i,ElemType e){
	//在顺序线性表L中第i个位置之前插入新的元素e
	//i 的合法值为1<=i<=listlength_sq(L) +1
	ElemType *newbase;
	ElemType *q,*p;
	if(i<1 || i>L->length + 1) return ERROR;  // i 值不合法
	if(L->length >= L->listsize){
		//存储空间满 增加分配
		newbase = (ElemType *)realloc(L->elem,(L->listsize+LISTCRENTMENT)*sizeof(ElemType));
		if(!newbase) exit(OVERFLOW);
		L->elem = newbase;
		L->listsize += LISTCRENTMENT;  //增加存储空间容量
	}
	//插入
	q = L->elem + i - 1;
	for(p=L->elem+L->length-1;p>=q;p--)
	  *(p+1) = *p;
	*q = e; //插入e
	L->length ++;
	return OK;
}


Status isListEmpty(SqList L){
	if(L.length == 0) return OK;
	else return FALSE;
}

//算法2.5 《数据结构》
//再顺序你线性表L中删除第i个元素，并用e返回其值
//i的合法性
Status ListDelete_sq(SqList *L,int i,ElemType *e){
	ElemType *p,*q;
	if((i < 1) || (i > L->length)) return ERROR;
	p = L->elem + i - 1;
	*e = *p;
	q = L->elem + L->length - 1;
	for(++p;p<=q;p++) *(p-1)=*p;  //元素后移
	L->length --;
	return OK;
}

//算法2.2 《数据结构》
//已知线性表La和Lb中的数据元素按值非递减排列
//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列
//TODO 
