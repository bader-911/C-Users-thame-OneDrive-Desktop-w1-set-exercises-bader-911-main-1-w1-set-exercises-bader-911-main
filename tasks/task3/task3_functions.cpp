#include <iostream>
#include <fstream>
#include <sstream>
#include "task3_functions.h"

string findCorners(std::string filePath)
{
    string result;

std::string findCorners(std::string strFileName) {
    std::ifstream inputFile(strFileName); // Open the file
    std::string line;
    int rowCount = 0;
    int colCount = 0;

    // Find number of rows and columns in the grid
    while (std::getline(inputFile, line)) {
        rowCount++;
        if (rowCount == 1) {
            std::stringstream ss(line);
            std::string cell;
            while (ss >> cell) {
                colCount++;
            }
        }
    }
    inputFile.clear();
    inputFile.seekg(0, std::ios::beg);

    int topLeftRow = -1, topLeftCol = -1, bottomRightRow = -1, bottomRightCol = -1;
    bool found = false;

    // Loop through the grid to find the coordinates of the first rectangle
    for (int i = 0; i < rowCount; ++i) {
        std::getline(inputFile, line);
        std::stringstream ss(line);
        char cell;
        int col = 0;
        while (ss >> cell) {
            if (cell == '*') {
                if (!found) {
                    topLeftRow = i;
                    topLeftCol = col;
                    found = true;
                }
                bottomRightRow = i;
                bottomRightCol = col;
            }
            col++;
        }
    }
    inputFile.close();

    // Prepare the output string with the coordinates
    std::ostringstream output;
    output << "{\"topLeft\" : [" << topLeftRow << "," << topLeftCol << "], \"bottomRight\" : ["
           << bottomRightRow << "," << bottomRightCol << "]}";

    return output.str();
}

// Leave main function unchanged
int main() {
    std::string result = findCorners("task3data-1.txt"); // Replace "task3data-1.txt" with your file name
    std::cout << result << std::endl;
    return 0;
}
 

