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
    // Reading in csv file values for Lenovo & Motorola and inputting it into corresponding parallel arrays

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

    cout << fixed << setprecision(4) << showpoint;
    cout << lenovo.CalcMean() << endl;
    cout << lenovo.CalcRange() << endl;
    cout << lenovo.CalcIQR() << endl;
    cout << lenovo.CalcVariance() << endl;
    cout << lenovo.CalcStdDev() << endl;

    cout << motorola.CalcMean() << endl;
    cout << motorola.CalcRange() << endl;
    cout << motorola.CalcIQR() << endl;
    cout << motorola.CalcVariance() << endl;
    cout << motorola.CalcStdDev() << endl;

    motorola.SetMean(motorola.CalcMean());
    motorola.SetRange(motorola.CalcRange());
    motorola.SetIQR(motorola.CalcIQR());
    motorola.SetVariance(motorola.CalcVariance());
    motorola.SetStdDev(motorola.CalcStdDev());

    lenovo.SetMean(lenovo.CalcMean());
    lenovo.SetRange(lenovo.CalcRange());
    lenovo.SetIQR(lenovo.CalcIQR());
    lenovo.SetVariance(lenovo.CalcVariance());
    lenovo.SetStdDev(lenovo.CalcStdDev());

    ofstream lenovo_output_file("LenovoStockRecords.txt");
    ofstream motorola_output_file("MotorolaStockRecords.txt");

    lenovo.SetStockRecords(lenovo_output_file);
    motorola.SetStockRecords(motorola_output_file);

    return 0;
}
