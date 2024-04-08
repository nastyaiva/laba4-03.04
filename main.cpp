#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <fstream>
#include <string>

class Employee {
public:
    std::string name;
    std::string hire_date;
    std::string position;
    double base_salary;

    Employee() : name(""), hire_date(""), position(""), base_salary(0.0) {}

    Employee(const std::string& n, const std::string& h, const std::string& p, double s)
        : name(n), hire_date(h), position(p), base_salary(s) {}

    friend std::ostream& operator<<(std::ostream& os, const Employee& e) {
        os << e.name << ": " << e.hire_date << ", " << e.position << ", " << e.base_salary << "$";
        return os;
    }

    bool operator<(const Employee& other) const {
        return name > other.name;
    }
};

bool compareByName(const Employee& a, const Employee& b) {
    return a.name > b.name;
}


int main() {
    std::deque<Employee> employees;
    std::ifstream input("input.txt");
    std::string name, hire_date, position;
    double base_salary;

    while (getline(input, name)) {
        getline(input, hire_date);
        input >> position >> base_salary;
        input.ignore();
        employees.push_back(Employee(name, hire_date, position, base_salary));
    }
    input.close();

    std::ofstream output("output.txt");
    output << "Original container:\n";
    std::cout << "Original container:\n";
    for (const auto& e : employees) {
        output << e << std::endl;
        std::cout << e << std::endl;
    }

    std::deque<Employee> originalEmployees = employees;
    std::list<Employee> copiedEmployees;

    copiedEmployees.resize(originalEmployees.size());

    std::copy(originalEmployees.begin(), originalEmployees.end(), copiedEmployees.begin());

    std::sort(employees.begin(), employees.end());

    std::list<Employee> employees_list(employees.begin(), employees.end());

    output << "\nSorted container:\n";
    std::cout << "\nSorted container:\n";
    for (const auto& e : employees_list) {
        output << e << std::endl;
        std::cout << e << std::endl;
    }

    output << "\nCopied container:\n";
    std::cout << "\nCopied container:\n";
    for (const auto& e : copiedEmployees) {
        output << e << std::endl;
        std::cout << e << std::endl;
    }

    output.close();

    return 0;
}
