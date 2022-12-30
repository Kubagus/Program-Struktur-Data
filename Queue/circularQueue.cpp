// Program to implement circular queue using Array
#include<iostream>
#define maxSize 4

using namespace std;
// Globally declared queue and front and rear
string queue[maxSize];
int front = -1;
int rear = -1;

// Function to insert the element in queue
void enqeue(string item)
{
    if(front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else if(((rear + 1) % maxSize) == front)
    {
        cout << "\nAntrian Penuh !!" << endl;
    }
    else
    {
        rear = (rear + 1) % maxSize;
        queue[rear] = item;
    }
}

// Function to delete the element from queue [FIFO]
void dequeue()
{
    if(front == -1 && rear == -1)
    {
        cout << "\nAntrian Kosong" << endl;
    }
    else if(front == rear)
    {
        cout << "\nAntrian yang dihapus: " << queue[front] << endl;
        front = rear = -1;
    }
    else
    {
        cout << "\nAntrian yang dihapus: " << queue[front] << endl;
        front = (front + 1) % maxSize;
    }
}

// Function to display the first element of queue
void peek()
{
    if(front == -1 && rear == -1)
    {
        cout << "\nAntrian kosong" << endl;
    }
    else
    {
        cout << "\nAntrian paling depan (front) adalah: " << queue[front] << endl;
    }
}

// Function to display the elements of queue
void display()
{
    int temp = front;

    if(front == -1 && rear == -1)
    {
        cout << "\nAntrian kosong" << endl;
    }
    else
    {
        cout << endl;
        cout << "Antrian: " << endl;
        while(temp != rear)
        {
            cout << queue[temp] << " ";
            temp = (temp + 1) % maxSize;
        }    
        cout << queue[rear] << " " << endl;
    }
}

int main()
{
    string item;
    int choice = 1;

    // Using while loop so that user can use this program according to his/her choice
    while(choice != 5)
    {
        cout << "\n*** CIRCULAR QUEUE ***" << endl;
        cout << "1. Masukkan antrian" << endl;
        cout << "2. Keluarkan antrian" << endl;
        cout << "3. PEEK" << endl;
        cout << "4. DISPLAY" << endl;
        cout << "5. EXIT" << endl;

        cout << "Pilih menu: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "Masukkan data: ";
                cin >> item;
                enqeue(item);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            default:
            {
                if(choice > 5)
                {
                    cout << "\nSilakan pilih menu yang benar." << endl;
                }
            }
        }
    }
    return 0;
}