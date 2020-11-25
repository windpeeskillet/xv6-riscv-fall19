#include "kernel/types.h"
#include "user.h"

void prints(int num[],int count){
    int prime = num[0];
    printf("prime %d \n",prime);
    if(count == 1){
        return;
    }
    int p[2],i;
    int temp;
    pipe(p);
    if(fork() == 0){
        for(i = 0; i < count;i ++){
            temp = num[i];
            write(p[1],&temp,4);
        }
        exit();
    }
    close(p[1]);
    if(fork()==0){
        int ps = 0;
        int buffer;
        while(read(p[0],&buffer,4) != 0){
            if(buffer % prime != 0){
                num[ps] = buffer;
                ps++;
            }
        }
        prints(num,ps);
        exit();
    }
wait();
wait();
}

int main(int arg , char* argv[]){
    int num[34],i = 0;
    for(;i<34;i++){
        num[i] = i + 2;
    }
    prints(num,34);
    exit();
}