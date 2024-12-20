#include <iostream>
#include "relasi.h"

using namespace std;

int main()
{
    ListDR LDR;
    ListP LP;
    ListR LR;

    createlistDR(LDR);
    createlistP(LP);
    createlistR(LR);

    menu();
    int pilihan;
    cin>> pilihan;
    while(pilihan!=0){
        switch(pilihan){
            case 1: {
                infotypeDR DR;
                cout<<"\nMasukkan nama: ";
                cin.ignore();
                getline(cin,DR.nama);
                cout<<"Masukkan Jam kerja: ";
                cin>>DR.jamkerja;
                cout<<"Masukkan ID: ";
                cin>>DR.ID;

                adrdrgigi newdr = createelemenDR(DR);
                insertlastDR(LDR,newdr);
                cout<<"Data dokter telah di input\n\n"<<endl<<endl;
                break;
            }
            case 2:{
                printDR(LDR);
                break;
            }
            case 3:{
                cout<<"Masukkan ID Dokter yang dicari: ";
                int id;
                cin>>id;
                adrdrgigi ketemu = findDR(LDR,id);
                if(ketemu != NULL){
                    cout<<endl<<endl<<"Nama             : "<<infoDR(ketemu).nama<<endl;
                    cout<<"Jam Kerja        : "<<infoDR(ketemu).jamkerja<<endl;
                    cout<<"ID Dokter        : "<<infoDR(ketemu).ID<<endl;
                }else{
                    cout<<"Dokter dengan ID "<<id<<" Tidak ditemukan"<<endl;
                }
                cout<<"\n\n";
                break;
            }
            case 4:{
                showAllChildFromAllParent(LDR,LP,LR);
                break;
            }
            case 5:{
                infotypeP PS;
                cout<<"Masukkan nama: ";
                cin.ignore();
                getline(cin,PS.nama);
                cout<<"Masukkan Tempat/Tanggal lahir: ";
                cin.ignore();
                getline(cin,PS.TTL);
                cout<<"Alamat: ";
                cin>>PS.alamat;
                cout<<"Masukkan Jenis kelamin: ";
                cin>>PS.kelamin;
                while(!(PS.kelamin =="laki" || PS.kelamin =="Laki" || PS.kelamin =="Perempuan" || PS.kelamin =="perempuan" || PS.kelamin == "Pria" || PS.kelamin == "pria" || PS.kelamin == "wanita" || PS.kelamin == "Wanita")){
                    cout<<"Masukkan tidak terhitung sebagai Jenis Kelamin"<<endl<<"Masukkan Jenis Kelamin :";
                    cin>>PS.kelamin;
                }
                cout<<"Masukkan usia: ";
                cin>> PS.usia;
                cout<<endl;
                cout<<"===== K E T E R A N G A N====="<<endl;
                cout<<"1. Gigi Berlubang"<<endl; // biaya 150.000
                cout<<"2. Bau Mulut"<<endl; // biaya 100.000
                cout<<"3. Gigi sensitif"<<endl; // biaya 120.000
                cout<<"4. Gigi tumbuh miring (gigi bungsu)"<<endl; // 500.000
                cout<<"5. Gigi Retak atau Patah"<<endl; // 250.000
                cout<<endl;
                cout<<"Masukkan nomor dengan keluhan anda : ";
                int k;
                cin>>k;
                if (k>0 && k<6){
                    if (k==1){
                        PS.keterangan = "Gigi Berlubang";
                    }else if (k==2){
                        PS.keterangan = "Bau Mulut";
                    }else if (k==3){
                        PS.keterangan = "Gigi sensitif";
                    }else if (k==4){
                        PS.keterangan = "Gigi tumbuh miring (gigi bungsu)";
                    }else if (k==5){
                        PS.keterangan = "Gigi Retak atau Patah";
                    }
                }else{
                    while(k<0 || k>6){
                        cout<<"Masukkan tidak terdaftar.\n"<<"Masukkan nomor dengan keluhan anda : ";
                        cin>>k;
                        if (k==1){
                        PS.keterangan = "Gigi Berlubang";
                        }else if (k==2){
                            PS.keterangan = "Bau Mulut";
                        }else if (k==3){
                            PS.keterangan = "Gigi sensitif";
                        }else if (k==4){
                            PS.keterangan = "Gigi tumbuh miring (gigi bungsu)";
                        }else if (k==5){
                            PS.keterangan = "Gigi Retak atau Patah";
                        }
                    }
                }
                cout<<"Masukkan ID(integer) :";
                cin>>PS.ID;
                adrpasien newp = createelemenP(PS);
                insertlastP(LP, newp);
                infoP(newp).totharga = hitungperawatan(LP,PS.ID);
                break;
            }
            case 6:{
                cout<<"\n\n";
                printP(LP);
                break;
            }
            case 7:{
                cout<<"Masukkan ID Pasien yang dicari: ";
                int id;
                cin>>id;
                adrpasien ketemu = findP(LP,id);
                cout<<"\n\n";
                if(ketemu != NULL){
                    cout<<"Nama             : "<<infoP(ketemu).nama<<endl;
                    cout<<"Tempat/Tgl lahir : "<<infoP(ketemu).TTL<<endl;
                    cout<<"Alamat           : "<<infoP(ketemu).alamat<<endl;
                    cout<<"Jenis Kelamin    : "<<infoP(ketemu).kelamin<<endl;
                    cout<<"Usia             : "<<infoP(ketemu).usia<<endl;
                    cout<<"Keterangan       : "<<infoP(ketemu).keterangan<<endl;
                    cout<<"ID Pasien        : "<<infoP(ketemu).ID<<endl;
                    cout<<"Total Harga      : "<<infoP(ketemu).totharga<<endl;
                }else{
                    cout<<"Pasien dengan ID "<<id<<" Tidak ditemukan"<<endl;
                }
                cout<<"\n\n";
                break;
            }
            case 8:{
                cout<<"Masukkan ID pasien untuk menhitung biaya: ";
                int ID;
                cin >> ID;
                printP(LP);
                int totharga = hitungperawatan(LP,ID);
                cout<<"Rp"<<totharga<<endl;
                cout<<endl<<endl;
                break;
            }
            case 9:{
                tambahrelasi(LDR,LP,LR);
                cout<<"\nRelasi telah dibuat\n\n";
                break;
            }
            case 10:{
                printDR(LDR);
                cout<<"\nMasukkan ID dokter yang ingin diubah: ";
                int id;
                cin>>id;
                updateDR(LDR,id);
                break;
            }
            case 11:{
                printP(LP);
                cout<<"\nMasukkan ID pasien yang ingin diubah: ";
                int id;
                cin>>id;
                updateP(LP,id);
                break;
            }
            case 12:{
                cout<<"Masukkan ID dokter yang ingin dihapus relasi: ";
                int idDR;
                cin>>idDR;
                cout<<"Masukkan ID pasien yang ingin dihapus relasi: ";
                int idPas;
                cin>>idPas;
                adrdrgigi DR = findDR(LDR,idDR);
                adrpasien P = findP(LP,idPas);
                adrrelasi R = findR(LR,DR,P);
                if(R == first(LR)){
                    deletefirstR(LR, R);
                }else if (next(R)==NULL){
                    deletelastR(LR, R);
                }else{
                    adrrelasi cari = first(LR);
                    while(next(cari)!=R){
                        cari = next(cari);
                    }
                    deleteafterR(LR,cari,R);
                }

                break;
            }
            case 13:{
                int total = totalP(LP);
                cout<<"\nTotal pasien: "<<total<<endl<<endl;
                break;
            }
        }
        menu();
        cin>>pilihan;
    }
    return 0;
}
