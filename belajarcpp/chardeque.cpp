#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>

using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
    Node(char x) : data(x), prev(nullptr), next(nullptr) {}
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

    void insertFront(char x){
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
    void insertBack(char x){
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
    char deleteFront(){
        Node* nodeToDelete;
        char value;
        if (head == nullptr){
            throw out_of_range("Deque kosong.\n");
        }
        if (head == tail){
            nodeToDelete = head;
            value = nodeToDelete->data;
            head = nullptr;
            tail = nullptr;
            delete nodeToDelete;
            counter -= 1;
            return value;
        }
        else {
            nodeToDelete = head;
            value = nodeToDelete->data;
            head->next->prev = nullptr;
            head = head->next;
            delete nodeToDelete;
            counter -= 1;
            return value;
        }

    }
    char deleteBack(){
        Node* nodeToDelete;
        char value;
        if (tail == nullptr){
            throw out_of_range("Deque kosong.\n");
        }
        if (head == tail){
            nodeToDelete = tail;
            value = nodeToDelete->data;
            head = nullptr;
            tail = nullptr;
            delete nodeToDelete;
            counter -= 1;
            return value;
        }
        else {
            nodeToDelete = tail;
            value = nodeToDelete->data;
            tail->prev->next = nullptr;
            tail = tail->prev;
            delete nodeToDelete;
            counter -= 1;
            return value;
        }

    }
    char getFront() const {
        if (head == nullptr){
            throw out_of_range("Deque kosong.\n");
        }
        return head->data;

    }
    char getBack() const {
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

bool isPalindrome(string teks){
    MyDeque dq;

    for (char c: teks){
        if (isalnum(c)){
            dq.insertBack(tolower(c));
        }

    }
    char c1;
    char c2;
    int n = dq.getSize();
    for (int i = 0; i < n/2;i++){
        c1 = dq.deleteFront();
        c2 = dq.deleteBack();
        if (c1 != c2 ) return false;
    }

    return true;
}

// --- MAIN FUNCTION UNTUK PENGUJIAN ---
int main() {

    cout << "=================================================" << endl;
    cout << "UJI KASUS DEQUE: PALINDROME CHECKER (O(n))" << endl;
    cout << "=================================================" << endl;

    // --- UJI KASUS UTAMA ---
    string kata1 = "level";
    string kata2 = "katak";
    string kata3 = "a";
    string kata4 = "hello";
    string kata5 = "madam";

    // Uji Kasus Frasa (Menguji logika alfanumerik)
    string frasa1 = "kasur rusak";
    string frasa2 = "A man, a plan, a canal: Panama"; // Palindrom Terkenal

    cout << "1. '" << kata1 << "': " << (isPalindrome(kata1) ? "PALINDROM" : "BUKAN") << endl;
    cout << "2. '" << kata2 << "': " << (isPalindrome(kata2) ? "PALINDROM" : "BUKAN") << endl;
    cout << "3. '" << kata3 << "': " << (isPalindrome(kata3) ? "PALINDROM" : "BUKAN") << endl;
    cout << "4. '" << kata4 << "': " << (isPalindrome(kata4) ? "PALINDROM" : "BUKAN") << endl;
    cout << "5. '" << kata5 << "': " << (isPalindrome(kata5) ? "PALINDROM" : "BUKAN") << endl;
    cout << "6. '" << frasa1 << "': " << (isPalindrome(frasa1) ? "PALINDROM" : "BUKAN") << endl;
    cout << "7. '" << frasa2 << "': " << (isPalindrome(frasa2) ? "PALINDROM" : "BUKAN") << endl;
    cout << "8. isPalindrome(\"\"): " << (isPalindrome("") ? "PALINDROM" : "BUKAN") << endl; // TRUE (Kasus Kosong)

    return 0;
}
