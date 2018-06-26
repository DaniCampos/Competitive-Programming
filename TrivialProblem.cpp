#include <iostream>
#include <vector>
using namespace std;
 
int zeros(int n)
{
    int count = 0;

    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;
 
    return count;
}
 

int main(){

    int m;
    cin >>m;

    int x = 0, ind = 0;
    vector<int> v (400010);

    while(x <= 100000){
        x = zeros(ind);
        v[ind] = x;
        ++ind;
    }



    vector<int> found;
    int cant = 0;

    for (int i = 0; i < ind; ++i)
    {
        if(v[i] == m){
            cant++;
            found.push_back(i);
        }

    }

    cout << cant << endl;

    if(cant != 0){
        for (int i = 0; i < cant; ++i)
        {
            cout << found[i] << " ";
        }

        cout << endl;   
    }

    
    return 0;
}