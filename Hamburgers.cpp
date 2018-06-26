//Hamburgers

#include <iostream>
#include <string>
using namespace std;

bool precioreceta(long long recetaB, long long recetaS, long long recetaC,long long nB, long long nS,long long nC,long long pB,long long pS, long long pC,long long ham, long long r){

	if(recetaB*ham - nB > 0) r = r - (recetaB*ham - nB)*pB;
	if(recetaS*ham - nS > 0) r = r - (recetaS*ham - nS)*pS;
	if(recetaC*ham - nC > 0) r = r - (recetaC*ham - nC)*pC;

	if(r >= 0) return 1;

	else return 0;
}

long long BinarySearch(long long min,long long max,long long recetaB,long long recetaS,long long recetaC,long long nB,long long nS,long long nC,long long pB,long long pS,long long pC,long long r){
	
	long long pos = -1,mid;

	while(min < max){
		mid = min + (max-min)/2;
		if(precioreceta(recetaB,recetaS,recetaC,nB,nS,nC,pB,pS,pC,mid,r)){
			pos = mid;
			min = mid + 1;
		}
		else max = mid;
	}

	if(pos == -1)return 0;
	else return pos;

}



int main(){
	
	ios::sync_with_stdio(0); cin.tie(0);

	string s;

	cin >> s;
    
	long long recetaB=0,recetaS=0,recetaC=0;


	for (int i = 0; i < s.length(); ++i){
		if(s[i] == 'B'){
			recetaB++;
		}	
		else if(s[i] == 'S'){
			recetaS++;
		}
		else{
			recetaC++;
		}
	}

	long long nB,nS,nC,pB,pS,pC,r;

	cin >> nB >> nS >> nC >> pB >> pS >> pC >>r;

	long long min = 0, max = r*(pB+pS+pC) + nB + nS + nC;
    
    
	cout << BinarySearch(min,max,recetaB,recetaS,recetaC,nB,nS,nC,pB,pS,pC,r) << endl;




	return 0;
}