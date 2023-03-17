#include<iostream>
#include<vector>
using namespace std;



void moveDiscs(int num, char fromPeg, char toPeg, char tempPeg, vector<int>& a, vector<int>& b, vector<int>& c);
void manageArray(vector<int>& a, vector<int>& b, vector<int>& c, char fromPeg, char toPeg, int num);
void arrayPrinter(vector<int>& a, vector<int>& b, vector<int>& c);

int main(){
    vector<int> a;
    vector<int> b;
    vector<int> c;
    int n;
    cout << "number of discs: ";
    cin >> n;
    for(int i = n; i > 0; i--){
        a.push_back(i);
    }
    arrayPrinter(a, b, c);
    moveDiscs(n, 'A', 'B', 'C', a, b, c);
    return 0;
}

void moveDiscs(int num, char fromPeg, char toPeg, char tempPeg, vector<int>& a, vector<int>& b, vector<int>& c){
    if(num > 0){
        moveDiscs(num-1, fromPeg, tempPeg, toPeg, a, b, c);
        cout << "move " << num << " from peg " << fromPeg << " to peg " << toPeg << endl;
        manageArray(a,b,c,fromPeg,toPeg,num);
        arrayPrinter(a,b,c);
        moveDiscs(num-1, tempPeg, toPeg, fromPeg, a, b, c);
    }
}

void manageArray(vector<int>& a, vector<int>& b, vector<int>& c, char fromPeg, char toPeg, int num){
    if(fromPeg == 'A'){
        a.pop_back();
    }
    else if(fromPeg == 'B'){
        b.pop_back();
    }
    else{
        c.pop_back();
    }
    if(toPeg == 'A'){
        a.push_back(num);
    }
    else if(toPeg == 'B'){
        b.push_back(num);
    }
    else{
        c.push_back(num);
    }
}

void arrayPrinter(vector<int>& a, vector<int>& b, vector<int>& c){
    cout << "A : {";
    if(a.size() != 0){
        for(int i=0; i < a.size(); i++){
            cout << a[i];
            if(i != a.size()-1){
                cout <<", ";
            }
        }
    }
    cout << "}" << endl;
    
    cout << "B : {";
    if(b.size() != 0){
        for(int i=0; i < b.size(); i++){
            cout << b[i];
            if(i != b.size()-1){
                cout <<", ";
            }
        }
    }
    cout << "}" << endl;
    
    cout << "C : {";
    if(c.size() != 0){
        for(int i=0; i < c.size(); i++){
            cout << c[i];
            if(i != c.size()-1){
                cout <<", ";
            }
        }
    }
    cout << "}" << endl;
}



