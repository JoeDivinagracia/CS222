#include <iostream>

using namespace std;

string getName(int value);
string getTens(int value);
string getTeens(int value);
string getHundreds(int value);

int main(){
  int number;
  cout << "Enter a number: (0-999) ";
  cin >> number;
  string numberInWords="";

  if(number == 0)
    numberInWords+="zero";
  if(number/100 != 0){
    numberInWords+=getHundreds(number/100);
    numberInWords+=" ";
  }
  if(number%100 != 0){
    int teens = number%100;
    if(teens > 10 && teens < 20)
      numberInWords += getTeens(teens);
    else
      numberInWords += getTens(number%100 - number%10);
    
    numberInWords+=" ";
  }
  if(number%100 < 10 || number%100 > 20){
    numberInWords += getName(number%10);
    numberInWords+=" ";
  }
  cout << "Your number in other words: " <<  numberInWords << endl;
  
  return 0;
}

string getName(int value){
  switch(value){
  case 1: return "one";
  case 2: return "two";
  case 3: return "three";
  case 4: return "four";
  case 5: return "five";
  case 6: return "six";
  case 7: return "seven";
  case 8: return "eight";
  case 9: return "nine";
  }
  return "";
}

string getTens(int value){
 switch(value){
  case 10: return "one";
  case 20: return "twenty";
  case 30: return "thirty";
  case 40: return "fourty";
  case 50: return "fifty";
  case 60: return "sixty";
  case 70: return "seventy";
  case 80: return "eighty";
  case 90: return "ninety";
  }
  return "";
}

string getTeens(int value){
  switch(value){
  case 11: return "eleven";
  case 12: return "twelve";
  case 13: return "thirteen";
  case 14: return "fourteen";
  case 15: return "fifteen";
  case 16: return "sixteen";
  case 17: return "seventeen";
  case 18: return "eighteen";
  case 19: return "nineteen";
  }
  return "";
}

string getHundreds(int value){
  switch(value){
  case 1: return "one hundred";
  case 2: return "two hundred";
  case 3: return "three hundre";
  case 4: return "four hundred";
  case 5: return "five hundred";
  case 6: return "six hundred";
  case 7: return "seven hundred";
  case 8: return "eight hundred";
  case 9: return "nine hundred";
  }
  return "";
}
