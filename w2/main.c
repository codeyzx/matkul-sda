// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <stdbool.h>

// typedef struct
// {
//     char propinsi[100];
//     int kota;
//     int penduduk;
//     int pria;
// } Data;

// void writeToFile()
// {
//     FILE *file = fopen("A.txt", "w");
//     fprintf(file, "%s %s %d %d\n", "Jabar", "Bandung", 1, 5);
//     fprintf(file, "%s %s %d %d\n", "Jabar", "Cimahi", 1, 4);
//     fprintf(file, "%s %s %d %d\n", "Jabar", "Tasik", 3, 3);
//     fprintf(file, "%s %s %d %d\n", "Jabar", "Garut", 4, 2);
//     fprintf(file, "%s %s %d %d\n", "Jateng", "Semarang", 6, 7);
//     fprintf(file, "%s %s %d %d\n", "Jateng", "Tegal", 7, 6);
//     fclose(file);
// }

// int main(int argc, char const *argv[])
// {

//     char propinsi[100], kota[100], Vpropinsi[100];
//     int wanita, pria, index = 0;
//     bool sama = true;

//     Data arrayData[100];

//     // writeToFile();

//     FILE *fileA = fopen("A.txt", "r");
//     fscanf(fileA, "%s %s %d %d", propinsi, kota, &wanita, &pria);
//     while (feof(fileA) == 0)
//     {
//         strcpy(Vpropinsi, propinsi);
//         while (!sama)
//         {
//             if (strcmp(Vpropinsi, propinsi) == 0)
//             {
//                 arrayData[index].kota = arrayData[index].kota + 1;
//                 arrayData[index].penduduk = arrayData[index].penduduk + wanita + pria;

//                 if (pria > wanita)
//                 {
//                     arrayData[index].pria = arrayData[index].pria + 1;
//                 }
//                 fscanf(fileA, "%s %s %d %d", propinsi, kota, &wanita, &pria);
//             }
//             else
//             {
//                 printf("here");
//                 FILE *fileB = fopen("B.txt", "w");
//                 fprintf(fileB, "%s %d %d %d\n", arrayData[index].propinsi, arrayData[index].kota, arrayData[index].penduduk, arrayData[index].pria);
//                 fclose(fileB);
//                 sama = false;
//                 index = index + 1;
//             }
//         }
//     }

//     return 0;
// }

#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Include for using bool type

// Define a structure to hold data for each province
typedef struct
{
    char propinsi[100];
    int kota;
    int penduduk;
    int pria;
} Data;

int main(int argc, char const *argv[])
{
    char propinsi[100], kota[100], Vpropinsi[100];
    int wanita, pria, index = 0;
    Data arrayData[100];

    FILE *fileA = fopen("A.txt", "r");
    FILE *fileB = fopen("B.txt", "w");

    while (fscanf(fileA, "%s %s %d %d", propinsi, kota, &wanita, &pria) == 4)
    {
        strcpy(Vpropinsi, propinsi);
        bool sama = true;
        strcpy(arrayData[index].propinsi, propinsi);

        do
        {
            arrayData[index].kota++;
            arrayData[index].penduduk += wanita + pria;
            if (pria > wanita)
            {
                arrayData[index].pria++;
            }

            fscanf(fileA, "%s %s %d %d", propinsi, kota, &wanita, &pria);

            if (strcmp(Vpropinsi, propinsi) != 0 || feof(fileA) != 0)
            {
                fprintf(fileB, "%s %d %d %d\n", arrayData[index].propinsi, arrayData[index].kota, arrayData[index].pria, arrayData[index].penduduk);
                sama = false;
                index++;
                arrayData[index].kota++;
                arrayData[index].penduduk += wanita + pria;
                if (pria > wanita)
                {
                    arrayData[index].pria++;
                }
            }
        } while (sama == true && !feof(fileA));
    }

    fclose(fileB);
    fclose(fileA);
    return 0;
}
