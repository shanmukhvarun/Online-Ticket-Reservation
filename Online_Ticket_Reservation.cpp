#include<iostream>
#include<unistd.h>
#include<cctype>
#include<stack>
#include<ctime>
#include <chrono>
#include <thread>
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
stack<string> TPickUp2;
stack<string> TDestination2;
stack<int>TDate2;
stack<string> TCompartment2;
stack<int> TSeat2;
stack<int> TFare2;
stack<string> BPickUp2;
stack<string> BDestination2;
stack<int> BDate2;
stack<int> BSeat2;
stack<int> BFare2;
void TicketReservation();
void dashboard();
void BUS(string ,string ,int);
void Train(string ,string ,int);
void History();
void cancellation();
void payment(int );
void showBookingSummary(string , string , int , int , int , string compart = "");
int main()
{
    cout<<"\n\033[1mWELCOME TO TRAVEL MATE  \033[0m\n\n";
    sleep(1);
    srand(time(0));  
    dashboard();
    return 0;
}
void dashboard()
{
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
void TicketReservation()
{
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
    if(date >31||date<1||month>12||month<4||year<2025 ){
        cout<<"\033[1;31mInvalid Option!\033[0m\\n";
        goto d;
    }
    cout<<"\033[1mMode of transport you need :\033[0m\\n\n\n";
    mode:
    cout<<"1.Bus\n"<<"2.Train\n";
    cout<<"select your Mode of Transport :";
    cin>>MOT;
    
    switch(MOT)
    {
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
void BUS(string pickup, string destination, int date) 
{
    int B, seat, fare = rand() % 300 + 500, m;
    cout << "\033[1mFinding the buses for you \033[0m";
    for (int i = 0; i < 5; ++i)
     {
        std::cout << "." << std::flush;  
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
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
    while (B > 4 || B < 1)
    {
        cout << "\033[1;31mInvalid option!\033[0m\\n" << "enter again:" << endl;
        cin >> B;
    }
    cout << "\nSearching for the vacancies in the bus, it may take few seconds";
    for (int i = 0; i < 6; ++i)
    {
        std::cout << "." << std::flush;  
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    sleep(3);
    int SeatSelection[3][2]; 
    cout << "\nAvailable Seats:\n\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            SeatSelection[i][j] = rand() % 40 + 1;
            cout << setw(5) << SeatSelection[i][j];
        }
        cout << endl;
    }

    selectSeat:
    cout << "\n\nEnter Seat you like: ";
    cin >> seat;
    bool found = false;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (seat == SeatSelection[i][j])
            {
                found = true;
                break;
            }
        }
        if (found) break;
    }
    if (!found)
    {
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
    BPickUp2.push(pickup);
    BDestination2.push(destination);
    BDate2.push(date);
    BFare2.push(fare);
    BSeat2.push(seat);

    cout << "Reservation Completed.\n";
    cout << "Do you want to:\n1. Book Another Ticket\n2. Proceed to Payment\n3. Dashboard\n";
    cout << "Enter your choice: ";
    cin >> m;

    if (m == 1)
    {
        TicketReservation(); 
    }
    else if (m == 2)
    {
        showBookingSummary(pickup, destination, date, seat, fare);
        payment(fare);
    }
    
    else
    {
        dashboard();
    }
}

void Train(string pickup, string destination, int date)
{
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
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
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
    for ( i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (seat == SeatSelection[i][j])
            {
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
    TPickUp2.push(pickup);
    TDestination2.push(destination);
    TDate2.push(date);
    TFare2.push(fare);
    TSeat2.push(seat);
    TCompartment2.push(compart);

    cout << "Reservation Completed.\n";
    cout << "Do you want to:\n1. Book Another Ticket\n2. Proceed to Payment\n3. Dashboard\n";
    cout << "Enter your choice: ";
    cin >> m;

    if (m == 1)
    {
        TicketReservation(); 
    }
        else if (m == 2)
        {
            showBookingSummary(pickup, destination, date, seat, fare, compart);
            payment(fare);
    }
    else {
        dashboard();
    }
}
void History()
{
    int i=1,Thistory;
    cout<<"Which history you want to know :\n 1.Bus History \n 2.Train History \n";
    cout<<"Select history :";
    cin>>Thistory;
    if(Thistory==1){
       
        cout <<"S.No"<< left << setw(5) << "  Pickup Point" << setw(15) << "  Destination Point" << setw(15) << "  Seat number" << setw(15) << "Total Fare" << endl;
        while(!BPickUp2.empty())
        {
            cout <<i<< left << setw(5) <<" "<< BPickUp2.top() << setw(15) <<" "<<BDestination2.top() << setw(15) << " "<<BSeat2.top() << setw(15) <<" "<< BFare2.top() << endl;
            BPickUp2.pop();
            BDestination2.pop();
            BDate2.pop();
            BFare2.pop();
            i++;
        }

    }
    else if(Thistory==2)
    {
       
        cout <<"S.No"<< left << setw(5) << "  Pickup Point" << setw(15) << "  Destination Point" << setw(15) << "   compartment"<<setw(15)<<"  Seat number" << setw(15) << "Total Fare" << endl;
        while(!TPickUp2.empty())
        {
            cout <<i<< left << setw(5) <<"  "<< TPickUp2.top() << setw(15) <<"  "<<TDestination2.top() << setw(15) <<TCompartment2.top() <<setw(15)<< " "<<TSeat2.top() << setw(15) << TFare2.top() << endl;
            TPickUp2.pop();
            TDestination2.pop();
            TDate2.pop();
            TFare2.pop();
            TCompartment2.pop();
            i++;
        }
    }
    else
    {
        cout<<"invalid! input Enter again :";
        History();
    }
    sleep(1);
    dashboard();
}
void cancellation()
{
    int mode,S,cancel;
    string CANCEL;
    cout<<"which ticket you want to cancel \n "<<"1.Bus \n"<<"2.Train \n";
    cin>>mode;
    if(mode==1)
    {
        cout<<"\033[1;31mreason for cancellation :\033[0m"<<endl;
        cout<<"1.entered wrong pickup\n "<<"2.booked accidentally \n "<<"3.fare was too high \n "<<"4.entered wrong destination\n ";
        cin>>cancel;
        cout <<"S.No"<< left << setw(5) << "  Pickup Point" << setw(15) << "  Destination Point" << setw(15) << "  Seat number" << setw(15) << "Total Fare" << endl;
            cout << left << setw(5) <<" "<< BPickUp.top() << setw(15) <<" "<<BDestination.top() << setw(15) << " "<<BSeat.top() << setw(15) <<" "<< BFare.top() << endl;
         cout<<"are you sure of cancelling the ticket :";
         cout<<"Enter YES IF YOU ARE SURE"<<endl;
         cin>>CANCEL;
         if(CANCEL=="YES"||CANCEL=="yes")
         {
             cout<<"full money can't be refunded \n"<<"90% of the money will be Refunded .."<<endl;
             cout<<"If you are okay with the Refunding amount of   "<<(BFare.top()*90/100)<<" enter 1 else enter 2"<<endl;
            cin>>S;
            if(S==1){
                sleep(1);
                cout<<"cancelling the ticket";
                for (int i = 0; i < 4; ++i) {
                    std::cout << "." << std::flush;  
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
                sleep(3);
                cout<<"Ticket Cancelled "<<endl;  
                sleep(1);
                BPickUp.pop();
                BDestination.pop();
                BDate.pop();
                BFare.pop();
                BSeat.pop();
                cout<<  " For another help ";
                dashboard();
            }
            else if(S==2)
            {
                dashboard();
            }
            else
            {
                cancellation();
            }
   }
}

     else if(mode==2)
     {
        cout<<"\033[1;31mreason for cancellation :\033[0m"<<endl;
        cout<<"1.entered wrong pickup\n "<<"2.booked accidentally \n "<<"3.fare was too high \n "<<"4.entered wrong destination\n ";
        cin>>cancel;
        cout <<"S.No"<< left << setw(5) << "  Pickup Point" << setw(15) << "  Destination Point" << setw(15) << "   compartment"<<setw(15)<<"  Seat number" << setw(15) << "Total Fare" << endl;
            cout << left << setw(5) <<"  "<< TPickUp.top() << setw(15) <<"  "<<TDestination.top() << setw(15) <<TCompartment.top() <<setw(15)<< " "<<TSeat.top() << setw(15) << TFare.top() << endl;
         cout<<"are you sure of cancelling the ticket :";
         cout<<"Enter YES IF YOU ARE SURE"<<endl;
         cin>>CANCEL;
         if(CANCEL=="YES")
         {
             cout<<"full money can't be refunded \n"<<"90% of the money will be Refunded .."<<endl;
             cout<<"If you are okay with the Refunding amount of   "<<(TFare.top()*90/100)<<" enter 1 else enter 2"<<endl;
            cin>>S;
            if(S==1)
            {
                sleep(1);
                cout<<"cancelling the ticket";
                for (int i = 0; i < 4; ++i)
                {
                    std::cout << "." << std::flush;  
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
                sleep(3);
                cout<<"Ticket Cancelled "<<endl;  
                sleep(1);
                TPickUp.pop();
                TDestination.pop();
                TCompartment.pop();
                TDate.pop();
                TFare.pop();
                TSeat.pop();
                cout<<  " For another help ";
                 sleep(1);
                dashboard();
            }
            else if(S==2){
                dashboard();
            }
            else{
                cancellation();
            }
    }
}
    else{
        cancellation();
    }
}
void payment(int fare)
{
    cout << "\n1. Credit/Debit Card\n"
    << "2. UPI\n"
    <<"Choose a payment method:\n";
    int paymentType;
    string upiID;
    cin>>paymentType;
    switch(paymentType)
    {
    case 1:
        long long cardNumber;
        int cvv, cardPin;
        cout<<"Enter your Card number: ";
        cin>>cardNumber;
        Ecvv:
        cout<<"Enter CVV: ";
        cin>>cvv;
        if(cvv <= 100 || cvv > 999)
        {
            cout<<"Incorrect CVV entered!";
            goto Ecvv;
        }
        Epin:
        cout<<"Enter PIN: ";
        cin>>cardPin;
        if((cardPin <=100 && cardPin > 9999) || (cardPin <= 999 && cardPin > 999999)){
            cout<<"Incorrect PIN entered!";
            goto Epin;
        }
        cout<<"Processing payment";
        for(int j=0;j<5;j++){
            cout<<".";
        }
        cout<<"Payment Successful.reservation successfull\n";
        break;
    case 2:
        cout << "Enter your UPI ID: ";
        cin >> upiID;
        cout << "Processing payment through"<<"  "<<upiID;
        for (int i = 0; i < 7; ++i) {
            std::cout << "." << std::flush;  
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
        cout<<endl;
        cout << "Payment Successful via UPI!\n";
        break;
    default:
        cout<<"\033[1;31mInvalid Payment Type!\033[0m";
        payment(fare);
    }
    sleep(2);
    dashboard();
}
void showBookingSummary(string pickup, string destination, int date, int seat, int fare, string compart )
{
    cout << "\n\033[1mBooking Summary:\033[0m\n";
    cout << "Pickup Location: " << pickup << endl;
    cout << "Destination: " << destination << endl;
    cout << "Date of Travel: " << date << endl;
    cout << "Seat Number: " << seat << endl;
    cout << "Fare: " << fare << endl;
    if (compart != "") { 
        cout << "Compartment: " << compart << endl;
    }
    cout << "\nProceeding to Payment...\n";
    sleep(2);
}
