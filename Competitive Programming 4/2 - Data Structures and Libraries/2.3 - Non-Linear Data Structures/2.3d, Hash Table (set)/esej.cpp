#include<bits/stdc++.h>
using namespace std;

string generateWord(int);

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int L, R;
    cin >> L >> R;

    for( int i = 0 ; i < R ; i++ ) cout << generateWord(i) << ' '; cout << endl; 

}

string generateWord( int v ){
    string rv = "a";
    while(v){
        rv += (v%26) + 'a';
        v /= 26;
    } return rv;
}
