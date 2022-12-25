#include <iostream>
#include "operations.h"
#include "file_reader.h"
#include "constants.h"
#include <iomanip>

using namespace std;


int main()
{   
    setlocale(LC_ALL,"ru");
    std::cout << "Вариант 7. Банковские операции. Валерия Михалевич\n";
    operation* operation[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", operation, size);
        for (int i = 0; i < size; i++)
        {
            cout << operation[i]->date.day << '\n';
            cout << operation[i]->date.month << '\n';
            cout << operation[i]->date.year << '\n';
            cout << operation[i]->time.min << ' ';
            cout << operation[i]->time.hour << ' ';
            cout << operation[i]->time.sec << '\n';
            cout << operation[i]->transaction.type << ' ';
            cout << operation[i]->transaction.account << ' ';
            cout << " ...: ";
            cout << setw(2) << setfill('0') << operation[i]->date.day << "-";
            cout << setw(2) << setfill('0') << operation[i]->date.month << "-";
            cout << setw(4) << setfill('0') << operation[i]->date.year << '\n';
            cout << " ..: ";
            cout << setw(2) << setfill('0') << operation[i]->time.min << ':';
            cout << setw(2) << setfill('0') << operation[i]->time.hour << ':';
            cout << setw(2) << setfill('0') << operation[i]->time.sec << '\n';
            cout << " ....: ";
            cout << operation[i]->transaction.type << '\n';
            if (!strcmp(operation[i]->transaction.type, ""))
            {
                cout << " ......: ";
                cout << operation[i]->transaction.account << '\n';
            }
            else if (!strcmp(operation[i]->transaction.type, ""))
            {
                cout << " .......: ";
                cout << operation[i]->transaction.account << '\n';
            }
            cout << "...........: ";
            cout << operation[i]->transaction.sum << '\n';
            cout << "......: ";
            cout << operation[i]->purpose << '\n';
            cout << '\n';
        }

        for (int i = 0; i < size; i++)
        {
            delete operation[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    return 0;
}
