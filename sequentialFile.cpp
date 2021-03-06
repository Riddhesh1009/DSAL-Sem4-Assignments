/*Department maintains a student information. The file contains roll number, name, division
and address. Allow user to add, delete information of student. Display information of
particular employee. If record of student does not exist an appropriate message is displayed.
If it is, then the system displays the student details. Use sequential file to main the data.*/
#include <iostream>
// #include <bits/stdc++.h> be sure this header file is not allowed in exam
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

class Student
{
    char Name[10], Address[20];
    int Roll_No;
    char Div;

public:
    Student()
    {
        Name[0] = '\0';
        Address[0] = '\0';
        Roll_No = -1;
        Div = '\0';
    }
    void get_Data();
    void show_data();
    int return_Roll() { return Roll_No; } // this used when we check for searching and deleting
};

void Student::get_Data()
{
    cout << "\nEnter Student Data";
    cout << "\nName: ";
    cin >> Name;
    cout << "\nAddress: ";
    cin >> Address;
    cout << "\nRoll Number: ";
    cin >> Roll_No;
    cout << "\nDiv(A/B/C): ";
    cin >> Div;
}
void Student::show_data()
{
    cout << "\n";
    cout << Div << "\t" << Roll_No << "\t" << Name << "\t" << Address << endl;
}

class Seq_File

{
   

public:
    void Create();
    void Display();
    void Insert();
    void Delete();
    int Search(int);

};

void Seq_File::Create()
{
    ofstream ofs;
    Student S;
    int i, n;
    
    ofs.open("studentData.txt", ios::app);

    if (ofs)
    {
        cout << "\nHow many student you have to add\n";
        cin >> n;
        for (i = 0; i < n; i++)
        {
            S.get_Data();
            ofs.write((char *)(&S), sizeof(S)); // write all data in the file
        }

        ofs.close();
    }
    else
        cout << "\nFile creation Error";
}

void Seq_File::Delete()
{
    int Roll;
    cout << "Enter roll number that you want to delete: " << endl;
    cin >> Roll;
    ifstream ifs;
    ofstream ofs;
    Student S;
    int Flag = 0;
    ifs.open("studentData.txt");  // first main file
    ofs.open("Temp.Txt"); // then create a temporary file
    if (ifs && ofs)       // when both are open
    {
        ifs.read((char *)(&S), sizeof(S)); // read the data from them
        while (!ifs.eof())
        {
            if (Roll == S.return_Roll())
            {
                S.show_data();
                Flag = 1;
            }
            else
            {
                ofs.write((char *)(&S), sizeof(S)); // copy all data from main file except deleted data in temp file
            }
            ifs.read((char *)(&S), sizeof(S));
        }
        if (Flag == 0)
        {
            cout << "Roll No. " << Roll << " not present \n";
        }

        ifs.close(); // file both files
        ofs.close();
        remove("studentData.txt");             // remove main file
        rename("Temp.Txt", "studentData.txt"); // now rename temporary file as main file name
    }
    else
        cout << "File opening Error";
}

void Seq_File::Display()
{
    ifstream ifs;
    Student S;
    ifs.open("studentData.txt");
    if (ifs)
    {

        cout << "__________________________________________\n";
        cout << "Div\tRollNo\tName\tAddress" << endl;
        cout << "__________________________________________\n";
        ifs.read((char *)(&S), sizeof(S));
        while (!ifs.eof())
        {
            S.show_data();
            ifs.read((char *)(&S), sizeof(S));
        }
        ifs.close();
    }
    else
        cout << "\nFile opening Error";
}

void Seq_File::Insert()
{
    ofstream File;
    Student S;
    File.open("studentData.txt", ios::app); // insert data at last
    if (File)
    {
        S.get_Data();                        // get data
        File.write((char *)(&S), sizeof(S)); // write that data in the file
        File.close();
    }
    else
        cout << "File opening Error";
}

int Seq_File::Search(int Roll)
{
    ifstream File;
    Student S;
    int Flag = 0;
    File.open("studentData.txt");
    if (File)
    {
        File.read((char *)(&S), sizeof(S)); // start reading data
        while (!File.eof())
        {
            if (Roll == S.return_Roll())
            {
                S.show_data(); // display data
                Flag = 1;
            }
            File.read((char *)(&S), sizeof(S));
        }
        File.close();
    }
    else
        cout << "\nFile opening Error";
    return Flag;
}

int main()
{
    Seq_File sFile;
    int key, Choice;
    while (1)
    {

        cout << "\n1: Create Database\n2: Display Database\n3: Insert a record\n4: Delete a Record\n5: Search a record\n6: Exit\nEnter your choice: ";
        cin >> Choice;
        switch (Choice)
        {
        case 1:
            sFile.Create();
            break;
        case 2:
            sFile.Display();
            break;
        case 3:
            sFile.Insert();
            break;
        case 4:
            sFile.Delete();
            break;
        case 5:
            cout << "\nEnter Roll No to Search : ";
            cin >> key;
            if (sFile.Search(key)==0)
                cout << "\nRecord NOT Found!!!!"<<endl;
            break;

        case 6:
            return 0;
        }
        
    }
}
