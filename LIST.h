#ifndef LIST_H
#define LIST_H

#include <string>
using namespace std;

class Task {
private:
    string description;
    string priority;
    string dueDate;
    string category;
    bool completed;

public:
    Task(string descrip = "", string prior = "high", string duedat = "", string cate = "", bool comp = false);

    // Getters
    string get_desc() const;
    string get_prior() const;
    string get_date() const;
    string get_category() const;
    bool is_complet() const;

    // Setters
    void set_desc(const string& desc);
    void set_priority(const string& prior);
    void set_date(const string& date);
    void set_category(const string& cate);
    void set_completed(bool comp);

    // File input/output
    string avel_fileum() const;
    static Task hanel_fileic(const string& line);

    // Display
    void print_list(int index) const;
};

#endif
