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
    ifstream motorola_file("MSI.csv");


    Stock lenovo;
    Stock motorola;

    lenovo.SetDatesVec(lenovo_file);
    motorola.SetDatesVec(motorola_file);
    lenovo.SetOpensVec(lenovo_file);
    motorola.SetOpensVec(motorola_file);
    lenovo.SetHighsVec(lenovo_file);
    motorola.SetHighsVec(motorola_file);
    lenovo.SetLowsVec(lenovo_file);
    motorola.SetLowsVec(motorola_file);
    lenovo.SetClosesVec(lenovo_file);
    motorola.SetClosesVec(motorola_file);
    lenovo.SetAdjClosesVec(lenovo_file);
    motorola.SetAdjClosesVec(motorola_file);
    lenovo.SetVolumesVec(lenovo_file);
    motorola.SetVolumesVec(motorola_file);

    ofstream lenovo_output_file("LenovoStockRecords.txt");
    ofstream motorola_output_file("MotorolaStockRecords.txt");
    lenovo.SetStockRecords(lenovo_output_file);
    motorola.SetStockRecords(motorola_output_file);

    // Declared & initialized boolean variables to be used to flag when there is opportunity for exercising pairs trading concepts
    // trade_flag will be raised (set to true) when a certain threshold of separation between stock values is reached
    bool trade_flag = false;

    return 0;
}
