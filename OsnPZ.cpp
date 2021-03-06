#include <iostream>
#include <string>

using namespace std;

int Demical(const int& sistem, const string& chislo){
    int desin = 0;
    int razrad = 1;
    int m;
    
	for(int i = 0; i < chislo.size(); ++i){
		if(chislo[i] >= '0' && chislo[i] <= '9'){
			m = (int)(chislo[i]) - '0';
		} else if(chislo[i] >= 'A'){
	    	m = (int)(chislo[i]) - 'A' + 10;
	    }
	    for(int j = chislo.size() - i - 1; j > 0; --j){
	    	razrad *= sistem;
	    }
        m *= razrad;
        desin += m;
        razrad = 1;
    }
    return desin;
}

string Perevod(int& chislo, const int& sistem){
    string newchislo;
	char p;
	int ostatok;

    for(int i = 0; chislo >= 1; ++i){
        ostatok = chislo % sistem;
        if((ostatok >= 0) && (ostatok <= 9)){
        	p = '0' + ostatok;
        	newchislo += p;
        } else if(ostatok >= 10){
        	p = 'A' + ostatok - 10;
        	newchislo +=p;
        }
        chislo /= sistem;
    }
    return newchislo;
}


int main(){
	int sistem1,sistem2;
	string chislo;
	cin >> sistem1 >> chislo >> sistem2;
    int desit = Demical(sistem1,chislo);
    string result = Perevod(desit,sistem2);
    cout << '\n';
    for(int i = result.size() - 1; i >= 0; --i){
    	cout << result[i];
    }
    return 0;
} 
    