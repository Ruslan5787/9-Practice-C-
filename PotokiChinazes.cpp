#include <iostream>
#include <windows.h>
#include <process.h>

using namespace std;

int res;

UINT WINAPI getArraySum(void *array) {
    int sum = 0;

    for (int i = 0; i < 7; i++)
    {
        sum += ((int*)array)[i];
    }

    cout << "Сумма масива - " << sum;

    return sum;
}

int main()
{
    INT numbers[7] = { 6, 8, 1, 4, 9, 2, -100 };

    HANDLE hThread;
    UINT IDThread;

    hThread = (HANDLE)_beginthreadex(NULL, 0, getArraySum, numbers, 0, &IDThread);

    if (hThread == NULL) return GetLastError();

    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}
