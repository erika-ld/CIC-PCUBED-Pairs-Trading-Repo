#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <iostream>
#include <string>

class Stock
{
public:
    void calc_set_mean();
    void calc_set_range();
    void calc_set_std_dev();
    void calc_set_variance();
    void calc_set_iqr();

    double get_mean();
    double get_range();
    double get_std_dev();
    double get_variance();
    double get_iqr();

private:
    std::vector<std::string> date;
    std::vector<double> open;
    std::vector<double> high;
    std::vector<double> low;
    std::vector<double> close;
    std::vector<double> adj_close;
    std::vector<double> volume;

    double mean;
    double range;
    double std_dev;
    double variance;
    double iqr;

    double cointegration;
    bool trade_flag;
};

#endif