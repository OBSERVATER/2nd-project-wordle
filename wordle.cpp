#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

#define GREEN 303
#define GREY 399
#define YELLOW 367
#define INIT 7

// 303(green),399(grey),367(y),7(init)
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
    return max < min ? 0 : (rand() % (max - min + 1)) + min;
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
    vector<string> input;
    int wordNum[25] = {140, 173, 198, 111, 72, 135, 115, 69, 34, 20, 20, 87, 107, 37, 41, 141, 23, 105, 366, 149, 33, 43, 82, 6, 3};
    int letterCondition[6][5]; // COLOR数字
    bool isWin = false;

public:
    void init()
    {
        word.clear();
        input.clear();
        memset(letterCondition, 0, sizeof(letterCondition));
        isWin = false;
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
    }

    void wordInput(string in,int cnt)
    {
        transform(in.begin(), in.end(), in.begin(), ::toupper);
        input.push_back(in);
        transform(in.begin(), in.end(), in.begin(), ::tolower);
        
        if (in.compare(word) == 0)
        {
            for (size_t i = 0; i < 5; i++)
                letterCondition[cnt][i] = GREEN;
            isWin = true;
        }
        else
        {
            for (size_t i = 0; i < 5; i++)
            {
                int findNum = word.find(in[i]);
                if (findNum == -1)
                {
                    letterCondition[cnt][i] = GREY;
                }
                else if (findNum != i)
                {
                    letterCondition[cnt][i] = YELLOW;
                }
                else
                {
                    letterCondition[cnt][i] = GREEN;
                }
            }
        }
    }

    int getInputNum()
    {
        return input.size();
    }

    int getLetterCondition(int i,int j)
    {
        return letterCondition[i][j];
    }

    string getInput(int i)
    {
        return input[i];
    }

    bool getIsWin(){
        return isWin;
    }
    
    string getWord(){
        return word;
    }
};

bool wordJudgeLegal(string in)
{
    if (in.size() != 5)
    {
        cout << "The amount of letter is not 5!" << endl
             << endl;
        return false;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            if (!((in[i] >= 'a' && in[i] <= 'z') || (in[i] >= 'A' && in[i] <= 'Z')))
            {
                cout << "Found illegal input in the word!" << endl
                     << endl;
                return false;
            }
        }
        transform(in.begin(), in.end(), in.begin(), ::tolower);

        string temp;
        temp = in[0];
        ifstream importWord;
        char buf[1024 * 16] = {0};
        string aaa = "dictionary_all\\";
        string aaaa = ".ina";
        aaa.append(temp);
        aaa.append(aaaa);
        importWord.open(aaa.c_str(), ios::in);
        if (!importWord)
            std::cerr << "cannot open the file";
        while (importWord.getline(buf, sizeof(buf)))
        {
            string compareBuf;
            compareBuf = buf;
            if (in.compare(compareBuf) == 0)
                return true;
        }
        cout << "Word not found." << endl
             << endl;
        return false;
    }
}

void printWordle(WordInWordle word)
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
    cout << "=================================================================" << endl
         << endl;

    //以下是输出用户记录
    cout << word.getWord() << endl;
    if (word.getInputNum() != 0)
    {
        cout << "=====================" << endl;
        for (size_t i = 0; i < word.getInputNum(); i++)//第几个输入单词
        {
            for (size_t k = 0; k < 3; k++)//行数
            {
                cout << '|';
                for (size_t j = 0; j < 5; j++)//第几格
                {
                    color(word.getLetterCondition(i,j));
                    if (k != 1)
                        cout << "   ";
                    else
                    {
                        cout << ' ' << word.getInput(i)[j] << ' ';
                    }
                    color(INIT);
                    cout << '|';
                }
                cout << endl;
            }
            cout << "=====================" << endl;
        }

    }
    if (word.getIsWin())
    {
        cout << "\n\n" << "======================================================" << endl;
        cout << "You win! Congratulation!" << endl;
        cout << "You guess out the hidden word within " << word.getInputNum() << " tries!" << endl;
        cout << "======================================================" << "\n\n";
        system("pause");
    }
    
}

void runFrame()
{
    WordInWordle word;
    //生成目标单词
    word.init();
    word.wordSpawn();
    for (int i = 0; i < 6; i++)
    {
        printWordle(word);
        if (word.getIsWin()) break;
        string in;
        do
        {
            cout << "> ";
            cin >> in;
        } while (!wordJudgeLegal(in));
        word.wordInput(in,i);
    }

    if (!word.getIsWin())
    {
        cout << "\n\n" << "======================================================" << endl;
        cout << "You lose!" << endl;
        cout << "The correct word is \"" << word.getWord() << "\"" << endl;
        cout << "======================================================" << "\n\n";
        system("pause");
    }
    
}

int main()
{
    while (1)
    {
        system("cls");
        {
            cout << "======================================================================" << endl
                 << endl;
            cout << "\t\t\tWelcome to Wordle." << endl
                 << endl;
            cout << "----------------------------------------------------------------------" << endl;
            cout << "In this game, you need to guess the 5-letter hidden word in 6 tries, " << endl;
            cout << "the color of the letters changes to show how close you are." << endl;
            cout << "For example:\t";
        }
        {
            color(GREY);
            cout << 'T';
            color(YELLOW);
            cout << 'A';
            color(GREY);
            cout << 'B';
            color(YELLOW);
            cout << 'L';
            color(GREEN);
            cout << 'E';
            color(INIT);
            cout << endl;
        }
        {
            color(GREY);
            cout << "\nT,B";
            color(INIT);
            cout << " are not in the target word at all." << endl;
            color(YELLOW);
            cout << "A,L";
            color(INIT);
            cout << " are in the target word but in wrong spot." << endl;
            color(GREEN);
            cout << 'E';
            color(INIT);
            cout << " is in the word and in the correct spot.\n"
                 << endl;
            cout << "If you find out all the matching letters like: ";
            color(GREEN);
            cout << "FLAME";
            color(INIT);
            cout << "\nthen you got it!" << endl;
            cout << "----------------------------------------------------------------------" << endl;
        }
        {
            cout << "Now, press any button to start!!!" << endl;
            cout << "======================================================================" << endl;
        }
        system("pause");
        runFrame();
    }

    return 0;
}