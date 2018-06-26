#include <iostream>
using namespace std;

int dp[4001];

int f2(int n, int a, int b, int c){
	

	if(n == 0){
		//dp[n] = 0;
		return 0;
	}
	else if(n < 0){
		return -100000000;
	}
	else if(dp[n] != -1){
		return dp[n];
	}
	else{
		dp[n] = 1 + max(f2(n-a,a,b,c), max(f2(n-b,a,b,c), f2(n-c,a,b,c)));
	}
	
	return dp[n];

}

int main(){
	
	int n, a, b, c;

	cin >> n >> a >> b >> c;

	dp[0] = 0;

	for (int i = 1; i <= n; ++i)
	{
		dp[i] = -1;
	}

	cout <<f2(n,a,b,c) << endl;


	return 0;
}	