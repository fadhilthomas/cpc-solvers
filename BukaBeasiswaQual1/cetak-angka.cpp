#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    long n, angka;

    cin >> n;

    angka = n%10;
    if(angka == 3)
    {
        cout << "Hore tanggal lahirku!" << endl;
    }
    else if(angka == 1 ||angka == 4 || angka == 9)
    {
        cout << "Hore angka kuadrat kesukaanku!" << endl;
    }
    else
    {
        cout << "Bukan angka kesukaanku" << endl;
    }
    n /= 10;

    while(n > 0)
    {
    	angka = n%10;
        if(angka == 3)
        {
            cout << "Hore ada angka 3!" << endl;
        }
        else if(angka == 1 ||angka == 4 || angka == 9)
        {
            cout << "Hore ada angka kuadrat!" << endl;
        }
        else
        {
            cout << "Bukan angka kesukaanku" << endl;
        }
        n /= 10;
    }

    return 0;
}
