#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int main(){

	int n = 8982009;
	
	bool primos1[n+1];
	bool primos2[n+1];
	bool primos3[n+1];
	
	memset(primos1, true, sizeof(primos1));
	memset(primos2, true, sizeof(primos2));
	memset(primos3, true, sizeof(primos3));

	primos1[1] = false;
	primos2[1] = false;
	primos3[1] = false;

	for(int p = 2; p*p<=n; p++){
		if(primos1[p] == true){

			for(int i = p*2; i<=n; i+=p){

				if(primos1[i] == false && primos2[i] == false && primos3[i] == true){
					primos3[i] = false;
				}

				if((primos1[i] == false) && (primos2[i] == true)){

					primos2[i] = false;
				}
				
				primos1[i] = false;
			}
		}
	}

	int ent;

	cin >> ent;

	int bla = 0;
	int max = 0;
	for(int i = 2; i <= ent; i++){
		if(primos2[i] == false && primos3[i] == true){
			bla++;
			max = i;
		}
	}
	cout << bla<< endl;

}