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

//Function to delete a according to value:
void DeleteNode(struct node **n, int key)
{
    struct node *head_ref = *n, *prev;
    while(head_ref->data != key) {
        prev = head_ref;
        head_ref = head_ref->next;
    }
    prev->next = head_ref->next;
}

//Function to delete a according to key:

void DeleteNodeKey(struct node **n, int key)
{
    struct node *head_ref = *n, *prev;
    int i=1;
    while(i != key)
    {
        prev = head_ref;
        head_ref = head_ref->next;
        i++;
    }
    prev->next = head_ref->next;
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

    //Delete a node:
    DeleteNode(&head, 1);

    //Delete a node according to key:
    DeleteNodeKey(&head, 4);

    //PrintLinkNode:
    printList(head);
    //  0  11  1  2  3

    return 0;
}
