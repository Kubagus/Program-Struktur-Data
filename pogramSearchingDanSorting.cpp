#include<iostream>
#include<conio.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
void menu();
void linear_search();
void binary_search();
void fibonacci_search();
void linear_sort();
void bubble_sort();
void fibonacci();
void swap(int &value1, int &value2);
void tanya();
void salah();
int a,b,n,i,j,m,p,q,t,x,y,Fk,Fib[100],k,nilai[100],temp;
char jawab;
main()
{
cout<<setw(50)<<"\n\t========================="; 
cout<<setw(50)<<"\n\t| Searching And Sorting |"; 
cout<<setw(50)<<"\n\t|-----------------------|"; 
cout<<setw(50)<<"\n\t| Oleh : Tim Dosen |"; 
cout<<setw(50)<<"\n\t========================="; 
menu();
return 0; 
} 
void menu()
{
int nomor; 
system("cls"); 
cout<<"\n\n\tMENU SEARCHING AND SORTING"; 
cout<<"\n\t 1 :Linear Search"; 
cout<<"\n\t 2 :Binary Search"; 
cout<<"\n\t 3 :Fibonacci Search"; 
cout<<"\n\t 4 :Linear Sort"; 
cout<<"\n\t 5 :Exchange (Bubble) Sort"; 
cout<<"\n\t 6 :Keluar Program"; 
cout<<"\n\tPilihan Anda : "; 
cin>>nomor; 
switch(nomor) 
 {
case 1: 
linear_search(); 
 break;
case 2: 
 binary_search();
 break;
case 3: 
 fibonacci_search();
 break;
case 4: 
linear_sort(); 
 break;
case 5: 
 bubble_sort();
 break;
case 6: 
 tanya();
 break;
 default:
 salah();
 menu();
 break;
 }
}
void linear_search()
{
system("cls"); 
cout<<"\n\nMasukan jumlah nilai : "; 
cin>>n; 
for(i=1;i<=n;i++) 
 {
cout<<"Nilai ["<<i<<"] : "; 
cin>>nilai[i]; 
 }
cout<<"\nApakah data akan disortir? Y/N : "; 
cin>>jawab; 
if(jawab=='Y'||jawab=='y') 
 { 
for(i=1;i<=n;i++) 
 {
 for(j=i+1;j<=n;j++)
 {
 if(nilai[i]>nilai[j])
 {
 temp=nilai[i];
 nilai[i]=nilai[j];
 nilai[j]=temp;
 }
 } 
 }
cout<<"\n\nUrutan Ascending data :\n"; 
for(i=1;i<=n;i++) 
 cout<<nilai[i]<<" "; 
 
cout<<"\nNilai yang dicari : "; 
 cin>>b;
i=1; 
while(nilai[i]!=b) 
 i++;
if(i==n+1) 
 cout<<"\n\tPencarian gagal...";
 else
 {
 cout<<"\n\tNilai yang dicari :"<<nilai[i];
 cout<<"\n\tDi lokasi :"<<i;
 }
 }
else if(jawab=='N'||jawab=='n') 
 {
cout<<"\nNilai yang dicari : "; 
 cin>>b;
i=1; 
while(nilai[i]!=b) 
 i++;
if(i==n+1) 
 cout<<"\n\tPencarian gagal...";
 else
 {
 cout<<"\n\tNilai yang dicari :"<<nilai[i];
 cout<<"\n\tDi lokasi :"<<i;
 }
 }
 else
 {
salah(); 
linear_search(); 
 }
tanya(); 
}
void binary_search()
{
system("cls"); 
int low,mid,high,flag=0; 
cout<<"\n\nMasukan jumlah nilai : "; 
cin>>n; 
for(i=1;i<=n;i++) 
 {
cout<<"Nilai ["<<i<<"] : "; 
cin>>nilai[i]; 
 }
for(i=1;i<=n;i++) 
 {
for(j=i+1;j<=n;j++) 
 { 
 if(nilai[i]>nilai[j])
 {
 temp=nilai[i];
 nilai[i]=nilai[j]; 
 nilai[j]=temp;
 }
 }
 }
cout<<"\n\nUrutan Ascending data :\n"; 
for(i=1;i<=n;i++) 
cout<<nilai[i]<<" "; 
cout<<"\n\nNilai yang dicari : "; 
cin>>b; 
low=1;high=n; 
while(low<=high&&flag==0) 
 {
mid=(low+high)/2; 
if(nilai[mid]==b) 
 flag=1;
else if(nilai[mid]<b) 
 low=mid+1;
else high=mid-1; 
 }
if(flag==1) 
 {
cout<<"\n\n\tNilai yang dicari : "<<b; 
cout<<"\n\tDi lokasi : "<<mid; 
 }
 else
cout<<"Pencarian gagal..."; 
tanya(); 
}
void fibonacci_search()
{
system("cls"); 
cout<<"\n\nFibonanci search ini mengunakan jumlah data sebanyak 10"<<endl<<endl;
cin>>n; 
for(j=1;j<=n;j++) 
 {
cout<<"Masukan data ke "<<j<<"= "; 
cin>>nilai[j]; 
 } 
for(j=1;j<=n;j++) 
 {
for(y=j+1;y<=n;y++) 
 {
 if(nilai[j]>nilai[y])
 {
 temp=nilai[j];
 nilai[j]=nilai[y];
 nilai[y]=temp;
 }
 } 
 }
cout<<"\n\nUrutan Ascending data :\n"; 
for(j=1;j<=n;j++) 
 { 
 
cout<<nilai[j]<<" "; 
 }
cout<<endl; 
 /*
 a=10+1;
k=2; 
while(a<=n) 
 {
Fib[k]=Fib[k-2]+Fib[k-1]; 
if(Fib[k]==a) 
 {
 Fib[k]=k-1;
 Fk=Fib[k];
 }
cout<<Fib[k]<<" "; 
k++; 
 }*/
Fib[0]=0; 
Fib[1]=1; 
k=0; 
cout<<"Baris Fibonaci terdekat dengan data :"; 
while(Fib[k]<=n+1) 
 {
 if(k>0)
 Fib[k+1]=Fib[k]+Fib[k-1];
cout<<Fib[k]<<" "; 
k++; 
 }
cout<<endl<<"Jumlah data fibonaci = "<<k--<<endl; 
Fk=Fib[k]; 
cout<<"Nilai Fk = "<<Fk<<endl; 
i=Fib[k-1]; 
p=Fib[k-2]; 
q=Fib[k-3]; 
 m=n-Fk+1;
cout<<"i="<<i<<endl<<"p="<<p<<endl<<"q="<<q<<endl<<"m="<<m<<endl; 
cout<<"\nMasukan data yang ingin dicari = "; 
cin>>x; 
if(x>nilai[i]) 
 { 
i=i+m; 
 }
while(i!=0) 
 {
if(x<nilai[i]) 
 {
 if(q==0)
 {
 i=0;
 cout<<"Data tidak ditemukan !!";
 break; 
 }
 i=i-q;
 t=p;
 p=q; 
 q=t-q;
 }
else if(x==nilai[i]||i==9||i==10) 
 {
 cout<<"Data yang dicari ditemukan pada lokasi ke "<<i<<endl;
 break;
 }
else if(x>nilai[i]) 
 {
 if(p==1)
 {
 i=0;
 cout<<"Data tidak ditemukan !!";
 break;
 }
 i=i+q;
 p-=q;
 q-=p;
 }
 
 }
tanya(); 
}
void linear_sort()
{
system("cls"); 
cout<<"\n\nMasukan jumlah data : "; 
cin>>n; 
for(i=1;i<=n;i++) 
{
cout<<"Nilai ["<<i<<"] : "; 
cin>>nilai[i]; 
 }
cout<<"\n\nMetode sorting?"; 
cout<<"\n A :Ascending"; 
cout<<"\n D :Descending"; 
cout<<"\nPilihan Anda : "; 
cin>>jawab; 
if(jawab=='A'||jawab=='a') 
 {
for(i=1;i<=n;i++) 
 {
 for(j=i+1;j<=n;j++)
 {
 if(nilai[i]>nilai[j])
 {
 temp=nilai[i];
 nilai[i]=nilai[j];
 nilai[j]=temp; 
 }
 }
 }
cout<<"\n\nUrutan Ascending data :\n"; 
for(i=1;i<=n;i++) 
 cout<<nilai[i]<<" ";
 }
else if(jawab=='D'||jawab=='d') 
 {
for(i=1;i<=n;i++) 
 {
 for(j=i+1;j<=n;j++)
 {
 if(nilai[i]<nilai[j])
 {
 temp=nilai[i];
 nilai[i]=nilai[j];
 nilai[j]=temp;
 }
 }
 }
cout<<"\n\nUrutan Descending data :\n"; 
for(i=1;i<=n;i++) 
 cout<<nilai[i]<<" ";
 }
 else
 {
salah(); 
linear_sort(); 
 }
tanya(); 
}
void bubble_sort()
{
int exc,loop,j=1; 
system("cls"); 
cout<<"\n\nMasukan jumlah data : "; 
cin>>n; 
for(i=1;i<=n;i++) 
 {
cout<<"Nilai ["<<i<<"] : "; 
cin>>nilai[i]; 
 }
cout<<"\n\nMetode sorting?"; 
cout<<"\n A :Ascending"; 
cout<<"\n D :Descending"; 
cout<<"\nPilihan Anda : "; 
cin>>jawab; 
cout<<endl<<endl; 
if(jawab=='A'||jawab=='a') 
 {
for(loop=1;loop<=n;loop++) 
 { 
 cout<<"Looping ke : "<<loop;
 cout<<endl;
 exc=0;
 for(j=1;j<n;j++) 
 {
 if(nilai[j]>nilai[j+1])
 {
 swap(nilai[j],nilai[j+1]);
 exc++;
 for(i=1;i<=n;i++)
 cout<<nilai[i]<<" ";
 cout<<endl;
 }
 }
 if(exc==0)
 cout<<"Tidak ada eksekusi berlangsung...\n";
 cout<<"Akhir looping ke : "<<loop;
 cout<<"\n----------------------------\n\n";
 getch();
 }
cout<<"\n\nUrutan Ascending data :\n"; 
for(i=1;i<=n;i++) 
 cout<<nilai[i]<<" ";
 }
else if(jawab=='D'||jawab=='d') 
 {
for(loop=1;loop<=n;loop++) 
 {
 cout<<"Looping ke : "<<loop;
 cout<<endl;
 exc=0;
 for(j=1;j<n;j++)
 {
 if(nilai[j]<nilai[j+1])
 {
 swap(nilai[j],nilai[j+1]);
 exc++;
 for(i=1;i<=n;i++)
 cout<<nilai[i]<<" ";
 cout<<endl;
 }
 }
 if(exc==0) 
 cout<<"\nTidak ada eksekusi berlangsung...\n";
 cout<<"Akhir looping ke : "<<loop;
 cout<<"\n----------------------------\n\n";
 getch();
 }
cout<<"\n\nUrutan Descending data :\n"; 
for(i=1;i<=n;i++) 
 cout<<nilai[i]<<" ";
 }
 else 
 {
salah(); 
bubble_sort(); 
 } 
 
tanya(); 
}
void swap(int &value1,int &value2)
{
int holdValue=value1; 
value1=value2; 
value2=holdValue; 
}
void tanya()
{
cout<<"\n\nProgram telah selesai"; 
cout<<"\nAnda ingin mengulang? Y/N : "; 
cin>>jawab; 
if(jawab=='Y'||jawab=='y') 
 menu();
else if(jawab=='N'||jawab=='n') 
 {
cout<<setw(50)<<"\n\n\t========================="; 
cout<<setw(50)<<"\n\t| Searching And Sorting |"; 
cout<<setw(50)<<"\n\t|-----------------------|"; 
cout<<setw(50)<<"\n\t| Oleh : Tim Dosen 	 |"; 
cout<<setw(50)<<"\n\t========================="; 
cout<<setw(50)<<"\n\t Universitas Muhammadiyah Semarang\n"; 
 }
 else
 {
salah(); 
 tanya();
 }
}
void salah()
{
cout<<"\n\n\tFatal Error"; 
cout<<"\n\tInput unrecognized"; 
cout<<"\n\tSystem back to the last action"; 
cout<<"\n\tPress any key to continue..."; 
getch();
}