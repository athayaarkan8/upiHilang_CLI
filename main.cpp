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

// ====== BAGIAN KAMU (ADEL) ======
void updateBarang() {
    if (head == NULL) {
        cout << "Data kosong!\n";
        return;
    }

    int idCari;
    cout << "Masukkan ID barang yang ingin diupdate: ";
    cin >> idCari;

    Node* temp = head;
    bool ketemu = false;

    while (temp != NULL) {
        if (temp->data.id == idCari) {
            ketemu = true;

            cout << "Data ditemukan!\n";

            cin.ignore();
            cout << "Nama baru: ";
            getline(cin, temp->data.nama);

            cout << "Deskripsi baru: ";
            getline(cin, temp->data.deskripsi);

            cout << "Lokasi baru: ";
            getline(cin, temp->data.lokasi);

            cout << "Kontak baru: ";
            getline(cin, temp->data.kontak);

            cout << "Data berhasil diupdate!\n";
            break;
        }
        temp = temp->next;
    }

    if (!ketemu) {
        cout << "ID tidak ditemukan!\n";
    }
}
// ====== END BAGIAN KAMU ======

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

        // TAMBAHAN KAMU (TIDAK MENGUBAH YANG LAIN)
        if (pilihan == 1) {
            tambahBarang();
        }
        else if (pilihan == 3) {
            updateBarang();
        }

    } while (pilihan != 0);
}

int main() {
    menu();
    return 0;
}