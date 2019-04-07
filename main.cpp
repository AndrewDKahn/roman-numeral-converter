#include <iostream>
#include <map>
#include <string>
#include <algorithm>


using namespace std;

string formatNumeral(string numeral){
    string newNumeral = "";
    for (int i = 0; i < numeral.length(); i++){
        if (numeral[i] != ' '){
            newNumeral += toupper(numeral[i]);
        }
    }
    return newNumeral;
}
bool noInvalidChar(string numeral){
    bool notInvalid = true;
    bool validChar;
    char validChars[] = {'M','D','C','L','X','V','I'};
    for (int i = 0; i < numeral.length(); i++){
        validChar = false;
        for (int j = 0; j < sizeof(validChars); j++){
            if(numeral[i] == validChars[j]){
                validChar = true;
            }
        }
        if (!validChar){
            notInvalid = false;
            break;
        }
    }
    return notInvalid;
}
string intToNumeral(int num){
    string numeral = "";
    //cout << "This will convert int to numeral." << endl;
    while(num >= 1000){
        numeral += "M";
        num -= 1000;
    }
    if(num >= 900){
        numeral += "CM";
        num -= 900;
    }
    if(num >= 500){
        numeral += "D";
        num -= 500;
    }
    if(num >= 400){
        numeral += "CD";
        num -= 400;
    }
    while(num >= 100){
        numeral += "C";
        num -= 100;
    }
    if(num >= 90){
        numeral += "XC";
        num -= 90;
    }
    if(num >= 50){
        numeral += "L";
        num -= 50;
    }
    if(num >= 40){
        numeral += "XL";
        num -= 40;
    }
    while(num >= 10){
        numeral += "X";
        num -= 10;
    }
    if(num >= 9){
        numeral += "IX";
        num -= 9;
    }
    if(num >= 5){
        numeral += "V";
        num -= 5;
    }
    if(num >= 4){
        numeral += "IV";
        num -= 4;
    }
    while(num >= 1){
        numeral += "I";
        num -= 1;
    }
    return numeral;
}

int numeralToInt(string numeral){
    //cout << "This will convert numeral to int." << endl;
    numeral = formatNumeral(numeral);
    if (!noInvalidChar(numeral)){
        throw "Invalid Numeral";
    }
    //cout << numeral<< endl;
    int num = 0;
    map <char, int> dict;

    dict.insert(pair<char, int> ('M', 1000));
    dict.insert(pair<char, int> ('D', 500));
    dict.insert(pair<char, int> ('C', 100));
    dict.insert(pair<char, int> ('L', 50));
    dict.insert(pair<char, int> ('X', 10));
    dict.insert(pair<char, int> ('V', 5));
    dict.insert(pair<char, int> ('I', 1));

    for(int i = 0; i < numeral.length(); i++){
        num += dict[numeral[i]];
        if (i != 0 && dict[numeral[i-1]] < dict[numeral[i]] ){
            num -= 2*dict[numeral[i-1]];
        }
    }

    return num;
}


void numeralConverter(){
    cout << "Welcome to RomanNumeralConverter!" << endl;
    bool notDone = true;
    int input;
    string numeral;
    int num;
    while (notDone){
        cout << "1 to convert int to numeral" << endl;
        cout << "2 to convert numeral to int" << endl;
        cout << "0 to quit" << endl;
        cin >> input;
        if (input == 1){
            cout << "Enter a number: ";
            cin >> num;
            numeral = intToNumeral(num);
            cout << numeral << endl;
        }
        else if (input == 2){
            cout << "Enter a numeral: ";
            cin >> numeral;
            num = numeralToInt(numeral);
            cout << num << endl;
        }
        else{
            notDone = false;
        }
    }
}

int main() {
    numeralConverter();
    return 0;
}

