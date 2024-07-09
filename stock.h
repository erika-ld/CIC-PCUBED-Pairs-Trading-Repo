#ifndef STOCK_H
#define STOCK_H

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class Stock
{
public:
    double CalcMean();
    double CalcRange();
    double CalcStdDev();
    double CalcVariance();
    double CalcIQR();

    void SetMean(double mean);
    void SetRange(double range);
    void SetStdDev(double std_dev);
    void SetVariance(double variance);
    void SetIQR(double iqr);
    void SetDatesVec(std::ifstream &file);
    void SetOpensVec(std::ifstream &file);
    void SetHighsVec(std::ifstream &file);
    void SetLowsVec(std::ifstream &file);
    void SetClosesVec(std::ifstream &file);
    void SetAdjClosesVec(std::ifstream &file);
    void SetVolumesVec(std::ifstream &file);

    void SetStockRecords(std::ofstream &output_file);

    Stock GetStock();
    std::vector<std::string> GetDatesVec();
    std::vector<double> GetOpensVec();
    std::vector<double> GetHighsVec();
    std::vector<double> GetLowsVec();
    std::vector<double> GetClosesVec();
    std::vector<double> GetAdjClosesVec();
    std::vector<double> GetVolumesVec();
    double GetMean();
    double GetRange();
    double GetStdDev();
    double GetVariance();
    double GetIQR();

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
};

#endif