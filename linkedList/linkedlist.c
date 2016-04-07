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

Status LocatePos(LinkList *L,int i,Link *p){
	//返回P指示的线性链表中第i个节点的位置并返回OK，i值不合法返回ERROR
	int j = 1;
	//判断i值是否合法
	if(i < 1 || i > ListLength(*L)) return ERROR;
	*p = L->head->next;
	while(j<i){
		*p = (*p)->next;
		j ++;
	}
}

int ListLength(LinkList L){
	int i;
	Link node;
	i = 0;
	node = L.head->next;
	while(node){
		node = node->next;
		i ++;
	}
	return i;
}

/**
 *在带头节点的单链线性表L的第i个元素之前插入元素e
 * **/
Status ListInsert(LinkList *L,int i,ElemType e){
	Link h;
	Link s;
	if(!LocatePos(L,i-1,&h)) return ERROR; // i不合法
	if(!makeNode(&s,e)) return ERROR; //分配空间失败
	InsFirst(h,s);
	return OK;
}
