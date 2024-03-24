#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

void init();
bool canBeDefused();

string BOMB[5];
map <string, int> charMap;

int main()
{
    ios::sync_with_stdio( false );

    init();

    for( int i = 0 ; i < 5 ; i++ ) getline( cin, BOMB[i] );

    cout << ( canBeDefused() ? "BEER!!" : "BOOM!!" ) << endl;
}

bool canBeDefused(){

    int timer = 0;
    for( int i = 0 ; i < BOMB[0].length() ; i += 4 ){
        string digit = "";
        for( int j = 0 ; j < 5 ; j++ ) digit += BOMB[j].substr(i,3);
        if( !charMap.count(digit) ) return false;
        timer = timer*10 + charMap[digit];
    }
    
    return !( timer % 6 );
    
}

/*
### ### ### ### ### ### ### ### ### ###
***   * *** *** * * *** *** *** *** ***
* *   *   *   * * * *   *     * * * * *
* *   * *** *** *** *** ***   * *** ***
* *   * *     *   *   * * *   * * *   *
***   * *** ***   * *** ***   * *** ***
*/
void init(){

    charMap["**** ** ** ****"] = 0;
    charMap["  *  *  *  *  *"] = 1;
    charMap["***  *****  ***"] = 2;
    charMap["***  ****  ****"] = 3;
    charMap["* ** ****  *  *"] = 4;
    charMap["****  ***  ****"] = 5;
    charMap["****  **** ****"] = 6;
    charMap["***  *  *  *  *"] = 7;
    charMap["**** ***** ****"] = 8;
    charMap["**** ****  ****"] = 9;

}
