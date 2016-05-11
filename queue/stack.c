/*
	栈的基本操作的实现
	编辑时间：2016年4月15日11:27:45
*/

#include "stack.h"
#include<stdlib.h>

/*
	构造一个空栈S
	return：成功返回TRUE，失败退出 返回OVERFLOW
*/
Status InitStack(SqStack *s)
{
	s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if(!s->base) exit(OVERFLOW);  //存储分配失败
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}

/************************************************************************/
/* 销毁栈S S不不再存在                                                  */
/************************************************************************/
Status DestroyStack(SqStack *s)
{
	if(s->base){
		free(s->base);
		s->base = s->top = NULL;
		return OK;
	}
	return FALSE;
}

/************************************************************************/
/* 把S置为空栈                                                          */
/************************************************************************/
Status ClearStack(SqStack *s)
{
	s->top = s->base;
	return OK;
}

/************************************************************************/
/* 若栈s为空栈，则返回TRUE，否则返回FALSE                               */
/************************************************************************/
Status StackEmpty(SqStack s)
{
	if(s.top == s.base) return TRUE;
	else return FALSE;
}

/************************************************************************/
/* 返回S的元素的个数，即栈的长度                                        */
/************************************************************************/
int StackLength(SqStack s)
{
	int n = 0;
	while(s.top != s.base){
		n ++;
		s.top --;
	}
	return n;
}

/************************************************************************/
/* 若栈不空，则用e返回s的栈顶元素，并返回OK，否则返回ERROR              */
/************************************************************************/
Status GetTop(SqStack s,SElemType *e)
{
	if(s.top == s.base) return ERROR;
	//s.top --;
	//	*e = *s.top;
	*e = * --s.top; 
	return OK;
}

/************************************************************************/
/* 插入元素e为新的栈顶元素                                              */
/************************************************************************/
Status Push(SqStack *s,SElemType e)
{
	if(s->top - s->base >= s->stacksize){
		s->base = (SElemType *)realloc(s->base,
			(s->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if(!s->base) return(OVERFLOW);

		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	
	*s->top ++ = e;
	return OK;
}  //push

/************************************************************************/
/* 若栈不空，则删除s的栈顶元素，用e返回值，并返回OK，否则返回ERROR      */
/************************************************************************/
Status Pop(SqStack *s,SElemType *e)
{
	if(s->base == s->top) return ERROR;
	*e = *(-- s->top);
	return OK;
}


#if 0
/************************************************************************/
/* 从栈底到栈顶依次对栈中的每个元素调用函数visit（）。一旦失败，则      */
/*操作失败                                                              */
/************************************************************************/
Status StackTraverse(SqStack s)
{

}
#endif