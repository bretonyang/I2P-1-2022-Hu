#include <stdio.h>
#include <stdlib.h>
#include "function.h"

/// TODO: Try using recursive `Solver` function to avoid awkward conditions.

Node* reverse(Node* head, Node* tail);

Node* Solver(Node* head, int k) {

    Node* groupHead = head;
    Node* groupTail = head;
    Node* lastGroupHead = head;
    int sizeOfGroup = 0;
    int notReversedYet = 1;

    // walk through list and count current group's size
    while (groupTail != NULL) {
        sizeOfGroup += 1;
        Node* nextNode = groupTail->next;

        // reverse size k group
        if (sizeOfGroup == k) {
            // reverse the group
            reverse(groupHead, groupTail);

            // default link of the groupHead
            groupHead->next = nextNode;

            // if it's the first reversed group, we want to
            // return the head of the reversed group
            if (notReversedYet) {
                head = groupTail;
                notReversedYet = 0;
            }
            else {
                // link different groups
                lastGroupHead->next = groupTail;
                lastGroupHead = groupHead;
            }

            // reset the size
            sizeOfGroup = 0;
            groupHead = nextNode;
        }

        groupTail = nextNode;
    }

    return head;
}

Node* reverse(Node* head, Node* tail) {
    if (head == tail) {
        return tail;
    }

    Node* headOfReversed = reverse(head->next, tail);
    head->next->next = head;
    head->next = NULL;
    return headOfReversed;
}

