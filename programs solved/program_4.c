#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};


void insertAfter(struct Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("The given previous node cannot be NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;

    
    new_node->next = prev_node->next;
    prev_node->next = new_node;

    
    new_node->prev = prev_node;

    
    if (new_node->next != NULL) {
        new_node->next->prev = new_node;
    }
}


void deleteNode(struct Node** head_ref, struct Node* del) {
    if (*head_ref == NULL || del == NULL) return;

    
    if (*head_ref == del) {
        *head_ref = del->next;
    }

    
    if (del->next != NULL) {
        del->next->prev = del->prev;
    }

    
    if (del->prev != NULL) {
        del->prev->next = del->next;
    }

    free(del);
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->data = 10;
    head->prev = NULL;
    head->next = NULL;

    
    insertAfter(head, 20);      
    insertAfter(head->next, 30); 
    
    printf("List after insertions:\n");
    printList(head);

   
    deleteNode(&head, head->next); 

    printf("List after deleting node 20:\n");
    printList(head);

    return 0;
}