#include <bits/stdc++.h>
using namespace std;

string FEN_eilute;

// Issirasom kiekvienos figuros ivertinima visose lentos vietose
int Pestininkas_Lentele[8][8] = {
    0, 0, 0, 0, 0, 0, 0, 0,
    5, 10, 10, -20, -20, 10, 10, 5,
    5, -5, -10, 0, 0, -10, -5, 5,
    0, 0, 0, 20, 20, 0, 0, 0,
    5, 5, 10, 25, 25, 10, 5, 5,
    10, 10, 20, 30, 30, 20, 10, 10,
    50, 50, 50, 50, 50, 50, 50, 50,
    0, 0, 0, 0, 0, 0, 0, 0};

int Zirgas_Lentele[8][8] = {
    -50, -40, -30, -30, -30, -30, -40, -50
    -40, -20, 0, 5, 5, 0, -20, -40,
    -30, 5, 10, 15, 15, 10, 5, -30,
    -30, 0, 15, 20, 20, 15, 0, -30,
    -30, 5, 15, 20, 20, 15, 5, -30,
    -30, 0, 10, 15, 15, 10, 0, -30,
    -40, -20, 0, 0, 0, 0, -20, -40,
    -50, -40, -30, -30, -30, -30, -40, -50};

int Rikis_Lentele[8][8] = {
    -20, -10, -10, -10, -10, -10, -10, -20,
    -10, 5, 0, 0, 0, 0, 5, -10,
    -10, 10, 10, 10, 10, 10, 10, -10,
    -10, 0, 10, 10, 10, 10, 0, -10,
    -10, 5, 5, 10, 10, 5, 5, -10,
    -10, 0, 5, 10, 10, 5, 0, -10,
    -10, 0, 0, 0, 0, 0, 0, -10,
    -20, -10, -10, -10, -10, -10, -10, -20};

int Bokstas_Lentele[8][8] = {
    0, 0, 0, 5, 5, 0, 0, 0,
    -5, 0, 0, 0, 0, 0, 0, -5,
    -5, 0, 0, 0, 0, 0, 0, -5,
    -5, 0, 0, 0, 0, 0, 0, -5,
    -5, 0, 0, 0, 0, 0, 0, -5,
    -5, 0, 0, 0, 0, 0, 0, -5,
    5, 10, 10, 10, 10, 10, 10, 5,
    0, 0, 0, 0, 0, 0, 0, 0};

int Karaliene_Lentele[8][8] = {
    -20, -10, -10, -5, -5, -10, -10, -20,
    -10, 0, 0, 0, 0, 0, 0, -10,
    -10, 5, 5, 5, 5, 5, 0, -10,
    0, 0, 5, 5, 5, 5, 0, -5,
    -5, 0, 5, 5, 5, 5, 0, -5,
    -10, 0, 5, 5, 5, 5, 0, -10,
    -10, 0, 0, 0, 0, 0, 0, -10,
    -20, -10, -10, -5, -5, -10, -10, -20};

int Karalius_Lentele[8][8] = {
    20, 30, 10, 0, 0, 10, 30, 20,
    20, 20, 0, 0, 0, 0, 20, 20,
    -10, -20, -20, -20, -20, -20, -20, -10,
    -20, -30, -30, -40, -40, -30, -30, -20,
    -30, -40, -40, -50, -50, -40, -40, -30,
    -30, -40, -40, -50, -50, -40, -40, -30,
    -30, -40, -40, -50, -50, -40, -40, -30,
    -30, -40, -40, -50, -50, -40, -40, -30};

void Figuru_skaiciaus_radimas() {

    // Susirandam koks skaicius kiekvienos figuros yra ant lentos
    size_t bp = count(FEN_eilute.begin(), FEN_eilute.end(), 'P');
    size_t jp = count(FEN_eilute.begin(), FEN_eilute.end(), 'p');
    size_t bz = count(FEN_eilute.begin(), FEN_eilute.end(), 'K');
    size_t jz = count(FEN_eilute.begin(), FEN_eilute.end(), 'k');
    size_t br = count(FEN_eilute.begin(), FEN_eilute.end(), 'R');
    size_t jr = count(FEN_eilute.begin(), FEN_eilute.end(), 'r');
    size_t bb = count(FEN_eilute.begin(), FEN_eilute.end(), 'B');
    size_t jb = count(FEN_eilute.begin(), FEN_eilute.end(), 'b');
    size_t bk = count(FEN_eilute.begin(), FEN_eilute.end(), 'Q');
    size_t jk = count(FEN_eilute.begin(), FEN_eilute.end(), 'q');
}

void FEN_eilutes_gavimas() {

    /// Pasiemam FEN eilute is python programos
    ifstream fd("duota.txt");

    for (int i = 0; i < 6; i++) {
        string s;
        fd >> s;
        FEN_eilute += s;

        if (i != 5) {
            FEN_eilute += " ";
        }
    }

    return;
}




extern "C"

void Ejimo_generavimas() {

    /// Pasiemame lentos FEN eilute
    FEN_eilutes_gavimas();

    /// Surandame ant lentos esanciu figuru skaiciu
    Figuru_skaiciaus_radimas();

    /// Perduodame geriausio ejimo FEN eilute pyhton programai
    ofstream fr("rezultatai.txt");
    fr << FEN_eilute;
    return;
}

