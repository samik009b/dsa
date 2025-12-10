#include <stdio.h>
#include <stdlib.h>

/**
 * front - Keeps track of first element in the queue
 *         Front stays place until first element is removed
 *  rear - Keeps track of last added element in the queue
 *         Rear stays in same place until new element is added
 */
int front = -1, rear = -1;

void enqueue (int *queue, int value, int size) {
    if (rear == size - 1) {
        printf("Queue is full\n");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear += 1;
        queue[rear] = value;
        printf("pushed %d, queue size %d Bytes\n", queue[rear], sizeof(queue));
    }
}

void dequeue (int *queue, int size) {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    }
    else if (front == 0 && rear == 0) {
        front = rear = -1;
    }
    else if (front < rear) {
        front++;
    }
    printf("size of queue %d Bytes\n", sizeof(queue));
}

void display (int *queue, int size) {
    if (rear == -1 || front > rear) {
        printf("Queue is empty, nothing to display\n");
    }
    else {
        for (int i = front; i <= rear; i++) {
            printf("%d", queue[i]);
        }
    }
}

int main () {
    int size, choice, value;
    
    printf("Input size of queue : ");
    scanf("%d", &size);
    int *queue = (int*) malloc(size * sizeof(int));

    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            enqueue(queue, value, size);
            break;

            case 2:
            dequeue(queue, size);
            break;

            case 3:
            display(queue, size);
            break;

            case 4:
            printf("Exiting menu");
            return 0;

            default:
            printf("enter between 1 -4\n");
        }
    }
    return 0;
}