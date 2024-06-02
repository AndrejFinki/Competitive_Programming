#include<bits/stdc++.h>
using namespace std;
#define LL long long

set <LL> people;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    LL V; cin >> V;

    for( LL i = 1 ; i*i <= V ; i++ ){
        if( V % i ) continue;
        people.insert(i-1);
        people.insert(V/i-1);
    }

    for( const LL &i : people ) cout << i << ' '; cout << endl;

}
