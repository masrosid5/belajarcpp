#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr){}
};

class MyCircularLinkedList{
    Node* tail;
    int count;
public:
    MyCircularLinkedList(){
        tail = nullptr;
        count = 0;
    }
    ~MyCircularLinkedList(){
        if (tail == nullptr) return;
        Node* current = tail->next;
        while (current!= tail){
            Node* nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;

        }
        delete tail;
        tail = nullptr;
    }
    void insertAtBegin(int x){
        Node* newNode = new Node(x);
        if (tail == nullptr){
            tail = newNode;
            tail->next = tail;
            count++;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        count++;
    }
    void insertAtEnd(int x){
        Node* newNode = new Node(x);
        if (tail == nullptr){
            tail = newNode;
            tail->next = tail;
            count++;
            return;
        }
        else {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
            count++;
        }
    }
    int deleteAtBegin(){
        if (tail == nullptr) throw out_of_range("List Kosong");
        if (tail->next == tail){
            Node* nodeToDelete = tail;
            int value = tail->data;
            tail = nullptr;
            delete nodeToDelete;
            count--;
            return value;
        }
        else {
            Node* nodeToDelete = tail->next;
            int value = tail->next->data;
            tail->next = tail->next->next;
            delete nodeToDelete;
            count--;
            return value;
        }
    }
    int deleteAtEnd(){
        if (tail == nullptr) throw out_of_range("List Kosong");
        if (tail->next == tail){
            Node* nodeToDelete = tail;
            int value = tail->data;
            tail = nullptr;
            delete nodeToDelete;
            count--;
            return value;
        }
        else {
            Node* nodeToDelete;
            Node* current;
            current = tail;
            do {
                current = current->next;
            } while (current->next != tail);
            nodeToDelete = current->next;
            int value = nodeToDelete->data;
            current->next = current->next->next;
            tail = current;
            delete nodeToDelete;
            count--;
            return value;
        }
    }

    void printList(){
        if (tail == nullptr) {
            cout << "List kosong" << endl;
            return;
        }
        Node* head = tail->next;
        Node* current = tail->next;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current!=head);
        cout << endl;
    }
    bool isEmpty(){
        return tail == nullptr;
    }
    int getSize(){
        return count;
    }
};
// --- MAIN FUNCTION UNTUK PENGUJIAN ---
int main() {

    cout << "=========================================" << endl;
    cout << "UJI KASUS CIRCULAR LINKED LIST (CLL)" << endl;
    cout << "=========================================" << endl;

    MyCircularLinkedList cll;

    // ===================================
    // UJI 1: INSERT O(1)
    // ===================================
    cout << "1. UJI INSERT O(1)" << endl;

    // Insert Node Pertama
    cll.insertAtBegin(100); // List: [100]
    cout << "   - Insert 100 (Begin): Tail=" << cll.getSize() << endl; // Size=1

    // InsertAtEnd
    cll.insertAtEnd(300); // List: [100 -> 300] (Tail=300)
    cout << "   - Insert 300 (End): " << endl;

    // InsertAtBegin (sekarang Tail menunjuk ke 100, jadi 100 bukan Head lagi)
    cll.insertAtBegin(50); // List: [50 -> 100 -> 300] (Tail=300)
    cout << "   - Insert 50 (Begin): " << endl;

    // InsertAtEnd
    cll.insertAtEnd(500); // List: [50 -> 100 -> 300 -> 500] (Tail=500)
    cout << "   - Insert 500 (End): " << endl;

    cout << "   List Akhir (Harusnya [50 -> 100 -> 300 -> 500]):" << endl;
    cll.printList(); // Tail harus 500
    cout << "   Size: " << cll.getSize() << endl; // Harusnya 4

    // ===================================
    // UJI 2: DELETE O(1) (Menghapus Head)
    // ===================================
    cout << "\n2. UJI DELETE AT BEGIN (O(1))" << endl;

    // Hapus Head (50)
    cout << "   - Delete Head (Harusnya 50): " << cll.deleteAtBegin() << endl; // List: [100 -> 300 -> 500]

    // Hapus Head (100)
    cout << "   - Delete Head (Harusnya 100): " << cll.deleteAtBegin() << endl; // List: [300 -> 500]

    cout << "   List Setelah 2 Delete Begin (Harusnya [300 -> 500]):" << endl;
    cll.printList();
    cout << "   Size: " << cll.getSize() << endl; // Harusnya 2

    // ===================================
    // UJI 3: DELETE AT END (O(n))
    // ===================================
    cout << "\n3. UJI DELETE AT END (O(n))" << endl;

    // Hapus Tail (500)
    cout << "   - Delete Tail (Harusnya 500): " << cll.deleteAtEnd() << endl; // List: [300] (Tail=300)

    cout << "   List Setelah Delete End (Harusnya [300]):" << endl;
    cll.printList();
    cout << "   Size: " << cll.getSize() << endl; // Harusnya 1

    // ===================================
    // UJI 4: KASUS TEPI (Menghapus node terakhir)
    // ===================================
    cout << "\n4. UJI KASUS TEPI (Hapus Node Terakhir)" << endl;

    // Hapus Node Terakhir (300)
    cout << "   - Delete Head (Harusnya 300): " << cll.deleteAtBegin() << endl; // List: Kosong

    cout << "   List Akhir:" << endl;
    cll.printList();
     // Harusnya List kosong.

    // Uji Kasus Tepi: Delete pada List Kosong
    try {

        cll.deleteAtBegin();
    } catch (const out_of_range& e) {
        cout << "   - Kasus Tepi: Delete List Kosong berhasil ditangani." << endl;
    }


    return 0;
}
