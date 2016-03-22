
/**
 *模拟进程管理，先来先服务算法实现。。。
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
#include<time.h>
#define TRUE 1
#define FALSE 0 
#define OK 1
#define TIME_PIACE_TIME 5 //定义时间片大小
#define RUN 2 //运行状态
#define PAUSE 3 //挂起状态
typedef struct node{
    char name[10];
    int PID;
    int prio; //优先数
    int round;
    int needtime;
    int cputime;
    int count;
    int state;
	int startTime;
	int complate_time;
    struct node *next;
}PCB;
typedef struct QNode{
    PCB data;
    struct QNode *next;
}*PCBNode;
typedef struct{
    PCBNode front; //队头指针
    PCBNode rear; //队尾指针
}PCBQueue;

typedef int Status;


//函数声明
int Myrandom();
void printNode(PCBQueue *queue);
void initProcessQueue(PCBQueue *pcb,int n);
Status QueueEmpty(PCBQueue *q);
Status initQueue(PCBQueue *q);
Status DeQueue(PCBQueue *q,PCB *e);
void printPCB(PCB data);
Status EnQueue(PCBQueue *queue,PCB pcb);
void run(PCB *pcb);
void printResult(PCBQueue *pcb);   
int PC = 0; //定义总的时间流

/************************************************************************/
/* 先来先服务算法
    模拟一个队列，每个进程分配一个时间片，时间片轮转完后如果没有运行完则加入队列等待运行

*/
/************************************************************************/
int main(){
    int n = 0;
    PCBQueue pcbQueue;
	PCBQueue pcbFinishQueue;  // 初始化一个已经完成的进程的队列，保存已经完成的进程，以便程序最后打印信息
    PCB currentPCB;
    int runningTime = 0; //保存当前进程已经运行的时间

    srand((unsigned)time(NULL));  //给随机数种子

	initQueue(&pcbFinishQueue);  //  初始化完成队列

    printf("多线程控制\n");
    printf("先来先服务算法：请输入模拟线程个数：\n");
    scanf("%d",&n);
    initQueue(&pcbQueue);
    initProcessQueue(&pcbQueue,n);
    printf("初始化的PCB进程块完成\n");
    printNode(&pcbQueue);
    //判断队列是否为空
    while(QueueEmpty(&pcbQueue) == FALSE){  //队列空，退出
        runningTime = 0; //初始化运行时间
        if(OK != DeQueue(&pcbQueue,&currentPCB)){  //取出一个元素
            printf("取队列错误"); 
            exit(1);
        }
        printf("取出：");
        printPCB(currentPCB); // 已经取出的元素
        currentPCB.count ++;
        while(1){
           //判断是否继续运行
            if(runningTime >= TIME_PIACE_TIME){
                //时间片到达 进程退出运行
                currentPCB.state = PAUSE;
                EnQueue(&pcbQueue,currentPCB); //加入到等待队列队尾
                printf("当前时间片运行完成,PCB：");
                printPCB(currentPCB); //打印当前PCB的状态
                break;
            }else if(currentPCB.cputime >= currentPCB.needtime){
                //程序运行完成
                printf("\033[;31m%s运行完成，该进程调用次数：%d，退出\033[0m\n",currentPCB.name,currentPCB.count);
				currentPCB.complate_time = PC;
				EnQueue(&pcbFinishQueue,currentPCB);  //进入已完成队列
                break;
            }else{
				//继续运行     
				currentPCB.state = RUN;
				run(&currentPCB);
				runningTime ++;
			}
			PC ++;  //程序总时间+1  
        } // end of while
        //运行PCB块
    }
    // printNode(&pcbQueue);
	printResult(&pcbFinishQueue);
	printf("程序运行完成，总时间：%d\n",PC);
    return 0;
}

/**
 * 模拟程序运行一个单位时间片
 * @param pcb [description]
 */
void run(PCB *pcb){
    pcb->needtime --;
    pcb->cputime ++;
    // Sleep(1000);
}

/**
 * 初始化一个进程链队列
 * @param pcb [description]
 * @param n   [初始化进程的个数]
 */
void initProcessQueue(PCBQueue *pcb,int n){
    int i = 0;
    PCBNode p,front;
    p = (PCBNode)malloc(sizeof(struct QNode));
    if(!p) exit(1);
    pcb->front->next = p;
    while(1){
        sprintf(p->data.name,"线程%d",i);  //初始化线程名称
        p->data.PID = 1000 + i; //分配PID
        p->data.needtime = Myrandom();  //用一个随机数初始化进程需要运行的时间
        p->data.prio = 0;
        p->data.cputime = 0;
        p->data.count = 0;
        p->data.state = 0;
        p->data.round = 0;
		p->data.startTime = i;
		p->data.complate_time = 0;
        front = p; //保存上一个节点
        if(i >= n - 1) break;
        i++;
        p = (PCBNode)malloc(sizeof(struct QNode)); 
        if(!p) exit(1);
        front->next = p; 
    }
    front->next = NULL;
    pcb->rear = front; //尾节点
    //随机产生PID
}

/**
 * 产生一个随机数
 * @return [一个1-100的随机数]
 */
int Myrandom(){
    int i;
    i = rand()%100 + 1;
    return i;
}

/**
 * 打印节点信息，测试用
 * @param queue [description]
 */
void printNode(PCBQueue *queue){
    PCBNode p;
    p = queue->front->next;
    while(1){
        printf("%s\t%d\t%d\t%d\n",p->data.name,p->data.PID,p->data.needtime,p->data.cputime);
        p = p->next;
        if(!p) break;
    }
}

/**
 * 初始化一个队列
 * 创建一个头节点为空的队列
 * @param  q [description]
 * @return   [创建成功返回OK 创建失败则程序中断]
 */
Status initQueue(PCBQueue *q){
    q->front = q->rear = (PCBNode)malloc(sizeof(struct QNode));
    if(!q) exit(1);
    q->front->next = NULL;
    return OK;
}
/**
 * 判断队列是否为空
 * @param  q [队列]
 * @return   [队列状态，为空返回TRUE，否则返回fALSE]
 */
Status QueueEmpty(PCBQueue *q){
    if(q->front == q->rear) return TRUE;
    else return FALSE;
}

/**
 * 出队列
 * 若队列不为空，则删除q的队头元素，用e返回值，并返回OK
 * @param  q [description]
 * @param  e [description]
 * @return   [OK]
 */
Status DeQueue(PCBQueue *q,PCB *e){
    PCBNode p;
    if(QueueEmpty(q) == TRUE) 
        return FALSE;
    p = q->front->next;
    *e = p->data;
    q->front->next = p->next;
    if(q->rear == p) q->rear = q->front;
    free(p);
    return OK;
}

/**
 * 在队尾插入元素
 * @param  queue [description]
 * @param  pcb   [description]
 * @return       [description]
 */
Status EnQueue(PCBQueue *queue,PCB pcb){
    PCBNode pnode;
    pnode = (PCBNode)malloc(sizeof(struct QNode));
    if(!pnode) exit(1);
    pnode->data = pcb;
    pnode->next = NULL;
    queue->rear->next = pnode;
    queue->rear = pnode;
    return OK;
}
/**
 * 打印PCB信息
 * @param data [description]
 */
void printPCB(PCB data){
    // printf("进程名称\tPID\tneedtime\tcputime\n");
    printf("%s\t%d\t%d\t%d\n",data.name,data.PID,data.needtime,data.cputime);
}

void test(){
	
}
/**
 *
 * 打印最后程序的运行结果。
 * */
void printResult(PCBQueue *pcb){
	PCBNode p;
	PCB data;
	int turnOver;
	float WTT;
	if(QueueEmpty(pcb) == OK) return;
	p = pcb->front->next;
	printf("\t\t运行结果\n");
	printf("ProcessName\tPID\tneedTime\tcputime\tstartTime\t周转时间\t带权周转时间\n");
	while(1){
		data = p->data;
		turnOver = data.complate_time - data.startTime;
		WTT = (float)turnOver / (float)data.needtime;
		//打印信息
		printf("%s\t\t%d\t%d\t\t%d\t%d\t\t%d\t\t%.2f\n",data.name,data.PID,data.needtime,data.cputime,data.startTime,turnOver,WTT);
		p = p->next;
		if(!p) break;
	}
}
