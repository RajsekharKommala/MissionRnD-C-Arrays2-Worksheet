/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/
#include<string.h>
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int d, m, y, i, year, mon, day, count = 0, j = 0;
	int A[10];
	for (i = 0; i<10; i++)
	{
		A[i] = (*(date + i) - 48);
	}
	d = (A[0] * 10) + A[1];
	m = (A[3] * 10) + A[4];
	y = (A[6] * 1000) + (A[7] * 100) + (A[8] * 10) + A[9];
	for (i = 0; i < len; i++)
	{

		if (!strcmp(Arr[i].date, date))
		{
			j = 1;
			count = i;
		}
	}
	if (j == 0)
		return 0;
	else
		return len - 1 - count;
}
