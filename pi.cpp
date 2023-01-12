#include"pi.hpp"

//This file contains all the functions required for calculating the value of π upto any given precision.

pair<vector<int>, int> pi(int precision, int base)
{
    pair<vector<int>, int> one = {{1}, 0}, two = {{2}, 0};base=10;
    pair<vector<int>, int> a = root(two, precision, base), a_prev = a, root_a;
    pair<vector<int>, int> b = {{0}, 0}, b_prev = b;
    pair<vector<int>, int> p = add_real(two, a, base), p_prev = p;

    pair<vector<int>, int> div, add1, add2, sub, mul1, mul2;
    while(true)
    {
        root_a = root(a_prev, precision, base);

        a = divide_real(add_real(root_a, divide_real(one, root_a, precision, base), base), two, precision, base);
        remove_back(&a, precision);

        b = divide_real(multiply_real(add_real(one, b_prev, base), root_a, base), add_real(a_prev, b_prev, base), precision, base);
        remove_back(&b, precision);
        
        /*add1 = add_real(one, a, base);
        add2 = add_real(one, b, base);
        mul1 = multiply_real(add1, p_prev, base);
        mul2 = multiply_real(mul1, b, base);*/
        p = divide_real(multiply_real(multiply_real(add_real(one, a, base), p_prev, base), b, base), add_real(one, b, base), precision, base);
        remove_back(&p, precision);

        if(!isPrecise(p_prev, p, precision, base))
        {
            a_prev = a;
            b_prev = b;
            p_prev = p;
        }
        else
        {
            break;
        }
    }
    
    for(int i=0;i<5;i++)
    {
        p.first.pop_back();
    }
    return p;
}