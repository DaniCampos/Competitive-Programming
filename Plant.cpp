#include <iostream>

using namespace std;

#define ll long long

ll m = 1000000007;

ll modpow(ll base, ll exp) {

   ll result = 1;

   while (exp > 0) {
      if ((exp & 1) > 0) result = (result * base) % m;
      exp >>= 1;
      base = (base * base) % m;
   }

   return result;

 }

int main(){

	ll n;

	cin >> n;

	ll a = modpow(2,n);

	ll count = 0;

	for(ll i = 1; i <= a; i++){
		count+=i;
	}

	cout << count%m << endl;

	return 0;
}