#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "drgigi.h"
#include "pasien.h"
#define infoRP(P) P->infoP
#define next(P) P->next
#define first(L) L.first

typedef struct elmrelasi *adrrelasi;

struct elmrelasi{
    adrrelasi next;
    adrpasien infoP;
    adrdrgigi infoDR;
};

struct ListR {
    adrrelasi first;
};

void createlistR(ListR &LR);
adrrelasi createelemenR(adrdrgigi DR, adrpasien P);
void inserlastR(ListR &LR, adrrelasi P);
void deletefirstR(ListR &LR, adrrelasi &P);
void deletelastR(ListR &LR, adrrelasi &P);
void deleteafterR(ListR &LR, adrrelasi prec, adrrelasi &P);
adrrelasi findR(ListR LR, adrdrgigi DR, adrpasien P);
void printR(ListR LR);
void showAllChildFromAllParent(ListDR LDR, ListP LP, ListR LR);
void tambahrelasi(ListDR &LDR, ListP &LP, ListR &LR);
void menu();
#endif // RELASI_H_INCLUDED
