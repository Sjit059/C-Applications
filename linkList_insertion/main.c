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

    //PrintLinkNode:
    printList(head);

    return 0;
}
