#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
fstream odczyt;
int c, x, w;
int k=0;
string a;

bool sprawdzpali (string s1) //funkcja sprawdzaj¹ca czy to jest palingram.
{
    int dl=s1.size();
    for (int i=0; i<dl/2; i++)
        if (s1[i]!=s1[dl-i-1])
            return false;
    return true;
}

void sprawdzb()
{
    odczyt.open("dane.txt",ios::in);

    while(odczyt.good())
    {
        odczyt >> a;
        if(sprawdzpali(a)==true && a[0]=='B')
        {

            c++;
            k++;
            cout <<k<<"."<< a << endl;
        }
    }
    cout <<"Liczba ich wynosi:"<<c;
    odczyt.close();
}

void sprawdzparzyste()
{
    odczyt.open("dane.txt",ios::in);

    while(odczyt.good())
    {
        odczyt >> a;
        if(sprawdzpali(a)==true)
        {
            int dlugosc=a.length();
            if(dlugosc%2==0)
            {
                k++;
                cout <<k<<"."<< a << endl;
                c++;

            }
        }
    }
    cout <<"Liczba ich wynosi:"<<c;
    odczyt.close();
}

void sprawdznieparzyste()
{
    odczyt.open("dane.txt",ios::in);

    while(odczyt.good())
    {
        odczyt >> a;
        if(sprawdzpali(a)==true)
        {
            int dlugosc=a.length();
            if(dlugosc%2!=0)
            {
                k++;
                cout <<k<<"."<< a << endl;
                c++;

            }
        }
    }
    cout <<"Liczba ich wynosi:"<<c;
    odczyt.close();
}

void sprawdztrzya()
{
    odczyt.open("dane.txt",ios::in);

    while(odczyt.good())
    {
        odczyt >> a;
        if(sprawdzpali(a)==true)
        {
            if(count(a.begin(), a.end(), 'A')>=3)
            {
                k++;
                cout <<k<<"."<< a << endl;
                c++;

            }
        }
    }
    cout<<"Liczba ich wynosi:"<<c;
    odczyt.close();
}


int main()
{
    cout << "Wprowadz 1 jak chcesz zobaczyc palindromy zaczynajace sie na B jak Bartosz i ich liczbe" << endl;
    cout << "Wprowadz 2 jak chcesz zobaczyc palindromy parzyste literami i ich liczbe" << endl;
    cout << "Wprowadz 3 jak chcesz zobaczyc palindromy nieparzyste literami i ich liczbe" << endl;
    cout << "wprowadz 4 jak chcesz zobaczyc palondromy, ktore zawieraja trzy lub wiecej litery A i ich liczbe" << endl;
    cout << "Wprowadz liczbe z menu:";
    cin >> w;
    switch(w)
    {
    case 1:
        sprawdzb();
        break;
    case 2:
        sprawdzparzyste();
        break;
    case 3:
        sprawdznieparzyste();
        break;
    case 4:
        sprawdztrzya();
        break;
    default:
        cout << "Wybrales zly numer!!!";
        break;
    }
    return 0;
}
