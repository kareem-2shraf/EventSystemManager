#include "queue.h"
#include "stack.h"
#include <iostream>
#include <string>
using namespace std;


#define RESET   "\033[0m"
#define RED     "\033[31m"



    attend::attend()
    {
        front = rear = NULL;
        count = 0;
    }

    // Check if the queue is empty
    bool attend::isEmpty()
    {
        return (count == 0);
    }


    void attend::addAttendee(string name)
    {
        NodeQueue* newNode = new NodeQueue{name, NULL};
        if (isEmpty())
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
            rear-> next = NULL;
        }
        count++;
    }

    /*
     * @brief Delete the front attendee from the queue
     * @details Removes the front node from the linked list and adjusts the front pointer.
     */
    void attend::delAttendee(string val, stack& undo_attendee)
    {
        if (isEmpty())
        {
            cout << RED <<"Queue is Empty...!! \t You Can't delete one...!!" << RESET << endl;
            return;
        }

        NodeQueue* temp = front;
        NodeQueue* prev = NULL;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                found = true;
                undo_attendee.push_attendee(val); // revise
                break;
            }

            prev = temp;
            temp = temp->next;
        }

        if (!found)
        {
            cout << RED << "\nElement not found in Our System..!!\n" << RESET;
            return;
        }

        if(temp == front)
        {
            front = front->next;
            if(front == NULL)
            {
                rear == NULL;
            }
        }
        else{
            prev->next = temp->next;
            if(temp == rear)
                rear = prev;
        }

        delete temp;
        temp = NULL;
        count--;

        cout << "attendee " << val << " Deleted Successfully!" << endl;
    }

    /*
     * @brief Display the list of attendees
     * @details Iterates over the linked list and prints each element.
     */
    void attend::disAttendees()
    {
        if (isEmpty())
        {
            cout << RED <<"\nQueue is Empty...!! \t Can't display anything...!!" << RESET << endl;
            return;
        }
        NodeQueue* current = new NodeQueue;
        current = front;
        int k = 1;
        while (current != NULL)
        {
            cout << k << " - " << current->data << endl;
            current = current->next;
            k++;
        }
    }

    /*
     * @brief Search for an attendee in the queue
     * @return Position (0-based index), or -1 if not found
     */
    int attend::attendSearch(string attendee)
    {
        if (isEmpty())
        {
            cout << RED << "\nThe queue is empty...!! \t There is nothing to search for...!!" << RESET <<endl;
            return -1;
        }

        NodeQueue* current = new NodeQueue;
        current = front;
        int i = 0;
        while (current != NULL)
        {
            if (current->data == attendee)
                return i;
            current = current->next;
            i++;
        }
        return -1; // Not found
    }



