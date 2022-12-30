#include <iostream>

#include <conio.h>

#include <stdlib.h>

using namespace std;
int n = 10, dasar1 = 0, dasar2 = n + 1, top1 = 0, top2 = n + 1, pil, j;
char wadah[10];
char huruf;

void push1(void) {
  system("cls");
  if (top2 - top1 > 1) {
    cout << "Input 1 huruf : ";
    cin >> huruf;
    top1 = top1 + 1;
    wadah[top1] = huruf;
  } else {
    cout << endl << "=======================" << endl;
    cout << "STACK PENUH" << endl;
    cout << "KURANGI STACK" << endl;
    cout << "=======================" << endl;
  }
}

void pop1(void) {
  system("cls");
  if (top1 > 0) {
    huruf = wadah[top1];
    cout << "Huruf yang dihapus : " << huruf << endl;
  } else {
    cout << endl << "=======================" << endl;
    cout << "STACK KOSONG" << endl;
    cout << "TAMBAH STACK" << endl;
    cout << "=======================" << endl;

  }
}

void push2(void) {
  system("cls");
  if (top2 - top1 > 1) {
    cout << "Input 1 huruf : ";
    cin >> huruf;
    top2 = top2 - 1;
    wadah[top2] = huruf;
  } else {
    cout << endl << "=======================" << endl;
    cout << "STACK PENUH" << endl;
    cout << "KURANGI STACK" << endl;
    cout << "=======================" << endl;

  }
}

void pop2(void) {
  system("cls");
  if (top2 < n + 1) {
    huruf = wadah[top2];
    cout << "Huruf yang dihapus : " << huruf << endl;
    top2 = top2 + 1;
  } else {
    cout << endl << "=======================" << endl;
    cout << "STACK KOSONG" << endl;
    cout << "TAMBAH STACK" << endl;
    cout << "=======================" << endl;

  }
}

void c_stack() {
  //menampilkan array terkahir yg pernah terisi, jaadi walaupun sudah dikurangi akan menampilkan huruf yang pernah mengisinya.
  //	system("cls");
  int i;
  cout << "Huruf yang mengisi : ";
  for (j = 0; j < 11; j++) {
    cout << wadah[j] << " ";
  }
  cout << endl << endl;
  for (i = 0 + 1; i < 11; i++) {
    cout << i << ". " << wadah[i] << endl;
  }
}

int main() {
  x: //ke menu utama
  {
    for (; pil < 1000;) {
      //			system("cls");
      cout << endl << "MENU UTAMA" << endl;
      cout << "=======================" << endl;
      cout << "1. MASUK" << endl;
      cout << "2. KELUAR" << endl;
      cout << "3. CETAK" << endl;
      cout << "4. QUIT" << endl; 
      cout << "PILIH (1-6) : ";

      cin >> pil;
      switch (pil) {
      case 1:
        push1();
        break;
      case 2:
        pop1();
        break;
      case 3:
        push2();
        break;
      case 4:
        pop2();
        break;
      case 5:
        c_stack();
        break;
      case 6:
        cout << "Terimakasih";
        goto y;
        break;
      default:
        cout << "Anda salah input" << endl;
        getch();
        goto x; //kembali ke menu utama bila salah
        break;
      }
    }
  }
  y:{
  }
}