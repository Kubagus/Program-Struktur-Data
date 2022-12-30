#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

using namespace std;

struct SIMPUL { int INFO;

	struct SIMPUL *LINK;
};

struct SIMPUL *P, *FIRST, *LAST, *T, *Q;

void AWAL(void);
void TAMPIL(void);
void INSERT_KANAN(void);
void INSERT_KIRI(void);
void INSERT_TENGAH(void);
void DELETE_KIRI(void);
void DELETE_KANAN(void);
void DELETE_TENGAH(void);
void COBA(void);
int X, PIL;
string konfirmasi = "y";

main(){
	do{
		system("cls");
		cout << "LINIER SINGLY LIST" << endl;
		cout << "===================" << endl;
		cout << "1.	SIMPUL AWAL" << endl;
		cout << "2.	INSERT KANAN" << endl;
		cout << "3.	INSERT KIRI" << endl;
		cout << "4.	INSERT TENGAH" << endl;
		cout << "5.	DELETE KANAN" << endl;
		cout << "6.	DELETE KIRI" << endl;
		cout << "7.	DELETE TENGAH" << endl;
		cout << "8.	TAMPIL" << endl;
		cout << "9.	EXIT\n\n" << endl;
		
		cout << "PILIHAN	:	"; cin >> PIL;
		
		switch(PIL){
			case 1: AWAL();
				break;
			case 2 : INSERT_KANAN();
				break;
			case 3 : INSERT_KIRI();
				break;
			case 4 : INSERT_TENGAH();
				break;
			case 5 : DELETE_KANAN();
				break;
    		case 6 : DELETE_KIRI();
				break;
			case 7 : DELETE_TENGAH();
				break;
			case 8 : TAMPIL();
				break;
			case 9 : cout << "TERIMA KASIH"; break;
		
		} getch();		
	} while(PIL < 9);
			
}


void AWAL(void){
//	system("cls");
	cout << "MASUKKAN SIMPUL AWAL	:	";
	cin >> X;
	
	P = (struct SIMPUL *)malloc(sizeof(struct SIMPUL));
	P->INFO = X;	
	P->LINK = NULL;	
	
	FIRST = P;
		LAST = P;
	
	cout << "Isi P			=	" << P->INFO << endl;
	cout << "Isi FIRST		=	" << FIRST->INFO << endl;
	cout << "Isi LAST		=	" << LAST->INFO << endl;
	cout << "Isi Pointer P		=	" << P->LINK << endl;
	cout << "Isi Pointer FIRST	=	" << FIRST->LINK << endl;
	cout << "Isi Pointer LAST	=	" << LAST->LINK << endl;
}


void INSERT_KANAN(void){
//	system("cls");
	TAMPIL();
	cout << "MASUKKAN SIMPUL KANAN	:	";
	cin >> X;
	
	P = (struct SIMPUL*)malloc(sizeof(struct SIMPUL));
	P->INFO = X;	
	LAST->LINK = P;	
	LAST = P;	
	P->LINK = NULL;
	TAMPIL();
}

void INSERT_KIRI(void){
//	system("cls");
	TAMPIL();
	cout << "MASUKKAN SIMPUL KIRI	:	";
	cin >> X;
	
	P = (struct SIMPUL*)malloc(sizeof(struct SIMPUL));
	P->INFO = X;	
	P->LINK =  FIRST;	
	FIRST = P;
	cout << "Isi P	=	" << P->INFO << endl;
	TAMPIL();

}
void INSERT_TENGAH(void){
//	system("cls");
	TAMPIL();
	cout << "MASUKKAN SIMPUL TENGAH	:	";
	cin >> X;
	Q = (struct SIMPUL*)malloc(sizeof(struct SIMPUL));
	Q->INFO = X;
	cout << "Isi P	=	" << Q->INFO << endl;
	int nomor = 1;	
	int posisi;
	cout << "Masukkan simpul pada data ke- :	"; cin >> posisi; 	
	P = FIRST;
	while(nomor < posisi - 1 ){
		P = P->LINK;
		nomor++;
	}
	Q->LINK = P->LINK;
	P->LINK = Q;
	TAMPIL();
}
void DELETE_KANAN(void){
//	system("cls");
	TAMPIL();
	if(FIRST != NULL){
		P = FIRST;
		
		while(P->LINK != NULL){
			Q = P;
			P = P->LINK;
		}
		X = P->INFO;
		cout << "DATA YANG AKAN DIHAPUS	:	" << X;
		free(P);
		Q->LINK = NULL;
		LAST = Q;
	} else{
		cout << "SIMPUL KOSONG";
	}
}
void DELETE_KIRI(void){
	TAMPIL();
//	system("cls");
	if(FIRST != NULL){	
		P = FIRST;
		FIRST = FIRST->LINK;
		X = P->INFO;
		cout << "DATA YANG AKAN DIHAPUS	:	" << X;
		free(P);
	}else{
		cout << "Simpul Kosong." << endl;
	}
}

void DELETE_TENGAH(void){
//	system("cls");
	TAMPIL();
	if(FIRST != NULL){
		P = FIRST;
		int nomor = 1;
		int posisi;
		cout << "Ingin menghapus data ke- :	"; cin >> posisi; 	
		P = FIRST;
		while(nomor <= posisi){
			if(nomor == posisi - 1){
                Q = P; 	
			}
			if(nomor == posisi){
                T = P; 	
			}
	 		P = P->LINK;
	  	    nomor++;
		}
	    cout << "Ingin menghapus  " << T->INFO << " ? y/n :"; 
		cin >> konfirmasi;
		if(T != FIRST ||T != LAST){		 	
   		 if(konfirmasi == "y" || "Y"){    	
				Q->LINK = P;
				free(T);
				cout << "Data telah terhapus.";
			}else{
				cout << "Pilihan anda salah." << endl;  	
			}
		}else{
 		cout << "Tidak bisa menghapus data awal / akhir menggunakan delete tengah" << endl;
		}
	} else{
		cout << "SIMPUL KOSONG";
	}
}


void TAMPIL(void){
//	system("cls");
	T = FIRST;
	cout <<"Daftar Simpul" << endl; 
	while(T != NULL){
		X = T->INFO;
		cout << X << " ";
			T = T->LINK;
	}
	cout << endl;
}


