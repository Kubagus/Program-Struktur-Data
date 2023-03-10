#include<iostream>
using namespace std;
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}

int steps(int *array, int size){
	for (int i=0;i<size;i++){
  		cout <<array[i] << "|";
	}
	cout<<endl;
}
void insertionSort(int *array, int size) {
   int key, j;
   cout << "Proses insertion sort" << endl;
   for(int i = 1; i<size; i++) {
      key = array[i];//take value
      j = i;
      while(j > 0 && array[j-1]<key) {
         array[j] = array[j-1];
         j--;
      }
      array[j] = key;   //insert in right place
      steps(array, size);
   }
}


int main() {
   cout << "PROGRAM INSERT SORT DESCENDING" << endl;
   int n;
   cout << "Masukkan jumlah data: ";
   cin >> n;
   int arr[n];    //create an array with given number of elements
   cout << "Msukkan data:" << endl;
   for(int i = 0; i<n; i++) {
      cout << "elemen ke-" << i+1 << ": ";  	
      cin >> arr[i];
   }
   cout << "Array sebelum Sorting: ";
   display(arr, n);
   insertionSort(arr, n);
   cout << "Array setelah Sorting: ";
   display(arr, n);
   cout << endl;
   steps(arr, n);
}