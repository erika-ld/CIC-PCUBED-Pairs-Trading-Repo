#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <iostream>
#include <string>

class Stock
{
public:
    double CalcMean();
    double CalcRange();
    double CalcStdDev();
    double CalcVariance();
    double CalcIqr();

    Stock GetStock();

    void SetMean(double mean);
    void SetRange(double range);
    void SetStdDev(double std_dev);
    void SetVariance(double variance);
    void SetIqr(double iqr);

    const std::vector<std::string>& GetDates();
    const std::vector<double>& GetOpens();
    const std::vector<double>& GetHighs();
    const std::vector<double>& GetLows();
    const std::vector<double>& GetCloses();
    const std::vector<double>& GetAdjCloses();
    const std::vector<double>& GetVolumes();
    double GetMean();
    double GetRange();
    double GetStdDev();
    double GetVariance();
    double GetIqr();

private:
    std::vector<std::string> dates_;
    std::vector<double> opens_;
    std::vector<double> highs_;
    std::vector<double> lows_;
    std::vector<double> closes_;
    std::vector<double> adj_closes_;
    std::vector<double> volumes_;

    double mean_;
    double range_;
    double std_dev_;
    double variance_;
    double iqr_;

    double cointegration_;
    bool trade_flag_;
};

#endif