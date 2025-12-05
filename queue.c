#include <stdio.h>

int queue[100];
/**
 * front - Keeps track of first element in the queue
 *         Front stays place until first element is removed
 *  rear - Keeps track of last added element in the queue
 *         Rear stays in same place until new element is added
 */
int front = -1, rear = -1;

void enqueue (int value, int size) {
    if (rear == size - 1) {
        printf("Queue is full");
    }
    else {
        if (front == -1) {
            front = 0;
        }
        rear += 1;
        queue[rear] = value;
    }
}

void dequeue (int size) {
    if (front == -1 || front > rear) {
        printf("Queue is empty");
    }
    else if (front == 0 && rear == 0) {
        front = rear = -1;
    }
    else if (front < rear) {
        front++;
    }
}

void display (int size) {
    if (rear == -1 || front > rear) {
        printf("Queue is empty, nothing to display");
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

    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            enqueue(value, size);
            break;

            case 2:
            dequeue(size);
            break;

            case 3:
            display(size);
            break;

            case 4:
            printf("Exiting menu");
            return 0;
        }
    }
    return 0;
}