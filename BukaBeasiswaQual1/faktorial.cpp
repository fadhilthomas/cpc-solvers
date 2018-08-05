#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long long faktorial, n;

    cin >> n;
    faktorial = 1;
    for(int i=1; i<=n; i++)
    {
        faktorial *= i;
    }
    cout << faktorial << endl;
    return 0;
}
