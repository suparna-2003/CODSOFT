#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;

class MovieTicketBooking {
private:
    vector<vector<char> > seats;

public:
    MovieTicketBooking() {
        // Initialize seats as available ('O')
        seats.resize(NUM_ROWS, vector<char>(NUM_COLS, 'O'));
    }

    void displaySeats() {
        cout << "  ";
        for (int col = 0; col < NUM_COLS; ++col) {
            cout << setw(3) << col + 1;
        }
        cout << "\n";

        for (int row = 0; row < NUM_ROWS; ++row) {
            cout << static_cast<char>('A' + row) << " ";
            for (int col = 0; col < NUM_COLS; ++col) {
                cout << setw(3) << seats[row][col];
            }
            cout << "\n";
        }
    }

    bool bookSeat(char row, int col) {
        int rowIndex = row - 'A';
        int colIndex = col - 1;

        if (rowIndex < 0 || rowIndex >= NUM_ROWS || colIndex < 0 || colIndex >= NUM_COLS) {
            cout << "Invalid seat selection!\n";
            return false;
        }

        if (seats[rowIndex][colIndex] == 'X') {
            cout << "Seat already booked!\n";
            return false;
        }

        seats[rowIndex][colIndex] = 'X'; // Mark seat as booked
        cout << "Seat " << row << col << " booked successfully.\n";
        return true;
    }

    double calculateTotalCost(int numOfSeats) {
        const double PRICE_PER_SEAT = 10.0;
        return numOfSeats * PRICE_PER_SEAT;
    }
};

int main() {
    MovieTicketBooking bookingSystem;

    char choice;
    do {
        cout << "\nWelcome to Movie Ticket Booking System\n";
        cout << "1. View available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Calculate total cost\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                bookingSystem.displaySeats();
                break;
            case '2': {
                char row;
                int col;
                cout << "Enter seat (Row and Column): ";
                cin >> row >> col;
                bookingSystem.bookSeat(row, col);
                break;
            }
            case '3': {
                int numOfSeats;
                cout << "Enter the number of seats: ";
                cin >> numOfSeats;
                double totalCost = bookingSystem.calculateTotalCost(numOfSeats);
                cout << "Total cost for " << numOfSeats << " seat(s): $" << totalCost << endl;
                break;
            }
            case '4':
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != '4');

    return 0;
}
