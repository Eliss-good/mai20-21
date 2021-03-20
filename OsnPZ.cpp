#include <iostream>

int desit = 0;

void Demical(char a, const int sistem1){
    desit *= sistem1;
    if(a >= '0' && a <= '9'){
        desit += (int)(a) - '0';
    } else if(a >= 'A'){
        desit += (int)(a) - 'A' + 10;
    } 
    
}

void Perevod(const int sistem2){
    int max = 1;
    char p;
    int k;
    while(max <= desit){
      max *= sistem2;
    }
    max /= sistem2;

    while (max > 0)
    {  
        int m1 = desit / max;
        desit = desit - m1*max;
        k=m1;
        if((k <= 9)){
            p = '0' + k;
        } else {
            p = 'A' + k - 10;
        }
        std::cout << p;
        //desit -= max;
        max /= sistem2;
    }
} 

int main(){
  int sistem1,sistem2;
  char chislo;
  std::cin >> sistem1;
  int i;
  for(i = 0; i < 2147483647; ++i){
    std::cin >> chislo;
    if(chislo == ';'){
      break;
    } else {
      Demical(chislo,sistem1);
    }
  }
  std :: cin >> sistem2;
  Perevod(sistem2);
}
