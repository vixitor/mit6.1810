#include "kernel/types.h"
#include "user/user.h"
#include "kernel/fcntl.h"
#include "kernel/param.h"
int main(int argc, char* argv[]){
    if(argc < 3){
        fprintf(2, "usage: trace mask exec_expr\n");
        exit(0);
    }
}