#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

void solve();

const int maxN = 200005;
int N;
int degree[maxN] = {};
priority_queue < int, vector<int>, greater<int> > pq;
queue <int> result, iq;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    int x;
    for( int i = 0 ; i < N ; i++ ){
        cin >> x;
        degree[x]++;
        iq.push(x);
    }

    for( int i = 1 ; i <= N ; i++ ){
        if( !degree[i] ) pq.push(i);
    }

    solve();

}

void solve(){

    while( !pq.empty() ){

        int V = pq.top();
        pq.pop();

        if( V == N+1 ) break;

        result.push(V);

        int adj = iq.front();
        iq.pop();

        degree[adj]--;
        if( !degree[adj] ) pq.push( adj );

    }

    if( !iq.empty() ){
        cout << "Error" << endl; return;
    }

    while( !result.empty() ){
        cout << result.front() << endl;
        result.pop();
    }

}
