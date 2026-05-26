/*
Author: Preme Malaviphusit
Assignment: HW1
Date due: 05 28
I pledge that I have completed this assignment without the use of AI tools or
collaborating with anyone else, in conformance with the NYU School of
Engineering Policies and Procedures on Academic Misconduct.
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

//prototypes
bool isInVector(const vector<int>& nums, int target);
void makeUnique(const vector<int>& nums, vector<int>& unique);
void fillVecFromFile(vector<int>& vFile);

//output Q4
void writeVecToFile(const vector<int>& nums);

int main() {
    vector<int> vFile;
    fillVecFromFile(vFile);
    vector<int> unique;
    makeUnique(vFile, unique);
    writeVecToFile(unique);
}

// Q1
//find if the target number is in the vector
bool isInVector(const vector<int>& nums, int target) {
    for (int x : nums) { //iterate through the vector
        if (x == target) { //check if the target number is inside
            return true;
        }
    }
    return false;
}


// Q2
//eliminate any duplicate numbers
void makeUnique(const vector<int>& nums, vector<int>& unique) {
    for (int x : nums) { //iterate through vector
        if (!isInVector(unique, x)) { //if not in the vector
            unique.push_back(x); //push into the unique vector
        }
    }
}

// Q3
//get the numbers in the file and fill them into a vector
void fillVecFromFile(vector<int>& vFile) {
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    ifstream file;
    file.open(filename);
    //check if the file exists
    if (!file) {
        cout << "Unable to open file." << endl;
        exit(1);
    }
    int num;
    //for each number, push into a vector
    while (file>>num) {
        vFile.push_back(num);
    }
}

// Q4
//write vector of numbers into uniqe_ints.txt file
void writeVecToFile(const vector<int>& nums) {
    ofstream outFile;
    outFile.open("uniqe_ints.txt");
    if (!outFile) {
        cout << "uniqe_ints.txt doesn't exist." << endl;
        exit(1);
    }
    //loop through each number in nums vector to print into the output file
    for (int x : nums) {
        outFile << x << " ";
    }
}
