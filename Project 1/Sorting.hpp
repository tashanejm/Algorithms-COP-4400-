#ifndef __SORTING_H
#define __SORTING_H

#include "Helper.hpp"
using namespace std;


template <class T> void selectionsort(T * data, int size){
	int i;
	for (i = 0; i < size; i++){
		int min = i;
		for (int j = i + 1; j < size; j++){
			if (data[j] < data[min])
				min = j;
		}
		Swap(data[i], data[min]);
	}
}

template <class T> void insertionsort(T * data, int size){
	int i, j, temp;
	for (i = 1; i < size; i++)
	{
		temp = data[i];
		j = i - 1;
		while (j >= 0 && data[j] > temp)
		{
			data[j + 1] = data[j];
			j = j - 1;
		}
		data[j + 1] = temp;
	}
}

template <class T> void mergesort(T * data, int size, T *temp){
	if (size > 1)
	{
		int i = 0;
		int j;
		const int mid = (size + 1) / 2;
		T *left = data;
		T *right = &data[mid];

		mergesort(left, mid, temp);
		mergesort(right, size - mid, &temp[mid]);
		
		int l = 0;
		int r = 0;
		int s = 0;

		while (l < mid && r < (size - mid))
		{
			if (left[l] < right[r])
			{
				temp[s] = left[l];
				l++;
			}
			else
			{
				temp[s] = right[r];
				r++;
			}
			s++;
		}


		for (j = s, i = l; i < mid; i++, j++)
		{
			temp[j] = left[i];
		}
		s = s + mid - l;
		for (i = r, j = s; i < (size - mid); i++, j++)
		{
			temp[j] = right[i];
		}
		
		for (i = 0; i < size; i++)
		{
			data[i] = temp[i];
		}
	}
}

template <class T> void quicksort(T * data, int size)
{
	if (size <= 1)
	{
		return;
	}

	int mid = (size + 1) / 2;
	int pivot = medianof3(data[0], data[mid], data[size - 1]); 
	/*int pivot;
	if (data[0] > data[mid]){
		pivot = 0;
	}
	else if (data[mid] > data[size - 1]){
		pivot = mid;
	}
	else {
		pivot = size - 1;
	}*/

	if (pivot == 1){
		pivot = 0;
	}
	else if (pivot == 2){
		pivot = mid;
	}
	else {
		pivot = size-1;
	}
	Swap(data[pivot], data[0]);
	
	int left = 0;
	int right = size-1;

	do
	{
		while (left < right && data[left] <= data[0])
		{
			left++;
		}
		while (left < right && data[right] > data[0])
		{
			right--;
		}
		Swap(data[left], data[right]);
	} while (left < right);

	if (data[left] > data[0])
	{
		left--;
	}

	Swap(data[0], data[left]);

	quicksort(data, left);
	quicksort(data+left+1, size-left-1);
}


#endif
