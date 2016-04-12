/**
 *
 *
 * 多项式，链表实现
 * **/
#include"linkedlist_pol.h"
#include<stdio.h>

typedef int(*compare)(term,term);
int cmp(term a,term b);
void displayLinkedlist(LinkList L);
Status LocateElem(LinkList L,ElemType e,Position *q,compare cmp);
void CreatePolyn(polynomial *p,int m);
Status showPolynomial(polynomial p,char *ch);
void init();


polynomial pa,pb;

int main()
{
	//CreatePolyn(&p,2);
	//displayLinkedlist(p);
	init();
	return 0;	
}

//根据a的指数值<b的指数值 返回-1
int cmp(term a,term b)
{
	if(a.expn < b.expn) return -1;
	else if(a.expn == b.expn) return 0;
	else return 1;
}

void displayLinkedlist(LinkList L)
{
	Link l;
	l = L.head->next;
	printf("-------the linked list content-------\n");
	printf("the head node pointer is:%p\n",L.head);
	printf("head->next:%p\n",L.head->next);
	printf("addr\t\tcoef\t\texpn\t\tnext\n");
	while(l){
		printf("%p\tcoef:%.3f\texpn:%d\t%p\n",l,l->data.coef,l->data.expn,l->next);
		l = l->next;
	}
}

//若有序链表L中存在与e满足判定函数取0的元素，则q指示L中第一个值为e的节点的元素
//，并返回TRUE，否则q指示第一个与e满足判定函数取值>0的元素的前驱的位置
Status LocateElem(LinkList L,ElemType e,Position *q,compare cmp)
{
	Link h,pro;
	if(L.head == L.tail){  //链表空 返回错误  这句不应该返回错误 应该返回头节点的地址，插入进去
		*q = L.head;
		return FALSE;  //TODO 这样的话尾节点咋办。。值怎么改变
	}
	h = L.head->next;
	pro = L.head;
	while(h){
		if(cmp(h->data,e) == 0){
			*q = h;
			return TRUE;
		}
		if(cmp(h->data,e) > 0){
			*q = pro;
			return FALSE;
		}
		pro = h; //保存前一个节点
		h = h->next;
	}
	return FALSE;
}


//输入m项系数和指数，简历表示一元多项式的有序链表P
void CreatePolyn(polynomial *p,int m)
{
	Link h,s;
	Position q;
	int i;
	ElemType e;
	InitList(p); //初始化链表
	h = GetHead(*p);
	e.coef = 0.0;
	e.expn = -1;
	SetCurElm(h,e);  // 设置头节点的数据元素
	for(i=0;i<m;i++){
		scanf("%f %d",&e.coef,&e.expn);
		//当前链表不存在该指数项
		if(!LocateElem(*p,e,&q,cmp)){
			if(makeNode(&s,e)) InsFirst(q,s); //生成节点并插入链表
		}
	}
}


void init()
{
	//初始化链表并输入一个多项式
	int n,i;
	ElemType elm;
	printf("输入多项式A：\n");
	printf("输入多项式A的项数：");
	scanf("%d",&n);
	printf("输入多项式：");
	CreatePolyn(&pa,n);
	printf("输入多项式B：\n");
	printf("输入多项式B的项数：");
	scanf("%d",&n);
	printf("输入多项式：");
	CreatePolyn(&pb,n);

	printf("多项式初始化成功\n");
	showPolynomial(pa,"pa");
}

Status showPolynomial(polynomial p,char *ch)
{
	Link h;
	if(p.head == p.tail) return ERROR;
	h = p.head->next;
	printf("%s=",ch);
	while(1){
		printf("%.3f^%d",h->data.coef,h->data.expn);
		h = h->next;
		if(!h) break;  //到最后一个节点退出
		printf("+");
	}
	printf("\n");
}
