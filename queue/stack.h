/*
	栈的基本操作头文件
	编辑时间：2016年4月15日11:28:33

*/
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define OK 1

#define OVERFLOW -1

typedef int Status;

// typedef struct  
// {
// 	char ch;
// } SElemType;

typedef char SElemType;

typedef struct 
{
	SElemType *base; //在栈构造之前和销毁之后，base的值为null
	SElemType *top;  //栈顶指针
	int stacksize; //当前已经分配的存储空间，以元素为单位
}SqStack;

//函数声明
Status InitStack(SqStack *s);
Status DestroyStack(SqStack *s);
Status ClearStack(SqStack *s);
Status StackEmpty(SqStack s);
int StackLength(SqStack s);
Status GetTop(SqStack s,SElemType *e);
Status Push(SqStack *s,SElemType e);
Status Pop(SqStack *s,SElemType *e);