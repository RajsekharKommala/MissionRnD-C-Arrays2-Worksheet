/*
OVERVIEW: You are given 2 bank statements that are ordered by date. 
Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.


ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction *answer = (struct transaction *)malloc((ALen + BLen)*sizeof(struct transaction));
	int i, j, k, flag = 0;
	for (i = 0; i < ALen; i++)
	{
		for(j = 0; j < BLen; j++)
		{
			k = 6;
			while (k < 10)
			{
				if (A[i].date[k] - 48 == B[j].date[k] - 48)
					k++;
				else
					break;
			}
			if (k == 10)
			{
			    k = 3;
				while (k < 5)
				{
					if (A[i].date[k] - 48 == B[j].date[k] - 48)
						k++;
					else
					{
						break;
					}
				}
			}
			if (k == 5)
			{
				k = 0;
				while (k < 2)
				{
					if (A[i].date[k] - 48 == B[j].date[k] - 48)
						k++;
					else
						break;
				}
			}
			if (k == 2)
			{
				answer[flag] = A[i];
				flag++;
			}
		}
	}
	if (flag == 0)
		return NULL;
	else
		return answer;
}