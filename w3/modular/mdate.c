/* Nama Program : mdate.c
	Deskripsi : Driver untuk menggunakan unit ADT Date
			yang ada di date.h dan date.c
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "date.h"
#include "date.c"

/* P R O G R A M   U T A M A   */
int main()
{
	date D1, D2, D3, D4;
	char lagi = 'y';

	/* Algoritma : Procedure yang isi bodynya call thd semua feature yang ada */
	for (;;)
	{
		// lakukan clear screen;
		system("cls");

		//** PROCEDURE ReadDate **//
		// // case birthday
		// printf("=== ReadDate Birthday Case ===\n");
		// date birthday;
		// ReadDate(&birthday);
		// printf("Birthday: %d/%d/%d\n", GetTgl(birthday), GetBln(birthday), GetThn(birthday));
		// // case today
		// printf("\n=== ReadDate Today Case ===\n");
		// date today;
		// ReadDate(&today);
		// printf("Today: %d/%d/%d\n", GetTgl(today), GetBln(today), GetThn(today));
		// // case independence day
		// printf("\n=== ReadDate Independence Day Case ===\n");
		// date independenceDay;
		// ReadDate(&independenceDay);
		// printf("Independence Day: %d/%d/%d\n", GetTgl(independenceDay), GetBln(independenceDay), GetThn(independenceDay));

		//** PROCEDURE isValid **//
		// case valid
		printf("=== isValid Valid Case ===\n");
		CreateDate(&D1);
		SetTgl(22, &D1);
		SetBln(2, &D1);
		SetThn(2024, &D1);
		printf("Day: %d\n", GetTgl(D1));
		printf("Month: %d\n", GetBln(D1));
		printf("Year: %d\n", GetThn(D1));
		printf("Date: %d/%d/%d\n", GetTgl(D1), GetBln(D1), GetThn(D1));
		if (isValid(D1))
			printf("Date is valid\n");
		else
			printf("Date is invalid\n");

		// Case tahun yang diinput < min tahun
		printf("\n=== isValid Invalid Case ===\n");
		CreateDate(&D2);
		SetTgl(31, &D2);
		SetBln(12, &D2);
		SetThn(1895, &D2);
		printf("Day: %d\n", GetTgl(D2));
		printf("Month: %d\n", GetBln(D2));
		printf("Year: %d\n", GetThn(D2));
		printf("Date: %d/%d/%d\n", GetTgl(D2), GetBln(D2), GetThn(D2));
		if (isValid(D2))
			printf("Date is valid\n");
		else
			printf("Date is invalid\n");

		// Case tanggal kabisat bukan di tahun kabisat
		printf("\n=== isValid Invalid Case ===\n");
		CreateDate(&D3);
		SetTgl(29, &D3);
		SetBln(2, &D3);
		SetThn(2023, &D3);
		printf("Day: %d\n", GetTgl(D3));
		printf("Month: %d\n", GetBln(D3));
		printf("Year: %d\n", GetThn(D3));
		printf("Date: %d/%d/%d\n", GetTgl(D3), GetBln(D3), GetThn(D3));
		if (isValid(D3))
			printf("Date is valid\n");
		else
			printf("Date is invalid\n");

		// ** PROCEDURE PrintObj **//
		// Case print tanggal default
		printf("=== PrintObj Default Case ===\n");
		CreateDate(&D1);
		PrintObj(D1);

		// Case print tanggal custom
		printf("\n=== PrintObj Custom Case ===\n");
		CreateDate(&D2);
		SetTgl(31, &D2);
		SetBln(12, &D2);
		SetThn(2024, &D2);
		PrintObj(D2);

		// case print tanggal dengan bulan 1 digit
		printf("\n=== PrintObj 1 Digit Month Case ===\n");
		CreateDate(&D3);
		SetTgl(31, &D3);
		SetBln(1, &D3);
		SetThn(2024, &D3);
		PrintObj(D3);

		// ** PROCEDURE isKabisat **//
		// iTgl = 29, iBln = 2, iThn = 2020
		printf("=== isKabisat Kabisat Case ===\n");
		CreateDate(&D1);
		SetTgl(29, &D1);
		SetBln(2, &D1);
		SetThn(2020, &D1);
		printf("Date: %d/%d/%d\n", GetTgl(D1), GetBln(D1), GetThn(D1));
		if (isKabisat(D1))
			printf("Date is kabisat\n");
		else
			printf("Date is not kabisat\n");

		// iTgl = 9, iBln = 6, iThn = 1900
		printf("\n=== isKabisat Not Kabisat Case ===\n");
		CreateDate(&D2);
		SetTgl(9, &D2);
		SetBln(6, &D2);
		SetThn(1900, &D2);
		printf("Date: %d/%d/%d\n", GetTgl(D2), GetBln(D2), GetThn(D2));
		if (isKabisat(D2))
			printf("Date is kabisat\n");
		else
			printf("Date is not kabisat\n");

		// iTgl = 9, iBln = 11, iThn = 2000
		printf("\n=== isKabisat Kabisat Case ===\n");
		CreateDate(&D3);
		SetTgl(9, &D3);
		SetBln(11, &D3);
		SetThn(2000, &D3);
		printf("Date: %d/%d/%d\n", GetTgl(D3), GetBln(D3), GetThn(D3));
		if (isKabisat(D3))
			printf("Date is kabisat\n");
		else
			printf("Date is not kabisat\n");

		// ** PROCEDURE getEndDate **//
		// iTgl = 9, iBln = 12, iThn = 2023
		printf("=== getEndDate Case ===\n");
		CreateDate(&D1);
		SetTgl(9, &D1);
		SetBln(12, &D1);
		SetThn(2023, &D1);
		printf("Day %d Month %d Year %d\n", GetTgl(D1), GetBln(D1), GetThn(D1));
		printf("Date: %d/%d/%d\n", GetTgl(D1), GetBln(D1), GetThn(D1));

		// iTgl = 29, iBln = 2, iThn = 2020
		printf("\n=== getEndDate Kabisat Case ===\n");
		CreateDate(&D2);
		SetTgl(29, &D2);
		SetBln(2, &D2);
		SetThn(2020, &D2);
		printf("Day %d Month %d Year %d\n", GetTgl(D2), GetBln(D2), GetThn(D2));
		printf("Date: %d/%d/%d\n", GetTgl(D2), GetBln(D2), GetThn(D2));

		// iTgl = 20, iBln = 2, iThn = 2021
		printf("\n=== getEndDate Not Kabisat Case ===\n");
		CreateDate(&D3);
		SetTgl(20, &D3);
		SetBln(2, &D3);
		SetThn(2021, &D3);
		printf("Day %d Month %d Year %d\n", GetTgl(D3), GetBln(D3), GetThn(D3));
		printf("Date: %d/%d/%d\n", GetTgl(D3), GetBln(D3), GetThn(D3));

		// ** PROCEDURE DateBefore **//
		// iTgl = 17, iBln = 8, iThn = 2023
		printf("=== DateBefore Case ===\n");
		CreateDate(&D1);
		SetTgl(17, &D1);
		SetBln(8, &D1);
		SetThn(2023, &D1);
		DateBefore(D1);

		// iTgl = 1, iBln = 3, iThn = 2024
		printf("\n=== DateBefore Case ===\n");
		CreateDate(&D2);
		SetTgl(1, &D2);
		SetBln(3, &D2);
		SetThn(2024, &D2);
		DateBefore(D2);

		// iTgl = 1, iBln = 1, iThn = 2024
		printf("\n=== DateBefore Case ===\n");
		CreateDate(&D3);
		SetTgl(1, &D3);
		SetBln(1, &D3);
		SetThn(2024, &D3);
		DateBefore(D3);

		// ** PROCEDURE NextDate **//
		// iTgl = 17, iBln = 4, iThn = 2023
		printf("\n=== NextDate Case ===\n");
		CreateDate(&D1);
		SetTgl(17, &D1);
		SetBln(4, &D1);
		SetThn(2023, &D1);
		NextDate(D1);

		// iTgl = 28, iBln = 2, iThn = 2024
		printf("\n=== NextDate Case ===\n");
		CreateDate(&D2);
		SetTgl(28, &D2);
		SetBln(2, &D2);
		SetThn(2024, &D2);
		NextDate(D2);

		// iTgl = 31, iBln = 12, iThn = 2023
		printf("\n=== NextDate Case ===\n");
		CreateDate(&D3);
		SetTgl(31, &D3);
		SetBln(12, &D3);
		SetThn(2023, &D3);
		NextDate(D3);

		//** PROCEDURE DifferenceDate **//
		// D1 = 1/1/2024, D2 = 31/12/2024
		printf("\n=== DifferenceDate Case ===\n");
		CreateDate(&D1);
		SetTgl(1, &D1);
		SetBln(1, &D1);
		SetThn(2024, &D1);
		CreateDate(&D2);
		SetTgl(31, &D2);
		SetBln(12, &D2);
		SetThn(2024, &D2);
		printf("Date 1: %d/%d/%d\n", GetTgl(D1), GetBln(D1), GetThn(D1));
		printf("Date 2: %d/%d/%d\n", GetTgl(D2), GetBln(D2), GetThn(D2));
		DifferenceDate(D1, D2);

		// D1 = 29/2/2020, D2 = 29/2/2024
		printf("\n=== DifferenceDate Case ===\n");
		CreateDate(&D3);
		SetTgl(29, &D3);
		SetBln(2, &D3);
		SetThn(2020, &D3);
		CreateDate(&D4);
		SetTgl(29, &D4);
		SetBln(2, &D4);
		SetThn(2024, &D4);
		printf("Date 1: %d/%d/%d\n", GetTgl(D3), GetBln(D3), GetThn(D3));
		printf("Date 2: %d/%d/%d\n", GetTgl(D4), GetBln(D4), GetThn(D4));
		DifferenceDate(D3, D4);

		// D1 = 1/1/2019, D2 = 1/1/2024
		printf("\n=== DifferenceDate Case ===\n");
		CreateDate(&D1);
		SetTgl(1, &D1);
		SetBln(1, &D1);
		SetThn(2019, &D1);
		CreateDate(&D2);
		SetTgl(1, &D2);
		SetBln(1, &D2);
		SetThn(2024, &D2);
		printf("Date 1: %d/%d/%d\n", GetTgl(D1), GetBln(D1), GetThn(D1));
		printf("Date 2: %d/%d/%d\n", GetTgl(D2), GetBln(D2), GetThn(D2));
		DifferenceDate(D1, D2);

		printf("\nUlangi lagi (y/t) ? ");
		lagi = getche();
		if (lagi != 'y')
			break;
	}
	return 0;
}