#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

#include<bits/extc++.h>
using namespace __gnu_pbds;
typedef tree< pair<int, int> , null_type, less< pair<int, int> >, rb_tree_tag, tree_order_statistics_node_update> ost;

void get_cookie();
void add_cookie( int );

ost cookie_list;
int next_cookie_idx = 1;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string cookie;

    while( getline( cin, cookie ) ){

        if( cookie == "#" ) get_cookie();
        else                add_cookie( stoi( cookie ) );

    }

}

void get_cookie(){
    cout << cookie_list.find_by_order( cookie_list.size()/2 )->first << endl;
    cookie_list.erase( cookie_list.find_by_order( cookie_list.size()/2 ) );
}

void add_cookie( int d ){
    cookie_list.insert( make_pair( d, next_cookie_idx++ ) );
}
