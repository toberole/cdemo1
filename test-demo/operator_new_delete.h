#ifndef __xxx_operator_new_delete__
#define __xxx_operator_new_delete__

#include <stdlib.h>
#include <new>

void *operator new(size_t size)throw(std::bad_alloc);

void operator delete(void *p)throw();
/**
 * 重载 加额外参数
 */ 
// void *operator new(size_t size,const char* fileName,const char* line)throw(std::bad_alloc);

// void operator delete(void *p,const char* fileName,const char* line)throw();

#endif