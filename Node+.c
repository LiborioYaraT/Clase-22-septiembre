#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

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

// Función para crear una lista de n nodos automáticamente
struct Node* createLargeList(int nodeCount) {
    if (nodeCount <= 0) return NULL;
    
    struct Node* head = createNode(1);  // Primer nodo con valor 1
    struct Node* current = head;
    
    // Crear los nodos restantes usando un bucle
    for (int i = 2; i <= nodeCount; i++) {
        current->next = createNode(i);  // Cada nodo tiene un valor incremental
        current = current->next;
    }
    
    return head;
}

void printlist(struct Node* head){
    struct Node* temp = head;
    int count = 0;
    
    // Limitar la impresión a los primeros 10 nodos para no saturar la consola
    while (temp != NULL && count < 10)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
        count++;
    }
    
    if (temp != NULL) {
        printf("... -> ");  // Indicador de que hay más nodos
    }
    printf("NULL\n");
}

// Función para liberar toda la memoria de la lista
void freeList(struct Node* head) {
    struct Node* temp;
    int freedNodes = 0;
    
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
        freedNodes++;
    }
    
    printf("Se liberaron %d nodos de memoria\n", freedNodes);
}

// Función para contar los nodos en la lista
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    return count;
}

int main(){
    const int NODE_COUNT = 10000;
    
    printf("Creando lista con %d nodos...\n", NODE_COUNT);
    struct Node* head = createLargeList(NODE_COUNT);
    
    printf("Lista creada exitosamente!\n");
    printf("Total de nodos: %d\n", countNodes(head));
    
    printf("\nPrimeros 10 nodos de la lista:\n");
    printlist(head);
    
    // Liberar toda la memoria
    printf("\nLiberando memoria...\n");
    freeList(head);
    
    return 0;
}