#include <iostream>
#include <string>

using namespace std;

int main(){
    int chislo,i;
    cin >> chislo;
    char p;
    string array;
    for(i = 0; chislo >= 1; ++i){
        p = (chislo & 3) + '0';
        array[i] += p;
        chislo >>= 2;
    }
    
    for(int k = i; k >= 0; --k){
        cout << array[k];
    }
    return 0;
}