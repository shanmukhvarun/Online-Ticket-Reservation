#include<iostream>
#include<unistd.h>
#include<cctype>
#include<stack>
#include<ctime>
#include<iomanip>
using namespace std;
stack<string> BPickUp;
stack<string>BDestination;
stack<int >BFare;
stack<int>BDate;
stack<int>BSeat;
stack<string> TPickUp;
stack<string>TDestination;
stack<int >TFare;
stack<int>TDate;
stack<int>TSeat;
stack<string> TCompartment;
void TicketReservation();
void dashboard();
void BUS(string ,string ,int);
void Train(string ,string ,int);
void History();
void cancellation();
void payment(int );
void showBookingSummary(string , string , int , int , int , string compart = "");