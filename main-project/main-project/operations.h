#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "constants.h"

struct operation_date
{
    int day;
    int month;
    int year;
};

struct operation_time
{
    int min;
    int hour;
    int sec;
};

struct transactions
{
    char type[MAX_STRING_SIZE];
    char account[MAX_STRING_SIZE];
    char sum[MAX_STRING_SIZE];
};

struct operation
{
    operation_date date;
    operation_time time;
    transactions transaction;
    char purpose[MAX_STRING_SIZE];
};

#endif
