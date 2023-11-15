#include <string>
#include <vector>
#include <map>
using namespace std;

class BasicBlock{

	public:
		//Constructors
		BasicBlock();
		BasicBlock(string name);
		BasicBlock(string name, map<string, BasicBlock> successors);
		//Destructor
		~BasicBlock();
		//Getter
		string getName();
		BasicBlock getSuccessor(string tag);
		vector<BasicBlock> getAllSuccessors();
		//Setter
		void setName(string newname);
		//Print the list of tags and successors' name
		void printSuccessors();
		//Successors Management
		void addSuccessor(pair<string, BasicBlock> newsuccessors);
		void removeSuccessor(string tag);

	private:
		string name_;
		map<string, BasicBlock> successors_; //The implementation of a map will prevent the presence of tag duplicates
};

class Function{

	public:
		//Constructors
		Function();
		Function(string name, BasicBlock entry);
		Function(string name, BasicBlock entry, BasicBlock block);
		Function(string name, BasicBlock entry, vector<BasicBlock> vectorofblocks);
		//Destructor
		~Function();
		//Getters
		string getName();
		BasicBlock getEntryBlock();
		BasicBlock getIndexedBlock(int pos);
		vector<BasicBlock> getAllblocks();
		//Setters
		void setName(string newname);
		void setEntryBlock(BasicBlock newentry); //Changes the entry block
		void setIndexedBlock(BasicBlock newblock, int pos); //Change the basic block at position pos (note: the first block is at pos=0)
		//Blocks Management
		void addBlockAtIndex(BasicBlock newblock, int pos); //Adds a new block at index pos (the first block is at pos 0)
		void removeBlockAtIndex(int pos); //Removes the block at index pos
		void purgeAllBlocks(); //Clears the vector of BasicBlocks
		//Function Validity Checking
		bool checkValidity(BasicBlock h);



	private:
		string name_;
		BasicBlock entryblock_;
		vector<BasicBlock> blocks_;

};

class Module{

	public:
		//Constructors
		Module();
		Module(string name);
		Module(string name, vector<Function> vectoroffunctions);
		//Destructor
		~Module();
		//Getter
		string getName();
		Function getIndexedFunction(int pos);
		vector<Function> getAllFunctions();
		//Setters
		void setName(string newname);
		void setIndexedFunction(Function newfunction, int pos);
		//Functions Management (They are implemented in the same way as the ones for basic blocks in class Function)
		void addFunctionAtIndex(Function newfunction, int pos);
		void removeFunctionAtIndex(int pos);
		void purgeAllFunctions();

	private:
		string name_;
		vector<Function> functions_;
};