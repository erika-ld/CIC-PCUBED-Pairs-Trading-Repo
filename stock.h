#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <iostream>
#include <string>

class Stock
{
public:
<<<<<<< HEAD
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
=======
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
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a

private:
    std::vector<std::string> dates_;
    std::vector<double> opens_;
    std::vector<double> highs_;
    std::vector<double> lows_;
    std::vector<double> closes_;
<<<<<<< HEAD
    std::vector<double> adj_closes_;
=======
    std::vector<double> adjCloses_;
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a
    std::vector<double> volumes_;

    double mean_;
    double range_;
<<<<<<< HEAD
    double std_dev_;
=======
    double stdDev_;
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a
    double variance_;
    double iqr_;

    double cointegration_;
<<<<<<< HEAD
    bool trade_flag_;
=======
    bool tradeFlag_;
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a
};

#endif