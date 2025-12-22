#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

class MyBST {
    Node* root;


    Node* insertRecursive(Node* root, int value){
        if (root == nullptr){
            return new Node(value);
        }
        if (value <= root->data){
            root->left = insertRecursive(root->left, value);
        } else {
            root->right = insertRecursive(root->right, value);
        }
        return root;
    }

    bool searchRecursive(Node* root, int value) const {
        if (root == nullptr) return false;
        if (value == root->data) return true;
        else if (value < root->data) {
            return searchRecursive(root->left, value);
        }
        else return searchRecursive(root->right, value);

    }

    void destroyRecursive(Node* root){
        if (root != nullptr){
            destroyRecursive(root->left);
            destroyRecursive(root->right);
            delete root;
        }
    }

    void inOrderRecursive(Node* root) const {
        if (root == nullptr) return;
        inOrderRecursive(root->left);
        cout << root->data << " ";
        inOrderRecursive(root->right);
    }

    void preOrderRecursive(Node* root) const{
        if (root == nullptr) return;
        cout << root->data << " ";
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
    void postOrderRecursive(Node* root) const{
        if (root == nullptr) return;

        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        cout << root->data << " ";
    }

    Node* findMaxNode(Node* node) const {
        while (node->right != nullptr) node = node->right;
        return node;
    }

    Node* deleteRecursive(Node* current, int value){
        // Kasus dasar: jika node tidak ditemukan.
        if (current == nullptr) return current;

        if (value < current->data){
            current->left = deleteRecursive(current->left, value);
            return current;
        }
        else if (value > current->data){
            current->right = deleteRecursive(current->right, value);
            return current;
        }
        else {
            // jika ketemu
            // Kasus 1: jika yang mau dihapus adalah sebuah leaf atau punya 1 anak
            if (current->left == nullptr) {
                // kembalikan yang right-child
                Node* temp = current->right;
                delete current;
                return temp;
            }
            else if (current->right == nullptr){
                // kembalikan yang left-child
                Node* temp = current->left;
                delete current;
                return temp;
            }
            // kasus 3: jika mempunyai dua child
            Node* successor = findMaxNode(current->left);
            current->data = successor->data;
            current->left = deleteRecursive(current->left, successor->data);
            return current;
        }
    }

public:
    MyBST() : root(nullptr){

    }
    ~MyBST(){
        destroyRecursive(root);
    }
    bool search(int x){
        return searchRecursive(root, x);
    }
    void insert(int x){
        root = insertRecursive(root, x);
    }

    void deleteNode(int x){
        root = deleteRecursive(root, x);
    }

    void displayInOrder(){
        inOrderRecursive(root);
        cout << endl;
    }
    void displayPreOrder(){
        preOrderRecursive(root);
        cout << endl;
    }
    void displayPostOrder(){
        postOrderRecursive(root);
        cout << endl;
    }

};

// --- MAIN FUNCTION UNTUK PENGUJIAN ---
int main() {

    cout << "=========================================" << endl;
    cout << "UJI KASUS BST DELETION (REKURSIF)" << endl;
    cout << "=========================================" << endl;

    MyBST bst;

    // Pohon awal: 50(R), 30(L), 70(R), 20(LL), 40(LR), 60(RL), 80(RR)
    bst.insert(50); // Root
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // FUNGSI BANTUAN TRAVERSAL (Tambahkan di sini untuk pengujian)
    // Tulis fungsi printInOrder di sini jika Anda ingin melihat hasil BST setelah penghapusan

    bst.displayInOrder();
    // --- UJI KASUS 1: HAPUS LEAF (KASUS PALING MUDAH) ---
    cout << "\n1. Hapus Leaf (20):" << endl;
    bst.deleteNode(20);
    bst.displayInOrder();
    // Harapan: 20 hilang. Struktur masih bagus.

    // --- UJI KASUS 2: HAPUS SATU ANAK (KASUS 60) ---
    // Node 70 punya anak 60 dan 80. Node 60 hanya punya satu anak atau tidak punya anak

    // Hapus Node 60 (Leaf di subpohon kanan 70)
    bst.deleteNode(60);
    bst.displayInOrder();
    // Harapan: 60 hilang. 70 kini hanya punya 80 di kanan.

    // --- UJI KASUS 3: HAPUS DUA ANAK (KASUS 30) ---
    // 30 punya anak 20(Kiri - sudah dihapus) dan 40(Kanan).
    // Node 30 punya 40 saja. Hapus 30
    cout << "\n2. Hapus Node dengan Satu Anak (30):" << endl;
    bst.deleteNode(30);
    bst.displayInOrder();
    // Harapan: 30 digantikan 40. Struktur: 50 -> 40 (Kiri) -> 70 (Kanan) -> 80 (70 Kanan)

    // --- UJI KASUS 4: HAPUS ROOT (KASUS PALING SULIT, 50) ---
    cout << "\n3. Hapus Root (50):" << endl;
    bst.deleteNode(50);
    bst.displayInOrder();
    // Harapan: 50 digantikan In-Order Successor (70 atau 60 jika masih ada)
    // Di sini 50 digantikan 70.

    // (Anda harus menggunakan fungsi traversal Anda di sini untuk memverifikasi)

    return 0;
}
