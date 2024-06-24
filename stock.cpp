#include "stock.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

double Stock::CalcMean()
{
    double sum = 0.0;
    for (double x : this->adj_closes_)
    {
        sum += x;
    }

    int size = adj_closes_.size();
    return (sum / size);
}

double Stock::CalcRange()
{
    int max = this->adj_closes_.at(0);
    int min = this->adj_closes_.at(0);
    for (double x : this->adj_closes_)
    {
        if (x > max)
        {
            max = x;
        }

        if (x < min)
        {
            min = x;
        }
    }
    return (max - min);
}

double Stock::CalcStdDev()
{
    this->CalcVariance();
    return (sqrt(this->variance_));
}

double Stock::CalcVariance()
{
    this->CalcMean();
    double sum = 0.0;
    for (double x : this->adj_closes_)
    {
        sum += pow((x - this->mean_), 2);
    }
    int size = adj_closes_.size();
    return (sum / size);
}

double Stock::CalcIQR()
{
    //TO-DO: FINISH IQR
    this->iqr_ = iqr_;
}

void Stock::SetMean(double mean)
{
    this->mean_ = mean;
}

void Stock::SetRange(double range)
{
    this->range_ = range;
}

void Stock::SetStdDev(double std_dev)
{
    this->std_dev_ = std_dev;
}

void Stock::SetVariance(double variance)
{
    this->variance_ = variance;
}

void Stock::SetIQR(double iqr)
{
    this->iqr_ = iqr;
}

Stock Stock::GetStock()
{
    return *this;
}

const std::vector<std::string>& Stock::GetDates()
{
    return this->dates_;
}

const std::vector<double> &Stock::GetOpens()
{
    return this->opens_;
}

const std::vector<double>& Stock::GetHighs()
{
    return this->highs_;
}

const std::vector<double>& Stock::GetLows()
{
    return this->lows_;
}

const std::vector<double>& Stock::GetCloses()
{
    return this->closes_;
}

const std::vector<double>& Stock::GetAdjCloses()
{
    return this->adj_closes_;
}

const std::vector<double>& Stock::GetVolumes()
{
    return this->volumes_;
}

double Stock::GetMean()
{
    return this->mean_;
}

double Stock::GetRange()
{
    return this->range_;
}

double Stock::GetStdDev()
{
    return this->std_dev_;
}

double Stock::GetVariance()
{
    return this->variance_;
}

double Stock::GetIQR()
{
    return this->iqr_;
}
