//Deleting in a Linked List
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

void Display(struct Node * head)
{
    struct Node * ptr = head;
    printf("Displaying Linked List:\n ");
    while(ptr!=NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr=ptr->next;
    }
}

struct Node * DeleteFirstNode(struct Node * head)
{
    struct Node * ptr = head;
    head = ptr->next;
    free(ptr);

    return head;
}

struct Node * DeleteLastNode(struct Node * head)
{   
    struct Node * ptr = head;
    struct Node * ptr2 = head->next;
    while(ptr2->next!=NULL)
    {
        ptr2=ptr2->next;
        ptr=ptr->next;
    }
    ptr->next=NULL;
    free(ptr2);

    return head;
}

struct Node * DeleteAtIndex(struct Node * head, int index)
{
    struct Node * ptr = head;
    struct Node * ptr2 = head->next;
    int i =0;
    while(i<index-1)
    {
        ptr=ptr->next;
        ptr2=ptr2->next;
        i++;
    }
    ptr->next=ptr2->next;
    free(ptr2);

    return head;
}

struct Node * DeleteByValue(struct Node * head, int value)
{
    struct Node * ptr = head;
    struct Node * ptr2 = head->next;
    if(ptr->data==value)
    {
        head=ptr2;
        free(ptr);
    }
    else
    {
        while(ptr2!=NULL)
        {
            if(ptr2->data==value)
            {
                ptr->next=ptr2->next;
                free(ptr2);
                break;
            }
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
    }

    return head;

}

void main()
{
    struct Node * head = (struct Node *)malloc(sizeof(struct Node));
    struct Node * second = (struct Node *)malloc(sizeof(struct Node));
    struct Node * third = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node * fifth = (struct Node *)malloc(sizeof(struct Node));

    head->data=10;
    second->data=20;
    third->data=30;
    fourth->data=40;
    fifth->data=50;

    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    int choice = -1;
    int index, value;

    while(choice!=0)
    {
        printf("1. Delete First Node \n 2. Delete Last Node \n 3. Delete node at Index \n 4. Delete Node by Value \n 5. Display LinkedList \n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
                head = DeleteFirstNode(head);
                break;
            case 2: 
                head = DeleteLastNode(head);
                break;
            case 3:
                printf("Enter index at which to delete Node at:");
                scanf("%d", &index);
                head = DeleteAtIndex(head, index);
                break;
            case 4:
                printf("Enter the value you want to delete in Linked List:");
                scanf("%d", &value);
                head = DeleteByValue(head, value);
                break;
            case 5:
                Display(head);
                break;
            default:
                printf("Wrong input!");
                break;
        }
    }
}