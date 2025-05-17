#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "stack.h"
#include "queue.h"
#include "event.h"
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"

    linkedlist::linkedlist() {
        head = tail = NULL;
        length = 0;
    }
    bool linkedlist::isEmpty(){
        return (head==NULL);
    }

    void linkedlist::addfirst(string name , string id){

        node* newNode = new node;
        newNode->event_name = name;
        newNode->event_id = id;
        if (length == 0){
            head = tail = newNode;
            newNode->next = NULL;
        }
        else{
            newNode->next = head;
            head = newNode;
        }
        length++;
    }

    void linkedlist::addlast(string name , string id){

        node* current = head;
        while(current != NULL)
        {
            if(current->event_id == id)
            {
                cout << RED << "** Conflict..!! ** Invalid ID value...! \t ***Try Again***\n" << RESET << endl;
                return;
            }
            current = current->next;
        }

        node* newNode = new node;
        newNode->event_name = name;
        newNode->event_id = id;
        newNode->next = NULL;

            if (length == 0){
                head = tail = newNode;
                newNode->next = NULL;
            }
            else{
                tail->next = newNode;
                newNode->next = NULL;
                tail = newNode;
            }
            length++;
    }

    void linkedlist::addAtPos(string name, string id, int pos) {
    node* newNode = new node;
    newNode->event_name = name;
    newNode->event_id = id;
    newNode->next = NULL;

    if (pos < 0 || pos > length){
       cout << RED << "Out of Range!" << RESET <<endl;
       delete newNode;
       return;
     }
     if (pos == 0){
       addfirst(name , id);
     }
     else if (pos == length){
       addlast(name , id);
     }
     else{
       node* current = head;
       for (int i = 0; i < pos - 1; i++){
         current = current->next;
       }
       newNode->next = current->next;
       current->next = newNode;
       length++;
     }
}


    void linkedlist::print_list() {
        node* current = head;
        while(current != NULL) {
          cout << current->event_name << " ";
          cout << current->event_id << " " << endl;
          this_thread::sleep_for(chrono::milliseconds(300));
          current = current->next;
        }
       }



    void linkedlist::remove_event(string id) {
    if (isEmpty()) {
        cout << RED << "List is empty now!" << RESET << endl;
        return;
    }
    if (head->event_id == id) {
        undo_event.push(head->event_name, head->event_id, 0);
        node* temp = head;
        head = head->next;
        if (head == NULL) tail = NULL;
        delete temp;
        length--;
        return;
    }
    if (length == 1) {
        undo_event.push(head->event_name, head->event_id, 0);
        delete head;
        head = tail = NULL;
        length--;
        return;
    }
    node* cur = head->next;
    node* prev = head;
    int i = 1;
    while (cur != NULL) {
        if (cur->event_id == id) {
            undo_event.push(cur->event_name, cur->event_id, i);
            prev->next = cur->next;
            if (cur == tail) {
                tail = prev;
            }
            delete cur;
            length--;
            return;
        }
        prev = cur;
        cur = cur->next;
        i++;
    }
    cout << RED << "Event not found!" << RESET << endl;
}


    void linkedlist::insertAttendto_event(string id, string attendees)
    {
        if(isEmpty())
        {
            cout << RED << "There is no events in ur list to insert an Attendee in...!" << RESET << endl;
        }
        else{
        node* curr = head;
        while(curr != NULL)
        {
            if(curr->event_id == id)
            {
                curr->attendee_name.addAttendee(attendees);
                cout << "\nAttendee \"" << attendees << "\" added to event: " << curr->event_name << endl;
                return;
            }
            curr = curr->next;
        }
        cout << RED <<"Event with ID ** " << id << " **" << "not found" << RESET << endl;
        }
    }


    void linkedlist::delAttendfrom_event(string id, string attendees)
    {
        if(isEmpty())
        {
            cout << "There is no events in ur list to insert an Attendee in...!" << endl;
        }
        else{
        node* curr = head;
        while(curr != NULL)
        {
            if(curr->event_id == id)
            {
                curr->attendee_name.delAttendee(attendees, curr->undo_attendee);
                cout << "\nAttendee \"" << attendees << "\" removed from event : " << curr->event_name << endl;
                return;
            }
            curr = curr->next;
        }
        cout << RED <<"Event with ID ** " << id << " **" << "not found" << RESET << endl;
        }
    }


    void linkedlist::disAttendin_event(string id)
    {
        if(isEmpty())
        {
            cout << RED << "\nThere is no events in ur list to insert an Attendee in...!" << RESET << endl;
        }
        else{
        node* curr = head;
        while(curr != NULL)
        {
            if(curr->event_id == id)
            {
                cout << "\nAttendees in event ** " << curr->event_name << " **" << endl;
                curr->attendee_name.disAttendees();
                return;
            }
            curr = curr->next;
        }
        cout << RED <<"Event with ID ** " << id << " **" << "not found" << RESET << endl;
        }
    }


    void linkedlist::findAttendat_event(string id, string attendees)
    {
        if(isEmpty())
        {
            cout << RED << "\nThere is no events in ur list to insert an Attendee in...!" << RESET <<  endl;
        }
        else{
        node* curr = head;
        while(curr != NULL)
        {
            if(curr->event_id == id)
            {
                int re = curr->attendee_name.attendSearch(attendees);
                if(re == -1)
                {
                    cout << RED << "\nThe Attendee is not at this Event !!" << RESET << endl;
                    cout << "You may find him/her in another event" << endl;
                }
                else{
                cout << "The Attendee ** " << attendees << " ** you are searching for is --! HERE !-- at position * " << re << " *" << endl;
                }
                return;
            }
            curr = curr->next;
        }
        cout << RED << "\nEvent with ID ** " << id << " **" << "not found" << RESET << endl;
        }
    }




    void linkedlist::undo() {
    if (undo_event.isEmpty()) {
        cout << RED << "Nothing to undo_event!" << RESET << endl;
        return;
    }
    else {
        string x;
        string y;
        int i;
        undo_event.getTopName(y);
        undo_event.getTopPos(i);
        undo_event.getTopID(x);
        undo_event.pop();
        addAtPos(y, x , i);
    }
}

void linkedlist::undo_last_attendee(string event_id)
{
    node* curr = head;
    while (curr != NULL)
    {
        if (curr->event_id == event_id)
        {
            if (curr->undo_attendee.isEmpty())
            {
                cout << RED << "Nothing to undo_Attendee!" << RESET << endl;
                return;
            }
            string name = curr->undo_attendee.pop_attendee();
            curr->attendee_name.addAttendee(name);
            cout << "Restored: " << name << endl;
            return;
        }
        curr = curr->next;
    }
}

