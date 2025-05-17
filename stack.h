#pragma once
using namespace std;
#include <iostream>


struct Node
    {
        string name;
        string id;
        int pos;
        string att;
        Node *next;
    };



class stack
{
private:
    Node *top;
    int size;
public:
    stack();
    bool isEmpty();
    void push(string name , string id , int pos);
    void pop();
    void getTopID(string &stackTop);
    void getTopName(string &stackTop);
    void getTopPos(int &stackTop);
    void push_attendee(string name2);
    string pop_attendee();
    void getTopAttendee(string &stackTop);

};

