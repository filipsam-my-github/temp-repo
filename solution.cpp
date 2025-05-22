#include <iostream>
#include <string>
#include <vector>

using namespace std;





float Abs(float number){
  if (number >= 0){
    return number;
  }
  else if (number < 0){
    return -number;
  }
}



float Pow(float f_num, float f_power) {
  int result = 1;

  int num = static_cast<int>(f_num);
  int power = static_cast<int>(f_num);

  while (power > 0) {
    if (power % 2 == 1) {
      result *= num;
    }
    power /= 2;
    num *= num;
  }

  return static_cast<int>(result);
}

float Floor(float number){
  return static_cast<float>((static_cast<int>(number)));
}





void PrintResults(vector<float> numbers_from_equsion, string type_of_operation, bool absolut_val){
  float result = 0;

  if (type_of_operation == "+"){
    result = numbers_from_equsion[0] + numbers_from_equsion[1];
  }
  else if (type_of_operation == "-"){
    result = numbers_from_equsion[0] - numbers_from_equsion[1];
  }
  else if (type_of_operation == "*"){
    result = numbers_from_equsion[0] * numbers_from_equsion[1];
  }
  else if (type_of_operation == "/"){
    result = numbers_from_equsion[0] / numbers_from_equsion[1];
  }
  else if (type_of_operation == "^"){
    result = Pow(numbers_from_equsion[0], numbers_from_equsion[1]);
  }
  else if (type_of_operation == "srednia"){
    result = (numbers_from_equsion[0] + numbers_from_equsion[1])/2;
  }
  else if (type_of_operation == "ogleglosc"){
    result = Abs(numbers_from_equsion[0] - numbers_from_equsion[1]);
  }


  if (absolut_val){
    cout << "wynik " << Abs(result) << endl;
  }
  cout << "wynik " << result << endl;
}

int main(){
  //komendy uzytkownika zaiwerajace cala 
  string operation;
  string in_absolute;


  float num1 = 0;
  float num2 = 0;

  vector<float> numbers = {0.,0.};

  bool absolut = false;
  
  while (true)
  {
  cout << "Podaj dwie liczby\n";
  cin >> num1 >> num2;


  vector<float> numbers = {num1,num2};

  cout << "Podaj operacje (q wyjscia)\n";
  cin >> operation;
  cin.clear();


  if (operation == "q" || operation == "Q"){
    break;
    return 0;
  }

  cout << "czy ma byc wartosc bezwzgledna (1-tak 0-nie)" << endl;
  cin >> in_absolute;
  absolut = false;
  if (in_absolute == "1"){
    absolut = true;
  }
  cin.clear();
  PrintResults(numbers, operation, absolut);

   

  }

  return 0;


}

