//线性表的动态分配顺序存储结构
#define LIST_INIT_SIZE 100  //线性表存储空间初始分配量
#define LISTCRENTMENT 10  //线性表存储空间分配增量

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW 1
typedef int Status;
typedef struct{
	char ch;
}ElemType;

typedef struct{
	ElemType *elem;
	int length;  //当前长度
	int listsize;  //当前分配的存储容量
}SqList;

Status InitList_sq(SqList *L);
int ListLength(SqList L);
Status ListInsert_sq(SqList *L,int i,ElemType e);
Status isListEmpty(SqList L);
Status ListDelete_sq(SqList *L,int i,ElemType *e);
