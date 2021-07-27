#include <stdlib.h>
#include <string>

/*prototype define for us*/
static void my_init_hook(void);
static void *my_malloc_hook(size_t, const void *);
static void *my_free_hook(void *, const void *);

/*some temp variable*/
static void *(*old_malloc_hook)(size_t, const void *);
static void (*old_free_hook)(void *, const void *);

/*initialize hook*/
void (*__malloc_initialize_hook)(void) = my_init_hook;

/*init function*/
static void
my_init_hook(void)
{
    old_malloc_hook = __malloc_hook;
    old_free_hook = __free_hook;
    __malloc_hook = my_malloc_hook;
    __free_hook = my_free_hook;
}

/*my alloc hook*/
static void *
my_malloc_hook(size_t size, const void *caller)
{
    void *result; /*malloc's return*/
    /*restore all old hooks*/
    __malloc_hook = old_malloc_hook;
    __free_hook = old_free_hook;
    /*call recursively*/
    result = malloc(size);
    /*save underlying hooks*/
    old_malloc_hook = __malloc_hook;
    old_free_hook = __free_hook;
    /*printf might call malloc, so protect it too*/
    printf("malloc(%u) call from %p, return %p\n", (unsigned int)size, caller, result);
    /*restore our own hooks*/
    __malloc_hook = my_malloc_hook;
    __free_hook = my_free_hook;

    return result;
}
/*free hook is same like malloc*/
static void my_free_hook(void *ptr, const void *caller)
{
}
/*main*/
int main(void)
{
    char *p = malloc(10);
    free(p);
    return 0;
}