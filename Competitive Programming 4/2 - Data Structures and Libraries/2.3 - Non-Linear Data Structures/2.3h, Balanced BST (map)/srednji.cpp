#include<bits/stdc++.h>
using namespace std;

int solve();

const int maxN = 100005;
int N, B;
int A[maxN];
int cL[maxN] = {}, cR[maxN] = {};
int cL_range, cR_range;
map <int, int> freq;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N >> B;

    for( int i = 0 ; i < N ; i++ ) cin >> A[i];

    cout << solve() << endl;

}

int solve(){

    function <int()> get_median_idx = []() -> int {
        for( int i = 0 ; i < N ; i++ ) if( A[i] == B ) return i;
        return -1;
    };

    int rv = 0;

    int Bi = get_median_idx();

    cL[0] = 0;
    for( int i = 1 ; Bi - i >= 0 ; i++ ){
        cL[i] = cL[i-1] + ( B > A[Bi-i] ? -1 : 1 );
        cL_range = i;
    }

    cR[0] = 0; freq[0]++;
    for( int i = 1 ; Bi + i < N ; i++ ){
        cR[i] = cR[i-1] + ( B > A[Bi+i] ? -1 : 1 );
        cR_range = i;
        freq[ cR[i] ]++;
    }

    for( int i = 0 ; i <= cL_range ; i++ ){
        rv += freq[ -cL[i] ];
    }

    return rv;

}
