// structs.h
#ifndef STRUCTS_H
#define STRUCTS_H

#include <iostream>
using namespace std;

const int MAX = 100;

struct accounts
{
    char adminU[50];
    char admP[50];
};

struct cliente
{
    int client_id;
    char client_name[50];
    char client_lastname[50];
    char client_mail[50];
    int client_telf;
    int puntos;
}clt[MAX];

struct cmpr_fecha
{
    int day;
    int month;
    int year;
}fCmp[MAX];

struct reg_compra
{
    cliente clt;
    int cmpr_id;
    cmpr_fecha fCmp;
    string prodCmpr;
    float cmpr_Sqty;
    float cmp_iva;
    float cmpr_Tqty;
    int cmpr_pts;
}cmp[MAX];

struct gift
{
    int gft_id;
    int gft_cant;
    char gft_name[50];
    int gft_pts;
    int gft_Mney;
}gft[MAX];

#endif // STRUCTS_H
