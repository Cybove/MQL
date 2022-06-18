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
    void sortById(){
        sNode *temp = top;
        while(temp != NULL){
            sNode *temp2 = temp->next;
            while(temp2 != NULL){
                if(temp->id > temp2->id){
                    int tempId = temp->id;
                    string tempName = temp->name;
                    int tempScore = temp->score;
                    temp->id = temp2->id;
                    temp->name = temp2->name;
                    temp->score = temp2->score;
                    temp2->id = tempId;
                    temp2->name = tempName;
                    temp2->score = tempScore;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
    }
    void push(int d, string n, int s) {
        sNode *temp = new sNode(d, n, s);
        temp->next = top;
        top = temp;
        Stack::sortById();
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

    int maxScore() {
        int max = 0;
        sNode *temp = top;
        while (temp != NULL) {
            if (temp->score > max) {
                max = temp->score;
            }
            temp = temp->next;
        }
        return max;
    }

    int minScore() {
        int min = 100;
        sNode *temp = top;
        while (temp != NULL) {
            if (temp->score < min) {
                min = temp->score;
            }
            temp = temp->next;
        }
        return min;
    }

    /*void sortByScore() {
        Queue q;
        sNode *temp = top;
        while (temp != NULL) {
            q.enqueue(temp->id, temp->name, temp->score);
            temp = temp->next;
        }
        while (q.front != NULL) {
            sNode *temp = new sNode(q.front->id, q.front->name, q.front->score);
            if (top == NULL) 
                top = temp;
            else {
                sNode *temp2 = top;
                while (temp2->next != NULL) {
                    temp2 = temp2->next;
                }
                temp2->next = temp;
                
            }
            q.dequeue();
        }
    }*/

    //sort in the stack by score 
    void sortByScore() {
        Stack s;
        sNode *temp = top;
        while (temp != NULL) {
            s.push(temp->id, temp->name, temp->score);
            temp = temp->next;
        }
        while (s.top != NULL) {
            sNode *temp = new sNode(s.top->id, s.top->name, s.top->score);
            if (top == NULL) {
                top = temp;
            } else {
                sNode *temp2 = top;
                while (temp2->next != NULL) {
                    temp2 = temp2->next;
                }
                temp2->next = temp;
            }
            s.pop();
        }
    }
    
};

#endif