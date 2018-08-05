#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int data[100005];

    int upper, lower, guess;
    int n, query, x;

    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> data[i];
    }

    cin >> query;
    for(int i=0; i<query; i++)
    {
        cin >> x;

        upper = n-1;
        lower = 0;

        while(upper >= lower)
        {
            guess = lower + (upper - lower)/ 2;
            if(data[guess] > x)
            {
                upper = guess - 1;
            }
            else if(data[guess] < x)
            {
                lower = guess + 1;
            }
            else
            {
                break;
            }
        }

        data[guess] == x ? cout << "Ada\n" : cout << "Tidak Ada\n";
    }

    return 0;
}
