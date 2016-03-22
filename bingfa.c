#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

#define TN 3  // numbers of threads

void routine(void *arg);

int main(){
	 	 pthread_t thread[TN];
         int retval,i;
         char msg[TN][10];
         puts("this is main thread!.");
         for(i = 0;i<TN;i++)
         {
         sprintf(msg[i],"thread %d",i);
         retval = Pthread_create(&thread[i],NULL,(void *)routine,msg[i]);
         if(retval!= 0)
                  {
                 perror("thread create failed.");
                   exit(1);
                }
         }
         for(i = 0;i<TN;i++)
        Pthread_join(thread[i],NULL);
         puts("main thread exiting.");
         return 0;
}

void routine(void *arg){
    int j;
    for(j=0;j<5;j++){
       sleep(1 + (int)(5.0*rand()/(RAND_MAX + 1.0)));
        printf("%s:",(char *)arg);
        printf("%d\n",j);
    }

    return;
}
