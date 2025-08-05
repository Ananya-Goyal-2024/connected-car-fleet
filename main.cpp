#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;


enum class Status {
    ACTIVE,
    MAINTENANCE,
    DECOMMISSIONED
};


string statusToString(Status status) {
    switch (status) {
        case Status::ACTIVE: return "Active";
        case Status::MAINTENANCE: return "Maintenance";
        case Status::DECOMMISSIONED: return "Decommissioned";
        default: return "Unknown";
    }
}

class Vehicle {
public:
    string vin;
    string manufacturer;
    string model;
    string fleet_id;
    string owner;
    Status status;

    void display() const {
        cout << "VIN: " << vin << ", Manufacturer: " << manufacturer
             << ", Model: " << model << ", Fleet: " << fleet_id
             << ", Owner: " << owner << ", Status: " << statusToString(status) << endl;
    }
};


class VehicleManager {
private:
    unordered_map<string, Vehicle> vehicles;

public:
    void addVehicle() {
        Vehicle v;
        int statusInput;

        cout << "Enter VIN: ";
        cin >> v.vin;

        if (vehicles.count(v.vin)) {
            cout << "Vehicle with this VIN already exists.\n";
            return;
        }

        cout << "Enter Manufacturer: ";
        cin >> v.manufacturer;
        cout << "Enter Model: ";
        cin >> v.model;
        cout << "Enter Fleet ID: ";
        cin >> v.fleet_id;
        cout << "Enter Owner: ";
        cin >> v.owner;
        cout << "Enter Status (0: Active, 1: Maintenance, 2: Decommissioned): ";
        cin >> statusInput;

        switch (statusInput) {
            case 0: v.status = Status::ACTIVE; break;
            case 1: v.status = Status::MAINTENANCE; break;
            case 2: v.status = Status::DECOMMISSIONED; break;
            default: cout << "Invalid status.\n"; return;
        }

        vehicles[v.vin] = v;
        cout << "Vehicle added successfully.\n";
    }

    void displayVehicles() const {
        if (vehicles.empty()) {
            cout << "No vehicles found.\n";
            return;
        }

        for (const auto& pair : vehicles) {
            pair.second.display();
        }
    }

    void removeVehicle() {
        string vin;
        cout << "Enter VIN to remove: ";
        cin >> vin;

        if (vehicles.erase(vin)) {
            cout << "Vehicle removed successfully.\n";
        } else {
            cout << "Vehicle not found.\n";
        }
    }

    void searchVehicle() const {
        string vin;
        cout << "Enter VIN to search: ";
        cin >> vin;

        auto it = vehicles.find(vin);
        if (it != vehicles.end()) {
            it->second.display();
        } else {
            cout << "Vehicle not found.\n";
        }
    }

    void updateVehicle() {
        string vin;
        cout << "Enter VIN to update: ";
        cin >> vin;

        auto it = vehicles.find(vin);
        if (it == vehicles.end()) {
            cout << "Vehicle not found.\n";
            return;
        }

        int statusInput;
        cout << "Enter new Manufacturer: ";
        cin >> it->second.manufacturer;
        cout << "Enter new Model: ";
        cin >> it->second.model;
        cout << "Enter new Fleet ID: ";
        cin >> it->second.fleet_id;
        cout << "Enter new Owner: ";
        cin >> it->second.owner;
        cout << "Enter new Status (0: Active, 1: Maintenance, 2: Decommissioned): ";
        cin >> statusInput;

        switch (statusInput) {
            case 0: it->second.status = Status::ACTIVE; break;
            case 1: it->second.status = Status::MAINTENANCE; break;
            case 2: it->second.status = Status::DECOMMISSIONED; break;
            default: cout << "Invalid status.\n"; return;
        }

        cout << "Vehicle updated successfully.\n";
    }
};

int main() {
    VehicleManager manager;
    int choice;

    while (true) {
        cout << "\n--- Vehicle Fleet Management ---\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Display All Vehicles\n";
        cout << "3. Remove Vehicle\n";
        cout << "4. Search Vehicle\n";
        cout << "5. Update Vehicle\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addVehicle(); break;
            case 2: manager.displayVehicles(); break;
            case 3: manager.removeVehicle(); break;
            case 4: manager.searchVehicle(); break;
            case 5: manager.updateVehicle(); break;
            case 0: return 0;
            default: cout << "Invalid choice. Try again.\n";

        }
    }
}




