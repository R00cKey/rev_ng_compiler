#include "CompilerStructures.h"
#include <iostream>

////////////BasicBlock////////////
//Constructors
BasicBlock::BasicBlock(){}
BasicBlock::BasicBlock(string name){
	name_= name;
}
BasicBlock::BasicBlock(string name, map<string, BasicBlock> successors){
	name_= name;
	successors_=successors;
}
//Destructor
BasicBlock::~BasicBlock(){}
//Getter
string BasicBlock::getName(){
	return name_;
}
BasicBlock BasicBlock::getSuccessor(string tag){
	return successors_[tag];
}
//Setter
void BasicBlock::setName(string newname){
	name_=newname;
}
//Print the list of tags and successors' name
void BasicBlock::printSuccessors(){
	cout << "\"" << this->getName() << "\" has the following successors:" << endl;
	if(!successors_.empty()){
		for(map<string, BasicBlock>::iterator it=successors_.begin(); it!= successors_.end(); it++){
			cout << "Tag: \"" << it->first << "\" \t Successor's Name: \"" << (it->second).getName() << "\"" << endl;
		}
	}
	else{cout << "No successors" << endl;}
}
//Successors Management
void BasicBlock::addSuccessor(pair<string, BasicBlock> newsuccessors){
	map<string, BasicBlock>::iterator it=successors_.find(get<0>(newsuccessors));
	if(it->first==get<0>(newsuccessors)){
		cout << "The tag \"" << get<0>(newsuccessors) << "\" has already been used for basic block \"" << (it->second).getName() << "\". Please remove via \"BasicBlock::removeSuccessor\" and then add the new successor" << endl;
	}
	else{
		successors_.insert(newsuccessors);
	}
}
void BasicBlock::removeSuccessor(string tag){
	map<string, BasicBlock>::iterator it=successors_.find(tag);
	if(it->first!=tag){
		cout << "The tag \"" << tag << "\" does not exist for any of basic block \"" << this->getName() << "\" successors." << endl;
	}
	else{
		successors_.erase(it);
	}
}
vector<BasicBlock> BasicBlock::getAllSuccessors(){
	vector<BasicBlock> taglist;
	for(map<string, BasicBlock>::iterator it=successors_.begin(); it!= successors_.end(); it++){
			taglist.push_back(it->second);
		}
	return taglist;
}




////////////Function////////////
//Constructors
Function::Function(){};
Function::Function(string name, BasicBlock entry){ //Since a Function must have a name and include an entry block, I implemented only constructors which contain both these fundamental parameters
	name_ = name;
	entryblock_=entry;
}
Function::Function(string name, BasicBlock entry, BasicBlock block){ //In case of a single other basic block, it is added to the vector
	name_ = name;
	entryblock_=entry;
	blocks_.push_back(block);
}
Function::Function(string name, BasicBlock entry, vector<BasicBlock> vectorofblocks){
	name_ = name;
	entryblock_=entry;
	blocks_= vectorofblocks;
}
//Destructors
Function::~Function(){}
//Getter
string Function::getName(){
	return name_;
}
BasicBlock Function::getEntryBlock(){
	return entryblock_;
}
BasicBlock Function::getIndexedBlock(int pos){
	return blocks_[pos];
}
vector<BasicBlock> Function::getAllblocks(){
	return blocks_;
}
//Setter
void Function::setName(string newname){
	name_=newname;
}
void Function::setEntryBlock(BasicBlock newentry){
	entryblock_=newentry;
}
void Function::setIndexedBlock(BasicBlock newblock, int pos){
	blocks_[pos]=newblock;
}
//Blocks Management
void Function::addBlockAtIndex(BasicBlock newblock, int pos){
	blocks_.insert(blocks_.begin()+pos, newblock);
}
void Function::removeBlockAtIndex(int pos){
	blocks_.erase(blocks_.begin()+pos);
}
void Function::purgeAllBlocks(){
	blocks_.clear();
}

////////////Module////////////
//Constructors
Module::Module(){}
Module::Module(string name){
	name_=name;
}
Module::Module(string name, vector<Function> vectoroffunctions){
	name_=name;
	functions_= vectoroffunctions;
}
//Destructor
Module::~Module(){}
//Getter
string Module::getName(){
	return name_;
}
Function Module::getIndexedFunction(int pos){
	return functions_[pos];
}
vector<Function> Module::getAllFunctions(){
	return functions_;
}
//Setters
void Module::setName(string newname){
	name_=newname;
}
void Module::setIndexedFunction(Function newfunction, int pos){
	functions_[pos]=newfunction;
};
//Functions Management
void Module::addFunctionAtIndex(Function newblock, int pos){
	functions_.insert(functions_.begin()+pos, newblock);
}
void Module::removeFunctionAtIndex(int pos){
	functions_.erase(functions_.begin()+pos);
};
void Module::purgeAllFunctions(){
	functions_.clear();
}

