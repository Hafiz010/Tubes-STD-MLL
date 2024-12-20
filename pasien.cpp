#include <iostream>
#include "pasien.h"

using namespace std;

void createlistP(ListP &LP){
    first(LP) = NULL;
    last(LP) = NULL;
}
adrpasien createelemenP(infotypeP x){
    adrpasien P = new elmpasien;
    infoP(P) = x;
    nextP(P) = NULL;
    prevP(P) = NULL;
    return P;
}
void insertlastP(ListP &LP, adrpasien P){
    if (first(LP) == NULL && last(LP)==NULL){
        first(LP) = P;
        last(LP) = P;
    }else{
        prevP(P) = last(LP);
        nextP(last(LP)) = P;
        last(LP) = P;
    }
}
void deletefirstP(ListP &LP, adrpasien &P){
    P = first(LP);
    if (P!= NULL){
        if(first(LP)!=last(LP)){
            first(LP) = nextP(P);
            nextP(P) = NULL;
            prevP(first(LP)) = NULL;
        }else{
            first(LP) = NULL;
            last(LP) = NULL;
        }
    }else{
        P=NULL;
    }
}
void deletelastP(ListP &LP, adrpasien &P){
    P = last(LP);
    if (P!= NULL){
        if(first(LP)!=last(LP)){
            last(LP) = prevP(P);
            prevP(P) = NULL;
            nextP(last(LP)) = NULL;
        }else{
            first(LP) = NULL;
            last(LP) = NULL;
        }
    }else{
        P=NULL;
    }
}
void deleteafterP(ListP &LP, adrpasien prec, adrpasien &P){
    if (prec!=last(LP)){
        P = nextP(prec);
        if(P!=last(LP)){
            nextP(prec)= nextP(P);
            prevP(nextP(P))=prec;
            nextP(P) = NULL;
            prevP(P) = NULL;
        }else{
            last(LP)=prec;
            prevP(P) = NULL;
            nextP(prec) = NULL;
        }
        P = NULL;
    }
}
adrpasien findP(ListP LP, int ID){
    adrpasien P = first(LP);
    while(P!= NULL){
        if(infoP(P).ID ==ID){
            return P;
        }
        P = nextP(P);
    }
    return NULL;
}
void printP(ListP LP){
    adrpasien P = first(LP);
    if(P==NULL){
        cout<<"\nTidak ada pasien dalam List\n";
    }else{
        cout<<"======PASIEN======\n";
    }
    while(P!=NULL){
        cout<<"Nama             : "<<infoP(P).nama<<endl;
        cout<<"Tempat/Tgl lahir : "<<infoP(P).TTL<<endl;
        cout<<"Alamat           : "<<infoP(P).alamat<<endl;
        cout<<"Jenis Kelamin    : "<<infoP(P).kelamin<<endl;
        cout<<"Usia             : "<<infoP(P).usia<<endl;
        cout<<"Keterangan       : "<<infoP(P).keterangan<<endl;
        cout<<"ID Pasien        : "<<infoP(P).ID<<endl;
        cout<<"Total Harga      : "<<infoP(P).totharga<<endl;
        P=nextP(P);
    }
    cout<<endl<<endl;
}
void updateP(ListP &LP, int ID){
    cout<<endl;
    int i;
    string input;
    adrpasien P = findP(LP,ID);
    if (P!= NULL){
        cout<<"Data apa yang ingin diubah?"<<endl<<"1.Nama"<<endl<<"2.Tempat/Tanggal Lahir"<<endl<<"3.Alamat"<<"4.kelamin"<<endl<<"5.usia"<<endl<<"6.Keterangan"<<endl<<"0.Exit"<<endl<<"Masukkan : ";
        cin>>i;
        while(i!=0 && i<7){
            if(i==1){
                cout<<"Masukkan Nama Baru: ";
                cin>>input;
                infoP(P).nama = input;
            }else if(i==2){
                cout<<"Masukkan TTL baru: ";
                getline(cin,input);
                infoP(P).TTL = input;
            }else if(i==3){
                cout<<"Masukkan alamat baru: ";
                cin>>input;
                infoP(P).alamat = input;
            }else if(i==4){
                cout<<"Masukkan Jenis kelamin: ";
                cin>>input;
                while(input =="laki" || input =="Laki" || input =="Perempuan" || input =="perempuan" || input == "Pria" || input == "pria" || input == "wanita" || input =="Wanita"){
                    cout<<"Masukkan tidak terhitung sebagai Jenis Kelamin"<<endl<<"Masukkan Jenis Kelamin :";
                    cin>>input;
                }
                infoP(P).kelamin = input;
            }else if(i==5){
                cout<<"Masukkan usia terbaru: ";
                int umur;
                cin>>umur;
                infoP(P).usia = umur;
            }else if(i==6){
                cout<<"===== K E T E R A N G A N====="<<endl;
                cout<<"1. Gigi Berlubang"<<endl; // biaya 150.000
                cout<<"2. Bau Mulut"<<endl; // biaya 100.000
                cout<<"3. Gigi sensitif"<<endl; // biaya 120.000
                cout<<"4. Gigi tumbuh miring (gigi bungsu)"<<endl; // 500.000
                cout<<"5. Gigi Retak atau Patah"<<endl<<endl; // 250.000
                cout<<"Masukkan No sebagai Keterangan terbaru: ";
                int j;
                cin>>j;
                if (j>0 && j<6){
                    if (j==1){
                        infoP(P).keterangan = "Gigi Berlubang";
                    }else if (j==2){
                        infoP(P).keterangan = "Bau Mulut";
                    }else if (j==3){
                        infoP(P).keterangan = "Gigi sensitif";
                    }else if (j==4){
                        infoP(P).keterangan = "Gigi tumbuh miring (gigi bungsu)";
                    }else if (j==5){
                        infoP(P).keterangan = "Gigi Retak atau Patah";
                    }
                }else{
                    cout<<"Perubahan Gagal"<<endl;
                }
            }
            cout<<"Apakah Masih terdapat Data yang Ingin diubah?"<<endl<<"1.Nama"<<endl<<"2.Tempat/Tanggal Lahir"<<endl<<"3.Alamat"<<"4.kelamin"<<endl<<"5.usia"<<endl<<"6.Keterangan"<<endl<<"0.Exit"<<endl<<"Masukkan : ";
            cin>>i;
        }
    }
    cout<<"Data telah diubah"<<endl<<endl;
}

int totalP(ListP LP){
    adrpasien P = first(LP);
    int i=0;
    while(P!=NULL){
        i++;
        P=nextP(P);
    }
    return i;
}
int hitungperawatan(ListP &LP,int ID){

    cout<<endl<<endl;

    adrpasien P =findP(LP,ID);
    int total;

    if (P!=NULL){
        if (infoP(P).keterangan == "Gigi Berlubang"){
            total = 150000;
        }else if(infoP(P).keterangan =="Bau Mulut"){
            total = 100000;
        }else if(infoP(P).keterangan =="Gigi sensitif"){
            total = 120000;
        }else if(infoP(P).keterangan =="Gigi tumbuh miring (gigi bungsu)"){
            total = 500000;
        }else if(infoP(P).keterangan == "Gigi Retak atau Patah"){
            total = 250000;
        }
    }
    return total;
}
