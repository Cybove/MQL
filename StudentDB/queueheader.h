#ifndef queueheader
#define queueheader
#include <iostream>
#include <string>
#include <fstream>
#include "stackheader.h"
using namespace std;

class qNode {
public:
    int id;
    string name;
    int score;
    qNode *next;
    qNode(int d, string n, int s) {
        id = d;
        name = n;
        score = s;
        next = NULL;
    }
};
class Queue {
public:
    qNode *front;
    qNode *rear;
    Queue() {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int d, string n, int s) {
        qNode *temp = new qNode(d, n, s);
        if (front == NULL) {
            front = temp;
            rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
    }
    void dequeue() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
        } else {
            qNode *temp = front;
            front = front->next;
            delete temp;
        }
    }
    void display() {
        qNode *temp = front;
        while (temp != NULL) {
            cout << temp->id << " " << temp->name << " " << temp->score << endl;
            temp = temp->next;
        }
    }
};


#endif