// Consider   telephone   book   database   of   N   clients.
// Make   use   of   a   hash   table implementation to quickly look up client‘s telephone number.
// Make use of two collision handling techniques and compare them using number of comparisons required to find a set of telephone numbers

#include <iostream>
using namespace std;

class client
{
private:
    int ID;
    string Name;
    int Mno;

public:
    client()
    {
        ID = -1;
        Name = "";
        Mno = 0;
    }

    void getdata()
    {
        cout << "Enter Client Details : " << endl;
        cout << "Enter Id : ";
        cin >> ID;
        cout << "Enter Name : ";
        cin >> Name;
        cout << "Enter Mobile/Telephone Number : ";
        cin >> Mno;
    }

    void showdata()
    {
        cout << ID << " \t " << Name << " \t " << Mno << endl;
    }

    friend class DataBase;
};

class DataBase
{
private:
    client HashTable[10];
    int n;

public:
    DataBase()
    {
        n = 0;
        cout << "Empty HashTable created " << endl;
        cout << "======================================================" << endl;
        cout << "Index \t ID \t Name \t Mobile No. " << endl;
        cout << "======================================================" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << " \t ";
            HashTable[i].showdata();
        }
        cout << "======================================================" << endl;
    }

    int HashFunc(client c)
    {
        int ind;
        ind = c.ID % 10;
        return ind;
    }

    void insertData()
    {
        client c;
        c.getdata();
        int index = HashFunc(c);
        if (HashTable[index].ID == -1)
        {
            HashTable[index] = c;
            n++;
        }
        else // Without Replacemnet
        {
            cout << "collision occured" << endl;
            cout << "Using Linear Probing Without Replacement" << endl;
            while (HashTable[index].ID != -1)
            {
                index = index + 1;
                if (index == 10)
                {
                    index = 0;
                }
                if (index == HashFunc(c))
                {
                    cout << "Hashtable Full!!!!" << endl;
                    break;
                }
            }

            if (HashTable[index].ID == -1)
            {
                HashTable[index] = c;
            }
        }

        /*else // With Replacemnet
        {
            cout << "collision occured" << endl;
            cout << "Using Linear Probing With Replacement" << endl;

            if (index != HashFunc(HashTable[index]))
            {
                client temp;
                temp = HashTable[index];
                HashTable[index] = c;
                c = temp;
            }

            while (HashTable[index].ID != -1)
            {
                index = index + 1;
                if (index == 10)
                {
                    index = 0;
                }
                if (index == HashFunc(c))
                {
                    cout << "Hashtable Full!!!!" << endl;
                    break;
                }
            }

            if (HashTable[index].ID == -1)
            {
                HashTable[index] = c;
            }
        }*/
    }

    void showData()
    {
        cout << "======================================================" << endl;
        cout << "Index \t ID \t Name \t Mobile No. " << endl;
        cout << "======================================================" << endl;
        for (int i = 0; i < 10; i++)
        {
            cout << i << " \t ";
            HashTable[i].showdata();
        }
        cout << "======================================================" << endl;
    }

    void search()
    {
        int iD;
        cout << "Enter the Id : ";
        cin >> iD;
        if (HashTable[iD % 10].ID == -1)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            if (HashTable[iD % 10].ID == iD)
            {
                cout << "Found" << endl;
                HashTable[iD % 10].showdata();
            }
            else
            {
                cout << "Not Found " << endl;
            }
        }
    }
};

int main()
{
    DataBase db;
    int a;
    while (1)
    {
        cout << "1.insert 2.show 3.search 0.Exit" << endl;
        cin >> a;
        if (a == 0)
        {
            return 0;
        }
        else if (a == 1)
        {
            cout << "Number of elments to insert" << endl;
            int n;
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                db.insertData();
            }
        }
        else if (a == 2)
        {
            db.showData();
        }
        else if (a == 3)
        {
            db.search();
        }
        else
        {
            cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
