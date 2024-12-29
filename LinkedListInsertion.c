//Linked List Insertion
#include <stdlib.h>
#include <stdio.h>

struct Node
{
    int data;
    struct Node * next;
};

void DisplayLinkedList(struct Node * ptr)
{
    printf("Displaying Linked List:\n");
    while(ptr!=NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
}

struct Node * InsertAtBeginning(struct Node * ptr, int data)
{
    struct Node * new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data=data;
    new->next = ptr;
    ptr = new;
    return ptr; 
}

struct Node * InsertAtEnd(struct Node * head, int data)
{
    struct Node * new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data = data;
    new->next=NULL;
    if(head==NULL)
    {
        return new;
    }

    struct Node * ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next=new;
    
    return head;
}

struct Node * InsertInBetween(struct Node * head, int index, int data)
{
    struct Node * new;
    new = (struct Node *) malloc(sizeof(struct Node));
    new->data=data;
    int i =0;
    struct Node * ptr = head;
    while(i!=index-1)
    {
        ptr=ptr->next;
        i++;
    }
    new->next=ptr->next; 
    ptr->next=new;
    return head;
}

struct Node * FindNodeByIndex(struct Node * head, int index)
{
    if(head==NULL)
    {
        return NULL;
    }

    int i=0;
    struct Node * ptr = head;

    while(ptr!=NULL && i<index)
    {
        ptr=ptr->next;
        i++;
    }    
    if(i==index)
    {return ptr;}
    else
    {return NULL;}
}

struct Node * InsertAfterNode(struct Node * head, struct Node * ptr, int data)
{
    struct Node * new;
    new = (struct Node *)malloc(sizeof(struct Node));
    
    new->data=data;
    new->next=ptr->next;
    ptr->next=new;

    return head;
}
void main()
{
    int value, index;
    struct Node * head;
    struct Node * second;
    struct Node * third;
    struct Node * fourth;
    struct Node * fifth;

    //allocate memory
    head = (struct Node *) malloc(sizeof(struct Node));
    second = (struct Node *) malloc(sizeof(struct Node));
    third = (struct Node *) malloc(sizeof(struct Node));
    fourth = (struct Node *) malloc(sizeof(struct Node));
    fifth = (struct Node *) malloc(sizeof(struct Node));

    //Assign data
    head -> data = 10;
    second -> data = 20;
    third -> data = 30;
    fourth -> data = 40;
    fifth -> data = 50;

    //link nodes
    head -> next = second;
    second -> next = third;
    third -> next = fourth;
    fourth -> next = fifth;
    fifth -> next = NULL;
    printf("Hello\n");
    int choice=-1;
    while(choice!=0)
    {
        
        printf("1. Insert at beginning \n 2. Insert at End \n 3. Insert in Between\n 4. Insert after Node \n 5. Display Linked List \n 6. EXIT \n");
        printf("Enter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to enter at the beginning of Linked List:");
                scanf("%d", &value);
                head = InsertAtBeginning(head, value);
                break;

            case 2:
                printf("Enter value to enter at the end of Linked List:");
                scanf("%d", &value);
                head = InsertAtEnd(head, value);
                break;

            case 3:
                printf("Enter the index at which you want to add value:");
                scanf("%d", &index);
                printf("Enter the value:");
                scanf("%d", &value);
                head = InsertInBetween(head,index,value);
                break;
            
            case 4:
                printf("Choose the node(index starts from 0) after which you want to enter value:");
                scanf("%d", &index);
                struct Node * found_node = FindNodeByIndex(head, index);
                printf("Enter the value:");
                scanf("%d", &value);
                head = InsertAfterNode(head, found_node, value);
                break;
            case 5:
                if(head->next==NULL)
                {
                    printf("Linked List is empty!");
                    break;
                }
                DisplayLinkedList(head);
                break;
            default:
                printf("Wrong Input! \n");
        }
    }

}

