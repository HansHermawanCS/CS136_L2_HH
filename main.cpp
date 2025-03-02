#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <algorithm>

using namespace std;

void addQuotientSeries(int n, int currentIndex, double product);
void addProductSeries(int n, int product);
int askUserForAmount();
void exitProgram();
void printMenuChoices();
void invalidSwitchInput();
void switchStatement(int numOfTerms);
bool validateAmountInput(string input);
int validateSwitchInput(string input);

int main(){
  int userInput = askUserForAmount();

  printMenuChoices();

  switchStatement(userInput);
}

void switchStatement(int numOfTerms){
  int userInput;

  do{
    string stringUserInput;
    getline(cin, stringUserInput);
    userInput = validateSwitchInput(stringUserInput);

    cout << "\n";

    switch(userInput){
      case (1):
        addQuotientSeries(numOfTerms, 1, 0);
        printMenuChoices();
        break;

      case (2):
        addProductSeries(numOfTerms, 0);
        printMenuChoices();
        break;

      case (3):
        exitProgram();
        break;

      default:
        invalidSwitchInput();
        break;
    }
  } while (userInput != 3);
}

void invalidSwitchInput(){
  cout << "- Invalid input, please try again. - \n";
 
  printMenuChoices();
}

int askUserForAmount(){
  string stringUserInput;
  
  cout << "\nPlease Enter Number of Terms: ";
  getline(cin, stringUserInput);

  if(!validateAmountInput(stringUserInput)){
    cout << "- Invalid input, please try again. - \n";
    return askUserForAmount();
  } else{
    return stoi(stringUserInput);
  };
}

bool validateAmountInput(string input){
  const bool isDigits = all_of(input.begin(), input.end(), ::isdigit);
  
  return isDigits;
}

int validateSwitchInput(string input){
  if(input.length() != 1){
    // returns 4 in order to result in default in switch statement
    return 4; 
  } else{
    return stoi(input);
  }
}

void addQuotientSeries(int n, int currentIndex, double product){
  if(currentIndex == n + 1){
    cout << "= " + to_string(product) + "\n";

  } else{
    const int subtractedIndex = currentIndex - 1;
    double newProduct = (1.0 / ((subtractedIndex) + currentIndex)) + product;

    if(currentIndex != 1){
      cout << "1/(" + to_string(subtractedIndex) + "+" + to_string(currentIndex) + ") ";
    } else{
      cout << to_string(currentIndex) + " + ";
    }

    if(currentIndex != 1 && currentIndex != n) cout << "+ ";

    return addQuotientSeries(n, currentIndex + 1, newProduct);
  }
}

void addProductSeries(int n, int product){
  if(n == 0){
    cout << "= " + to_string(product) + "\n";

  } else{
    int newProduct = (n * n) + product;

    if(n != 1){
      cout << "(" + to_string(n) + "*" + to_string(n) + ") + ";
    } else{
      cout << to_string(n) + " ";
    }

    return addProductSeries(n - 1, newProduct);
  }
}

void exitProgram(){
  cout << "Exiting Program";
}

void printMenuChoices(){
  cout << setfill('-') << setw(100) << " " << "\n Here are your choices (input the number for the corresponding action): \n 1. Call a recursive function to add the first n terms of the series \n 2. Call a recursive function, that produces the sum of the first n terms of the series \n 3. Quit program"
       << endl;
}
