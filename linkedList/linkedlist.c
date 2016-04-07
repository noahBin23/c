#include"linkedlist.h"

Status makeNode(Link *p,ElemType e){ //
	*p = (Link)malloc(sizeof(struct LNode));
	if (!*p) return ERROR;
	(*p)->data = e;
	return OK;
}

void FreeNode(Link *p){
	free(p);
}

Status InitList(LinkList *L){
	Link head;
	head = (Link)malloc(sizeof(struct LNode));
	if(!head) return ERROR;
	L->head = L->tail = head;
	L->len = 0;
	return OK;
}

Status DestoryList(LinkList *L){
	Link l;
	l = L->head->next;
	while(l){
		//l 不为空
		L->tail = l->next;
		free(l);
		l = L->tail;
	}
	free(L->head);  //释放头节点
	//free(L); //释放链表
	return OK;
}

Status ClearList(LinkList *L){
	
}


Status Remove(LinkList *L,Link q){
	Link temp;
	if(L->head == L->tail) return ERROR;  //链表为空　返回错误
	q = L->tail;
	temp = L->head;
	//找到新的尾节点还得从头节点开始遍历？
	while(temp->next){
		L->tail = temp;
	}	
	return OK;
}

Status InsFirst(Link h,Link q){
	//*已知h指向线性表的头节点，将ｐ所指的节点插入在第一个节点之前
	q->next = h->next;
	h->next = q;
	return OK;
}

Status DelFirst(Link h,Link *q){
	//已知ｈ指向线性表的头节点，删除表中的第一个节点并以ｑ返回
	//判断是否为空
	if(h->next->next == NULL) return ERROR;
	(*q) = h->next;
	h->next = h->next->next;
	return OK;
}

Status ListEmpty(LinkList L){
	if(L.head == L.tail) return TRUE;
	else return FALSE;
}
