#include<iostream>
#include <queue>  
#define mp make_pair
#define f first
#define s second
using namespace std;
typedef pair<int, int> pii;

int main(){

	int n, m, k, s=0, l;

	cin >> n >> m >> k;

	vector < vector<char> > grilla(n, vector<char>(m));  // pre-allocate memory
	vector < vector<int> > reg(n, vector<int>(m));
	vector < vector<char> > resultado(n, vector<char>(m));

	pii pos;


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> grilla[i][j];
			resultado[i][j] = '.';
			if(grilla[i][j] == '.'){
				s++;
				pos = mp(i, j);
			}
			if(grilla[i][j] == '#'){
				resultado[i][j]='#';
			}
			
		}
	}

	l = s-k-1;

	queue<pii> q;

	reg[pos.f][pos.s] = 1;


	if(pos.f>0 && grilla[pos.f-1][pos.s]=='.' && reg[pos.f-1][pos.s]!=1){
		if(l>0){
			q.push(mp(pos.f-1, pos.s));
			reg[pos.f-1][pos.s]=1;
			l--;	
		}
	}
	if(pos.f<n-1 && grilla[pos.f+1][pos.s]=='.' && reg[pos.f+1][pos.s]!=1){
		if(l>0){
			q.push(mp(pos.f+1, pos.s));
			reg[pos.f+1][pos.s]=1;
			l--;	
		}
	}
	if(pos.s>0 && grilla[pos.f][pos.s-1]=='.' && reg[pos.f][pos.s-1]!=1){
		if(l>0){
			q.push(mp(pos.f, pos.s-1));
			reg[pos.f][pos.s-1]=1;
			l--;	
		}
	}
	if(pos.s<m-1 && grilla[pos.f][pos.s+1]=='.' && reg[pos.f][pos.s+1]!=1){
		if(l>0){
			q.push(mp(pos.f, pos.s+1));
			reg[pos.f][pos.s+1]=1;
			l--;	
		}
	}

	while(!q.empty() && l>0){
		pos = q.front();
		q.pop();

		if(pos.f>0 && grilla[pos.f-1][pos.s]=='.' && reg[pos.f-1][pos.s]!=1){
			if(l>0){
				q.push(mp(pos.f-1, pos.s));
				reg[pos.f-1][pos.s]=1;
				l--;	
			}
		}
		if(pos.f<n-1 && grilla[pos.f+1][pos.s]=='.' && reg[pos.f+1][pos.s]!=1){
			if(l>0){
				q.push(mp(pos.f+1, pos.s));
				reg[pos.f+1][pos.s]=1;
				l--;	
			}
		}
		if(pos.s>0 && grilla[pos.f][pos.s-1]=='.' && reg[pos.f][pos.s-1]!=1){
			if(l>0){
				q.push(mp(pos.f, pos.s-1));
				reg[pos.f][pos.s-1]=1;
				l--;	
			}
		}
		if(pos.s<m-1 && grilla[pos.f][pos.s+1]=='.' && reg[pos.f][pos.s+1]!=1){
			if(l>0){
				q.push(mp(pos.f, pos.s+1));
				reg[pos.f][pos.s+1]=1;
				l--;	
			}
		}	

	}




	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(grilla[i][j]=='.' && reg[i][j]!= 1){
				resultado[i][j] = 'X';
			}	
		}
	}

	for(int a=0;a<n;a++){
		for(int b=0;b<m;b++){
			cout << resultado[a][b];
		}
		cout << endl;
	}

	return 0;
}