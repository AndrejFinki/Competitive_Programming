#include<bits/stdc++.h>
using namespace std;
#define INF (1<<30)

struct Instruction{
    string line;
    int label;
    string type;
    Instruction(){}
    Instruction( string _line, int _label, string _type ) : line(_line), label(_label), type(_type) {}
    const bool operator < ( const Instruction &o ) const{
        return label < o.label;
    }
};

void get_input();
void run_basic();
void run_instruction( const Instruction & );

map <string, int> definition;
vector <Instruction> i_list;
int i_idx = 0;
bool condition_is_true = false;

int main(){ ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    get_input();
    run_basic();
}

void run_instruction( const Instruction &I ){ // FINISH UP IF AND PRINT COMMANDS, NEXT THING TO DO IS THE CONDITION CHECK

    function <int(string)> evaluate_var = [&]( string S ) -> int{
        return ( definition.count(S) ? definition[S] : stoi(S) );
    };

    function <bool(string, string, string)> evaluate_condition = [&]( string v1, string cmp, string v2 ) -> bool{
        int val1 = evaluate_var(v1), val2 = evaluate_var(v2);
        if( cmp == "=" ) return val1 == val2;
        if( cmp == ">" ) return val1 > val2;
        if( cmp == "<" ) return val1 < val2;
        if( cmp == "<>" ) return val1 != val2;
        if( cmp == "<=" ) return val1 <= val2;
        if( cmp == ">=" ) return val1 >= val2;
        return true;
    };

    function <int(int)> find_instruction_with_label = [&]( int L ) -> int{
        int idx = -1;
        for( const Instruction &I : i_list ){ idx++;
            if( I.label == L ) return idx;
        } return -1;
    };

    function <int(string)> evaluate_arithmetic = [&]( string S ) -> int{
        stringstream SS(S);
        string v1 = "", op = "", v2 = "";
        SS >> v1 >> op >> v2;
        if( op == "" ) return evaluate_var(v1);
        int val1 = evaluate_var(v1), val2 = evaluate_var(v2);
        if( op == "+" ) return val1 + val2;
        if( op == "-" ) return val1 - val2;
        if( op == "*" ) return val1 * val2;
        if( op == "/" ) return val1 / val2;
        return -1;
    };

    function <void()> run_let = [&]() -> void{
        stringstream SS(I.line);
        string S;
        SS >> S >> S >> S;
        string VAR = S;
        SS >> S; getline( SS, S );
        int VAL = evaluate_arithmetic(S);
        definition[VAR] = VAL;
    };

    function <void()> run_if = [&]() -> void{
        stringstream SS(I.line);
        string S;
        SS >> S >> S;
        string v1, cmp, v2;
        SS >> v1 >> cmp >> v2;
        SS >> S >> S;
        int L;
        SS >> L;
        if( evaluate_condition( v1, cmp, v2 ) ){ condition_is_true = true; i_idx = find_instruction_with_label(L); }
    };

    function <void(string)> run_print = [&]( string append = "" ) -> void{
        stringstream SS(I.line);
        string S;
        SS >> S >> S;
        getline( SS, S );
        S = S.substr(1, INF);
        if( S[0] == '\"' ) cout << S.substr(1, S.length()-2) << append;
        else cout << evaluate_var(S) << append;
    };

    if( I.type == "LET" )     run_let();
    if( I.type == "IF" )      run_if();
    if( I.type == "PRINT" )   run_print("");
    if( I.type == "PRINTLN" ) run_print("\n");

}

void run_basic(){

    while( i_idx < i_list.size() ){
        condition_is_true = false;
        run_instruction( i_list[i_idx] );
        if( !condition_is_true ) i_idx++;
    }

}

void get_input(){

    string line;
    while( getline( cin, line ) ){

        stringstream SS(line);
        Instruction I;

        I.line = line;
        SS >> I.label;
        SS >> I.type;

        i_list.push_back(I);

    }

    sort( i_list.begin(), i_list.end() );

}
