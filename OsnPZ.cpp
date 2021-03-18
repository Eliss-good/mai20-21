#include <iostream>

using namespace std;
//Десятичное число из ф-ии Demical мы преобразуем в нужную систему счисления (которая была введена пользователем)
void Perevod(int chislo,const int size){
  char p;
  int ostatok,sistem,n;
  cin >> sistem; 
  char* array = new char[n+1];
  for(n = 0; chislo >= 1; ++n){
    ostatok = chislo % sistem;
    if((ostatok >= 0) && (ostatok <= 9)){
      p = '0' + ostatok;
    } else if(ostatok > 9){
      p = 'A' + ostatok - 10;
    }
    chislo /= sistem;
    array[n] = p;
    }

  while(n >= 0){
    cout << array[n];
    --n;
  }
} 
// Переводим в введеное число пользователя в дестичную систему
int Demical(char arrayN[], const int size, const int sistem){
    int desin = 0;
    int razrad = 1;
    int m;
    
  for(int n = 0; n < size; ++n){
    if(arrayN[n] >= '0' && arrayN[n] <= '9'){
      m = (int)(arrayN[n]) - '0';
    } else if(arrayN[n] >= 'A'){
        m = (int)(arrayN[n]) - 'A' + 10;
      }
      for(int j = size - n - 1; j > 0; --j){
        razrad *= sistem;
      }
        m *= razrad;
        desin += m;
        razrad = 1;
    }
    delete [] arrayN;
    Perevod(desin,size);
}

int main(){
  setlocale(LC_ALL, "Russian");
  cout << "Инструкция : сначала вводите систему счисления вводимого числа, далее само число, которое будет переводится";
  cout << "(на конце числа пишете 'S') ,далее вводите ту систему счислени, в которую хотите перевести ваше число." ;
  cout << " Пример : 16 2FFS 8" << '\n';
  int sistem1,i;
  char chislo;
  cin >> sistem1;
  char* array = new char[i+1];
  for(i = 0; i < 2147483647; ++i){
    cin >> chislo;
    if(chislo == 'S'){
      break;
    } else {
      array[i] = chislo;
    }
  }
  Demical(array,i,sistem1);
  return 0;
}