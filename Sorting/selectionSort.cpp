#include<iostream>
using namespace std;

int main() {
	cout << "PROGRAM SELECTION SORT DESCENDING" << endl;
    int n, tukar, A[100];
    cout << "Masukkan jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Data ke-" << i + 1 << " = " ;
        cin >> A[i];
        cout << endl;
    }
    cout << endl;
    cout << "Data sebelum disorting: ";
    for(int i = 0; i < n; i++){
    	cout << A[i] << " ";
	}
	cout << endl;
	cout << "Proses selection sort" << endl;
    for (int i = 0; i < n-1; i++) {
        tukar = i;
        int temp;
        for(int j = i+1; j < n; j++){
            if(A[j] > A[tukar]){
                tukar = j;
            }
        }   
        temp = A[tukar];
        A[tukar] = A[i];
        A[i] = temp;
        
	    for(int i = 0; i < n; i++){
	        cout << A[i] << "|";
	    }
     	cout << endl;
    }
    
    cout << "Data setelah disorting: ";
    for(int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    
    cin.get();
    return 0;
}
