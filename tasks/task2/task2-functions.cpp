#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

// Structure to store x and y coordinates as a point
struct Point {
    int x, y;
};

int main() {
    // Open the file containing the coordinates
    std::ifstream inputFile("task2data-1"); // Replace "task2data-1" with your file name
    std::vector<Point> points; // Vector to store the points

    // Check if the file is open
    if (inputFile.is_open()) {
        char bracket;

        // Loop to read characters from the file
        while (inputFile >> bracket) {
            // If an opening brace '{' is encountered
            if (bracket == '{') {
                std::string line;
                // Read the file line by line until a closing brace '}' is found
                while (std::getline(inputFile, line, '}')) {
                    std::stringstream ss(line); // Create a stringstream to process the line

                    char ch;
                    // Loop to extract characters from the stringstream
                    while (ss >> ch) {
                        // Check if the character is a digit or a negative sign (for negative numbers)
                        if (isdigit(ch) || ch == '-') {
                            ss.putback(ch); // Put back the character into stringstream
                            int x, y;
                            // Ext

