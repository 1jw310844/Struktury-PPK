
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cassert>

using namespace std;

enum class Typ {Warsztatowe, Rzemieslnicze, Problemowe, Projektowe};
const char* TYP[4] = { "Warsztatowe", "Rzemieslnicze", "Problemowe", "Projektowe" };


struct Przedmiot{};
struct Zadania
{
    char tresc[2001];
    double maks;
    Typ typ;
    Przedmiot* przedmiot;
};

void wypelnijInstancje(Zadania &z, const char* t, double m, Typ ty, Przedmiot* p)
{
    strncpy_s(z.tresc, t, 2000);
    if (m >= 0.0 && m <= 5.0)
    {
        z.maks = m;
    }
    else {
        throw invalid_argument("Nieprawidlowa liczba punktow");
    }
    z.typ = ty;
    z.przedmiot = p;
}
void wypiszInstancje(Zadania& z)
{
    cout << "Tresc zadania: " << z.tresc << endl
        << "Maksymalna liczba punktow: " << fixed << setprecision(1) <<z.maks << endl
        << "Typ zadania: " << TYP[(int)(z.typ)] << endl << endl;
}
Zadania* konkretnaInstancja(Zadania* tablica, int rozmiar, double min, double max)
{
    assert(min <= max && "Przedzial punktowy jest nieprawidlowy!");

    Zadania* najdluzszeZadanie = nullptr;
    size_t maxDlugosc = 0;

    for (int i = 0; i < rozmiar; ++i) {
        if (tablica[i].maks >= min && tablica[i].maks <= max) {
            size_t dlugosc = strlen(tablica[i].tresc);
            if (dlugosc > maxDlugosc) {
                maxDlugosc = dlugosc;
                najdluzszeZadanie = &tablica[i];
            }
        }
    }
    if (najdluzszeZadanie == nullptr) {
        throw runtime_error("Brak zadania w zadanym przedziale punktowym");
    }
    return najdluzszeZadanie;
}
void test1()
{
    Zadania z1, z2, z3;
    Przedmiot p1, p2;
    wypelnijInstancje(z1, "Zadanie z kurwy wziete", (5.0), Typ::Projektowe, &p1);
    wypelnijInstancje(z2, "Zadanie z kurwy wzieteeeeeeeeeeeeeeeee", (5.0), Typ::Rzemieslnicze, &p2);
    wypelnijInstancje(z3, "niewiem", (4.0), Typ::Projektowe, &p2);
    Zadania tablica[3] = { z1, z2, z3 };
    Zadania* prawidlowaInstancja = konkretnaInstancja(tablica, 3, 2.0, 5.0);
    try {
        if (prawidlowaInstancja == &tablica[1])
        {
            cerr << "Test OK!" << endl;
        }
        else
        {
            cerr << "Test FAIL!" << endl;
            throw runtime_error("");
        }
    }
    catch (...)
    {
        cerr << "Zlapano wyjatek nieoczekiwany";
    } 
}
void test2()
{
    Zadania z1, z2, z3;
    Przedmiot p1, p2;
    wypelnijInstancje(z1, "Zadanie z kurwy wziete", (5.0), Typ::Projektowe, &p1);
    wypelnijInstancje(z2, "", (5.0), Typ::Rzemieslnicze, &p2);
    wypelnijInstancje(z3, "niewiem", (4.0), Typ::Projektowe, &p2);
    Zadania tablica[3] = { z1, z2, z3 };
    try {
        Zadania* prawidlowaInstancja = konkretnaInstancja(tablica, 3, 2.0, 3.0);
    }
    catch (runtime_error)
    {
        cerr << "Test OK!";
    }
    catch (...)
    {
        cerr << "Zlapano wyjatek nieoczekiwany";
    }

}
int main()
{
    Zadania z1, z2, z3;
    Przedmiot p1, p2;
    wypelnijInstancje(z1, "Zadanie z kurwy wziete", (5.0), Typ::Projektowe, &p1);
    wypelnijInstancje(z2, "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaax", (5.0), Typ::Rzemieslnicze, &p2);
    wypelnijInstancje(z3, "niewiem", (4.0), Typ::Projektowe, &p2);
    wypiszInstancje(z1);
    wypiszInstancje(z2);
    wypiszInstancje(z3);
    test1();
    test2();
}
