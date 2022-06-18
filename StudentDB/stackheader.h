#ifndef stackheader
#define stackheader
#include <iostream>
#include <string>
#include <fstream>
#include "queueheader.h"
using namespace std;

class sNode {
public:
    int id;
    string name;
    int score;
    sNode *next;
    sNode(int d, string n, int s) {
        id = d;
        name = n;
        score = s;
        next = NULL;
    }
};
class Stack {
public:
    sNode *top;
    Stack() {
        top = NULL;
    }
    void push(int d, string n, int s) {
        sNode *temp = new sNode(d, n, s);
        temp->next = top;
        top = temp;
    }
    void pop() {
        if (top == NULL) {
            cout << "Stack is empty" << endl;
        } else {
            sNode *temp = top;
            top = top->next;
            delete temp;
        }
    }
    void display() {
        sNode *temp = top;
        while (temp != NULL) {
            cout << temp->id << " " << temp->name << " " << temp->score << endl;
            temp = temp->next;
        }
    }
};

#endif