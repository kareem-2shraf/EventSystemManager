#pragma once
#include <iostream>
#include <string>
#include "event.h"
#include "stack.h"
#include "queue.h"
#include <chrono>
#include <thread>
using namespace std;

//color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

linkedlist list;
attend attendee;
// Function to delay
void Delay(int t) {
    this_thread::sleep_for(chrono::milliseconds(t));
}

// Function to prompt user to enter events until 'x' is pressed
void enterEvents() {
    string input;
    string id;
    while (true) {
        cout << GREEN << "Enter event name & Id (or 'x' to print list): " << RESET;
        getline(cin, input);
        if (input == "x" || input == "X") {
            cout << MAGENTA << "Printing list of events..." << RESET << endl;
            Delay(500);
            list.print_list();
            break;
        }
        getline(cin, id);
        cout << YELLOW << "Adding event: " << input << RESET << endl;
        if(input.find_first_not_of(' ') == string::npos|| id.find_first_not_of(' ') == string::npos)
        {
            cout << RED << "** Conflict..!! ** Invalid value...! \t ***Try Again***\n" << RESET << endl;
            continue;
        }
        list.addlast(input, id);
        Delay(500);
    }
}

// display menu and handle user operations
void manageEvents() {

    while (true) {
        cout << BLUE << "\nWhat would you like to do?\n" << RESET;
        cout << "1. Add Another Event\n";
        cout << "2. Remove Event\n";
        cout << "3. Print Events\n";
        cout << "4. Add Attendee to Event\n";
        cout << "5. Remove Attendee from Event\n";
        cout << "6. Display Attendees in Event\n";
        cout << "7. Save & Exit\n" ;
        cout << MAGENTA << "Enter your choice (1-7): " << RESET;
        Delay(500);

        int choice;
        cin >> choice;
        Delay(500);

        switch (choice) {
            case 1: {
                // Add Event
                string eventName;
                string id;
                cout << GREEN << "Enter event name & Id: " << RESET;
                getline(cin, eventName);
                getline(cin, id);
                if(eventName.find_first_not_of(' ') == string::npos|| id.find_first_not_of(' ') == string::npos)
                {
                    cout << RED << "** Conflict..!! ** Invalid value...! \t ***Try Again***\n" << RESET << endl;
                    continue;
                }
                list.addlast(eventName, id);
                cout << YELLOW << "Adding event: " << eventName << RESET << endl;
                Delay(500);
                break;
            }
            case 2: {
                // Remove Event
                string eventId;
                cout << GREEN << "Enter event ID to remove: " << RESET;
                getline(cin, eventId);
                if(eventId.find_first_not_of(' ') == string::npos)
                {
                    cout << RED << "** Conflict..!! ** Invalid ID value...! \t ***Try Again***\n" << RESET << endl;
                    continue;
                }
                cout << YELLOW << "Removing event ID: " << eventId << RESET << endl;
                Delay(500);
                list.remove_event(eventId);
                cout << GREEN << "To Undo Press 'z' (or 'c' to continue) :" << RESET;
                char ch;
                cin >> ch;
                if(ch == 'z') {
                    list.undo();
                    cout << YELLOW << "Undoing last event removal.";
                    Delay(500);
                    cout << ".";
                    Delay(500);
                    cout << ".";
                    cout << GREEN << "\n Event undoed successfully!" << RESET << endl;
                }
                break;
            }
            case 3: {
                cout << MAGENTA << "Printing list of events..." << RESET << endl;
                 Delay(500);
                 list.print_list();
            break;
            }
            case 4: {
                // Add Attendee to Event
                string eventId;
                string attendeeName;
                string input;
                cout << GREEN << "Enter event ID to add attendee to it: " << RESET;
                getline(cin, eventId);
                if(eventId.find_first_not_of(' ') == string::npos)
                {
                    cout << RED << "** Conflict..!! ** Invalid ID value...! \t ***Try Again***\n" << RESET << endl;
                    continue;
                }
                while (true){
                    cout << GREEN << "Enter attendee name (press x to finish): " << RESET;
                    getline(cin, input);
                    if (input == "x" || input == "X")
                        break;
                        if(input.find_first_not_of(' ') == string::npos)
                        {
                            cout << RED << "** Conflict..!! ** Invalid value...! \t ***Try Again***\n" << RESET << endl;
                            continue;
                        }
                    attendeeName = input;
                    cout << YELLOW << "Adding attendee " << attendeeName << " to event ID: " << eventId << RESET << endl;
                    Delay(200);
                    list.insertAttendto_event(eventId, attendeeName);

                }


                break;
            }
            case 5: {
                // Remove Attendee from Event
                string eventId;
                string attendeeName;
                cout << GREEN << "Enter event ID: " << RESET;
                getline(cin, eventId);
                cout << GREEN << "Enter attendee name to remove: " << RESET;
                getline(cin, attendeeName);
                if(eventId.find_first_not_of(' ') == string::npos || attendeeName.find_first_not_of(' ') == string::npos)
                {
                    cout << RED << "** Conflict..!! ** Invalid value...! \t ***Try Again***\n" << RESET << endl;
                    break;
                }
                cout << YELLOW << "Removing attendee " << attendeeName << " from event ID: " << eventId << RESET << endl;
                Delay(500);
                list.delAttendfrom_event(eventId, attendeeName);
                cout << GREEN << "To Undo Press 'z' (or 'c' to continue) :" << RESET;
                char ch;
                cin >> ch;
                if(ch == 'z') {
                    cout << YELLOW << "Undoing last attendee removal.";
                    Delay(500);
                    cout << ".";
                    Delay(500);
                    cout << "." << endl;
                    list.undo_last_attendee(eventId);
                    cout << GREEN << "\n Attendee undoed successfully!" << RESET << endl;
                }
                break;
            }
            case 6: {
                // Display Attendees in Event
                string eventId;
                cout << GREEN << "Enter event ID to display attendees: " << RESET;
                getline(cin, eventId);
                if(eventId.find_first_not_of(' ') == string::npos)
                {
                    cout << RED << "** Conflict..!! ** Invalid ID value...! \t ***Try Again***\n" << RESET << endl;
                    break;
                }
                cout << MAGENTA << "Printing list of attendees..." << RESET << endl;
                Delay(500);
                list.disAttendin_event(eventId);
                cout << endl;
                break;
            }
            case 7: {
                // Save & Exit

                cout << CYAN << "Thank you for using Robotics Event Manager!" << RESET << endl;
                Delay(500);
                return;

            }
            default:
                cout << endl;
                cout << RED << "Invalid choice. Please enter a number between 1 and 7." << RESET << endl;
                Delay(500);
        }
    }
}


