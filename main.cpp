using namespace std;
#include <iostream>

struct Barang {
    int id;
    string nama;
    string deskripsi;
    string lokasi;
    string kontak;
};

struct Node {
    Barang data;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;
int counter = 1;

void tambahBarang() {
    Node* baru = new Node;

    baru->data.id = counter++;

    cout << "Nama barang: ";
    cin.ignore();
    getline(cin, baru->data.nama);

    cout << "Deskripsi: ";
    getline(cin, baru->data.deskripsi);

    cout << "Lokasi hilang: ";
    getline(cin, baru->data.lokasi);

    cout << "Kontak: ";
    getline(cin, baru->data.kontak);

    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }

    cout << "Data berhasil ditambahkan!\n";
}

void menu() {
    int pilihan;

    do {
        cout << "\n=== UPIHilang ===\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Tampilkan Barang\n";
        cout << "3. Update Barang\n";
        cout << "4. Hapus Barang\n";
        cout << "5. Cari Barang\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}

void hapusBarang() {
    int id;
    cout << "Masukkan ID yang ingin dihapus: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->data.id == id) {
            if (temp == head && temp == tail) {
                head = tail = NULL;
            }

            else if (temp == head) {
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
            }

            else if (temp == tail) {
                tail = tail->prev;
                if (tail != NULL) {
                    tail->next = NULL;
                }
            }

            else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            cout << "Data berhasil dihapus!\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Data tidak ditemukan.\n";
}