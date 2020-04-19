#include <iostream>
#include <bits/stdc++.h> 
#include <string>
#include <math.h>
#include "FamilyTree.hpp"

using namespace std;
namespace family{

	Tree::node* Tree::createNode(string name){
		node* p = new node;
		p->name = name;
		p->mother = NULL;
		p->father = NULL;
		
		return p;
	}

	Tree::node* Tree::findChild(string child, node* root){
		if(root == NULL)
			return NULL;
		else if(root->name == child)
			return root;
		
		node* person = findChild(child, root->mother);
		if(person == NULL)
			person = findChild(child, root->father);
			
		return person;

	}

	Tree Tree::addFather(string child, string father){
		node* pFather = createNode(father);

		if(child == this->root->name){
			if(this->root->father != NULL)
				throw runtime_error(child + "already has a father!");
			else
				this->root->father = pFather;
			
		}
		else{
			node* temp = new node;
			temp = findChild(child, this->root);
			if(temp == NULL)	
				throw runtime_error(child + "not found!");
			else if(temp->father != NULL)
				throw runtime_error(child + "already has a father!");
			temp->father=pFather;
		}

		return *this;
	}

	Tree Tree::addMother(string child, string mother){
		node* pMother = createNode(mother);
		
		if(child == this->root->name){
			if(this->root->mother != NULL)
				throw runtime_error(child + "already has a mother!");
			else
				this->root->mother = pMother;	
		}
		else{
			node* temp = new node;
			temp = findChild(child, this->root);
			if(temp == NULL)	
				throw runtime_error(child + "not found!");
			else if(temp->mother != NULL)
				throw runtime_error(child + "already has a mother!");
			temp->mother=pMother;
		}

		return *this;
	}



	string Tree::relation(string person){
		if(root->name == person)
			return "me";		
		else if(root->mother!=NULL && root->mother->name == person)
			return "mother";
		else if(root->father !=NULL && root->father->name == person)
			return "father";
		
		node* mother = root->mother;
		node* father = root->father;

		int generation = 1, i=0;
		string relation="";
		queue<node*> q; 
		q.push(this->root);

		while (q.empty() == false) { 
			int nodeCount = q.size(); 
			while (nodeCount > 0) {  

			    node *node = q.front(); 
			    mother = node->mother;
			    father = node ->father;

			    if(mother != NULL && mother->name == person)
				return relation+"grandmother";	
			    else if(father != NULL && father->name == person)
				return relation+"grandfather";
			    
			    mother = node->mother;
			    father = node->father;
			    q.pop();
			  
			    
			    if (node->father != NULL) 
					q.push(node->father);
			    if (node->mother != NULL) 
					q.push(node->mother); 
			    nodeCount--;  
			}
			if(generation>=2)
				relation+="great-";
			generation++; 	
	        }
		return "unrelated";
	}




	int findGeneration(string relation){
		int i=0, generation=0;
		while(i<relation.length()){
			if(relation.at(i) == '-')
				generation++;
			i++;
		}
		return generation;


	}
	string findGender(string relation, int generation){
		string person = "" ;
		int i=0;
		while(i<generation){
			person+="great-";
			i++;
		}
		string temp1 = person + "grandmother";
		string temp2 = person + "grandfather";
		string gender;
		if(relation == temp1)
			gender = "female";
		else if(relation == temp2)
			gender = "male";
		else
			throw runtime_error("The tree cannot handle the " + relation + " relation.");
		return gender;
	}



	string Tree::find(string relation){
		if(relation == "me")
			return root->name;
	
		else if(relation == "mother"){
			if(root->mother == NULL)
				throw runtime_error("not found");
			return root->mother->name;
		}
		else if(relation == "father"){
			if(root->father == NULL)
				throw runtime_error("not found");
			return root->father->name;
		}


		int generation = findGeneration(relation);
		string gender = findGender(relation, generation);


		int i=0;
		node* temp =this->root;
		queue<node*> q; 
		q.push(this->root);
		while (q.empty() == false && i<generation+2) { 
			int nodeCount = q.size();  
			while (nodeCount > 0) {  
			    node *node = q.front();   
			    q.pop();
			    
			    if (node->father != NULL) {
				if(i != generation+1 || gender == "male") 
					q.push(node->father);
			    }
			    if (node->mother != NULL) { 
				if(i != generation+1 || gender == "female")
					q.push(node->mother);
			    } 
			    
			    nodeCount--;  
			}
			i++; 	
	        } 
		if(q.empty() == true)
			throw runtime_error("not found");

		temp = q.front();
		return temp->name;
	}









	int Tree::height(node* node){
		int height;
		if(node==NULL)	
			return 0;
		else{	
			int hMother = Tree::height(node->mother);
			int hFather = Tree::height(node->father);
			if (hMother > hFather)  
            			return(hMother + 1);  
        		else 
				return(hFather + 1);  
		}
			
	}
	void Tree::display(){
		int height = Tree::height(this->root);
		double maxNodes = pow(2,height);
		
	        if (this->root == NULL)  
			return; 
	  
	        queue<node*> q; 
		queue<int> s;
	  
	        // Enqueue Root and initialize height 
	        q.push(this->root);
		s.push(maxNodes*2); 
		
	  
	        while (q.empty() == false) { 
			int nodeCount = q.size();  
		  
			// Dequeue all nodes of current level and  
			// Enqueue all nodes of next level  
			while (nodeCount > 0) {  
			    node *node = q.front();  
			    int numOfSpaces = s.front();
			    if(node == NULL){
			    	print(" ", numOfSpaces);
				q.pop();
				s.pop();
				nodeCount--; 
				continue;
			    }	 
			    print(node->name, numOfSpaces);  
			    q.pop(); 
			    s.pop();
			 
			    if (node->father != NULL) {
				q.push(node->father);
			    }
			    else{
				q.push(NULL);
			    }
			    s.push(numOfSpaces/2);
			    if (node->mother != NULL) { 
				q.push(node->mother);
			    } 
			    else{
				q.push(NULL);
				
			    }
			    s.push(numOfSpaces/2);
			    nodeCount--;  
			}  
			cout << endl;  
			
	     
	        } 
		
	}
	//a simple printing function, for the display function
	void print(string name, int numOfSpaces){
		int i=0;
		while(i<numOfSpaces){
			cout<<" ";
			i++;
		}	
		cout<< name;
		i=0;
		while(i<numOfSpaces){
			cout<<" ";
			i++;
		}
	}

	void Tree::remove(string person){
		if(root->name == person){
			throw runtime_error("Cannot delete the root!");
		}
		queue<node*> q; 
		q.push(this->root);
		while (q.empty() == false) { 
			//int nodeCount = q.size(); 
			//while (nodeCount > 0) {  
				node *node = q.front(); 
				if(node->father != NULL && node->father->name == person){
					deleteTree(node->father);
					node->father = NULL;
					return;
				}
				else if(node->mother != NULL && node->mother->name == person){
					deleteTree(node->mother);
					node->mother = NULL;
					return;
				}
				q.pop();
				if (node->father != NULL) {
					q.push(node->father);
				}
				if (node->mother != NULL) { 
					q.push(node->mother);
				}
				//nodeCount--;  
			//} 	
	        } 
	
		throw runtime_error("Not found!");


	}
	void Tree::deleteTree(node* node)  {  
		if (node == NULL) return;  
	  
		if(node->father != NULL)
			deleteTree(node->father);
		if(node->mother != NULL)  
			deleteTree(node->mother);  
	      
		//cout << "Deleting node: " << node->name <<endl;  
		free(node);  
	}  
}


