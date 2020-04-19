#pragma once
#include <iostream>
#include <string>

using namespace std;

namespace family{
	class Tree{
		struct node{
			string name;
			node* mother;
			node* father;
		};

		public:
		node* root = new node;
		Tree(string name){
			root->name=name;
			root->mother=NULL;
			root->father=NULL;
			
		}
		struct node* createNode(string name);
		struct node* findChild(string child, node* temp);
		Tree addFather(string child, string father);
		Tree addMother(string child, string mother);
		string relation(string person);
		string find(string relation);
		void display();
		void remove(string person);
		int height(node* node);
		void deleteTree(node* node);
	};
	void print(string name, int numOfSpaces);
}




