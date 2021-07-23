#include "operator_new_delete.h"
#include <stdio.h>

#define extra_size_4_len 4

/**
 * 额外多分配四个字节 用于隐式的记录分配的长度
 */
void *operator new(size_t size) throw(std::bad_alloc)
{
    printf("my operator new: %d \n", size);
    void *p = malloc(size + extra_size_4_len);
    int *temp_p = (int*)p;
    *temp_p = size;
    return (void *)(temp_p+1);
}

void operator delete(void *p) throw()
{
    int *temp_p = (int*)p;
    temp_p = temp_p-1;
    printf("my operator delete size: %d \n",*temp_p);

    free((void*)temp_p);
}

// void *operator new(size_t size,const char* fileName,const char* line) throw(std::bad_alloc)
// {
//     printf("my operator new fileName: %s,line: %s,size: %d \n", fileName,line,size);
//     void *p = malloc(size + extra_size_4_len);
//     int *temp_p = (int*)p;
//     *temp_p = size;
//     return (void *)(temp_p+1);
// }

// void operator delete(void *p,const char* fileName,const char* line) throw()
// {
//     int *temp_p = (int*)p;
//     temp_p = temp_p-1;
//     printf("my delete fileName: %s,line: %s,size: %d \n", fileName,line,*temp_p);
   
//     free((void*)temp_p);
// }

