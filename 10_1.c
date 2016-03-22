#include<stdio.h>
#include<ctype.h>
#define LENGTH 11

int main(){
    char c[LENGTH] = {"CHinA No.1"};
    int i;
    puts(c);
    for(i=0;i<LENGTH;i++){
        if(isalpha(c[i])){
            //判断该元素中的字符串是否是字母
            if(islower(c[i]))
                c[i] = toupper(c[i]);  //将小写字母转变为大写字母
        }
    }
    puts(c);
    return 0;
}