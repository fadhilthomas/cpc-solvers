#include <cstdio>
#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> data;
    int n;
    cin >> n;
    while(n>0){
    	if(n%2==0){
    		data.push_front(0);
		}else{
			data.push_front(1);
		}
		n/=2;
	}
	for (list<int>::iterator it=data.end(); it != data.begin(); --it){
    	cout << *it;
    }
    cout<<"\n";
}
