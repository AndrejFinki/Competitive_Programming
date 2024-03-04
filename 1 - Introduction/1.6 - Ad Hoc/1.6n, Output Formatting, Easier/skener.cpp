#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void printChar(int,int,char);

const int maxN = 50*5 + 5;
int R, C, Zr, Zc;
string OUT[maxN] = {};

int main()
{
    ios::sync_with_stdio( false );

    cin >> R >> C >> Zr >> Zc;

    for( int i = 0 ; i < R ; i++ ) for( int j = 0 ; j < C ; j++ ){
        char c; cin >> c;
        printChar(i,j,c);
    }

    for( int i = 0 ; i < R*Zr ; i++ ) cout << OUT[i] << endl;

}

void printChar( int i, int j, char c ){

    i *= Zr;
    j *= Zc;

    for( int _i = i ; _i-i < Zr ; _i++ ) for( int _j = j ; _j-j < Zc ; _j++ ){
        OUT[_i] += c;
    }

}
