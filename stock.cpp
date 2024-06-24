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
    double mean = sum / size;
    return mean;
}

double Stock::CalcRange()
{
    int max = this->adj_closes_.at(0);
    int min = this->adj_closes_.at(0);
    for (double x: this->adj_closes_)
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
    double range = max - min;
    return range;
}

double Stock::CalcStdDev()
{
    this->CalcVariance();
    double std_dev = sqrt(this->variance_);
    return std_dev;
}

double Stock::CalcVariance()
{
    this->CalcMean();
    double sum = 0.0;
    for (double x : this->adj_closes_)
    {
        sum += pow((x - this->mean_), 2);
        sum += pow((x - this->mean_), 2);
    }
    int size = adj_closes_.size();
    double variance = (sum / size);
    return variance;
}

double Stock::CalcIqr()
{

}

void Stock::SetMean(double mean)
{
    mean_ = mean;
}
void Stock::SetRange(double range)
{
    range_ = range;
}
void Stock::SetStdDev(double std_dev)
{
    std_dev_ = std_dev;
}
void Stock::SetVariance(double variance)
{
    variance_ = variance;
}
void Stock::SetIqr(double iqr)
{
    iqr_ = iqr;
}

Stock Stock::GetStock()
{
    return *this;
}

const std::vector<std::string>& Stock::GetDates()
{
    return this->dates_;
    return this->dates_;
}

const std::vector<double> &Stock::GetOpens()
{
    return this->opens_;
    return this->opens_;
}

const std::vector<double>& Stock::GetHighs()
{
    return this->highs_;
    return this->highs_;
}

const std::vector<double>& Stock::GetLows()
{
    return this->lows_;
    return this->lows_;
}

const std::vector<double>& Stock::GetCloses()
{
    return this->closes_;
    return this->closes_;
}

const std::vector<double>& Stock::GetAdjCloses()
{
    return this->adj_closes_;
}

const std::vector<double>& Stock::GetVolumes()
{
    return this->volumes_;
    return this->volumes_;
}

double Stock::GetMean()
{
    return this->mean_;
    return this->mean_;
}

double Stock::GetRange()
{
    return this->range_;
    return this->range_;
}

double Stock::GetStdDev()
{
    return this->std_dev_;
}

double Stock::GetVariance()
{
    return this->variance_;
    return this->variance_;
}

double Stock::GetIqr()
{
    return this->iqr_;
    return this->iqr_;
}
