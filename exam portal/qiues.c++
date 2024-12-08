#include <bits/stdc++.h>
#include <string> // Include this header for stoi
using namespace std;

int main()
{
    string ans, var;
    cin >> ans;
    vector<int> num;

    for (int i = 0; i < ans.length(); i++)
    {
        if (isdigit(ans[i]))
        {
            var += ans[i];
        }
        else
        {
            if (!var.empty())
            {
                num.push_back(stoi(var));
                var = "";
            }
        }
    }

    // To handle the last accumulated number if the string ends with a digit
    if (!var.empty())
    {
        num.push_back(stoi(var));
    }

    for (int i = 0; i < num.size(); i++)
    {
        cout << num[i] << endl;
    }

    return 0;
}
