extern "C"
{
#include "mem/MemTrarker.h"
}

void test_mem1(){
    char*chs = (char*)malloc(100);

    free(chs);
}
