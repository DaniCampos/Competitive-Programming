#include <iostream>
using namespace std;

int ptos[50], tiempo[50], lugar[50];


int main(){
	
	int n, k;

	cin >> n >> k;

	int p, t;

	for (int i = 0; i < n; ++i)
	{

		cin >> p >> t;

		ptos[i] = p;
		tiempo[i] = t;
	}
	int val;
	for(int j = 0; j < n; ++j){
		for(int i = 0; i < n-j-1; ++i){

			if(ptos[i]>ptos[i+1]){
				val = ptos[i];
				ptos[i] = ptos[i+1];
				ptos[i+1] = val;

				val = tiempo[i];
				tiempo[i] = tiempo[i+1];
				tiempo[i+1] = val;
			}
		}
	}

	for(int j = 0; j < n; ++j){
		for(int i = 0; i < n-j-1; ++i){

			if(ptos[i] == ptos[i+1] && tiempo[i] < tiempo[i+1]){
				val = ptos[i];
				ptos[i] = ptos[i+1];
				ptos[i+1] = val;

				val = tiempo[i];
				tiempo[i] = tiempo[i+1];
				tiempo[i+1] = val;
			}

		}
	}


	int cant = 1;

	bool val1 = true, val2 = true;

	int i1 = n-k, i2 = n-k;
	while(val1){

		if(i1 == n-1){

			val1 = false;
		}
		else if(ptos[i1+1] == ptos[i1] && tiempo[i1+1] == tiempo[i1]){
			cant++;
			i1++;
		}
		else{
			val1=false;
		}
	}

	while(val2){
		if(i2 == 0) val2 = false;
		else if(ptos[i2-1] == ptos[i2] && tiempo[i2-1]==tiempo[i2]){
			cant++;
			i2--;
		}
		else{
			val2=false;
		}
	}

	cout << cant << endl;

	return 0;
}