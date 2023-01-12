#include"real.hpp"

//This file contains all the functions required for floating point operations.

//Normalize function for multiplication
void normalize_mul(vector<int> *num, int shift)
{
    for(int i=0;i<shift;i++)
    {
        num->push_back(0);
    }
}

//Padding zeroes in the end. Exponents are negative.
void normalize(vector<int> *num1, vector<int> *num2, int exp1, int exp2)
{
    if(exp1==exp2)
    {
        return;
    }
    else if(exp1>exp2)
    {
        for(int i=0;i<exp1-exp2;i++)
        {
            num1->push_back(0);
        }
    }
    else
    {
        for(int i=0;i<exp2-exp1;i++)
        {
            num2->push_back(0);
        }
    }
    return;
}

void precise(pair<vector<int>, int> *num1, int p)
{
    for(int i=0;i<p;i++)
    {
        num1->first.push_back(0);
    }
}

//To remove the extras digits if it exceeds the precision.
void remove_back(pair<vector<int>, int> *num, int precision)
{
    while(num->second!=(-1)*precision)
    {
        num->first.pop_back();
        num->second++;
    }
}


//------------------------------------------------------//
//Operations on real numbers

//Addition for floating point numbers
pair<vector<int>, int> add_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base)
{
    normalize(&(num1.first), &(num2.first), num1.second, num2.second);
    int precision = (num1.second > num2.second)?num2.second:num1.second;
    pair<vector<int>, int> ans = {add(num1.first, num2.first, base), precision};
    return ans;
}

//Subtraction for floating point numbers
pair<vector<int>, int> subtract_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base)
{
    normalize(&(num1.first), &(num2.first), num1.second, num2.second);
    int precision = (num1.second > num2.second)?num2.second:num1.second;
    pair<vector<int>, int> ans = {subtract(num1.first, num2.first, base), precision};
    return ans; 
}

//Multplication for floating point numbers
pair<vector<int>, int> multiply_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base)
{
    pair<vector<int>, int> ans;
    ans.first = multiply(num1.first, num2.first, base);
    ans.second = num1.second+num2.second;
    return ans;
}

//Division for floating point numbers
//Only quotient will have an exponent, remainder does not have an exponent.
pair<vector<int>, int> divide_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int precision, int base)
{
    int l = precision - num2.second;
    precise(&num1, l);
    pair<vector<int>, vector<int>> ans_div = divide(num1.first, num2.first, base);
    pair<vector<int>, int> ans = {ans_div.first, (-1)*(precision - num1.second)};
    remove_back(&ans, precision);    
    return ans;
}
