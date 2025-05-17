#include <iostream>
#include <chrono>
#include <thread>
#include "event.h"
#include "queue.h"
#include "stack.h"
#include "utilities.h"
#include "string"


using namespace std;

//color codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"

int main()
{
    cout << GREEN <<"*********************************************************" << RESET << endl;
    Delay(200);
    cout  << "\tWelcome to ";
    Delay(500);
    cout << BLUE << "Mansoura " << RESET ;
    Delay(500);
    cout << RED <<"Robotics " << RESET ;
    Delay(500);
    cout << "Event Manager" << RESET << endl;
    Delay(200);
    cout << GREEN <<"*********************************************************" << RESET << endl;

    enterEvents();
    manageEvents();

    return 0;
}
