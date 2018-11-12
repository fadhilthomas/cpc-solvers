#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n, o, i, j, temp;

    cin >> n;
    int a[n];
    
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(i=0;i<n;i++)
	{		
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				temp  =a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
	
	for(i=0;i<10;i++)
	{
	 	for(j=0;j<n;j++)
		{
			if(a[j] % 10 == i)
			{
				cout<<a[j]<<endl;
			}
 		}
 	}
	return 0;
}
