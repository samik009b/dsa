#include <stdio.h>
#include <stdlib.h>

int top = -1;   // tracks element

void push (int *stack, int value, int size) {
    if (top == size -1) {
        printf("Stack is full\n");
    }
    else {
        top += 1;
        stack[top] = value;
        printf("added %d\n", stack[top]);
    }
}

void pop (int *stack, int size) {
    if (top == -1) {
        printf("Stack is empty\n");
    }
    else {
        top--;
        printf("removed %d\n", stack[top+1]);
    }
}

void display (int *stack, int size) {
    if (top == -1) {
        printf("Stack empty, nothing to display\n");
    }
    else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
    }
}

int main () {
    int size, choice, value;
    int *stack = (int*)malloc (size * sizeof(int));
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
            push(stack, value, size);
            break;

            case 2:
            pop(stack, size);
            break;

            case 3:
            display(stack, size);
            break;

            case 4:
            free(stack);
            printf("Exiting menu");
            return 0;

            default:
            printf("Enter between 1-4\n");
            break;
        }
    }
    return 0;
}
