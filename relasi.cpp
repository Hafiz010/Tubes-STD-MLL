#include <iostream>
#include "relasi.h"
#include <cstdio>
using namespace std;

void createlistR(ListR &LR){
    first(LR)=NULL;
}
adrrelasi createelemenR(adrdrgigi DR, adrpasien P){
    adrrelasi R = new elmrelasi;
    infoP(R) = P;
    infoDR(R) = DR;
    next(R) = NULL;
    return R;
}
void inserlastR(ListR &LR, adrrelasi P){
    if (first(LR)== NULL){
        first(LR) = P;
    }else{
        adrrelasi Q = first(LR);
        while(next(Q)!=NULL){
            Q = next(Q);
        }
        next(Q) = P;
    }
}
void deletefirstR(ListR &LR, adrrelasi &P){
    if (first(LR) != NULL){
        P = first(LR);
        first(LR) = next(P);
        next(P) = NULL;
        delete P;
    }
}
void deletelastR(ListR &LR, adrrelasi &P){
    P = first(LR);
    if(P!=NULL){
        while(next(P)!=NULL){
            P = next(P);
        }
        adrrelasi Q = next(P);
        next(P)=NULL;
        delete Q;
    }
}
void deleteafterR(ListR &LR, adrrelasi prec, adrrelasi &P){
    if (prec != NULL && next(prec) != NULL) {
        P = next(prec);
        next(prec) = next(P);
        next(P) = NULL;
        delete P;
    }
}
adrrelasi findR(ListR LR, adrdrgigi DR, adrpasien P){
    adrrelasi Q = first(LR);
    while(next(Q)!=NULL){
        if(infoDR(Q)==DR && infoP(Q)==P){
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}
void printR(ListR LR){
    adrrelasi P = first(LR);
    while(P!=NULL){
        cout<<infoDR(P)<<"->"<<infoP(P)<<endl;
        P=next(P);
    }
}

void showAllChildFromAllParent(ListDR LDR, ListP LP, ListR LR){
    adrdrgigi P = first(LDR);
    int i = 1;
    printf("-------------------------\n");
    printf("    DOKTER dan PASIEN    \n");
    printf("-------------------------\n");
    if(P==NULL){
        cout<<"Tidak ada relasi Dokter dan Pasien dalam List\n";
    }
    while(P != NULL) {
        printf(" %d. %s : ", i, infoDR(P).nama.c_str());
        adrrelasi R = first(LR);
        int n = 0;
        while(R != NULL){
            if (infoDR(R) == P){
                cout << infoP(infoRP(R)).nama << ", ";
                n++;
            }
            R = next(R);
        }
        i++;
        if (n >= 1){
            cout << "\b\b" << ".";
        }
        cout << endl;
        P = nextDR(P);
    }
    cout<<endl<<endl;
};
void tambahrelasi(ListDR &LDR, ListP &LP, ListR &LR){
    int idDR,idP;
    cout<<"Masukkan ID Dokter untuk membuat relasi: ";
    cin>>idDR;
    cout<<"Masukkan ID Pasien untuk membuat relasi: ";
    cin>>idP;
    adrdrgigi DR = findDR(LDR,idDR);
    adrpasien P = findP(LP,idP);
    if (DR ==NULL){
        cout<<"Dokter dengan ID: "<<idDR<<" tidak ditemukan\n\n";
        return;
    }
    adrrelasi R = createelemenR(DR,P);
    inserlastR(LR, R);
}
void menu(){
    cout<<"===========MENU==========="<<endl;
    cout<<"1.Tambah Dokter Gigi"<<endl;
    cout<<"2.Tampilkan Semua Dokter Gigi"<<endl;
    cout<<"3.Cari Dokter Gigi"<<endl;
    cout<<"4.Tampilkan Pasien dari Dokter Tertentu"<<endl;
    cout<<"5.Tambah Pasien"<<endl;
    cout<<"6.Tampilkan Semua Pasien"<<endl;
    cout<<"7.Cari Pasien"<<endl;
    cout<<"8.Hitung Pembayaran pasien"<<endl;
    cout<<"9.Tambah Relasi Dokter dengan Pasien"<<endl;
    cout<<"10.Ubah data Dokter"<<endl;
    cout<<"11.Ubah data Pasien"<<endl;
    cout<<"12.Delete Relasi"<<endl;
    cout<<"13.Hitung banyak Pasien"<<endl;
    cout<<"0.EXIT"<<endl;
    cout<<"Pilih Menu: ";
}
