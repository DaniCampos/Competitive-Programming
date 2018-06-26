#include <iostream>
#include <queue>  
#define mp make_pair
#define f first
#define s second
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, m;

	cin >> n >> m;

	vector < vector<char> > grilla(n, vector<char>(m));  // pre-allocate memory
	vector < vector<int> > reg(n, vector<int>(m));
	vector < vector<char> > resultado(n, vector<char>(m));

	string fila;

	for (int i = 0; i < n; ++i){
		cin >> fila;
		for (int j = 0; j < m; ++j){
			grilla[i][j] = fila[j];
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if(grilla[i][j] == '.'){
				if(i%2==0){
					if(j%2==0){
						grilla[i][j]='B';
					}
					else{
						grilla[i][j]='W';
					}
				}
				else{
					if(j%2==0){
						grilla[i][j]='W';
					}
					else{
						grilla[i][j]='B';
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cout << grilla[i][j];
		}
		cout << endl;
	}

	return 0;
}