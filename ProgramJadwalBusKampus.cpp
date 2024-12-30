#include <iostream>
#include <string>
using namespace std;

struct Bus { int number; string driver, destination; int capacity; };

void addBus(Bus b[], int &c, int m) {
    if (c >= m) { cout << "\nPenuh!\n"; return; }
    cout << "\nNomor: "; cin >> b[c].number; cin.ignore();
    cout << "Sopir: "; getline(cin, b[c].driver);
    cout << "Tujuan: "; getline(cin, b[c].destination);
    cout << "Kapasitas: "; cin >> b[c++].capacity;
}

void displayBuses(const Bus b[], int c) {
    if (!c) { cout << "\nTidak ada bus.\n"; return; }
    for (int i = 0; i < c; i++)
        cout << "\nBus " << i + 1 << ": Nomor " << b[i].number << ", Sopir " << b[i].driver 
             << ", Tujuan " << b[i].destination << ", Kapasitas " << b[i].capacity << "\n";
}

void searchBus(const Bus b[], int c) {
    int n; cout << "\nCari nomor: "; cin >> n;
    for (int i = 0; i < c; i++)
        if (b[i].number == n) {
            cout << "\nNomor: " << b[i].number << ", Sopir: " << b[i].driver
                 << ", Tujuan: " << b[i].destination << ", Kapasitas: " << b[i].capacity << "\n";
            return;
        }
    cout << "\nBus tidak ditemukan.\n";
}

int main() {
    Bus b[100]; int c = 0, o;
    while (1) {
        cout << "\n1.Tambah\n2.Tampilkan\n3.Cari\n4.Keluar\nPilih: "; cin >> o;
        if (o == 1) addBus(b, c, 100);
        else if (o == 2) displayBuses(b, c);
        else if (o == 3) searchBus(b, c);
        else if (o == 4) break;
        else cout << "\nSalah!\n";
    }
    return 0;
}
