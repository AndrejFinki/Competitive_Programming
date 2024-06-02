#include<bits/stdc++.h>
using namespace std;

const int maxN = 105;
int N, R;
bool reserved[maxN] = {};

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> R;

    while( R-- ){
        int _t; cin >> _t;
        reserved[_t] = true;
    }

    for( int i = 1 ; i <= N ; i++ ){
        if( reserved[i] ) continue;
        cout << i << endl;
        return 0;
    }

    cout << "too late" << endl;

}
