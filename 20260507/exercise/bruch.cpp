#include "bruch.h"

void Bruch::kuerze()
{
    int teiler = ggt(zaehler, nenner);

    zaehler /= teiler;
    nenner /= teiler;
}

void Bruch::normalisiere()
{
    kuerze();

    if (nenner < 0)
    {
        zaehler = -zaehler;
        nenner = -nenner;
    }
}

int Bruch::ggt(int a, int b)
{
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

Bruch::Bruch(const int pz, const int pn)
{
    zaehler = pz;
    nenner = (pn == 0) ? 1 : pn;
}

std::string Bruch::toString() const
{
    return std::to_string(zaehler) + '/' + std::to_string(nenner);
}

void Bruch::add(const Bruch bruch)
{
    // 1/2 + 4/5 = 1 * 5 / 2 * 5 + 4 * 2/5 * 2
    zaehler = zaehler * bruch.nenner + bruch.zaehler * nenner;
    nenner = nenner * bruch.nenner;

    normalisiere();
}

void Bruch::sub(const Bruch bruch)
{
    // 1/2 + 4/5 = 1 * 5 / 2 * 5 + 4 * 2/5 * 2
    zaehler = zaehler * bruch.nenner - bruch.zaehler * nenner;
    nenner = nenner * bruch.nenner;

    normalisiere();
}

void Bruch::mult(const Bruch bruch)
{
    zaehler = zaehler * bruch.zaehler;
    nenner = nenner * bruch.nenner;

    normalisiere();
}

void Bruch::div(const Bruch bruch)
{
    zaehler = zaehler * bruch.nenner;
    nenner = nenner * bruch.zaehler;

    normalisiere();
}