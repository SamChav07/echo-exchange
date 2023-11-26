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
extern int idCmp;
extern int proxIDclt;

FILE *cltRegister;
FILE *gftRegister;
FILE *cmpRegister;

// FILES
void saveClt();
void readClt();
int cntClt(FILE *cltRegister);
int getLstCltID();

// Funciones para archivos de recompensas
void saveGft();
void readGft();
int cntGft(FILE *gftRegister);
int getLstGftID();

// Funciones para archivos de compras
void saveCMP();
void readCMP();
int cntCMP(FILE *cmpRegister);

void saveClt()
{
    cltRegister = fopen("ARCHIVOS/clientes.txt", "w");
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
    cltRegister = fopen("ARCHIVOS/clientes.txt", "r");
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
    cltRegister = fopen("ARCHIVOS/clientes.txt", "r");
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
    gftRegister = fopen("ARCHIVOS/recompensas.txt", "w");
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
    gftRegister = fopen("ARCHIVOS/recompensas.txt", "r");
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
    cltRegister = fopen("ARCHIVOS/recompensas.txt", "r");
    if (cltRegister == NULL)
    {
        cerr << "Error al abrir el archivo de RECOMPENSAS para obtener el ultimo ID..." << endl;
        return idCmp;
    }

    int lastId = -1;
    fseek(gftRegister, -sizeof(gift), SEEK_END);
    if (fread(&gft[0], sizeof(gift), 1, gftRegister) == 1)
    {
        lastId = gft[0].gft_id;
    }
    fclose(gftRegister);

    return (lastId == -1) ? idCmp : (lastId + 1);
}
////////// ARCH DE CMP
void saveCMP()
{
    cmpRegister = fopen("ARCHIVOS/compras.txt", "w");
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
    cmpRegister = fopen("ARCHIVOS/compras.txt", "r");
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
    return num_compras;
}
// fin de archivos

#endif