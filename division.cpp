#include"division.hpp"

//To remove extra zeroes.
void truncate(vector<int> *num)
{
    while(num->at(0) == 0 && num->size()>1)
    {
        num->erase(num->begin());
    }
    return;
}

pair<vector<int>, vector<int>> divide(vector<int> num1, vector<int> num2, int base)
{
    vector<int> remainder, quotient;
    int k = num1.size(), l = num2.size(), tmp, carry, NOfNormalize=0, count = 0;
    bool flag = false;

    if(k>l)
    {
        flag = true;
    }
    else if(l>k)
    {
        quotient.push_back(0);
        for(int i=0;i<k;i++)
        {
            remainder.push_back(num1.at(i));
        }
        return make_pair(quotient, remainder);
    }
    else
    {
        for(int i=0;i<k;i++)
        {
            if(num1[i]>num2[i])
            {
                flag = true;
                break;
            }
            else if(num2[i]>num1[i])
            {
                quotient.push_back(0);
                for(int i=0;i<k;i++)
                {
                    remainder.push_back(num1.at(i));
                }
                return make_pair(quotient, remainder);
            }
        }
        if(!flag)
        {
            quotient.push_back(1);
            remainder.push_back(0);
            return make_pair(quotient, remainder);
        }
    }

    k = num1.size();
    l = num2.size();

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for(int i=0;i<=k-1;i++)
    {
        remainder.push_back(num1.at(i)); 
    }
    remainder.push_back(0);

    for(int i=0;i<=k-l;i++)
    {
        quotient.push_back(0);
    } 

    for(int i=k-l;i>=0;i--)
    {
        quotient.at(i) = floor((remainder.at(i+l)*base + remainder.at(i+l-1))/num2[l-1]);
        if(quotient.at(i) >= base)
        {
            quotient.at(i) = base - 1;
        }
        carry = 0;
        count = 0;
        
        for(int j=0;j<=l-1;j++)
        {
            tmp = remainder.at(i+j) - quotient.at(i)*num2[j] + carry;
            carry = tmp/base;
            remainder.at(i+j) = tmp%base;
            if(remainder.at(i+j)<0)
            {
                remainder.at(i+j) += base;
                carry--;
            }
        }
        remainder.at(i+l) = remainder.at(i+l) + carry;
        
        while(remainder.at(i+l) < 0)
        {
            carry = 0;
            for(int j=0;j<=l-1;j++)
            {
                tmp = remainder.at(i+j) + num2[j] + carry;
                carry = tmp/base;
                remainder.at(i+j) = tmp%base;
                if(remainder.at(i+j)<0)
                {
                    remainder.at(i+j) += base;
                    carry--;
                }
            }
            remainder.at(i+l) = remainder.at(i+l) + carry;
            quotient.at(i) = quotient.at(i) - 1;
        }
    }

    reverse(quotient.begin(), quotient.end());
    reverse(remainder.begin(), remainder.end());

    for(int i=0;i<quotient.size();i++)
    {
        if(quotient.at(i)!=0)
        {
            truncate(&quotient);
        }
    }
    if(quotient.size()==0){
        quotient.push_back(0);
    }

    return make_pair(quotient, remainder);
}
