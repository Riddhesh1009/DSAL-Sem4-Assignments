// Read the marks obtained by students of second year in an online examination of 
// particular subject. Find out maximum and minimum marks obtained in that subject. Use 
// heap data structure. Analyze the algorithm

#include <stdio.h>
#include <iostream>
using namespace std;

int const SIZE = 100;
class Heap
{
private:
    int data[SIZE];
    int heapsize;

public:
    Heap()
    {
        heapsize = 0;
    }

    void insert(int value);
    void insertMax(int value);
    void reHeapUp(int child);
    void disply();
    void remove();
    void reHeapDown(int parent);
    void mini();
    void maxi();
};

void Heap::insert(int value)
{
    int child = heapsize;
    heapsize = heapsize + 1;
    data[child] = value;
    reHeapUp(child);
}

void Heap::insertMax(int value) //For Maximum
{
    int child = heapsize;
    heapsize = heapsize + 1;
    data[child] = value;
    
    int parent = (child - 1) / 2;
    while (data[child] > data[parent] && child > 0)   
    {
        int temp = data[parent];
        data[parent] = data[child];
        data[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }

}

void Heap::reHeapUp(int child)
{
    int parent = (child - 1) / 2;
    while (data[child] < data[parent] && child > 0)
    {
        int temp = data[parent];
        data[parent] = data[child];
        data[child] = temp;
        child = parent;
        parent = (child - 1) / 2;
    }
}

void Heap::disply()
{
    if (heapsize == 0)
    {
        cout << "Heap is Empty !!" << endl;
    }
    else
    {
        cout << "The heap is : ";
        for (int i = 0; i < heapsize; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
}

void Heap::remove()
{
    int parent = 0;
    if (parent != heapsize - 1)
    {
        data[parent] = data[heapsize - 1];
    }
    heapsize = heapsize - 1;
    reHeapDown(parent);
    disply();
}

void Heap::reHeapDown(int parent)
{
    int sc;
    int lc = 2 * parent + 1;
    int rc = 2 * parent + 2;
    while (data[parent] > data[lc] || data[parent] > data[rc] && rc < heapsize)
    {

        if (data[lc] < data[rc])
        {
            sc = lc;
        }
        else
        {
            sc = rc;
        }
        int temp = data[parent];
        data[parent] = data[sc];
        data[sc] = temp;
        parent = sc;
        lc = 2 * parent + 1;
        rc = 2 * parent + 2;
    }
}

void Heap::mini()
{
    cout<<"Minimum marks in the subject are : "<<data[0]<<endl;
}

void Heap::maxi()
{
    cout<<"Maximum marks in the subject are : "<<data[0]<<endl;
}

int main()
{
    Heap h,max;
    int c;
    while (1)
    {
        cout << "1. Insert 2.delete 3.Minimum Marks 4. Maximum Marks 5.Display 0. Exit" << endl;
        cin >> c;
        if (c == 0) 
        {
            return 0;
        }
        else if (c == 1) // insert
        {
            int i;
            cout << "Enter the Value to insert" << endl;
            cin >> i;
            h.insert(i);
            max.insertMax(i);
        }

        else if (c == 2) // delete
        {
            h.remove();
        }

        else if (c == 3) // mini
        {
            h.mini();
        }

        else if (c == 4) // max
        {
            max.maxi();
        }

        else if (c == 5) // nothing
        {
            h.disply();
        }

        else
        {
            cout << "Wrong Choice Entered !!" << endl;
        }
    }

    return 0;
}
