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
#define YELLOW "\033[33m"
#define RESET "\033[0m"


// FILES
void saveClt();
void readClt();
int cntClt(ifstream& cltRegister);
int getLstCltID(int idCmp);

// Funciones para archivos de recompensas
void saveGft();
void readGft();
int cntGft(ifstream& gftRegister);
int getLstGftID();

// Funciones para archivos de compras
void saveCMP();
void readCMP();
int cntCMP(ifstream& cmpRegister);

void saveClt()
{
    ofstream cltRegister("clientes.dat", ios::binary);

    if (!cltRegister.is_open())
    {
        cerr << YELLOW << "Error al abrir el archivo de CLIENTES para escribir..." << RESET << endl;
        return;
    }

    cltRegister.write(reinterpret_cast<char*>(&clt), sizeof(cliente) * lastRegClt);
    cltRegister.close();
}

void readClt()
{
    ifstream cltRegister("clientes.dat", ios::binary);
    if (!cltRegister.is_open())
    {
        cerr << "Error al abrir el archivo de clientes para leer" << endl;
        return;
    }
    lastRegClt = cntClt(cltRegister);
    cltRegister.read(reinterpret_cast<char*>(clt), sizeof(cliente) * MAX);

    cltRegister.close();
}

int cntClt(ifstream& cltRegister) // calcula el ultimo registro
{
    cltRegister.seekg(0, cltRegister.end);
    int tam_archv = cltRegister.tellg();
    cltRegister.seekg(0, cltRegister.beg);

    int num_clts = tam_archv / sizeof(cliente);
    return num_clts;
}

int getLstCltID()
{
    ifstream cltRegister("clientes.dat", ios::binary);
    if (!cltRegister.is_open())
    {
        cerr << "Error al abrir el archivo de CLIENTES para obtener el ultimo ID..." << endl;
        return proxIDclt;
    }

    int lastId = -1;
    cltRegister.seekg(-sizeof(cliente), cltRegister.end);
    if (cltRegister.read(reinterpret_cast<char*>(&clt[0]), sizeof(cliente)))
    {
        lastId = clt[0].client_id;
    }
    cltRegister.close();

    return (lastId == -1) ? proxIDclt : (lastId + 1);
}

// arch GFT
void saveGft()
{
    ofstream gftRegister("recompensas.dat", ios::binary);
    if (!gftRegister.is_open())
    {
        cerr << "Error al abrir el archivo de RECOMPENSAS para escribir..." << endl;
        return;
    }
    gftRegister.write(reinterpret_cast<char*>(&gft), sizeof(gift) * lasTregGft);
    gftRegister.close();
}

void readGft()
{
    ifstream gftRegister("recompensas.dat", ios::binary);
    if (!gftRegister.is_open())
    {
        cerr << "Error al abrir el archivo de RECOMPENSAS para leer" << endl;
        return;
    }
    lasTregGft = cntGft(gftRegister);
    gftRegister.read(reinterpret_cast<char*>(gft), sizeof(gift) * MAX);

    gftRegister.close();
}

int cntGft(ifstream& gftRegister) // calcula el ultimo registro
{
    gftRegister.seekg(0, gftRegister.end);
    int tam_archv = gftRegister.tellg();
    gftRegister.seekg(0, gftRegister.beg);

    int num_gfts = tam_archv / sizeof(gift);
    return num_gfts;
}

int getLstGftID()
{
    ifstream gftRegister("recompensas.dat", ios::binary);
    if (!gftRegister.is_open())
    {
        cerr << "Error al abrir el archivo de RECOMPENSAS para obtener el ultimo ID..." << endl;
        return idGft;
    }

    int lastId = -1;
    gftRegister.seekg(-sizeof(gift), gftRegister.end);
    if (gftRegister.read(reinterpret_cast<char*>(&gft[0]), sizeof(gift)))
    {
        lastId = gft[0].gft_id;
    }
    gftRegister.close();

    return (lastId == -1) ? idGft : (lastId + 1);
}

////////// ARCH DE CMP
void saveCMP()
{
    ofstream cmpRegister("compras.dat", ios::binary);
    if (!cmpRegister.is_open())
    {
        cerr << "Error al abrir el archivo de compras para escribir..." << endl;
        return;
    }
    // Suponiendo que 'compras' es un arreglo de estructuras de compras
    cmpRegister.write(reinterpret_cast<char*>(&cmp), sizeof(reg_compra) * lastREgCmp);
    cmpRegister.close();
}

void readCMP()
{
    ifstream cmpRegister("compras.dat", ios::binary);
    if (!cmpRegister.is_open())
    {
        cerr << "Error al abrir el archivo de compras para leer" << endl;
        return;
    }
    lastREgCmp = cntCMP(cmpRegister); // Ajusta 'cntCompra()' según tus necesidades
    // Suponiendo que 'compras' es un arreglo de estructuras de compras
    cmpRegister.read(reinterpret_cast<char*>(cmp), sizeof(reg_compra) * MAX);
    cmpRegister.close();
}

int cntCMP(ifstream& cmpRegister)
{
    cmpRegister.seekg(0, cmpRegister.end);
    int tam_archv = cmpRegister.tellg();
    cmpRegister.seekg(0, cmpRegister.beg);

    int num_compras = tam_archv / sizeof(reg_compra);

    if (tam_archv % sizeof(reg_compra) != 0)
    {
        num_compras++;
    }

    return num_compras;
}

// fin de archivos
#endif