#include <iostream>
#include <string>
#include <set>


using namespace std;


int main(){
    set<string> names;

    names.insert("Tom");
    names.insert("Mike");
    names.insert("Mike");
    names.insert("Bob");

    set<string>::iterator it;

    for(it = names.begin(); it != names.end(); it++){
        cout << *it << endl;
    }

    // find if data contains "Bob", "Steve".
    string n[] = {"Bob", "Steve"};
    int i;
    for(i=0; i<2;i++){

        it = names.find(n[i]);
        if(it==names.end()){

            cout << n[i] << " is not in a set." << endl;

        }else{

            cout << n[i] << " is in a set." << endl;

        }
        
    }

    return 0;
}
