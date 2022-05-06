#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M;
    int N;

    ifstream fd("duota.txt");
    ofstream fr("rezultatai.txt");

    /// Duomenu nuskaitymas
    fd >> M;

    /// Prdadedamas faktorialo ieskojimas
    int Faktorialas = 2;
    double Faktorialo_reiksme = 1;
    int Skaitmenu_sk = 0;
    int Skaitmenu_suma = 0;

    bool Skaiciaus_nera = true;

    while (Skaitmenu_sk <= M) {

        /// Apskaiciuojame faktorialo reiksme
        Faktorialo_reiksme = Faktorialo_reiksme * Faktorialas;

        /// Apskaiciuojame faktorialo reiksmes skaitmenu skaiciu
        Skaitmenu_sk = 0;
        Skaitmenu_sk = (log10(Faktorialo_reiksme) + 1);

        /// Jei skaitmenu suma atitinka salyga, apskaiciuojame faktoriala bei jo reiksme ir suskaiciuojame faktorialo reiksmes skaitmenu suma
        if (Skaitmenu_sk == M) {
            N = Faktorialas;
            Skaiciaus_nera = false;
        }

        /// Faktorialo reiksme padidiname vienetu
        Faktorialas++;
    }


    /// Duomenu spausdinimas
    if (Skaiciaus_nera) {
        fr << "NĖRA\n";
        return 0;
    }


    /// Surandam tikraja faktorialo reiksme
    vector<int> Skaicius;
    int N_dydis;

    string N_STRING;
    N_STRING = to_string(N);
    N_dydis = N_STRING.length();

    for (int i = 0; i < N_dydis; i++) {
        int x1;
        x1 = N_STRING[i] - '0';
        Skaicius.push_back(x1);
    }

    int Dauginamasis = N-1;
    int Skaiciaus_dydis;


    while (Dauginamasis != 1) {

        int Mintyse = 0;

        ///// Sandauga 1 /////
        vector<int> Sandauga_1_VECTOR;
        Skaiciaus_dydis = Skaicius.size();
        int Dauginamojo_antras_sk = Dauginamasis % 10;


        for (int i = 0; i < Skaiciaus_dydis; i++) {

            int Sandauga;
            Sandauga = Dauginamojo_antras_sk * Skaicius[Skaiciaus_dydis-i-1];
            Sandauga += Mintyse;
            Mintyse = 0;

            while (Sandauga >= 10) {
                Sandauga -= 10;
                Mintyse++;
            }

            Sandauga_1_VECTOR.insert(Sandauga_1_VECTOR.begin(), Sandauga);

            if (i == Skaiciaus_dydis-1 && Mintyse > 0) {
                Sandauga_1_VECTOR.insert(Sandauga_1_VECTOR.begin(), Mintyse);
            }

        }


        ///// Sandauga 2 /////
        vector<int> Sandauga_2_VECTOR;

        if (Dauginamasis >= 10) {

            int Dauginamojo_pirmas_sk = Dauginamasis / 10 % 10;
            int Sandaugos_dydis = Sandauga_1_VECTOR.size();
            Sandauga_2_VECTOR.push_back(0);
            Mintyse = 0;

            /// Dauginamas pirmas skaicius
            for (int i = 0; i < Skaiciaus_dydis; i++) {

                int Sandauga = 0;
                Sandauga = Dauginamojo_pirmas_sk * Skaicius[Skaiciaus_dydis-i-1];
                Sandauga += Mintyse;
                Mintyse = 0;

                while (Sandauga >= 10) {
                    Sandauga -= 10;
                    Mintyse++;
                }

                Sandauga_2_VECTOR.insert(Sandauga_2_VECTOR.begin(), Sandauga);

                if (i == Skaiciaus_dydis-1 && Mintyse > 0) {
                    Sandauga_2_VECTOR.insert(Sandauga_2_VECTOR.begin(), Mintyse);
                }

            }

        }


        /// Abi sandaugos sudedamos
        if (Dauginamasis >= 10) {

            int Antros_sandaugos_ilgis = Sandauga_2_VECTOR.size();
            int Pirmosios_sandaugos_skait_sk = Sandauga_1_VECTOR.size();
            Mintyse = 0;
            Skaicius.clear();

            for (int i = 0; i < Antros_sandaugos_ilgis; i++) {

                if (i == 0) {
                    int Pirmos_sandaugos_sk = Sandauga_1_VECTOR.back();
                    Skaicius.push_back(Pirmos_sandaugos_sk);
                }
                else {

                    int Sandaugu_sudetis;

                    /// Sudedama pirma ir antra sandauga
                    if (i+1 <= Pirmosios_sandaugos_skait_sk) {

                        int x1 = Sandauga_1_VECTOR.size()-i-1;
                        int x2 = Sandauga_2_VECTOR.size()-i-1;

                        Sandaugu_sudetis = Sandauga_1_VECTOR[x1] + Sandauga_2_VECTOR[x2] + Mintyse;
                        Mintyse = 0;
                    }
                    else {
                        int x2 = Sandauga_2_VECTOR.size()-i-1;
                        Sandaugu_sudetis = Sandauga_2_VECTOR[x2] + Mintyse;
                        Mintyse = 0;
                    }


                    /// Jei sandaugu sudetis yra dvieju skaitmenu, ja sutrumpiname
                    while (Sandaugu_sudetis >= 10) {
                        Sandaugu_sudetis -= 10;
                        Mintyse++;
                    }

                    Skaicius.insert(Skaicius.begin(), Sandaugu_sudetis);

                    /// Jei visi skaiciai sudeti, taciau liko skaiciu mintyse, juos taip pat itraukiam
                    if (i+1 == Antros_sandaugos_ilgis && Mintyse > 0) {

                        int Mintyse2 = 0;

                        if (Mintyse >= 10) {

                            while (Mintyse >= 10) {
                                Mintyse -= 10;
                                Mintyse2++;
                            }

                            Skaicius.insert(Skaicius.begin(), Mintyse);
                            Skaicius.insert(Skaicius.begin(), Mintyse2);
                        }
                        else {
                            Skaicius.insert(Skaicius.begin(), Mintyse);
                        }

                    }

                }

            }

        }
        else {

            Skaicius.clear();

            for (auto x : Sandauga_1_VECTOR) {
                Skaicius.push_back(x);
            }

        }

        /// Skaicius ir Sandauga_1_VECTOR sulyginami
        Sandauga_1_VECTOR.clear();
        Sandauga_2_VECTOR.clear();

        /// Dauginamasis sumazinamas vienu vienetu
        Dauginamasis--;
    }


    /// Rezultatu spausdinimas
    fr << "Skaičius N : " << N << "\n";

    fr << "Faktorialas : ";
    for (auto x : Skaicius) {
        fr << x;
        Skaitmenu_suma += x;
    }
    fr << "\n";

    fr << "Suma : " << Skaitmenu_suma << "\n";
}
