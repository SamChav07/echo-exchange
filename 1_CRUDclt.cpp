#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "structs.h"

using namespace std;

int lastRegClt = 0;
int proxIDclt = 123;

void addClt(cliente currentClt);
void initClt(int cltPos);
void showClt(int pos);
void showALLclt(int pos);
void showCltRegister();
cliente getClt(int pos);
void searchCltname(char *enteredClt_name, bool esStr);
void searchCltlstname(char *enteredClt_lstName, bool esStr);
int searchCltId(int enteredClt_id);
void searchCltmail(char *enteredClt_mail);
int searchCltelf(int enteredClt_telf);
void uptdClt(cliente currentClt, int i);
void delClt(int pos);

// codigos colores ANSI
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

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
        cout <<YELLOW<< "No se encontraron resultados..." <<RESET<< endl;
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
        cout <<YELLOW<< "No se encontraron resultados..." <<RESET<< endl;
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
        cout <<YELLOW<< "No se encontraron resultados..." <<RESET<< endl;
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
        cout <<YELLOW<< "No hay registros " <<RESET<< endl;
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
    cout << BLUE << "            ||==============================================================||" << RESET << endl;
    cout << BLUE << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << BLUE << BOLD << "------------------------||" << RESET <<endl;
    cout << BLUE << "            ||                                                              ||" << RESET << endl;
    cout << BLUE << "            ||"<<RESET<<BOLD<<"                       DATOS DE CLIENTE                       "<<RESET<<BLUE<<"||" << RESET << endl;
    cout << BLUE << BOLD << "            ||______________________________________________________________||" << endl;
    cout << BLUE << BOLD << "            ||--------------------------------------------------------------||" << endl;
    cout << BLUE << "            ||             "<<RESET<<CYAN<<"ID: "<<RESET<< clt[pos].client_id <<"                                          ||" << endl;
    cout << BLUE << "            ||             "<<RESET<<CYAN<<"NOMBRE: "<<RESET<< clt[pos].client_name <<" "<< clt[pos].client_lastname <<"              ||" << endl;
    cout << BLUE << "            ||             "<<RESET<<CYAN<<"E-MAIL: "<<RESET<< clt[pos].client_mail << clt[pos].client_lastname <<"              ||" << endl;
    cout << BLUE << "            ||             "<<RESET<<CYAN<<"TELEFONO: "<<RESET<< clt[pos].client_telf << clt[pos].client_lastname <<"                ||" << endl;
    cout << BLUE << "            ||==============================================================||" << RESET << endl;

    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
    system("cls || clear");
}

void showALLclt(int pos)
{

    // Imprimir datos de cada cliente en la tabla
    for (int i = 0; i < lastRegClt; i++)
    {
        cout << BLUE << "            ||" << setfill('+') << setw(220) << "||" << endl;
        cout << "            ||" << setw(50) << clt[i].client_id <<"||"<< setw(100) << clt[i].client_name << " " << clt[i].client_lastname << "||" << setw(50) << clt[i].client_mail << "||" << setw(20) << clt[i].client_telf << "||" << endl;
    }
}

void showCltRegister()
{
    system("cls || clear");
    if (lastRegClt == 0)
    {
        cout << YELLOW << "No hay registros" << RESET << endl;
        return;
    }

    // Encabezado del registro de clientes
    cout << "Registro de Clientes: " << endl;
    cout << BLUE << "            ||" << setw(50) << " ID "<< "||" << setw(100) << " NOMBRE "<< "||" << setw(50) << " E-MAIL "<< "||" << setw(20) << " TELEFONO "<< "||" << endl;
    cout << BLUE << "            ||==============================================================||" << RESET << endl;

    // Imprimir datos de cada cliente en el registro
    for (int i = 0; i < lastRegClt; i++)
    {
        cout << "Cliente #" << i + 1 << endl;
        showALLclt(i);
    }
    cout << BLUE << "            ||==============================================================||" << RESET << endl;
    cout << GREEN << "Ultimo registro..." << RESET << endl;
}
