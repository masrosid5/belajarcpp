// sll.cpp
// program ini mencoba untuk implementasi singly-linked list

#include <iostream>

using namespace std;

// Node
struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr){}
};

// Fungsi printList menerima parameter berupa pointer ke object Node
// Fungsi untuk mencetak Linked List di layar
// dalam format 3->5->6
void printList(Node* head){
    Node* current = head;

    while (current != nullptr) {
        cout << current->data; // mencetak nilai pada node

        current = current->next; // pindah ke node berikutnya
        if (current != nullptr){ // jika node bukan node terakhir,
            cout << "->";
        }
    }
    cout << endl; // ganti baris
}
// Fungsi insertAtBegin menerima paramater berupa pointer ke Node head, pass by reference
// dan value sebagai data
void insertAtBegin(Node*& head, int value){
    Node* newNode = new Node(value); // bikin node baru
    newNode->next = head; // arahkan ke node head
    head = newNode; // jadikan sebagai head
}

// Fungsi insertAtEnd:
// parameter pointer ke node head (pass by reference) agar bisa diganti
// dan value sebagai data
void insertAtEnd(Node* &head, int value){
    Node* newNode = new Node(value); // bikin node baru
    newNode->next = nullptr; // arahkan ke nullptr krn akan dirantai paling ujung akhir

    // Kasus 1: Jika linked list masih kosong
    if (head == nullptr){
        head = newNode; // jadikan sebagai head
        return; // keluar fungsi
    }

    // Kasus 2: jika linked list tidak kosong
    Node* last = head; // akan kita iterasi sampai nemu node terakhir
    while (last->next != nullptr){ // jika masih belum ujung node terakhir
        last = last->next; // geser ke node berikutnya
    }
    // sekarang sudah di posisi node terakhir.
    last->next = newNode; // kaitkan node baru tadi
}

// Fungsi inserAtPosition
// parameter: pointer ke node head (pass by reference)
// value sebagai data
// pos adalah posisi/letak penempatan node
// memasukkan nilai value ke dalam posisi pos dalam linked list
void insertAtPosition(Node* &head, int value, int pos){
    // Jika list masih kosong, atau cuma ada 1 node head
    if (pos <= 1 || head == nullptr ) {
        insertAtBegin(head, value); // sisipkan di depan
        return;
    }

    // jika list tidak kosong dan bukan 1 node doang
    Node* newNode = new Node(value); // buat node baru, dan tampung datanya
    newNode->next = nullptr;

    // kita akan iterasi sampai ke posisi pos-2
    // contoh: Misalkan kita akan menyisipkan di posisi 3 pada list 3->5->6->7
    //
    Node* current = head;
    for (int i = 0; i < pos-2; i++){
        if (current->next == nullptr){
            cout << "Gagal menyisipkan. " << pos << " pada posisi di luar batas list" << endl;
            delete newNode;
            return;
        }
        current = current->next;
    }
//    if (current == nullptr) {
//        cout << "Gagal menyisipkan. " << pos << " pada posisi di luar batas list" << endl;
//        delete newNode;
//        return;
//    }
    newNode->next = current->next;
    current->next = newNode;
}

void deleteByValue(Node* &head, int value){
    Node* current = head;
    Node* prev = nullptr;

    if (head == nullptr){
        cout << "List kosong. Tidak dapat menhapus" << endl;
        return;
    }

    // jika data yang dihapus ada di head, hapus head setelah head dipindah ke element kedua
    if (current->data == value){
        head = head->next;
        delete current;
        cout << value << " berhasil dihapus" << endl;
        return;
    }
    while (current != nullptr && current->data != value){
        prev = current;
        current = current->next;
    }
    // jika data ditemukan, hapus
    if (current != nullptr){
        prev->next = current->next;
        delete current;
        cout << value << " berhasil dihapus" << endl;
    }
    else {
        cout << "Nilai " << value << " tidak ditemukan." << endl;
    }
}

void deleteList(Node* &head){
    Node* current = head;

    while (current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    cout << "Memori berhasil dibebaskan." << endl;
}

// fungsi ini menghapus elemen dari list yang berupa bilangan ganjil
// menyisakan yang genap aja
void filterList(Node* &head){
    Node* prev;
    Node* current;

    while ( head != nullptr && head->data % 2 != 0){
        Node* nodeToDelete = head;
        head = head->next;
        delete nodeToDelete;
    }
    if (head == nullptr) return;

    prev = head;
    current = head->next;
    while (current != nullptr){
        if (current->data % 2 != 0){
            Node* nodeToDelete = current;
            prev->next = current->next;

            current = current->next;
            delete nodeToDelete;
        }
        else {
            prev = current;
            current = current->next;
        }
    }
}

void reverseList(Node* &head){
    Node* prev = nullptr;
    Node* current;
    Node* next;

    current = head;
    while (current != nullptr){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

// Fungsi hasCycle (Node* head)
// return true if the list has cycle in it
bool hasCycle(Node* head){
    if (head == nullptr || head->next == nullptr ) return false;
    Node* slowptr = head;
    Node* fastptr = head;

    while (fastptr != nullptr && fastptr->next != nullptr){
        slowptr = slowptr->next;
        fastptr = fastptr->next->next;
        if (slowptr == fastptr) return true;
    }
    return false;
}

// menghapus nilai pada posisi ke n dari belakang
Node* removeNthFromEnd(Node* head, int n){
    Node* dummy = new Node(0);
    dummy->next = head;
    Node* first = dummy;
    Node* second =dummy;

    for (int i = 1; i <= n+1; i++){
        if (first == nullptr){
            delete dummy;
            return head;
        }
        first = first->next;
    }

//    first = head;
//    second = head;
//    for (int i=1; i <= n; i++){
//        if (first == nullptr) return head;
//        first = first->next;
//    }
//    if (first==nullptr) {
//        head = second->next;
//        second->next = nullptr;
//        delete second;
//        return head;
//    }

    while (first!= nullptr){
        first = first->next;
        second = second->next;
    }

    Node* nodeToDelete = second->next;
    second->next = second->next->next;

    Node* newHead = dummy->next;
    delete nodeToDelete;
    delete dummy;

    return newHead;
}

// Function mergeSortedList receive two sorted list
// and return the mergedList
Node* mergeSortedList(Node* list1, Node* list2){
    Node* dummyHead = new Node(-2);
    Node* current = dummyHead;

    while (list1 != nullptr && list2 != nullptr){
        if (list1->data <= list2->data){
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    if (list1!= nullptr) {
        current->next = list1;
    }
    else{
        current->next = list2;
    }

    Node* mergedHead = dummyHead->next;
    delete dummyHead;

    return mergedHead;
}

void reorderList(Node* &head){
    if (head == nullptr || head->next == nullptr) return;
    // Tahap 1: Mencari titik tengah dan membagi list
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr && fast->next->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head2 = slow->next;
    slow->next = nullptr;
    Node* head1 = head;

    // Tahap 2: Mmembalik separuh list terakhir
    reverseList(head2);

    // Tahap 3: Menyambung secara alternatif
    while (head2 != nullptr){
        Node* next1 = head1->next;
        Node* next2 = head2->next;

        head1->next = head2;
        head2->next = next1;

        head1 = next1;
        head2 = next2;
    }
    if (head1!= nullptr){
        head1->next = nullptr;
    }
}
int main(){
    Node* head_even = nullptr;
    Node* head_odd = nullptr;

    // Kasus 1: Jumlah Node Genap (1->2->3->4->5->6)
    insertAtEnd(head_even, 1); insertAtEnd(head_even, 2); insertAtEnd(head_even, 3);
    insertAtEnd(head_even, 4); insertAtEnd(head_even, 5); insertAtEnd(head_even, 6);

    cout << "--- KASUS GENAP ---" << endl;
    cout << "Awal: "; printList(head_even); // 1->2->3->4->5->6
    reorderList(head_even);
    cout << "Akhir: "; printList(head_even); // Hasil diharapkan: 1->6->2->5->3->4
    deleteList(head_even);

    // Kasus 2: Jumlah Node Ganjil (1->2->3->4->5)
    insertAtEnd(head_odd, 1); insertAtEnd(head_odd, 2); insertAtEnd(head_odd, 3);
    insertAtEnd(head_odd, 4); insertAtEnd(head_odd, 5);

    cout << "\n--- KASUS GANJIL ---" << endl;
    cout << "Awal: "; printList(head_odd); // 1->2->3->4->5
    reorderList(head_odd);
    cout << "Akhir: "; printList(head_odd); // Hasil diharapkan: 1->5->2->4->3
    deleteList(head_odd);

    return 0;
}
