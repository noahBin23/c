#include<stdio.h>

void main(){
	int password=0,number=0,price=58,i=0;
	while(password != 1234){
		if(i > 3)
		  return;
		i ++;
		puts("Please input password");
		scanf("%d",&password);
	}
	i = 0;
	while(number != price){
		do{
			puts("Please input a number between 1 and 100");
			scanf("%d",&number);
			printf("Your input number is %d\n",number);
		}while(!(number>=1 && number <= 100));
	}
}
