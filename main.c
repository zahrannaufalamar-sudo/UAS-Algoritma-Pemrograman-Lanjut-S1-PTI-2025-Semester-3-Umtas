#include <stdio.h>
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
