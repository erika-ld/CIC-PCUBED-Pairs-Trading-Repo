#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <iostream>
#include <string>

class Stock
{
public:
    double calcMean();
    double calcRange();
    double calcStdDev();
    double calcVariance();
    double calcIQR();

    void setMean(double mean);
    void setRange(double range);
    void setStdDev(double stdDev);
    void setVariance(double variance);
    void setIQR(double iqr);

    Stock getStock();

    const std::vector<std::string>& getDates();
    const std::vector<double>& getOpens();
    const std::vector<double>& getHighs();
    const std::vector<double>& getLows();
    const std::vector<double>& getCloses();
    const std::vector<double>& getAdjCloses();
    const std::vector<double>& getVolumes();
    double getMean();
    double getRange();
    double getStdDev();
    double getVariance();
    double getIQR();

private:
    std::vector<std::string> dates_;
    std::vector<double> opens_;
    std::vector<double> highs_;
    std::vector<double> lows_;
    std::vector<double> closes_;
    std::vector<double> adjCloses_;
    std::vector<double> volumes_;

    double mean_;
    double range_;
    double stdDev_;
    double variance_;
    double iqr_;

    double cointegration_;
    bool tradeFlag_;
};

#endif