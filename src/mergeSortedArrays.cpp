/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int who_isOlder(char *dob_1, char *dob_2);
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	//for null input;;
	if (A == NULL || B== NULL)
		return NULL;
	struct transaction *result_trans_output;
	//memory allocation for result operation;;
	result_trans_output = (struct transaction *)malloc(sizeof(struct transaction)*(ALen + BLen));
	// initializing the values;;;
	int tran_i = 0, tran_j = 0, tran_k = 0;
	while (tran_i < ALen && tran_j < BLen){//checking with both arrays lengths
		if (who_isOlder(A[tran_i].date, B[tran_j].date) == 2)
		{
		   result_trans_output[tran_k].amount = B[tran_j].amount;
			tran_j++;
		}
		else
		{
			result_trans_output[tran_k].amount = A[tran_i].amount;
			tran_i++;
		}
		tran_k++;
	}
	while (tran_i<ALen){
		result_trans_output[tran_k].amount = A[tran_i].amount;
		tran_i++;
		tran_k++;
	}

	while (tran_j<BLen){
		result_trans_output[tran_k].amount = B[tran_j].amount;
		tran_j++;
		tran_k++;
	}
	return result_trans_output;
}
int who_isOlder(char *dob_1, char *dob_2) {
	int i = 0, dd1 = 0, mm1 = 0, yyyy1 = 0, dd2 = 0, mm2 = 0, yyyy2 = 0;
	while (dob_1[i] != '-'&&dob_1[i] != '\0')
	{
		if (dob_1[i] < '0' || dob_1[i] > '9')
			return -1;
		dd1 *= 10;
		dd1 += dob_1[i] - '0';
		i++;
	}
	if (dob_1[i] == '\0')
		return -1;
	i++;

	while (dob_1[i] != '-'&&dob_1[i] != '\0')
	{
		if (dob_1[i] < '0' || dob_1[i] > '9')
			return -1;
		mm1 *= 10;
		mm1 += dob_1[i] - '0';
		i++;
	}

	if (dob_1[i] == '\0')
		return -1;
	i++;

	while (dob_1[i] != '-'&&dob_1[i] != '\0')
	{
		if (dob_1[i] < '0' || dob_1[i] > '9')
			return -1;
		yyyy1 *= 10;
		yyyy1 += dob_1[i] - '0';
		i++;
	}

	if (dob_1[i] == '\0')
	{
		if (yyyy1 % 4 == 0 && mm1 == 2 && dd1 >= 30)
			return -1;
		if (yyyy1 % 4 != 0 && mm1 == 2 && dd1 >= 29)
			return -1;
		if (mm1 > 12 || dd1 > 31)
			return -1;
	}
	else
		return -1;

	i = 0;

	while (dob_2[i] != '-'&&dob_2[i] != '\0')
	{
		if (dob_2[i] < '0' || dob_2[i] > '9')
			return -1;
		dd2 *= 10;
		dd2 += dob_2[i] - '0';
		i++;
	}
	if (dob_2[i] == '\0')
		return -1;
	i++;
	while (dob_2[i] != '-'&&dob_2[i] != '\0')
	{
		if (dob_2[i] < '0' || dob_2[i] > '9')
			return -1;
		mm2 *= 10;
		mm2 += dob_2[i] - '0';

		i++;
	}
	if (dob_2[i] == '\0')
		return -1;
	i++;
	while (dob_2[i] != '-'&&dob_2[i] != '\0')
	{
		if (dob_2[i] < '0' || dob_2[i] > '9')
			return -1;
		yyyy2 *= 10;
		yyyy2 += dob_2[i] - '0';
		i++;
	}
	if (dob_2[i] == '\0')
	{
		if (yyyy2 % 4 == 0 && mm2 == 2 && dd2 >= 30)
			return -1;
		if (yyyy2 % 4 != 0 && mm2 == 2 && dd2 >= 29)
			return -1;
		if (mm2 > 12 || dd2 > 31)
			return -1;
	}
	else
		return -1;

	if (yyyy1>yyyy2)
		return 2;
	else if (yyyy1<yyyy2)
		return 1;
	else
	{
		if (mm1>mm2)
			return 2;
		else if (mm1<mm2)
			return 1;
		else
		{
			if (dd1>dd2)
				return 2;
			else if (dd1<dd2)
				return 1;
			else
				return 0;
		}
	}
	return 0;
}