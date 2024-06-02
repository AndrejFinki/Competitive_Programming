#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

struct numberCost{
    int C = 0, L = 0, X = 0, V = 0, I = 0;
    numberCost(){}
    const bool operator == ( const numberCost &o ){
        return C == o.C && L == o.L && X == o.X && V == o.V && I == o.I;
    }
};

void init();
numberCost findNumberCost( int );
string decimalToRoman( int );
int romanToDecimal( string );

pair <string, int> romanDigits[] = { { "C", 100 }, { "XC", 90 }, { "L", 50 }, { "XL", 40 }, { "X", 10 }, { "IX", 9 }, { "V", 5 }, { "IV", 4 }, { "I", 1 } };
int romanMap[256] = {};
numberCost A[100];

int main()
{
    ios::sync_with_stdio( false );

    init();

    for( int i = 1 ; i < 100 ; i++ ){
        A[i] = findNumberCost(i);
    }

    string R; cin >> R;
    int D = romanToDecimal(R);
    numberCost DNumberCost = A[D];

    int minNum = -1;
    for( int i = 1 ; i < 100 ; i++ ){
        if( DNumberCost == A[i] ){ minNum = i; break; }
    }

    cout << decimalToRoman(minNum) << endl;

}

int romanToDecimal( string R ){
    int rv = 0, maxDigit = 0;
    for( int i = R.length() - 1 ; i >= 0 ; i-- ){
        int D = romanMap[R[i]];
        rv += ( D >= maxDigit ? D : -D );
        maxDigit = max( maxDigit, D );
    }
    return rv;
}

numberCost findNumberCost( int D ){
    numberCost rv;
    string R = decimalToRoman(D);
    for( char c : R ){
        if( c == 'C' ) rv.C++;
        if( c == 'L' ) rv.L++;
        if( c == 'X' ) rv.X++;
        if( c == 'V' ) rv.V++;
        if( c == 'I' ) rv.I++;
    }
    return rv;
}

string decimalToRoman( int D ){
    string rv = "";
    for( int i = 0 ; i < 9 ; i++ ){
        while( D >= romanDigits[i].second ){
            rv += romanDigits[i].first;
            D -= romanDigits[i].second;
        }
    }
    return rv;
}

void init(){
    romanMap['C'] = 100;
    romanMap['L'] = 50;
    romanMap['X'] = 10;
    romanMap['V'] = 5;
    romanMap['I'] = 1;
}
