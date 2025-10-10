#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/param.h"
int main(int argc, char* argv[]){
    if(argc < 3){
        fprintf(2, "usage: trace mask exec_expr\n");
        exit(0);
    }
    if(fork() == 0) {
        uint64 mask = atoi(argv[1]);
        trace(mask);
        char* args[MAXARG];
        char* command = argv[2];
        for(int i = 2;i < argc; i++)args[i - 2] = argv[i];
        args[argc - 3] = 0;
        exec(command, args);
    } else {
        wait(0);
        exit(0);
    }
}