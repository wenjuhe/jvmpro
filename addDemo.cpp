#include "stdio.h"
#include "stdlib.h"

int addx(int x, int y);

/*
 * todo 指针函数
 * */
int * add(int x, int y);

/*
 * todo 函数指针
 * */

int (*addy) (int x, int y);

int main (){
    int a = 4;
    int b =5;
    int c = addx(a,b);
    printf("c===%d",c);
    //todo 指针函数使用
    int * ptr = add(a,b);
    printf("ptr ===%p\n",ptr);
    printf("ptr ===%d\n",*ptr);
    free(ptr);
    //todo 函数指针的使用
    addy = &addx;
    int ret = addy(a,b);
    printf("ret ====%d\n",ret);
    printf("addy ====%p\n",addy);
    return 0;
}

int addx(int x, int y) {
    return x + y;
}


int * add(int x, int y) {
    int * ptr = (int *)malloc(sizeof(int));
    *ptr = x + y;
    return ptr;
}


