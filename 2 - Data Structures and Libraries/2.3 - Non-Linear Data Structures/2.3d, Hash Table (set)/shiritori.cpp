#include<bits/stdc++.h>
using namespace std;

void setup();
string play_game();

const int maxN = 100005;
int N;
set <string> word_bank;
char last_char;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    setup();

    cout << play_game() << endl;

}

string play_game(){

    string S; int player = 1;

    function <string()> lose = [&]() -> string{ return "Player " + to_string(player+1) + " lost"; };

    while( cin >> S ){
        if( S[0] != last_char || word_bank.count(S) ) return lose();
        word_bank.insert(S);
        last_char = S[S.length()-1];
        player = 1 - player;
    }

    return "Fair Game";

}

void setup(){

    cin >> N;

    string S; cin >> S; 
    word_bank.insert(S); last_char = S[S.length()-1];

}
