#include "LIST.h"
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

Task::Task(string descrip, string prior, string duedat, string cate, bool comp)
    : description(descrip), priority(prior), dueDate(duedat), category(cate), completed(comp) {}

    //getters
string Task::get_desc() const { return description; }
string Task::get_prior() const { return priority; }
string Task::get_date() const { return dueDate; }
string Task::get_category() const { return category; }
bool Task::is_complet() const { return completed; }


//setters
void Task::set_desc(const string& desc) { description = desc; }
void Task::set_priority(const string& prior) { priority = prior; }
void Task::set_date(const string& date) { dueDate = date; }
void Task::set_category(const string& cate) { category = cate; }
void Task::set_completed(bool comp) { completed = comp; }

//fileum pahelu hertakanutyun
string Task::avel_fileum() const {
    return description + "/" + priority + "/" + dueDate + "/" + category + "/" + (completed ? "1" : "0");
}


Task Task::hanel_fileic(const string& line) {
    stringstream ss(line);
    string desc, prio, due, cat, comp;
    getline(ss, desc, '/');
    getline(ss, prio, '/');
    getline(ss, due, '/');
    getline(ss, cat, '/');
    getline(ss, comp, '/');
    return Task(desc, prio, due, cat, comp == "1");
}

void Task::print_list(int index) const {
    cout << left << setw(3) << index << setw(30) << description
         << setw(10) << priority << setw(12) << dueDate
         << setw(12) << category << setw(12)
         << (completed ? "Completed" : "In process") << endl;
}
