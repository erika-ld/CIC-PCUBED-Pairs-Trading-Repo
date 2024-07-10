#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdio>
#include <iomanip>
#include "stock.h"
#include "stock.cpp"

// Yahoo Finance: https://finance.yahoo.com/?guccounter=1&guce_referrer=aHR0cHM6Ly93d3cuZ29vZ2xlLmNvbS8&guce_referrer_sig=AQAAAKYPLNT2K6cohZ130zXknBtMd81b1MTutcH0ZzCnv0vjDUrBf6o4hYzi9Pl5jfXbbYCn-V3ylSQZmk3_iVA7fjdd5N3q3UrARD-KCno81YF-3KgzLVzye1ltw3RUmfuKwhk1_DUOU85vzbUrBCN5u1952eI-YQ1fTi7COWRSeVVd
// Stocks to be analyzed: Lenovo (LNVGF) & Motorola (MSI)

using namespace std;



int main()
{
    // Reading in csv file values for Lenovo & Motorola 
    // and inputting it into corresponding parallel arrays
    ifstream lenovo_file("LNVGF.csv");
    ifstream motorola_file("MSI.csv");

    //Create instances of Stock objects
    Stock lenovo;
    Stock motorola;

    //Populate parallel vectors with corresponding stock data, pulled from .csv files
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

    //Calculate & print the statistical data for each stock
    cout << fixed << setprecision(5) << showpoint;
    cout << "Lenovo" << endl;
    cout << "Mean: " << lenovo.CalcMean() << endl;
    cout << "Range: " << lenovo.CalcRange() << endl;
    cout << "Std. Dev.: " << lenovo.CalcStdDev() << endl;
    cout << "Variance: " << lenovo.CalcVariance() << endl;
    cout << "IQR: " << lenovo.CalcIQR() << endl;
    cout << "\n\n";

    cout << "Motorola" << endl;
    cout << "Mean: " << motorola.CalcMean() << endl;
    cout << "Range: " << motorola.CalcRange() << endl;
    cout << "Std. Dev.: " << motorola.CalcStdDev() << endl;
    cout << "Variance: " << motorola.CalcVariance() << endl;
    cout << "IQR: " << motorola.CalcIQR() << endl;

    //Set the private member variables with the results of the statistical calculations
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

    //Instantiate ofstream objects to print the stock data & calculations
    ofstream lenovo_output_file("LenovoStockRecords.txt");
    ofstream motorola_output_file("MotorolaStockRecords.txt");

    //Call function to set stock records with stock data & calculated values
    lenovo.SetStockRecords(lenovo_output_file);
    motorola.SetStockRecords(motorola_output_file);

    return 0;
}
