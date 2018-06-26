#include <iostream>
#include <vector>
using namespace std;

struct drift{int x, y; bool v; drift(int a, int b): x(a), y(b), v(0) {};};
std::vector<drift> array;


void search(int i, int L){
    if(array[i].v == 1){return;}
    array[i].v = 1;
    for(int p = 0; p < L; p++){
        if(array[p].x == array[i].x || array[p].y == array[i].y){
            search(p, L);
        }
    }
}



int main(){

    int n; 
    cin >> n;
    for(int p = 0; p < n; p++){
        int x, y; 
        cin >> x >> y; 
        array.push_back(drift(x,y));}

    int ans = 0;
    for(int p = 0; p < n; p++){
        if(array[p].v > 0){continue;}
        ++ans;
        search(p, n);
    }

    cout << ans - 1 << endl;

    return 0;
}