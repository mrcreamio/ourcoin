#include <iostream>
#include <string>
#include <time.h>
#include <fstream>
#include "sha256.h"
using namespace std;
string timestamp();

struct Block{
	string data;
	string prev_hashKey;
	string hashKey;
	int BlockNum;
	Block* next;
	Block* prev;
 	long long nonce;

};

class chain{
public:
		Block* GenesisBlock = NULL;

		void insert(string data)
		{
			data += timestamp();
			//data+= " ";
			int length = data.length();
			Block* NewBlock = new Block;
			Block* pntr = GenesisBlock;
			Block* previous_ptr = GenesisBlock;

			if (GenesisBlock == NULL) {
				NewBlock->hashKey = sha256(data);
				string temp;
				while (!(NewBlock->hashKey[0] == '0' && NewBlock->hashKey[1] == '0' && NewBlock->hashKey[2] == '0' && NewBlock->hashKey[3] == '0'  && NewBlock->hashKey[4] == '0'))
				{
					temp = data;
					NewBlock->nonce += 1;
					std::string s = std::to_string(NewBlock->nonce);
					temp += s;
					std::cout << "data = "<<temp << '\n';
					std::cout << "nonce = "<< NewBlock->nonce << '\n';
					NewBlock->hashKey = sha256(temp);
				}
				std::cout << "nonce = "<< NewBlock->nonce << '\n';
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
				NewBlock->hashKey = sha256(data);
				string temp;
				while (!(NewBlock->hashKey[0] == '0' && NewBlock->hashKey[1] == '0' && NewBlock->hashKey[2] == '0' && NewBlock->hashKey[3] == '0'&& NewBlock->hashKey[4] == '0'))
				{
					temp = data;
					NewBlock->nonce += 1;
					std::cout << "nonce = "<< NewBlock->nonce << '\n';
					std::string s = std::to_string(NewBlock->nonce);
					temp += s;
					std::cout << "data = "<<temp << '\n';
					NewBlock->hashKey = sha256(temp);
				}
				std::cout << "nonce = "<< NewBlock->nonce << '\n';
				NewBlock->prev_hashKey = previous_ptr->hashKey;

				NewBlock->prev = previous_ptr;
				NewBlock->data = data;
				NewBlock->BlockNum = counter;
				NewBlock->next = NULL;
			}
		}
	void print(){
		Block* curr = GenesisBlock;
		if (curr == NULL)
		{
			cout<<"-------------------------------------"<<endl;
				std::cout << "Nothing to print" << '\n';
			cout<<"-------------------------------------"<<endl;
		}
		else
		{

			cout<<"BlockNum:  "<<curr->BlockNum<<endl;
			cout<<"Data:  "<<curr->data<<endl;
			cout<<"Hash Key:  "<<curr->hashKey<<endl;
			cout<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
			cout<<"Nonce :"<<curr->nonce<<endl;
			do{
				curr = curr->next;
				cout<<"-------------------------------------"<<endl;
				cout<<"BlockNum:  "<<curr->BlockNum<<endl<<endl;
				cout<<"Data:  "<<curr->data<<endl;
				cout<<"Hash Key:  "<<curr->hashKey<<endl;
				cout<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
				cout<<"Nonce :"<<curr->nonce<<endl;
				cout<<"-------------------------------------"<<endl;
			}while(curr->next != NULL);
		}
	}
	void printBlock(int num)
	{
		Block* curr = GenesisBlock;
		if (curr == NULL)
		{
			cout<<"-------------------------------------"<<endl;
				std::cout << "Nothing to print" << '\n';
			cout<<"-------------------------------------"<<endl;
		}
		else
		{

		for (size_t i = 1; i < num; i++) {
				curr = curr->next;
		}
		cout<<"-------------------------------------"<<endl;
		cout<<"BlockNum:  "<<curr->BlockNum<<endl<<endl;
		cout<<"Data:  "<<curr->data<<endl;
		cout<<"Hash Key:  "<<curr->hashKey<<endl;
		cout<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
		cout<<"Nonce :"<<curr->nonce<<endl;
		cout<<"-------------------------------------"<<endl;
	}
	}
	void writetofile()
	{
		fstream file;
		file.open("blocks.txt", ios::out);
		Block* curr = GenesisBlock;
			file<<"BlockNum:  "<<curr->BlockNum<<endl;
			file<<"Data:  "<<curr->data<<endl;
			file<<"Hash Key:  "<<curr->hashKey<<endl;
			file<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
			file<<"Nonce :"<<curr->nonce<<endl;
			do{
				curr = curr->next;
				file<<"-------------------------------------"<<endl;
				file<<"BlockNum:  "<<curr->BlockNum<<endl<<endl;
				file<<"Data:  "<<curr->data<<endl;
				file<<"Hash Key:  "<<curr->hashKey<<endl;
				file<<"Previous Hash Key:  "<<curr->prev_hashKey<<endl;
				file<<"Nonce :"<<curr->nonce<<endl;
				file<<"-------------------------------------"<<endl;
			}while(curr->next != NULL);
			file.close();
	}

};
string timestamp()
{
	time_t now = time(0);
	char* dt = ctime(&now);
	return dt;
}
int main(){
	chain ch;
	bool driver = true;
	while(driver == true)
	{
		int var,x;
		string data;
		cout<<"-------------------------------------"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"---------WELCOME TO OURCOIN----------" <<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"-------------------------------------"<<endl;
		cout<<"-------------------------------------"<<endl;
		std::cout << "press 1 to make a new Ledger" << '\n';
		std::cout << "press 2 to print Ledgers" << '\n';
		std::cout << "press 3 to print a specific ledger" << '\n';
		std::cout << "press 4 to write the ledgers to file" << '\n';
		std::cout << "press 5 to quit" << '\n';
		std::cin >> var;
		switch (var) {
			case 1:
						std::cout << "enter Information" << '\n';
						cin.ignore();
						getline(cin, data);
						ch.insert(data);
						break;
			case 2:
						ch.print();
						break;
			case 3:
						std::cout << "Enter the block number of ledger you want to print" << '\n';
						std::cin >> x;
						ch.printBlock(x);
						break;
			case 4:
						ch.writetofile();
						std::cout << "All ledgers writed to the file" << '\n';
						break;
			case 5:
						driver = false;
						break;
		}
	}
	// ch.insert("Hello world!");
	// ch.insert("H---->");
	// ch.insert("e---->");
	// ch.insert("l---->");
	// ch.print();
	// ch.printBlock(1);
	// ch.writetofile();
	return 0;
}
