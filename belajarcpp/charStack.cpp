#include <iostream>
#include <string>
#include <stdexcept> // standard untuk except Stack underflow

using namespace std;

struct Node {
    // asumsikan stack untuk data bilangan positif
    char data;
    Node* next;
    Node(char x) : data(x), next(nullptr){};
};

class MyStack {
    Node* top;
    int counter;

public:
    MyStack(){
        top = nullptr;
        counter = 0;
    }
    MyStack(char x){
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
    void push(char value){
        Node* newNode = new Node(value);
        if (top == nullptr){
            top = newNode;
        } else {
        newNode->next = top;
        top = newNode;
        }
        counter += 1;
    }
    char pop(){
        if (isEmpty()) {
            throw out_of_range("Stack underflow. Tidak ada item.");
        } else {
            Node* nodeToDelete = top;
            char value = top->data;
            top = nodeToDelete->next;
            delete nodeToDelete;
            //cout << value << " berhasil dihapus.\n";
            counter -= 1;
            return value;
        }


    }
    char peek(){
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
bool cocok(char kurung1, char kurung2){
    if (kurung1 == '{' && kurung2 == '}') return true;
    else if (kurung1 == '(' && kurung2 == ')') return true;
    else if (kurung1 == '[' && kurung2 == ']') return true;
    else return false;
}
bool isBalanced(const string &expression){
    MyStack st;

    for (char c : expression){
        if (c == '{' || c == '(' || c == '[') st.push(c);
        if (c == '}' || c == ')' || c == ']') {
            if (st.isEmpty()) return false;
            char pasangan = st.pop();
            if (!cocok(pasangan,c)){
                return false;
            }
        }
    }
    return st.isEmpty();
};

int main(){
    // ------------------------------------
    // UJI 4: KESEIMBANGAN TANDA KURUNG
    // ------------------------------------
    cout << "\n--- UJI 4: KESEIMBANGAN TANDA KURUNG ---" << endl;

    string expression1 = "{[()]}"; // TRUE
    string expression2 = "{[)]}"; // FALSE (Urutan salah)
    string expression3 = "((()))"; // TRUE
    string expression4 = "({)}"; // FALSE (Urutan salah)
    string expression5 = "([)]"; // FALSE
    string expression6 = "([{}])"; // TRUE
    string expression7 = "{[}"; // FALSE (Tidak ditutup)

    cout << "1. " << expression1 << ": " << (isBalanced(expression1) ? "BENAR" : "SALAH") << endl;
    cout << "2. " << expression2 << ": " << (isBalanced(expression2) ? "BENAR" : "SALAH") << endl;
    cout << "3. " << expression3 << ": " << (isBalanced(expression3) ? "BENAR" : "SALAH") << endl;
    cout << "4. " << expression4 << ": " << (isBalanced(expression4) ? "BENAR" : "SALAH") << endl;
    cout << "5. " << expression5 << ": " << (isBalanced(expression5) ? "BENAR" : "SALAH") << endl;
    cout << "6. " << expression6 << ": " << (isBalanced(expression6) ? "BENAR" : "SALAH") << endl;
    cout << "7. " << expression7 << ": " << (isBalanced(expression7) ? "BENAR" : "SALAH") << endl;

    return 0;
}



