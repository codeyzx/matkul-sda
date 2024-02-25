/* File        : date.c */
/* Deskripsi   : Unit untuk keperluan ADT Date */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include <stdio.h>
#include <math.h>
#include "date.h"

/*********** Operasi Primitif ************/
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
void CreateDate(date *D)
{
	SetTgl(01, &(*D));
	SetBln(01, &(*D));
	SetThn(1900, &(*D));
}

/******* Selector komponen **********/
/* Mengambil bagian Tgl dari date */
int GetTgl(date D)
{
	return (D.Tgl);
}

/* Mengambil bagian Bln dari date */
int GetBln(date D)
{
	return (D.Bln);
}

/* Mengambil bagian Thn dari date */
int GetThn(date D)
{
	return (D.Thn);
}

/****** Pengubah komponen ******/
/* Memberi nilai untuk Tgl */
void SetTgl(int NewTgl, date *D)
{
	(*D).Tgl = NewTgl;
}

/* Memberi nilai untuk Bln */
void SetBln(int NewBln, date *D)
{
	(*D).Bln = NewBln;
}

/* Memberi nilai untuk Thn */
void SetThn(int NewThn, date *D)
{
	(*D).Thn = NewThn;
}

/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
void ReadDate(date *D)
{
	printf("Tanggal : ");
	scanf("%d", &((*D).Tgl));
	printf("Bulan : ");
	scanf("%d", &((*D).Bln));
	printf("Tahun : ");
	scanf("%d", &((*D).Thn));
	if (!isValid(*D))
	{
		printf("Tanggal tidak valid, maka dibuat tanggal default 1/1/1900");
		CreateDate(&(*D));
	}
}

/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
boolean isValid(date D)
{
	if ((GetThn(D) < 1900) || (GetThn(D) > 30000) || (GetBln(D) < 1) || (GetBln(D) > 12) || (GetTgl(D) < 1) || (GetTgl(D) > getEndDate(D)))
		return (false);
	else
		return (true);
}

/* Print nilai D dengan format dd/mm/yyyy */
void PrintObj(date D)
{
	printf("%d/%d/%d", GetTgl(D), GetBln(D), GetThn(D));
}

/****** Operator Relasional ******/
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja
Harusnya kabisat adalah thn yang habis dibagi 4, atau habis dibagi 100 dan 400, tapi implementasinya seringkali hanya menggunakan 4 sebagai pembagi */
boolean isKabisat(date D)
{
	return ((GetThn(D) % 4 == 0) && ((GetThn(D) % 100 != 0) || (GetThn(D) % 400 == 0)));
}

/***** Predikat lain *******/
/* Memberikan tanggal terakhir dari sebuah bulan */
int getEndDate(date D)
{
	if (GetBln(D) == 2)
	{
		return (isKabisat(D) ? 29 : 28);
	}
	else if ((GetBln(D) == 4) || (GetBln(D) == 6) || (GetBln(D) == 9) || (GetBln(D) == 11))
		return (30);
	else
		return (31);
}

/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
void DateBefore(date D)
{
	printf("Sebelum tanggal ");
	PrintObj(D);
	if ((GetBln(D) == 1) && (GetTgl(D) == 1))
	{
		SetThn(GetThn(D) - 1, &D);
		SetBln(12, &D);
		SetTgl(getEndDate(D), &D);
	}
	else if (GetTgl(D) == 1)
	{
		SetBln(GetBln(D) - 1, &D);
		SetTgl(getEndDate(D), &D);
	}
	else
	{
		SetTgl(GetTgl(D) - 1, &D);
	}
	printf(" adalah ");
	PrintObj(D);
}

/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
void NextDate(date D)
{
	printf("Setelah tanggal ");
	PrintObj(D);
	if ((GetBln(D) == 12) && (GetTgl(D) == getEndDate(D)))
	{
		SetThn(GetThn(D) + 1, &D);
		SetBln(1, &D);
		SetTgl(1, &D);
	}
	else if (GetTgl(D) == getEndDate(D))
	{
		SetBln(GetBln(D) + 1, &D);
		SetTgl(1, &D);
	}
	else
	{
		SetTgl(GetTgl(D) + 1, &D);
	}
	printf(" adalah ");
	PrintObj(D);
}

/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal dan menampilkan dalam hari, bulan, dan tahun
	Asumsi : 1 tahun = 365 hari */

void DifferenceDate(date D1, date D2)
{
	int totalDays = 0;

	if (D1.Thn > D2.Thn || (D1.Thn == D2.Thn && (D1.Bln > D2.Bln || (D1.Bln == D2.Bln && D1.Tgl > D2.Tgl))))
	{
		date temp = D1;
		D1 = D2;
		D2 = temp;
	}

	for (int year = D1.Thn; year < D2.Thn; year++)
	{
		totalDays += isKabisat((date){1, 1, year}) ? 366 : 365;
	}

	for (int month = 1; month < D1.Bln; month++)
	{
		totalDays -= getEndDate((date){1, month, D1.Thn});
	}
	totalDays -= D1.Tgl;

	for (int month = 1; month < D2.Bln; month++)
	{
		totalDays += getEndDate((date){1, month, D2.Thn});
	}
	totalDays += D2.Tgl;

	//** BEFORE FIXING **//
	// printf("Selisih kedua tanggal adalah %d tahun, %d bulan, %d hari dengan total %d hari", totalDays / 365, (totalDays % 365) / 30, (totalDays % 365) % 30, totalDays);

	//** AFTER FIXING **//
	date temp;
	CreateDate(&temp);
	SetBln(GetBln(D1), &temp);
	SetThn(GetThn(D1), &temp);
	boolean status = true;
	int months = 0, days = 0, allDays = totalDays;
	while (status)
	{
		if (totalDays - getEndDate(temp) > 2)
		{
			months++;
			totalDays -= getEndDate(temp);
			SetBln(GetBln(temp) + 1, &temp);
			if (GetBln(temp) > 12)
			{
				SetBln(1, &temp);
				SetThn(GetThn(temp) + 1, &temp);
			}
		}
		else
		{
			days = totalDays;
			status = false;
		}
	}
	printf("Selisih kedua tanggal adalah %d tahun, %d bulan, %d hari dengan total %d hari", months / 12, months % 12, days, allDays);
}
