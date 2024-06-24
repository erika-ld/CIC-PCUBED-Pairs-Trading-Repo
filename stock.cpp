#include "stock.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

double Stock::calcMean()
{
    double sum = 0.0;
    for (double x : this->adjCloses_)
    {
        sum += x;
    }

    int size = adjCloses_.size();
    return (sum / size);
}

double Stock::calcRange()
{
    int max = this->adjCloses_.at(0);
    int min = this->adjCloses_.at(0);
    for (double x : this->adjCloses_)
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
{
    return *this;
}

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
}
