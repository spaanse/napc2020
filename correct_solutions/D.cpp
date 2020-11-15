#include <iostream>

using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
	if(s[s.length()-1]=='?')
	    cout << "Quack!" << endl;
	else if(s == "I quacked the code!")
	    break;
	else
	    cout << "*Nod*" << endl;
    }
    return 0;
}
