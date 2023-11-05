#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

typedef struct NodeQueue {
    Node* data;
    struct NodeQueue* next;
} NodeQueue;

typedef struct Queue {
    NodeQueue* head;
    NodeQueue* tail;
    int tamanho;
} Queue;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

Queue* InitQueue(){
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->head = NULL;
    q->tail = NULL;
    q->tamanho = 0;
    return q;
}

 void Enqueue(Queue** q, Node* data) {
    NodeQueue* novo = (NodeQueue*)malloc(sizeof(NodeQueue));
    novo->data = data;
    novo->next = NULL;
    if ((*q)->tamanho == 0) {
        (*q)->head = novo;
        (*q)->tail = novo;
    } else {
        (*q)->tail->next = novo;
        (*q)->tail = novo;
    }
    (*q)->tamanho++;
}

Node* dequeue(Queue** q) {
    if ((*q)->tamanho == 0) {
        return NULL;
    }

    NodeQueue* aux = (*q)->head;
    Node* data = aux->data;
    (*q)->head = (*q)->head->next;
    free(aux);
    (*q)->tamanho--;
    return data;
}



// Printa a baseado no nível de cada nó
void PrintInOrder(Node* root) {
    if (root == NULL) {
        printf("Empty tree\n");
    }
    Queue* Q = InitQueue();
    Enqueue(&Q, root);
    Node* current;

    while (Q->tamanho != 0) {
        current = dequeue(&Q);
        printf("%d ", current->data);
        if (current->left != NULL) {
            Enqueue(&Q,current->left);
        }
        if (current->right != NULL) {
            Enqueue(&Q,current->right);
        }
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
    }
}

int main(){
    
    Node* root = NULL;
    char inputC;
    int input;


      while (scanf(" %c", &inputC) != EOF) {
        if (inputC == 'i') {
            scanf(" %d", &input);
            root = insert(root, input);
        } else if (inputC == 'p') {
            clearBuffer();
            PrintInOrder(root);
            printf("\n");
        }
    }


    return 0;
}
