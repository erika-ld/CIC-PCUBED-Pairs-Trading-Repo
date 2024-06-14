#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdio>
#include <iomanip>
// Yahoo Finance: https://finance.yahoo.com/?guccounter=1&guce_referrer=aHR0cHM6Ly93d3cuZ29vZ2xlLmNvbS8&guce_referrer_sig=AQAAAKYPLNT2K6cohZ130zXknBtMd81b1MTutcH0ZzCnv0vjDUrBf6o4hYzi9Pl5jfXbbYCn-V3ylSQZmk3_iVA7fjdd5N3q3UrARD-KCno81YF-3KgzLVzye1ltw3RUmfuKwhk1_DUOU85vzbUrBCN5u1952eI-YQ1fTi7COWRSeVVd
// Stocks to be analyzed: Lenovo (LNVGF) & Motorola (MSI)

using namespace std;

vector<string> date(300, "");
vector<double> open(300, 0.0);
vector<double> high(300, 0.0);
vector<double> low(300, 0.0);
vector<double> close(300, 0.0);
vector<double> adj_close(300, 0.0);
vector<int> volume(300, 0);
