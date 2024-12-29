// Create and Modify Array

#include <stdio.h>

void createArray(int array[],int size)
{   
    for(int i=0;i<size;i++)
    {
        printf("Enter element at index %d=",i);
        scanf("%d", &array[i]);
    }
}

void showArray(int array[], int size)
{   
    if(size==0)
    {
        printf("The array is empty!\n");
    }
    else
    {
        printf("{");
        for(int i=0;i<size;i++)
        {   
            if(i==size-1)
                printf("%d", array[i]);
            else   
                printf("%d,", array[i]);
        }
        printf("}\n");
    }
}

void updateArray(int array[], int size, int index, int element)
{
    if(size==0)
    {
        printf("The array is empty!\n");
    }
    if(index==size)
    {
        array[size]=element;
    }
    else
    {
        for(int i=size-1;i>=index;i--)
        {
            array[i+1]=array[i];
        }
        array[index]=element;
    }
}

void deleteArrayElement(int array[], int size, int index)
{
    if(size==0)
    {
        printf("The array is empty!\n");
    }
    else
    {
        for(int i=index;i<size-1;i++)
        {
            array[i]=array[i+1];
        }
    }
}

int main()
{   
    int capacity=100, size=0;
    int index, element;
    int array[capacity];
    int choice=-1;
    while(choice!=0)
    {
        printf("\nWelcome to array handling\n");
        printf("1. Create New Array \n 2. Show Array \n 3. Delete Array \n 4. Enter Element into the array \n 5. Delete element from array\n");
        printf("Please enter a choice:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the number of elements in the array=");
                scanf("%d",&size);
                if(size>=100)
                {
                    printf("!!Array exceeds assigned capacity!!\n");
                }
                else
                {
                    createArray(array, size);
                    printf("Array successfully created\n");
                }
                break;
            
            case 2:
                printf("Printing the array:\n");
                showArray(array,size);
                break;
            
            case 3:
                size=0;
                printf("Array successfully deleted! \n");
                break;

            case 4:
                printf("Enter the index you want to enter the element at:");
                scanf("%d",&index);
                if(index>size){printf("The array is only of size %d, try a smaller value\n", size); break;}
                printf("Enter the element value:");
                scanf("%d",&element);
                updateArray(array,size,index,element);
                size+=1;
                break;

            case 5:
                printf("Enter the index you want to delete the element at:");
                scanf("%d",&index);
                if(index>=size){printf("No element exists at this index\n", size); break;}
                if(index==size-1)
                {
                    size-=1; 
                    printf("Element successfully deleted at index %d\n", index); 
                    break;
                }
                deleteArrayElement(array,size,index);
                size-=1;
                printf("Element successfully deleted at index %d\n", index);
                break;

            default:
                printf("Wrong Input!\n");


        }
    }
    return 0;
}