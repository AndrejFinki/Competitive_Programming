#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define endl '\n'

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t; cin >> t;
    while( t-- ){

        int A, B; cin >> A >> B;

        if( A < B || (A-B)%2 ){ cout << "impossible" << endl; continue; }

        int y = ( A - B ) / 2;
        int x = B + y;

        cout << x << ' ' << y << endl;

    }

}
