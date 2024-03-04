#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define endl '\n'

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N, M; cin >> N >> M;

    if( M < N ) cout << "Dr. Chaz needs " << N-M << " more " << ( N-M == 1 ? "piece" : "pieces" ) << " of chicken!" << endl;
    else        cout << "Dr. Chaz will have " << M-N << " " << ( M-N == 1 ? "piece" : "pieces" ) << " of chicken left over!" << endl;

}
