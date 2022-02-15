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
        cout << "�������� 1 ���� ������ ���������� ����: "; 
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
void Input(string filee1)//���������� ������� ����� �������
{                      
    string s;
    ofstream file1(filee1);
    bool flag = true;
    char symbol = 19;//Ctrl + S - ������ ���������� �����
    while (flag)//���� ����� ���������� ���� �� �� ����� ������ ������������ ������
    { 
        getline(cin, s);//������ ����� � ���
        if (s.find(symbol) != string::npos)//����� �������
        {
            flag = false;
            s.erase(s.find(symbol), 1);//�������� �������
        }
        if (!s.empty())//������ ���� � ���� ���� �� �� ����
            file1 << s << endl;
    }
    file1.close();//�������� �����
}
void Output(string filee) 
{//���� ����� ������� ����� � �������                   
    cout << endl;
    string s;//���������� ��� ����������� �����
    ifstream file(filee);
    while (!file.eof())//�������� �� ����� �����
    {                      
        getline(file, s);//������ ������ � ����������
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
    while (!file1.eof())//�������� �� ����� �����
    {
        getline(file1, s);//������ ����� � ������� ����� � ���������� ����������
        if (s != "")
        {
            snew = to_string(k) + " " + s + " " + to_string(s.size());
            k++;
            file2 << snew << endl;//������ ����� ������ � ����� ����
        }
    }
    file1.close();
    file2.close();
}

void Add(string f)//����������� ����� � ����� ������� �����
{
    ofstream file(f, ios::app);
    string s;
    bool flag = true;//����������� �������
    char symbol = 19;//Ctrl + S - ������ ���������� �����
    while (flag)//����������� ���� �� ��������� ������
    {
        getline(cin, s);//������ ������ �����
        if (s.find(symbol) != string::npos)//����� ������� � ������
        {
            flag = false;
            s.erase(s.find(symbol), 1);//�������� �������
        }
        if (!s.empty())//������ ������ � ���� ���� ��� �� ������
            file << s << endl;
    }
    file.close();
}