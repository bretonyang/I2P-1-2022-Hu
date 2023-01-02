#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/*

3 3 1 3 8 5 6 5 6 0

*/

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
    /// TODO: We can consider using a map to store the # of indices,
    /// so that we can break from loop earlier

    Node* ptr = *head;

    while (ptr->next != NULL) {
        if (ptr->next->idx == num) {
            Node* nodeToDelete = ptr->next;

            ptr->next = ptr->next->next;

            free(nodeToDelete);
        }
        else {
            ptr = ptr->next;
        }
    }

    // update the back node
    *back = ptr;
}

void Swap(Node** head, Node** back) {
    // empty list
    if ((*head)->next == NULL) {
        return;
    }

    Node* frontOfReversed = NULL;
    Node* curNodeToAdd = (*head)->next;

    while (curNodeToAdd != NULL) {
        Node* rest = curNodeToAdd->next;
        curNodeToAdd->next = frontOfReversed;
        frontOfReversed = curNodeToAdd;
        curNodeToAdd = rest;
    }

    *back = (*head)->next;
    (*head)->next = frontOfReversed;
}




