#include <iostream>
#include "drgigi.h"

using namespace std;

void createlistDR(ListDR &LDR){
    first(LDR) = NULL;
}

adrdrgigi createelemenDR(infotypeDR x){
    adrdrgigi p = new elmdrgigi;
    infoDR(p) = x;
    nextDR(p) = NULL;
    return p;
}

void insertlastDR(ListDR &LDR, adrdrgigi P){
    if (first(LDR) == NULL){
        first(LDR) = P;
    }else {
        adrdrgigi Q;
        Q = first(LDR);
        while (nextDR(Q) != NULL){
            Q = nextDR(Q);
        }
        nextDR(Q) = P;
    }
}

void deletefirstDR(ListDR &LDR, adrdrgigi &P){
    P = first(LDR);
    first(LDR) = nextDR(P);
    nextDR(P) = NULL;
}

void deletelastDR(ListDR &LDR, adrdrgigi &P){
    P = first(LDR);
    if (P != NULL){
        while (nextDR(P) != NULL){
            P = nextDR(P);
        }
        nextDR(P) = NULL;
    }
}

void deleteafterDR(ListDR &LDR, adrdrgigi prec, adrdrgigi &P){
    if (prec != NULL && nextDR(prec) != NULL) {
        P = nextDR(prec);
        nextDR(prec) = nextDR(P);
        nextDR(P) = NULL;
    }
}

adrdrgigi findDR(ListDR LDR, int ID){
    adrdrgigi P = first(LDR);
    while (P != NULL){
        if (infoDR(P).ID == ID){
            return P;
        }
        P = nextDR(P);
    }
    return NULL;
}

void printDR(ListDR LDR) {
    adrdrgigi P = first(LDR);
    if(P==NULL){
        cout<<"\nTidak ada dokter dalam List\n";
    }else{
        cout<<"======PASIEN======\n";
    }
    while (P != NULL){
        cout<<endl<<endl<<"=========PASIEN========="<<endl;
        cout<<"Nama             : "<<infoDR(P).nama<<endl;
        cout<<"Jam Kerja        : "<<infoDR(P).jamkerja<<endl;
        cout<<"ID Dokter        : "<<infoDR(P).ID<<endl;
        P = nextDR(P);
    }
    cout<<endl<<endl;
}

void updateDR(ListDR &LDR, int ID){
    cout<<endl<<endl;
    int i;
    adrdrgigi P = findDR(LDR,ID);
    if (P != NULL) {
        cout<<"Data apa yang ingin diubah?"<<endl<<"1.Nama"<<endl<<"2.Jam Kerja"<<endl<<"3.ID Dokter"<<endl<<"0.Exit"<<endl<<"Masukkan : ";
        cin>>i;
        while(i!=0 && i<4){
            if (i==1){
                cout<<"Masukkan Nama baru: ";
                string nama;
                cin>> nama;
                infoDR(P).nama = nama;
            }else if(i==2){
                cout<<"Masukkan Jam kerja terbaru: ";
                string jadwal;
                getline(cin,jadwal);
                infoDR(P).jamkerja = jadwal;
            }else if (i==3){
                cout<<"Masukkan ID baru: ";
                int id;
                cin>> id;
                infoDR(P).ID = id;
            }
            cout<<"\n\nApakah masih ingin mengubah?"<<endl<<"1.Nama"<<endl<<"2.Jam Kerja"<<endl<<"3.ID Dokter"<<"0.Exit"<<endl<<"Masukkan : ";
            cin>>i;
        }
    }else {
        cout<<"Data tidak ditemukan!"<<endl;
    }
    cout<<endl<<endl;
}
