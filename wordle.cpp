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
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

/* void printNum()
{ //打表，计算单词数量
    ifstream importWord;
    char a[10240] = {0};
    for (size_t i = 0; i < 26; i++)
    {
        char aa = 'a' + i;
        if (aa == 'x')
        {
            continue;
        }
        string temp;
        temp = aa;
        string aaa = "dictionary_solution\\";
        string aaaa = ".in";
        aaa.append(temp);
        aaa.append(aaaa);
        importWord.open(aaa.c_str(), ios::in);
        // cout << aaa.c_str() << endl;
        if (!importWord)
        {
            std::cerr << "cannot open the file";
            continue;
        }
        int cnt = 0;
        while (importWord.getline(a, sizeof(a)))
        {
            cnt++;
        }
        cout << cnt << ',';
        importWord.close();
    }
} */

class WordInWordle
{
private:
    string word;
    int wordNum[25] = {140, 173, 198, 111, 72, 135, 115, 69, 34, 20, 20, 87, 107, 37, 41, 141, 23, 105, 365, 149, 33, 43, 82, 6, 3};

public:
    void init()
    {
        word.clear();
    }
    void wordSpawn()
    {
        ifstream importWord;
        char randomChar;
        char buf[10240] = {0};
        while (1)
        {
            if ((randomChar = 'a' + random(0, 25)) != 'x')
                break;
        }
        string randomCharS;
        randomCharS = randomChar;
        importWord.open("dictionary_solution\\" + randomCharS + ".in", ios::in);
        int randomNum = random(1, wordNum[randomChar - 'a']);
        if (!importWord)
        {
            std::cerr << "cannot open the file";
        }
        int cnt = 0;
        while (importWord.getline(buf, sizeof(buf)))
        {
            if (cnt++ == randomNum)
            {
                word = buf;
                break;
            }
        }
        importWord.close();
        cout << word << endl;
    }
};

void printWordle()
{
    system("cls");
    cout << "=================================================================" << endl;
    cout << "|                                                               |" << endl;
    cout << "|   $$\\      $$\\                           $$\\ $$\\          \t|" << endl;
    cout << "|   $$ | $\\  $$ |                          $$ |$$ |             |" << endl;
    cout << "|   $$ |$$$\\ $$ | $$$$$$\\   $$$$$$\\   $$$$$$$ |$$ | $$$$$$\\     |" << endl;
    cout << "|   $$ $$ $$\\$$ |$$  __$$\\ $$  __$$\\ $$  __$$ |$$ |$$  __$$\\    |" << endl;
    cout << "|   $$$$  _$$$$ |$$ /  $$ |$$ |  \\__|$$ /  $$ |$$ |$$$$$$$$ |   |" << endl;
    cout << "|   $$$  / \\$$$ |$$ |  $$ |$$ |      $$ |  $$ |$$ |$$   ____|   |" << endl;
    cout << "|   $$  /   \\$$ |\\$$$$$$  |$$ |      \\$$$$$$$ |$$ |\\$$$$$$$\\    |" << endl;
    cout << "|   \\__/     \\__| \\______/ \\__|       \\_______|\\__| \\_______|   |" << endl;
    cout << "|                                                               |" << endl;
    cout << "=================================================================" << endl;

    //以下是输出用户记录
}

int main()
{
    WordInWordle word;
    //生成目标单词
    word.init();
    word.wordSpawn();
    
    system("pause");
    return 0;
}