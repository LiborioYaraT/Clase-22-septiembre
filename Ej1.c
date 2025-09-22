#include <stdio.h>
#include <stdlib.h>

struct Node {
    float data;
    struct Node* next;
};

struct Node* createNode(float data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Error: memoria no reservada");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printlist(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%.2f -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(3.14);
    struct Node* first = createNode(2.71);
    struct Node* second = createNode(1.41);
    struct Node* third = createNode(0.57);

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