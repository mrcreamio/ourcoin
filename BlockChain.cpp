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
			Block* pntr = GenesisBlock;
			Block* previous_ptr = GenesisBlock;
			if (GenesisBlock == NULL) {
				NewBlock->hashKey = "sha256(data)";
				NewBlock->prev_hashKey = "00000000000000000000000000000000";
				NewBlock->data = data;
				NewBlock->BlockNum = 0;
				NewBlock->next = NULL;
				GenesisBlock = NewBlock;
			}
			else {
				int counter = 0;
				while(pntr != NULL) {
					previous_ptr = pntr;
					pntr = pntr->next;
					counter++;
				}
				previous_ptr->next = NewBlock;
				NewBlock->hashKey = "sha256(data)";
				NewBlock->prev_hashKey = previous_ptr->hashKey;
				
				NewBlock->prev = previous_ptr;
				NewBlock->data = data;
				NewBlock->BlockNum = counter;
				NewBlock->next = NULL;
			}
		}
	void print(){
		Block* curr = GenesisBlock;
			cout<<"BlockNum:  "<<curr->BlockNum<<endl;
			cout<<"Data:  "<<curr->data<<endl;
			cout<<"Hash Key:  "<<curr->hashKey<<endl;
			cout<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
			do{
				curr = curr->next;
				cout<<"-------------------------------------"<<endl;
				cout<<"BlockNum:  "<<curr->BlockNum<<endl<<endl;
				cout<<"Data:  "<<curr->data<<endl;
				cout<<"Hash Key:  "<<curr->hashKey<<endl;
				cout<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
				cout<<"-------------------------------------"<<endl;
			}while(curr->next != NULL);
	}
	
};
int main(){
	chain ch;
	ch.insert("Hello world!");
	ch.insert("H---->");
	ch.insert("e---->");
	ch.insert("l---->");
	ch.print();
	return 0;
}
