#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]){
    int i,j=0;
    char *buf[32];
    for(i=1;i<argc;i++){
        buf[j++] = argv[i];
    }
    int n = 0,m = 0;
    char buffer[32];
    char tem[32];

    while((n=read(0,buffer,sizeof(buffer))) > 0){
        for(i = 0;i < n;i++){
            if(buffer[i]=='\n'){//指令结尾
                tem[m] = 0;
                m=0;
                buf[j++] = tem;
                buf[j] = 0;//末尾加0
                j=argc -1;
                if(fork() == 0){//执行操作
                    exec(argv[1],buf);
                }
                wait();
            }else if(buffer[i]==' '){//一个变量完成
                tem[m++] = 0;
                buf[j++] = &tem[m];
            }else tem[m++] = buffer[i];//读取字符串
        }
    }
    exit();
}