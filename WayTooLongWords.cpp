#include <iostream>
#include <string>
using namespace std;

bool istoolong(string s){

	if(s.length()>10)return 1;
	else return 0;
}

int main(){
	
	int n;
	cin >> n;
	while(n--){
		string s;
		cin >> s;
		if(istoolong(s)){

			cout << s[0]+to_string((s.length()-2))+s[s.length() - 1] << endl;

		}		
		else cout << s << endl;
	
	}	
	return 0;
}