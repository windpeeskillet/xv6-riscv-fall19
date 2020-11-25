#include "kernel/types.h"
#include "user.h"

int main(int arg , char* argv[]){
    if(arg != 2){
        printf("Illegal Param Number Input");
    }else{
        int sleep_time = atoi(argv[1]);
        if(sleep_time < 0){
            printf("Illegal Time Set Input");
        }else{
	    printf("Sleep %d",sleep_time);
            sleep(sleep_time);
        }
    }
    exit();
}