#include<iostream>
using namespace std;
#define SIZE 10
class dequeue {
   int a[20],f,r;
   public:
      dequeue();
      void insert_at_beg(int);
      void insert_at_end(int);
      void delete_fr_front();
      void delete_fr_rear();
      void show();
};
dequeue::dequeue() {
   f=-1;
   r=-1;
}
void dequeue::insert_at_end(int i) {
   if(r>=SIZE-1) {
      cout<<"\ninsertion is not possible, overflow!!!!";
   } else {
      if(f==-1) {
         f++;
         r++;
      } else {
         r=r+1;
      }
      a[r]=i;
      cout<<"\nInserted item is: "<<a[r];
   }
}
void dequeue::insert_at_beg(int i) {
   if(f==-1) {
      f=0;
      a[++r]=i;
      cout<<"\ninserted element is: "<<i;
   } else if(f!=0) {
      a[--f]=i;
      cout<<"\ninserted element is: "<<i;
   } else {
      cout<<"\ninsertion is not possible, overflow!!!";
   }
}
void dequeue::delete_fr_front() {
   if(f==-1) {
      cout<<"\ndeletion is not possible::dequeue is empty";
      return;
   }
   else {
      cout<<"\nthe deleted element is: "<<a[f];
      if(f==r) {
         f=r=-1;
         return;
      } else
         f=f+1;
      }
   }
   void dequeue::delete_fr_rear() {
      if(f==-1) {
         cout<<"\ndeletion is not possible::dequeue is empty";
         return;
      }
      else {
         cout<<"\nthe deleted element is:"<<a[r];
         if(f==r) {
            f=r=-1;
         } else
            r=r-1;
      }
   }
   void dequeue::show() {
      if(f==-1) {
         cout<<"\nDequeue is empty";
      } else {
         for(int i=f;i<=r;i++) {
            cout<<a[i]<<" ";
         }
      }
   }
   int main() {
      int c,i;
      dequeue d;
      do{
      cout<<"\n\n1.insert at beginning\n";
      cout<<"2.insert at end\n";
      cout<<"3.show\n";
      cout<<"4.deletion from front\n";
      cout<<"5.deletion from rear\n";
      cout<<"6.exit\n";
      cout<<"enter your choice: ";
      cin>>c;
      switch(c) {
         case 1:
            cout<<"\nenter the element to be inserted: ";
            cin>>i;
            d.insert_at_beg(i);
         break;
         case 2:
            cout<<"\nenter the element to be inserted: ";
            cin>>i;
            d.insert_at_end(i);
         break;
         case 3:
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
            cout<<"invalid choice";
         break;
      }
   } while(c!=7);
}