#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char data[50];
    struct Node* next;
};

struct Node* createNode(const char* data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: memoria no reservada");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

void printlist(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode("Hola");
    struct Node* first = createNode("mundo");
    struct Node* second = createNode("listas");
    struct Node* third = createNode("enlazadas");

    head->next = first;
    first->next = second;
    second->next = third;

    printlist(head);

    free(head);
    free(first);
    free(second);
    free(third);

    return 0;
}