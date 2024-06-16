#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdio>
#include <iomanip>
// Yahoo Finance: https://finance.yahoo.com/?guccounter=1&guce_referrer=aHR0cHM6Ly93d3cuZ29vZ2xlLmNvbS8&guce_referrer_sig=AQAAAKYPLNT2K6cohZ130zXknBtMd81b1MTutcH0ZzCnv0vjDUrBf6o4hYzi9Pl5jfXbbYCn-V3ylSQZmk3_iVA7fjdd5N3q3UrARD-KCno81YF-3KgzLVzye1ltw3RUmfuKwhk1_DUOU85vzbUrBCN5u1952eI-YQ1fTi7COWRSeVVd
// Stocks to be analyzed: Lenovo (LNVGF) & Motorola (MSI)

using namespace std;

int main()
{
    cout << "working if this prints" << endl;

    // Declaration of vector variables for each column in .csv files, sized 300 for row count
    // Purpose: Utilize parallel array data structures to contain attributes of same data element
    vector<string> date(300, "");
    vector<double> open(300, 0.0);
    vector<double> high(300, 0.0);
    vector<double> low(300, 0.0);
    vector<double> close(300, 0.0);
    vector<double> adj_close(300, 0.0);
    vector<int> volume(300, 0);

    //Declared & initialized double variables for Lenovo (len) to be used in calculation of statistical values
    double len_mean = 0.0;
    double len_range = 0.0;
    double len_std_dev = 0.0;
    double len_variance = 0.0;
    double len_iqr = 0.0;

    // Declared & initialized double variables for Motorola (mot) to be used in calculation of statistical values
    double mot_mean = 0.0;
    double mot_range = 0.0;
    double mot_std_dev = 0.0;
    double mot_variance = 0.0;
    double mot_iqr = 0.0;

    //Declared & initialized double variables for the correlation and cointegration of the two data sets
    double correlation = 0.0;
    double cointegration = 0.0;

    //Declared & initialized boolean variables to be used to flag when there is opportunity for exercising pairs trading concepts
    //trade_flag will be raised (set to true) when a certain threshold of separation between stock values is reached
    bool trade_flag = false;

    return 0;
}
