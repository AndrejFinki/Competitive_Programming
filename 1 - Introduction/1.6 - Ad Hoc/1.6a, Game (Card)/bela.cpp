#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

struct Card{
    string card;
    char suit, rank;
    Card(){}
    Card( char _r, char _s ) : rank(_r), suit(_s) { card += rank; card += suit; }
    Card( string _c ) : card(_c) { rank = card[0]; suit = card[1]; }
};

int N; char dominantSuit;
int value[128][2] = {};

void setValue();


int main()
{
    ios::sync_with_stdio( false );

    setValue();

    cin >> N >> dominantSuit; N *= 4;

    int score = 0;
    for( int i = 0 ; i < N ; i++ ){
        string _card; cin >> _card;
        Card card(_card);
        score += value[card.rank][bool( card.suit == dominantSuit )];
    }

    cout << score << endl;
}

void setValue(){

    value['A'][0] = 11;
    value['K'][0] = 4;
    value['Q'][0] = 3;
    value['J'][0] = 2;
    value['T'][0] = 10;
    value['9'][0] = 0;
    value['8'][0] = 0;
    value['7'][0] = 0;

    value['A'][1] = 11;
    value['K'][1] = 4;
    value['Q'][1] = 3;
    value['J'][1] = 20;
    value['T'][1] = 10;
    value['9'][1] = 14;
    value['8'][1] = 0;
    value['7'][1] = 0;

}
