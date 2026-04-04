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
