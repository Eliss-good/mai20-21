#include <iostream>
#include <vector>

using namespace std;

int main(){
	int number,sistem;
	cin >> number >> sistem;
	vector<char> newchislo;
	char p;
	int ostatok;

    for(int i = 0; number >= 1; ++i){
        ostatok = number % sistem;
        if((ostatok >= 0) && (ostatok <= 9)){
        	p = '0' + ostatok;
        	newchislo.push_back(p);
        } else if(ostatok >= 10){
        	p = 'A' + ostatok - 10;
        	newchislo.push_back(p);
        }
        number /= sistem;
    }
    for(int i = 0; i < newchislo.size(); ++i){
    	cout << newchislo[i];
    }
    return 0;
}
