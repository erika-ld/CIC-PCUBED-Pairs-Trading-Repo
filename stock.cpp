#include "stock.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>

using namespace std;

void Stock::calc_set_mean()
{
    double sum = 0.0;
    for (double x : this->adj_closes)
    {
        sum += x;
    }

    int size = adj_closes.size();
    double mean = sum / size;
    this->mean = mean;
}

void Stock::calc_set_range()
{
    int max = this->adj_closes.at(0);
    int min = this->adj_closes.at(0);
    for (double x: this->adj_closes)
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
    this->range = range;
}

void Stock::calc_set_std_dev()
{
    this->calc_set_variance();
    double std_dev = sqrt(this->variance);
    this->std_dev = std_dev;
}

void Stock::calc_set_variance()
{
    this->calc_set_mean();
    double sum = 0.0;
    for (double x : this->adj_closes)
    {
        sum += pow((x - this->mean), 2);
    }
    int size = adj_closes.size();
    double variance = (sum / size);
    this->variance = variance;
}

void Stock::calc_set_iqr()
{
    this->iqr = iqr;
}

Stock Stock::get_stock()
{
    return *this;
}

const std::vector<std::string>& Stock::get_dates()
{
    return this->dates;
}

const std::vector<double> &Stock::get_opens()
{
    return this->opens;
}

const std::vector<double>& Stock::get_highs()
{
    return this->highs;
}

const std::vector<double>& Stock::get_lows()
{
    return this->lows;
}

const std::vector<double>& Stock::get_closes()
{
    return this->closes;
}

const std::vector<double>& Stock::get_adj_closes()
{
    return this->adj_closes;
}

const std::vector<double>& Stock::get_volumes()
{
    return this->volumes;
}

double Stock::get_mean()
{
    return this->mean;
}

double Stock::get_range()
{
    return this->range;
}

double Stock::get_std_dev()
{
    return this->std_dev;
}

double Stock::get_variance()
{
    return this->variance;
}

double Stock::get_iqr()
{
    return this->iqr;
}
