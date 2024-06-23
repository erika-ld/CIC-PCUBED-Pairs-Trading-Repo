#include "stock.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void Stock::calc_set_mean()
{
    
    this->mean = mean;
}

void Stock::calc_set_range()
{
    this->range = range;
}

void Stock::calc_set_std_dev()
{
    this->std_dev = std_dev;
}

void Stock::calc_set_variance()
{
    this->variance = variance;
}

void Stock::calc_set_iqr()
{
    this->iqr = iqr;
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
