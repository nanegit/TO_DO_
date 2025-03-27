#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

class Task{
    private:
        string description;
        string priority;
        string dueDate;
        string category;
        bool completed;

    public:
        Task(string descrip="", string prior="high", string duedat="", string cate="", bool comp=false):
        description(descrip),priority(prior),dueDate(duedat),completed(comp){}
        
        //getters
        string get_desc() const{ return description;}
        string get_prior() const{return priority;}
        string get_date() const{return dueDate;}
        string get_category() const{return category;}
        bool is_complet() const {return completed;}


        //setters
        void set_desc(const string& desc){
            description=desc;
        }

        void set_priority(const string& prior){
            priority=prior;
        }

        void set_date(const string& date){
            dueDate=date;
        }

        void set_category(const string& cate){
            category=cate;
        }

        void set_completed(bool comp){
            completed=comp;
        }

        //file-um pahelu hamar
        string toString() const {
            return description + "/" + priority + "/" + dueDate + "/" + category + "/" + (completed ? "1" : "0");
        }

        // Load task from a formatted string
        static Task fromString(const string& line) {
            stringstream ss(line);
            string desc, prio, due, cat, comp;
            getline(ss, desc, '/');
            getline(ss, prio, '/');
            getline(ss, due, '/');
            getline(ss, cat, '/');
            getline(ss, comp, '/');

            return Task(desc, prio, due, cat, comp == "1");
        }

        // Display task in table format
        void printTask(int index) const {
            cout << left << setw(3) << index << setw(30) << description
                << setw(10) << priority << setw(12) << dueDate
                << setw(12) << category << setw(12)
                << (completed ? "✔ Completed" : "Pending") << endl;
            }
};

// Function to save tasks to a file
void saveTasksToFile(const vector<Task>& tasks) {
    ofstream file("tasks.txt");
    for (const Task& task : tasks) {
        file << task.toString() << endl;
    }
    file.close();
}

// Function to load tasks from a file
void loadTasksFromFile(vector<Task>& tasks) {
    ifstream file("tasks.txt");
    string line;
    while (getline(file, line)) {
        tasks.push_back(Task::fromString(line));
    }
    file.close();
}

// Function to display tasks in a table
void printTasks(const vector<Task>& tasks) {
    cout << "\n----------------- TO-DO LIST ----------------------------------------------------------\n";
    cout << left << setw(3) << "ID" << setw(30) << "Task"
         << setw(10) << "Priority" << setw(12) << "Due Date"
         << setw(12) << "Category" << setw(12) << "Status" << endl;
    cout << "------------------------------------------------------------------------------------------\n";
    
    for (size_t i = 0; i < tasks.size(); i++) {
        tasks[i].printTask(i + 1);
    }
    cout << "-------------------------------------------------------------------------------------------\n";
}

int main() {
    vector<Task> tasks;
    loadTasksFromFile(tasks);
    printTasks(tasks);
    return 0;
}
