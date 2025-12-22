#include <iostream>
#include <stdexcept> // standard untuk except Stack underflow

using namespace std;

struct Node {
    // asumsikan stack untuk data bilangan positif
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr){};
};

class MyStack {
    Node* top;
    int counter;

public:
    MyStack(){
        top = nullptr;
        counter = 0;
    }
    MyStack(int x){
        top = new Node(x);
        counter +=1;
    }
    ~MyStack() {
        Node* current = top;

        while (current != nullptr){
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    void push(int value){
        Node* newNode = new Node(value);
        if (top == nullptr){
            top = newNode;
        } else {
        newNode->next = top;
        top = newNode;
        }
        counter += 1;
    }
    int pop(){
        int value;
        if (isEmpty()) {
            throw out_of_range("Stack underflow. Tidak ada item.");
        } else {
            Node* nodeToDelete = top;
            int value = top->data;
            top = nodeToDelete->next;
            delete nodeToDelete;
            //cout << value << " berhasil dihapus.\n";
            counter -= 1;
            return value;
        }


    }
    int peek(){
        int value;
        if (isEmpty()){
            throw out_of_range("Stack underflow");
        }
        return top->data;
    }
    bool isEmpty(){
        return top == nullptr;
    }
    int get_size(){
        return counter;
    }
};

int main(){
   MyStack st;
    cout << "==========================================" << endl;
    cout << "            UJI KASUS STACK SLL           " << endl;
    cout << "==========================================" << endl;

    // ------------------------------------
    // UJI 1: PUSH DAN UKURAN
    // ------------------------------------
    cout << "--- UJI 1: PUSH & SIZE ---" << endl;
    cout << "Ukuran stack awal: " << st.get_size() << endl; // 0
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes.\n" : "No.\n");
    cout << "Ukuran stack setelah 3 push: " << st.get_size() << endl; // Harusnya 3
    cout << "Mengintip top: " << st.peek() << endl; // Harusnya 3

    // ------------------------------------
    // UJI 2: POP (LIFO)
    // ------------------------------------
    cout << "\n--- UJI 2: POP (LIFO) ---" << endl;
    cout << "Pop 1 (Harusnya 3): " << st.pop() << endl;
    cout << "Pop 2 (Harusnya 2): " << st.pop() << endl;
    cout << "Ukuran stack: " << st.get_size() << endl; // Harusnya 1

    // ------------------------------------
    // UJI 3: KASUS TEPI
    // ------------------------------------
    cout << "\n--- UJI 3: KASUS TEPI ---" << endl;
    st.pop(); // Pop 1
    cout << "Ukuran stack setelah pop terakhir: " << st.get_size() << endl; // Harusnya 0
    cout << "Is stack empty? " << (st.isEmpty() ? "Yes.\n" : "No.\n");

    // Uji Pop pada Stack Kosong (Harusnya exception)
    try {
        st.pop();
    } catch (const out_of_range& e) {
        cout << "Berhasil ditangani: " << e.what() << endl;
    }

    return 0;
}



