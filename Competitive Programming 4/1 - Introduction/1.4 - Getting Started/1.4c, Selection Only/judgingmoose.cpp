#include<bits/stdc++.h>
using namespace std;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int L, R; cin >> L >> R;

    if( !L && !R ) cout << "Not a moose" << endl;
    else if( L == R ) cout << "Even " << L+R << endl;
    else cout << "Odd " << 2*max(L,R) << endl;

}
