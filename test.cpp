#include <iostream>
using namespace std;

#define MAX = 100;
struct cliente
{
    char client_name[20];
    char client_lstNa[20];
    int client_id;
    char client_mail[50];
    char client_telf[15];
}clt;


void addClt();
void readClt();

int main()
{
    int op;
    switch (op)
    {
    case 1:
        addClt();
        break;
    case 2:
        readClt();
        break;
    
    default:
        break;
    }
}

int numClt;
void addClt(cliente currentClient) 
{   
    if(numClt < MAX) {
        cliente newClt;
        cout <<"Nombre: ";
        cin.getline(clt.client_name, sizeof(clt.client_name));
        cout <<"Apellido: ";
        cin.getline(clt.client_lstNa, sizeof(clt.client_lstNa));

        newClt.client_id = 0123 + 1;

        cout <<"E-mail: ";
        cin>>clt.client_mail;
        cout <<"Telefono: ";
        cin>>clt.client_telf;

        clientes[numClt] = newClt;
        numClt++;
    } else {
        cout <<"El numero de Clientes supero el limite."<<endl;
    }
}

/*
void readClt(int &id)
{
    cout <<"ID: ";
    cin>>id;
    bool encontrado = false;

    for (int i = 0; i < numClt; i++)
    {
        if (clientes[i].client_id == id) 
        {
            cout << "Información del cliente con ID " << id << ":\n";
            cout << "Nombre: " << clientes[i].client_name << endl;
            cout << "Apellido: " << clientes[i].client_lstNa << endl;
            cout << "Correo electrónico: " << clientes[i].client_mail << endl;
            cout << "Número de teléfono: " << clientes[i].client_telf << endl;
            encontrado = true;
            break;
        }
    }
    if (!encontrado) {
        cout <<"Cliente con ID "<<id<<" no encontrado."<<endl;
    }
}
*/