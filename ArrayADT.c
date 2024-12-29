//Creating an abstract data type

#include <stdio.h>
#include <stdlib.h>

struct myArray
{
    int total_space;
    int used_space;
    int *ptr;
};

void createArray(struct myArray *a, int tSpace, int uSpace)
{
    a-> total_space = tSpace;
    a-> used_space = uSpace;
    a-> ptr = (int*) malloc(tSpace * sizeof(int));
}

void setArray(struct myArray *a, int tSpace, int uSpace)
{
    int n;
    for(int i=0 ; i<uSpace; i++)
    {
        printf("Enter element %d=", i);
        scanf("%d", &n);
        (a->ptr)[i]=n;
    }
}

void printArray(struct myArray *a, int tSize, int uSize)
{
    for(int i=0;i<uSize;i++)
    {
        printf("%d\n", (a->ptr)[i]);
    }
}

int main()
{
    struct myArray Marks;
    createArray(&Marks, 10, 2);
    printf("Creating array...\n");
    setArray(&Marks, 10, 2);
    printf("Printing Values:\n");
    printArray(&Marks, 10, 2);


    return 0;
}