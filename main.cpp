// #include <iostream>
// #include <unordered_map>
// #include <string>
// using namespace std;

// enum class Status {
//     ACTIVE,
//     MAINTENANCE,
//     DECOMMISSIONED
// };

// string statusToString(Status status) {
//     switch (status) {
//         case Status::ACTIVE: return "Active";
//         case Status::MAINTENANCE: return "Maintenance";
//         case Status::DECOMMISSIONED: return "Decommissioned";
//         default: return "Unknown";
//     }
// }


// struct TelemetryData {
//     double latitude;
//     double longitude;
//     double speed;
//     string engineStatus; // On, Off, Idle
//     int fuelLevel;       // percentage
//     int odometer;        // in km
//     string diagnosticCode;
//     string timestamp;
// };

// class Vehicle {
// public:
//     string vin;
//     string manufacturer;
//     string model;
//     string fleet_id;
//     string owner;
//     Status status;
//     TelemetryData telemetry;

//     void display() const {
//         cout << "VIN: " << vin << ", Manufacturer: " << manufacturer
//              << ", Model: " << model << ", Fleet: " << fleet_id
//              << ", Owner: " << owner << ", Status: " << statusToString(status) << endl;
//     }

//     void displayTelemetry() const {
//         cout << "--- Telemetry Data ---\n";
//         cout << "Location: (" << telemetry.latitude << ", " << telemetry.longitude << ")\n";
//         cout << "Speed: " << telemetry.speed << " km/h\n";
//         cout << "Engine Status: " << telemetry.engineStatus << endl;
//         cout << "Fuel Level: " << telemetry.fuelLevel << "%\n";
//         cout << "Odometer: " << telemetry.odometer << " km\n";
//         cout << "Diagnostic Code: " << telemetry.diagnosticCode << endl;
//         cout << "Timestamp: " << telemetry.timestamp << endl;
//     }
// };

// class VehicleManager {
// private:
//     unordered_map<string, Vehicle> vehicles;

// public:
//     void addVehicle() {
//         Vehicle v;
//         int statusInput;

//         cout << "Enter VIN: ";
//         cin >> v.vin;

//         if (vehicles.count(v.vin)) {
//             cout << "Vehicle with this VIN already exists.\n";
//             return;
//         }

//         cout << "Enter Manufacturer: ";
//         cin >> v.manufacturer;
//         cout << "Enter Model: ";
//         cin >> v.model;
//         cout << "Enter Fleet ID: ";
//         cin >> v.fleet_id;
//         cout << "Enter Owner: ";
//         cin >> v.owner;
//         cout << "Enter Status (0: Active, 1: Maintenance, 2: Decommissioned): ";
//         cin >> statusInput;

//         switch (statusInput) {
//             case 0: v.status = Status::ACTIVE; break;
//             case 1: v.status = Status::MAINTENANCE; break;
//             case 2: v.status = Status::DECOMMISSIONED; break;
//             default: cout << "Invalid status.\n"; return;
//         }

//         vehicles[v.vin] = v;
//         cout << "Vehicle added successfully.\n";
//     }

//     void displayVehicles() const {
//         if (vehicles.empty()) {
//             cout << "No vehicles found.\n";
//             return;
//         }

//         for (const auto& pair : vehicles) {
//             pair.second.display();
//         }
//     }

//     void removeVehicle() {
//         string vin;
//         cout << "Enter VIN to remove: ";
//         cin >> vin;

//         if (vehicles.erase(vin)) {
//             cout << "Vehicle removed successfully.\n";
//         } else {
//             cout << "Vehicle not found.\n";
//         }
//     }

//     void searchVehicle() const {
//         string vin;
//         cout << "Enter VIN to search: ";
//         cin >> vin;

//         auto it = vehicles.find(vin);
//         if (it != vehicles.end()) {
//             it->second.display();
//         } else {
//             cout << "Vehicle not found.\n";
//         }
//     }

//     void updateVehicle() {
//         string vin;
//         cout << "Enter VIN to update: ";
//         cin >> vin;

//         auto it = vehicles.find(vin);
//         if (it == vehicles.end()) {
//             cout << "Vehicle not found.\n";
//             return;
//         }

//         int statusInput;
//         cout << "Enter new Manufacturer: ";
//         cin >> it->second.manufacturer;
//         cout << "Enter new Model: ";
//         cin >> it->second.model;
//         cout << "Enter new Fleet ID: ";
//         cin >> it->second.fleet_id;
//         cout << "Enter new Owner: ";
//         cin >> it->second.owner;
//         cout << "Enter new Status (0: Active, 1: Maintenance, 2: Decommissioned): ";
//         cin >> statusInput;

//         switch (statusInput) {
//             case 0: it->second.status = Status::ACTIVE; break;
//             case 1: it->second.status = Status::MAINTENANCE; break;
//             case 2: it->second.status = Status::DECOMMISSIONED; break;
//             default: cout << "Invalid status.\n"; return;
//         }

//         cout << "Vehicle updated successfully.\n";
//     }

//     void updateTelemetry() {
//         string vin;
//         cout << "Enter VIN to update telemetry: ";
//         cin >> vin;

//         auto it = vehicles.find(vin);
//         if (it == vehicles.end()) {
//             cout << "Vehicle not found.\n";
//             return;
//         }

//         TelemetryData t;
//         cout << "Enter Latitude: "; cin >> t.latitude;
//         cout << "Enter Longitude: "; cin >> t.longitude;
//         cout << "Enter Speed (km/h): "; cin >> t.speed;
//         cout << "Enter Engine Status (On/Off/Idle): "; cin >> t.engineStatus;
//         cout << "Enter Fuel/Battery Level (%): "; cin >> t.fuelLevel;
//         cout << "Enter Odometer Reading (km): "; cin >> t.odometer;
//         cout << "Enter Diagnostic Code (or 'None'): "; cin.ignore(); getline(cin, t.diagnosticCode);
//         cout << "Enter Timestamp (e.g., 2025-08-05 10:00): "; getline(cin, t.timestamp);

//         it->second.telemetry = t;

//         cout << "Telemetry updated successfully!\n";
//     }

//     void displayTelemetry() const {
//         string vin;
//         cout << "Enter VIN to display telemetry: ";
//         cin >> vin;

//         auto it = vehicles.find(vin);
//         if (it == vehicles.end()) {
//             cout << "Vehicle not found.\n";
//             return;
//         }

//         it->second.displayTelemetry();
//     }
// };

// int main() {
//     VehicleManager manager;
//     int choice;

//     while (true) {
//         cout << "\n--- Vehicle Fleet Management ---\n";
//         cout << "1. Add Vehicle\n";
//         cout << "2. Display All Vehicles\n";
//         cout << "3. Remove Vehicle\n";
//         cout << "4. Search Vehicle\n";
//         cout << "5. Update Vehicle\n";
//         cout << "6. Update Telemetry Data\n";
//         cout << "7. Display Vehicle Telemetry\n";
//         cout << "0. Exit\n";
//         cout << "Enter choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: manager.addVehicle(); break;
//             case 2: manager.displayVehicles(); break;
//             case 3: manager.removeVehicle(); break;
//             case 4: manager.searchVehicle(); break;
//             case 5: manager.updateVehicle(); break;
//             case 6: manager.updateTelemetry(); break;
//             case 7: manager.displayTelemetry(); break;
//             case 0: return 0;
//             default: cout << "Invalid choice. Try again.\n";
//         }
//     }
// }








#include <iostream>
#include <unordered_map>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>
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

struct TelemetryData {
    double latitude;
    double longitude;
    double speed;
    string engineStatus; // On, Off, Idle
    int fuelLevel;       // percentage
    int odometer;        // in km
    string diagnosticCode;
    string timestamp;    // format: "YYYY-MM-DD HH:MM"
};

class Vehicle {
public:
    string vin;
    string manufacturer;
    string model;
    string fleet_id;
    string owner;
    Status status;
    TelemetryData telemetry;

    void display() const {
        cout << "VIN: " << vin << ", Manufacturer: " << manufacturer
             << ", Model: " << model << ", Fleet: " << fleet_id
             << ", Owner: " << owner << ", Status: " << statusToString(status) << endl;
    }

    void displayTelemetry() const {
        cout << "--- Telemetry Data ---\n";
        cout << "Location: (" << telemetry.latitude << ", " << telemetry.longitude << ")\n";
        cout << "Speed: " << telemetry.speed << " km/h\n";
        cout << "Engine Status: " << telemetry.engineStatus << endl;
        cout << "Fuel Level: " << telemetry.fuelLevel << "%\n";
        cout << "Odometer: " << telemetry.odometer << " km\n";
        cout << "Diagnostic Code: " << telemetry.diagnosticCode << endl;
        cout << "Timestamp: " << telemetry.timestamp << endl;
    }
};

time_t parseTimestamp(const string& timestamp) {
    tm t = {};
    istringstream ss(timestamp);
    ss >> get_time(&t, "%Y-%m-%d %H:%M");
    if (ss.fail()) return 0;
    return mktime(&t);
}

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

    void updateTelemetry() {
        string vin;
        cout << "Enter VIN to update telemetry: ";
        cin >> vin;

        auto it = vehicles.find(vin);
        if (it == vehicles.end()) {
            cout << "Vehicle not found.\n";
            return;
        }

        TelemetryData t;
        cout << "Enter Latitude: "; cin >> t.latitude;
        cout << "Enter Longitude: "; cin >> t.longitude;
        cout << "Enter Speed (km/h): "; cin >> t.speed;
        cout << "Enter Engine Status (On/Off/Idle): "; cin >> t.engineStatus;
        cout << "Enter Fuel/Battery Level (%): "; cin >> t.fuelLevel;
        cout << "Enter Odometer Reading (km): "; cin >> t.odometer;
        cout << "Enter Diagnostic Code (or 'None'): "; cin.ignore(); getline(cin, t.diagnosticCode);
        cout << "Enter Timestamp (e.g., 2025-08-05 10:00): "; getline(cin, t.timestamp);

        it->second.telemetry = t;

        cout << "Telemetry updated successfully!\n";
    }

    void displayTelemetry() const {
        string vin;
        cout << "Enter VIN to display telemetry: ";
        cin >> vin;

        auto it = vehicles.find(vin);
        if (it == vehicles.end()) {
            cout << "Vehicle not found.\n";
            return;
        }

        it->second.displayTelemetry();
    }

    void displayFleetAnalytics() const {
        int active = 0, inactive = 0;
        int fuelSum = 0, fuelCount = 0;
        int distanceTraveled = 0;
        unordered_map<string, int> alertSummary;

        time_t now = time(nullptr);

        for (const auto& pair : vehicles) {
            const Vehicle& v = pair.second;
            time_t ts = parseTimestamp(v.telemetry.timestamp);

            if (ts != 0 && difftime(now, ts) <= 86400) {
                active++;
                distanceTraveled += v.telemetry.odometer;
            } else {
                inactive++;
            }

            if (v.telemetry.fuelLevel >= 0) {
                fuelSum += v.telemetry.fuelLevel;
                fuelCount++;
            }

            if (!v.telemetry.diagnosticCode.empty() && v.telemetry.diagnosticCode != "None") {
                alertSummary[v.telemetry.diagnosticCode]++;
            }
        }

        cout << "\n--- Fleet Analytics ---\n";
        cout << "Active Vehicles: " << active << endl;
        cout << "Inactive Vehicles: " << inactive << endl;
        if (fuelCount > 0)
            cout << "Average Fuel/Battery Level: " << (fuelSum / fuelCount) << "%" << endl;
        else
            cout << "Average Fuel/Battery Level: N/A\n";
        cout << "Total Distance Traveled (last 24h): " << distanceTraveled << " km\n";

        cout << "Alert Summary (by type):\n";
        if (alertSummary.empty()) {
            cout << "No alerts.\n";
        } else {
            for (const auto& a : alertSummary) {
                cout << "  " << a.first << ": " << a.second << " alerts\n";
            }
        }
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
        cout << "6. Update Telemetry Data\n";
        cout << "7. Display Vehicle Telemetry\n";
        cout << "8. Display Fleet Analytics\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addVehicle(); break;
            case 2: manager.displayVehicles(); break;
            case 3: manager.removeVehicle(); break;
            case 4: manager.searchVehicle(); break;
            case 5: manager.updateVehicle(); break;
            case 6: manager.updateTelemetry(); break;
            case 7: manager.displayTelemetry(); break;
            case 8: manager.displayFleetAnalytics(); break;
            case 0: return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
}
