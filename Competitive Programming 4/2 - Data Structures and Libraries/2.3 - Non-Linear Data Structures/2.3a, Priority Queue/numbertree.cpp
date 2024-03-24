#include <bits/stdc++.h>
using namespace std;

int main(){ ios::sync_with_stdio(false);

    int H; string S = "";
    cin >> H >> S;

    int n = 1;
    for( const char &c : S ) n = 2*n + bool( c == 'R' );
    
    cout << (2<<H)-n << endl;

}
