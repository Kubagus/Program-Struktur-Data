#include <iostream>
using namespace std;

// fungsi untuk melakukan sequential search
int sequentialSearch(int data[], int n, int key)
{
for (int i = 0; i < n; i++)
{
cout << "Mencari angka " << key << " pada indeks ke-" << i << endl;
    // jika ditemukan angka yang dicari, maka return indeksnya
    if (data[i] == key)
    {
        return i;
    }
}

// jika tidak ditemukan, return -1
return -1;
}

int main()
{
	cout << "Ahmad Kubagus Subkhi | C2C021064" << endl;
// array of data
int data[] = {23, 75, 80, 86, 90, 100, 101, 103, 106, 199, 202, 212, 450};
for(int i=0; i< sizeof(data)/sizeof(data[0]); i++){
	cout << data[i] << " ";
}
// angka yang akan dicari
cout << "\nMasukkan angka yang ingin dicari: ";
int key; cin >> key;
cout << "Data angka: ";
cout << endl;
// melakukan sequential search
int n = sizeof(data) / sizeof(data[0]);
int result = sequentialSearch(data, n, key);

// cek hasil pencarian
if (result == -1)
{
    cout << "Angka tidak ditemukan" << endl;
}
else
{
    cout << "\nAngka ditemukan pada indeks ke-" << result << " dengan " << result+1 << " iterasi" << endl;
}

return 0;
}