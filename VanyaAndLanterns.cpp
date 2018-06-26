#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
ll h[100010];

int main(){
	ios::sync_with_stdio(0);

	int n; 
	double l,maxi, a;
	cin >> n; 
	cin >> l;

	for (int i = 0; i < n; ++i)cin >> h[i];
	sort(h, h+n ) ;
	maxi = 2*(h[0]-0.0);

	for (int i = 1; i < n; ++i){

		a = h[i]-h[i-1];
		if (a > maxi) maxi = a;

	}

	a = 2*(l - h[n-1]);
	if (a > maxi) maxi = a;

	printf("%.10f\n",maxi/2.0);

	return 0;
}