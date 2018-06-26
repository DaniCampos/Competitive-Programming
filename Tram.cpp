#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  int cantmin;
  int cant2;
  int a;
  int b;


  cin >> a;
  cin >> b;

  cantmin = b;
  cant2 = b;

  

  while (--(n))
  {    
    cin >> a;
    cin >> b;
    cant2 = cant2 - a + b;
    
    if (cant2 > cantmin)
    {
      cantmin = cant2;
    } 
  }

  cout << cantmin << endl;

  return 0;
}