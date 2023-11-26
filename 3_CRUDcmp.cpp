#include <iostream>
#include <fstream>
#include "structs.h"
#include "archivos.cpp"

using namespace std;

int lastREgCmp = 0;
int idCmp = 0;

void addCmp(reg_compra currentCmp);
void showCmpRegister(int enteredCltid, int pos);
void showCmp(int pos);
reg_compra getCmp(int pos);
int searCmpFID(int enteredCltid);

void addCmp(reg_compra currentCmp)
{
    if (lastREgCmp < MAX)
    {
        cmp[lastREgCmp] = currentCmp;
        lastREgCmp++;
    }
    else
    {
        cout << "El Registro de compras esta en Maxima capacidad..." << endl;
    }
}

void showCmpRegister(int enteredCltid, int pos) {
    readCMP();
    if (lastREgCmp == 0) {
        cout << "No hay registros" << endl;
        return;
    }
    bool found = false;
    cout << "Registro de compras para el cliente con ID " << enteredCltid << ":\n";
    cout << "====================================" << endl;

    for (int i = 0; i < lastREgCmp; i++) {
        if (cmp[i].clt.client_id == enteredCltid) {
            showCmp(i);
            found = true;
        }
    }
    cout << "====================================" << endl;
    cout << "Ultimo registro..." << endl;
    if (!found) {
        cout << "No hay registros para este cliente." << endl;
    }
}


void showCmp(int pos) // muestra los datos del cliente en X posición
{
    readCMP();
    cout << "====================================" << endl;
    cout << "N* de Recibo: " << cmp[pos].cmpr_id << endl;
    cout << "Fecha de compra: " << cmp[pos].fCmp.day << " - " << cmp[pos].fCmp.month << " - " << cmp[pos].fCmp.year << endl;
    cout << "Monto de compra: C$ " << cmp[pos].cmpr_Sqty << endl;
    cout << "Iva: C$ " << cmp[pos].cmp_iva << endl;
    cout << "Total: C$ " << cmp[pos].cmpr_Tqty << endl;
    cout << "Puntos por compra: " << cmp[pos].cmpr_pts << " pts" << endl;
    cout << "====================================" << endl;
}

reg_compra getCmp(int pos)
{
    return cmp[pos];
}

int searCmpFID(int enteredCltid)
{
    int position;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (enteredCltid == cmp[i].clt.client_id)
        {
            position = i;
            break;
        }
    }
    return position;
}