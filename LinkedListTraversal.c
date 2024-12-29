#include <stdio.h>
#include <stdlib.h>

struct LinkedList
{
    int value;
    struct LinkedList * next;
};

void LinkedListTraversal(struct LinkedList * ptr)
{
    while(ptr!=NULL)
    {
        printf("Element: %d \n", ptr->value);
        ptr = ptr -> next;
    }
}

int main()
{
    struct LinkedList * head;
    struct LinkedList * second;
    struct LinkedList * third;
    struct LinkedList * fourth;

    //Allocate Memory
    head = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    second = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    third = (struct LinkedList *) malloc(sizeof(struct LinkedList));
    fourth = (struct LinkedList *) malloc(sizeof(struct LinkedList));

    //Link first and second node
    head -> value = 10;
    head -> next = second;

    //Link second and third node
    second->value=20;
    second->next=third;

    //link third and fourth
    third->value=30;
    third->next=fourth;

    //Terminate the linked list at the fourth node
    fourth->value=40;
    fourth->next=NULL;

    LinkedListTraversal(head);
    return 0;
}