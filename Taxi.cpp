#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int g1, g2, g3, g4; 
	g1=0;
	g2=0;
	g3=0;
	g4=0;
	int taxis;
	taxis = 0;

	for (int i = 0; i < n; ++i)
	{
		int s;
		cin >> s;
		if(s == 1)++g1;
		else if(s==2)++g2;
		else if(s==3)++g3;
		else ++g4;
	}

	while((g1 > 0)&& (g3 >0))// 1
	{
		--g1;
		--g3;
		++taxis;
	}

	while((g1 > 1) && (g2 > 0) )//3
	{
		g1 -= 2;
		--g2;
		++taxis;
	}

	while(g1 > 0 && g2 > 0)
	{
		--g1;
		--g2;
		++taxis;
	}

	while(g1>0)//4
	{
		++taxis;
		g1 -=4;
	}

	while((g2 > 0))//2
	{
		g2 -= 2;
		++taxis;
	}

	if(g1 < 0)
	{
		g1 = 0;
	}

	if(g2 < 0)
	{
		g2 = 0;
	}
	
	taxis = taxis + g1 + g2 + g3 +g4;

	cout << taxis << endl;

	return 0;
}