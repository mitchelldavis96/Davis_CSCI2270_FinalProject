#ifndef huffman_h
#define huffman_h
#include <bits/tdc++.h>
using namespace std;

//creating the huffman tree node
struct minHeapNode
{
	char data;			//input character
	unsigned freq;     //frequency of character
	minHeapNode *left, *right;	//left and right children in the huffman tree (BST)

	minHeapNode(char data, unsigned freq)
	{
		left = right = nullptr;
		this->data = data;
		this->freq = freq;
	}
};

//compares two heap nodes, needed in minimum heap
struct compare
{
	bool operator()(minHeapNode *left, minHeapNode *right)
	{
		return (left->freq > right->freq);
	}
};

void printCodes(struct minHeapNode *root, string str);
void huffmanBuild(char data[], int freq[], int size);

//implememting a class instead of just using the function prototypes.

/*class huffman
{
public:
	huffman();
	~huffman();
	void printCodes(struct minHeapNode *root, string str);
	void huffmanBuild(char data[], int freq[], int size);
};*/

#endif
