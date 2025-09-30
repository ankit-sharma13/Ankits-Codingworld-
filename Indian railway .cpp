#include <iostream>
#include <string>
using namespace std;

struct Passenger {
    int seatNo;
    string name;
    int age;
    char gender;
    Passenger* next;
};
Passenger* head = NULL;

void addPassenger(int seatNo, string name, int age, char gender) {
    Passenger* newNode = new Passenger();
    newNode->seatNo = seatNo;
    newNode->name = name;
    newNode->age = age;
    newNode->gender = gender;
    newNode->next = head;
    head = newNode;
}

void removePassenger(int seatNo) {
    Passenger* temp = head, *prev = NULL;
    while (temp != NULL && temp->seatNo != seatNo) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) head = temp->next;
    else prev->next = temp->next;
    delete temp;
}

void displayPassengers() {
    if (head == NULL) {
        cout << "No passengers booked.\n";
        return;
    }
    Passenger* temp = head;
    while (temp != NULL) {
        cout << "Seat No: " << temp->seatNo
             << " | Name: " << temp->name
             << " | Age: " << temp->age
             << " | Gender: " << temp->gender << endl;
        temp = temp->next;
    }
}
int main() {
    int n = 30; 
    int* seats = new int[n]; 
    for (int i = 0; i < n; i++) seats[i] = 0; 

    int choice;
    do {
        cout << "## Railway Reservation System ***\n";
        cout << "1. Book Ticket\n2. Cancel Ticket\n3. View Train Status\n4. View Passenger List\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            string name; int age; char gender;
            int seatNo = -1;
            for (int i = 0; i < n; i++) {
                if (seats[i] == 0) { seatNo = i + 1; break; }
            }
            if (seatNo == -1) {
                cout << "No seats available!\n";
            } else {
                cout << "Enter Name: "; cin >> name;
                cout << "Enter Age: "; cin >> age;
                cout << "Enter Gender (M/F): "; cin >> gender;
                seats[seatNo - 1] = 1;
                addPassenger(seatNo, name, age, gender);
                cout << "Ticket booked! Seat No: " << seatNo <<"\nThanyou for visiting indian railway!\n"<< endl;
            }
        }
        else if (choice == 2) {
            int seatNo;
            cout << "Enter Seat No to cancel: ";
            cin >> seatNo;
            if (seatNo < 1 || seatNo > n || seats[seatNo - 1] == 0) {
                cout << "Invalid Seat Number or already empty.\n";
            } else {
                seats[seatNo - 1] = 0;
                removePassenger(seatNo);
                cout << "Ticket cancelled for Seat No: " << seatNo << endl;
            }
        }
        else if (choice == 3) {
            cout << "\nTrain Status:\n";
            for (int i = 0; i < n; i++) {
                cout << "Seat " << i + 1 << ": " 
                     << (seats[i] ? "Booked" : "Available") << endl;
            }
        }
        else if (choice == 4) {
            cout << "\nPassenger List:\n";
            displayPassengers();
        }
        else if (choice == 5) {
            cout << "Exiting... Freeing memory.\n";
        }
        else {
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);
    delete[] seats;
    while (head != NULL) {
        Passenger* temp = head;
        head = head->next;
        delete temp;
    }
}