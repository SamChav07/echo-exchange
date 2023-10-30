#ifndef DATA_H
#define DATA_H

using namespace std;
#define MAX 100

struct cliente {
    char client_name[20];
    char client_lstName[20]
    int client_id;
    char client_mail;
    char client_telf;
}clt[MAX];

struct reg_compra {
    int cmpr_id;
    struct cmpr_fecha;
    float cmpr_qty; // monto de la compra
    int cmpr_pts;
}r_cmpr;


struct cmpr_fecha {
    int day;
    int month;
    int year;
}cmpr_f;


struct historial {
    struct client; 
    struct reg_compra;
    int cmpr_ptsTot;
}hst;


struct gift {
    int gft_cant;
    char gft_name;
    int gft_pts;
}gft;

#endif

