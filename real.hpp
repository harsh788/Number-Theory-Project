#include<bits/stdc++.h>
#include"addition.hpp"
#include"subtraction.hpp"
#include"multiplication.hpp"
#include"division.hpp"
using namespace std;

#ifndef REAL_HPP
#define REAL_HPP

void normalize_mul(vector<int> *num, int shift);
void normalize(vector<int> *num1, vector<int> *num2, int exp1, int exp2);
void precise(pair<vector<int>, int> &num1, int p);
void remove_back(pair<vector<int>, int> *num, int precision);

pair<vector<int>, int> add_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base);
pair<vector<int>, int> subtract_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base);
pair<vector<int>, int> multiply_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int base);
pair<vector<int>, int> divide_real(pair<vector<int>, int> num1, pair<vector<int>, int> num2, int precision, int base);

#endif