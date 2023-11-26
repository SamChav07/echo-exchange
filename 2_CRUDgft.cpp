#include <iostream>
#include <cstring>
#include <string>
#include "structs.h"

using namespace std;

int lasTregGft = 0;
int idGft = 321;

void addGft(gift currentGft);
void initGft(int gftPos);
void showGft(int pos);
void showGftRegister();
gift getGft(int pos);
void searchGFTname(char *enteredGft_name, bool esStr);
int searchGFTid(int entered_id);
void uptGFT(gift currentGft, int i);
void delGFT(int pos);

void addGft(gift currentGft)
{
    if (lasTregGft < MAX)
    {
        gft[lasTregGft] = currentGft;
        lasTregGft++;
        idGft++;
    }
    else
    {
        cout << "Recompensas esta en Maxima capacidad..." << endl;
    }
}
void initGft(int gftPos)
{
    gft[gftPos].gft_id = 0;

    strncpy(gft[gftPos].gft_name, "", sizeof(gft[gftPos].gft_name));

    gft[gftPos].gft_cant = 0;

    gft[gftPos].gft_pts = 0;
}

gift getGft(int gftPos)
{
    return gft[gftPos];
}

void searchGFTname(char *enteredGft_name, bool esStr = false)
{
    int position = 0;
    for (int i = 0; i < lasTregGft; i++)
    {
        if ((esStr && strstr(gft[i].gft_name, enteredGft_name)) || (!esStr && strcmp(enteredGft_name, gft[i].gft_name) == 0))
        {
            cout << "====" << endl;
            showGft(i);
            position++;
        }
    }
    if (position == 0)
    {
        cout << "No se encontraron resultados..." << endl;
    }
}

int searchGFTid(int entered_id)
{
    int position = -1;
    for (int i = 0; i < lasTregGft; i++)
    {
        if (entered_id == (gft[i].gft_id))
        {
            position = i;
            break;
        }
    }
    return position;
}

void uptGFT(gift currentGft, int gftPos)
{
    gft[gftPos] = currentGft;
}

void delGFT(int gftPos) {
    if (gftPos == lasTregGft)
    {
        cout << "No hay registros..." << endl;
        return;
    }
    for (int i = gftPos; i < lasTregGft - 1; i++)
    {
        gft[i] = gft[i + 1];
    }
    lasTregGft--;
    idGft--;
    initGft(lasTregGft);
}

void showGft(int gftPos)
{
    system("cls || clear");
    cout << "====================================" << endl;
    cout << "ID: ";
    cout << gft[gftPos].gft_id << endl;
   cout << "Nombre: ";
    cout << gft[gftPos].gft_name << endl;
    cout << "Cantidad: ";
    cout << gft[gftPos].gft_cant << endl;
    cout << "Puntos Necesarios: ";
    cout << gft[gftPos].gft_pts << endl;

    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
    system("cls || clear");
}

void showGftRegister()
{
    system("cls || clear");
    if (lasTregGft == 0)
    {
        cout << "No hay Recompenas registradas" << endl;
        return;
    }
    cout << "Registro de Recompensas: " << endl;
    cout << "====================================" << endl;

    for (int i = 0; i < lasTregGft; i++)
    {
        cout << "Recompensa #" << i + 1 << endl;
        showGft(i);
    }
    cout << "====================================" << endl;
    cout << "Ultimo registro..." << endl;
}