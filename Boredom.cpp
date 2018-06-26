#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*int pre[100001];
int DP[100001];
int max1 = 0;
int maxDP = 0;



void dp(int n,int i){

	DP[i] = DP[i-2] + pre[i]*i;

	if(DP[i] > maxDP){
		maxDP = DP[i];
	}

}*/
int main(){
	
	int n, maxValue = 0, val;
	vector<long long int> arr(100010);

	cin >> n;

	for (int i = 0; i < n; ++i){
		cin >> val;
		arr[val]++;
		if(val > maxValue){
			maxValue = val;
		}
	}

	vector<long long int> maxDP(100002);

	maxDP[1]=arr[1];

	for (int i = 2; i <= maxValue; ++i){
		/*int maxAnt;
		if(arr[i-1]==0){
			maxAnt=maxDP[i-1];
		}
		else{
			maxAnt=maxDP[i-2]; 
		}

		if(arr[i]==0){
			maxDP[i]=maxDP[i-1];
		}
		else{
			maxDP[i]=max(maxAnt+arr[i]*i, maxDP[i-1]);
		}*/
		maxDP[i] = max(maxDP[i-1], maxDP[i-2] + arr[i]*i);	
	}

	/*for (int i = 0; i <= maxValue; ++i){
		cout << maxDP[i] << endl;
	}*/
	cout << maxDP[maxValue] << endl;	

	return 0;
}