// dll.cpp
// Implementing Double Linked List

#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int x) : data(x), prev(nullptr), next(nullptr){}
};

void insertAtBegin(Node* &head, Node* &tail, int value);
void insertAtEnd(Node* &head, Node* &tail, int value);
void printListForward(Node* head);
void printListBackward(Node* tail);
void deleteList(Node* &head);
void deleteAtEnd(Node* &head, Node* &tail);
void deleteNode(Node* &head, Node* &tail, Node* nodeToDelete);

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    Node* node_A = nullptr;
    Node* node_B = nullptr;
    Node* node_C = nullptr;

    cout << "========================================" << endl;
    cout << "  UJI KASUS DOUBLY LINKED LIST (DLL)  " << endl;
    cout << "========================================" << endl;

    // --- UJI KASUS 1: INSERT DAN TRAVERSAL ---
    cout << "\n--- UJI 1: INSERT & TRAVERSAL ---" << endl;
    insertAtBegin(head, tail, 10);
    insertAtEnd(head, tail, 40);
    insertAtBegin(head, tail, 5);
    insertAtEnd(head, tail, 50);
    // List: 5 <-> 10 <-> 40 <-> 50 (Head=5, Tail=50)

    cout << "List: "; printListForward(head); // 5->10->40->50
    cout << "Head: " << head->data << ", Tail: " << tail->data << endl;
    cout << "Mundur: "; printListBackward(tail); // 50->40->10->5

    // Simpan pointer untuk uji deleteNode
    node_A = head; // 5
    node_B = head->next->next; // 40
    node_C = tail; // 50

    // ----------------------------------------------------
    // UJI KASUS 2: DELETE AT END (O(1))
    // ----------------------------------------------------
    cout << "\n--- UJI 2: DELETE AT END ---" << endl;

    deleteAtEnd(head, tail); // Hapus 50
    cout << "Setelah Hapus Akhir (50): "; printListForward(head); // 5->10->40
    cout << "Tail Baru: " << tail->data << endl; // 40

    deleteAtEnd(head, tail); // Hapus 40 (Tail baru adalah 10)
    cout << "Setelah Hapus Akhir (40): "; printListForward(head); // 5->10
    cout << "Tail Baru: " << tail->data << endl; // 10


    // ----------------------------------------------------
    // UJI KASUS 3: DELETE NODE ARBITRER (O(1))
    // ----------------------------------------------------
    cout << "\n--- UJI 3: DELETE NODE ARBITRER ---" << endl;
    // List saat ini: 5 <-> 10
    insertAtEnd(head, tail, 15);
    insertAtEnd(head, tail, 20); // List: 5 <-> 10 <-> 15 <-> 20 (A=5, B=15, C=20)

    Node* node_H = head; // 5
    Node* node_M = head->next->next; // 15
    Node* node_T = tail; // 20

    cout << "List sebelum hapus: "; printListForward(head); // 5->10->15->20

    // a) Hapus Node Tengah (15)
    deleteNode(head, tail, node_M);
    cout << "Hapus Tengah (15): "; printListForward(head); // 5->10->20 (BENAR)

    // b) Hapus Head (5)
    deleteNode(head, tail, node_H);
    cout << "Hapus Head (5): "; printListForward(head); // 10->20 (BENAR)
    cout << "Head Baru: " << head->data << endl; // 10

    // c) Hapus Tail (20)
    deleteNode(head, tail, node_T);
    cout << "Hapus Tail (20): "; printListForward(head); // 10 (BENAR)
    cout << "Tail Baru: " << tail->data << endl; // 10


    // ----------------------------------------------------
    // UJI KASUS 4: HAPUS SATU NODE (Kasus: head == tail)
    // ----------------------------------------------------
    cout << "\n--- UJI 4: HAPUS SATU NODE ---" << endl;

    // List saat ini: 10
    Node* node_last = head;
    deleteNode(head, tail, node_last); // Hapus 10
    cout << "Setelah Hapus Sisa Node (10): ";
    if (head == nullptr) cout << "List Kosong (nullptr)." << endl; // BENAR


    // ----------------------------------------------------
    // UJI KASUS 5: HAPUS PADA LIST KOSONG
    // ----------------------------------------------------
    cout << "\n--- UJI 5: KASUS KOSONG ---" << endl;
    deleteAtEnd(head, tail); // Harusnya tampil "Gagal: List kosong."

    // Pembersihan memori final
    // deleteList(head, tail); // Tidak perlu dipanggil karena semua sudah dihapus oleh deleteNode/deleteAtEnd
    return 0;
}

void insertAtBegin(Node* &head, Node* &tail, int value){
    Node* newNode = new Node(value);

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;

}
void insertAtEnd(Node* &head, Node* &tail, int value){
    Node* newNode = new Node(value);
    if (tail == nullptr){
        tail = newNode;
        head = newNode;
        return;
    }
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}
void printListForward(Node* head){
    Node* current = head;

    while (current != nullptr) {
        cout << current->data; // mencetak nilai pada node

        current = current->next;

        if (current != nullptr){ // jika node bukan node terakhir,
            cout << "->";
        }
    }
    cout << endl; // ganti baris
}
void printListBackward(Node* tail){
    Node* current = tail;

    while (current != nullptr) {
        cout << current->data; // mencetak nilai pada node

        current = current->prev; // pindah ke node sebelumnya

        if (current != nullptr){ // jika node bukan node pertama,
            cout << "->";
        }
    }
    cout << endl; // ganti baris
}

void deleteList(Node* &head){
    Node* current = head;

    while (current != nullptr){
        Node* next = current->next;
        current->prev = nullptr;
        delete current;
        current = next;
    }
    head = nullptr;
    cout << "Memori berhasil dibebaskan." << endl;
}

void deleteAtEnd(Node* &head, Node* &tail){
    if (head == nullptr){
        cout << "List kosong. Tidak ada yang bisa dihapus" << endl;
        return;
    }
    if (head == tail){
        head = nullptr;
        delete tail;
        tail = nullptr;
        return;
    }
    Node* newTail = tail->prev;
    newTail->next = nullptr;
    delete tail;
    tail = newTail;
}

// asumsinya nodeToDelete sudah diketahui
void deleteNode(Node* &head, Node* &tail, Node* nodeToDelete){

    if(nodeToDelete == head && nodeToDelete == tail){
        head = nullptr;
        tail = nullptr;
        delete nodeToDelete;
        return;
    }
    else if(nodeToDelete == head){
        head = head->next;
        if (head != nullptr){
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete nodeToDelete;
        return;
    }else if (nodeToDelete == tail){
        tail->prev->next=nullptr;
        tail = tail->prev;
        delete nodeToDelete;
        return;
    }

    nodeToDelete->prev->next = nodeToDelete->next;
    nodeToDelete->next->prev = nodeToDelete->prev;
    delete nodeToDelete;
}
