#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int FRONT = 946, BACK = 54; 

void init();
string decimalToRoman( int );
void generateRomanList();
int position( string );

pair <string, int> romanDigits[] = { { "M", 1000 }, { "CM", 900 }, { "D", 500 }, { "CD", 400 }, { "C", 100 }, { "XC", 90 }, { "L", 50 }, { "XL", 40 }, { "X", 10 }, { "IX", 9 }, { "V", 5 }, { "IV", 4 }, { "I", 1 } };
int romanMap[256] = {};
vector <string> romanList;
map <string, int> orderPosition;

int main()
{
    ios::sync_with_stdio( false );

    init();

    generateRomanList();

    int t; cin >> t;
    while( t-- ){
        int N; cin >> N;
        string R = decimalToRoman(N);
        cout << position(R) << endl;
    }
}

int position( string R ){

    int countM = 0;
    for( countM = 0 ; countM < R.length() && R[countM] == 'M' ; countM++ ){}
    
    R = R.substr(countM,INF);

    if( R.empty() ) return countM * FRONT;

    int POS = orderPosition[R];

    if( R[0] < 'M' ) return countM * FRONT + POS;
    return POS - countM * BACK - 1000;

}

void generateRomanList(){

    for( int i = 1 ; i < 1000 ; i++ ){
        romanList.push_back( decimalToRoman(i) );
    }

    sort( romanList.begin(), romanList.end() );

    for( int i = 0 ; i < romanList.size() ; i++ ){
        orderPosition[ romanList[i] ] = i+1;
    }

}

string decimalToRoman( int D ){

    string rv = "";
    for( int i = 0 ; i < 13 ; i++ ){
        while( D >= romanDigits[i].second ){
            rv += romanDigits[i].first;
            D -= romanDigits[i].second;
        }
    }
    return rv;

}

void init(){

    romanMap['M'] = 1000;
    romanMap['D'] = 500;
    romanMap['C'] = 100;
    romanMap['L'] = 50;
    romanMap['X'] = 10;
    romanMap['V'] = 5;
    romanMap['I'] = 1;

}
