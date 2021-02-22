#include <iostream>

using namespace std;

int main(){
    int sum = 0;
    int q;
    cout << "Ведите кол-во символов" << endl;
    cin >> q;
    char simvol;
    for(int i = 0; i < q; ++i){
    	cin >> simvol;
    	if((simvol >= '0') && (simvol <= '9')){
    		sum += (int)simvol - 48;
    	}
    	
    }
    cout << "Cумма чисел : " << sum << endl;
    return 0;
}