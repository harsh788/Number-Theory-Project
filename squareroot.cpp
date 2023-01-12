#include"squareroot.hpp"

//This file contains functions for calculating the square root of any number.

//Function to check if the precision is reached or not.
bool isPrecise(pair<vector<int>, int> prev, pair<vector<int>, int> ans, int precision, int base)
{
    /*If the difference between the previous value
      and the current value is less than or equal to
      the precision required, we conclude that the 
      precision is obtained*/

    pair<vector<int>, int> diff = subtract_real(prev, ans, base);
    pair<vector<int>, int> prec = {{1}, (-1)*precision};
    pair<vector<int>, int> diff2 = subtract_real(diff, prec, base);

    if(diff2.second == (-1)*precision && diff2.first[0]<=1 && diff2.first.size()==1)
    {
        return true;
    }
    else if(diff2.second > precision)
    {
        return true;
    }
    else
    {
        return false;
    }
    return true;
}

pair<vector<int>, int> root(pair<vector<int>, int> num, int precision, int base)
{
    pair<vector<int>, int> ans = num, prev = ans;
    pair<vector<int>, int> two = {{2}, 0};base=10;
    while(true)
    {
        pair<vector<int>, int> div = divide_real(num, ans, precision, base);
        pair<vector<int>, int> add = add_real(ans, div, base);
        ans = divide_real(add, two, precision, base);
        remove_back(&ans, precision);

        if(!isPrecise(prev, ans, precision, base))
        {
            prev = ans;
        }
        else
        {
            break;
        }
    }
    return ans;
}