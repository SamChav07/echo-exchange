#include <iostream>
#include <cstring>
#include <string>
#include "structs.h"

using namespace std;

int lasTregGft = 0;
int idGft = 321;

void addGft(gift currentGft);
void initGft(int gftPos);
void showGft(int gftPos);
void showGftRegister();
gift getGft(int gftPos);
void searchGFTname(const char *enteredGft_name, bool esStr);
int searchGFTid(int entered_id);
void uptGFT(gift currentGft, int gftPos);
void delGFT(int gftPos);

void addGft(gift currentGft)
{
    if (lasTregGft < MAX)
    {
        currentGft.gft_id = idGft;
        gft[lasTregGft] = currentGft;
        lasTregGft++;
        idGft++;
    }
    else
    {
        cout << "Recompensas alcanzó su capacidad máxima..." << endl;
    }
}

void initGft(int gftPos)
{
    gft[gftPos].gft_id = 0;
    strcpy(gft[gftPos].gft_name, "");
    gft[gftPos].gft_cant = 0;
    gft[gftPos].gft_pts = 0;
    gft[gftPos].gft_Mney = 0;
}

gift getGft(int gftPos)
{
    return gft[gftPos];
}

void searchGFTname(const char *enteredGft_name, bool esStr = false)
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
        if (entered_id == gft[i].gft_id)
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

void delGFT(int gftPos)
{
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
    cout << "ID: " << gft[gftPos].gft_id << endl;
    cout << "Nombre: " << gft[gftPos].gft_name << endl;
    cout << "Cantidad: " << gft[gftPos].gft_cant << endl;
    cout << "Puntos Necesarios: " << gft[gftPos].gft_pts << endl;
    cout << "Precio: C$ " << gft[gftPos].gft_Mney << endl;
}

void showGftRegister()
{
    system("cls || clear");
    if (lasTregGft == 0)
    {
        cout << "No hay Recompensas registradas" << endl;
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
    cout << "Último registro..." << endl;
}
