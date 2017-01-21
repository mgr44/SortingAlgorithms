#ifndef SORTIMPLS_H
#define SORTIMPLS_H
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

void BubbleSort(vector<int> &list, int startIndex, int endIndex);
void InsertSort(vector<int> &list, int startIndex, int endIndex);
void MergeSort(vector<int> &list, int startIndex, int endIndex);
void Merge(vector<int> &list, int startIndex, int midIndex, int endIndex);
void IterativeMergeSort(vector<int> &list, int startIndex, int endIndex);
void QuickSort(vector<int> &list, int startIndex, int endIndex);
int Partition(vector<int> &list, int startIndex, int endIndex);

void BubbleSort(vector<int> &list, int startIndex, int endIndex)
{
	for (int i = startIndex; i < endIndex; i++)
	{
		for (int j = startIndex; j < endIndex; j++)
		{
			if (list[j] > list[j + 1])
			{
				swap(list[j], list[j + 1]);
			}
		}
	}
}
void InsertSort(vector<int> &list, int startIndex, int endIndex)
{
	for (int i = startIndex + 1; i <= endIndex; i++)
	{
		int current = i;
		int temp = list[current];
		while (current > startIndex && temp <= list[current - 1])
		{
			list[current] = list[current - 1];
			current--;
		}
		list[current] = temp;
	}
}
void MergeSort(vector<int> &list, int startIndex, int endIndex)
{
	int mid = (startIndex + endIndex) / 2;
	if (startIndex < endIndex)
	{
		MergeSort(list, startIndex, mid);
		MergeSort(list, mid + 1, endIndex);
		Merge(list, startIndex, mid, endIndex);
	}

}

void Merge(vector<int> &list, int startIndex, int midIndex, int endIndex)
{
	int size = endIndex - startIndex + 1;

	int *tempArray;
	tempArray = new int[size];

	int arr1Index = startIndex;
	int arr2Index = midIndex + 1;
	int end1 = midIndex;
	int end2 = endIndex;
	int tempArrIndex = 0;

	//merge the items together into the temp array until one half is empty.
	while (arr1Index <= end1 && arr2Index <= end2)
	{
		if (list[arr1Index] < list[arr2Index])
		{
			tempArray[tempArrIndex] = list[arr1Index];
			arr1Index++;
		}
		else
		{
			tempArray[tempArrIndex] = list[arr2Index];
			arr2Index++;
		}
		tempArrIndex++;
	}
	// add any remaining items in either half.
	while (arr1Index <= end1)
	{
		tempArray[tempArrIndex] = list[arr1Index];
		arr1Index++;
		tempArrIndex++;
	}
	while (arr2Index <= end2)
	{
		tempArray[tempArrIndex] = list[arr2Index];
		arr2Index++;
		tempArrIndex++;
	}
	// add the sorted items from temp array back into the list.
	for (int i = 0; i < size; i++)
	{
		list[startIndex] = tempArray[i];
		startIndex++;
	}
	delete[] tempArray;
}
void IterativeMergeSort(vector<int> &list, int startIndex, int endIndex)
{
	int totalSize = endIndex - startIndex + 1;
	int *tempArray = new int[totalSize];

	int groupSize = 1;
	while (groupSize < totalSize)
	{
		// merge into the temp array
		for (int i = startIndex; i <= endIndex; i += (2 * groupSize))
		{
			int group1Index = i;
			int end1 = group1Index + groupSize - 1;
			int group2Index = i + groupSize;
			int end2 = group2Index + groupSize - 1;


			int tempArrIndex = i;
			while (group2Index <= endIndex && group1Index <= end1 && group2Index <= end2)
			{
				if (list[group1Index] < list[group2Index])
				{
					tempArray[tempArrIndex] = list[group1Index];
					group1Index++;
				}
				else
				{
					tempArray[tempArrIndex] = list[group2Index];
					group2Index++;
				}
				tempArrIndex++;
			}
			// add any remaining items in either half.
			while (group1Index <= end1  && group1Index <= endIndex)
			{
				tempArray[tempArrIndex] = list[group1Index];
				group1Index++;
				tempArrIndex++;
			}
			while (group2Index <= end2  && group2Index <= endIndex)
			{
				tempArray[tempArrIndex] = list[group2Index];
				group2Index++;
				tempArrIndex++;
			}
		}

		//double groupsize
		groupSize *= 2;

		for (int i = startIndex; i <= endIndex; i += (2 * groupSize))
		{
			int group1Index = i;
			int end1 = group1Index + groupSize - 1;
			int group2Index = i + groupSize;
			int end2 = group2Index + groupSize - 1;

			int listIndex = i;
			while (group2Index <= endIndex && group1Index <= end1 && group2Index <= end2)
			{
				if (tempArray[group1Index] < tempArray[group2Index])
				{
					list[listIndex] = tempArray[group1Index];
					group1Index++;
				}
				else
				{
					list[listIndex] = tempArray[group2Index];
					group2Index++;
				}
				listIndex++;
			}
			// add any remaining items in either half.
			while (group1Index <= end1  && group1Index <= endIndex)
			{
				list[listIndex] = tempArray[group1Index];
				group1Index++;
				listIndex++;
			}
			while (group2Index <= end2 && group2Index <= endIndex)
			{
				list[listIndex] = tempArray[group2Index];
				group2Index++;
				listIndex++;
			}
		}
		//double groupsize again
	}
	delete[] tempArray;
}
void QuickSort(vector<int> &list, int startIndex, int endIndex)
{
	int pivotIndex;

	if (startIndex < endIndex)
	{

		pivotIndex = Partition(list, startIndex, endIndex);

		QuickSort(list, startIndex, pivotIndex);
		QuickSort(list, pivotIndex + 1, endIndex);
	}

}
int Partition(vector<int> &list, int startIndex, int endIndex)
{
	int pivotVal = list[endIndex];
	int rightIndex = endIndex - 1;
	int leftIndex = startIndex;

	while (true)
	{
		while (list[leftIndex] < pivotVal && leftIndex < rightIndex)
		{
			leftIndex++;
		}
		while (list[rightIndex] > pivotVal && rightIndex > leftIndex)
		{
			rightIndex--;
		}
		//either swap values or we are done

		//swap
		if (rightIndex > leftIndex)
		{
			swap(list[leftIndex], list[rightIndex]);

		}
		else
		{
			break;
		}
	}
	if (list[endIndex] < list[rightIndex])
	{
		swap(list[rightIndex], list[endIndex]);
	}
	return rightIndex;

}
#endif