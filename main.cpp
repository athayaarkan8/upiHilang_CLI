using namespace std;
#include <iostream>

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