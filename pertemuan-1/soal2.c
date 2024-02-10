#include <stdio.h>
#include <stdlib.h>

// Prosedur untuk mencetak array
void printArray(char result[], char remain[], char arr[], int resultSize, int remainSize, int arrSize, int t);

// Prosedur untuk menghitung panjang array
void calculateLengthArray(char arr[], int *length);

// Prosedur untuk mencari huruf yang berurutan
void findConsecutive(char arr[], char result[], int *arrSize, int *resultSize);

// Prosedur untuk memindahkan array ke result
void arrToResult(char arr[], char result[], char remain[], int *arrSize, int *resultSize, int *remainSize, int t);

// Prosedur untuk memindahkan array ke remain
void arrToRemain(char arr[], char result[], char remain[], int *arrSize, int *resultSize, int *remainSize, int t);

// Prosedur untuk menginisialisasi array
void initalizeArr(char arr[], char result[], char remain[], int *arrSize, int *resultSize, int *remainSize);

// Prosedur untuk mengurutkan array dengan insertion sort
void insertionSort(char arr[], int n);

// Prosedur untuk menggabungkan dan mengurutkan array
void sortAndMergeArray(char arr1[], char arr2[], int *resultSize, char result[], int *remainSize);

int main()
{
    char arr[11] = {'E', 'K', 'A', 'C', 'D', 'O', 'L', 'M', 'N', 'F', 'G'};
    // char arr[11] = {'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D'};
    // char arr[11] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K'};

    char result[11];
    char remain[11];

    int resultSize = 0, remainSize = 0, arrSize = 11, t = 1;

    for (int i = 0; i < 11; i++)
    {
        // Assuming null character '\0' denotes empty element for avoid garbage value like $, #, etc
        result[i] = '\0';
        remain[i] = '\0';
    }

    while (arrSize > 0 || remainSize > 0)
    {
        if (resultSize == 0)
        {
            arrToResult(arr, result, remain, &arrSize, &resultSize, &remainSize, t);
        }
        else if (remainSize == 0)
        {
            arrToRemain(arr, result, remain, &arrSize, &resultSize, &remainSize, t);
        }
        else
        {
            sortAndMergeArray(result, remain, &resultSize, result, &remainSize);
            printArray(result, remain, arr, resultSize, remainSize, arrSize, t);
        }
        t++;
    }
    return 0;
}
void printArray(char result[], char remain[], char arr[], int resultSize, int remainSize, int arrSize, int t)
{
    printf("t = %i, ", t);

    printf("[");
    printf("[");
    for (int i = 0; i < resultSize; i++)
    {
        printf("'%c'", result[i]);
        if (i != resultSize - 1)
        {
            printf(", ");
        }
    }
    printf("], [");
    for (int i = 0; i < remainSize; i++)
    {
        printf("'%c'", remain[i]);
        if (i != remainSize - 1)
        {
            printf(", ");
        }
    }
    printf("]");
    printf("] ");

    printf("[");
    for (int i = 0; i < arrSize; i++)
    {
        printf("'%c'", arr[i]);
        if (i != arrSize - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
    t++;
}

void calculateLengthArray(char arr[], int *length)
{
    int i = 0;
    while (arr[i] != '\0')
    {
        i++;
    }
    *length = i;
}

void findConsecutive(char arr[], char result[], int *arrSize, int *resultSize)
{
    int i = 0;

    // find length of consecutive array
    while (i < *arrSize - 1 && arr[i] < arr[i + 1])
    {
        i++;
    }
    *resultSize = i + 1;

    // copy consecutive array to result
    for (int j = 0; j < *resultSize; j++)
    {
        result[j] = arr[j];
    }

    // remove consecutive array from arr
    for (int j = 0; j < *arrSize - *resultSize; j++)
    {
        arr[j] = arr[j + *resultSize];
    }

    // update arrSize
    *arrSize = *arrSize - *resultSize;
}

void arrToResult(char arr[], char result[], char remain[], int *arrSize, int *resultSize, int *remainSize, int t)
{
    findConsecutive(arr, result, arrSize, resultSize);
    printArray(result, remain, arr, *resultSize, *remainSize, *arrSize, t);
}

void arrToRemain(char arr[], char result[], char remain[], int *arrSize, int *resultSize, int *remainSize, int t)
{
    findConsecutive(arr, remain, arrSize, remainSize);
    printArray(result, remain, arr, *resultSize, *remainSize, *arrSize, t);
}

void initalizeArr(char arr[], char result[], char remain[], int *arrSize, int *resultSize, int *remainSize)
{
    // Reset result array
    for (int i = 0; i < 11; i++)
    {
        // Assuming null character '\0' denotes empty element
        result[i] = '\0';
        remain[i] = '\0';
    }

    // copy arr to result
    arrToResult(arr, result, remain, arrSize, resultSize, remainSize, 1);

    // copy arr to remain
    arrToRemain(arr, result, remain, arrSize, resultSize, remainSize, 2);
}

void insertionSort(char arr[], int n)
{
    int i, j;
    char key;
    // loop through the array
    for (i = 1; i < n; i++)
    {
        // set the key to the current element
        key = arr[i];
        j = i - 1;

        // check if the previous element is greater than the key
        while (arr[j] > key && j >= 0)
        {
            // if yes, move the previous element to the next position
            arr[j + 1] = arr[j];
            j--;
        }

        // move the key to the next position
        arr[j + 1] = key;
    }
}

void sortAndMergeArray(char arr1[], char arr2[], int *resultSize, char result[], int *remainSize)
{
    int arr1Length, arr2Length, totalLength;

    calculateLengthArray(arr1, &arr1Length);
    calculateLengthArray(arr2, &arr2Length);

    totalLength = arr1Length + arr2Length;

    char temp[11];

    // merge arr1 and arr2
    for (int i = 0; i < totalLength; i++)
    {
        if (i < arr1Length)
        {
            temp[i] = arr1[i];
        }
        else
        {
            temp[i] = arr2[i - arr1Length];
        }
    }

    insertionSort(temp, totalLength);

    // copy sorted merged array back to result
    for (int i = 0; i < totalLength; i++)
    {
        result[i] = temp[i];
        arr2[i] = '\0';
    }

    *resultSize = totalLength;
    *remainSize = 0;
}
