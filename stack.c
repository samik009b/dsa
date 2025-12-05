#include <stdio.h>

int stack[100]; // give any size of stack
int top = -1;   // tracks element

void push (int value, int size) {
    if (top == size -1) {
        printf("Stack is full");
    }
    else {
        top += 1;
        stack[top] = value;
    }
}

void pop (int size) {
    if (top == -1) {
        printf("Stack is empty");
    }
    else {
        top--;
    }
}

void display (int size) {
    if (top == -1) {
        printf("Stack empty, nothing to display");
    }
    else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
    }
}

int main () {
    int size, choice, value;

    printf("Input size of stack : ");
    scanf("%d", &size);

    // menu-driven program
    /**
     * 1. push element in stack
     * 2. pop element from stack
     * 3. display the stack
     * 4. exit the loop (menu)
     */
    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("Enter the value to be inserted : ");
            scanf("%d", &value);
            push(value, size);
            break;

            case 2:
            pop(size);
            break;

            case 3:
            display(size);
            break;

            case 4:
            printf("Exiting menu");
            return 0;

            default:
            printf("Enter between 1-4");
            break;
        }
    }
    return 0;
}