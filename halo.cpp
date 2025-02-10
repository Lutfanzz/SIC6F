#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Memulai seed untuk fungsi random
    int angkaRahasia = rand() % 100 + 1; // Membuat angka acak antara 1-100
    int tebakan;
    int kesempatan = 0;
    bool menang = false;

    cout << "Selamat datang di Permainan Tebak Angka!" << endl;
    cout << "Saya telah memilih sebuah angka antara 1 dan 100." << endl;
    cout << "Anda memiliki 10 kesempatan untuk menebaknya." << endl;

    while (kesempatan < 10) {
        cout << "\nMasukkan tebakan Anda: ";
        cin >> tebakan;
        kesempatan++;

        if (tebakan == angkaRahasia) {
            menang = true;
            break;
        } else if (tebakan < angkaRahasia) {
            cout << "Tebakan Anda terlalu kecil! Coba yang lebih besar.";
        } else {
            cout << "Tebakan Anda terlalu besar! Coba yang lebih kecil.";
        }

        cout << "\nKesempatan yang tersisa: " << 10 - kesempatan;
    }

    if (menang) {
        cout << "\nSelamat! Anda berhasil menebak angka yang benar: " << angkaRahasia;
    } else {
        cout << "\nSayang sekali, kesempatan Anda habis.";
        cout << "\nAngka yang benar adalah: " << angkaRahasia;
    }

    cout << "\n\nTerima kasih telah bermain!";

    return 0;
}
