/*----------------------------------------------------------------------------*/
/* File : PTR21.cpp */
/* Deskripsi : contoh deklarasi list dan pemakaian makro */
/* Dibuat oleh : Tim Dosen SDP */
/* Tanggal : 13-09-2001 */
/*----------------------------------------------------------------------------*/
#include <stdlib.h>
#include <stdio.h>
/*Definisi akses komponen type, standard kuliah Algoritma dan pemrograman*/
#define info(P) (P)->info
#define next(P) (P)->next
#define Nil NULL
/* Definisi TYPE global (sebenarnya untuk soal ini tidak perlu global) */
/* Element list linier */
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist
{
    infotype info;
    address next;
} ElmtList;

void printList(ElmtList *First)
{
    address P;
    P = First;
    while (P != Nil)
    {
        printf("%d ", info(P));
        P = next(P);
    }
    printf("\n");
}

int insertAtFirst(ElmtList **First, int data)
{
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P == NULL)
    {
        return 0;
    }

    info(P) = data;
    next(P) = *First;
    *First = P;
    return data;
}

int insertAtLast(ElmtList **First, int data)
{
    address P, last;
    P = (address)malloc(sizeof(ElmtList));
    if (P == NULL)
    {
        return 0;
    }

    info(P) = data;
    next(P) = Nil;
    next(next(next(next(*First)))) = P;
    return data;
}

int insertNth(ElmtList **First, int data, int before, int after)
{
    address P, last;
    P = (address)malloc(sizeof(ElmtList));
    if (P == NULL)
    {
        return 0;
    }

    info(P) = data;
    next(P) = next(next(next(*First)));
    next(next(next(*First))) = P;
    return data;
}

/* Program Utama */
int main()
{
    /* kamus */
    address First;
    address P, Q;
    /* program */
    /* Create list kosong */
    First = Nil;
    /* Alokasi, insert as first elemen */
    P = (address)malloc(sizeof(ElmtList));
    info(P) = 10;
    next(P) = Nil;
    First = P;
    /* Alokasi, insert as first elemen */
    Q = (address)malloc(sizeof(ElmtList));
    info(Q) = 20;
    next(Q) = Nil;
    next(Q) = First;
    First = Q;
    /* Alokasi, insert as first elemen */
    P = (address)malloc(sizeof(ElmtList));
    info(P) = 30;
    next(P) = Nil;
    next(P) = First;
    First = P;

    printList(First);
    // insertAtFirst(&First, 40);
    P = (address)malloc(sizeof(ElmtList));
    info(P) = 40;
    next(P) = First;
    First = P;
    printList(First);
    // insertAtLast(&First, 50);
    P = (address)malloc(sizeof(ElmtList));
    info(P) = 50;
    next(P) = Nil;
    next(next(next(next(First)))) = P;
    printList(First);
    // insertNth(&First, 60, 20, 10);
    P = (address)malloc(sizeof(ElmtList));
    info(P) = 60;
    next(P) = next(next(next(First)));
    next(next(next(First))) = P;
    printList(First);
    return 0;
}