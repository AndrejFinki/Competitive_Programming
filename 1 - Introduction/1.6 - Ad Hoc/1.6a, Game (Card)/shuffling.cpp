#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 1e9+7
#define LD long double
#define LL long long

const int maxN = 1005;
int N; string type;
int originalDeck[maxN], deck[maxN];

bool deckIsOriginal();
void outShuffle(), inShuffle();

int main()
{
    ios::sync_with_stdio( false );

    memset( deck, -1, sizeof deck );

    cin >> N >> type;

    for( int i = 0 ; i < N ; i++ ) originalDeck[i] = deck[i] = i;

    int counter = 0;
    do{
        ( type == "out" ? outShuffle() : inShuffle() ); 
        counter++;
    }while( !deckIsOriginal() );

    cout << counter << endl;
}

void outShuffle(){

    int tempDeck[maxN];

    int L = 0, R = N, M = N / 2;
    if( N & 1 ) M++;

    int i = L, j = M, idx = 0;
    while( true ){

        if( i < M ) tempDeck[idx++] = deck[i++];
        if( j < R ) tempDeck[idx++] = deck[j++];

        if( i == M && j == R ) break;

    }

    for( int i = 0 ; i < maxN ; i++ ) deck[i] = tempDeck[i];

}

void inShuffle(){
    
    int tempDeck[maxN];

    int L = 0, R = N, M = N / 2;

    int i = L, j = M, idx = 0;
    while( true ){

        if( j < R ) tempDeck[idx++] = deck[j++];
        if( i < M ) tempDeck[idx++] = deck[i++];

        if( i == M && j == R ) break;

    }

    for( int i = 0 ; i < maxN ; i++ ) deck[i] = tempDeck[i];

}

bool deckIsOriginal(){
    for( int i = 0 ; i < N ; i++ ) if( deck[i] != originalDeck[i] ) return false;
    return true;
}
