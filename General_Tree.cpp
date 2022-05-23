// A book consists of chapters, chapters consist of sections and sections consist of 
// subsections. Construct a tree and print the nodes. Find the time and space requirements 
// of your method.



#include <iostream>
//#include <stdlib.h>
using namespace std;

const int N=200;

class Node
{
    string name;
    int count;
    Node *child[N];
    friend class general;
};

class general
{
    Node *root;
public:
    void insert();
    void display();
    general()
    {
        root = NULL;
    }
};

void general::insert()
{
    root = new Node();
    cout << "Enter the name of book" << endl;
    cin >> root->name;
    cout << "Enter the no of chapters" << endl;
    cin >> root->count;
    for (int i = 0; i < root->count; i++)
    {
        root->child[i] = new Node();
        cout << "Enter the name of chapter "<<i+1<<" : " << endl;
        cin >> root->child[i]->name;

        cout << "Enter the number of sections : " << endl;
        cin >> root->child[i]->count;

        for (int j = 0; j < root->child[i]->count; j++)
        {
            root->child[i]->child[j] = new Node();
            cout << "Enter the name of section "<<j+1<<" : "<< endl;
            cin >> root->child[i]->child[j]->name;

            cout << "Enter the number of subsections" << endl;
            cin >> root->child[i]->child[j]->count;

            for (int k = 0; k < root->child[i]->child[j]->count; k++)
            {
                root->child[i]->child[j]->child[k] = new Node();
                cout << "Enter the name of subsection "<<k+1<<" : " << endl;
                cin >> root->child[i]->child[j]->child[k]->name;
            }
        }
    }
}

void general::display()
{
    if (root != NULL)
    {
        cout << "**Book Contents**" << endl;
        cout << "Book name is"<<endl<<" >>>>>>" << root->name<<"<<<<<<" << endl;
        for (int i = 0; i < root->count; i++)
        {
            cout << "--" << root->child[i]->name << endl;
            for (int j = 0; j < root->child[i]->count; j++)
            {
                cout << "--------" << root->child[i]->child[j]->name << endl;
                for (int k = 0; k < root->child[i]->child[j]->count; k++)
                {
                    cout << "------------" << root->child[i]->child[j]->child[k]->name << endl;
                }
            }
        }
    }
}

int main()
{
    general g;
    int ch;

    while(1)
    {
        cout << "~~ MENU ~~" << endl;
        cout << "1. Insert." << endl;
        cout << "2. Display." << endl;
        cout << "0. EXIT." << endl;
        cout << "Enter the choice:" << endl;
        cin >> ch;
        if (ch==0)
        {
            return 0;
        }
        else if(ch==1)
        {
            g.insert();

        }
        else if(ch==2)
        {
            g.display();

        }
        else 
        {
            cout<<"Wrong choice"<<endl;
        }
    }   
              

    return 0;
}
