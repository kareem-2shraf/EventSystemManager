#pragma once
#include <string>
#include "stack.h"
#include "queue.h"
#include <iostream>
using namespace std;

struct node {
        string event_id;
        string event_name;
        attend attendee_name;
        stack undo_attendee;
        node* next;
};


class linkedlist {
private:
    int length;
    node* head;
    node* tail;
    stack undo_event;
public:
    linkedlist();
    bool isEmpty();
    void addfirst(string name , string id);
    void addlast(string name , string id);
    void addAtPos(string name , string id , int pos);
    void remove_event(string id);
    void print_list();
    void undo();
    void insertAttendto_event(string id, string attendees);
    void delAttendfrom_event(string id, string attendees);
    void disAttendin_event(string id);
    void findAttendat_event(string id, string attendees);
    void undo_last_attendee(string id);

};

