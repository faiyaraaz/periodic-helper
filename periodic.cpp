#include <iostream>
#include <string>
using namespace std;

//PROGRAM UNTUK MENENTUKAN UNSUR DI TABEL PERIODIK DAN MASSA RELATIF (MR)

//PROGRAM 1 (TABEL PERIODIK)
// Kumpulan data dalam tabel periodik
struct elemen {
    int nomorAtom;
    string simbol;
    string nama;
    double massaAtom;
};

// Fungsi untuk menentukan elemen dalam tabel periodik
void menentukanTabelPeriodik(elemen elements[], int nomorElemen, int nomorAtom) {
    for (int i = 0; i < nomorElemen; i++) {
        if (elements[i].nomorAtom == nomorAtom) {
            cout << "Berikut elemen yang anda cari di tabel periodik" << endl;
            cout << "Nomor Atom: " << elements[i].nomorAtom << endl;
            cout << "Simbol: " << elements[i].simbol << endl;
            cout << "Nama: " << elements[i].nama << endl;
            cout << "Massa atom: " << elements[i].massaAtom << endl;
            cout << endl;
            cout << "===================" << endl;
            cout << "  PROGRAM SELESAi  " <<endl;
            cout << "===================" << endl;
            cout << "     THANK YOU     " << endl;
            cout << "===================" << endl;
            exit(0); // Keluar dari program setelah menemukan elemen
        }
    }
    cout << "---------------------------------------------" << endl;
    cout << "Elemen dengan nomor atom " << nomorAtom << " tidak ditemukan." << endl;
    cout << "---------------------------------------------" << endl;
    cout << endl;
    cout << "Silahkan Coba Lagi" << endl;
    cout << endl;
}

//PROGRAM 2 (MENGHITUNG MASSA RELATIF)

//kumpulan data yang diperlukan untuk menghitung massa relatif

struct Elemen {
    string simbol;
    double massaAtom;
};

//fungsi untuk mencari massa masing-masing atom berdasarkan simbol
double cariMassaAtom(string simbol, Elemen tabelPeriodik[],
int jumlahElemen) {
    for (int i = 0; i < jumlahElemen; i++) {
        if (tabelPeriodik[i].simbol == simbol) {
            return tabelPeriodik[i].massaAtom;
        }
    }
    return -1; // Return -1 jika elemen tidak ditemukan
}

// Fungsi menghitung Massa Relatif (Mr) Molekul
double hitungMr(const string& senyawa, Elemen tabelPeriodik[], 
int jumlahElemen) {
    double totalMass = 0.0;
    int panjang = senyawa.length();

    for (int i = 0; i < panjang; i++) {
        if (senyawa[i] == '(') {
            double groupMass = 0.0;
            int j = i + 1;

            //perhitungan massa relatif jika ada yang di dalam kurung
            
            while (j < panjang && senyawa[j] != ')') {
                string simbol = "";
                simbol += senyawa[j];
                if (j + 1 < panjang && senyawa[j + 1] >= 'a' && senyawa[j + 1] <= 'z') {
                    simbol += senyawa[j + 1];
                    j++;
                }

                int jumlahAtom = 0;
                while (j + 1 < panjang && senyawa[j + 1] >= '0' && senyawa[j + 1] <= '9') {
                    jumlahAtom = jumlahAtom * 10 + (senyawa[j + 1] - '0');
                    j++;
                }
                if (jumlahAtom == 0) jumlahAtom = 1;

                double massaAtom = cariMassaAtom(simbol, tabelPeriodik, jumlahElemen);
                if (massaAtom == -1) {
                    cout << "Elemen '" << simbol << "' tidak ditemukan dalam tabel periodik." << endl;
                    return -1;
                }
                groupMass += massaAtom * jumlahAtom;
                j++;
            }
            //kalikan massa yang ada di dalam kurung dengan angka setelah ")"
           
            i = j;
            int multiplier = 0;
            while (i + 1 < panjang && senyawa[i + 1] >= '0' && senyawa[i + 1] <= '9') {
                multiplier = multiplier * 10 + (senyawa[i + 1] - '0');
                i++;
            }
            if (multiplier == 0) multiplier = 1;

            totalMass += groupMass * multiplier;
        } 
        //perhitungan biasa jika tidak ada tanda kurung
        else {
            string simbol = "";
            simbol += senyawa[i];
            if (i + 1 < panjang && senyawa[i + 1] >= 'a' && senyawa[i + 1] <= 'z') {
                simbol += senyawa[i + 1];
                i++;
            }

            int jumlahAtom = 0;
            while (i + 1 < panjang && senyawa[i + 1] >= '0' && senyawa[i + 1] <= '9') {
                jumlahAtom = jumlahAtom * 10 + (senyawa[i + 1] - '0');
                i++;
            }
            if (jumlahAtom == 0) jumlahAtom = 1;

            double massaAtom = cariMassaAtom(simbol, tabelPeriodik, jumlahElemen);
            if (massaAtom == -1) {
                cout << "Elemen '" << simbol << "' tidak ditemukan dalam tabel periodik." << endl;
                return -1;
            }

            totalMass += massaAtom * jumlahAtom;
        }
    }
    return totalMass;
}

//fungsi utama
int main() {
    //kumpulan elemen di tabel periodik untuk program 1
    elemen elements[] = {
        {1, "H", "Hydrogen", 1.00784},
        {2, "He", "Helium", 4.002602},
        {3, "Li", "Lithium", 6.941},
        {4, "Be", "Beryllium", 9.012182},
        {5, "B", "Boron", 10.811},
        {6, "C", "Carbon", 12.011},
        {7, "N", "Nitrogen", 14.0067},
        {8, "O", "Oxygen", 15.999},
        {9, "F", "Fluorine", 18.9984032},
        {10, "Ne", "Neon", 20.1797},
        {11, "Na", "Sodium", 22.98976928},
        {12, "Mg", "Magnesium", 24.305},
        {13, "Al", "Aluminium", 26.9815386},
        {14, "Si", "Silicon", 28.08855},
        {15, "P", "Phosphorus", 30.973762},
        {16, "S", "Sulfur", 32.065},
        {17, "Cl", "Chlorine", 35.453},
        {18, "Ar", "Argon", 39.948},
        {19, "K", "Potassium", 39.0983},
        {20, "Ca", "Calcium", 40.078},
        {21, "Sc", "Scandium", 44.955912},
        {22, "Ti", "Titanium", 47.867},
        {23, "V", "Vanadium", 50.9415},
        {24, "Cr", "Chromium", 51.9961},
        {25, "Mn", "Manganese", 54.938044},
        {26, "Fe", "Iron", 55.845},
        {27, "Co", "Cobalt", 58.933195},
        {28, "Ni", "Nickel", 58.6934},
        {29, "Cu", "Copper", 63.546},
        {30, "Zn", "Zinc", 65.38},
        {31, "Ga", "Gallium", 69.723},
        {32, "Ge", "Germanium", 72.64},
        {33, "As", "Arsenic", 74.9216},
        {34, "Se", "Selenium", 78.96},
        {35, "Br", "Bromine", 79.904},
        {36, "Kr", "Krypton", 83.798},
        {37, "Rb", "Rubidium", 85.4678},
        {38, "Sr", "Strontium", 87.62},
        {39, "Y", "Yttrium", 88.90585},
        {40, "Zr", "Zirconium", 91.224},
        {41, "Nb", "Niobium", 92.90638},
        {42, "Mo", "Molybdenum", 95.95},
        {43, "Tc", "Technetium", 98},
        {44, "Ru", "Ruthenium", 101.07},
        {45, "Rh", "Rhodium", 102.9055},
        {46, "Pd", "Palladium", 106.42},
        {47, "Ag", "Silver", 107.8682},
        {48, "Cd", "Cadmium", 112.411},
        {49, "In", "Indium", 114.818},
        {50, "Sn", "Tin", 118.71},
        {51, "Sb", "Antimony", 121.76},
        {52, "Te", "Tellurium", 127.6},
        {53, "I", "Iodine", 126.90447},
        {54, "Xe", "Xenon", 131.293},
        {55, "Cs", "Cesium", 132.9054519},
        {56, "Ba", "Barium", 137.327},
        {57, "La", "Lanthanum", 138.90547},
        {58, "Ce", "Cerium", 140.116},
        {59, "Pr", "Praseodymium", 140.90765},
        {60, "Nd", "Neodymium", 144.242},
        {61, "Pm", "Promethium", 145},
        {62, "Sm", "Samarium", 150.36},
        {63, "Eu", "Europium", 151.964},
        {64, "Gd", "Gadolinium", 157.25},
        {65, "Tb", "Terbium", 158.92535},
        {66, "Dy", "Dysprosium", 162.5},
        {67, "Ho", "Holmium", 164.93032},
        {68, "Er", "Erbium", 167.259},
        {69, "Tm", "Thulium", 168.93421},
        {70, "Yb", "Ytterbium", 173.04},
        {71, "Lu", "Lutetium", 174.967},
        {72, "Hf", "Hafnium", 178.49},
        {73, "Ta", "Tantalum", 180.94788},
        {74, "W", "Tungsten", 183.84},
        {75, "Re", "Rhenium", 186.207},
        {76, "Os", "Osmium", 190.23},
        {77, "Ir", "Iridium", 192.217},
        {78, "Pt", "Platinum", 195.084},
        {79, "Au", "Gold", 196.966569},
        {80, "Hg", "Mercury", 200.59},
        {81, "Tl", "Thallium", 204.3833},
        {82, "Pb", "Lead", 207.2},
        {83, "Bi", "Bismuth", 208.9804},
        {84, "Po", "Polonium", 209},
        {85, "At", "Astatine", 210},
        {86, "Rn", "Radon", 222},
        {87, "Fr", "Francium", 223},
        {88, "Ra", "Radium", 226},
        {89, "Ac", "Actinium", 227},
        {90, "Th", "Thorium", 232.03806},
        {91, "Pa", "Protactinium", 231.03588},
        {92, "U", "Uranium", 238.02891},
        {93, "Np", "Neptunium", 237.0482},
        {94, "Pu", "Plutonium", 244},
        {95, "Am", "Americium", 243},
        {96, "Cm", "Curium", 247},
        {97, "Bk", "Berkelium", 247},
        {98, "Cf", "Californium", 251},
        {99, "Es", "Einsteinium", 252},
        {100, "Fm", "Fermium", 257},
        {101, "Md", "Mendelevium", 258},
        {102, "No", "Nobelium", 259},
        {103, "Lr", "Lawrencium", 262},
        {104, "Rf", "Rutherfordium", 261},
        {105, "Db", "Dubnium", 262},
        {106, "Sg", "Seaborgium", 269},
        {107, "Bh", "Bohrium", 264},
        {108, "Hs", "Hassium", 269},
        {109, "Mt", "Meitnerium", 278},
        {110, "Ds", "Darmstadtium", 281},
        {111, "Rg", "Roentgenium", 282},
        {112, "Cn", "Copernicium", 285},
        {113, "Nh", "Nihonium", 286},
        {114, "Fl", "Flerovium", 289},
        {115, "Mc", "Moscovium", 289},
        {116, "Lv", "Livermorium", 293},
        {117, "Ts", "Tennessine", 294},
        {118, "Og", "Oganesson", 294}
        };

        /*kumpulan elemen dan massa relatifnya untuk program 2, 
        di sini kita memakai pembulatan untuk menghasilkan perhitungan praktis*/  
        Elemen tabel[] = {
        {"H", 1}, 
        {"He", 4}, 
        {"Li", 6}, 
        {"Be", 9}, 
        {"B", 11},
        {"C", 12}, 
        {"N", 14}, 
        {"O", 16}, 
        {"F", 19}, 
        {"Ne", 20},
        {"Na", 23}, 
        {"Mg", 24}, 
        {"Al", 27}, 
        {"Si", 28}, 
        {"P",  31},
        {"S",  32}, 
        {"Cl", 35}, 
        {"K",  39}, 
        {"Ar", 40}, 
        {"Ca", 40},
        {"Sc", 45}, 
        {"Ti", 48}, 
        {"V",  51}, 
        {"Cr", 52}, 
        {"Mn", 55},
        {"Fe", 56}, 
        {"Co", 59}, 
        {"Ni", 59}, 
        {"Cu", 64}, 
        {"Zn", 65},
        {"Ga", 70}, 
        {"Ge", 73}, 
        {"As", 75}, 
        {"Se", 79}, 
        {"Br", 80},
        {"Kr", 84}, 
        {"Rb", 85}, 
        {"Sr", 88}, 
        {"Y",  89}, 
        {"Zr", 91},
        {"Nb", 93}, 
        {"Mo", 96}, 
        {"Tc", 98}, 
        {"Ru", 101}, 
        {"Rh", 103},
        {"Pd", 106}, 
        {"Ag", 108}, 
        {"Cd", 112}, 
        {"In", 115}, 
        {"Sn", 119},
        {"Sb", 122}, 
        {"I",  127}, 
        {"Te", 128}, 
        {"Xe", 131}, 
        {"Cs", 133},
        {"Ba", 137}, 
        {"La", 139}, 
        {"Ce", 140}, 
        {"Pr", 140}, 
        {"Nd", 144},
        {"Pm", 145}, 
        {"Sm", 150}, 
        {"Eu", 152}, 
        {"Gd", 157}, 
        {"Tb", 159},
        {"Dy", 163}, 
        {"Ho", 165}, 
        {"Er", 167}, 
        {"Tm", 169}, 
        {"Yb", 173},
        {"Lu", 175}, 
        {"Hf", 178}, 
        {"Ta", 181}, 
        {"W",  184}, 
        {"Re", 186},
        {"Os", 190}, 
        {"Ir", 192}, 
        {"Pt", 195}, 
        {"Au", 197}, 
        {"Hg", 201},
        {"Tl", 204}, 
        {"Pb", 207}, 
        {"Bi", 209}, 
        {"Po", 209}, 
        {"At", 210},
        {"Rn", 222}, 
        {"Fr", 223}, 
        {"Ra", 226}, 
        {"Ac", 227}, 
        {"Th", 232},
        {"Pa", 231}, 
        {"U",  238}, 
        {"Np", 237}, 
        {"Pu", 244}, 
        {"Am", 243},
        {"Cm", 247}, 
        {"Bk", 247}, 
        {"Cf", 251}, 
        {"Es", 252}, 
        {"Fm", 257},
        {"Md", 258}, 
        {"No", 259}, 
        {"Lr", 266},
    };
    
    int pilihan;
    do {
        // Tampilkan menu pilihan
        cout << "==============================" << endl;
        cout << "  PROGRAM SISTEM KIMIA UNSUR  " << endl;
        cout << "==============================" << endl;
        cout << endl;
        cout << "Pilih opsi berikut: " << endl;
        cout << endl;
        cout << "1. Tentukan Unsur Berdasarkan Nomor Atom" << endl;
        cout << "2. Hitung Massa Relatif Senyawa (Mr)" << endl;
        cout << "3. Keluar" << endl;
        cout << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                int nomorAtom;
                cout << "Masukkan nomor atom elemen: ";
                cin >> nomorAtom;
                cout << endl;
                menentukanTabelPeriodik(elements, sizeof(elements) / sizeof(elements[0]), nomorAtom);
                break;
            }
            case 2: {
                string senyawa;
                cout << "Masukkan rumus senyawa (misal: H2O, Mg(OH)2, CH3COOH): ";
                cin >> senyawa;
                

                double massaRelatif = hitungMr(senyawa, tabel, sizeof(tabel) / sizeof(tabel[0]));
                if (massaRelatif != -1) {
                    cout << "Massa relatif senyawa " << senyawa << " adalah: " << massaRelatif << endl;
                    cout << endl;
                    cout << "===================" << endl;
                    cout << "  PROGRAM SELESAi  " <<endl;
                    cout << "===================" << endl;
                    cout << "     THANK YOU     " << endl;
                    cout << "===================" << endl;
                    exit(0); // Keluar dari program setelah perhitungan massa relatif
                }
                break;
            }
            case 3:
                cout << endl;
            cout << "===================" << endl;
            cout << "KELUAR DARI PROGRAM" <<endl;
            cout << "===================" << endl;
            cout << "     THANK YOU     " << endl;
            cout << "===================" << endl;
                break;
            default:
                cout << "-----------------------------------------" << endl;
                cout << " Pilihan tidak valid. Silakan coba lagi. " << endl;
                cout << "-----------------------------------------" << endl;
                cout << endl;
        }
    } while (pilihan != 3);

    return 0;
}
