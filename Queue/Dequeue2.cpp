#include<iostream>
using namespace std;
#define SIZE 5
string a[20];
class dequeue {
   int f,r;
   public:
      dequeue();
      void insert_at_beg(string);
      void insert_at_end(string);
      void delete_fr_front();
      void delete_fr_rear();
      void show();
};
dequeue::dequeue() {
   f=-1;
   r=-1;
}
void dequeue::insert_at_end(string i) {
   if(r>=SIZE-1) {
      cout<<"\nAntrian pernah diisi. Hapus akhir untuk kembali mengisi antrian akhir!!!!";
   } else {
      if(f==-1) {
         f++;
         r++;
      } else {
         r=r+1;
      }
      a[r]=i;
      cout<<"\nData yang dimasukkan adalah: "<<a[r];
   }
}
void dequeue::insert_at_beg(string i) {
   if(f==-1) {
      f=0;
      a[++r]=i;
      cout<<"\nData yang dimasukkan adalah: "<<i;
   } else if(f!=0) {
      a[--f]=i;
      cout<<"\nData yang dimasukkan adalah: "<<i;
   } else {
      cout<<"\nAntrian pernah diisi. Hapus awal untuk kembali mengisi antrian awal";
   }
}
void dequeue::delete_fr_front() {
   if(f==-1) {
      cout<<"\nTidak ada yang dihapus. Antrian kosong.";
      return;
   }
   else {
      cout<<"\nData yang dihapus adalah: "<<a[f];
      if(f==r) {
         f=r=-1;
         return;
      } else
         f=f+1;
      }
   }
   void dequeue::delete_fr_rear() {
      if(f==-1) {
         cout<<"\nTidak ada yang dihapus. Antrian kosong.";
         return;
      }
      else {
         cout<<"\nData yang dihapus adalah: "<<a[r];
         if(f==r) {
            f=r=-1;
         } else
            r=r-1;
      }
   }
   void dequeue::show() {
      if(f==-1) {
         cout<<"\nAntrian kosong.";
      } else {
         for(int i=f;i<=r;i++) {
            cout<<a[i]<<" ";
         }
      }
   }
   int main() {
      int c;
      string i;
      dequeue d;
      cout<<"\n\n1.Insert kiri\n";
      cout<<"2.Insert kanan\n";
      cout<<"3.show\n";
      cout<<"4.Hapus kiri\n";
      cout<<"5.Hapus kanan\n";
      cout<<"6.exit\n";
      do{
      cout<<"\n\nPilih Menu: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"\nMasukkan data di awal antrian: ";
            cin>>i;
            d.insert_at_beg(i);
         break;
         case 2:
            cout<<"\nMasukkan data di akhir antrian: ";
            cin>>i;
            d.insert_at_end(i);
         break;
         case 3:
         	cout << "Daftar Antrian" << endl;
            d.show();
         break;
         case 4:
            d.delete_fr_front();
         break;
         case 5:
            d.delete_fr_rear();
         break;
         case 6:
            exit(1);
         break;
         default:
            cout<<"Pilihan salah.";
         break;
      }
   } while(c!=7);
}