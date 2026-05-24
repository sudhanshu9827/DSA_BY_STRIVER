#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line = "101 Alex 25";
    std::stringstream ss(line); // Initialize stringstream with the string


    int id;
    std::string name;
    int age;

    // Extract data using the >> operator, which stops at whitespace
    ss >> id >> name >> age; 

    std::cout << "ID: " << id << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    
    return 0;
}