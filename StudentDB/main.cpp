#include <iostream>
#include <string>
#include <fstream>
#include "queueheader.h"
#include "stackheader.h"
using namespace std;

ifstream fin;

int main(){
    fin.open("math.txt");
    while(!fin.eof()){
        int id;
        string name;
        int score;
        fin >> id >> name >> score;
        Queue q;
        q.enqueue(id, name, score);
        q.display();
    }
}