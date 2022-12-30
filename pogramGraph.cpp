#include <cstdlib>
 #include <iostream>
 #include <fstream>
 
 
 using namespace std;
 
 class kruskal
 {
 private:
 int n ;//no of nodes
 int noe; //no edges in the graph
 int graph_edge[100][4];
 
 int tree[10][10];
 
 int sets[100][10];
 int top[100];
 
 public:
 int read_graph();
 void initialize_span_t();
 void sort_edges();
 void algorithm();
 int find_node(int );
 void print_min_span_t();
 };
 
 int kruskal::read_graph()
 {
 cout << "----------------------------------------------------------------" <<endl;
 cout << " PROGRAM ALGORITMA KRUSKAL " <<endl;
 cout << " INFORMATIKA UNIMUS " <<endl;
 cout << "----------------------------------------------------------------" <<endl;
 cout<<endl;
 cout << " Banyak titik graph : "; cin >> n;
 noe=0;
 
 cout<<"\n Jarak antar tiap titik:\n";
 
 for(int i=1;i<=n;i++)
 {
 for(int j=i+1;j<=n;j++)
 {
 cout << " ("<<i<<" , "<<j<<") = ";
 float w;
 cin>>w;
 if(w!=0)
 {
 noe++;
 
 graph_edge[noe][1]=i;
 graph_edge[noe][2]=j;
 graph_edge[noe][3]=w;
 }
 }
 }
 }
 
 void kruskal::sort_edges()
 {
 /** Sort the edges using bubble sort in increasing order******/
 
 for(int i=1;i<=noe-1;i++)
 {
 for(int j=1;j<=noe-i;j++)
 {
 if(graph_edge[j][3]>graph_edge[j+1][3])
 {
 int t=graph_edge[j][1];
 graph_edge[j][1]=graph_edge[j+1][1];
 graph_edge[j+1][1]=t;
 
 t=graph_edge[j][2];
 graph_edge[j][2]=graph_edge[j+1][2];
 graph_edge[j+1][2]=t;
 
 t=graph_edge[j][3];
 graph_edge[j][3]=graph_edge[j+1][3];
 graph_edge[j+1][3]=t;
 }
 }
 }
 
 cout<<"\n\n Setelah Jarak diurutkan adalah ::\n";
 
 for(int i=1;i<=noe;i++)
 cout << " (" << graph_edge[i][1] << " , "<<graph_edge[i][2] << " ) = " <<graph_edge[i][3]<<endl;
 }
 
 void kruskal::algorithm()
 {
 
 for(int i=1;i<=n;i++)
 {
 sets[i][1]=i;
 top[i]=1;
 }
 
 cout<<"\n Rentang Yang di Pakai\n\n";
 
 for(int i=1;i<=noe;i++)
 {
 int p1=find_node(graph_edge[i][1]);
 int p2=find_node(graph_edge[i][2]);
 
 if(p1!=p2)
 {
 cout<<"Rentang yg masuk ke pohon ::"
 <<" < "<<graph_edge[i][1]<<" , "
 <<graph_edge[i][2]<<" > "<<endl<<endl;
 
 tree[graph_edge[i][1]][graph_edge[i][2]]=graph_edge[i][3];
 tree[graph_edge[i][2]][graph_edge[i][1]]=graph_edge[i][3];
 
 // Mix the two sets
 
 for(int j=1;j<=top[p2];j++)
 {
 top[p1]++;
sets[p1][top[p1]]=sets[p2][j];
 }
 
 top[p2]=0;
 }
 else
 {
 cout<<"Jika "
 <<" < "<<graph_edge[i][1]<<" , "
 <<graph_edge[i][2]<<" > "<<"di masukkan, maka terbentuk siklus. jadi di hapus\n\n";
 }
 }
 }
 
 int kruskal::find_node(int n)
 {
 for(int i=1;i<=noe;i++)
 {
 for(int j=1;j<=top[i];j++)
 {
 if(n==sets[i][j])
 return i;
 }
 }
 
 return -1;
 }
 
 
 int main(int argc, char *argv[])
 {
 kruskal obj;
 obj.read_graph();
 obj.sort_edges();
 obj.algorithm();
 
 system("PAUSE");
 return EXIT_SUCCESS;
}