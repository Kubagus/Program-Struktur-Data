#include <iostream>
using namespace std;

int fib(int n)
{
if (n <= 1)
return n;
return fib(n-1) + fib(n-2);
}

int fibSearch(int arr[], int x, int n)
{
int fibMm2 = 0;
int fibMm1 = 1;
int fibM = fibMm1 + fibMm2;
while (fibM < n)
{
    fibMm2 = fibMm1;
    fibMm1 = fibM;
    fibM = fibMm1 + fibMm2;
}

int offset = -1;
int iter =1;

while (fibM > 1)
{
    int i = min(offset+fibMm2, n-1);

    cout << "Iterasi ke-" << iter++ << " mendekati angka fibonacci " << fibM << ": Mencari di indeks " << i << endl;

    if (arr[i] < x)
    {
        fibM = fibMm1;
        fibMm1 = fibMm2;
        fibMm2 = fibM - fibMm1;
        offset = i;
    }

    else if (arr[i] > x)
    {
        fibM = fibMm2;
        fibMm1 = fibMm1 - fibMm2;
        fibMm2 = fibM - fibMm1;
    }

    else
        return i;
}

if(fibMm1 && arr[offset+1]==x)
    return offset+1;

return -1;
}

int main()
{
	cout << "Ahmad Kubagus Subkhi | C2C021064" << endl;
int arr[] = {23, 75, 80, 86, 90, 100, 101, 103, 106, 199, 202, 212, 450};
int n = sizeof(arr)/sizeof(arr[0]);
int x = 199;
cout << "Nilai yang dicari: " << x << endl;
int index = fibSearch(arr, x, n);
if (index != -1)
cout << "Nilai ditemukan di indeks ke-" << index << endl;
else
cout << "Nilai tidak ditemukan di dalam array" << endl;
return 0;
}