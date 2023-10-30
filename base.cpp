#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
#include "data.h"
using namespace std;

//LOG
void login();
void log_clt();
void log_adm();
bool verification_clt();
bool verification_adm();

//menus
void searchMclt();  //menu de busqueda de cliente

//CRUD clientes
//create
void addClt();
void initClt(int cltPos);
//read
void showClt()
void searchCltname(char client_name[]);
void searchCltlstname(int client_lstName[]);
int searchCltId(int client_id);
void searchCltmail(char client_mail[]);
int searchCltelf(char client_telf[]);
//uptade
void uptdClt();
//delete
void delClt();

//funciones 
void admin();
void clientS();
void regPurchase();
void client();
void rewards();
void redeem();
void checkPts();
void record();

//variables globales 
int lastReg = 1;

int main()
{

}

void addClt(clt currentClt)
{
    clt[lastReg] = currentClt;
    lastReg++;
}

void initClt(int cltPos)    //inicializa los datos del cliente
{
    strcpy(clt[cltPos].client_id, "");
    strcpy(clt[cltPos].client_name, "");
    strcpy(clt[cltPos].client_lstName, "");
    strcpy(clt[cltPos].client_mail, "");
    strcpy(clt[cltPos].client_telf, "");
}

void searchMclt()
{
    int options, pos;
    char enteredClt_name[20];
    char enteredClt_lstName[20];
    int enteredClt_id;
    char enteredClt_mail[50];
    char enteredClt_telf[15];
    
    do{
        system("cls || clear");
        cout <<"** Menu de busqueda **"<<endl;
        cout <<"1. Nombre."<<endl;
        cout <<"2. Apellido."<<endl;
        cout <<"3. Id."<<endl;
        cout <<"4. E-mail."<<endl;
        cout <<"5. Telefono."<<endl;
        cout <<"6. Mostrar todos los registros."<<endl;
        cout <<"7. Cerrar Sesion."<<endl;
        cout <<"Seleccione una opcion: ";
        cin >> options;
        
        switch (options)
        {
        case 1:
            system("cls || clear");
            cout << "Buscar por nombre de Cliente" << endl;
            cout << "Nombre a buscar: ";
            scanf(" %[^\n]", enteredClt_name[20]);
            searchCltname(enteredClt_name[20]);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 2:
            system("cls || clear");
            cout << "Buscar por apellido de Cliente" << endl;
            cout << "Apellido a buscar: ";
            scanf(" %[^\n]", enteredClt_lstName[20]);
            searchCltlstname(enteredClt_lstName[20]);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 3:
            system("cls || clear");
            cout << "Buscar por id de Cliente" << endl;
            cout << "ID a buscar: ";
            scanf(" %[^\n]", enteredClt_id);
            searchCltId(enteredClt_id);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 4:
            system("cls || clear");
            cout << "Buscar por e-mail de Cliente" << endl;
            cout << "E-mail a buscar: ";
            scanf(" %[^\n]", enteredClt_mail[50]);
            searchCltmail(enteredClt_mail[50]);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 5:
            system("cls || clear");
            cout << "Buscar por telefono de Cliente" << endl;
            cout << "Telefono a buscar: ";
            scanf(" %[^\n]", enteredClt_telf[15]);
            searchCltelf(enteredClt_telf[15]);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 6:
            system("cls || clear");
            cout << "Visualizando todos los registros..." << endl;
            showClt()
            system("cls || clear");
            break;
        case 7:
            system("cls || clear");
            cout << "Saliendo..." << endl;
            login();
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        default:
            cout << "Opcion Invalida. Ingrese una opcion valida del 1 - 7" << endl; 
            break;
        }
        
    } while (options != 9);
}

void showClt(int pos) // mostrara todos los datos del Clt
{
    cout << endl;
    cout << "ID: " << clt[pos].client_id << endl;
    cout << "Nombre: " << clt[pos].client_name << endl;
    cout << "Apellido: " << clt[pos].client_lstName << endl;
    cout << "E-mail: " << clt[pos].client_mail << endl;
    cout << "Telefono: " << clt[pos].client_telf << endl;
}

void searchCltname(char enteredClt_name)
{
    int position = -1;
    for (int i =0; i < lastReg; i++)
    {
        if (strcmp(enteredClt_name, clt[i].client_name) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

void searchCltlstname(char enteredClt_lstName)
{
    int position = -1;
    for (int i =0; i < lastReg; i++)
    {
        if (strcmp(enteredClt_lstName, clt[i].client_lstName) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

int searchCltId(char enteredClt_id)
{
    int position = -1;
    for (int i =0; i < lastReg; i++)
    {
        if (strcmp(enteredClt_id, clt[i].client_id) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

void searchCltmail(char enteredClt_mail)//busq por mail
{
    int position = -1;
    for (int i =0; i < lastReg; i++)
    {
        if (strcmp(enteredClt_mail, clt[i].client_mail) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}

int searchCltelf(char enteredClt_telf) //busqueda por numero telef
{
    int position = -1;
    for (int i =0; i < lastReg; i++)
    {
        if (strcmp(enteredClt_telf, clt[i].client_telf) == 0)
        {
            position = i;
            break;
        }
    }
    return position;
}
