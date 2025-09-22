#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;  // Se agregó el punto y coma que faltaba
};

// Corrección: 'struct Node' no 'struct node'
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL){
        printf("Error: memoria no reservada");
        exit(1);
    }

    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Corrección: 'Node' no 'NOde'
void printlist(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct Node* head = createNode(10);
    struct Node* first = createNode(11);
    struct Node* second = createNode(12);
    struct Node* third = createNode(13);

    // Conectar los nodos correctamente
    head->next = first;
    first->next = second;
    second->next = third;

    printlist(head);

    // Liberar memoria correctamente (sin duplicar head)
    free(head);
    free(first);
    free(second);
    free(third);
    
    return 0; 
}