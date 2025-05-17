#include "stack.h"
#include "queue.h"
#include <iostream>
using namespace std;

    stack::stack()
    {
        top = NULL;
        size = 0;
    }
    bool stack::isEmpty()
    {
        return top == NULL;
    }
    // Store the id of the event in the stack
    // This function will be used to undo_event the last event
    void stack::push(string name, string id , int pos)
    {
        Node *newNode = new Node;
        newNode->name = name;
        newNode->id = id;
        newNode->pos = pos;
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Store the name of the event in the stack
    // This function will be used to undo_event the last event

    void stack::pop()
    {
        int temp;
        if (isEmpty())
        {
            cout << "stack empty on pop";
            return;
        }
        else
        {
            Node *temp = top;
            top = top->next;
            delete temp;
            size--;
        }
        return;
    }

    void stack::getTopID(string &stackTop)
    {
        if (isEmpty())
            cout << "stack empty on getTop";
        else
        {
            stackTop = top->id;
            //cout << stackTop << endl;
        }
    }

    void stack::getTopName(string &stackTop)
    {
        if (isEmpty())
            cout << "stack empty on getTop";
        else
        {
            stackTop = top->name;
            //cout << stackTop << endl;
        }
    }

    void stack::getTopPos(int &stackTop)
    {
        if (isEmpty())
            cout << "stack empty on getTop";
        else
        {
            stackTop = top->pos;
            //cout << stackTop << endl;
        }
    }


    void stack::push_attendee(string name2){
        Node *newNode = new Node;
        newNode->att = name2;
        newNode->next = top;
        top = newNode;
        size++;
    }

    string stack::pop_attendee()
    {
        if (isEmpty())
        {
            cout << "Nothing to undo_Attendee!" << endl;
            return "";
        }

        string value = top->att;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;

        return value;
    }

    void stack::getTopAttendee(string &stackTop)
    {
        if (isEmpty())
            cout << "stack empty on getTop";
        else
        {
            stackTop = top->att;
            //cout << stackTop << endl;
        }
    }
