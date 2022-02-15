#include<iostream>
#include<istream>
#include<fstream>
#include<string>
using namespace std;
void Input(string file1);
void Output(string file);
void NewF(string file1, string filee);
void Add(string f);
int main()
{
    setlocale(LC_ALL, "ru");
    char sym = '1';
    string f1 = "file1.txt";
    string f2 = "file2.txt";
    Input(f1);
    Output(f1);
    NewF(f1, f2);
    Output(f2);
    while (sym == '1')
    {
        cout << "Поставте 1 если хотите продолжить ввод: "; 
        cin >> sym;
        if (sym == '1')
        {
            Add(f1);
            Output(f1);
            NewF(f1, f2);
            Output(f2);
        }
    }
}
void Input(string filee1)//Заполнение первого файла данными
{                      
    string s;
    ofstream file1(filee1);
    bool flag = true;
    char symbol = 19;//Ctrl + S - символ завершения файла
    while (flag)//Цикл будет выполнятся пока не не будет введен опреедленный символ
    { 
        getline(cin, s);//Запись рядка в фал
        if (s.find(symbol) != string::npos)//Поиск символа
        {
            flag = false;
            s.erase(s.find(symbol), 1);//Удаление символа
        }
        if (!s.empty())//Запись ряда в файл если он не пуст
            file1 << s << endl;
    }
    file1.close();//Закрытие файла
}
void Output(string filee) 
{//Вивід вмісту першого файла у консоль                   
    cout << endl;
    string s;//Переменная для запоминания рядка
    ifstream file(filee);
    while (!file.eof())//Проверка на конец файла
    {                      
        getline(file, s);//Запись строки в переменную
        cout << s << endl;
    }
    file.close();
}

void NewF(string filee1, string filee2) 
{
    string s, snew;
    int k = 1;
    ifstream file1(filee1);
    ofstream file2(filee2);
    while (!file1.eof())//Проверка на конец файла
    {
        getline(file1, s);//Чтение строк с первого файла и присвоение переменной
        if (s != "")
        {
            snew = to_string(k) + " " + s + " " + to_string(s.size());
            k++;
            file2 << snew << endl;//Запись новой строки в новый файл
        }
    }
    file1.close();
    file2.close();
}

void Add(string f)//Дописування рядків у кінець першого файла
{
    ofstream file(f, ios::app);
    string s;
    bool flag = true;//Присутствие символа
    char symbol = 19;//Ctrl + S - символ завершения файла
    while (flag)//Выполняется пока не обнуружен символ
    {
        getline(cin, s);//Запись строки файла
        if (s.find(symbol) != string::npos)//Поиск символа в строке
        {
            flag = false;
            s.erase(s.find(symbol), 1);//Удаление символа
        }
        if (!s.empty())//Запись строки в файл если она не пустая
            file << s << endl;
    }
    file.close();
}