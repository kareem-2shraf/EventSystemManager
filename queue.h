#pragma once
#include <string>
#include "stack.h"

using namespace std;

struct NodeQueue
    {
        string data;
        NodeQueue* next;
    };

struct attend
{

private:
    NodeQueue* front;
    NodeQueue* rear;
    int count;
    stack undo_attendee;
public:
    attend();
    bool isEmpty();
    void addAttendee(string name);
    void delAttendee(string val, stack& undo_attendee);
    void disAttendees();
    int attendSearch(string attendee);
};

