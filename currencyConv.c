/*
 *栈的应用举例，数制转换
 * 2016年03月21日
 * xubin
 * */
#include<stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OK 1
#define ERROR 0
#define FALSE 0
#define TRUE 1
#include<stdlib.h>
#include<unistd.h>   //包含getopt函数 用来处理参数
typedef int Status;
typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

Status pop(SqStack *S,int *e);
Status InitStack(SqStack *S);
Status push(SqStack *S,int e);
Status stackEmpty(SqStack s);

int main(int argc,char *argv[]){
	//TODO 以命令行方式传递参数
	SqStack stack;
	int n;
	int jinzhi = 8;
	int ch;
	opterr = 0;
	InitStack(&stack);
	if(argc != 0){
		//处理命令行参数
		//-d 要转换成的进制数，为一个数字
		while((ch=getopt(argc,argv,"d:c:h")) != -1){
			switch(ch){
				case 'd':
					n = atoi(optarg);
					break;
				case 'c':
					jinzhi = atoi(optarg);
					break;
				case 'h':
					printf("-d 指定要转换的十进制数字\n-c 制定要转换的进制数\n");
					break;
				default:
					printf("arguments error!!\n-h查看帮助\n");
					exit(1);
			}
		}
	}else{
		printf("Please input a number(to octal number):");
		scanf("%d",&n);
	}
	while(n){
		push(&stack,n%jinzhi);
		n = n/jinzhi;
	}

	while(!stackEmpty(stack)){
		pop(&stack,&n);
		printf("%d",n);
	}
	printf("\n");


	return 0;
}

Status InitStack(SqStack *S){
	S->base = (int *)malloc(sizeof(int)*STACK_INIT_SIZE);
	if(!S->base) return ERROR;
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status push(SqStack *S,int e){
	if(S->top - S->base >= S->stacksize){
		//栈满，追加存储空间
		S->base = (int *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(int));
		if(!S->base) return ERROR;
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
    //	*S->top ++ = e;  // 把数据给top后top加一
	*(S->top) = e;
	S->top ++;
	return OK;
}

Status pop(SqStack *S,int *e){
	//若不空，则删除栈顶元素并返回值
	if(S->top == S->base) return ERROR;
	S->top --; //  //   先减再取值
	*e = *(S->top); ///传递值不要传递指针
	// e=* --S->top  同样的效果
	return OK;
}

Status stackEmpty(SqStack s){
	if(s.top == s.base) return TRUE;
	else return FALSE;
}
