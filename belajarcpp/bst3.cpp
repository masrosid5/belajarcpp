#include <iostream>
#include <limits> // Digunakan untuk std::numeric_limits
#include <stdexcept>
#include <string>

using namespace std;

// --- STRUKTUR NODE BST ---
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// --- KELAS BINARY SEARCH TREE ---
class MyBST {
private:
    Node* root;

    // FUNGSI DASAR INSERT (Implementasi Anda)
    Node* insertRecursive(Node* current, int value) {
        if (current == nullptr) return new Node(value);
        if (value <= current->data) {
            current->left = insertRecursive(current->left, value);
        } else {
            current->right = insertRecursive(current->right, value);
        }
        return current;
    }

    // FUNGSI UTAMA UNTUK TANTANGAN 1: Validasi BST
    // Batasan: [min, max]
    bool isValidBSTRecursive(Node* current, long minVal, long maxVal) const {
        // KASUS DASAR 1: Simpul kosong selalu valid
        if (current == nullptr) {
            return true;
        }

        // KASUS DASAR 2: Pelanggaran aturan
        if (current->data <= minVal || current->data >= maxVal) {
            return false;
        }

        // TULIS LOGIKA REKURSIF ANDA DI SINI
        // Panggil fungsi secara rekursif untuk anak kiri dan kanan,
        // dengan mempersempit batasan [minVal, maxVal]
        bool isValidLeft = isValidBSTRecursive(current->left, minVal, current->data);
        bool isValidRight = isValidBSTRecursive(current->right, current->data, maxVal);
        bool result = (isValidLeft && isValidRight);

        // Logika rekursif harus mengembalikan BENAR jika kedua subpohon valid
        return result;
    }

    // FUNGSI UTAMA UNTUK TANTANGAN 2: Terkecil Kedua (Menggunakan In-Order Traversal)
    void findKthSmallestRecursive(Node* current, int& count, int k, int& result) const {
        if (current == nullptr || count >= k) return;

        // 1. Kunjungi Kiri (Langkah In-Order)
        findKthSmallestRecursive(current->left, count, k, result);

        // 2. Kunjungi Root (Hitung)
        count++; // Tingkatkan hitungan setelah mengunjungi node
        if (count == k) {
            result = current->data;
            return; // Hentikan rekursi
        }

        // 3. Kunjungi Kanan
        findKthSmallestRecursive(current->right, count, k, result);
    }

    // Destructor helper
    void destroyRecursive(Node* node) {
        if (node != nullptr) {
            destroyRecursive(node->left);
            destroyRecursive(node->right);
            delete node;
        }
    }

public:
    MyBST() : root(nullptr) {}
    ~MyBST() { destroyRecursive(root); }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    // Wrapper untuk Tantangan 1: Validasi BST
    bool isValidBST() const {
        // Mulai dengan batasan terendah dan tertinggi yang mungkin
        return isValidBSTRecursive(root, std::numeric_limits<long>::min(), std::numeric_limits<long>::max());
    }

    // Wrapper untuk Tantangan 2: Terkecil Kedua (k=2)
    int findSecondSmallest() const {
        int count = 0;
        int result = -1; // -1 jika tidak ditemukan
        findKthSmallestRecursive(root, count, 2, result); // Kita mencari elemen ke-2 (k=2)
        if (result == -1) throw out_of_range("Pohon terlalu kecil atau kosong.");
        return result;
    }

    // Fungsi tambahan untuk menguji pohon yang tidak valid (untuk Tantangan 1)
    void setRootForInvalidTest(Node* invalidRoot) {
        this->root = invalidRoot;
    }
};

// --- MAIN FUNCTION UNTUK PENGUJIAN ---
int main() {

    cout << "=========================================" << endl;
    cout << "UJI KASUS LANJUTAN BST" << endl;
    cout << "=========================================" << endl;

    // ===================================
    // TANTANGAN 1: VALIDASI BST
    // ===================================
    MyBST bst_valid;
    bst_valid.insert(50);
    bst_valid.insert(30);
    bst_valid.insert(70);
    bst_valid.insert(40);
    bst_valid.insert(60);

    cout << "\n1. UJI VALIDASI BST" << endl;
    cout << "   - BST Standard (Harusnya BENAR): " << (bst_valid.isValidBST() ? "BENAR" : "SALAH") << endl;

    // Uji BST TIDAK VALID (Harus dibuat secara manual)
    // Node 55 dimasukkan di kanan 50, tapi di kiri 70.
    // Jika 55 memiliki anak 40 (melanggar aturan BST root 50)
    Node* invalid_root = new Node(50);
    invalid_root->left = new Node(30);
    invalid_root->right = new Node(70);
    invalid_root->right->left = new Node(20); // Nilai 20 berada di subpohon kanan 50. SALAH.

    MyBST bst_invalid;
    bst_invalid.setRootForInvalidTest(invalid_root);
    cout << "   - BST Invalid (Harusnya SALAH): " << (bst_invalid.isValidBST() ? "BENAR" : "SALAH") << endl;

    // ===================================
    // TANTANGAN 2: TERKECIL KEDUA
    // ===================================
    MyBST bst_second;
    bst_second.insert(50);
    bst_second.insert(30);
    bst_second.insert(70);
    bst_second.insert(20);
    bst_second.insert(40);
    bst_second.insert(60);
    bst_second.insert(80);
    // Urutan In-Order: 20, 30, 40, 50, 60, 70, 80

    cout << "\n2. UJI TERKECIL KEDUA" << endl;
    // Elemen terkecil pertama adalah 20. Elemen terkecil kedua adalah 30.
    cout << "   - Elemen Terkecil Kedua (Harusnya 30): " << bst_second.findSecondSmallest() << endl;


    return 0;
}
