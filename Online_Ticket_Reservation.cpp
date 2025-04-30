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
int main(){
    cout<<"\n\033[1mWELCOME TO TRAVEL MATE  \033[0m\n\n";
    sleep(1);
    srand(time(0));  
    dashboard();
    return 0;
}
void dashboard(){
    int choice; 
    cout<<"\n\033[1mHow can we help you  \033[0m \n";
    cout<<"1.TICKET RESERVATION\n"<<"2.HISTORY\n"<<"3.CANCELLATION\n\n";
    cout<<"Select the sector needed :";
    cin>>choice;
    cout<<endl<<endl;
    // sleep(1);
    switch(choice){
        case 1:
        TicketReservation();
        break;
        case 2:
        History();
        break;
        case 3:
        cancellation();
        break;
        default:
        cout<<"\033[1;31mInvalid Option!\033[0m\n";
        sleep(1);
        dashboard();
        break;
    }
}
void TicketReservation(){
    string pickup,destination;
    int date,MOT,month,year;
    cout<<"Enter your pickup location  :";
    cin>>pickup;
    cout<<"Enter destination  :";
    cin>>destination;
    d:
    cout<<"Date of Travel: ";
    cin>>date>> month >> year;
    cout<<endl;
    if(date >31||month>12||year<2025 ){
        cout<<"\033[1;31mInvalid Option!\033[0m\\n";
        goto d;
    }
    cout<<"\033[1mMode of transport you need :\033[0m\\n\n\n";
    mode:
    cout<<"1.Bus\n"<<"2.Train\n";
    cout<<"select your Mode of Transport :";
    cin>>MOT;
    
    switch(MOT){
        case 1:
        BUS(pickup,destination,date);
        break;
        case 2:
        Train(pickup,destination,date);
        break;
        default:
        goto mode;
        break;
    }
    
}
void BUS(string pickup, string destination, int date) {
    int B, seat, fare = rand() % 300 + 500, m;
    cout << "\033[1mFinding the buses for you ......\033[0m";
    sleep(2);
    cout << "\n\n\033[1mBuses available are:\033[0m\n";
    sleep(1);
    cout << "1. Garuda (08:00 AM - 02:00 PM)\n" 
         << "2. TSRTC Super Luxury (09:30 AM - 04:00 PM)\n"
         << "3. Morning Star (06:00 PM - 12:00 AM)\n" 
         << "4. Fresh Bus (11:00 PM - 05:00 AM)\n"; 
    sleep(1);
    cout << "select any travels: ";
    cin >> B;
    while (B > 4 || B < 1) {
        cout << "\033[1;31mInvalid option!\033[0m\\n" << "enter again:" << endl;
        cin >> B;
    }
    cout << "\nsearching for the vacancies in the bus, it may take few seconds.....\n\n";
    sleep(4);
    int SeatSelection[3][2]; 
    cout << "\nAvailable Seats:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            SeatSelection[i][j] = rand() % 40 + 1;
            cout << setw(5) << SeatSelection[i][j];
        }
        cout << endl;
    }

    selectSeat:
    cout << "\n\nEnter Seat you like: ";
    cin >> seat;
    bool found = false;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (seat == SeatSelection[i][j]) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found) {
        cout << "Seat not found. Please choose from the available seats.\n";
        goto selectSeat;
    }

    cout << "\033[1mCalculating the total fare:\033[0m" << endl<<endl;
    cout << "fare for your destination is: " << fare << endl;
    sleep(1);
    cout << endl;

    BPickUp.push(pickup);
    BDestination.push(destination);
    BDate.push(date);
    BFare.push(fare);
    BSeat.push(seat);

    cout << "Reservation Completed.\n";
    cout << "Do you want to:\n1. Book Another Ticket\n2. Proceed to Payment\n3. Dashboard\n";
    cout << "Enter your choice: ";
    cin >> m;

    if (m == 1) {
        TicketReservation(); 
    }
    else if (m == 2) {
        showBookingSummary(pickup, destination, date, seat, fare);
        payment(fare);
    }
    
    else {
        dashboard();
    }
}

void Train(string pickup, string destination, int date) {
    int k, p, seat, m;
    string compart;
    sleep(1);
    cout << "\nThe trains available are:\n"
         << "1. RAJDHANI EXPRESS (06:00 AM - 08:00 PM)\n"
         << "2. SHATABDI EXPRESS (07:00 AM - 03:00 PM)\n"
         << "3. VANDE BHARAT (04:00 PM - 10:00 PM)\n"
         << "4. DURONTO EXPRESS (11:00 PM - 08:00 AM)\n"; 
    cout << "Your choice: ";
    cin >> k;
    sleep(1);

    Com:
    cout << "The Available Compartments are:\n"
         << "1. Sleeper Class\n"
         << "2. AC First Class\n"
         << "3. Second Seating\n"
         << "4. General\n";
    cin >> p;

    switch(p) {
        case 1: compart = "Sleeper"; break;
        case 2: compart = "AC First Class"; break;
        case 3: compart = "Second Seating"; break;
        case 4: compart = "General"; break;
        default:
            cout << "\033[1;31mInvalid option!\033[0m\\n";
            goto Com;
    }

    int SeatSelection[3][2];
    cout << "\nAvailable Seats:\n\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            SeatSelection[i][j] = rand() % 50 + 1;
            cout << setw(5) << SeatSelection[i][j];
        }
        cout << endl;
    }
    int i;
    selectSeat:
    cout << "\nSelect seat: ";
    cin >> seat;
    bool found = false;
    for ( i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (seat == SeatSelection[i][j]) {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (i>4) {
        cout << "Seat not available! Choose another.\n";
        goto selectSeat;
    }

    int fare;
    if (p == 1) fare = rand() % 300 + 700;
    else if (p == 2) fare = rand() % 499 + 1001;
    else if (p == 3) fare = rand() % 300 + 400;
    else fare = rand() % 300 + 100;

    cout << "Fare for your destination is: " << fare << endl;
    sleep(2);

    TPickUp.push(pickup);
    TDestination.push(destination);
    TDate.push(date);
    TFare.push(fare);
    TSeat.push(seat);
    TCompartment.push(compart);

    cout << "Reservation Completed.\n";
    cout << "Do you want to:\n1. Book Another Ticket\n2. Proceed to Payment\n3. Dashboard\n";
    cout << "Enter your choice: ";
    cin >> m;

    if (m == 1) {
        TicketReservation(); 
    }
        else if (m == 2) {
            showBookingSummary(pickup, destination, date, seat, fare, compart);
            payment(fare);
    }
    else {
        dashboard();
    }
}
