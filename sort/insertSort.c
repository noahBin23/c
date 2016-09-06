#include<stdio.h>
#include<stdlib.h>
/**
普通插入排序的实现
*/
void sort(int *list,int n){
	int i,j;
	int tmp;
	for(i=1;i<n;i++){
		tmp = list[i];
		for(j=i;j>0 && tmp < list[j-1];j--){
			list[j] = list[j-1];
		}
		list[j] = tmp;
	}
}

int main(){
	int i = 0;	
	int a[] = {52,56,89,66,6666,9959,3356,1323,48653,222};
	sort(a,10);
	for(i=0;i<10;i++){
		printf("%d\n",a[i]);
}
	return 0;
}
