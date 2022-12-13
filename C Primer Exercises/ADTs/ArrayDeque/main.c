#include <stdio.h>
#include <stdlib.h>

// Define the ArrayDeque structure
typedef struct {
  int *data;
  int front;
  int back;
  int size;
  int capacity;
} ArrayDeque;

// Initialize an empty ArrayDeque
void init(ArrayDeque *deque) {
  deque->front = 0;
  deque->back = -1;
  deque->size = 0;
  deque->capacity = 1;
  deque->data = (int *)malloc(deque->capacity * sizeof(int));
}

// Check if the ArrayDeque is empty
int isEmpty(ArrayDeque *deque) {
  return deque->size == 0;
}

// Check if the ArrayDeque is full
int isFull(ArrayDeque *deque) {
  return deque->size == deque->capacity;
}

// Check if the ArrayDeque is at or below the minimum capacity
int isBelowMinCapacity(ArrayDeque *deque) {
  return deque->capacity >= 1 && deque->size <= deque->capacity / 4;
}

// Resize the ArrayDeque if it is full or at or below the minimum capacity
void resize(ArrayDeque *deque) {
  if (isFull(deque)) {
    // Double the capacity if the deque is full
    deque->capacity *= 2;
    deque->data = (int *)realloc(deque->data, deque->capacity * sizeof(int));
  } else if (isBelowMinCapacity(deque)) {
    // Halve the capacity if the deque is at or below the minimum capacity
    deque->capacity /= 2;
    deque->data = (int *)realloc(deque->data, deque->capacity * sizeof(int));
  }
}

// Add an element to the front of the ArrayDeque
void addFront(ArrayDeque *deque, int data) {
  resize(deque);
  if (isFull(deque)) {
    printf("Error: deque is full.\n");
    return;
  }
  if (deque->front == 0) {
    deque->front = deque->capacity;
  }
  deque->front--;
  deque->data[deque->front] = data;
  deque->size++;
}

// Add an element to the back of the ArrayDeque
void addBack(ArrayDeque *deque, int data) {
  resize(deque);
  if (isFull(deque)) {
    printf("Error: deque is full.\n");
    return;
  }
}
