#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL long long
#define LD long double

int main()
{
    ios::sync_with_stdio( false );

    bool foundOne = false;
    int N; cin >> N;

    for( int i = 0 ; i < N ; i++ )
    {
        bool hasPancakes = false, hasPeaSoup = false;
        int k; cin >> k; cin.ignore();
        string NAME, S;
        getline( cin, NAME );

        for( int i = 0 ; i < k ; i++ )
        {
            getline( cin, S );
            if( S == "pancakes" ) hasPancakes = true;
            if( S == "pea soup" ) hasPeaSoup = true;
        }

        if( hasPancakes && hasPeaSoup ) {
            foundOne = true;
            cout << NAME << endl;
            break;
        }
    } 

    if( !foundOne ) cout << "Anywhere is fine I guess" << endl;
}
