#include <bits/stdc++.h>
using namespace std;

string FEN_eilute;
string Galima_FEN_eilute;
vector<vector<int>> Legalus_ejimai;
int Lenta[8][8];


ofstream fr1 ("testas.txt");


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


    int Baltu_pestininku_sk = 0, Baltu_bokstu_sk = 0, Baltu_zirgu_sk = 0, Baltu_rikiu_sk = 0, Baltu_valdoviu_sk = 0,
        Juodu_pestininku_sk = 0, Juodu_bokstu_sk = 0, Juodu_zirgu_sk = 0, Juodu_rikiu_sk = 0, Juodu_valdoviu_sk = 0;

    int Pestininku_langeliai = 0, Bokstu_langeliai = 0, Zirgu_langeliai = 0, Rikiu_langeliai = 0, Valdoviu_langeliai = 0, Karaliu_langeliai = 0;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (Lenta[i][j] == 1){
                Juodu_pestininku_sk++;
                Pestininku_langeliai = Pestininku_langeliai + (-1 * Pestininkas_Lentele[i][j]);
            }
            else if (Lenta[i][j] == -1){
                Baltu_pestininku_sk++;
                Pestininku_langeliai = Pestininku_langeliai + Pestininkas_Lentele[7 - i][7 - j];
            }
            else if (Lenta[i][j] == 5){
                Juodu_bokstu_sk++;
                Bokstu_langeliai = Bokstu_langeliai + (-1 * Bokstas_Lentele[i][j]);
            }
            else if (Lenta[i][j] == -5){
                Baltu_bokstu_sk++;
                Bokstu_langeliai = Bokstu_langeliai + Bokstas_Lentele[7 - i][7 - j];
            }
            else if (Lenta[i][j] == 3){
                Juodu_zirgu_sk++;
                Zirgu_langeliai = Zirgu_langeliai + (-1 * Zirgas_Lentele[i][j]);
            }
            else if (Lenta[i][j] == -3){
                Baltu_zirgu_sk++;
                Zirgu_langeliai = Zirgu_langeliai + Zirgas_Lentele[7 - i][7 - j];
            }
            else if (Lenta[i][j] == 2){
                Juodu_rikiu_sk++;
                Rikiu_langeliai = Rikiu_langeliai + (-1 * Rikis_Lentele[i][j]);
            }
            else if (Lenta[i][j] == -2){
                Baltu_rikiu_sk++;
                Rikiu_langeliai = Rikiu_langeliai + Rikis_Lentele[7 - i][7 - j];
            }
            else if (Lenta[i][j] == 6){
                Juodu_valdoviu_sk++;
                Valdoviu_langeliai = Valdoviu_langeliai + (-1 * Karaliene_Lentele[i][j]);
            }
            else if (Lenta[i][j] == -6){
                Baltu_valdoviu_sk++;
                Valdoviu_langeliai = Valdoviu_langeliai + Karaliene_Lentele[7 - i][7 - j];
            }
            else if (Lenta[i][j] == 10){
                Karaliu_langeliai = Karaliu_langeliai + (-1 * Karalius_Lentele[i][j]);
            }
            else if (Lenta[i][j] == -10){
                Karaliu_langeliai = Karaliu_langeliai + Karalius_Lentele[7 - i][7 - j];
            }
        }
    }

    int Materialas = 100 * (Baltu_pestininku_sk - Juodu_pestininku_sk) + 320 * (Baltu_zirgu_sk - Juodu_zirgu_sk) + 330 * (Baltu_rikiu_sk - Juodu_rikiu_sk) + 500 * (Baltu_bokstu_sk - Juodu_bokstu_sk) + 900 * (Baltu_valdoviu_sk - Juodu_valdoviu_sk);

    int Galutinis_ivertinimas = Materialas + Pestininku_langeliai + Bokstu_langeliai + Rikiu_langeliai + Zirgu_langeliai + Valdoviu_langeliai + Karaliu_langeliai;

    fr1 << "PESTITINKAI: " << Pestininku_langeliai << "\n";
    fr1 << "BOKSTAI: " << Bokstu_langeliai << "\n";
    fr1 << "ZIRGAI: " << Zirgu_langeliai << "\n";
    fr1 << "RIKIAI: " << Rikiu_langeliai << "\n";
    fr1 << "VALDOVES: " << Valdoviu_langeliai << "\n";
    fr1 << "KARALIAI: " << Karaliu_langeliai << "\n";
    fr1 << "GALUTINIS: " << Galutinis_ivertinimas << "\n";
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
            fr1 << Lenta[i][y];
        }
        fr1 << "\n";
    }

    fr1 << "\n\n";
}





void Lentos_generavimas() {

    int FEN_eilute_nr = 0;
    int X = 7;
    int Y = 0;

    for (int i = 0; i < 8; i++) {

        if (FEN_eilute[FEN_eilute_nr] >= 'A' && FEN_eilute[FEN_eilute_nr] <= 'z') {

            for (int y = 0; y < 8; y++) {
                if (FEN_eilute[FEN_eilute_nr] >= 'A' && FEN_eilute[FEN_eilute_nr] <= 'z') {

                    char Figura = FEN_eilute[FEN_eilute_nr];

                    if (Figura == 'P') {
                        Lenta[X][Y] = -1;
                    }
                    else if (Figura == 'p') {
                        Lenta[X][Y] = 1;
                    }
                    else if (Figura == 'B') {
                        Lenta[X][Y] = -2;
                    }
                    else if (Figura == 'b') {
                        Lenta[X][Y] = 2;
                    }
                    else if (Figura == 'r') {
                        Lenta[X][Y] = 5;
                    }
                    else if (Figura == 'R') {
                        Lenta[X][Y] = -5;
                    }
                    else if (Figura == 'n') {
                        Lenta[X][Y] = 3;
                    }
                    else if (Figura == 'N') {
                        Lenta[X][Y] = -3;
                    }
                    else if (Figura == 'q') {
                        Lenta[X][Y] = 6;
                    }
                    else if (Figura == 'Q') {
                        Lenta[X][Y] = -6;
                    }
                    else if (Figura == 'k') {
                        Lenta[X][Y] = 10;
                    }
                    else if (Figura == 'K') {
                        Lenta[X][Y] = -10;
                    }

                    FEN_eilute_nr++;
                    Y++;
                }
                else {
                    char a = FEN_eilute[FEN_eilute_nr];
                    int sk = a - '0';
                    FEN_eilute_nr++;
                    y += sk - 1;

                    for (int z = 0; z < sk; z++) {
                        Lenta[X][Y] = 0;
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

                    char Figura = FEN_eilute[FEN_eilute_nr];

                    if (Figura == 'P') {
                        Lenta[X][Y] = -1;
                    }
                    else if (Figura == 'p') {
                        Lenta[X][Y] = 1;
                    }
                    else if (Figura == 'B') {
                        Lenta[X][Y] = -2;
                    }
                    else if (Figura == 'b') {
                        Lenta[X][Y] = 2;
                    }
                    else if (Figura == 'r') {
                        Lenta[X][Y] = 5;
                    }
                    else if (Figura == 'R') {
                        Lenta[X][Y] = -5;
                    }
                    else if (Figura == 'n') {
                        Lenta[X][Y] = 3;
                    }
                    else if (Figura == 'N') {
                        Lenta[X][Y] = -3;
                    }
                    else if (Figura == 'q') {
                        Lenta[X][Y] = 6;
                    }
                    else if (Figura == 'Q') {
                        Lenta[X][Y] = -6;
                    }
                    else if (Figura == 'k') {
                        Lenta[X][Y] = 10;
                    }
                    else if (Figura == 'K') {
                        Lenta[X][Y] = -10;
                    }

                    Y++;
                    FEN_eilute_nr++;
                    Uzpildyti_laukeliai++;
                }
                else {
                    int sk = a - '0';
                    for (int y = 0; y < sk; y++) {
                        Lenta[X][Y] = 0;
                        Y++;
                    }
                    FEN_eilute_nr++;
                    Uzpildyti_laukeliai += sk;
                }
            }
        }
        X -= 2;
        FEN_eilute_nr++;
    }

    Spausdink();
}






/// Legaliu eijimu generatorius ///



bool check_w(){
    int row;
    int col;
    bool found = false;
    for (int i = 0; i < 8; i++){
        for (int j = 0;j < 8;j++){
            if(Lenta[i][j] == 10){
                row = i;
                col = j;
                found = true;
            }
        }
    }
    if (found == false){
        cout << "There is no white king on the Lenta " << endl;
        return false;
    }
    if (row != 0 && col != 0 && Lenta[row-1][col-1] == -1) return true;
    if (row != 0 && col != 7 && Lenta[row-1][col+1] == -1) return true;
    int a;
    int b;
    a = row;
    if (row != 7){
        for (;;){
            a+=1;
            if(Lenta[a][col] == -5 || Lenta[a][col] == -6) return true;
            if (a == 7 || Lenta[a][col] != 0) break;
        }
    }
    a = row;
    if (row != 0){
        for (;;){
            a-=1;
            if(Lenta[a][col] == -5 || Lenta[a][col] == -6) return true;
            if (a == 0 || Lenta[a][col] != 0) break;
        }
    }
    b = col;
    if (col != 0){
        for (;;){
            b-=1;
            if (Lenta[row][b] == -6 or Lenta[row][b] == -5) return true;
            if(b == 0 || Lenta[row][b] != 0) break;
        }
    }
    b = col;
    if (col != 7){
        for (;;){
            b+=1;
            if (Lenta[row][b] == -6 or Lenta[row][b] == -5) return true;
            if(b == 7 || Lenta[row][b] != 0) break;
        }
    }
    a = row;
    b = col;
    if (a != 0 && b != 0){
        for (;;){
            a-=1;
            b-=1;
            if (Lenta[a][b] == -6 or Lenta[a][b] == -2) return true;
            if(b == 0  || a == 0 || Lenta[a][b] != 0) break;
        }
    }
    a = row;
    b = col;
    if (a != 0 && b != 7){
        for (;;){
            a-=1;
            b+=1;
            if (Lenta[a][b] == -6 or Lenta[a][b] == -2) return true;
            if(b == 7  || a == 0 || Lenta[a][b] != 0) break;
        }
    }
    a = row;
    b = col;
    if (a != 7 && b != 0){
        for (;;){
            a+=1;
            b-=1;
            if (Lenta[a][b] == -6 or Lenta[a][b] == -2) return true;
            if(b == 0  || a == 7 || Lenta[a][b] != 0) break;
        }
    }
    a = row;
    b = col;
    if (a != 7 && b != 7){
        for (;;){
            a+=1;
            b+=1;
            if (Lenta[a][b] == -6 or Lenta[a][b] == -2) return true;
            if(b == 7  || a == 7 || Lenta[a][b] != 0) break;
        }
    }
    if (row > 0 && col < 6 && Lenta[row-1][col+2] == -3)return true;
    if (row > 1 && col < 7 && Lenta[row-2][col+1] == -3)return true;
    if (row < 7 && col < 6 && Lenta[row+1][col+2] == -3)return true;
    if (row < 6 && col < 7 && Lenta[row+2][col+1] == -3)return true;
    if (row < 6 && col > 0 && Lenta[row+2][col-1] == -3)return true;
    if (row < 7 && col > 1 && Lenta[row+1][col-2] == -3)return true;
    if (row > 1 && col > 0 && Lenta[row-2][col-1] == -3)return true;
    if (row > 1 && col > 0 && Lenta[row-2][col-1] == -3)return true;
    if (row != 7 && Lenta[row+1][col] == 10) return true;
    if (row != 0 && Lenta[row-1][col] == 10) return true;
    if (col != 7 && Lenta[row][col+1] == 10) return true;
    if (col != 0 && Lenta[row][col-1] == 10) return true;
    if (row != 0 && col != 0 && Lenta[row-1][col-1] == 10) return true;
    if (row != 0 && col != 7 && Lenta[row-1][col+1] == 10) return true;
    if (row != 7 && col != 0 && Lenta[row+1][col-1] == 10) return true;
    if (row != 7 && col != 0 && Lenta[row+1][col+1] == 10) return true;
    return false;
}

vector<int> push(int row,int col,int desrow,int descol){
    vector<int> move;
    move.push_back(row);
    move.push_back(col);
    move.push_back(desrow);
    move.push_back(descol);
    return move;
}

void undomove(int original,vector<int> Move){
    Lenta[Move[0]][Move[1]] = Lenta[Move[2]][Move[3]];
    Lenta[Move[2]][Move[3]] = original;
}

int perform(vector<int> Move){
    int original;
    original = Lenta[Move[2]][Move[3]];
    Lenta[Move[2]][Move[3]] = Lenta[Move[0]][Move[1]];
    Lenta[Move[0]][Move[1]] = 0;
    return original;
}

vector<vector<int>> generate_moves_w(){
    vector<vector<int>> pseudomoves,legal_moves;
    vector<int> move;
    int original,a,b;
    for(int row = 0; row < 8; row++){
        for(int col = 0;col < 8;col++){
            if (!Lenta[row][col]) continue;
            if (Lenta[row][col] == 1 && row != 0){
                if (row == 6 && Lenta[row-1][col] == 0 && Lenta[row-2][col] == 0)
                    pseudomoves.push_back(push(row,col,row-2,col));
                if (Lenta[row-1][col] == 0)
                    pseudomoves.push_back(push(row,col,row-1,col));
                if (col != 0 && Lenta[row-1][col-1] < 0)
                    pseudomoves.push_back(push(row,col,row-1,col-1));
                if (col != 7 && Lenta[row-1][col+1] < 0)
                    pseudomoves.push_back(push(row,col,row-1,col+1));
            }
            else if (Lenta[row][col] == 5){
                a = row;
                b = col;
                if (a != 0){
                    for (;;){
                        a-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a = row;
                b = col;
                if (a!=7){
                    for(;;){
                        a+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a = row;
                b = col;
                if (b!= 0){
                    for(;;){
                        b-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || b == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a  =row;
                b = col;
                if (b != 7){
                    for(;;){
                        b+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || b == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }

            }
            else if (Lenta[row][col] == 3){
                if (row > 0 && col < 6 && Lenta[row-1][col+2] <= 0)pseudomoves.push_back(push(row,col,row-1,col+2));
                if (row > 1 && col < 7 && Lenta[row-2][col+1] <= 0)pseudomoves.push_back(push(row,col,row-2,col+1));
                if (row < 7 && col < 6 && Lenta[row+1][col+2] <= 0)pseudomoves.push_back(push(row,col,row+1,col+2));
                if (row < 6 && col < 7 && Lenta[row+2][col+1] <= 0)pseudomoves.push_back(push(row,col,row+2,col+1));
                if (row < 6 && col > 0 && Lenta[row+2][col-1] <= 0)pseudomoves.push_back(push(row,col,row+2,col-1));
                if (row < 7 && col > 1 && Lenta[row+1][col-2] <= 0)pseudomoves.push_back(push(row,col,row+1,col-2));
                if (row > 1 && col > 0 && Lenta[row-2][col-1] <= 0)pseudomoves.push_back(push(row,col,row-2,col-1));
                if (row > 0 && col > 1 && Lenta[row-1][col-2] <= 0)pseudomoves.push_back(push(row,col,row-1,col-2));
            }
            else if (Lenta[row][col] == 2){
                a = row;
                b = col;
                if (a !=  0 && b != 0){
                    for (;;){
                        a-=1;
                        b-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 0 || b == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a = row;
                b = col;
                if (a !=  0 && b != 7){
                    for (;;){
                        a-=1;
                        b+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 0 || b == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));

                    }
                }
                a = row;
                b = col;
                if (a !=  7 && b != 7){
                    for (;;){
                        a+=1;
                        b+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 7 || b == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));
                }
                }
                a = row;
                b = col;
                if (a !=  7 && b != 0){
                    for (;;){
                        a+=1;
                        b-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 7 || b == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));
                }
                }
        }
            else if (Lenta[row][col] == 6){
                a = row;
                b = col;
                if (a !=  0 && b != 0){
                    for (;;){
                        a-=1;
                        b-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 0 || b == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a = row;
                b = col;
                if (a !=  0 && b != 7){
                    for (;;){
                        a-=1;
                        b+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 0 || b == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));

                    }
                }
                a = row;
                b = col;
                if (a !=  7 && b != 7){
                    for (;;){
                        a+=1;
                        b+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 7 || b == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));
                }
                }
                a = row;
                b = col;
                if (a !=  7 && b != 0){
                    for (;;){
                        a+=1;
                        b-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 7 || b == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b])pseudomoves.push_back(push(row,col,a,b));
                }
                }
                a = row;
                b = col;
                if (a != 0){
                    for (;;){
                        a-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a = row;
                b = col;
                if (a!=7){
                    for(;;){
                        a+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || a == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a = row;
                b = col;
                if (b!= 0){
                    for(;;){
                        b-=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || b == 0){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }
                a  =row;
                b = col;
                if (b != 7){
                    for(;;){
                        b+=1;
                        if (Lenta[a][b] > 0) break;
                        if (Lenta[a][b] < 0 || b == 7){
                            pseudomoves.push_back(push(row,col,a,b));
                            break;
                        }
                        if(!Lenta[a][b]) pseudomoves.push_back(push(row,col,a,b));
                    }
                }

            }
            else if (Lenta[row][col] == 10){
                if (row != 7 && Lenta[row+1][col] <= 0)pseudomoves.push_back(push(row,col,row+1,col));
                if (row != 0 && Lenta[row-1][col] <= 0)pseudomoves.push_back(push(row,col,row-1,col));
                if (col != 7 && Lenta[row][col+1] <= 0)pseudomoves.push_back(push(row,col,row,col+1));
                if (col != 0 && Lenta[row][col-1] <= 0)pseudomoves.push_back(push(row,col,row,col-1));
                if(row != 0 && col!= 0 && Lenta[row-1][col-1] <= 0)pseudomoves.push_back(push(row,col,row-1,col-1));
                if(row != 0 && col!= 7 && Lenta[row-1][col+1] <= 0)pseudomoves.push_back(push(row,col,row-1,col+1));
                if(row != 7 && col!= 0 && Lenta[row+1][col-1] <= 0)pseudomoves.push_back(push(row,col,row+1,col-1));
                if(row != 7 && col!= 7 && Lenta[row+1][col+1] <= 0)pseudomoves.push_back(push(row,col,row+1,col+1));
            }
        }
    }

    for (long unsigned int i = 0; i < pseudomoves.size(); i++){
        original = perform(pseudomoves[i]);
        if (check_w() == false) legal_moves.push_back(pseudomoves[i]);
        undomove(original,pseudomoves[i]);
    }
    return legal_moves;
}





void Naujos_eilutes_generavimas() {

    char tusciu_langeliu_sk_char;
    int tusciu_langeliu_sk = 0;


    for (int i = 7; i >= 0; i--) {
        tusciu_langeliu_sk = 0;
        for(int j = 0; j < 8; j++) {
            if (Lenta[i][j] == 0) {
                tusciu_langeliu_sk++;
            }
            if (j != 7 && Lenta[i][j] == 0 && Lenta[i][j+1] != 0) {
                tusciu_langeliu_sk_char = '0' + tusciu_langeliu_sk;
                Galima_FEN_eilute += tusciu_langeliu_sk_char;
                tusciu_langeliu_sk = 0;
            }
            if (j == 7 && Lenta[i][j] == 0) {
                tusciu_langeliu_sk_char = '0' + tusciu_langeliu_sk;
                Galima_FEN_eilute += tusciu_langeliu_sk_char;
                tusciu_langeliu_sk == 0;
            }
            if (Lenta[i][j] == 10) {
                Galima_FEN_eilute += 'k';
            }
            if (Lenta[i][j] == -10) {
                Galima_FEN_eilute += 'K';
            }
            if (Lenta[i][j] == 6) {
                Galima_FEN_eilute += 'q';
            }
            if (Lenta[i][j] == -6) {
                Galima_FEN_eilute += 'Q';
            }
            if (Lenta[i][j] == 5) {
                Galima_FEN_eilute += 'r';
            }
            if (Lenta[i][j] == -5) {
                Galima_FEN_eilute += 'R';
            }
            if (Lenta[i][j] == 3) {
                Galima_FEN_eilute += 'n';
            }
            if (Lenta[i][j] == -3) {
                Galima_FEN_eilute += 'N';
            }
            if (Lenta[i][j] == 2) {
                Galima_FEN_eilute += 'b';
            }
            if (Lenta[i][j] == -2) {
                Galima_FEN_eilute += 'B';
            }
            if (Lenta[i][j] == 1) {
                Galima_FEN_eilute += 'p';
            }
            if (Lenta[i][j] == -1) {
                Galima_FEN_eilute += 'P';
            }
        }
        if(i != 0) {
        Galima_FEN_eilute += '/';
        }
    }

    Galima_FEN_eilute += ' b';
}






void Figuru_perkelimas_lentoje(int x1, int y1, int x2, int y2) {

    int Perkeliama_figura = Lenta[x1][y1];
    Lenta[x1][y1] = 0;
    Lenta[x2][y2] = Perkeliama_figura;
}





void Legaliu_ejimu_generavimas() {

    vector<vector<int>> legal_moves = generate_moves_w();

    for (unsigned long int i = 0; i < legal_moves.size(); i++) {

        vector<int> v;

        fr1 << legal_moves[i][0] << " " <<  legal_moves[i][1] << " " <<  legal_moves[i][2] << " " <<  legal_moves[i][3] << endl;

        v.push_back(legal_moves[i][0]);
        v.push_back(legal_moves[i][1]);
        v.push_back(legal_moves[i][2]);
        v.push_back(legal_moves[i][3]);

        Legalus_ejimai.push_back(v);
    }

}






extern "C"

void Ejimo_generavimas() {

    /// Pasiemame lentos FEN eilute
    FEN_eilutes_gavimas();
    fr1 << FEN_eilute << "\n";

    /// Sachmatu lenteles generavimas
    Lentos_generavimas();

    Naujos_eilutes_generavimas();
    fr1 << Galima_FEN_eilute << "\n\n";

    /// Surandame ant lentos esanciu figuru skaiciu
    Figuru_skaiciaus_radimas();

    /// Surandame visus legalius ejimus
    Legaliu_ejimu_generavimas();

    /// Perduodame geriausio ejimo FEN eilute pyhton programai
    ofstream fr("rezultatai.txt");
    fr << FEN_eilute;
    return;
}

