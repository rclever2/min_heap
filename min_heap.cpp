/*
 * 	min_heap.cpp
 *	Version: 1.0
 *  Created on: Oct 26, 2019
 *  Author: Russell Cleverly
 *
 *  The purpose of this program is to demonstrate a basic min_heap implementation written in C++ with limited functionality.
 *  As it is, the program is not very useful but can easily be adapted into a priority queue or integrated into another program.
 */

#include <iostream>

/**
 * Helper Functions
 */
int getLeftChildIndex (int index) { return (index * 2) + 1; }
int getRightChildIndex (int index) { return (index * 2) + 2; }
int getParentIndex (int index) { return (index - 1) / 2; }
bool hasLeftChild (int index, int size) { return getLeftChildIndex(index) < size; }
bool hasRightChild (int index, int size) { return getRightChildIndex(index) < size; }
bool hasParent (int index) { return getParentIndex(index) >= 0; }

/**
 * Function swaps nodes given two indexes of the nodes.
 */
void swap (int min_heap[], int indexOne, int indexTwo)
{
	int temp = min_heap[indexOne];
	min_heap[indexOne] = min_heap[indexTwo];
	min_heap[indexTwo] = temp;
}

/**
 * Function takes in an index of a new node and places the node in the correct position
 */
void heapifyUp(int index, int min_heap[])
{
	while(hasParent(index) && min_heap[getParentIndex(index)] > min_heap[index])
	{
		swap(min_heap,getParentIndex(index),index);
		index = getParentIndex(index);
	}
}

/**
 * Function places the root node in the correct location
 */
void heapifyDown(int min_heap[], int size)
{
	int index = 0; //root node
	while(hasLeftChild(index,size))
	{
		int smallestIndex;
		if (min_heap[getRightChildIndex(index)] > min_heap[getLeftChildIndex(index)])
		{
			smallestIndex = getLeftChildIndex(index);
		}
		else
		{
			smallestIndex = getRightChildIndex(index);
		}

		if (min_heap[index] > min_heap[smallestIndex])
		{
			swap(min_heap,index,smallestIndex);
		}
		index = smallestIndex;
	}
}

/**
 * Driver function
 */
int main()
{



	std::cout << "How large would you like this heap to be? ";
	int size;
	std::cin >> size;
	std:: cout << std::endl;

	int numOfNodes = 0; //current number of nodes in the heap
	int *min_heap = new int[size]; //creates a heap of size 1


	while (numOfNodes<size)
	{
		std::cout << "Input another number into the min heap: ";
		int entry;
		std::cin >> entry;

		min_heap[numOfNodes] = entry; //inputs new entry into the last heap slot
		heapifyUp(numOfNodes,min_heap); //places new node in correct position in the heap

		// for outputting the heap to std out
		std::cout << "Heap: ";
		for (int i=0;i<=numOfNodes;i++) { std::cout << min_heap[i] << " "; }
		std::cout << std::endl << std::endl;

		numOfNodes++;
	}

	std::cout << "Removing root node..." << std::endl;
	min_heap[0] = min_heap[numOfNodes-1];
	heapifyDown(min_heap,size);
	numOfNodes--;

	// for outputting the heap to std out
			std::cout << "Heap: ";
			for (int i=0;i<=numOfNodes;i++) { std::cout << min_heap[i] << " "; }
			std::cout << std::endl << std::endl;

}

