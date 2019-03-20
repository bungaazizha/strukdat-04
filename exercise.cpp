/*
Author		: Bunga Azizha N
NPM			: 140810180016
Deskripsi	: Struktur data pegawai menggunakan Single Linked List
Tahun		: 2019
*/
//exercise

#include<iostream>
using namespace std;

struct pegawai{
    char nama[30];
    char bidang[20];
    int gaji;
    pegawai* next;
};
typedef pegawai* pointer;
typedef pointer List;

void createList(List& First);
void createElmt(pointer& pBaru);
void insertFirst (List& First, pointer pBaru);
void insertLast (List& First, pointer pBaru);
void traversal (List First);
void deleteFirst(List& First, pointer& pHapus);
void deleteLast (List& First, pointer& pHapus);

main()
{
    pointer pBaru;
    List first;
    int pilihan;

    createList(first);
    while(1){
        system("cls");
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"\tMenu"<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout<<"1. Insert First "<<endl;
        cout<<"2. Insert Last "<<endl;
        cout<<"3. Delete First"<<endl;
        cout<<"4. Delete Last"<<endl;
        cout<<"5. Traversal"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"=-=-=-=-=-=-=-=-=-=-=-=-="<<endl;
        cout << "Masukan Pilihan : "; cin >> pilihan;
        cout<<endl;
        switch(pilihan){
        case 1:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 2:
            createElmt(pBaru);
            insertLast(first, pBaru);
        break;

        case 3:
            deleteFirst(first, pBaru);
        break;

        case 4:
            deleteLast(first, pBaru);
        break;

        case 5:
            traversal(first);
        break;

        case 6:
            return 0;
            break;
        }
        system("pause");
    }
}


void createList(List& First){
    First = NULL;
    }

void createElmt (pointer& pBaru){
    pBaru = new pegawai;
    cout<<"Nama     : "; cin>>pBaru->nama;  cin.ignore();
    cout<<"Bidang   : "; cin.getline(pBaru->bidang, 20);
    cout<<"Gaji     : "; cin>>pBaru->gaji;
    pBaru->next=NULL;
}

void insertFirst (List& First, pointer pBaru){
    if(First==NULL){
        First=pBaru;
    }
    else{
        pBaru->next=First;
        First=pBaru;
    }
}

void insertLast (List& First, pointer pBaru){
    pointer Last;
    if (First==NULL){
        First=pBaru;
    }
    else {
        Last=First;
        while (Last->next!=NULL){
            Last=Last->next;
        }
        Last->next=pBaru;
    }
}
void traversal (List First){
    pointer pBantu;
    pBantu=First;
    int counter=1;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"	\t	DATA KARYAWAN"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    cout<<"No\t\tNama\t\tBidang\t\tGaji"<<endl;
    cout<<"----------------------------------------------------------"<<endl;
    while(pBantu != NULL){
    		cout<<counter<<"\t\t"<<pBantu->nama<<"\t\t"<<pBantu->bidang<<"\t\t"<<pBantu->gaji<<endl;
        pBantu=pBantu->next;
        counter++;
    }
}

void deleteFirst(List& First, pointer& pHapus){
    if(First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada  yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void deleteLast (List& First, pointer& pHapus){
    pointer Last, precLast;
    if (First==NULL){
        pHapus=NULL;
        cout<<"List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else {
        Last=First;
        precLast=NULL;
        while (Last->next!=NULL){
            precLast=Last;
            Last=Last->next;
        }
        pHapus=Last;
        precLast->next=NULL;
    }
}
