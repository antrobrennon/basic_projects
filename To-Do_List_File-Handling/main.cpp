#include<iostream>
#include<fstream>
using namespace std;

void writeFile(string line);
void readFile();
void writeFileSpecific(int delList);
void readSpecific();


int createTask(){
    cout << "Enter Your Choice \n";
    
    cout << "1. To add a list" << endl;
    cout << "2. To delete a specific list" << endl;
    cout << "3. To print all list" << endl;
    cout << "4. To remove all list;" << endl;
    cout << "5. To print specific list" << endl;
    cout << "6. To end" << endl;

    //To get input
    int n;
    cin >> n;
    cin.ignore();

    return n;
}
int createList(int count){
    cout << "List to be added" << endl;
    string Task;

    while(getline(cin, Task)){
        if(Task == "break"){
            break;
        }
        writeFile(Task);
        count++;  
    }
    return count;
}
int deleteList(int count){
    cout << "The current Lists are:";
    readFile();
    cout << "List the number to be deleted";
        int delList;
        cin >> delList;

    writeFileSpecific(delList);
    return count--;
}
void readFile(){
    int count = 1;
    string line;
    ifstream file("sample.txt");

    while(getline(file,line)){
        cout << count << " : " << line << endl;
        count++;
    }

    file.close();
}
void writeFile(string line){
    
    ofstream file("sample.txt",ios::app);

        file << line << endl;
    
    file.close();
}
void writeFileSpecific(int delList){
    int count = 0;
    string line;
    ifstream file("sample.txt");
    ofstream temp("temp.txt");


    while(getline(file,line)){
        if(count != delList){
            temp << line << endl;
        }
        count++;
    }

    file.close();
    temp.close();

    remove("sample.txt");
    rename("temp.txt","sample.txt");

}
void readSpecific(){
    int specList, count = 1;
    string line;
    cout << "The lists are:" << endl;
    readFile();
    cout << "The line to be read Specifically is:";
    cin >> specList;

    ifstream file("sample.txt");
    
    while(getline(file,line)){
        if(count == specList){
            cout << line << endl;
            count++;
        }
    }
    file.close();
}
int main(){
    int count = 0;
    int inputNumber = createTask();
        if(inputNumber == 1){
            count = createList(count);
        }else if(inputNumber == 2){
            count = deleteList(count);
        }else if(inputNumber == 3){
            readFile();
        }else if(inputNumber == 4){
            std::ofstream file("sample.txt");
            file << "";
            cout << "successfully removed all list";
        }else if(inputNumber == 5){
            readSpecific();
        }else if(inputNumber == 6){
            return 0;
        }
    return 0;
}