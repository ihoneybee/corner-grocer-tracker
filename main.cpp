#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class GroceryTracker {
private:
    map<string, int> frequencyMap;

public:
    // Processing: read file and count item frequency
    void loadData(const string& filename) {
        ifstream inFile(filename);
        string item;

        while (inFile >> item) {
            frequencyMap[item]++;
        }

        inFile.close();
    }

    // Output: write frequency data to backup file
    void saveData() {
        ofstream outFile("frequency.dat");

        for (const auto& pair : frequencyMap) {
            outFile << pair.first << " " << pair.second << endl;
        }

        outFile.close();
    }

    // Input + Output: user enters item, display frequency
    void searchItem() {
        string item;
        cout << "Enter item: ";
        cin >> item;

        if (frequencyMap.count(item)) {
            cout << item << " " << frequencyMap[item] << endl;
        } else {
            cout << item << " 0" << endl;
        }
    }

    // Output: display all item frequencies
    void printAll() {
        for (const auto& pair : frequencyMap) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Output: display histogram using asterisks
    void printHistogram() {
        for (const auto& pair : frequencyMap) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// Output: display menu
void displayMenu() {
    cout << "\n1. Search item frequency\n";
    cout << "2. Print all frequencies\n";
    cout << "3. Print histogram\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

int main() {
    GroceryTracker tracker;

    // Processing: load data and create backup file
    tracker.loadData("CS210_Project_Three_Input_File.txt");
    tracker.saveData();

    int choice;

    do {
        displayMenu();      // Output
        cin >> choice;      // Input

        switch (choice) {
            case 1:
                tracker.searchItem();
                break;
            case 2:
                tracker.printAll();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                cout << "Exiting program.\n";  // Output
                break;
            default:
                cout << "Invalid choice.\n";   // Output
        }

    } while (choice != 4);

    return 0;
}