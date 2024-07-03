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

    // Reading in csv file values for Lenovo and inputting it into corresponding parallel arrays
    // Open the CSV file
    ifstream lenovo_file("LNVGF.csv");
    //ifstream motorola_file("MSI.csv");


    Stock lenovo;

    lenovo.SetDatesVec(lenovo_file);
    lenovo.SetOpensVec(lenovo_file);
    lenovo.SetHighsVec(lenovo_file);
    lenovo.SetLowsVec(lenovo_file);
    lenovo.SetClosesVec(lenovo_file);
    lenovo.SetAdjClosesVec(lenovo_file);
    lenovo.SetVolumesVec(lenovo_file);

    ofstream output_file("LenovoStockRecords.txt");
    lenovo.SetStockRecords(output_file);

    // Declared & initialized boolean variables to be used to flag when there is opportunity for exercising pairs trading concepts
    // trade_flag will be raised (set to true) when a certain threshold of separation between stock values is reached
    bool trade_flag = false;

    return 0;
}
