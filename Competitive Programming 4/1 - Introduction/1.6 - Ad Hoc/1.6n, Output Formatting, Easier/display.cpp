#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void init();
void printTime(string);

string digitToString[10];
string OUT[7];

int main()
{
    ios::sync_with_stdio( false );

    init();

    string S;
    while( cin >> S && S != "end" ){
        for( string &S : OUT ) S = "";
        printTime(S);
    }

    cout << "end" << endl;
}

void printTime( string S ){

    function <void(int)> addDigit = [](int d) -> void {
        for( int i = 0 ; i < 7 ; i++ ){
            OUT[i] += digitToString[d].substr(i*5,5);
        } 
    };

    function <void(string)> addSpacing = [](string s) -> void {
        for( int i = 0 ; i < 7 ; i++ ){
            OUT[i] += s[i];
        }
    };

    addDigit(S[0]-'0');
    addSpacing("       ");
    addSpacing("       ");
    addDigit(S[1]-'0');
    addSpacing("       ");
    addSpacing("       ");
    addSpacing("  o o  ");
    addSpacing("       ");
    addSpacing("       ");
    addDigit(S[3]-'0');
    addSpacing("       ");
    addSpacing("       ");
    addDigit(S[4]-'0');

    for( int i = 0 ; i < 7 ; i++ ){
        cout << OUT[i] << endl;
    } cout << endl << endl;


}

void init(){

    digitToString[0] = "+---+|   ||   |+   +|   ||   |+---+";
    digitToString[1] = "    +    |    |    +    |    |    +";
    digitToString[2] = "+---+    |    |+---+|    |    +---+";
    digitToString[3] = "+---+    |    |+---+    |    |+---+";
    digitToString[4] = "+   +|   ||   |+---+    |    |    +";
    digitToString[5] = "+---+|    |    +---+    |    |+---+";
    digitToString[6] = "+---+|    |    +---+|   ||   |+---+";
    digitToString[7] = "+---+    |    |    +    |    |    +";
    digitToString[8] = "+---+|   ||   |+---+|   ||   |+---+";
    digitToString[9] = "+---+|   ||   |+---+    |    |+---+";

}
