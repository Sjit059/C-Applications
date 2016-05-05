#include <stdio.h>
#include <stdlib.h>

//create link list:
struct node{
    int data;
    struct node *next;
};
//function to printLinkNode
void printList(struct node *n) {
    while(n != NULL)
    {
        printf("%d  ",n->data);
        n = n->next;
    }
}
//Function to insert a node at first:
void InsertAtFirst(struct node **n)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = 0;
    newNode->next = *n;
    *n = newNode;
}

//Function to insert a node at the end:
void InsertAtEnd(struct node **n)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data =3;
    newNode->next = NULL;

    struct node *lastNode = *n;
    while(lastNode->next!= NULL)
    {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
}

//Function to insert after a given node:
void InsertAfterNode(struct node **n, int newValue)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    struct node *last = *n;
    newNode->data = newValue;
    newNode->next = last->next;
    last->next = newNode;

}

//Function to delete a given node:
void DeleteNode(struct node **n, int key) {
    struct node *head_ref = *n, *prev;
    while(head_ref->data != key){
        prev = head_ref;
        head_ref = head_ref->next;
    }
    prev->next = head_ref->next;

}

//Function to swap link node:
void SwapLinkNode(struct node **n, int value1, int value2)
{
    struct node *head_ref = *n, *prev1;
    while(head_ref->data != value1)
    {
        prev1 = head_ref;
        head_ref = head_ref->next;
    }

    struct node *head_ref2 = *n,*prev2;
    while(head_ref2->data != value2)
    {
        prev2 = head_ref2;
        head_ref2 = head_ref2->next;
    }


    if(prev1 != NULL)
    {
        prev1->next = head_ref2;
    }
    if(prev2 != NULL)
    {
        prev2->next = head_ref;
    }

    //swap the next pointer:
    struct node *tmp = head_ref2->next;
    head_ref2->next = head_ref->next;
    head_ref->next = tmp;
}
int main()
{
    struct node *head = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    head->data =1;
    head->next = second;

    second->data = 2;
    second->next = NULL;
    //Insert a node at first:
    InsertAtFirst(&head);
    //Insert a node at the end:
    InsertAtEnd(&head);
    //Insert after a given node:
    InsertAfterNode(&head, 11);
    //swap link node:
    SwapLinkNode(&head, 11,2);

    //Delete a given node:
    //DeleteNode(&head, 1);

    //PrintLinkNode:
    printList(head);

    return 0;
}
