#include <stdlib.h>


/** Comment out lines below */

//#include "function.h"

typedef struct node {
    int idx;
    struct node* next;
} Node;

/** Comment out lines above */


void AddFront(Node** head, Node** back, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->idx = num;
    newNode->next = (*head)->next;
    (*head)->next = newNode;

    // When the list is empty, addFront is equivalent to adding to back
    // so we should update the back too.
    if (*head == *back) {
        *back = newNode;
    }
}

void AddBack(Node** head, Node** back, int num) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->idx = num;
    newNode->next = (*back)->next;
    (*back)->next = newNode;
    (*back) = newNode;
}

void DeleteFront(Node** head, Node** back) {
    // do nothing if list is empty
    if (*head == *back)
        return;

    Node* nodeToDelete = (*head)->next;
    (*head)->next = (*head)->next->next;

    // Deleting front node of a list of 1 item is equivalent to delete the back
    if (*back == nodeToDelete) {
        *back = *head;
    }

    free(nodeToDelete);
}

void Delete(Node** head, Node** back, int num) {

}

void Swap(Node** head, Node** back) {

}











