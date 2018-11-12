#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int n, m;

    cin >> n;
    cin >> m;
    
    int a[n], b[n];
        
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    
    for(int j = 0; j < n; j++)
    {
	    for(int i = 0; i < n; i++)
	    {
	        if(m >= a[i]){
	        	m += b[i];
	        	a[i] = 0;
	        	b[i] = 0;
			}
	    }
	}
    cout<<m<<endl;
    
	return 0;
}
