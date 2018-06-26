#include <iostream>
using namespace std;


int main(){

	int n, m, k;

	cin >> n >> m;

	int a[n], b[n], num[100001];

	for(int i = 0; i < 100001; ++i){
		num[i]=0;
	}

	for(int i = 0; i < n; i++){
		cin >> k;
		a[i] = k;
	}

	b[n-1]=1;
	num[a[n-1]] = 1;
	for(int i = n-2; i >= 0; --i){
		if(num[a[i]] == 1){
			b[i] = b[i+1];
		}
		else{
			num[a[i]] = 1;
			b[i] = b[i+1] + 1;
		}
	}

	for (int i = 0; i < m; ++i)
	{
		cin >> k;
		cout << b[k-1] << endl;
	}


	return 0;
}