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

    Stock get_stock();

    const std::vector<std::string>& get_dates();
    const std::vector<double>& get_opens();
    const std::vector<double>& get_highs();
    const std::vector<double>& get_lows();
    const std::vector<double>& get_closes();
    const std::vector<double>& get_adj_closes();
    const std::vector<double>& get_volumes();
    double get_mean();
    double get_range();
    double get_std_dev();
    double get_variance();
    double get_iqr();

private:
    std::vector<std::string> dates;
    std::vector<double> opens;
    std::vector<double> highs;
    std::vector<double> lows;
    std::vector<double> closes;
    std::vector<double> adj_closes;
    std::vector<double> volumes;

    double mean;
    double range;
    double std_dev;
    double variance;
    double iqr;

    double cointegration;
    bool trade_flag;
};

#endif