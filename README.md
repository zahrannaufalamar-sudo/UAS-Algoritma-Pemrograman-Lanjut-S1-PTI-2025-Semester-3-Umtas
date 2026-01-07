[main.c](https://github.com/user-attachments/files/24469477/main.c)![Tampil Data (Uas Alpro)](https://github.com/user-attachments/assets/c84abbb5-aaf4-4050-b08e-5871cd297b80)# Zahran Naufal Amar-C2483207012-UAS-Algoritma-Pemrograman-Lanjut-S1-PTI-2025-Semester-3-Umtas
Program ini dibuat menggunakan bahasa pemrograman **C** untuk mengelola data nilai mahasiswa.  
Data yang dikelola meliputi **NIM (string)**, **Nilai Tugas**, **Nilai UTS**, dan **Nilai UAS**.  
Program menyediakan menu interaktif untuk melakukan input, menampilkan data, menghapus data, mengubah nilai, serta mengolah nilai mahasiswa.

Program ini dirancang agar:
- Tidak mengalami infinite loop / hang
- Mendukung NIM yang mengandung huruf dan angka
- Mudah dipahami dan sesuai kebutuhan pembelajaran dasar struktur data dan pemrograman C

---

## Fitur Program
1. Input data mahasiswa
2. Menampilkan data mahasiswa beserta nilai rata-rata
3. Menghapus data mahasiswa berdasarkan NIM
4. Menampilkan nilai rata-rata tertinggi dan terendah beserta NIM
5. Mengubah nilai mahasiswa (Tugas / UTS / UAS)
6. Menu interaktif dan mudah digunakan

---

## Struktur Data
- NIM disimpan dalam bentuk **string (`char`)**
- Nilai disimpan dalam array **float**
- Maksimum data mahasiswa adalah **30 data**

---

## Menu Program
===== MENU =====

1. Input Data Mahasiswa
2. Tampilkan Data
3. Tambah Data Mahasiswa
4. Hapus Data Mahasiswa
5. Pengolahan Nilai
6. Ubah Nilai Mahasiswa
7. Rekursif
8. Keluar

## Cara Compile & Menjalankan Program (Code::Blocks)


1. Buka aplikasi **Code::Blocks**
2. Pilih menu **File → New → Project → Console Application**
3. Pilih bahasa **C**, lalu klik **Next**
4. Beri nama project dan tentukan lokasi penyimpanan
5. Salin seluruh kode program ke file `main.c`
6. Klik **Build and Run** atau tekan tombol **F9**
7. Program akan berjalan di jendela terminal Code::Blocks

---

### Program
[U#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

char nim[MAX][20];        // NIM sebagai string
float nilai[MAX][3];     // [0]=Tugas, [1]=UTS, [2]=UAS
int jumlah = 0;
char buffer[100];

/* ================= REKURSIF ================= */
int faktorial(int n) {
    if (n <= 1) return 1;
    return n * faktorial(n - 1);
}

/* ================= FIBONACCI ITERATIF ================= */
void fibonacciIteratif(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
}

/* ================= INPUT DATA ================= */
void inputData() {
    printf("Masukkan jumlah mahasiswa (maks 30): ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &jumlah);

    if (jumlah > MAX) jumlah = MAX;

    for (int i = 0; i < jumlah; i++) {
        printf("\nMahasiswa ke-%d\n", i + 1);

        printf("NIM          : ");
        fgets(nim[i], sizeof(nim[i]), stdin);
        nim[i][strcspn(nim[i], "\n")] = 0;

        printf("Nilai Tugas  : ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%f", &nilai[i][0]);

        printf("Nilai UTS    : ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%f", &nilai[i][1]);

        printf("Nilai UAS    : ");
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%f", &nilai[i][2]);
    }
}

/* ================= TAMPIL DATA ================= */
void tampilData() {
    if (jumlah == 0) {
        printf("Data masih kosong.\n");
        return;
    }

    printf("\n====================================================\n");
    printf("NIM             Tugas   UTS     UAS     Rata-rata\n");
    printf("====================================================\n");

    for (int i = 0; i < jumlah; i++) {
        float rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;
        printf("%-14s  %.2f   %.2f   %.2f   %.2f\n",
               nim[i], nilai[i][0], nilai[i][1], nilai[i][2], rata);
    }
}

/* ================= TAMBAH DATA ================= */
void tambahData() {
    if (jumlah >= MAX) {
        printf("Data sudah penuh!\n");
        return;
    }

    printf("NIM          : ");
    fgets(nim[jumlah], sizeof(nim[jumlah]), stdin);
    nim[jumlah][strcspn(nim[jumlah], "\n")] = 0;

    printf("Nilai Tugas  : ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &nilai[jumlah][0]);

    printf("Nilai UTS    : ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &nilai[jumlah][1]);

    printf("Nilai UAS    : ");
    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%f", &nilai[jumlah][2]);

    jumlah++;
    printf("Data berhasil ditambahkan.\n");
}

/* ================= UBAH NILAI ================= */
void ubahNilai() {
    char cari[20];
    printf("Masukkan NIM yang ingin diubah nilainya: ");
    fgets(cari, sizeof(cari), stdin);
    cari[strcspn(cari, "\n")] = 0;

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(nim[i], cari) == 0) {
            printf("Data ditemukan.\n");

            printf("Nilai Tugas baru : ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%f", &nilai[i][0]);

            printf("Nilai UTS baru   : ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%f", &nilai[i][1]);

            printf("Nilai UAS baru   : ");
            fgets(buffer, sizeof(buffer), stdin);
            sscanf(buffer, "%f", &nilai[i][2]);

            printf("Nilai berhasil diubah.\n");
            return;
        }
    }
    printf("NIM tidak ditemukan.\n");
}

/* ================= HAPUS DATA ================= */
void hapusData() {
    char cari[20];
    printf("Masukkan NIM yang dihapus: ");
    fgets(cari, sizeof(cari), stdin);
    cari[strcspn(cari, "\n")] = 0;

    for (int i = 0; i < jumlah; i++) {
        if (strcmp(nim[i], cari) == 0) {
            for (int j = i; j < jumlah - 1; j++) {
                strcpy(nim[j], nim[j + 1]);
                nilai[j][0] = nilai[j + 1][0];
                nilai[j][1] = nilai[j + 1][1];
                nilai[j][2] = nilai[j + 1][2];
            }
            jumlah--;
            printf("Data berhasil dihapus.\n");
            return;
        }
    }
    printf("Data tidak ditemukan.\n");
}

/* ================= PENGOLAHAN NILAI ================= */
void pengolahanNilai() {
    if (jumlah == 0) {
        printf("Data masih kosong.\n");
        return;
    }

    float max = -1, min = 101;
    int idxMax = 0, idxMin = 0;

    for (int i = 0; i < jumlah; i++) {
        float rata = (nilai[i][0] + nilai[i][1] + nilai[i][2]) / 3;

        if (rata > max) {
            max = rata;
            idxMax = i;
        }

        if (rata < min) {
            min = rata;
            idxMin = i;
        }
    }

    printf("\nRata-rata tertinggi:\n");
    printf("NIM   : %s\n", nim[idxMax]);
    printf("Nilai : %.2f\n", max);

    printf("\nRata-rata terendah:\n");
    printf("NIM   : %s\n", nim[idxMin]);
    printf("Nilai : %.2f\n", min);
}

/* ================= REKURSIF ================= */
void fiturRekursif() {
    printf("\nFaktorial jumlah mahasiswa (%d) = %d\n",
           jumlah, faktorial(jumlah));
    printf("Fibonacci: ");
    fibonacciIteratif(jumlah);
    printf("\n");
}

/* ================= MAIN ================= */
int main() {
    int menu;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Input data\n");
        printf("2. Tampil data\n");
        printf("3. Tambah data\n");
        printf("4. Ubah nilai mahasiswa\n");
        printf("5. Hapus data\n");
        printf("6. Pengolahan nilai\n");
        printf("7. Rekursif\n");
        printf("8. Keluar\n");
        printf("Pilih: ");

        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%d", &menu);

        switch (menu) {
            case 1: inputData(); break;
            case 2: tampilData(); break;
            case 3: tambahData(); break;
            case 4: ubahNilai(); break;
            case 5: hapusData(); break;
            case 6: pengolahanNilai(); break;
            case 7: fiturRekursif(); break;
            case 8: printf("Program selesai.\n"); break;
            default: printf("Menu tidak valid!\n");
        }
    } while (menu != 8);

    return 0;
}
ploading main.c…]()


## Screenshot Hasil Program

### Tampilan Menu Utama
![Menu Program (Uas Alpro)](https://github.com/user-attachments/assets/dfe4fd32-15f6-4e2b-b3e1-16a1a1fa1188)

### Tampilan Input Data Mahasiswa
![Input Data](Input Data (Uas Alpro) 1.jpeg)
![Input Data](Input Data (Uas Alpro) 2.jpeg)
![Input Data](Input Data (Uas Alpro) 3.jpeg)
![Input Data](Input Data (Uas Alpro) 4.jpeg)

### Tampilan Data
![Tampil Data (Uas Alpro)](https://github.com/user-attachments/assets/6e717b58-45d9-454c-ab31-a83b95230827)

### Tambah Data
![Tambah Data (Uas Alpro)](https://github.com/user-attachments/assets/c083f9f6-a897-49c3-8515-51640f57a20b)
![Output Tambah Data (Uas Alpro)](https://github.com/user-attachments/assets/c395919c-246f-4a3c-b454-22e1a30623a2)

### Ubah Nilai Mahasiswa
![Ubah Nilai Mahasiswa (Uas Alpro)](https://github.com/user-attachments/assets/500a75eb-2822-443b-ad85-07eef14406e9)
![Output Ubah NIlai (Uas Alpro)](https://github.com/user-attachments/assets/c1587ffa-66bf-413d-95f9-1b342917f24b)

### Tampilan Hapus Data
![Hapus Data (Uas Alpro)](https://github.com/user-attachments/assets/8a726f01-d5d8-47b3-92da-d6ba35d9cb3c)
![Hapus Data (Uas Alpro) 1](https://github.com/user-attachments/assets/8d8dced2-5458-4d41-a37f-e58b67218d5f)
![Output Hapus Data (Uas Alpro)](https://github.com/user-attachments/assets/7881b1b2-9d03-47cd-82cc-b1c90e3538d3)


### Tampilan Pengolahan Nilai
![Pengolahan Nilai (Uas Alpro)](https://github.com/user-attachments/assets/c5891970-5568-4bd8-973a-3084106db6e6)

### Tampilan Rekursif
![Rekrusif (Uas Alpro)](https://github.com/user-attachments/assets/5e5952ed-71d7-42ff-a5b6-8a8051d56ae2)


> **Catatan:**  
> Screenshot diambil dari hasil eksekusi program melalui terminal di Code::Blocks dan disimpan dalam satu folder dengan file README.md.

---

## Penulis
Nama  : Zahran Naufal Amar  
Bahasa Pemrograman : C  
Aplikasi : Code::Blocks  
Topik : Pengolahan Data Nilai Mahasiswa
