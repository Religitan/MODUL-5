#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

struct Mahasiswa {
  string nim;
  int nilai;
};


void addMahasiswa(unordered_map<string, Mahasiswa>& dataMahasiswa) {
  string nim, nilaiStr;
  cout << "Masukkan NIM: ";
  cin >> nim;
  cout << "Masukkan nilai: ";
  cin >> nilaiStr;

  int nilai = stoi(nilaiStr);


  if (dataMahasiswa.find(nim) != dataMahasiswa.end()) {
    cout << "NIM sudah ada. Silakan masukkan NIM lain." << endl;
    return;
  }


  dataMahasiswa[nim] = {nim, nilai};
  cout << "Data mahasiswa berhasil ditambahkan." << endl;
}


void deleteMahasiswa(unordered_map<string, Mahasiswa>& dataMahasiswa) {
  string nim;
  cout << "Masukkan NIM: ";
  cin >> nim;

  if (dataMahasiswa.find(nim) == dataMahasiswa.end()) {
    cout << "NIM tidak ditemukan." << endl;
    return;
  }


  dataMahasiswa.erase(nim);
  cout << "Data mahasiswa dengan NIM " << nim << " berhasil dihapus." << endl;
}


void findMahasiswaByNIM(const unordered_map<string, Mahasiswa>& dataMahasiswa) {
  string nim;
  cout << "Masukkan NIM: ";
  cin >> nim;

 
  if (dataMahasiswa.find(nim) == dataMahasiswa.end()) {
    cout << "NIM tidak ditemukan." << endl;
    return;
  }

  
  const Mahasiswa& mahasiswa = dataMahasiswa.at(nim);
  cout << "NIM: " << mahasiswa.nim << endl;
  cout << "Nilai: " << mahasiswa.nilai << endl;
}


void findMahasiswaByNilai(const unordered_map<string, Mahasiswa>& dataMahasiswa) {
  cout << "Mencari data mahasiswa dengan nilai antara 80 dan 90..." << endl;

  for (const auto& pair : dataMahasiswa) {
    const Mahasiswa& mahasiswa = pair.second;
    if (mahasiswa.nilai >= 80 && mahasiswa.nilai <= 90) {
      cout << "NIM: " << mahasiswa.nim << endl;
      cout << "Nilai: " << mahasiswa.nilai << endl;
    }
  }
}

void showMenu() {
  cout << "\nMenu:" << endl;
  cout << "1. Tambah Data Mahasiswa" << endl;
  cout << "2. Hapus Data Mahasiswa" << endl;
  cout << "3. Cari Data Mahasiswa Berdasarkan NIM" << endl;
  cout << "4. Cari Data Mahasiswa Berdasarkan Nilai (80 - 90)" << endl;
  cout << "5. Keluar" << endl;
  cout << "Pilih menu: ";
}

int main() {
  unordered_map<string, Mahasiswa> dataMahasiswa;

  int pilihan;
  do {
    showMenu();
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        addMahasiswa(dataMahasiswa);
        break;
      case 2:
        deleteMahasiswa(dataMahasiswa);
        break;
      case 3:
        findMahasiswaByNIM(dataMahasiswa);
        break;
      case 4:
        findMahasiswaByNilai(dataMahasiswa);
        break;
      case 5:
        cout << "Keluar dari program." << endl;
        break;
      default:
        cout << "Pilihan tidak valid. Silakan masukkan pilihan yang benar." << endl;
    }
  } while (pilihan != 5);

  return 0;
}