#include"addition.hpp"

//For adding two integers.
vector<int> add(vector<int> num1, vector<int> num2, int base)
{
    vector<int> ans;
    int len1 = num1.size(), len2 = num2.size();
    int temp, carry = 0;

    if(len1==0)
    {
        return num2;
    }
    else if(len2==0)
    {
        return num1;
    }

    vector<int> n1 = num1;
    vector<int> n2 = num2;

    while(len1!=len2)
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

    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    for(int i=0;i<len2;i++)
    {
        temp = num1[i]+num2[i]+carry;
        ans.push_back(temp%base);
        carry = temp/base;
    }
    for(int i=len2;i<len1;i++)
    {
        temp = num1[i]+carry;
        ans.push_back(temp%base);
        carry = temp/base;
    }
    if(carry)
        ans.push_back(carry);
    
    reverse(ans.begin(), ans.end());
    return ans;
}