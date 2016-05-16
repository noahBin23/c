/*
 *2016年05月11日14:09:33
 基于c语言的学生管理系统,链表实现
 要求：
	学生信息包括：姓名，学号，各科目分数，总分，平均分等
	将信息保存成文件，反复使用。
	对信息的操作，添加，修改，删除等
	排序，应用多种排序算法对信息进行排序，并比较各种排序算法的性能。
	信息查询：可以按照学号，姓名查询学生信息。也可以查询某个分数段中的学生信息
	文件结构结构示例：
		000000000000:铁拐李:95:96:97
		000000000000:铁拐李:95:96:97
		000000000000:铁拐李:95:96:97
 * */
#include<stdio.h>
#include<stdlib.h>

#define ELE_LENGTH 12
typedef struct Stu{
	char id[ELE_LENGTH];
	char name[ELE_LENGTH];
	int grade_eng;
	int grade_total;
	int grade_avg;  //平均分
	struct Stu *next;
}STU;


void show_menu();
//头节点指针
STU *pStu_head;
int total_num=0; //总学生数

void init(){
	FILE *fdata;
	char ch_buff[BUFSIZ];
	pStu_head = (STU *)malloc(sizeof(struct Stu));
	if(!pStu_head) exit(2);
	if((fdata = fopen("userdata.txt","r")) == NULL){
		printf("数据文件不存在\n");
		exit(2);
	}
	while(!feof(fdata)){
		total_num ++;	
		fgets(ch_buff,BUFSIZ,fdata);
	}

	fclose(fdata);
}


int main(){
	init();
	show_menu();
	return 0;
}

void show_menu(){
	printf("***********欢迎使用学生信息管理系统***********\n");
	printf("*当前共有%d条记录                           **\n",total_num);
	printf("*1.添加记录                                 **\n");
	printf("*2.查找记录                                 **\n");
	printf("*3.删除记录                                 **\n");
	printf("*4.另存为文件....                           **\n");
	printf("*5.修改记录                                 **\n");
	printf("**********************************************\n");
}
