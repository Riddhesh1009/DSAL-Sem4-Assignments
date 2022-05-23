// Implement all the functions of a dictionary (ADT) using hashing and handle collisions
// using chaining with / without replacement.
// Data: Set of (key, value) pairs, Keys are mapped to values, Keys must be comparable,
// Keys must be unique. Standard Operations: Insert(key, value), Find(key), Delete(key)

#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

class Student;

class Node
{
    string word;
    string meaning;
    Node *next;

public:
    Node()
    {
        word = "";
        meaning = "";
        next = NULL;
    }
    Node(string word, string meaning)
    {
        this->word = word;
        this->meaning = meaning;
        next = NULL;
    }
    friend class Student;
};

class Student
{
    Node *hashTable[SIZE];

public:
    Student()
    {
        for (int i = 0; i < SIZE; i++)
        {
            hashTable[i] = NULL;
        }
    }

    int hashFunction(string);
    void insert(string, string);
    void search(string);
    void remove(string);
    void displayDatabase();
};

int Student ::hashFunction(string word)
{
    int key = 0;

    for (int i = 0; i < word.length(); i++)
    {
        key = key + (int)word[i];
    }
    cout << endl
         << key << endl;

    return key % SIZE;
}

void Student ::insert(string word, string meaning)
{

    int loc = hashFunction(word);
    Node *temp;
    Node *pnew;
    pnew = new Node(word, meaning);

    if (hashTable[loc] == NULL)
    {
        hashTable[loc] = pnew;
    }
    else
    {
        temp = hashTable[loc];
        // compulsoriy check the temp next only, or it will check any randome memory location
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = pnew;
    }
    cout << "Record Inserted!" << endl;
}

void Student ::search(string word)
{
    Node *temp;
    bool found = 0;
    int loc = hashFunction(word);

    if (hashTable[loc]->word == word)
    {
        cout << "\nStudent Found ->" << endl;
        cout << "Word : " << hashTable[loc]->word << endl;
        cout << "Meaning : " << hashTable[loc]->meaning << endl;
    }
    else
    {
        temp = hashTable[loc];
        while (temp->next != NULL)
        {
            temp = temp->next;
            if (temp->word == word)
            {
                cout << "\nStudent Found ->" << endl;
                cout << "Word : " << temp->word << endl;
                cout << "Meaning : " << temp->meaning << endl;
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            cout << "Not found!!!!!" << endl;
        }
    }
}

void Student ::remove(string word)
{
    Node *temp;
    Node *prev; // previous pointer

    int loc = hashFunction(word);
    if (hashTable[loc]->word == word)
    {
        cout<<hashTable[loc]->word<<" is Deleted!!"<<endl;
        //  temp = hashTable[loc];
        hashTable[loc] = hashTable[loc]->next;
        //  temp->next = NULL;
    }
    else
    {
        temp = hashTable[loc]->next;
        prev = hashTable[loc];
        while (temp != NULL)
        {
            if (temp->word == word)
            {
                cout<<temp->word<<" is Deleted!!"<<endl;
                // while (prev->next == temp)
                // {
                //     prev = prev->next;
                // }
                prev->next = temp->next;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
            prev = prev->next;
        }
    }
}

void Student ::displayDatabase()
{
    Node *temp;
    cout << "Student Database =>" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        temp = hashTable[i];
        cout << i << " -> ";
        while (temp != NULL)
        {
            cout << "[ " << temp->word << " , " << temp->meaning << " ] - ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main()
{
    Student s;

    int choice;
    string word, meaning;
    do
    {
        cout << "\n1) Insert Record"
             << "\n2) Search Record"
             << "\n3) Delete Record"
             << "\n4) Display Record Database"
             << "\n5) Exit" << endl;
        cout << "\nEnter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter Word : ";
            cin >> word;
            cout << "\nEnter Meaning : ";
            cin >> meaning;
            s.insert(word, meaning);
            break;
        case 2:
            cout << "\nEnter Word to be search : ";
            cin >> word;
            s.search(word);
            break;
        case 3:
            cout << "\nEnter Word to be Deleted : ";
            cin >> word;
            s.remove(word);
            break;
        case 4:
            s.displayDatabase();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "\nInvalid Choice!" << endl;
            break;
        }

    } while (choice != 5);

    return 0;
}
