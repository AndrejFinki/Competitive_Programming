#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int maxV = 10;
int L = 1, R = maxV, G;

int main()
{
    ios::sync_with_stdio( false );

    string response;
    while( cin >> G && G ){ cin.ignore();

        getline( cin, response );

        if( response == "right on" ){
            cout << ( L <= R && L <= G && G <= R ? "Stan may be honest" : "Stan is dishonest" ) << endl;
            L = 1; R = maxV;
        }else if( response == "too high" ){
            R = min( R, G-1 );
        }else{
            L = max( L, G+1 );
        }

    }
}
