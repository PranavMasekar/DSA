#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total, using_size;
    int *ptr;
};

void createarray(struct myArray *a, int tsize, int usize)
{
    (*a).total = tsize;
    (*a).using_size = usize;
    (*a).ptr = (int *)malloc(tsize * sizeof(int)); //requesting a array in heap memory and pointing to its first element by pointer.
    // a->total = tsize;
    // a->using_size = usize;
    // a->ptr = (int *)malloc(tsize * sizeof(int));
}

void show(struct myArray *a)
{
    for (int i = 0; i < a->using_size; i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

void set(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->using_size; i++)
    {
        scanf("%d", &n);
        (a->ptr)[i] = n;
    }
}
int main()
{
    struct myArray marks;
    createarray(&marks, 10, 2);
    set(&marks);
    show(&marks);
    return 0;
}