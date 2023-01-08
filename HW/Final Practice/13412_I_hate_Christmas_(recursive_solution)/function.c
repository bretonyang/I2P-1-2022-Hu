#include <stdio.h>
#include <stdlib.h>

#include "function.h"

Node* reverse(Node* head, Node* tail);

Node* Solver(Node* head, int k) {
    if (head == NULL) {
        return head;
    }

    Node* tailOfGroup = head;
    int sizeOfGroup = 1;
    while (tailOfGroup->next != NULL && sizeOfGroup != k) {
        sizeOfGroup++;
        tailOfGroup = tailOfGroup->next;
    }

    if (sizeOfGroup == k) {
        Node* headOfNextGroup = tailOfGroup->next;
        Node* headOfReversed = reverse(head, tailOfGroup);
        Node* headOfRest = Solver(headOfNextGroup, k);
        head->next = headOfRest; // head is now tail of reversed group
        return headOfReversed;
    }
    else {
        return head;
    }
}

// Returns the head of the reversed list
Node* reverse(Node* head, Node* tail) {
    if (head == tail) {
        return tail;
    }

    Node* headOfReversed = reverse(head->next, tail);
    head->next->next = head;
    head->next = NULL;
    return headOfReversed;
}
