#include "stock.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

<<<<<<< HEAD
double Stock::CalcMean()
{
    double sum = 0.0;
    for (double x : this->adj_closes_)
=======
double Stock::calcMean()
{
    double sum = 0.0;
    for (double x : this->adjCloses_)
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a
    {
        sum += x;
    }

<<<<<<< HEAD
    int size = adj_closes_.size();
    double mean = sum / size;
    return mean;
}

double Stock::CalcRange()
{
    int max = this->adj_closes_.at(0);
    int min = this->adj_closes_.at(0);
    for (double x: this->adj_closes_)
=======
    int size = adjCloses_.size();
    return (sum / size);
}

double Stock::calcRange()
{
    int max = this->adjCloses_.at(0);
    int min = this->adjCloses_.at(0);
    for (double x : this->adjCloses_)
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a
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
<<<<<<< HEAD
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
=======
    return (max - min);
}

double Stock::calcStdDev()
{
    this->calcVariance();
    return (sqrt(this->variance_));
}

double Stock::calcVariance()
{
    this->calcMean();
    double sum = 0.0;
    for (double x : this->adjCloses_)
    {
        sum += pow((x - this->mean_), 2);
    }
    int size = adjCloses_.size();
    return (sum / size);
}

double Stock::calcIQR()
{
    //TO-DO: FINISH IQR
    this->iqr_ = iqr_;
}

void Stock::setMean(double mean)
{
    this->mean_ = mean;
}

void Stock::setRange(double range)
{
    this->range_ = range;
}

void Stock::setStdDev(double stdDev)
{
    this->stdDev_ = stdDev;
}

void Stock::setVariance(double variance)
{
    this->variance_ = variance;
}

void Stock::setIQR(double iqr)
{
    this->iqr_ = iqr;
}

Stock Stock::getStock()
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a
{
    return *this;
}

<<<<<<< HEAD
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
=======
const std::vector<std::string>& Stock::getDates()
{
    return this->dates_;
}

const std::vector<double> &Stock::getOpens()
{
    return this->opens_;
}

const std::vector<double>& Stock::getHighs()
{
    return this->highs_;
}

const std::vector<double>& Stock::getLows()
{
    return this->lows_;
}

const std::vector<double>& Stock::getCloses()
{
    return this->closes_;
}

const std::vector<double>& Stock::getAdjCloses()
{
    return this->adjCloses_;
}

const std::vector<double>& Stock::getVolumes()
{
    return this->volumes_;
}

double Stock::getMean()
{
    return this->mean_;
}

double Stock::getRange()
{
    return this->range_;
}

double Stock::getStdDev()
{
    return this->stdDev_;
}

double Stock::getVariance()
{
    return this->variance_;
}

double Stock::getIQR()
{
    return this->iqr_;
>>>>>>> 9b6ec9ca31c788bad1f306e1fae61350e173aa1a
}
