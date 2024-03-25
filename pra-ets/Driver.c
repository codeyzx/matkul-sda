#include <stdio.h>
#include "Header.h"
#include "Body.c"
#include "DBody.c"
#include "DHeader.h"

int main()
{
    // Palindrome with Single Linked List
    isPalindrome("JONI");
    isPalindrome("KASURINIRUSAK");

    // Palindrome with Double Linked List
    DisPalindrome("JONI");
    DisPalindrome("KASURINIRUSAK");
    DisPalindrome("ABIOBOIBA");

    // Initialize List
    List list;
    InitializeList(&list);
    InsertFirst(&list, "A");
    InsertFirst(&list, "B");
    InsertFirst(&list, "A");
    InsertFirst(&list, "C");
    InsertFirst(&list, "F");
    InsertFirst(&list, "D");
    InsertFirst(&list, "E");
    PrintList(list);

    // Sort List
    SortList(&list, CountList(list));
    PrintList(list);

    // Bracket Match
    isBracketMatch("((()))");
    isBracketMatch("(()))");
    isBracketMatch("(()()");
    isBracketMatch("(()))");

    return 0;
}