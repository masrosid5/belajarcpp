/*
Implementasi linked list dengan bahasa c
ini buat belajar malloc dan free
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node_t{
    int data;
    struct node_t* next;
} Node;

Node* createNode(int);
void deleteNode(Node**);
void insertFront(Node**, int);
void insertEnd(Node**, int);
void printList(Node*);
void deleteList(Node**);
int isEmpty(Node*);
void deleteValue(Node**, int);
void reverseList(Node**);

int main(){
    Node* head = NULL;
    int n, value;
    printf("Ini adalah program untuk implementasi LinkedList\nBerapa elemen? ");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++){
        printf("Masukkan elemen ke-%d: ",i);
        scanf("%d",&value);
        insertEnd(&head, value);
    }
    printf("List kamu adalah: ");
    printList(head);

    printf("Setelah dibalik: ");
    reverseList(&head);
    printList(head);
    
    printf("Elemen mana yang mau dihapus? ");
    scanf("%d",&value);
    deleteValue(&head, value);
    printf("Setelah dihapus\n ");
    printList(head);

    deleteList(&head);
    return 0;
}

Node* createNode(int data){
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

void deleteNode(Node** nodeToDelete){
    if (nodeToDelete == NULL || *nodeToDelete == NULL) return;
    else {
        int value = (*nodeToDelete)->data;
        free(*nodeToDelete);
        *nodeToDelete = NULL;
        //printf("%d berhasil dihapus dan memori berhasil dibebaskan\n",value);
    }
}

void insertFront(Node** head, int value){
    Node* newNode = createNode(value);
    
    newNode->next = *head;
    *head = newNode;
}

void insertEnd(Node** head, int value){
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }    

    Node* tail = *head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    tail->next = newNode;
}

void printList(Node* head){
    Node* current = head;

    while (current != NULL){
        printf("%d", current->data);
        if (current->next != NULL) printf("->");
        current = current->next;
    }
    printf("\n");
}

void deleteList(Node** head){
    Node* current = *head;
    Node* next;
    while (current != NULL){
        next = current->next;
        deleteNode(&current);
        current = next;
    }
    *head = NULL;
}

int isEmpty(Node* head){
    return head == NULL;
}

void deleteValue(Node** head, int value){
    if (head == NULL) return;

    char found = 'n';
    Node* current = *head;
    Node* prev = NULL;
    if (current->data == value){
        *head = current->next;
        deleteNode(&current);
        printf("%d berhasil dihapus...\n", value);
        return;
    }

    while (current != NULL && found != 'y'){
        if (current->data == value) {
            found = 'y';
            printf("%d berhasil dihapus...\n", value);
            Node* nodeToDelete = current;
            prev->next = current->next;
            deleteNode(&nodeToDelete);
            break;
        }
        else {
            prev = current;
            current = current->next;
            
        }
    }

    if (found == 'n') printf("Tidak ada nilai %d pada list\n", value);
    
}

void reverseList(Node** head){
    if (*head == NULL) return;

    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;

    while (current != NULL){
        next = current->next;
        current->next = prev;

        // geser prev dan next
        prev = current;
        current = next;
    }

    *head = prev;
}