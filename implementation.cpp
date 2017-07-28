#include <iostream>
#include <string>
#include "huffman.h"
#include<bits/tdc++.h>

using namespace std;

//prints the huffman codes from the root of the huffman tree
void printCodes(struct minHeapNode *root, string str)
{
	if (!root)
	{
		return;
	}
	if (root->data != '$')
	{
		cout << root->data << " : " << str << endl;
	}
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}



//builds the huffman tree and prints the codes by traversing through the tree
void huffmanBuild(char data[], int freq[], int size)
{
	struct minHeapNode *left, *right, *top;

	//create minimum heap and inserts all the characters of the data array
	priority_queue<minHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	for (int i = 0; i < size; ++i)
	{
		minHeap.push(new minHeapNode(data[i], freq[i]));
	}

	//iterate through while the size of the heap is not 1
	while (minHeap.size() != 1)
	{

		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		/*
		Create a new internal node with frequency equal to the
        sum of the two nodes frequencies. Make the two extracted
        node as left and right children of this new node. Add
        this node to the min heap. 
		'$' is a special value for internal nodes, not used
		*/
		top = new minHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	//prints huffman codes using the huffman tree built in the function
	printCodes(minHeap.top(), "");
}






//attempted code not complete for using a class in the header file instead of just using the function prototypes.

/*
huffman::huffman(){

}
huffman::~huffman(){

}

void huffman::printCodes(struct minHeapNode *root, string str)
{
	if (!root)
	{
		return;
	}
	if (root->data != '$')
	{
		cout << root->data << " : " << str << endl;
	}
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}




void huffman::huffmanBuild(char data[], int freq[], int size)
{
	priority_queue<minHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	for (int i = 0; i < size; ++i)
	minHeap.push(new minHeapNode(data[i], freq[i]));

	while (minHeap.size() != 1)
	{
		
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		
		top = new minHeapNode('$', left->freq + right->freq);
		top->left = left;
		top->right = right;
		minHeap.push(top);
	}

	
	printCodes(minHeap.top(), "");
}
/*


