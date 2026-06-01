#include <iostream>
#include <vector>
#include <string>
#include <limits>


using namespace std;

// -------------------- Car Class --------------------
class Car {
public:
    int carID;
    string brand;
    string model;
    float pricePerDay;
    bool available;

    Car(int id, string b, string m, float price) {
        carID = id;
        brand = b;
        model = m;
        pricePerDay = price;
        available = true;
    }

    void displayCar() {
        cout << "ID: " << carID
             << " | " << brand << " " << model
             << " | Price/Day: " << pricePerDay
             << " | ";
        if (available == true)
            cout << "Available";
        else
            cout << "Rented";
        cout << endl;
    }
};

// -------------------- Customer Class --------------------
class Customer {
public:
    int customerID;
    string name;
    string phoneNumber;
    string address;
    string licenseNumber;

    void registerCustomer() {
        cout << "Enter Customer ID: ";
        cin >> customerID;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Phone Number: ";
        getline(cin, phoneNumber);

        cout << "Enter Address: ";
        getline(cin, address);

        cout << "Enter Driving License Number: ";
        getline(cin, licenseNumber);
    }

    void displayCustomer() {
        cout << "\nCustomer ID: " << customerID
             << " | Name: " << name
             << " | Phone: " << phoneNumber
             << " | Address: " << address
             << " | License: " << licenseNumber << endl;
    }
};

// -------------------- Rental Record Class --------------------
class RentRecord {
public:
    int customerID;
    int carID;
    int days;
    float totalBill;
    bool returned;

    RentRecord(int cid, int carid, int d, float bill) {
        customerID = cid;
        carID = carid;
        days = d;
        totalBill = bill;
        returned = false;
    }

    void display() {
        cout << "\nCustomer ID: " << customerID
             << " | Car ID: " << carID
             << " | Days: " << days
             << " | Bill: " << totalBill
             << " | Status: ";
        if (returned == true)
            cout << "Returned";
        else
            cout << "Rented";
        cout << endl;
    }
};

// -------------------- Global Vectors --------------------
vector<Car> cars;
vector<Customer> customers;
vector<RentRecord> records;

// -------------------- Functions --------------------
void addCar() {
    int id;
    string brand, model;
    float price;

    cout << "Enter Car ID: ";
    cin >> id;
    cout << "Enter Brand: ";
    cin >> brand;
    cout << "Enter Model: ";
    cin >> model;
    cout << "Enter Price per Day: ";
    cin >> price;

    cars.push_back(Car(id, brand, model, price));
    cout << "Car added successfully!\n";
}

void viewCars() {
    cout << "\n--- Car List ---\n";
    for (int i = 0; i < cars.size(); i++) {
        cars[i].displayCar();
    }
}

void viewCustomers() {
    cout << "\n--- Customer List ---\n";
    for (int i = 0; i < customers.size(); i++) {
        customers[i].displayCustomer();
    }
}

void viewRecords() {
    cout << "\n--- Rental Records ---\n";
    for (int i = 0; i < records.size(); i++) {
        records[i].display();
    }
}

// -------------------- RENT FUNCTION --------------------
void rentCar() {
    int carID, customerID, days;

    cout << "Enter Customer ID: ";
    cin >> customerID;

    cout << "Enter Car ID to rent: ";
    cin >> carID;

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].carID == carID && cars[i].available == true) {

            cout << "Enter number of days: ";
            cin >> days;

            float bill = cars[i].pricePerDay * days;
            cars[i].available = false;

            records.push_back(RentRecord(customerID, carID, days, bill));

            cout << "Car rented successfully!\n";
            cout << "Total Bill: " << bill << endl;
            return;
        }
    }
    cout << "Car not available!\n";
}

// -------------------- RETURN FUNCTION --------------------
void returnCar() {
    int carID;

    cout << "Enter Car ID to return: ";
    cin >> carID;

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].carID == carID && cars[i].available == false) {

            cars[i].available = true;

            for (int j = 0; j < records.size(); j++) {
                if (records[j].carID == carID && records[j].returned == false) {
                    records[j].returned = true;
                    cout << "Total Bill: " << records[j].totalBill << endl;
                    break;
                }
            }

            cout << "Car returned successfully!\n";
            return;
        }
    }
    cout << "Invalid Car ID!\n";
}

void deleteCar() {
    int id;
    cout << "Enter Car ID to delete: ";
    cin >> id;

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].carID == id) {
            cars.erase(cars.begin() + i);
            cout << "Car deleted successfully!\n";
            return;
        }
    }
    cout << "Car not found!\n";
}

// -------------------- Main --------------------
int main() {

    // Preloaded Cars
    cars.push_back(Car(1, "Toyota", "Innova", 2000));
    cars.push_back(Car(2, "Honda", "City", 1500));
    cars.push_back(Car(3, "Hyundai", "i20", 1200));
    cars.push_back(Car(4, "Maruti", "Swift", 1000));
    cars.push_back(Car(5, "Tata", "Nexon", 1800));
    cars.push_back(Car(6, "Mahindra", "Scorpio", 2200));
    cars.push_back(Car(7, "Kia", "Seltos", 2000));
    cars.push_back(Car(8, "Hyundai", "Creta", 1900));
    cars.push_back(Car(9, "Toyota", "Fortuner", 3500));
    cars.push_back(Car(10, "Honda", "Amaze", 1300));
    cars.push_back(Car(11, "Maruti", "Baleno", 1400));
    cars.push_back(Car(12, "Tata", "Harrier", 2500));
    cars.push_back(Car(13, "Mahindra", "XUV700", 3000));
    cars.push_back(Car(14, "Kia", "Sonet", 1700));
    cars.push_back(Car(15, "Hyundai", "Verna", 1600));
    cars.push_back(Car(16, "Toyota", "Glanza", 1300));
    cars.push_back(Car(17, "Honda", "WRV", 1500));
    cars.push_back(Car(18, "Tata", "Punch", 1100));
    cars.push_back(Car(19, "Maruti", "Brezza", 1800));
    cars.push_back(Car(20, "Mahindra", "Thar", 2800));


    int choice;

    do {
        cout << "\n=============================\n";
        cout << "\n      Car Rental System      \n";
        cout << "\n=============================\n";
        cout << "1. Register Customer\n";
        cout << "2. View Customers\n";
        cout << "3. View Cars\n";
        cout << "4. Rent Car\n";
 /       cout << "5. Return Car\n";
        cout << "6. View Rental Records\n";
        cout << "7. Add Car (Admin)\n";
        cout << "8. Delete Car (Admin)\n";
        cout << "9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;


if (cin.fail()) {
    cout << "Invalid input! Enter numbers only.\n";
    cin.clear();
    cin.ignore(1000, '\n');
    continue;
}

if (choice < 1 || choice > 9) {
    cout << "Invalid input! Please enter 1 to 9.\n";
    continue;
}

        if (choice == 1) {
            Customer c;
            c.registerCustomer();
            customers.push_back(c);
            cout << "Customer Registered Successfully!\n";
        }
        else if (choice == 2) {
            viewCustomers();
        }
        else if (choice == 3) {
            viewCars();

        }
        else if (choice == 4) {
            rentCar();
        }
        else if (choice == 5) {
            returnCar();
        }
        else if (choice == 6) {
            viewRecords();
        }
        else if (choice == 7) {
            addCar();
        }
        else if (choice == 8) {
            deleteCar();
        }
    } while (choice != 9);

    cout << "Thank you!\n";
    return 0;
}