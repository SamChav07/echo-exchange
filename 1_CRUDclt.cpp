#include <iostream>
#include <cstring>
#include <string>
#include "structs.h"

using namespace std;

int lastRegClt = 0;
int proxIDclt = 123;

void addClt(cliente currentClt);
void initClt(int cltPos);
void showClt(int pos);
void showCltRegister();
cliente getClt(int pos);
void searchCltname(char *enteredClt_name, bool esStr);
void searchCltlstname(char *enteredClt_lstName, bool esStr);
int searchCltId(int enteredClt_id);
void searchCltmail(char *enteredClt_mail);
int searchCltelf(int enteredClt_telf);
void uptdClt(cliente currentClt, int i);
void delClt(int pos);

void addClt(cliente currentClt)
{
    if (lastRegClt < MAX)
    {
        clt[lastRegClt] = currentClt;
        lastRegClt++;
        proxIDclt++;
    }
    else
    {
        cout << "Clientes esta en Maxima capacidad..." << endl;
    }
}

void initClt(int pos) // inicializa los datos del cliente
{
    clt[pos].client_id = 0;

    strncpy(clt[pos].client_name, "", sizeof(clt[pos].client_name));

    strncpy(clt[pos].client_lastname, "", sizeof(clt[pos].client_lastname));

    strncpy(clt[pos].client_mail, "", sizeof(clt[pos].client_mail));

    clt[pos].client_telf = 0;
}

cliente getClt(int pos)
{
    return clt[pos];
}

void searchCltname(char *enteredClt_name, bool esStr = false) // funcion de prueba
{
    int position = 0;
    for (int i = 0; i < lastRegClt; i++)
    {
        if ((esStr && strstr(clt[i].client_name, enteredClt_name) != nullptr) || (!esStr && strcmp(enteredClt_name, clt[i].client_name) == 0))
        {
            cout << "=====" << endl;
            showClt(i);
            position++;
        }
    }
    if (position == 0)
    {
        cout << "No se encontraron resultados..." << endl;
    }
}

void searchCltlstname(char *enteredClt_lstName, bool esStr = false) // funcion de prueba
{
    int position = 0;
    for (int i = 0; i < lastRegClt; i++)
    {
        if ((esStr && strstr(clt[i].client_lastname, enteredClt_lstName) != nullptr) || (!esStr && strcmp(enteredClt_lstName, clt[i].client_lastname) == 0))
        {
            cout << "=========================" << endl;
            showClt(i);
            position++;
        }
    }
    if (position == 0)
    {
        cout << "No se encontraron resultados" << endl;
    }
}

int searchCltId(int enteredClt_id) // esta funcional
{
    int position = -1;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (enteredClt_id == (clt[i].client_id))
        {
            position = i;
            break;
        }
    }
    return position;
}

void searchCltmail(char *enteredClt_mail) // prueba
{
    int position = 0;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (strcmp(enteredClt_mail, clt[i].client_mail) == 0)
        {
            showClt(i);
            position++;
        }
    }
    if (position == 0)
    {
        cout << "No se encontraron resultados" << endl;
    }
}

int searchCltelf(int enteredClt_telf) // prueba
{
    int position = -1;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (enteredClt_telf == (clt[i].client_telf))
        {
            position = i;
            break;
        }
    }
    return position;
}

void uptdClt(cliente currentClt, int pos)
{
    clt[pos] = currentClt;
}

void delClt(int pos)
{
    if (pos == lastRegClt)
    {
        cout << "No hay registros " << endl;
        return;
    }
    for (int i = pos; i < lastRegClt - 1; i++)
    {
        clt[i] = clt[i + 1];
    }
    lastRegClt--;
    proxIDclt--;
    initClt(lastRegClt);
}

void showClt(int pos) // muestra los datos del cliente en X posición
{
    system("cls || clear");
    cout << "====================================" << endl;
    cout << "ID: ";
    cout << clt[pos].client_id << endl;
    cout << "Nombre: ";
    cout << clt[pos].client_name << endl;
    cout << "Apellido: ";
    cout << clt[pos].client_lastname << endl;
    cout << "E-mail: ";
    cout << clt[pos].client_mail << endl;
    cout << "Telefono: ";
    cout << clt[pos].client_telf << endl;

    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
    system("cls || clear");
}

void showCltRegister()
{
    system("cls || clear");
    if (lastRegClt == 0)
    {
        cout << "No hay registros" << endl;
        return;
    }
    cout << "Registro de Clientes: " << endl;
    cout << "====================================" << endl;

    for (int i = 0; i < lastRegClt; i++)
    {
        cout << "Cliente #" << i + 1 << endl;
        showClt(i);
    }
    cout << "====================================" << endl;
    cout << "Ultimo registro..." << endl;
}