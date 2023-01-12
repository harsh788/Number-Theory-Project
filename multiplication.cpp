#include "multiplication.hpp"

#define max(a,b) ((a) > (b) ? (a) : (b))

void normalize(vector<int> *num, int shift)
{
    for(int i=0;i<shift;i++)
    {
        num->push_back(0);
    }
}

//For multiplying two integers.
vector<int> multiply(vector<int> num1, vector<int> num2, int base) 
{
    int len1=num1.size(), len2=num2.size();
    int half, p;
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    vector<int> c;
    int carry, tmp;
    for(int i=0;i<=len1+len2-1;i++)
    {
        c.push_back(0);
    }

    for(int i=0;i<len1;i++)
    {
        carry = 0; 
        for(int j=0;j<len2;j++)
        {
            tmp = num1[i]*num2[j] + c[i+j] + carry;
            carry = tmp/base;
            c[i+j] = tmp%base;
        }
        c[i+len2] = carry;
    }
    reverse(c.begin(), c.end());
    return c;
    

    //Karatsuba's Algorithm

    /*while(len1!=len2)
    {
        if(len1<len2)
        {
            num1.insert(num1.begin(), 0);
            len1++;
        }
        else
        {
            num2.insert(num2.begin(), 0);
            len2++;
        }
    }

    if(len1 == 1)
    {
        p = num1[0]*num2[0];
        vector<int> ans;
        if(p>=base)
        {
            ans.push_back(p/base);
            ans.push_back(p%base);
            return ans;
        }
        else
        {
            ans.push_back(p);
            return ans;
        }
    }
    
    half = len1/2;
    
    vector<int> low1, high1, low2, high2;

    for(int i=0;i<half;i++)
    {
        high1.push_back(num1[i]);
        high2.push_back(num2[i]);
    }
    for(int i=half;i<len1;i++)
    {
        low1.push_back(num1[i]);
        low2.push_back(num2[i]);
    }

    vector<int> m0, m1, m2;
    m0 = multiply(low1, low2, base);
    m2 = multiply(high1, high2, base);
    m1 = subtract(subtract(multiply(add(low1, high1, base), add(low2, high2, base), base), m0, base), m2, base);

    normalize(&m2, 2*(len1-half));
    normalize(&m1, len1-half);

    vector<int> add1 = add(m2, m0, base);
    vector<int> add2;

    if(m1.at(0) < 0)
    {
        m1.at(0) = m1.at(0)*(-1);
        add2 = subtract(add1, m1, base);
    }
    else
    {
        add2 = add(add1, m1, base);
    }

    return add2;
    //return add(add(m2, m1, base), m0, base);*/
}
