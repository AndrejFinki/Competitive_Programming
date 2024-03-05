#include <bits/stdc++.h>
using namespace std;

void sell(int, int);
void buy(int, int);
void doExchange();
string ask();
string bid();
string stock();

priority_queue <int> qbid;
priority_queue <int, vector<int>, greater<int>> qask;
int lastDeal = -1;

int main(){ ios::sync_with_stdio(false);

    int t; cin >> t;
    while( t-- ){

        lastDeal = -1;
        while( !qbid.empty() ) qbid.pop();
        while( !qask.empty() ) qask.pop();

        string orders, _dummy; int N, x, y; cin >> N;
        for( int i = 0 ; i < N ; i++ ){
            cin >> orders >> x >> _dummy >> _dummy >> y;
            ( orders == "sell" ? sell(x,y) : buy(x,y) );
            doExchange();
            cout << ask() << ' ' << bid() << ' ' << stock() << endl;
        }
            
    }

}



void sell( int n, int p ){
    while( n-- ) qask.push(p);
}

void buy( int n, int p ){
    while( n-- ) qbid.push(p);
}

void doExchange(){
    while( !qask.empty() && !qbid.empty() && qask.top() <= qbid.top() ){
        lastDeal = qask.top();
        qask.pop();
        qbid.pop();
    }
}

string ask(){
    return ( qask.empty() ? "-" : to_string( qask.top() ) );
}

string bid(){
    return ( qbid.empty() ? "-" : to_string( qbid.top() ) );
}

string stock(){
    return ( lastDeal == -1 ? "-" : to_string( lastDeal ) );
}
