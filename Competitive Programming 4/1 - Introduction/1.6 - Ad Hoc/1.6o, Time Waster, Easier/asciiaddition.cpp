#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void init();
pair <int, int> findNumbers();
void printAscii( int );

string digitToString[10];
map <string, int> stringToDigit;
string IN[7], OUT[7] = {};

int main()
{
    ios::sync_with_stdio( false );

    init();

    for( int i = 0 ; i < 7 ; i++ ) getline( cin, IN[i] );

    pair <int, int> numbers = findNumbers();
    
    int sum = numbers.first + numbers.second;

    printAscii(sum);
}

void printAscii( int x ){

    string S = to_string(x);
    for( int i = 0 ; i < S.length() ; i++ ){
        if( i ){ for( int j = 0 ; j < 7 ; j++ ) OUT[j] += "."; }
        string ds = digitToString[S[i]-'0'];
        for( int j = 0 ; j < 7 ; j++ ){
            OUT[j] += ds.substr(j*5,5);
        }
    }

    for( int i = 0 ; i < 7 ; i++ ) cout << OUT[i] << endl;

}

pair <int, int> findNumbers(){

    int a = 0, b = 0; bool onFirstNumber = true;
    for( int i = 0 ; i < IN[0].length() ; i += 6 ){
        string currentDigit = "";
        for( int j = 0 ; j < 7 ; j++ ){
            currentDigit += IN[j].substr(i,5);
        }
        int digit = stringToDigit[currentDigit];
        if( digit == -1 ){ onFirstNumber = false; continue; }
        ( onFirstNumber ? a : b ) *= 10;
        ( onFirstNumber ? a : b ) += digit;
    }

    return {a,b};

}

void init(){

    digitToString[0] = "xxxxxx...xx...xx...xx...xx...xxxxxx";
    digitToString[1] = "....x....x....x....x....x....x....x";
    digitToString[2] = "xxxxx....x....xxxxxxx....x....xxxxx";
    digitToString[3] = "xxxxx....x....xxxxxx....x....xxxxxx";
    digitToString[4] = "x...xx...xx...xxxxxx....x....x....x";
    digitToString[5] = "xxxxxx....x....xxxxx....x....xxxxxx";
    digitToString[6] = "xxxxxx....x....xxxxxx...xx...xxxxxx";
    digitToString[7] = "xxxxx....x....x....x....x....x....x";
    digitToString[8] = "xxxxxx...xx...xxxxxxx...xx...xxxxxx";
    digitToString[9] = "xxxxxx...xx...xxxxxx....x....xxxxxx";

    stringToDigit["xxxxxx...xx...xx...xx...xx...xxxxxx"] = 0;
    stringToDigit["....x....x....x....x....x....x....x"] = 1;
    stringToDigit["xxxxx....x....xxxxxxx....x....xxxxx"] = 2;
    stringToDigit["xxxxx....x....xxxxxx....x....xxxxxx"] = 3;
    stringToDigit["x...xx...xx...xxxxxx....x....x....x"] = 4;
    stringToDigit["xxxxxx....x....xxxxx....x....xxxxxx"] = 5;
    stringToDigit["xxxxxx....x....xxxxxx...xx...xxxxxx"] = 6;
    stringToDigit["xxxxx....x....x....x....x....x....x"] = 7;
    stringToDigit["xxxxxx...xx...xxxxxxx...xx...xxxxxx"] = 8;
    stringToDigit["xxxxxx...xx...xxxxxx....x....xxxxxx"] = 9;

    stringToDigit[".......x....x..xxxxx..x....x......."] = -1;

}
