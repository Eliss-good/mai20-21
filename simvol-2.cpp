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
    	if(((int)simvol >= 48) && ((int)simvol <= 57)){
    		sum += (int)simvol - 48;
    	}
    }
    cout << "Cумма чисел : " << sum << endl;
    return 0;
}