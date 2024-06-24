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
    double CalcIQR();

    void SetMean(double Mean);
    void SetRange(double Range);
    void SetStdDev(double StdDev);
    void SetVariance(double Variance);
    void SetIQR(double IQR);

    Stock GetStock();

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
    double GetIQR();

private:
    std::vector<std::string> Dates_;
    std::vector<double> Opens_;
    std::vector<double> Highs_;
    std::vector<double> Lows_;
    std::vector<double> Closes_;
    std::vector<double> AdjCloses_;
    std::vector<double> Volumes_;

    double Mean_;
    double Range_;
    double StdDev_;
    double Variance_;
    double IQR_;

    double Cointegration_;
    bool TradeFlag_;
};

#endif