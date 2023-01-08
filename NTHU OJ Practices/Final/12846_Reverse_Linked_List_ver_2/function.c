#include <stdio.h>
#include <stdlib.h>

#include "function.h"

// Add one Node (with data = x) at the front of linked list.
void Push(Node** ptr_head, int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = *ptr_head;
    *ptr_head = newNode;
}

// Delete the Node at the front of linked list.
void Pop(Node** ptr_head) {
    if (*ptr_head == NULL) {
        return;
    }

    Node* nodeToDelete = (*ptr_head);
    *ptr_head = (*ptr_head)->next;
    free(nodeToDelete);
}

Node* reverse(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    Node* headOfReversed = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return headOfReversed;
}

void Reverse_List(Node** ptr_head) {
    *ptr_head = reverse(*ptr_head);
}

