#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include<random>


using std::string;
using std::cin;
using std::cout;
using std::endl;

const int N = 2;
struct studentas {
    string vardas, pavarde;
    int egzaminas=0;
    double vidGalutinis = 0, medGalutinis=0;
    int dydis=1;
    int paskutinis=0;
    double *nd = new double[dydis];

    void sort(){
        int a = paskutinis;
        double b;
        bool swap;
        while(a > 1) {
            swap = false;
            for(int i = 0; i < a - 1; i++) {
                if(nd[i] > nd[i + 1]) {
                    swap = true;
                    b = nd[i];
                    nd[i] = nd[i + 1];
                    nd[i + 1] = b;
                }
            }
            if(!swap)
                break;
            a--;
        }
    }

    void didintiArr() {
        dydis *= 2;
        auto *newArr = new double[dydis];
        for (int i = 0; i < paskutinis; i++)
            newArr[i] = nd[i];
        delete [] nd;
        nd = newArr;
    }

};

double mediana(std::vector<studentas >& stud, int x, int y){
    double med;
    stud[x].sort();
    if (y % 2 == 0)
    {
        med =  (stud[x].nd[y / 2 - 1] + stud[x].nd[y / 2]) / 2.0;
    }
    else
    {
        med = stud[x].nd[y / 2];
    }
    return med;
};

bool netinkamasPav(const string a){
    char c;
    for(int i = 0; i < a.length(); i++) {
        c = a.at(i);
        if (!(( c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) return false;
    }
}

void generate( std::vector<studentas >& stud){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 10);
    double vid;
    int i = 0;
    int st = 0;
    while(true) {
        cout << "Jei norite prideti studenta spauskite 1" << endl;
        cin >> st;
        if (st == 1) {
            stud.push_back(studentas());
            double sum = 0;
            int k = 0;
            int q = 1;
            int f;
            cout << "Iveskite studento varda " << endl;
            cin >> stud[i].vardas;
            while (!netinkamasPav(stud[i].vardas)) {
                cout << "Netinkamas vardas, iveskite kita ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> stud[i].vardas;
            }

            cout << "Iveskite studento pavarde" << endl;
            cin >> stud[i].pavarde;
            while (!netinkamasPav(stud[i].pavarde)) {
                cout << "Netinkamas vardas, iveskite kita ";
                cin.clear();
                cin.ignore(256, '\n');
                cin >> stud[i].pavarde;
            }
            cout
                    << "Jei norite ivseti studento egzamino pazymi ranka, spauskite 1, jei norite ji atsitiktinai sugeneruoti, spauskite 0"
                    << endl;
            cin >> f;
            while (f != 0 && f != 1) {
                cout << "Ivestas neteisingas simbolis, pasirinkite dar karta " << endl;
                cin >> f;
            }
            if (f == 1) {
                while(true){
                    int eg = 0;
                    cout << "Iveskite egzamino rezultata" << endl;
                    cin >> eg;
                    if( eg>= 0 && eg <= 10){
                        if(q!=0) {
                            stud[i].egzaminas = eg;
                            break;
                        }
                    }
                    else {
                        cout << "Netinkamas pazymys, iveskite kita" << endl;
                        continue;
                    }
                }
            } else if (f == 0) {
                stud[i].egzaminas = random(gen);
            }
            cout
                    << "Jei norite ivseti studento namu darbu pazymius ranka, spauskite 1, jei norite juos atsitiktinai sugeneruoti, spauskite 0"
                    << endl;
            cin >> f;
            while (f != 0 && f != 1) {
                cout << "Ivestas neteisingas simbolis, pasirinkite dar karta " << endl;
                cin >> f;
            }
            if (f == 1) {
                cout << "Iveskite namu darbu rezultatus, kai visi namu darbu rezultataibus suvesti, spauskite 0"
                     << endl;
                while (q != 0) {
                    cout << "Iveskite namu darbu pazymi " << endl;
                    cin >> q;
                    if (q >= 0 && q <= 10) {
                        if (q != 0) {
                            k++;
                            if (stud[i].paskutinis + 1 == stud[i].dydis) stud[i].didintiArr();
                            stud[i].nd[stud[i].paskutinis] = q;
                            stud[i].paskutinis++;
                        }
                    } else {
                        cout << "Netinkamas pazymys, iveskite kita" << endl;
                        continue;
                    }
                }
                for (int z = 0; z < k; z++) {
                    sum += stud[i].nd[z];
                }
                vid = sum / k;
                stud[i].vidGalutinis = 0.4 * vid + 0.6 * stud[i].egzaminas;
                stud[i].medGalutinis = 0.4 * mediana(stud, i, k) + 0.6 * stud[i].egzaminas;
            } else if (f == 0) {
                cout << "Iveskite kiek namu darbu pazymiu norite sugeneruoti" << endl;
                cin >> stud[i].dydis;
                for (int j = 0; j < stud[i].dydis; j++) {
                    stud[i].nd[j] = random(gen);
                }
                for (int z = 0; z < stud[i].dydis; z++) {
                    sum += stud[i].nd[z];
                }
                vid = sum / stud[i].dydis;
                stud[i].vidGalutinis = 0.4 * vid + 0.6 * stud[i].egzaminas;
                stud[i].medGalutinis = 0.4 * mediana(stud, i, stud[i].dydis) + 0.6 * stud[i].egzaminas;
            }
            i++;
        }
        else break;
    }
};


void isvedimas( std::vector<studentas > stud){
    cout << "Vardas     Pavarde             Galutiis(vid.)    Galutinis(med.)" << endl;
    cout << "----------------------------------------------------------------" << endl;
    for(int i = 0; i < stud.size(); i++){
        cout << std::left <<  std::setw(11) << stud[i].vardas << std::setw(19) << stud[i].pavarde << "  ";
        cout << std::setw(6) << std::fixed << std::setprecision(2) << stud[i].vidGalutinis << "             ";
        cout << std::setw(12) << std::fixed << std::setprecision(2) << stud[i].medGalutinis << endl;
    }
};

int main() {
    std::vector<studentas> stud;
    generate(stud);
    isvedimas(stud);
    return 0;
};