#include<bits/stdc++.h>
using namespace std;


class Spreadsheet {
public:
    map<pair<char, int>, int> grid;
    Spreadsheet(int rows) {
        
    }
    
    void setCell(string cell, int value) {
        char ch = cell[0];
        string indx = cell.substr(1);
        grid[{ch, stoi(indx)}] = value;
    }
    
    void resetCell(string cell) {
        char ch = cell[0];
        string indx = cell.substr(1);
        grid[{ch, stoi(indx)}] = 0;
    }
    
    int getValue(string formula) {
        string num1, num2;
        char row1 = '@', row2 = '@';
        bool found = false;

        for (char ch : formula) {
            if (found) {
                if (ch >= 'A' and ch <= 'Z') {
                    row2 = ch;
                }
            }
            else {
                if (ch >= 'A' and ch <= 'Z') {
                    row1 = ch;
                }
            }
            if (ch >= '0' and ch <= '9') {
                if (found) {
                    num2 += ch;
                } else {
                    num1 += ch;
                }
            }
            if (ch == '+') {
                found = true;
            }
        }
        int sum = 0;
        if (row1 != '@') {
            sum += grid[{row1, stoi(num1)}];
        } else {
            sum += stoi(num1);
        }

        if (row2 != '@') {
            sum += grid[{row2, stoi(num2)}];
        } else {
            sum += stoi(num2);
        }

        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */


 int main() {
     map<pair<char, int>, int> grid;

     cout << grid[{'A', 10}];
 }