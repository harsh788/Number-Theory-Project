//Harsh Shah - IMT2020006, Anwit Damale - IMT2020532

#include"addition.hpp"
#include"subtraction.hpp"
#include"multiplication.hpp"
#include"division.hpp"
#include"real.hpp"
#include"squareroot.hpp"
#include"pi.hpp"

int main()
{
    int base, precision, m, choice;
    cin >> choice >> precision >> m;

    base = pow(2, m);    

    //For addition, subtraction, multiplication
    /*pair<vector<int>, int> num1 = {{8, 4, 0}, -3};
    pair<vector<int>, int> num2 = {{6,8,7,9,2,1,0}, -6};
    pair<vector<int>, int> ans;

    //ans = add_real(num1, num2, base);
    //ans = subtract_real(num2, num1, base);
    ans = multiply_real(num1, num2, base);
    
    for(int i=0;i<ans.first.size();i++)
    {
        cout << ans.first[i];
    }
    cout << ans.second << endl;*/

    //For division
    /*pair<vector<int>, int> num1 = {{5, 4, 5, 3, 4,2,4}, -4};
    pair<vector<int>, int> num2 = {{3, 7, 5, 8, 1, 8, 0}, -5};
    pair<vector<int>, int> ans;

    ans = divide_real(num1, num2, precision, base);
    
    cout << "Quotient: ";
    for(int i=0;i<ans.first.size();i++)
    {
        cout << ans.first[i];
    }
    cout << "x" << base << "^" << ans.second << endl;*/

    if(choice == 2)
    {
        //For square root
        pair<vector<int>,int> num = {{2}, 0}, ans;
        ans = root(num, precision, base);
        for(int i=0;i<ans.first.size();i++)
        {
            if(i==1)
            {
                cout << ".";
            }
            cout << ans.first[i];
        }
    }

    if(choice == 1)
    {
        //For pi
        pair<vector<int>, int> ans = pi(precision+5, base);
        for(int i=0;i<ans.first.size();i++)
        {
            if(i==1)
            {
                cout << ".";
            }
            cout << ans.first[i];
        }
    }
    cout << endl;
}