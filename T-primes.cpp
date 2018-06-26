#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

int main(){

	int n = 1000000;
	
	//int n = ;
	int primos1[n+1];

	memset(primos1, -1, sizeof(primos1));

	primos1[1] = 1;

	for(int p = 2; p*p <= n ; p++){
		if(primos1[p] == -1){
			//Tprimos[p*p] = 1;
			for (int i = p*2; i <=n ; i+=p){
				primos1[i] = p;
			}

		}
	}


	int ent;

	cin >> ent;

	for (int i = 1; i <= ent; ++i)
	{
		long long val, primo;
		cin >> val;
		
		if(sqrt(val) - int(sqrt(val)) != 0){
			cout << "NO" << endl;
		}
		else{
			if(primos1[int(sqrt(val))] == -1){
				cout << "YES" << endl;
			}
			else{
				cout << "NO" << endl;
			}
		}
	}

	return 0;

}