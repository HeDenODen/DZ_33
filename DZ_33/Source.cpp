#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <Windows.h>
#define MAX_SIZE 128

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    //1
    const char* path = "Text.txt";

    FILE* myFile;

    char str[MAX_SIZE];
    int max = 0;

    if (fopen_s(&myFile, path, "r") != NULL)
        cout << "The file cannot be opened";
    else {
        while (fgets(str, sizeof(str), myFile) != NULL)
        {
            if (strlen(str) > max)
                max = strlen(str);
        }
    }
    cout << "Длина самой длинной строки: " << max << endl;
    if (fclose(myFile) == EOF)
        cout << "\nThis file could not be closed!" << endl;
    else
        cout << "\nThis file is closed!" << endl;
    
    
    //2
    const char* path2 = "Text.txt";

    FILE* myFile2;

    char s[MAX_SIZE];
    cout << "Введите слово для поиска: ";
    cin.getline(s, 128, '\n');
    int c = 0;
    char word[MAX_SIZE];

    if (fopen_s(&myFile2, path2, "r") != NULL)
        cout << "The file cannot be opened";
    else {
        while (fscanf(myFile2, "%s", word) == 1) {
            if (strcmp(s, word) == 0)
                c++;
        }
    }
    cout << "Количество слов " << s << ": " << c << endl;
    if (fclose(myFile2) == EOF)
        cout << "\nThis file could not be closed!" << endl;
    else
        cout << "\nThis file is closed!" << endl;
    
    return 0;
}
