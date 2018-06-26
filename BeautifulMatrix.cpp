#include <iostream>

using namespace std;

int steps(int I,int J){
	int a,b;
	a = I-3;
	b = J-3; 
	if(a<0)a=a*(-1);
	if(b<0)b=b*(-1);
	return a+b;
}

int main(){

	int n;
	int I;
	int J;
	
	for (int i = 1; i <= 5 ; ++i){
		for (int j = 1; j <= 5 ; ++j){
			cin >> n;
			if(n==1){
				I=i;
				J=j;
			}	
		}
	}

	cout << steps(I,J)<< endl;




	return 0;
}