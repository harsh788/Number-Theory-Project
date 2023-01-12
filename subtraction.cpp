#include"subtraction.hpp"

//For subtracting two integers.
vector<int> subtract(vector<int> num1, vector<int> num2, int base)
{
    vector<int> ans;
    int len1 = num1.size(), len2 = num2.size();
    int temp, carry = 0;

    if(len1==0)
    {
        num2[0] = -1*num2[0];
        return num2;
    }
    else if(len2==0)
    {
        return num1;
    }

    //Finding the greater number
    int grt,sml;
    if(len1>len2)
    {
        grt = 1;
        sml = 2;
    }    
    else if(len2>len1)
    {
        grt = 2;
        sml = 1;
    }
    else
    {
        bool flag = false;
        for(int i=0;i<len1;i++)
        {
            if(num1[i]>num2[i])
            {
                grt = 1;
                sml = 2;
                flag = true;
                break;
            }
            else if(num2[i]>num1[i])
            {
                grt = 2;
                sml = 1;
                flag = true;
                break;
            }
        }
        if(!flag)
        {
            vector<int> ans={0};
            return ans;
        }
    }

    //Padding zeroes in the beggining to equate the lengths
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

    if(grt==1)
    {
        for(int i=0;i<len2;i++)
        {
            temp = num1[i]-num2[i]+carry;
            if(temp<0 && i!=len1-1)
            {
                temp = temp + base;
                carry = -1;
            }
            else
            {
                carry = 0;
            }
            ans.push_back(temp%base);
            carry = carry + temp/base;
        }
        for(int i=len2;i<len1;i++)
        {
            temp = num1[i]+carry;
            if(temp<0)
            {
                temp = temp + base;
                carry = -1;
            }
            else
            {
                carry = 0;
            }
            ans.push_back(temp%base);
            carry = carry + temp/base;
        }
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        while(true)
        {
            auto i = ans.begin();
            if(*i != 0 || ans.size()==1)
            {
                break;
            }
            else
            {
                ans.erase(i);
            }
        }
    }
    else if(grt == 2)
    {
        for(int i=0;i<len1;i++)
        {
            temp = num2[i]-num1[i]+carry;
            if(temp<0 && i!=len2-1)
            {
                temp = temp + base;
                carry = -1;
            }
            else
            {
                carry = 0;
            }
            ans.push_back(temp%base);
            carry = carry + temp/base;
        }
        for(int i=len1;i<len2;i++)
        {
            temp = num2[i]+carry;
            if(temp<0)
            {
                temp=temp+base;
                carry = -1;
            }
            else
            {
                carry = 0;
            }
            ans.push_back(temp%base);
            carry = carry + temp/base;
        }
        if(carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        while(true)
        {
            auto i = ans.begin();
            if(*i != 0)
            {
                break;
            }
            else
            {
                ans.erase(i);
            }
        }
        ans[0] = (-1)*ans[0];
    }
    return ans;
}
