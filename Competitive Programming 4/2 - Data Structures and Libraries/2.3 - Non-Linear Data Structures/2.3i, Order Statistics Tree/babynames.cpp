#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

#include<bits/extc++.h>
using namespace __gnu_pbds;
typedef tree<string, null_type, less<string>, rb_tree_tag, tree_order_statistics_node_update> ost;

void add_suggestion( const string &, const int & );
void remove_suggestion( const string & );
int query( const string &, const string &, const int & );

ost male, female;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int command;

    while( cin >> command && command ){

        if( command == 1 ){
            string baby_name;
            int gender;
            cin >> baby_name >> gender;
            add_suggestion( baby_name, gender );
        }

        if( command == 2 ){
            string baby_name;
            cin >> baby_name;
            remove_suggestion( baby_name );
        }

        if( command == 3 ){
            string start_str, end_str;
            int gender;
            cin >> start_str >> end_str >> gender;
            cout << query( start_str, end_str, gender ) << endl;
        }
        
    }

}

void add_suggestion( const string &name, const int &gender ){

    ost &tree = ( gender == 1 ? male : female );
    tree.insert( name );

}

void remove_suggestion( const string &name ){

    ost &tree = ( male.find(name) == male.end() ? female : male );
    tree.erase( name );

}

int query( const string &L, const string &R, const int &gender ){

    function <int(const ost &)> query = [&]( const ost &tree ) -> int {
        return tree.order_of_key(R) - tree.order_of_key(L);
    };

    return ( gender != 2 ? query( male ) : 0 ) + ( gender != 1 ? query( female ) : 0 );

}
