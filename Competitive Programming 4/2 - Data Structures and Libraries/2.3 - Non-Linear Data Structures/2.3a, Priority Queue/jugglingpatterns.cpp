#include <bits/stdc++.h>
using namespace std;

void simulate(string);

const int MAX_STEPS = 1000000;

int main(){ ios::sync_with_stdio(false);

    string S;
    while( getline( cin, S ) ){
        simulate(S);
    }

}



void simulate( string P ){

    function <int()> calculateBallCount = [&]() -> int{
        int sum = 0, len = P.length();
        for( const char &c : P ) sum += c - '0';
        if( sum % len ) return -1;
        return sum / len;
    };

    function <int(int)> getThrow = [&](int t) -> int{
        t--;
        t %= int( P.size() );
        return P[t] - '0';
    };

    int BC = calculateBallCount();
    if( BC == -1 ){ cout << P << ": invalid # of balls" << endl; return; }
    int _BC = BC;

    int STEPS = MAX_STEPS;
    priority_queue < int, vector<int>, greater<int> > pq;
    for( int CS = 1 ; CS < MAX_STEPS ; CS++ ){

        int THROW = getThrow(CS);

        if( pq.empty() || CS != pq.top() ){
            if( !BC || THROW == 0 ) continue;
            pq.push(CS); BC--;
        }

        pq.pop();
        pq.push( CS + THROW );

        if( pq.top() == CS ){ cout << P << ": invalid pattern" << endl; return; } 

    }

    cout << P << ": valid with " << _BC << " balls" << endl;

}
