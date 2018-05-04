#include <iostream>
#include <string>//needed for string use

using namespace std;

int main(){
  string input;
  int repeats;

  cout << "Enter a string: ";
  cin >> input;

  cout << "Enter a number: ";
  cin >> repeats;

  for(int i=0;i<repeats;i++)
    cout << i+1 << ": " << input << endl;
  
  return 0;
}
    
