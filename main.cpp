#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdio>
#include <iomanip>
#include "stock.h"
#include "stock.cpp"

// Yahoo Finance: https://finance.yahoo.com/?guccounter=1&guce_referrer=aHR0cHM6Ly93d3cuZ29vZ2xlLmNvbS8&guce_referrer_sig=AQAAAKYPLNT2K6cohZ130zXknBtMd81b1MTutcH0ZzCnv0vjDUrBf6o4hYzi9Pl5jfXbbYCn-V3ylSQZmk3_iVA7fjdd5N3q3UrARD-KCno81YF-3KgzLVzye1ltw3RUmfuKwhk1_DUOU85vzbUrBCN5u1952eI-YQ1fTi7COWRSeVVd
// Stocks to be analyzed: Lenovo (LNVGF) & Motorola (MSI)

using namespace std;



int main()
{
    cout << "working if this prints" << endl;

    // Declaration of vector variables for each column in Lenovo's csv file, sized 300 for row count
    // Purpose: Utilize parallel array data structures to contain attributes of same data element

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
    /*
    vector<string> mot_date(MAX_ROWS, "");
    vector<double> mot_open(MAX_ROWS, 0.0);
    vector<double> mot_high(MAX_ROWS, 0.0);
    vector<double> mot_low(MAX_ROWS, 0.0);
    vector<double> mot_close(MAX_ROWS, 0.0);
    vector<double> mot_adj_close(MAX_ROWS, 0.0);
    vector<int> mot_volume(MAX_ROWS, 0);
    */

   //FUNCTION CALL HERE
   // -----------------------------------------------------------

    // Function call to import_data function which will move data from csv files to vectors
    ifstream lenovo_file("LNVGF.csv");
    // ifstream motorola_file("MSI.csv");

   // -----------------------------------------------------------

    // Reading in csv file values for Lenovo and inputting it into corresponding parallel arrays
    // Open the CSV file
    Stock lenovo;

    lenovo.SetDatesVec(lenovo_file);
    // lenovo.SetOpensVec(lenovo_file);
    // lenovo.SetHighsVec(lenovo_file);
    // lenovo.SetLowsVec(lenovo_file);
    // lenovo.SetClosesVec(lenovo_file);
    // lenovo.SetAdjClosesVec(lenovo_file);
    // lenovo.SetVolumesVec(lenovo_file);

    for (int i = 0; i < MAX_ROWS; ++i)
    {
        cout << lenovo.GetDates()[i] << " ";
    }

    cout << "\n\n";

    lenovo.SetOpensVec(lenovo_file);
    for (int j = 0; j < MAX_ROWS; ++j)
    {
        cout << lenovo.GetOpens()[j] << " ";
    }
    cout << "\n\n";

    // for (int i = 0; i < MAX_ROWS; ++i)
    // {
    //     cout << lenovo.GetHighs()[i] << " ";
    // }
    // cout << "\n\n";

    // for (int i = 0; i < MAX_ROWS; ++i)
    // {
    //     cout << lenovo.GetLows()[i] << " ";
    // }
    // cout << "\n\n";

    // for (int i = 0; i < MAX_ROWS; ++i)
    // {
    //     cout << lenovo.GetCloses()[i] << " ";
    // }
    // cout << "\n\n";

    // for (int i = 0; i < MAX_ROWS; ++i)
    // {
    //     cout << lenovo.GetAdjCloses()[i] << " ";
    // }
    // cout << "\n\n";

    // for (int i = 0; i < MAX_ROWS; ++i)
    // {
    //     cout << lenovo.GetVolumes()[i] << " ";
    // }
    // cout << "\n\n";

    // Declared & initialized boolean variables to be used to flag when there is opportunity for exercising pairs trading concepts
    // trade_flag will be raised (set to true) when a certain threshold of separation between stock values is reached
    bool trade_flag = false;

    return 0;
}
