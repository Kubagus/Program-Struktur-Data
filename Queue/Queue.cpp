#include <iostream>
#define MAX 10
using namespace std;


struct queue {
	int F;
	int R;
	string data[MAX];
} Antrian;

void init(){
	Antrian.F = Antrian.R = -1;
}

bool isFull(){
	 if(Antrian.R == MAX - 1){
        return true;
    } else {
        return false;
    }
}

bool isEmpty(){
	return Antrian.R == 0;
}

void printQueue(){ //Menampilkan data
	if(isEmpty()){
		cout << "Antrian kosong" << endl;
	}else{
		cout << "Antrian : ";
		for(int i = Antrian.F; i < Antrian.R; i++){
			cout << endl;
			//Menambahkan koma jika tidak terdapat di antrean pertama
			cout << Antrian.data[i];
		}
		cout << endl;
	}
}

void enqueue(){ //Memasukkan data
	if(isFull()){
		cout << "Antrian penuh" << endl;
	}else{
		string data;
		cout << "Masukkan nama : ";
		cin >> data;
		Antrian.data[Antrian.R] = data;
		Antrian.R++;
		cout << "Nama masuk ke antrian" << endl;
		printQueue();
	}
}

void dequeue(){ //Mengeluarkan antrean data
	if(isEmpty()){
		cout << "Antrian kosong" << endl;
	}else{
		cout << "Mengeluarkan antrian \n" << Antrian.data[Antrian.F] << endl;
		for(int i = Antrian.F; i < Antrian.R; i++){
			Antrian.data[i] = Antrian.data[i+1];
			Antrian.R;
			printQueue();
		}
	}
}

void clear(){
	Antrian.F = Antrian.R = -1;
	cout << "Antrian sudah kosong" << endl;
}

int main(){
	int pilihan;
	do{
		cout << "----------------------------------\n";
		cout << "Menu Pilihan \n";
		cout << "----------------------------------\n";
		cout << "1. Masukkan Antrian \n";
		cout << "2. Keluarkan Antrian \n";
		cout << "3. Bersihkan Antrian \n";
		cout << "4. Keluar\n";
		cout << "Masukkan pilihan (1-4) : "; cin >> pilihan;
		
		switch (pilihan){
			case 1:{
				enqueue();
				break;
			}
			case 2:{
				dequeue();
				break;
			}
			case 3:{
				clear();
				break;
			}
			default:{
				cout << "Terima kasih";
				break;
			}
		}
	}while(pilihan != 4);
	return 0;
}