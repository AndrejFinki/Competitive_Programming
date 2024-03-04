#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define LD long double
#define endl '\n'

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N; cin >> N;
    int SUM = 0, D = 0, x;

    for( int i = 0 ; i < N ; i++ ){

        cin >> x;

        if( x == -1 ) continue;

        SUM += x; D++;

    }

    cout << fixed << setprecision(3) << (LD)SUM / D << endl;

}
