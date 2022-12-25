#include <iostream>
#include "operations.h"
#include "file_reader.h"
#include "constants.h"
#include "filter.h"
#include <iomanip>

using namespace std;


int main()
{   
    setlocale(LC_ALL,"ru");
    std::cout << "Вариант 7. Банковские операции. Валерия Михалевич\n";
    std::cout << "Группа 12\n";
    operation* operations[MAX_FILE_ROWS_COUNT];
    int size;
    try
    {
        read("data.txt", operations, size);
        for (int i = 0; i < size; i++)
        {
            cout << setw(2) << setfill('0') << operations[i]->date.day << "-";
            cout << setw(2) << setfill('0') << operations[i]->date.month << "-";
            cout << setw(4) << setfill('0') << operations[i]->date.year << '\n';
            cout << setw(2) << setfill('0') << operations[i]->time.min << ':';
            cout << setw(2) << setfill('0') << operations[i]->time.hour << ':';
            cout << setw(2) << setfill('0') << operations[i]->time.sec << '\n';
            cout << " ....: ";
            if (!strcmp(operations[i]->transaction.type, "")) {
                cout << operations[i]->transaction.account << '\n';
            }
            else if (!strcmp(operations[i]->transaction.type, ""))
            {
                cout << " .......: ";
                cout << operations[i]->transaction.account << '\n';
            }
            cout << "...........: ";
            cout << operations[i]->transaction.sum << '\n';
            cout << "......: ";
            cout << operations[i]->purpose << '\n';
            cout << '\n';
        }

        bool (*check_function)(operation*) = NULL; // check_function -    ,    bool,
        //        book_subscription*
        cout << "\n     :\n";
        cout << "1)  \"\"\n";
        cout << "2)    2021\n";
        cout << "\n   : ";
        int item;
        cin >> item;
        cout << '\n';
        switch (item)
        {
        case 1:
            check_function = check_operation_by_type; //       
            cout << "*****   \"\" *****\n\n";
            break;
        case 2:
            check_function = check_operation_by_date; //       
            cout << "*****    2021 *****\n\n";
            break;
        default:
            throw "  ";
        }
        if (check_function)
        {
            int new_size;
            operation** filtered = filter(operations, size, check_function, new_size);
            for (int i = 0; i < new_size; i++)
            {
                cout << " ...: ";
                cout << setw(2) << setfill('0') << filtered[i]->date.day << "-";
                cout << setw(2) << setfill('0') << filtered[i]->date.month << "-";
                cout << setw(4) << setfill('0') << filtered[i]->date.year << '\n';
                cout << " ..: ";
                cout << setw(2) << setfill('0') << filtered[i]->time.min << ':';
                cout << setw(2) << setfill('0') << filtered[i]->time.hour << ':';
                cout << setw(2) << setfill('0') << filtered[i]->time.sec << '\n';
                cout << " ....: ";
                cout << filtered[i]->transaction.type << '\n';
                if (!strcmp(filtered[i]->transaction.type, ""))
                {
                    cout << " ......: ";
                    cout << filtered[i]->transaction.account << '\n';
                }
                else if (!strcmp(filtered[i]->transaction.type, ""))
                {
                    cout << " .......: ";
                    cout << filtered[i]->transaction.account << '\n';
                }
                cout << "...........: ";
                cout << filtered[i]->transaction.sum << '\n';
                cout << "......: ";
                cout << filtered[i]->purpose << '\n';
                cout << '\n';
            }
            delete[] filtered;
        }


        for (int i = 0; i < size; i++)
        {
            delete operations[i];
        }
    }
    catch (const char* error)
    {
        cout << error << '\n';
    }

    return 0;
}
