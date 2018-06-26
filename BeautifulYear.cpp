#include <iostream>
using namespace std;

int main() {
	
	int n;
	
	cin >> n;
	
	int a, b, c, d, v = n;
	
	++n;
	while(n){
	    
	    int a, b, c, d, v = n;
	    a= v/1000;
	    v = v%1000;
	    b= v/100;
	    v=v%100;
	    c=v/10;
	    d= v%10;
	    
        if(a!=b && a!=c && a!=d && b!=c && b!=d && c!=d){
            cout << n << endl;
            return 0;
        }
	    n++;
	}
	return 0;
}