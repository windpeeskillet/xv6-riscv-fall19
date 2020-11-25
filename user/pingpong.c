#include "kernel/types.h"
#include "user.h"

int main(int arg , char* argv[]){
    int p_p[2],p_c[2];
    int ret_p;
    int ret_c;
    int pid;

    char* buffer[5];

    ret_p = pipe(p_p); /*正常创建后，p[1]为管道写入端，p[0]为管道读出端*/ 
    ret_c = pipe(p_c);

    if((pid = fork())<0){
        printf("Fork error");
        exit();
    }else if(pid == 0){
	pid = getpid();
        write(p_c[1],"pong",5);
	read(p_p[0],buffer,5);
        printf("%d: received %s\n",pid,buffer);
	close(ret_c);
	close(ret_p);
	exit();
    }else{
	pid = getpid();
    	write(p_p[1],"ping",5);
	read(p_c[0],buffer,5);
    	printf("%d: received %s\n",pid,buffer);
	close(ret_p);
	close(ret_c);
	exit();
    }


}