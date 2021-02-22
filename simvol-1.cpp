#include <iostream>

using namespace std;

int main(){
	int Q;
	int sum = 0;
	char p;
	cin >> Q;
	for(int i = 0; i < Q; ++i){
        cin >> p;
        sum += (int)(p) - 48;

    }
    cout << sum; 
	return 0;
}