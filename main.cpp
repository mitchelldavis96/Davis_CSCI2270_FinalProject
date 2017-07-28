//test program to see how the implementation works and to get an 
//example of what huffman encoding is and how it uses BST's and 
//priority queues.


#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "huffman.h"

using namespace std;

int main()
{
	int z;
	char x;
	
	char *arr[10];                        
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter in the ten array characters." << endl;
		cin >> x;
		*arr[i] = x;
	}
	
	int *freq[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter in the frequency of each character." << endl;
		cin >> z;
		*freq[i] = z;
	}

  //sample code to test without user input
	//char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	//int freq[] = { 5, 9, 12, 13, 16, 45 };
	int size = sizeof(arr) / sizeof(arr[0]);
	
	huffmanBuild(*arr, *freq, size);

	return 0;
}
