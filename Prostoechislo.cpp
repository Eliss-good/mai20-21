#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
	double chislo,delenie,usingn;
	vector<int> sum;
	cin >> chislo;
	usingn = abs(chislo);
	for(int i = 1; i <= usingn; ++i){
        delenie = usingn / i;
        if(delenie == int(delenie)){
            if(count(sum.begin(), sum.end(), delenie) == 0){
            sum.push_back((int)delenie);
            }
        }
	}
	for(int i = 0; i < sum.size(); ++i){
	    cout << sum[i] << " ";
	}
	return 0;
}