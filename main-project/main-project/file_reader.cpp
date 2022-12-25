#include "file_reader.h"
#include "constants.h"

#include <fstream>
#include <cstring>

operation_date convert_date(char* str)
{
    operation_date result;
    char* context = NULL;
    char* str_number = strtok_s(str, ".", &context);
    result.day = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.month = atoi(str_number);
    str_number = strtok_s(NULL, ".", &context);
    result.year = atoi(str_number);
    return result;
}

operation_time convert_time(char* str)
{
    operation_time result;
    char* context = NULL;
    char* str_number = strtok_s(str, ":", &context);
    result.min = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.hour = atoi(str_number);
    str_number = strtok_s(NULL, ":", &context);
    result.sec = atoi(str_number);
    return result;
}

void read(const char* file_name, operation* array[], int& size)
{
    std::ifstream file(file_name);
    if (file.is_open())
    {
        size = 0;
        char tmp_buffer[MAX_STRING_SIZE];
        while (!file.eof())
        {
            operation* item = new operation;
            file >> tmp_buffer;
            item->date = convert_date(tmp_buffer);
            file >> tmp_buffer;
            item->time = convert_time(tmp_buffer);
            file >> item->transaction.type;
            file >> item->transaction.account;
            file >> item->transaction.sum;
            file.read(tmp_buffer, 1); //    
            file.getline(item->purpose, MAX_STRING_SIZE);
            array[size++] = item;
        }
        file.close();
    }
    else
    {
        throw "  ";
    }
}
