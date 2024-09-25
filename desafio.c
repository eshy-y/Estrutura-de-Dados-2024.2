#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;           
    struct Node* next;  
};

void initialize(struct Node** head_ref) {
    *head_ref = NULL;
}

void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = *head_ref;

    *head_ref = new_node;
}

void insertAtEnd(struct Node** head_ref, int new_data) {
    struct Node* new_node = malloc(sizeof(struct Node));
    struct Node* last = *head_ref; 

    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = new_node;
}

int countElements(struct Node* head) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }

    return count;
}

struct Node* search(struct Node* head, int key) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == key) {
            return current;
        }
        current = current->next;
    }

    return NULL;
}

void deleteNode(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;
    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next; 
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void reinitialize(struct Node** head_ref) {
    struct Node* current = *head_ref;
    struct Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head_ref = NULL;
}

void reverseList(struct Node** head_ref) {
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next; 
        current->next = prev; 
        prev = current;       
        current = next;       
    }
    *head_ref = prev; 
}

int main() {
    struct Node* head = NULL;
    initialize(&head);

    insertAtBeginning(&head, 10); 
    insertAtBeginning(&head, 20); 
    insertAtBeginning(&head, 30); 

    printList(head);

    reverseList(&head);

    printList(head);

    return 0;
}