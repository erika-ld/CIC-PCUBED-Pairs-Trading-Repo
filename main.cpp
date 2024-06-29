#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdio>
#include <iomanip>
#include "stock.h"

// Yahoo Finance: https://finance.yahoo.com/?guccounter=1&guce_referrer=aHR0cHM6Ly93d3cuZ29vZ2xlLmNvbS8&guce_referrer_sig=AQAAAKYPLNT2K6cohZ130zXknBtMd81b1MTutcH0ZzCnv0vjDUrBf6o4hYzi9Pl5jfXbbYCn-V3ylSQZmk3_iVA7fjdd5N3q3UrARD-KCno81YF-3KgzLVzye1ltw3RUmfuKwhk1_DUOU85vzbUrBCN5u1952eI-YQ1fTi7COWRSeVVd
// Stocks to be analyzed: Lenovo (LNVGF) & Motorola (MSI)

using namespace std;

const int MAX_ROWS = 254;
const int MAX_COLS = 7;

int main()
{
    cout << "working if this prints" << endl;
    
    // Declaration of vector variables for each column in Lenovo's csv file, sized 300 for row count
    // Purpose: Utilize parallel array data structures to contain attributes of same data element
    vector<string> len_date;
    vector<string> len_open;
    vector<string> len_high;
    vector<string> len_low;
    vector<string> len_close;
    vector<string> len_adj_close;
    vector<string> len_volume;

    /*
    vector<string> len_date;
    vector<double> len_open;
    vector<double> len_high;
    vector<double> len_low;
    vector<double> len_close;
    vector<double> len_adj_close;
    vector<int> len_volume;
    */

    // Declaration of vector variables for each column in Motorola's csv file, sized 300 for row count
    // Purpose: Utilize parallel array data structures to contain attributes of same data element
    vector<string> mot_date;
    vector<string> mot_open;
    vector<string> mot_high;
    vector<string> mot_low;
    vector<string> mot_close;
    vector<string> mot_adj_close;
    vector<string> mot_volume;
    /*
    vector<string> mot_date(MAX_ROWS, "");
    vector<double> mot_open(MAX_ROWS, 0.0);
    vector<double> mot_high(MAX_ROWS, 0.0);
    vector<double> mot_low(MAX_ROWS, 0.0);
    vector<double> mot_close(MAX_ROWS, 0.0);
    vector<double> mot_adj_close(MAX_ROWS, 0.0);
    vector<int> mot_volume(MAX_ROWS, 0);
    */
    // Reading in csv file values for Lenovo and inputting it into corresponding parallel arrays
    // Open the CSV file
    ifstream lenovo_file("LNVGF.csv");
    if (!lenovo_file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string temp_len_arr[MAX_ROWS][MAX_COLS];
    string line;
    int row = 0;

    while (getline(lenovo_file, line) && row < MAX_ROWS)
    {
        stringstream ss(line);
        string cell;
        int col = 0;
        while (getline(ss, cell, ',') && col < MAX_COLS)
        {
            temp_len_arr[row][col] = cell;
            col++;
        }
        row++;
    }

    for (int i = 1; i < MAX_ROWS; ++i)
    {
        int j = 0;
        while (j < 7)
        {
            switch(j)
            {
                case 0:
                    len_date.push_back(temp_len_arr[i][j]);
                    ++j;
                    break;
                case 1:
                    len_open.push_back((temp_len_arr[i][j]));
                    ++j;
                    break;
                case 2:
                    len_high.push_back((temp_len_arr[i][j]));
                    ++j;
                    break;
                case 3:
                    len_low.push_back((temp_len_arr[i][j]));
                    ++j;
                    break;
                case 4:
                    len_close.push_back((temp_len_arr[i][j]));
                    ++j;
                    break;
                case 5:
                    len_adj_close.push_back((temp_len_arr[i][j]));
                    ++j;
                    break;
                case 6:
                    len_volume.push_back((temp_len_arr[i][j]));
                    ++j;
                    break;
            }
        }
    }

    for (string x : len_date)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    for (string x : len_open)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    for (string x : len_high)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    for (string x : len_adj_close)
    {
        cout << x << " ";
    }
    cout << "\n\n";






    //Implementation of motorola

    ifstream motorola_file("MSI.csv");
    if (!motorola_file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string temp_mot_arr[MAX_ROWS][MAX_COLS];
    row = 0;

    while (getline(motorola_file, line) && row < MAX_ROWS)
    {
        stringstream ss(line);
        string cell;
        int col = 0;
        while (getline(ss, cell, ',') && col < MAX_COLS)
        {
            temp_mot_arr[row][col] = cell;
            col++;
        }
        row++;
    }

    for (int i = 1; i < MAX_ROWS; ++i)
    {
        int j = 0;
        while (j < 7)
        {
            switch (j)
            {
            case 0:
                mot_date.push_back(temp_len_arr[i][j]);
                ++j;
                break;
            case 1:
                mot_open.push_back((temp_mot_arr[i][j]));
                ++j;
                break;
            case 2:
                mot_high.push_back((temp_mot_arr[i][j]));
                ++j;
                break;
            case 3:
                mot_low.push_back((temp_mot_arr[i][j]));
                ++j;
                break;
            case 4:
                mot_close.push_back((temp_mot_arr[i][j]));
                ++j;
                break;
            case 5:
                mot_adj_close.push_back((temp_mot_arr[i][j]));
                ++j;
                break;
            case 6:
                mot_volume.push_back((temp_mot_arr[i][j]));
                ++j;
                break;
            }
        }
    }

    for (string x : mot_date)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    for (string x : mot_open)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    for (string x : mot_high)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    for (string x : mot_adj_close)
    {
        cout << x << " ";
    }
    cout << "\n\n";

    // Declared & initialized boolean variables to be used to flag when there is opportunity for exercising pairs trading concepts
    // trade_flag will be raised (set to true) when a certain threshold of separation between stock values is reached
    bool trade_flag = false;

    return 0;
}
