#include <iostream>
#include <cstring>
#include <cassert>
#include <stdexcept>
using namespace std;

using tekst = char[51];
enum class Typ { Szklo, PET, stal };
const char* TYP[3] = { "Szklo", "PET", "Stal" };

struct Producent
{
    tekst nazwa;
};

struct Butelka
{
    tekst opis;
    int pojemnosc;
    Typ typ;
    Producent* producent;
};

void wypelnijInstancje(Butelka& b, const char* o, int p, Typ t, Producent* pr)
{
    strncpy_s(b.opis, o, 50);
    if (p >= 100 && p <= 2000)
    {
        b.pojemnosc = p;
    }
    else
    {
        throw invalid_argument("");
    }
    b.typ = t;
    b.producent = pr;
}
void wypiszInstancje(Butelka& b)
{
    cout << "Nazwa producenta: " << b.producent->nazwa << endl << "Opis: " << b.opis
        << endl << "Rodzaj butelki: " << TYP[(int)b.typ] << endl
        << "Pojemnosc: " << b.pojemnosc << " ml" << endl;
}

Butelka* konkretnaButelka(Butelka* b, int size, Typ t)
{
    assert(size > 0);
    for (int i = 0; i < size; i++)
    {
        if (b[i].typ == t)
        {
            return &b[i];
        }
    }
    throw runtime_error("Nie znaleziono butelki o podanym typie");
}

void test1()
{
    Producent p1, p2, p3;
    strncpy_s(p1.nazwa, "Zywiec Zdroj", 50);
    strncpy_s(p2.nazwa, "Saguaro", 50);
    strncpy_s(p3.nazwa, "Cisowianka", 50);
    Butelka b1, b2, b3;
    wypelnijInstancje(b1, "Wesola", 1500, Typ::stal, &p1);
    wypelnijInstancje(b2, "Llalalal", 1300, Typ::Szklo, &p2);
    wypelnijInstancje(b3, "Bembel", 1200, Typ::PET, &p3);
    Butelka tablicaButelek[3] = { b1, b2, b3 };
    try
    {
        Butelka* wyszukana = konkretnaButelka(tablicaButelek, 4, Typ::Szklo);
        if (wyszukana == &tablicaButelek[1])
        {
            cerr << "Test OK!";
        }
        else {
            cerr << "Test FAIL!";
        }
    }
    catch (...)
    {
        cerr << "Nieoczekiwany wyjatek";
    }
    
}

void test2()
{
    Producent p1, p2, p3;
    strncpy_s(p1.nazwa, "Zywiec Zdroj", 50);
    strncpy_s(p2.nazwa, "Saguaro", 50);
    strncpy_s(p3.nazwa, "Cisowianka", 50);
    Butelka b1, b2, b3;
    wypelnijInstancje(b1, "Wesola", 1500, Typ::stal, &p1);
    wypelnijInstancje(b2, "Llalalal", 1300, Typ::Szklo, &p2);
    wypelnijInstancje(b3, "Bembel", 1200, Typ::Szklo, &p3);
    Butelka tablicaButelek[3] = { b1, b2, b3 };

    try
    {
        Butelka* wyszukana = konkretnaButelka(tablicaButelek, 3, Typ::PET);
        cerr << "Test FAIL!";
    }
    catch (runtime_error)
    {
        cerr << "Test OK!";
    }
    catch (...)
    {
        cerr << "Test FAIL!";
    }
}
int main()
{
    Producent p5;
    strncpy_s(p5.nazwa, "12345678901234567890123456789012345678901234567890", 50);
    Butelka b5;
    wypelnijInstancje(b5, "Niegazowana", 1500, Typ::PET, &p5);
    wypiszInstancje(b5);
    cout << endl;
    test1();
    cout << endl;
    test2();
}
