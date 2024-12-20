#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED
#include <iostream>
#define infoP(P) P-> infoP
#define nextP(P) P-> nextP
#define prevP(P) P->prevP
#define first(L) L.first
#define last(L) L.last

using namespace std;

struct pasien{
    string nama;
    string TTL;
    string alamat;
    string kelamin;
    int usia;
    string keterangan;
    int ID;
    int totharga;
};

typedef struct pasien infotypeP;
typedef struct elmpasien *adrpasien;

struct elmpasien{
    infotypeP infoP;
    adrpasien nextP;
    adrpasien prevP;
};

struct ListP{
    adrpasien first;
    adrpasien last;
};

void createlistP(ListP &LP);
adrpasien createelemenP(infotypeP x);
void insertlastP(ListP &LP, adrpasien P);
void deletefirstP(ListP &LP, adrpasien &P);
void deletelastP(ListP &LP, adrpasien &P);
void deleteafterP(ListP &LP, adrpasien prec, adrpasien &P);
adrpasien findP(ListP LP, int ID);
void printP(ListP LP);
void updateP(ListP &LP, int ID);
int totalP(ListP LP);
int hitungperawatan(ListP &LP,int ID);

#endif // PASIEN_H_INCLUDED
