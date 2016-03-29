/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/
#define NULL 0

int findSingleOccurenceNumber(int *A, int len) {
	//checking for null input
	if (A == NULL)
		return -1;
	int arr_i, arr_j;
	int arr_ele;
	//checking for single occurence;;
	for (arr_i = 0; arr_i < len; arr_i++) {
		for (arr_j = 0; arr_j < len - 1; arr_j++)
			if (A[arr_i] == A[arr_j] && arr_i != arr_j)
				break;
		if (arr_j == len - 1)
			arr_ele = A[arr_i];
	}
	return arr_ele;


	
}