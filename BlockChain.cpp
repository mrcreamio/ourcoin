#include <iostream>
#include <string>
#include <time.h>
using namespace std;
struct Block{
	string data;
	string prev_hashKey;
	string hashKey;
	int BlockNum;
	Block* next;
	Block* prev;
};

class chain{
public:
		Block* GenesisBlock = NULL;
		void insert(string data)
		{
			Block* NewBlock = new Block;
			NewBlock->hashKey = "2r3yqj4vrqm32gqjy4q2gjm4yq23f4yj";
			NewBlock->prev_hashKey = "00000000000000000000000000000000";
			NewBlock->data = data;
			NewBlock->BlockNum = 1;
			NewBlock->next = NULL;
			GenesisBlock = NewBlock;
		}
	void print(){
		Block* curr = GenesisBlock;
		if(curr->next == NULL){
			cout<<"BlockNum:  "<<curr->BlockNum<<endl;
			cout<<"Data:  "<<curr->data<<endl;
			cout<<"Hash Key:  "<<curr->hashKey<<endl;
			cout<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
		}
		else{
			while(curr->next != NULL){
				cout<<"-------------------------------------"<<endl;
				cout<<"BlockNum:  "<<curr->BlockNum<<endl<<endl;
				cout<<"Data:  "<<curr->data<<endl;
				cout<<"Hash Key:  "<<curr->hashKey<<endl;
				cout<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
				curr = curr->next;
				cout<<"-------------------------------------"<<endl;
			}
		}
	}
	
};
int main(){
	chain ch;
	ch.insert("Hello world!");
	ch.print();
	return 0;
}
