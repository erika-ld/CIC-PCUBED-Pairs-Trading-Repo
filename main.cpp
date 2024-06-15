#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <cstdio>
#include <iomanip>
// Yahoo Finance: https://finance.yahoo.com/?guccounter=1&guce_referrer=aHR0cHM6Ly93d3cuZ29vZ2xlLmNvbS8&guce_referrer_sig=AQAAAKYPLNT2K6cohZ130zXknBtMd81b1MTutcH0ZzCnv0vjDUrBf6o4hYzi9Pl5jfXbbYCn-V3ylSQZmk3_iVA7fjdd5N3q3UrARD-KCno81YF-3KgzLVzye1ltw3RUmfuKwhk1_DUOU85vzbUrBCN5u1952eI-YQ1fTi7COWRSeVVd
// Stocks to be analyzed:

using namespace std;

string date[300];
double open[300];
double high[300];
double low[300];
double close[300];
double adj_close[300];
int volume[300];
