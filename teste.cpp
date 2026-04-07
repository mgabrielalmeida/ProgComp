#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> abacaxi;
    abacaxi.push_back(19);
    abacaxi.push_back(83);
    abacaxi.pop_back();
    cout << abacaxi[0];
}