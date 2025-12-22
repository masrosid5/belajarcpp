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
}
int main(){
    // Uji Kasus Gabungan Semua Fungsi

    // ----------------------------------------------------
    // SETUP Awal
    // ----------------------------------------------------
    Node* head_main = nullptr;
    Node* list_a = nullptr;
    Node* list_b = nullptr;

    // --- Uji insert dan reverse ---
    insertAtEnd(head_main, 10);
    insertAtEnd(head_main, 20);
    insertAtEnd(head_main, 30);
    insertAtEnd(head_main, 40);
    insertAtEnd(head_main, 50);

    cout << "--- Operasi Awal ---" << endl;
    cout << "List Awal: "; printList(head_main); // 10->20->30->40->50
    reverseList(head_main);
    cout << "Setelah Reverse: "; printList(head_main); // 50->40->30->20->10

    // --- Uji insertAtPosition dan deleteByValue ---
    insertAtPosition(head_main, 35, 3); // Sisipkan 35 di posisi 3
    cout << "Insert 35 di Pos 3: "; printList(head_main); // 50->40->35->30->20->10

    deleteByValue(head_main, 40); // Hapus di tengah
    deleteByValue(head_main, 50); // Hapus Head
    cout << "Setelah Hapus 40 & 50: "; printList(head_main); // 35->30->20->10

    // ----------------------------------------------------
    // UJI KASUS KRITIS 1: removeNthFromEnd
    // ----------------------------------------------------
    cout << "\n--- UJI removeNthFromEnd ---" << endl;
    cout << "Sebelum dihapus: " << endl;
    printList(head_main);
    // Hapus node ke-2 dari belakang (Node 20)
    head_main = removeNthFromEnd(head_main, 2);
    cout << "Hapus ke-2 dari Belakang (Node 20): "; printList(head_main); // 35->30->10

    // Hapus Head (N=L=3, Node 35)
    head_main = removeNthFromEnd(head_main, 3);
    cout << "Hapus ke-3 dari Belakang (Head, Node 35): "; printList(head_main); // 30->10

    // ----------------------------------------------------
    // UJI KASUS KRITIS 2: mergeSortedList
    // ----------------------------------------------------
    cout << "\n--- UJI mergeSortedList ---" << endl;

    // List A: 5 -> 15 -> 25
    insertAtEnd(list_a, 5); insertAtEnd(list_a, 15); insertAtEnd(list_a, 25);
    // List B: 10 -> 20 -> 30
    insertAtEnd(list_b, 10); insertAtEnd(list_b, 20); insertAtEnd(list_b, 30);

    cout << "List A: "; printList(list_a);
    cout << "List B: "; printList(list_b);

    Node* mergedList = mergeSortedList(list_a, list_b);
    cout << "Setelah digabung: "; printList(mergedList); // 5->10->15->20->25->30

    reorderList(mergedList);
    cout << "Setelah reorderList: "; printList(mergedList);
    // PENTING: Hanya hapus list gabungan (mergedList) karena node-nya dipakai ulang.
    deleteList(mergedList);

    // ----------------------------------------------------
    // UJI KASUS KRITIS 3: filterList dan hasCycle
    // ----------------------------------------------------
    Node* head_filter = nullptr;
    insertAtEnd(head_filter, 1); insertAtEnd(head_filter, 8); // 1 (ganjil)
    insertAtEnd(head_filter, 3); insertAtEnd(head_filter, 4); // 3 (ganjil)
    insertAtEnd(head_filter, 5); insertAtEnd(head_filter, 2); // 5 (ganjil)

    cout << "\n--- UJI filterList dan hasCycle ---" << endl;
    cout << "List Filter Awal: "; printList(head_filter); // 1->8->3->4->5->2

    filterList(head_filter);
    cout << "List Setelah Filter Ganjil: "; printList(head_filter); // 8->4->2

    // Uji hasCycle pada list tanpa siklus
    cout << "List memiliki siklus? " << (hasCycle(head_filter) ? "Ya" : "Tidak") << endl;

    // Pembebasan memori
    deleteList(head_filter);

    return 0;
}
