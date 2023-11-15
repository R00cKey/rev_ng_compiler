#include "CompilerStructures.h"
using namespace std;

int main(){
	BasicBlock myblock("The first");
	BasicBlock myblock2("The second");
	map<string, BasicBlock> mymap;
	string s1("a");
	string s2("b");
	string s3("c");
	myblock2.addSuccessor(pair<string, BasicBlock>(s1,myblock));
	mymap.clear();
	mymap.insert(pair<string, BasicBlock>(s1,myblock));
	mymap.insert(pair<string, BasicBlock>(s2,myblock2));
	BasicBlock myblock3("The third", mymap);
	myblock3.addSuccessor(pair<string, BasicBlock>(s1,myblock2)); //Try to an already used tag
	myblock3.printSuccessors();
	myblock3.removeSuccessor(s1);
	myblock3.addSuccessor(pair<string, BasicBlock>(s1,myblock2)); //Now tag "a" should be associated to The second
	myblock3.printSuccessors();
}