#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define LL unsigned long long

#include<bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<pair<LL,LL>, null_type, less<pair<LL,LL>>, rb_tree_tag, tree_order_statistics_node_update> ost;

LL get_median( LL );

ost ost_array;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    LL t; cin >> t;
    while( t-- ){

        ost_array.clear();

        LL N; cin >> N;

        LL rv = 0, V;
        for( LL i = 0 ; i < N ; i++ ){
            cin >> V;
            ost_array.insert( make_pair( V, i ) );
            rv += get_median( i+1 );
        }

        cout << rv << endl;

    }

}

LL get_median( LL M ){
    if( M & 1 ) return ost_array.find_by_order(M/2)->first;
    return ( ost_array.find_by_order((M-1)/2)->first + ost_array.find_by_order(M/2)->first ) / 2LL;
}
