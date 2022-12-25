#ifndef FILTER_H
#define FILTER_H

#include "operations.h"

operation** filter(operation* array[], int size, bool (*check)(operation* element), int& result_size);

bool check_operation_by_type(operation* element);


bool check_operation_by_date(operation* element);


#endif
