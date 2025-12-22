#include <iostream>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr){}
};

class MyQueue {
    Node* head;
    Node* tail;
    int counter;

public:
    MyQueue (){
        head = nullptr;
        tail = nullptr;
        counter = 0;
    }
    MyQueue (int x){
        Node* newNode = new Node(x);
        head = newNode;
        tail = newNode;
        counter = 1;
    }
    ~MyQueue(){
        Node* current = head;

        while (current != nullptr){
            Node* next = current->next;
            current->prev = nullptr;
            delete current;
            current = next;
        }
        head = nullptr;
    }
    // memasukkan data dari belakang
    void enqueue(int x){
        Node* newNode = new Node(x);
        if (tail == nullptr) {
            tail = newNode;
            head = newNode;
        }
        else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
        }
        counter +=1;
    }

    // mengeluarkan data dari depan
    int dequeue(){
        Node* nodeToDelete;
        int value;
        if (head == nullptr){
            throw out_of_range("Tidak ada antrian.");
        }
        else if (head == tail){
            nodeToDelete = head;
            value = head->data;
            head = nullptr;
            tail = nullptr;
            delete nodeToDelete;
            counter -=1;
            return value;
        }
        else {
            nodeToDelete = head;
            value = head->data;
            head = head->next;
            head->prev = nullptr;
            delete nodeToDelete;
            counter -= 1;
            return value;
        }
    }

    // mengintip data paling depan tanpa menghapus
    int peek(){
        if (head == nullptr){
            throw out_of_range("Tidak ada antrian.");
        }
        return head->data;
    }

    // mengecek kosong atau tidak
    bool isEmpty(){
        return counter == 0;
    }

    int get_size(){
        return counter;
    }
};

int main(){
    cout << "===================================" << endl;
    cout << "UJI KASUS QUEUE (FIFO) DENGAN DLL" << endl;
    cout << "===================================" << endl;

    MyQueue myQueue;

    // Enqueue elemen (masuk dari belakang)
    myQueue.enqueue(100); // [100]
    myQueue.enqueue(200); // [100, 200]
    myQueue.enqueue(300); // [100, 200, 300]

    cout << "1. Enqueue: 100, 200, 300" << endl;
    cout << "   Size: " << myQueue.get_size() << endl;
    cout << "   Peek (Harusnya 100): " << myQueue.peek() << endl;

    // Dequeue elemen (FIFO)
    cout << "\n2. Dequeue 1 (Harusnya 100): " << myQueue.dequeue() << endl; // Dequeue 100
    cout << "3. Dequeue 2 (Harusnya 200): " << myQueue.dequeue() << endl; // Dequeue 200

    cout << "\n4. Size setelah Dequeue: " << myQueue.get_size() << endl; // Size harus 1
    cout << "5. Peek (Harusnya 300): " << myQueue.peek() << endl;

    myQueue.dequeue(); // Dequeue 300
    cout << "6. Is Empty? " << (myQueue.isEmpty() ? "YA" : "TIDAK") << endl;

    // Uji Kasus Tepi: Dequeue pada Queue Kosong (Harusnya exception/error)
    try {
        cout << "\n7. Uji Kasus Tepi: Dequeue pada Queue kosong. ";
        myQueue.dequeue();
    } catch (const out_of_range& e) {
        cout << "Berhasil ditangani (Exception)." << endl;
    }


    return 0;
}
