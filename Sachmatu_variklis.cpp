#include <bits/stdc++.h>
using namespace std;

string FEN_eilute;
char Lenta[8][8];
vector<string> Legalus_ejimai;

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

void Spausdink() {
    for (int i = 0; i < 8; i++){
        for (int y = 0; y < 8; y++) {
            cout << Lenta[i][y];
        }
        cout << "\n";
    }
}


void Lentos_generavimas() {

    int FEN_eilute_nr = 0;
    int X = 0;
    int Y = 0;

    for (int i = 0; i < 8; i++) {

        if (FEN_eilute[FEN_eilute_nr] >= 'A' && FEN_eilute[FEN_eilute_nr] <= 'z') {

            for (int y = 0; y < 8; y++) {
                if (FEN_eilute[FEN_eilute_nr] >= 'A' && FEN_eilute[FEN_eilute_nr] <= 'z') {
                    Lenta[X][Y] = FEN_eilute[FEN_eilute_nr];
                    FEN_eilute_nr++;
                    Y++;
                }
                else {
                    char a = FEN_eilute[FEN_eilute_nr];
                    int sk = a - '0';
                    FEN_eilute_nr++;
                    y += sk - 1;

                    for (int z = 0; z < sk; z++) {
                        Lenta[X][Y] = '.';
                        Y++;
                    }
                }
            }
        }
        else if (FEN_eilute[FEN_eilute_nr] >= '1' && FEN_eilute[FEN_eilute_nr] <= '9') {

            int Uzpildyti_laukeliai = 0;
            while (Uzpildyti_laukeliai < 8) {

                char a = FEN_eilute[FEN_eilute_nr];

                if (a >= 'A' && a <= 'z') {
                    Lenta[X][Y] = FEN_eilute[FEN_eilute_nr];
                    Y++;
                    FEN_eilute_nr++;
                    Uzpildyti_laukeliai++;
                }
                else {
                    int sk = a - '0';
                    for (int y = 0; y < sk; y++) {
                        Lenta[X][Y] = '.';
                        Y++;
                    }
                    FEN_eilute_nr++;
                    Uzpildyti_laukeliai += sk;
                }
            }
        }
        FEN_eilute_nr++;
    }
}



extern "C"

void Ejimo_generavimas() {

    /// Pasiemame lentos FEN eilute
    FEN_eilutes_gavimas();

    /// Surandame ant lentos esanciu figuru skaiciu
    Figuru_skaiciaus_radimas();

    /// Sachmatu lenteles generavimas
    Lentos_generavimas();

    /// Atspausdink lenta
    Spausdink();

    /// Perduodame geriausio ejimo FEN eilute pyhton programai
    ofstream fr("rezultatai.txt");
    fr << FEN_eilute;
    return;
}

