#pragma once
#include <stdio.h>
#include <stdlib.h>

void *myMalloc(const char *file, int line, int size)
{
    printf("file: %s,line: %d", file, line);
    return malloc(size);
}

void myFree(const char *file, int line,void*p)
{
    
    printf("file: %s,line: %d", file, line);
    return free(p);
}

#define malloc(size) myMalloc(__FILE__,__LINE__,size)
#define free(p) myFree(__FILE__,__LINE__,p)