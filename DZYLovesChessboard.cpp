#include<iostream>
#include <queue>  
#define mp make_pair
#define f first
#define s second
using namespace std;
typedef pair<char, pair<int, int> > pii;

int main(){

	int n,m;

	cin >> n >> m;

	vector < vector<char> > grilla(n, vector<char>(m));  // pre-allocate memory
	vector < vector<int> > reg(n, vector<int>(m));
	vector < vector<char> > resultado(n, vector<char>(m));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grilla[i][j];
		}
	}

	int ip, jp;
	queue<pii> q;
	pii pos;
	char l = 'B';
	int a = 0;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grilla[i][j] == '.' && reg[i][j]!=1){

				reg[i][j]=1;

				if(i>0 && grilla[i-1][j]=='.' && reg[i-1][j]!=1){
					q.push(mp(l,mp(i-1, j)));
					reg[i-1][j]=1;
				}
				if(i<n-1 && grilla[i+1][j]=='.' && reg[i+1][j]!=1){
					q.push(mp(l,mp(i+1, j)));
					reg[i+1][j]=1;
				}
				if(j>0 && grilla[i][j-1]=='.' && reg[i][j-1]!=1){
					q.push(mp(l,mp(i, j-1)));
					reg[i][j-1]=1;
				}
				if(j<m-1 && grilla[i][j+1]=='.' && reg[i][j+1]!=1){
					q.push(mp(l,mp(i, j+1)));
					reg[i][j+1]=1;
				}

				resultado[i][j]=l;

				while(!q.empty()){
				
					pii actual = q.front();
					q.pop();

					//cout << actual.s.f << " " << actual.s.s << endl;

					reg[actual.s.f][actual.s.s]=1;
					if(actual.f == 'B'){
						l = 'W';
					}
					else{
						l = 'B';
					}

					if(actual.s.f>0 && grilla[actual.s.f-1][actual.s.s]=='.' && reg[actual.s.f-1][actual.s.s]!=1){
						q.push(mp(l,mp(actual.s.f-1, actual.s.s)));
						reg[actual.s.f-1][actual.s.s]=1;
					}
					if(actual.s.f<n-1 && grilla[actual.s.f+1][actual.s.s]=='.' && reg[actual.s.f+1][actual.s.s]!=1){
						q.push(mp(l,mp(actual.s.f+1, actual.s.s)));
						reg[actual.s.f+1][actual.s.s]=1;
					}
					if(actual.s.s>0 && grilla[actual.s.f][actual.s.s-1]=='.' && reg[actual.s.f][actual.s.s-1]!=1){
						q.push(mp(l,mp(actual.s.f, actual.s.s-1)));
						reg[actual.s.f][actual.s.s-1]=1;
					}
					if(actual.s.s<m-1 && grilla[actual.s.f][actual.s.s+1]=='.' && reg[actual.s.f][actual.s.s+1]!=1){
						q.push(mp(l,mp(actual.s.f, actual.s.s+1)));
						reg[actual.s.f][actual.s.s+1]=1;
					}

					resultado[actual.s.f][actual.s.s]=l;	

				}	

			}
			else if(grilla[i][j]=='-'){
				resultado[i][j]='-';
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout << resultado[i][j];
		}
		cout << endl;
	}

	return 0;
}