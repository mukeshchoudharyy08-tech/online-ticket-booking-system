#include <iostream>
using namespace std;

class BookingSystem
{
private:
    string eventName;
    int totalSeats;

public:
    BookingSystem(string name, int seats)
    {
        eventName = name;
        totalSeats = seats;
    }

    void displayMenu()
    {
        cout << "\n===== Online Ticket Booking System =====\n";
        cout << "Event: " << eventName << endl;

        cout << "1. Book Ticket\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. Check Availability\n";
        cout << "4. Exit\n";
    }

    void bookTicket()
    {
        int tickets;

        cout << "Enter number of tickets: ";
        cin >> tickets;

        if (tickets <= totalSeats)
        {
            totalSeats -= tickets;
            cout << "Booking Confirmed\n";
            cout << "Seats Remaining: " << totalSeats << endl;
        }
        else
        {
            cout << "Not enough seats available!\n";
        }
    }

    void cancelTicket()
    {
        int tickets;

        cout << "Enter number of tickets to cancel: ";
        cin >> tickets;

        totalSeats += tickets;

        cout << "Tickets Cancelled\n";
        cout << "Seats Remaining: " << totalSeats << endl;
    }

    void checkAvailability()
    {
        cout << "Seats Available: " << totalSeats << endl;
    }
};

int main()
{
    BookingSystem system("Music Concert", 50);

    int choice;

    while (true)
    {
        system.displayMenu();

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                system.bookTicket();
                break;

            case 2:
                system.cancelTicket();
                break;

            case 3:
                system.checkAvailability();
                break;

            case 4:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }

    return 0;
}