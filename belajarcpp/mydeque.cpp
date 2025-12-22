#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), prev(nullptr), next(nullptr) {}
};

class MyDeque {
    Node* head;
    Node* tail;
    int counter;


public:
    MyDeque(){
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }
    ~MyDeque(){
        Node* current = head;
        Node* nodeToDelete;

        while (current != nullptr){
            nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
        tail = nullptr;
        head = nullptr;
    }

    void insertFront(int x){
        Node* newNode = new Node(x);
        // jika kosong
        if (head == nullptr){
            tail = newNode;
            head = newNode;
        }
        // jika lebih dari 1 elemen
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        counter++;
    }
    void insertBack(int x){
        Node* newNode = new Node(x);
        // jika kosong
        if (tail == nullptr){
            tail = newNode;
            head = newNode;
        }
        // jika lebih dari 1 elemen
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        counter++;
    }
    int deleteFront(){
        Node* nodeToDelete;
        int value;
        if (head == nullptr){
            throw out_of_range("Deque kosong.\n");
        }
        if (head == tail){
            nodeToDelete = head;
            value = head->data;
            head = nullptr;
            tail = nullptr;
            delete nodeToDelete;
            counter -= 1;
            return value;
        }
        else {
            nodeToDelete = head;
            value = head->data;
            head->next->prev = nullptr;
            head = head->next;
            counter -= 1;
            return value;
        }

    }
    int deleteBack(){
        Node* nodeToDelete;
        int value;
        if (tail == nullptr){
            throw out_of_range("Deque kosong.\n");
        }
        if (head == tail){
            nodeToDelete = tail;
            value = tail->data;
            head = nullptr;
            tail = nullptr;
            delete nodeToDelete;
            counter -= 1;
            return value;
        }
        else {
            nodeToDelete = tail;
            value = tail->data;
            tail->prev->next = nullptr;
            tail = tail->prev;
            counter -= 1;
            return value;
        }

    }
    int getFront() const {
        if (head == nullptr){
            throw out_of_range("Deque kosong.\n");
        }
        return head->data;

    }
    int getBack() const {
        if (tail == nullptr){
            throw out_of_range("Deque kosong.\n");
        }
        return tail->data;
    }
    int getSize()const {
        return counter;
    }
    bool isEmpty() const {
        return head == nullptr;
    }
};

// --- MAIN FUNCTION UNTUK PENGUJIAN ---
int main() {

    cout << "===================================" << endl;
    cout << "UJI KASUS DEQUE (O(1)) DENGAN DLL" << endl;
    cout << "===================================" << endl;

    MyDeque dq;

    // --- UJI 1: INSERT DEPAN & BELAKANG ---
    dq.insertBack(10); // Deque: [10]
    dq.insertFront(5); // Deque: [5, 10]
    dq.insertBack(20); // Deque: [5, 10, 20]
    dq.insertFront(1); // Deque: [1, 5, 10, 20]

    cout << "1. List awal (1, 5, 10, 20)" << endl;
    cout << "   Front (Harusnya 1): " << dq.getFront() << endl;
    cout << "   Back (Harusnya 20): " << dq.getBack() << endl;
    cout << "   Size (Harusnya 4): " << dq.getSize() << endl;

    // --- UJI 2: PENGHAPUSAN CAMPURAN (Stack & Queue Ops) ---
    cout << "\n2. Hapus (Mix Ops)" << endl;

    // Pop/Delete Front (Queue/Stack)
    cout << "   Delete Front (Harusnya 1): " << dq.deleteFront() << endl; // List: [5, 10, 20]

    // Delete Back (Stack/Deque)
    cout << "   Delete Back (Harusnya 20): " << dq.deleteBack() << endl; // List: [5, 10]

    // Delete Front lagi (Harusnya 5)
    cout << "   Delete Front (Harusnya 5): " << dq.deleteFront() << endl; // List: [10]

    cout << "   Size setelah 3 hapus (Harusnya 1): " << dq.getSize() << endl;
    cout << "   Sisa (Harusnya 10): " << dq.getFront() << endl;

    // --- UJI 3: KASUS TEPI (SISA SATU NODE) ---
    cout << "\n3. Uji Kasus Tepi (Hapus Node Terakhir)" << endl;

    // Hapus Node Terakhir (10). Head dan Tail harus jadi nullptr
    cout << "   Delete Back (Harusnya 10): " << dq.deleteBack() << endl;

    cout << "   Is Empty? " << (dq.isEmpty() ? "YA" : "TIDAK") << endl; // YA

    // Uji Kasus Tepi: Hapus pada Deque Kosong (Harusnya exception)
    try {
        cout << "4. Uji Kasus Tepi: Delete Front pada Deque kosong. ";
        dq.deleteFront();
    } catch (const out_of_range& e) {
        cout << "Berhasil ditangani (Exception)." << endl;
    }


    return 0;
}
