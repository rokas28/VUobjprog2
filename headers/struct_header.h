#ifndef UNTITLED_STRUCT_HEADER_H
#define UNTITLED_STRUCT_HEADER_H

struct studentas {
    string vardas, pavarde;
    int egzaminas=0;
    double vidGalutinis = 0;
    double medGalutinis=0;
    std::vector<int > nd;
};

double mediana(std::vector<studentas> stud, int x, int y);
bool netinkamasPav(const string a);
void ndGen(std::vector<studentas>& stud, int x, int y);
void egGen(std::vector<studentas>& stud, int y);
double ndSum(std::vector<studentas> stud, int x, int y);
void galutinis(std::vector<studentas>& stud, int x, int y);
void varTikrinimas(std::vector<studentas>& stud, int y);
void pavTikrinimas(std::vector<studentas>& stud, int y);
void fTikrinimas(int &f);
void egzIvedimas(std::vector<studentas>& stud, int y, int f);
void ndIvedimas(std::vector<studentas>& stud, int y, int f);
void generate( std::vector<studentas>& stud, int &ilgVar, int &ilgPav );
void stringTikrinimas (std::ifstream &df, string a, bool &fail, int eil);
void nd(std::ifstream &df,std::vector<studentas> &stud, int x, int y, bool &fail, int eil);
void egz(std::ifstream &df,std::vector<studentas> &stud, int y, bool &fail, int eil);
int ndSk(std::ifstream &df);
void fileGenerate(int x);
void failoSkaitymas(std::vector<studentas> &stud, int &ilgVar, int &ilgPav, int N);
void rikiavimas(std::vector<studentas>& stud);
void rusiavimas(std::vector<studentas>& stud);
void skirstymas(std::vector<studentas>& stud, std::vector<studentas>& vargsiukai, int x);
void skirstymas2(std::vector<studentas>& stud, std::vector<studentas>& vargsiukai, std::vector<studentas>& galvociai, int x);
void isvedimas( std::vector<studentas> stud, std::vector<studentas> vargsiukai, int ilgVar, int ilgPav);
void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end);

#endif //UNTITLED_STRUCT_HEADER_H
