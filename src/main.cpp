/********************************************/
             /* "17.06.2022" */
/* a program for student exam score db query */
    /* made for educational purposes only */
/********************************************/



#include <iostream>
#include <string>
#include <fstream>
#include "qsheader.h"
//#include "stackheader.h"
using namespace std;

ifstream fin;
Queue qMath;
Stack sEng;
string choice;

void choose() {
    cout << "Enter Query : ";
    cin >> choice;
    
    if(choice == "math")
    {
        qMath.display();
        choose();
    }

    else if(choice == "eng")
    {
        sEng.display();
        choose();
    }
    
    else if(choice == "max(math)" || choice == "min(math)")
    {
        if(choice == "max(math)")
        {
            cout << "Max Score: " << qMath.maxScore() << endl;
            choose();
        }
        else if(choice == "min(math)")
        {
            cout << "Min Score: " << qMath.minScore() << endl;
            choose();
        }
    }
    
    
    else if(choice == "sort(math)")
    {
        qMath.sortByScore();
        cout << "Sorted by Score" << endl;
        choose();
    }

    else if(choice == "max(eng)" || choice == "min(eng)")
    {
        if(choice == "max(eng)")
        {
            cout << "Max Score: " << sEng.maxScore() << endl;
            choose();
        }
        else if(choice == "min(eng)")
        {
            cout << "Min Score: " << sEng.minScore() << endl;
            choose();
        }
    }

    else if(choice == "sort(eng)")
    {
        sEng.sortByScore();
        cout << "Sorted by Score" << endl;
        choose();
    }

    else if(choice == "avg(math)")
    {
        cout << "Average Score: " << qMath.averageScore() << endl;
        choose();
    }

    else if(choice == "avg(eng)")
    {
        cout << "Average Score: " << sEng.averageScore() << endl;
        choose();
    }
    
    else if(choice == "exit")
        exit(0);
    
    else { 
        cout << "Syntax Error!" << endl;
        choose();
    }
}

int main() {
    fin.open("math.txt");
    while (!fin.eof()) {
        int id;
        string name;
        int first;
        int second;
        fin >> id >> name >> first >> second;
        int score = (first + second)/2;
        qMath.enqueue(id, name, score);
    }
    fin.close();
    fin.open("eng.txt");
    while (!fin.eof()) {
        int id;
        string name;
        int first;
        int second;
        fin >> id >> name >> first >> second;
        int score = (first + second)/2;
        sEng.push(id, name, score);
    }
    fin.close();
    choose();
}