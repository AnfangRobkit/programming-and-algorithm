#include <iostream>
#include <string>
#include <set>
using namespace std;
#pragma warning(disable: 4996)

bool stop = false;

void printItem(int hierachy, string item) {
	for (int i = 0; i < hierachy; i++) {

		cout << "|        ";
	}
	cout << item << endl;
}

void presentFile(int hierachy, string curDir) {

    set<string> Files;
    printItem(hierachy, curDir);
    string item;
    while (cin>>item)
    {
        if(item == "]" || item == "*") {
            set<string>::iterator i;
            for(i=Files.begin(); i != Files.end(); i++) {
                printItem(hierachy, *i);
            }
            return;
        }
        if(item[0] == 'f')
            Files.insert(item);
        else if( item[0] == 'd')
            presentFile(hierachy + 1, item);
    }
}
int main() {
    int i =1;
    while(!stop) {
        cout<<"DATA SET "<< i << endl;
        presentFile(0, "ROOT");
        cout<<endl;
        i++;
        char a = cin.get();
        char b = cin.peek();
    }

}