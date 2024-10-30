#include <iostream>
using namespace std;

void wyswietlPlansze(char tablica[3][3])
{
    cout << tablica[0][0] << tablica[0][1] << tablica[0][2] << endl;
    cout << tablica[1][0] << tablica[1][1] << tablica[1][2] << endl;
    cout << tablica[2][0] << tablica[2][1] << tablica[2][2] << endl;
}

bool czyWolneMiejsce(char tab[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tab[i][j] == '-')
            {
                return true;
            }
        }
    }
    return false;
}

char ktoWygral(char tab[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (tab[i][0] == tab[i][1] && tab[i][1] == tab[i][2])
        {
            char znak = tab[i][0];
            if (znak != '-')
            {
                return znak;
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        if (tab[0][i] == tab[1][i] && tab[1][i] == tab[2][i])
        {
            char znak = tab[0][i];
            if (znak != '-')
            {
                return znak;
            }
        }
    }

    if (tab[0][0] == tab[1][1] && tab[1][1] == tab[2][2])
    {
        char znak = tab[0][0];
        return znak;
    }

    if (tab[2][0] == tab[1][1] && tab[1][1] == tab[0][2])
    {
        char znak = tab[1][1];
        return znak;
    }

    return '-';
}

bool czyMoznaDalej(char tab[3][3])
{
    bool wolneMiejsce = czyWolneMiejsce(tab);
    char wygralGracz = ktoWygral(tab);

    return wolneMiejsce == true && wygralGracz == '-';
}

char nastepnyGracz(char biezacyGracz)
{
    if (biezacyGracz == 'O')
    {
        return 'X';
    }
    else
    {
        return 'O';
    }
}

int main()
{

    int wiersz;
    int kolumna;
    char kolko = 'O', krzyzyk = 'X';
    char gracz = kolko;

    char plansza[3][3] = {
        {'-', '-', '-'},
        {'-', '-', '-'},
        {'-', '-', '-'}};

    wyswietlPlansze(plansza);

    while (czyMoznaDalej(plansza) == true)
    {
        cout << "Które pole wybierasz?: ";
        cin >> wiersz;
        cin >> kolumna;

        plansza[wiersz][kolumna] = gracz;

        wyswietlPlansze(plansza);

        gracz = nastepnyGracz(gracz);
    }

    return 0;
}
