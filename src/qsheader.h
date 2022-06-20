/********************************************/
            /* "17.06.2022" */
        /* header file of the program*/
    /* made for educational purposes only */
/********************************************/



#ifndef queueheader
#define queueheader
#include <iostream>
#include <string>
#include <fstream>
//#include "stackheader.h"

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
            cout << "No Record" << endl;
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
    string maxScore() {
        int max = 0;
        int id;
        string name;
        qNode *temp = front;
        while (temp != NULL) {
            if (temp->score > max) {
                max = temp->score;
                name = temp->name;
                id = temp->id;
            }
            temp = temp->next;
        }
        string maxs = to_string(max);
        string ids = to_string(id);
        maxs = ids + " " + name + " " + maxs;
        return maxs;
        
    }
    string minScore() {
        int min = 100;
        int id;
        string name;
        qNode *temp = front;
        while (temp != NULL) {
            if (temp->score < min) {
                min = temp->score;
                name = temp->name;
                id = temp->id;
            }
            temp = temp->next;
        }
        string mins = to_string(min);
        string ids = to_string(id);
        mins = ids + " " + name + " " + mins;
        return mins;
    }

    /*string maxScoreName() {
        int max = 0;
        string name = "";
        qNode *temp = front;
        while (temp != NULL) {
            if (temp->score > max) {
                max = temp->score;
                name = temp->name;
            }
            temp = temp->next;
        }
        return name;
    }*/

    /*void sortByScore() { 
        Stack s;
        qNode *temp = front;
        while (temp != NULL) {
            s.push(temp->id, temp->name, temp->score);
            temp = temp->next;
        }
        while (s.top != NULL) {
            qNode *temp = new qNode(s.top->id, s.top->name, s.top->score);
            if (front == NULL) {
                front = temp;
                rear = temp;
            } else {
                rear->next = temp;
                rear = temp;
            }
        }
    }*/

    void sortByScore() {
        qNode *temp = front;
        while (temp != NULL) {
            qNode *temp2 = front;
            while (temp2 != NULL) {
                if (temp->score > temp2->score) {
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

    int averageScore() {
        int sum = 0;
        int count = 0;
        qNode *temp = front;
        while (temp != NULL) {
            sum += temp->score;
            count++;
            temp = temp->next;
        }
        int avg = sum / count;
        return avg;
    }

};

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
            cout << "No Record" << endl;
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

    string maxScore() {
        int max = 0;
        int id;
        string name;
        sNode *temp = top;
        while (temp != NULL) {
            if (temp->score > max) {
                max = temp->score;
                name = temp->name;
                id = temp->id;
            }
            temp = temp->next;
        }
        string maxs = to_string(max);
        string ids = to_string(id);
        maxs = ids + " " + name + " " + maxs;
        return maxs;
    }

    string minScore() {
        int min = 100;
        int id;
        string name;
        sNode *temp = top;
        while (temp != NULL) {
            if (temp->score < min) {
                min = temp->score;
                name = temp->name;
                id = temp->id;
            }
            temp = temp->next;
        }
        string mins = to_string(min);
        string ids = to_string(id);
        mins = ids + " " + name + " " + mins;
        return mins;
    }

    /*void sortByScore() { //queue swap
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

    void sortByScore() {
        Queue q;
        sNode *temp = top;
        while (temp != NULL) {
            q.enqueue(temp->id, temp->name, temp->score);
            temp = temp->next;
            pop();
        }
        q.sortByScore();
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
    }

    int averageScore() {
        int sum = 0;
        int count = 0;
        sNode *temp = top;
        while (temp != NULL) {
            sum += temp->score;
            count++;
            temp = temp->next;
        }
        int avg = sum / count;
        return avg;
    }
    
};

#endif