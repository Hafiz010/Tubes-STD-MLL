#ifndef DRGIGI_H_INCLUDED
#define DRGIGI_H_INCLUDED
#include <iostream>
#define first(L) L.first
#define nextDR(P) P-> nextDR
#define infoDR(P) P->infoDR

using namespace std;

struct drgigi{
    string nama;
    string jamkerja;
    int ID;
};

typedef struct drgigi infotypeDR;
typedef struct elmdrgigi *adrdrgigi;

struct elmdrgigi{
    infotypeDR infoDR;
    adrdrgigi nextDR;
};

struct ListDR{
    adrdrgigi first;
};

void createlistDR(ListDR &LDR);
adrdrgigi createelemenDR(infotypeDR x);
void insertlastDR(ListDR &LDR, adrdrgigi P);
void deletefirstDR(ListDR &LDR,adrdrgigi &P);
void deletelastDR(ListDR &LDR,adrdrgigi &P);
void deleteafterDR(ListDR &LDR,adrdrgigi prec,adrdrgigi &P);
adrdrgigi findDR(ListDR LDR,int ID);
void printDR(ListDR LDR);
void updateDR(ListDR &LDR, int ID);

#endif // DRGIGI_H_INCLUDED
