#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

class User {
public:
    string userId, name, address, phoneNumber, email;
    User(string id, string n, string addr, string phone, string mail)
        : userId(id), name(n), address(addr), phoneNumber(phone), email(mail) {}
    void displayUser() const {
        cout << "User ID: " << userId << "\nName: " << name << "\nAddress: " << address
            << "\nPhone Number: " << phoneNumber << "\nEmail: " << email << endl;
    }
};

class Computer {
public:
    string computerId, memoryCapacity, processorModel, motherboardCompany;
    Computer(string id, string mem, string proc, string mb)
        : computerId(id), memoryCapacity(mem), processorModel(proc), motherboardCompany(mb) {}
    void displayComputer() const {
        cout << "Computer ID: " << computerId << "\nMemory Capacity: " << memoryCapacity
            << "\nProcessor Model: " << processorModel << "\nMotherboard Company: " << motherboardCompany << endl;
    }
};

class CafeManagementSystem {
private:
    vector<User> users;
    vector<Computer> computers;
    map<string, time_t> loginTimes;
public:
    void login() {
        string password;
        cout << "Enter password: ";
        cin >> password;
        if (password == "admin") {
            cout << "Login successful!" << endl;
        }
        else {
            cout << "Incorrect password!" << endl;
        }
    }

    void addUser() {
        string userId, name, address, phoneNumber, email;
        cout << "Enter User ID: "; cin >> userId;
        cout << "Enter Name: "; cin >> name;
        cout << "Enter Address: "; cin >> address;
        cout << "Enter Phone Number: "; cin >> phoneNumber;
        cout << "Enter Email: "; cin >> email;
        users.push_back(User(userId, name, address, phoneNumber, email));
        cout << "User added successfully!" << endl;
    }

    void displayUsers() const {
        for (const auto& user : users) {
            user.displayUser();
            cout << "-----------------------" << endl;
        }
    }

    void addComputer() {
        string computerId, memoryCapacity, processorModel, motherboardCompany;
        cout << "Enter Computer ID: "; cin >> computerId;
        cout << "Enter Memory Capacity: "; cin >> memoryCapacity;
        cout << "Enter Processor Model: "; cin >> processorModel;
        cout << "Enter Motherboard Company: "; cin >> motherboardCompany;
        computers.push_back(Computer(computerId, memoryCapacity, processorModel, motherboardCompany));
        cout << "Computer added successfully!" << endl;
    }

    void displayComputers() const {
        for (const auto& computer : computers) {
            computer.displayComputer();
            cout << "-----------------------" << endl;
        }
    }

    void bookComputer(string userId, string computerId) {
        time_t now = time(0);
        loginTimes[userId] = now;
        cout << "Computer booked successfully for user " << userId << endl;
    }

    void logoutComputer(string userId) {
        time_t now = time(0);
        if (loginTimes.find(userId) != loginTimes.end()) {
            time_t startTime = loginTimes[userId];
            double duration = difftime(now, startTime) / 60; // duration in minutes
            cout << "User " << userId << " logged out. Duration: " << duration << " minutes." << endl;
            loginTimes.erase(userId);
        }
        else {
            cout << "User not logged in." << endl;
        }
    }

    void calculateCharges(string userId) {
        time_t now = time(0);
        if (loginTimes.find(userId) != loginTimes.end()) {
            time_t startTime = loginTimes[userId];
            double duration = difftime(now, startTime) / 60; // duration in minutes
            double charges = duration * 0.5; // assume $0.5 per minute
            cout << "Charges for user " << userId << ": $" << charges << endl;
        }
        else {
            cout << "User not logged in." << endl;
        }
    }

    void renewMembership(string userId) {
        cout << "Membership for user " << userId << " renewed successfully." << endl;
    }

    void saveData() {
        // Placeholder for save logic
        cout << "Data saved successfully." << endl;
    }

    void loadData() {
        // Placeholder for load logic
        cout << "Data loaded successfully." << endl;
    }
};

int main() {
    CafeManagementSystem system;
    system.loadData();
    system.login();

    int choice;
    do {
        cout << "1. Master Entry\n2. Cafe Management\n3. Exit\n";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "1. Add New Member\n2. Show Member\n3. Update Record\n4. Delete Record\n5. Search Record\n6. Return\n";
            // Handle master entry operations
            break;
        case 2:
            cout << "1. Member Login\n2. Member Logout\n3. Non-Member Login\n4. Non-Member Logout\n5. Take Charges\n6. Show Charges\n7. Return\n";
            // Handle cafe management operations
            break;
        case 3:
            system.saveData();
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 3);

    return 0;
}

