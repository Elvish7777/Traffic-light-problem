#include <stdio.h>
#include <stdlib.h>

// Define the structure for a queue node
typedef struct Node {
    int vehicle_id;
    struct Node* next;
} Node;

// Define the queue structure
typedef struct Queue {
    Node* front;
    Node* rear;
    int size;
} Queue;

// Function to initialize a queue
Queue* createQueue() {
    Queue* q = (Queue)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    q->size = 0;
    return q;
}

// Function to enqueue a vehicle
void enqueue(Queue q, int vehicle_id) {
    Node* temp = (Node)malloc(sizeof(Node));
    temp->vehicle_id = vehicle_id;
    temp->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->size++;
}

// Function to dequeue a vehicle
int dequeue(Queue q) {
    if (q->front == NULL) return -1; // Queue is empty
    Node* temp = q->front;
    int vehicle_id = temp->vehicle_id;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    q->size--;
    return vehicle_id;
}

// Function to check if the queue is empty
int isEmpty(Queue* q) {
    return q->size == 0;
}
