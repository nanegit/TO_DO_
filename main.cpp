#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>
#include "LIST.cpp"
using namespace std;

// Save tasks
void save_in_file(const vector<Task>& tasks) {
    ofstream file("file.txt");
    for (const Task& task : tasks) {
        file << task.avel_fileum() << endl;
    }

    file.close();
}

// Load tasks
void loadTasksFromFile(vector<Task>& tasks) {
    ifstream file("file.txt");
    string line;
    while (getline(file, line)) {
        tasks.push_back(Task::hanel_fileic(line));
    }
    file.close();
}

// Print tasks
void printTasks(const vector<Task>& tasks) {
    cout << "\n----------------- TO-DO LIST ----------------------------------------------------------\n";
    cout << left << setw(4) << "ID" << setw(25) << "Task"
         << setw(12) << "Priority" << setw(12) << "Due Date"
         << setw(12) << "Category" << setw(12) << "Status" << endl;
    cout << "------------------------------------------------------------------------------------------\n";
    
    for (size_t i = 0; i < tasks.size(); i++) {
        tasks[i].print_list(i + 1);
    }
    cout << "-------------------------------------------------------------------------------------------\n";
}

int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);
    
    int choice;
    do {
        cout << "\n--- TO-DO MENU ---\n";
        cout << "1. Add Task\n2. Delete Task\n3. Mark Task as Completed\n4. View Tasks\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string desc, prio, due, cat;
                cout << "Enter description: ";
                getline(cin, desc);
                cout << "Enter priority (low/medium/high): ";
                getline(cin, prio);
                cout << "Enter due date: ";
                getline(cin, due);
                cout << "Enter category: ";
                getline(cin, cat);
                tasks.push_back(Task(desc, prio, due, cat, false));
                save_in_file(tasks);
                break;
            }
            case 2: {
                int id;
                printTasks(tasks);
                cout << "Enter ID to delete: ";
                cin >> id;
                if (id >= 1 && id <= tasks.size()) {
                    tasks.erase(tasks.begin() + (id - 1));
                    save_in_file(tasks);
                } else {
                    cout << "Invalid ID.\n";
                }
                break;
            }
            case 3: {
                int id;
                printTasks(tasks);
                cout << "Enter ID to mark as completed: ";
                cin >> id;
                if (id >= 1 && id <= tasks.size()) {
                    tasks[id - 1].set_completed(true);
                    save_in_file(tasks);
                } else {
                    cout << "Invalid ID.\n";
                }
                break;
            }
            case 4:
                printTasks(tasks);
                break;
            case 0:
                cout << "END\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
