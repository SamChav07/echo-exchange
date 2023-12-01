#ifndef ARCHIVOS_CPP
#define ARCHIVOS_CPP

#include <iostream>
#include <fstream>
#include "structs.h"

using namespace std;

//variables externas
extern int lastRegClt;
extern int lasTregGft;
extern int lastREgCmp;
extern int idGft;
extern int proxIDclt;
extern int lastRHST;

FILE *cltRegister;
FILE *gftRegister;
FILE *cmpRegister;
FILE *hstReg;

// FILES
void saveClt();
void readClt();
int cntClt(FILE *cltRegister);
int getLstCltID(int idCmp);

// Funciones para archivos de recompensas
void saveGft();
void readGft();
int cntGft(FILE *gftRegister);
int getLstGftID();

// Funciones para archivos de compras
void saveCMP();
void readCMP();
int cntCMP(FILE *cmpRegister);
int getLstCMPID();
// hst
void saveHst();
void readHst();
int cntHST(FILE *hstReg);

void saveClt()
{
    FILE *cltRegister = fopen("clientes.dat", "w");
    if (cltRegister == NULL)
    {
        cerr << "Error al abrir el archivo de clientes para escribir..." << endl;
        return;
    }
    fwrite(clt, sizeof(cliente), lastRegClt, cltRegister);
    fclose(cltRegister);
}

void readClt()
{
    FILE *cltRegister = fopen("clientes.dat", "r");
    if (cltRegister == NULL)
    {
        cerr << "Error al abrir el archivo de clientes para leer" << endl;
        return;
    }
    lastRegClt = cntClt(cltRegister);
    fread(clt, sizeof(cliente), MAX, cltRegister);

    fclose(cltRegister);
}

int cntClt(FILE *cltRegister) // calcula el ultimo registro
{
    int tam_archv, num_clts;
    // obtiene el tamaño del archv
    fseek(cltRegister, 0, SEEK_END);
    tam_archv = ftell(cltRegister);
    rewind(cltRegister);

    // calc el # de clts
    num_clts = tam_archv / sizeof(cliente);
    return num_clts;
}

int getLstCltID()
{
    cltRegister = fopen("clientes.dat", "r");
    if (cltRegister == NULL)
    {
        cerr << "Error al abrir el archivo de CLIENTES para obtener el ultimo ID..." << endl;
        return proxIDclt;
    }

    int lastId = -1;
    fseek(cltRegister, -sizeof(cliente), SEEK_END);
    if (fread(&clt[0], sizeof(cliente), 1, cltRegister) == 1)
    {
        lastId = clt[0].client_id;
    }
    fclose(cltRegister);

    return (lastId == -1) ? proxIDclt : (lastId + 1);
}
// arch GFT
void saveGft()
{
    FILE *gftRegister = fopen("recompensas.dat", "w");
    if (gftRegister == NULL)
    {
        cerr << "Error al abrir el archivo de RECOMPENSAS para escribir..." << endl;
        return;
    }
    fwrite(gft, sizeof(gift), lasTregGft, gftRegister);
    fclose(gftRegister);
}

void readGft()
{
    FILE *gftRegister = fopen("recompensas.dat", "r");
    if (gftRegister == NULL)
    {
        cerr << "Error al abrir el archivo de RECOMPENSAS para leer" << endl;
        return;
    }
    lasTregGft = cntGft(gftRegister);
    fread(gft, sizeof(gift), MAX, gftRegister);

    fclose(gftRegister);
}

int cntGft(FILE *gftRegister) // calcula el ultimo registro
{
    int tam_archv, num_gfts;
    // obtiene el tamaño del archv
    fseek(gftRegister, 0, SEEK_END);
    tam_archv = ftell(gftRegister);
    rewind(gftRegister);

    // calc el # de clts
    num_gfts = tam_archv / sizeof(gift);
    return num_gfts;
}

int getLstGftID()
{
    cltRegister = fopen("recompensas.dat", "r");
    if (cltRegister == NULL)
    {
        cerr << "Error al abrir el archivo de RECOMPENSAS para obtener el ultimo ID..." << endl;
        return idGft;
    }

    int lastId = -1;
    fseek(gftRegister, -sizeof(gift), SEEK_END);
    if (fread(&gft[0], sizeof(gift), 1, gftRegister) == 1)
    {
        lastId = gft[0].gft_id;
    }
    fclose(gftRegister);

    return (lastId == -1) ? idGft : (lastId + 1);
}
////////// ARCH DE CMP
void saveCMP()
{
    FILE *cmpRegister = fopen("compras.dat", "w");
    if (cmpRegister == NULL)
    {
        cerr << "Error al abrir el archivo de compras para escribir..." << endl;
        return;
    }
    // Suponiendo que 'compras' es un arreglo de estructuras de compras
    fwrite(cmp, sizeof(reg_compra), lastREgCmp, cmpRegister);
    fclose(cmpRegister);
}

void readCMP()
{
    FILE *cmpRegister = fopen("compras.dat", "r");
    if (cmpRegister == NULL)
    {
        cerr << "Error al abrir el archivo de compras para leer" << endl;
        return;
    }
    lastREgCmp = cntCMP(cmpRegister); // Ajusta 'cntCompra()' según tus necesidades
    // Suponiendo que 'compras' es un arreglo de estructuras de compras
    fread(cmp, sizeof(reg_compra), MAX, cmpRegister);
    fclose(cmpRegister);
}

int cntCMP(FILE *cmpRegister)
{
    int tam_archv, num_compras;
    // obtiene el tamaño del archv
    fseek(cmpRegister, 0, SEEK_END);
    tam_archv = ftell(cmpRegister);
    rewind(cmpRegister);

    // calc el # de compras
    num_compras = tam_archv / sizeof(cmp);

    if (tam_archv % sizeof(cmp) != 0)
    {
        num_compras++;
    }

    return num_compras;
}
//hst
void saveHst()
{
    FILE *hstReg = fopen("historial.dat", "w");
    if (hstReg == NULL)
    {
        cerr << "Error al abrir el archivo de HISTORIAL para escribir..." << endl;
        return;
    }
    fwrite(hst, sizeof(historial), lastRHST, hstReg);
    fclose(hstReg);
}

void readHst()
{
    FILE *hstReg = fopen("historial.dat", "r");
    if (hstReg == NULL)
    {
        cerr << "Error al abrir el archivo de HISTORIAL para leer..." << endl;
        return;
    }
    lastRHST = cntHST(hstReg);
    fread(hst, sizeof(historial), MAX, hstReg);

    fclose(hstReg);
}

int cntHST(FILE *hstReg)
{
    int tam_archv, num_hst;
    // obtiene el tamaño del archv
    fseek(hstReg, 0, SEEK_END);
    tam_archv = ftell(hstReg);
    rewind(hstReg);

    // calc el # de clts
    num_hst = tam_archv / sizeof(historial);
    return num_hst;
}

// fin de archivos

#endif