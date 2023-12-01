#include <iostream>
#include <fstream>
#include "structs.h"
#include "archivos.cpp"

using namespace std;

int lastREgCmp = 0;
int lastRHST = 0;
reg_compra currentCmp;
historial currentHst;

void addCmp(reg_compra currentCmp);
void initCMP(int pos);
void showCmpRegister(int enteredCltid);
void showCmp(int pos);
reg_compra getCmp(int pos);
int searCmpFID(int enteredCltid);

void addHst(historial currentHst);
void initHst(int pos);

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

void addHst(historial currentHst)
{
  if(lastRHST < MAX)
  {
    hst[lastRHST] = currentHst;
    lastRHST++;
  }
  else
  {
    cout << "El registro de Historial esta en Maxima capacidad..." << endl;
  }
}

void initCMP(int pos) // inicializa los datos de compra
{
  cmp[pos].clt.client_id = 0;

  cmp[pos].cmpr_id = 0;

  cmp[pos].fCmp.day = 0;
  cmp[pos].fCmp.month = 0;
  cmp[pos].fCmp.year = 0;

  cmp[pos].cmpr_Sqty = 0;
  cmp[pos].cmpr_pts = 0;
  cmp[pos].cmp_iva = 0;
  cmp[pos].cmpr_Tqty = 0;
  
}

void initHst(int pos)
{
  hst[pos].cmp.clt.client_id = 0;
  hst[pos].cmpr_ptsTot = 0;
}

void showCmpRegister(int enteredCltid) {
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

  if (!found) {
    cout << "No hay registros para este cliente." << endl;
  }
}

void showCmp(int pos) { // muestra los datos del cliente en X posición
  readClt();
  readCMP();

  system("cls || clear");
  cout << BLUE << BOLD << " ||==============================================================||" << RESET << endl;
  cout << BLUE << BOLD << " ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << BLUE << BOLD << "------------------------||" << RESET << endl;
  cout << BLUE << BOLD << " ||______________________________________________________________||" << endl;
  cout << BLUE << BOLD << " ||--------------------------------------------------------------||" << endl;
  cout << BOLD << " || " << RESET << CYAN << "||*||" << RESET << " " << CYAN << "||*||" << CYAN << BLUE " ||" << RESET << endl;
  cout << BLUE << BOLD << " || " << RESET << " " << CYAN << "N* de Recibo: " << RESET << cmp[pos].cmpr_id << BLUE << BOLD << " ||" << RESET << endl;
  cout << BLUE << BOLD << " || " << RESET << " " << CYAN << "Fecha de compra: " << RESET << cmp[pos].fCmp.day << " - " << cmp[pos].fCmp.month << " - " << cmp[pos].fCmp.year << BLUE << BOLD << " ||" << RESET << endl;
  cout << BLUE << BOLD << " || " << RESET << " " << CYAN << "Monto de compra: C$ " << RESET << cmp[pos].cmpr_Sqty << BLUE << BOLD << " ||" << RESET << endl;
  cout << BLUE << BOLD << " || " << RESET << " " << CYAN << "Iva: C$ " << RESET << cmp[pos].cmp_iva << BLUE << BOLD << " ||" << RESET << endl;
  cout << BLUE << BOLD << " || " << RESET << " " << CYAN << "Total: C$ " << RESET << cmp[pos].cmpr_Tqty << BLUE << BOLD << " ||" << RESET << endl;
  cout << BLUE << BOLD << " || " << RESET << " " << CYAN << "Puntos por compra: " << RESET << cmp[pos].cmpr_pts << " pts" << BLUE << BOLD << " ||" << RESET << endl;
  cout << BLUE << BOLD << " ||==============================================================||" << RESET << endl;

  system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
}


reg_compra getCmp(int pos)
{
  return cmp[pos];
}

int searCmpFID(int enteredCltid) // funcion sin proposito AUN
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