#include <iostream>
#include "header/functions.h"
using namespace std;

int main(){
    functionList();

    int UserInput;
    cout << "Enter Your choice: " ;
    while(cin >> UserInput && UserInput != 0){
        switch(UserInput){
            case 1:
                addStudentInformation();
                break;
            case 2:
                update();
                break;
            case 3:
                deleteStudentData();
                break;
            default:
                display();
        }
        functionList();
        cout << "Enter Your choice: " ;
    }
}