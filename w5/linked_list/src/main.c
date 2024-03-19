#include <stdio.h>
#include "LinkedList.c"

int main()
{
    LinkedList *list = createList();

    // List sebelum diisi
    printf("List sebelum dilakukan operasi apapun \n");
    displayList(list);
    printf("\n");

    // Melakukan operasi enqueue di posisi terakhir
    enqueueEnd(list, 10);
    enqueueEnd(list, 20);
    enqueueEnd(list, 30);

    printf("List setelah dilakukan operasi enqueue di posisi terakhir (10, 20, 30) \n");
    displayList(list);

    // Melakukan operasi enqueue di posisi pertama
    enqueueBegin(list, 5);

    printf("List setelah dilakukan operasi enqueue di posisi pertama (5) \n");
    displayList(list);

    // Melakukan operasi enqueue di posisi ke-2 (dari depan)
    enqueueNth(list, 15, 2);

    printf("List setelah dilakukan operasi enqueue di posisi ke-2 (dari depan) (15) \n");
    displayList(list);

    // Menampilkan isi list setelah dilakukan operasi enqueue
    printf("List setelah dilakukan semua operasi enqueue \n");
    displayList(list);

    // Melakukan operasi dequeue di posisi pertama
    printf("Operasi dequeue di posisi pertama: %d\n", dequeueBegin(list));
    printf("List setelah dilakukan operasi dequeue di posisi pertama \n");
    displayList(list);

    // Melakukan operasi dequeue di posisi terakhir
    printf("Operasi dequeue di posisi terakhir: %d\n", dequeueEnd(list));
    printf("List setelah dilakukan operasi dequeue di posisi terakhir \n");
    displayList(list);

    // Melakukan operasi dequeue di posisi ke-2 (dari depan)
    printf("Operasi dequeue di posisi ke-2 (dari depan): %d\n", dequeueNth(list, 2));
    printf("List setelah dilakukan operasi dequeue di posisi ke-2 (dari depan) \n");
    displayList(list);

    // Menampilkan isi list setelah dilakukan operasi dequeue
    printf("List setelah dilakukan semua operasi dequeue \n");
    displayList(list);

    // Mengosongkan isi list
    freeList(list);
    return 0;
}
