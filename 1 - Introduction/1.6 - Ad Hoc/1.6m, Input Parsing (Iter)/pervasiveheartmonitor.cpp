#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

int main()
{
    ios::sync_with_stdio( false );

    string line;
    while( getline( cin, line ) ){

        stringstream SS(line);
        string S;

        LD SUM = 0; int COUNT = 0; string NAME = "";
        while( SS >> S ){
            if( isdigit(S[0]) ){ SUM += stod(S); COUNT++; }
            else{ NAME += " " + S; }
        }

        cout << fixed << setprecision(6) << SUM/COUNT << NAME << endl;

    }
}
