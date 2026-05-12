#include <iostream>
#include <bits/stdc++.h>
#include "header/functions.h"
using namespace std;

struct students{
    string studentName;
    string dob;
    string cls;
    string sec;
};
void functionList(){
    cout << "\n===============================================================" << endl;
    cout << "                   STUDENT MANAGEMENT SYSTEM" << endl;
    cout << "===============================================================" << endl;

    cout << "Enter the function:"<< endl;

    cout << "1.Add Student Information" << endl;
    cout << "2.Update Student Information" << endl;
    cout << "3.Delete Student Information" << endl;
    cout << "4.Display Student Information" << endl;
}
void addStudentInformation(){
    map<int,students> studentDB;
    int rollNo;
    char choice = 'y';

     while(choice == 'y' || choice == 'Y'){

        students s;

        cout << "----------------Enter the Student details----------------" << endl;
        cout << "\nEnter the Student Roll Number:";
        cin >> rollNo;

        cout << "\n Enter the Student Name:";
        cin >> s.studentName;
        cin.ignore();

        cout << "\n Enter the Student Date-of-Birth:";
        cin >> s.dob;
        cin.ignore();

        cout << "\n Enter the Student Class:";
        getline(cin,s.cls);

        cout << "\n Enter the Student Section:";
        cin >> s.sec;
        cin.ignore();

        studentDB[rollNo] = s;

        cout << "Do You want to add another Student data:" ;
        cin >> choice;
    }

    ofstream file("studentDB.txt",ios::app);

    if(file.is_open()){
        for(auto const& entry : studentDB){
            file << entry.first << " "
                 << entry.second.studentName << " "
                 << entry.second.dob << " "
                 << entry.second.cls << " "
                 << entry.second.sec << endl;
        }
        file.close();
        cout << "\nAll results are successfully saved";
    }else{
            cout << "\nFile is not open!"; 
        }
}
void update(){
    int rollNo;

    map<int,students> studentDB;

    ifstream file("studentDB.txt");
    students s;

    if(file.is_open()){
        while(file >> rollNo >> s.studentName >> s.dob >> s.cls >> s.sec){
            studentDB[rollNo] = s;
        }
        file.close();
    }

    cout << "\nEnter the roll number to Update: ";
    cin >> rollNo;

    if(studentDB.find(rollNo) != studentDB.end()){
        cout << "\nThe Student data is found for: " << studentDB[rollNo].studentName << endl;

        cout << "\nEnter the New Name: ";
        cin >> studentDB[rollNo].studentName;

        cout << "\nEnter the New DOB: ";
        cin >> studentDB[rollNo].dob;

        cout << "\nEnter the New Class: ";
        cin >> studentDB[rollNo].cls;

        cout << "\nEnter the New Section: ";
        cin >> studentDB[rollNo].sec;

        ofstream file("studentDB.txt",ios::trunc);
        if(file.is_open()){
            for(auto const& entry : studentDB){
                file << entry.first << " "
                    << entry.second.studentName << " "
                    << entry.second.dob << " "
                    << entry.second.cls << " "
                    << entry.second.sec << endl;
            }
        file.close(); 
            cout << "The Record has successfully Updated";
        }
    }else{
        char option;
        cout << "\nThe student data is not found for " << rollNo << endl;
        cout << "would you like to add data(y/n): ";
        cin >> option;
        if(option == 'y' || option == 'Y'){
            addStudentInformation();
        }
    }
}
void deleteStudentData(){
    int rollNo;

    map<int,students> studentDB;

    ifstream file("studentDB.txt");
    students s;

    if(file.is_open()){
        while(file >> rollNo >> s.studentName >> s.dob >> s.cls >> s.sec){
            studentDB[rollNo] = s;
        }
        file.close();
    }

    cout << "\nEnter the roll number to delete: ";
    cin >> rollNo;

    auto it = studentDB.find(rollNo);

    if(it != studentDB.end()){
        studentDB.erase(it);
        cout << "The Student Data has successfully erased" << endl;

        ofstream file("studentDB.txt",ios::trunc);

        if(file.is_open()){
            for(auto const& stud : studentDB){
                file << stud.first << " "
                     << stud.second.studentName << " "
                     << stud.second.dob << " "
                     << stud.second.cls << " "
                     << stud.second.sec << endl;
            }
            file.close();
            cout << "The file has successfully saved!" << endl;
        }else{
            cout << "The file cannot be opened!" << endl;
        }
    }else{
        cout << "The student with rollNo : " << rollNo << "is not found." << endl;
    }
}
void display(){
    ifstream file("studentDB.txt");

    int rollNo;
    students s;

    cout << "\n==========================================================" << endl;
    cout << "                    STUDENT RECORDS                       " << endl;
    cout << "==========================================================" << endl;
    
    cout << left << setw(10) << "Roll No" 
             << setw(15) << "Name" 
             << setw(15) << "DOB" 
             << setw(10) << "Class" 
             << setw(10) << "Section" << endl;
        cout << "----------------------------------------------------------" << endl;

    
    if(file.is_open()){
        while(file >> rollNo >> s.studentName >> s.dob >> s.cls >> s.sec){
            cout << left << setw(10) << rollNo 
                 << setw(15) << s.studentName 
                 << setw(15) << s.dob 
                 << setw(10) << s.cls 
                 << setw(10) << s.sec << endl;
        }
        file.close();
    }else{
        cout << "Unable to Open the file" << endl;
    }
    cout << "==========================================================" << endl;
}
