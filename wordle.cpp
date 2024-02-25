#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void color(int a)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), a);
}

void color_list()
{
    for (int i = 0; i < 8192; i++)
    {
        color(i);
        cout << i << endl;
    }
    system("pause");
}

int random(int min, int max)
{
    srand(time(0)) return (rand() % (max - min + 1)) + min;
}
int main()
{
}