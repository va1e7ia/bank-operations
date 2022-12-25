#include "filter.h"
#include <cstring>
#include <iostream>

operation** filter(operation* array[], int size, bool (*check)(operation* element), int& result_size)
{
	operation** result = new operation * [size];
	result_size = 0;
	for (int i = 0; i < size; i++)
	{
		if (check(array[i]))
		{
			result[result_size++] = array[i];
		}
	}
	return result;
}

bool check_operation_by_type(operation* element)
{
	return strcmp(element->transaction.type, "ïðèõîä") == 0;
}

bool check_operation_by_date(operation* element)
{
	return element->date.month == 11 && element->date.year == 2021;
}
