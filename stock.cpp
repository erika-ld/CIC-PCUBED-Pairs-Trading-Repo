#include "stock.h"
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <cstdlib>

using namespace std;

const int MAX_ROWS = 253;
const int MAX_COLS = 7;

double Stock::CalcMean()
{
    double sum = 0.0;
    for (int i = 0; i < MAX_ROWS; ++i)
    {
        sum += adj_closes_[i];
    }

    int size = adj_closes_.size();
    return (sum / size);
}

double Stock::CalcRange()
{
    int max = adj_closes_.at(0);
    int min = adj_closes_.at(0);

    for (int i = 0; i < MAX_ROWS; ++i)
    {
        if (adj_closes_[i] > max)
        {
            max = adj_closes_[i];
        }

        if (adj_closes_[i] < min)
        {
            min = adj_closes_[i];
        }
    }
    return (max - min);
}

double Stock::CalcStdDev()
{
    CalcVariance();
    return (sqrt(variance_));
}

double Stock::CalcVariance()
{
    CalcMean();
    double sum = 0.0;

    for (int i = 0; i < MAX_ROWS; ++i)
    {
        sum += pow((adj_closes_[i] - mean_), 2);
    }
    int size = adj_closes_.size();
    return (sum / size);
}

double Stock::CalcIQR()
{
    vector<double> temp_v = adj_closes_;
    sort(temp_v.begin(), temp_v.end());

    //REMOVE
    //vector<double> adj_closes_data;
    //copy(adj_closes_.begin() + 1, adj_closes_.end(), back_inserter(adj_closes_data));
    
    //Size should be 253
    int size = adj_closes_.size();
    int median_index = (size / 2);
    int q1 = ceil((size / 4));
    int q3 = ceil((3 * (size / 4)));
    return adj_closes_.at(q3) - adj_closes_.at(q1);
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

void Stock::SetIQR(double iqr)
{
    iqr_ = iqr;
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
            dates_.push_back(temp_arr[0]);
        }
        dates_.erase(dates_.begin());
        file.clear();
        file.seekg(0);
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
        double temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            if (!isalpha(line[0]))
            {
                while (getline(ss, cell, ',') && col < MAX_COLS)
                {
                    temp_arr[col] = stod(cell);
                    col++;
                }
                opens_.push_back(temp_arr[1]);
            }
        }
        file.clear();
        file.seekg(0);
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
        double temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            if (!isalpha(line[0]))
            {
                while (getline(ss, cell, ',') && col < MAX_COLS)
                {
                    temp_arr[col] = stod(cell);
                    col++;
                }
            highs_.push_back(temp_arr[2]);
            }
        }
        file.clear();
        file.seekg(0);
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
        double temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            if (!isalpha(line[0]))
            {
                while (getline(ss, cell, ',') && col < MAX_COLS)
                {
                    temp_arr[col] = stod(cell);
                    col++;
                }
            lows_.push_back(temp_arr[3]);
            }
        }
        file.clear();
        file.seekg(0);
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
        double temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            if (!isalpha(line[0]))
            {
                while (getline(ss, cell, ',') && col < MAX_COLS)
                {
                    temp_arr[col] = stod(cell);
                    col++;
                }
            closes_.push_back(temp_arr[4]);
            }
        }
        file.clear();
        file.seekg(0);
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
        double temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            if (!isalpha(line[0]))
            {
                while (getline(ss, cell, ',') && col < MAX_COLS && !isalpha(line[0]))
                {
                    temp_arr[col] = stod(cell);
                    col++;
                }
            adj_closes_.push_back(temp_arr[5]);
            }
        }
        file.clear();
        file.seekg(0);
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
        double temp_arr[MAX_COLS];
        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            string cell;
            int col = 0;
            if (!isalpha(line[0]))
            {
                while (getline(ss, cell, ',') && col < MAX_COLS && !isalpha(line[0]))
                {
                    temp_arr[col] = stod(cell);
                    col++;
                }
            volumes_.push_back(temp_arr[6]);
            }
        }
        file.clear();
        file.seekg(0);
    }
}

void Stock::SetStockRecords(ofstream& output_file)
{
    if (!output_file.is_open())
    {
        cerr << "Error opening file!" << endl;
    } else
    {
        int format_counter = 1;
        if (!dates_.empty())
        {
            output_file << "Dates: \n";
            for (int i = 0; i < MAX_ROWS; ++i)
            {
                output_file << dates_[i] << " ";
                if (format_counter % 10 == 0)
                {
                    output_file << "\n";
                }
                format_counter++;
            }
            output_file << "\n\n";
        }


        format_counter = 1;
        if (!opens_.empty())
        {
            output_file << "Opens: \n";
            for (int i = 0; i < MAX_ROWS; ++i)
            {
                output_file << opens_[i] << " ";
                if (format_counter % 10 == 0)
                {
                    output_file << "\n";
                }
                format_counter++;
            }
            output_file << "\n\n";
        }


        format_counter = 1;
        if (!highs_.empty())
        {
            output_file << "Highs: \n";
            for (int i = 0; i < MAX_ROWS; ++i)
            {
                output_file << highs_[i] << " ";
                if (format_counter % 10 == 0)
                {
                    output_file << "\n";
                }
                format_counter++;
            }
            output_file << "\n\n";
        }


        format_counter = 1;
        if (!lows_.empty())
        {
            output_file << "Lows: \n";
            for (int i = 0; i < MAX_ROWS; ++i)
            {
                output_file << lows_[i] << " ";
                if (format_counter % 10 == 0)
                {
                    output_file << "\n";
                }
                format_counter++;
            }
            output_file << "\n\n";
        }


        format_counter = 1;
        if (!closes_.empty())
        {
            output_file << "Closes: \n";
            for (int i = 0; i < MAX_ROWS; ++i)
            {
                output_file << closes_[i] << " ";
                if (format_counter % 10 == 0)
                {
                    output_file << "\n";
                }
                format_counter++;
            }
            output_file << "\n\n";
        }


        format_counter = 1;
        if (!adj_closes_.empty())
        {
            output_file << "Adj. Closes: \n";
            for (int i = 0; i < MAX_ROWS; ++i)
            {
                output_file << adj_closes_[i] << " ";
                if (format_counter % 10 == 0)
                {
                    output_file << "\n";
                }
                format_counter++;
            }
            output_file << "\n\n";
        }


        format_counter = 1;
        if (!volumes_.empty())
        {
            output_file << "Volumes: \n";
            for (int i = 0; i < MAX_ROWS; ++i)
            {
                output_file << volumes_[i] << " ";
                if (format_counter % 10 == 0)
                {
                    output_file << "\n";
                }
                format_counter++;
            }
            output_file << "\n\n";
        }
    }
}

Stock Stock::GetStock()
{
    return *this;
}

std::vector<std::string> Stock::GetDatesVec()
{
    
    return dates_;
}

std::vector<double> Stock::GetOpensVec()
{
    return opens_;
}

std::vector<double> Stock::GetHighsVec()
{
    return highs_;
}

std::vector<double> Stock::GetLowsVec()
{
    return lows_;
}

std::vector<double> Stock::GetClosesVec()
{
    return closes_;
}

std::vector<double> Stock::GetAdjClosesVec()
{
    return adj_closes_;
}

std::vector<double> Stock::GetVolumesVec()
{
    return volumes_;
}

double Stock::GetMean()
{
    return mean_;
}

double Stock::GetRange()
{
    return range_;
}

double Stock::GetStdDev()
{
    return std_dev_;
}

double Stock::GetVariance()
{
    return variance_;
}

double Stock::GetIQR()
{
    return iqr_;
}


