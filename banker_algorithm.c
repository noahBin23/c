/************************************************************************/
/* 银行家算法
2016年3月25日16:39:30    
修改 2016年3月27日10:00:15                                                                 */
/************************************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void printarray(int *p,int n);
void print2Array(int *p,int n,int m);
void displayProcess();
//安全性算法
Status safe();
Status cmpNeedWork(int *work,int i);

#define M 3 //M 类资源

#define P_ARRAY(p,i,j) (p+(M*i)+j)
#define LF printf("\n")  //换行
#define OK 1
#define FALSE 0
#define ERROR 0
#define TRUE 1



typedef int Status;

void init();
//定义各种向量
int Available[M];
int *Max;  //最大需求矩阵
int *Allocation; //分配矩阵
int *Need; //需求矩阵
int n; //进程数目

int Request[M]; //请求向量

int main(){
	char choice;
	int num;
	int i;
	init();
	//提出请求
	
	printf("请求资源，输入进程号：");
	scanf("%d",&num);
	printf("输入请求向量：");
	for(i=0;i<M;i++){
		scanf("%d",*(Request + i));
	}

	//执行银行家算法
	if(safe() == FALSE){
		printf("请求拒绝，你的请求时不安全的\n");
		//恢复请求前的状态
	}else{
		printf("请求成功，同意分配资源\n");
	}

	return 0;
}

void init(){
	int i = 0,j=0;
	printf("****************模拟银行家算法******************\n");
	printf("输入可利用资源数目(共%d类):",M);
	for(i=0;i < M;i ++){
		scanf("%d",Available+i);
	}
	
	printf("输入进程数量：");
	scanf("%d",&n);
	
	Max = (int *)malloc(n * M * sizeof(int));  //动态分配Max数组内存
	Allocation = (int *)malloc(n * M * sizeof(int));  //
	Need = (int *)malloc(n * M * sizeof(int));  //需求矩阵
	
	if(!Max) exit(1);  
	if(!Allocation) exit(1);
	if(!Need) exit(1);
	
	printf("Now input Max matrix\n");
	for(i=0;i<n;i++){  //初始化最大需求矩阵
		printf("Process[%d]:",i);
		for(j=0;j<M;j++){
			scanf("%d",P_ARRAY(Max,i,j));  
		}
		//检查系统是否有足够的资源分配给该进程
		for(j=0;j<M;j++){
			if(*P_ARRAY(Max,i,j) > *(Available + j)){
				printf("系统没有足够的资源分配给该进程，重新输入\n");
				i--;
				break;
			}
		}
	}
	
	//初始化分配矩阵，都为零
	for(i=0;i<n;i++)
		for(j=0;j<M;j++)
			*P_ARRAY(Allocation,i,j) = 0;
		//初始化需求矩阵 最初与最大需求矩阵相同
		for(i=0;i<n;i++)
			for(j=0;j<M;j++)
				*P_ARRAY(Need,i,j) = *P_ARRAY(Max,i,j);
			
	printf("进程初始化完成，初始化信息:\n");
	displayProcess();
}


//银行家算法
void Banker(int choice){
	int i;
	//(1)
	for(i=0;i<M;i++){
		if(*(Request + i) > *P_ARRAY(Need,choice,i)){
			printf("超出需求矩阵，请求错误\n");
			return;
		}
	}
	//(2)
	for(i=0;i<M;i++){
		if(*(Request + i) > *P_ARRAY(Available,choice,i)){
			printf("没有足够的资源，请求错误\n");
			return;
		}
	}
	//(3)
	for(i=0;i<M;i++){
		Available[i] = Available[i] - Request[i];
		*P_ARRAY(Allocation,choice,i) = *P_ARRAY(Allocation,choice,i) + *(Request+i);
		*P_ARRAY(Need,choice,i) = *P_ARRAY(Need,choice,i) - *(Request+i);
	}
	//(4) 执行安全性算法
}

//安全性算法
Status safe(){
	//1)	设置两个工作向量Work=Available，Finish=false；
	int work[M];
	int i,j;
	Status Finish[M]={FALSE};
	for(i=0;i<M;i++)
		work[i] = Available[i];
// 	2)	从进程集合中找到一个满足下述条件的进程；
// 		Finish=false;
// 	Need<=work;
	for(i=0;i<M;i++){
		if(Finish[i] == FALSE && cmpNeedWork(work,i)){
			//(3)
			for(j=0;j<M;j++){
				work[j] = work[j] + *P_ARRAY(Allocation,i,j);
				Finish[i] = TRUE;
			}
			i = 0;
		}
	}

	for(i=0;i<M;i++){
		if(Finish[i] == FALSE)
			return FALSE;
	}
	return TRUE;

}

Status cmpNeedWork(int *work,int i){
	int j;
	for(j=0;j<M;j++){
		if(*P_ARRAY(Need,i,j) > *(work + j))
			return FALSE
	}
	return TRUE;
}

/**
打印一维数组，测试用
*/
void printarray(int *p,int n){
	int i = 0;
	for(i=0;i<n;i++){
		printf("%d\t",*(p+i));
	}
	printf("\n");
}

/**
打印二维数组
*/
void print2Array(int *p,int n,int m){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%d\t",*(p+(i*M)+j));
		}
		printf("\n");
	}
	
}

void displayProcess(){
	int i,j;
	int m = M;
	char str[64] = {'\0'};
	char tmp[20] = {'\0'};
	printf("current available is:");
	for(i=0;i<m;i++){
		printf("%d  ",*(Available+i));
	}
	LF;
	printf("\t\tMax\t\tAllocation\t\t\tNeed\n");
	for(i=0;i<n;i++){
		sprintf(tmp,"[%d]\t",i);
		strcat(str,tmp);

		for(j=0;j<m;j++){
			sprintf(tmp,"%4d",*P_ARRAY(Max,i,j));
			strcat(str,tmp);
		}
		sprintf(tmp,"\t\t\0");
		strcat(str,tmp);
		
		for(j=0;j<m;j++){
			sprintf(tmp,"%4d",*P_ARRAY(Allocation,i,j));
			strcat(str,tmp);
		}
		sprintf(tmp,"\t\t\0");
		strcat(str,tmp);

		for(j=0;j<m;j++){
			sprintf(tmp,"%4d",*P_ARRAY(Need,i,j));
			strcat(str,tmp);
		}
		sprintf(tmp,"\0");
		strcat(str,tmp);

		printf("%s\n",str);
		memset(str, 0x00, sizeof (char) * 64); //全部设置为0x00即\0字符
	}
}
