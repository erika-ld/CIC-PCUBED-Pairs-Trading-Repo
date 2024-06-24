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
    for (double x : this->AdjCloses_)
    {
        sum += x;
    }

    int size = AdjCloses_.size();
    return (sum / size);
}

double Stock::CalcRange()
{
    int max = this->AdjCloses_.at(0);
    int min = this->AdjCloses_.at(0);
    for (double x : this->AdjCloses_)
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
    return (sqrt(this->Variance_));
}

double Stock::CalcVariance()
{
    this->CalcMean();
    double sum = 0.0;
    for (double x : this->AdjCloses_)
    {
        sum += pow((x - this->Mean_), 2);
    }
    int size = AdjCloses_.size();
    return (sum / size);
}

double Stock::CalcIQR()
{
    //TO-DO: FINISH IQR
    this->IQR_ = IQR_;
}

void Stock::SetMean(double Mean)
{
    this->Mean_ = Mean;
}

void Stock::SetRange(double Range)
{
    this->Range_ = Range;
}

void Stock::SetStdDev(double StdDev)
{
    this->StdDev_ = StdDev;
}

void Stock::SetVariance(double Variance)
{
    this->Variance_ = Variance;
}

void Stock::SetIQR(double IQR)
{
    this->IQR_ = IQR;
}

Stock Stock::GetStock()
{
    return *this;
}

const std::vector<std::string>& Stock::GetDates()
{
    return this->Dates_;
}

const std::vector<double> &Stock::GetOpens()
{
    return this->Opens_;
}

const std::vector<double>& Stock::GetHighs()
{
    return this->Highs_;
}

const std::vector<double>& Stock::GetLows()
{
    return this->Lows_;
}

const std::vector<double>& Stock::GetCloses()
{
    return this->Closes_;
}

const std::vector<double>& Stock::GetAdjCloses()
{
    return this->AdjCloses_;
}

const std::vector<double>& Stock::GetVolumes()
{
    return this->Volumes_;
}

double Stock::GetMean()
{
    return this->Mean_;
}

double Stock::GetRange()
{
    return this->Range_;
}

double Stock::GetStdDev()
{
    return this->StdDev_;
}

double Stock::GetVariance()
{
    return this->Variance_;
}

double Stock::GetIQR()
{
    return this->IQR_;
}
