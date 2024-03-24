#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string victory_card( int );
string treasure_card( int );

int main()
{
    ios::sync_with_stdio( false );

    int G, S, C;
    cin >> G >> S >> C;

    int BP = G*3 + S*2 + C*1;

    string victory = victory_card( BP );
    string treasure = treasure_card( BP );

    if( victory != "" ) cout << victory << " or ";
    cout << treasure << endl;
}

string treasure_card(
    int BP
) {
    if( BP >= 6 ) return "Gold";
    if( BP >= 3 ) return "Silver";
    return "Copper";
}

string victory_card(
    int BP
) {
    if( BP >= 8 ) return "Province";
    if( BP >= 5 ) return "Duchy";
    if( BP >= 2 ) return "Estate";
    return "";
}