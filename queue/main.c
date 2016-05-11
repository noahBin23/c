/*
	栈的顺序存储表示

	第一次编辑：2016年4月15日11:19:56
	实例：括号匹配的检验

**/

#include<stdio.h>
#include "stack.h"
#define CHAR_SIZE 32



void displayStackInfo(SqStack s);
Status doAction(SqStack *s,char *ch);

int main()
{
	SqStack s;
	char ch[CHAR_SIZE];
	InitStack(&s);
	scanf("%s",ch);
	if(doAction(&s,ch) == TRUE){
		printf("匹配成功\n");
	}else{
		printf("匹配失败\n");
	}

	return 0;
}

/************************************************************************/
/* 括号的匹配 栈实现                                                                     */
/************************************************************************/
Status doAction(SqStack *s,char *ch)
{
	SElemType e;
	int i;
	for(i=0;i<CHAR_SIZE && ch[i] != '\0';i++){
		switch(ch[i]){
		case '[':
		case '(':
		case '{':   //左括号
			Push(s,ch[i]);
			break;
		case ']':
			Pop(s,&e);
			if(e != '['){
				return FALSE;
			}
			break;
		case ')':
			Pop(s,&e);
			if(e != '('){
				return FALSE;
			}
			break;
		case '}':
			Pop(s,&e);
			if(e != '{'){
				return FALSE;
			}
			break;
		default:
			break;
		}
	}
	if(StackEmpty(*s))
		return TRUE;
	else
		return FALSE;
}

//显示栈信息
void displayStackInfo(SqStack s)
{
	printf("--------the stack info------------\n");
	printf("the stack base:%p\n",s.base);
	printf("the stack top: %p\n",s.top);
	printf("ths stack elem num is:%d\n",StackLength(s));
	while(s.top != s.base){
		s.top --;
		printf("%p->%c\n",s.top,*s.top);
	}
}
