#include "stock.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iterator>
#include "Eigen/Dense"

using namespace std;

const int MAX_ROWS = 254;
const int MAX_COLS = 7;

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
    vector<double> temp_v = this->adj_closes_;
    sort(temp_v.begin(), temp_v.end());

    vector<double> adj_closes_data;
    copy(adj_closes_.begin() + 1, adj_closes_.end(), back_inserter(adj_closes_data));
    
    //Size should be 253
    int size = adj_closes_data.size();
    int median_index = (size / 2);
    int q1 = ceil((size / 4));
    int q3 = ceil((3 * (size / 4)));
    return adj_closes_data.at(q3) - adj_closes_data.at(q1);
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

void Stock::SetDatesVec(ifstream &file)
{
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        string temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            while (getline(ss, cell, ',') && col < MAX_COLS)
            {
                temp_arr[col] = cell;
                col++;
            }
        }
        this->dates_.push_back(temp_arr[0]);
    }
}

void Stock::SetOpensVec(ifstream &file)
{
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        string temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            while (getline(ss, cell, ',') && col < MAX_COLS)
            {
                temp_arr[col] = cell;
                col++;
            }
        }
        this->dates_.push_back(temp_arr[1]);
    }
}

void Stock::SetHighsVec(std::ifstream &file)
{
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        string temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            while (getline(ss, cell, ',') && col < MAX_COLS)
            {
                temp_arr[col] = cell;
                col++;
            }
        }
        this->dates_.push_back(temp_arr[2]);
    }
}

void Stock::SetLowsVec(std::ifstream &file)
{
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        string temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            while (getline(ss, cell, ',') && col < MAX_COLS)
            {
                temp_arr[col] = cell;
                col++;
            }
        }
        this->dates_.push_back(temp_arr[3]);
    }
}

void Stock::SetClosesVec(std::ifstream &file)
{
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        string temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            while (getline(ss, cell, ',') && col < MAX_COLS)
            {
                temp_arr[col] = cell;
                col++;
            }
        }
        this->dates_.push_back(temp_arr[4]);
    }
}

void Stock::SetAdjClosesVec(std::ifstream &file)
{
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        string temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            while (getline(ss, cell, ',') && col < MAX_COLS)
            {
                temp_arr[col] = cell;
                col++;
            }
        }
        this->dates_.push_back(temp_arr[5]);
    }
}

void Stock::SetVolumesVec(std::ifstream &file)
{
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
    }
    else
    {
        string temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            while (getline(ss, cell, ',') && col < MAX_COLS)
            {
                temp_arr[col] = cell;
                col++;
            }
        }
        this->dates_.push_back(temp_arr[6]);
    }
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


