#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;                       // head node initialized as null (mandatory)

void insert_node_at_last (int value) {
    struct Node *temporary = head;
    /**
     * creating the new node.
     * type-casting the node to give it type (struct Node*).
     * using malloc to allocate exact size for the new node.
     * allocating the value to the data field of the node.
     */
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node -> data = value;
    new_node -> next = NULL;

    /**
     * if the LL is empty, new node becomes head
     * else we iterate through the LL till the last node and then attach new node after
     */
    if (temporary == NULL) {
        head = new_node;
        return;
    }
    else {
        while (temporary -> next != NULL) {
            temporary = temporary -> next;
        }
        temporary -> next = new_node;
    }
}

void insert_node_at_start (int value) {
    struct Node *temporary = head;

    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node -> data = value;

    /**
     * if LL has not created we make the new node as head of the LL
     * else we attach the LL after it and make the new node as head
     */
    if (temporary == NULL) {
        new_node -> next = NULL;
        head = new_node;
    }
    else {
        new_node -> next = temporary;
        head = new_node;
    }
}

void remove_node_from_last () {
    struct Node *temporary = head;
    /**
     * if LL is empty then say just empty.
     * else iterate to the element before the last node and point it's next to null omitting the last node.
     */
    if (temporary == NULL) {
        printf("Linked list is empty\n");
        return;
    }

    /**
     * if LL has only one node we directly make the head as null.
     * else we iterate to 2nd last and points its next to null instead of last node.
     */
    if (temporary -> next == NULL) {
        head = NULL;
    }
    else {
        while (temporary -> next -> next != NULL) {
            temporary = temporary -> next;
        }
        temporary -> next = NULL;
    }
}

void remove_node_from_any_position (int target) {
    struct Node *temporary = head;
    struct Node *prev = NULL;

    /**
     * if LL is empty we just print message
     * else if head is target then we assign head as it's next node
     * else we find the target and then join the nodes beside it and link them together
     *      but here if we don't find the target the loop will end and temporary will be 
     *      NULL which indicates the target is not found in the list
     */
    if (temporary == NULL) {
        printf("Linked list is empty\n");
    }
    else if (temporary -> data == target) {
        head = temporary -> next;
    }
    else {
        while (temporary != NULL && temporary -> data != target) {
            prev = temporary;
            temporary = temporary -> next;
        }

        if (temporary == NULL) {
            printf("Target not found");
            return;
        }
        prev -> next = temporary -> next;          
    }                           
}

int main () {
    int value, choice;

    while (1) {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            printf("enter node value: ");
            scanf("%d", &value);
            insert_node_at_last(value);
            break;

            case 2:
            printf("enter node value: ");
            scanf("%d", &value);
            insert_node_at_start(value);
            break;

            case 3:
            remove_node_from_last();
            break;

            case 4:
            printf("enter node target: ");
            scanf("%d", &value);
            remove_node_from_any_position(value);
            break;

            case 5:
            printf("Exiting menu");
            return 0;

            default:
            printf("Enter a valid option between 1 to 5");
            break;
        }
    }
    return 0;
}
