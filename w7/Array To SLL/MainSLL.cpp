/* File        : MainSLL.cpp */
/* Deskripsi   : Driver / main program untuk ADT Single Linked/Linear List */
/* Dibuat oleh : Yahya Alfon Sinaga */
/* Tanggal     : 21-03-2024 */

#include "spnrsll.h"
#include <stdio.h>
#include <string.h>
#include "BodyNRSL.cpp"

int main()
{
    /* Kamus Lokal */
    const size_t MAX_KOTA = 5;
    const size_t MAX_PENDUDUK = 5;
    List A[MAX_KOTA];

    /* Program */
    /* Inisialisasi List */
    for (size_t i = 0; i < MAX_KOTA; i++)
    {
        CreateList(&A[i]);
    }

    /* Menambah nama kota pada Array A */
    const char *kota[MAX_KOTA] = {"Bandung", "Jakarta", "Surabaya", "Medan", "Yogyakarta"};
    for (size_t i = 0; i < MAX_KOTA; i++)
    {
        First(A[i]) = Alokasi(kota[i]);
    }

    /* Menambahkan nama penduduk pada masing-masing kota */
    const char *penduduk[MAX_KOTA][MAX_PENDUDUK] = {
        {"Yahya", "Wahab", "Amir", "Fahri", "Rahman"},
        {"Hasan", "Badu", "Indra", "Rini", "Sari"},
        {"Dewi", "Budi", "Anto", "Joko", "Siti"},
        {"Putra", "Mega", "Diana", "Yuni", "Bella"},
        {"Rudi", "Dini", "Nana", "Eka", "Rina"}};

    for (size_t i = 0; i < MAX_KOTA; i++)
    {
        for (size_t j = 0; j < MAX_PENDUDUK; j++)
        {
            InsertFirstSLL(&A[i].First->next, penduduk[i][j]);
        }
    }

    /* Menampilkan seluruh isi List */
    printf("Seluruh isi List:\n");
    for (size_t i = 0; i < MAX_KOTA; i++)
    {
        PrintInfo(A[i]);
    }

    /* Menghapus kota Jakarta */
    DelAll(&A[1]);

    /* Menampilkan seluruh isi List setelah kota Jakarta dihapus */
    printf("\nSeluruh isi List setelah kota Jakarta dihapus:\n");
    for (size_t i = 0; i < MAX_KOTA; i++)
    {
        PrintInfo(A[i]);
    }

    /* Menghapus kota Medan */
    DelAll(&A[3]);

    /* Menampilkan seluruh isi List setelah kota Medan dihapus */
    printf("\nSeluruh isi List setelah kota Medan dihapus:\n");
    for (size_t i = 0; i < MAX_KOTA; i++)
    {
        PrintInfo(A[i]);
    }

    return 0;
}
