using namespace std;
#include <iostream>

struct Barang
{
    int id;
    string nama;
    string deskripsi;
    string lokasi;
    string kontak;
};

struct Node
{
    Barang data;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;
int counter = 1;

int panjangLine = 30;

void header(string title = "")
{
    cout << "\n"
         << string(panjangLine, '=') << " " << title << " " << string(panjangLine, '=') << "\n";
}

void footer(int panjangTitle = 0)
{
    cout << string(panjangLine, '=') << string(panjangTitle + 2, '=') << string(panjangLine, '=') << "\n";
}

void infoCard(string title, string isi)
{
    header(title);
    cout << isi << endl;
    footer(title.length());
}

void tambahBarang()
{
    Node *baru = new Node;

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

    if (head == NULL)
    {
        head = tail = baru;
    }
    else
    {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }

    cout << "Data berhasil ditambahkan!\n";
}

void tampilkanBarang()
{
    Node *temp = head;

    if (temp == NULL)
    {
        cout << "Belum ada data.\n";
        return;
    }

    while (temp != NULL)
    {
        cout << "ID: " << temp->data.id << " Nama: " << temp->data.nama << " Desc: " << temp->data.deskripsi.substr(0, 8) << endl;

        temp = temp->next;
    }
}

void updateBarang(int id = 0)
{
    if (head == NULL)
    {
        cout << "Data kosong!\n";
        return;
    }

    Node *temp = head;
    bool ketemu = false;

    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            ketemu = true;

            cin.ignore();
            cout << "Nama baru: ";
            getline(cin, temp->data.nama);

            cout << "Deskripsi baru: ";
            getline(cin, temp->data.deskripsi);

            cout << "Lokasi baru: ";
            getline(cin, temp->data.lokasi);

            cout << "Kontak baru: ";
            getline(cin, temp->data.kontak);

            infoCard("Sukses", "Data berhasil diupdate!");
            break;
        }
        temp = temp->next;
    }

    if (!ketemu)
    {
        infoCard("Error", "ID tidak ditemukan!");
    }
}

void hapusBarang(int id = 0)
{
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            if (temp == head && temp == tail)
            {
                head = tail = NULL;
            }

            else if (temp == head)
            {
                head = head->next;
                if (head != NULL)
                {
                    head->prev = NULL;
                }
            }

            else if (temp == tail)
            {
                tail = tail->prev;
                if (tail != NULL)
                {
                    tail->next = NULL;
                }
            }

            else
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }

            delete temp;
            infoCard("Sukses", "Data berhasil dihapus!");
            return;
        }
        temp = temp->next;
    }

    infoCard("Error", "Data tidak ditemukan!");
}

void cariBarang()
{
    string keyword;
    cout << "Masukkan nama barang: ";
    cin.ignore();
    getline(cin, keyword);

    Node *temp = head;
    bool ditemukan = false;

    while (temp != NULL)
    {
        if (temp->data.nama.find(keyword) != string::npos)
        {
            header("Hasil Pencarian");
            cout << "ID: " << temp->data.id << endl;
            cout << "Nama: " << temp->data.nama << endl;
            cout << "Lokasi: " << temp->data.lokasi << endl;
            cout << "Kontak: " << temp->data.kontak << endl;
            footer(15);
            ditemukan = true;
        }
        temp = temp->next;
    }

    if (!ditemukan)
    {
        infoCard("Error", "Barang tidak ditemukan!");
    }
}

void detailBarang(int id = 0)
{

    Node *temp = head;
    char pilihan;

    header("Detail Barang");
    while (temp != NULL)
    {
        if (temp->data.id == id)
        {
            cout << "ID: " << temp->data.id << endl;
            cout << "Nama: " << temp->data.nama << endl;
            cout << "Deskripsi: " << temp->data.deskripsi << endl;
            cout << "Lokasi: " << temp->data.lokasi << endl;
            cout << "Kontak: " << temp->data.kontak << endl;
            footer(13);
            cout << "[A] Hapus Barang [B] Update Barang [X] Kembali\n";
            cout << "Pilih aksi: ";
            cin >> pilihan;

            pilihan = tolower(pilihan);
            if (pilihan == 'b')
            {
                updateBarang(id);
            }
            else if (pilihan == 'a')
            {
                hapusBarang(id);
            }
            else if (pilihan == 'x')
            {
                return;
            }
            else
            {
                infoCard("Error", "Pilihan [" + string(1, pilihan) + "] tidak valid. Silakan coba lagi.");
            }
        }
        else
        {
            infoCard("Error", "Data tidak ditemukan.");
        }
        temp = temp->next;
    }
}

void menu()
{
    char pilihan;
    string title = "UPIHilang";
    int panjangTitle = title.length();

    do
    {
        header(title);
        cout << "Selamat datang di aplikasi UPIHilang!\nDimana informasi barang hilang dapat ditemukan.\n\n";
        tampilkanBarang();
        footer(panjangTitle);
        cout << "[X] Tambah Barang [Y] Cari Barang [Z] Keluar\n";
        footer(panjangTitle);
        cout << "Masukan Nomor ID untuk Detail Barang atau Pilih Aksi: ";
        cin >> pilihan;

        pilihan = tolower(pilihan);
        if (pilihan == 'x')
        {
            tambahBarang();
        }
        else if (pilihan == 'y')
        {
            cariBarang();
        }
        else if (pilihan == 'z')
        {
            cout << "Terima kasih telah menggunakan aplikasi UPIHilang!\n";
        }
        else if (isdigit(pilihan))
        {
            int id = pilihan - '0';
            detailBarang(id);
        }
        else
        {
            infoCard("Error", "Pilihan [" + string(1, pilihan) + "] tidak valid. Silakan coba lagi.");
        }

    } while (pilihan != 'z');
}

int main()
{
    menu();
    return 0;
}