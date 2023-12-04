#include <iostream>
#include <cstring> //strcpy, strlen
#include <iomanip> //setw, setfill
#include <unistd.h> //system()

#include <algorithm>
#include <functional>
#include <cctype> // libreria para all_of y ::isdigit
#include <fstream>

#include "structs.h"
#include "1_CRUDclt.cpp"
#include "2_CRUDgft.cpp"
#include "3_CRUDcmp.cpp"
#include "archivos.cpp"
using namespace std; // talvez

// LOG
void SuperAdmin();
void logAdm();

// menus
void MDclient(); //--listo
void agregarCliente(cliente currentClt);
void modificarCliente(int enteredClt_id);
void eliminarCliente(int enteredClt_id);
void MDcmp(int enteredCltid);
void MDgft();      // en proceso
void delCmp();
void agregarRecompensa(gift currentGft);
void searchMclt(); // menu de busqueda de cliente   //--listo

void MAdm();
void MClt();
void consPts(int enteredCltid);
void mostrHstCMP(int enteredCltid);

// funciones
void record();
void redeem();   // -------------pendiente
void checkPts(reg_compra *currentCmp); // -------------pendiente
int consultarPtsCliente(int enteredCltid);

extern int enteredCltid;
extern int lastREgCmp;
extern int lastRegClt;
extern int proxIDclt;

// codigos colores ANSI
#define RESET "\033[0m"
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLEu "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"

int main()
{
    SuperAdmin();
    return 0;
}

void SuperAdmin()
{
    int spOpcion;

    cout << BOLD << CYAN << "EEEE  CCCC  HH  HH  OOOOOO     EEEE  XX    XX  CCCC  HH  HH  AAAAAA  NN     NN  GGGGGG   EEEE" << RESET << endl;
    cout << BOLD << CYAN << "EE    CC    HH  HH  OO  OO     EE     XX  XX   CC    HH  HH  AA  AA  NN NN  NN  GG       EE" << RESET << endl;
    cout << BOLD << CYAN << "EEEE  CC    HHHHHH  OO  OO" << BOLD << CYAN << " === " << RESET << BOLD << CYAN << "EEEE    XXXX    CC    HHHHHH  AAAAAA  NN  NN NN  GG  GGG  EEEE" << RESET << endl;
    cout << BOLD << CYAN << "EE    CC    HH  HH  OO  OO     EE     XX  XX   CC    HH  HH  AA  AA  NN   NNNN  GG  GG   EE" << RESET << endl;
    cout << BOLD << CYAN << "EEEE  CCCC  HH  HH  OOOOOO     EEEE  XX    XX  CCCC  HH  HH  AA  AA  NN    NNN  GGGGGG   EEEE" << RESET << endl;

    do
    {
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << "            ||" << RESET << BOLD << WHITE << "                      BIENVENIDO SUPER-ADMIN                  " << RESET << CYAN << "||" << RESET << endl;
        cout << CYAN << "            ||" << RESET << "          ¿Qué cuenta desea fijar en el dispositivo?          " << RESET << CYAN <<  "||" << RESET << endl;
        cout << CYAN << "            ||" << RESET << CYAN << "                         1."<<RESET<<WHITE<<" Administrador.                    " << RESET << CYAN <<  "||" << RESET << endl;
        cout << CYAN << "            ||" << RESET << CYAN << "                           2."<<RESET<<WHITE<<" Cliente.                        " << RESET << CYAN <<  "||" << RESET << endl;
        cout << CYAN << "            ||" << RESET << CYAN << "                           3."<<RESET<<WHITE<<" Cerrar.                         " << RESET << CYAN <<  "||" << RESET << endl;
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << "\n                  [OPCION] --> " << RESET;

        cin >> spOpcion; 

        if (cin.fail() || cin.peek() != '\n') {
            system("cls || clear");
            cout << YELLOW << "                   Digite una de las opciones disponibles, no ingrese caracteres. Intente de nuevo..." << RESET << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } else {
            switch (spOpcion)
            {
            case 1:
                logAdm();
                break;
            case 2:
                MClt();
                break;
            case 3:
                cout << CYAN << "                    **-- Gracias, por usar el sistema Echo-Exchange --**" << RESET << endl;
                exit(0);
                break;
            default:
                cout << YELLOW << "                   Ingrese una opcion valida. 1 - 3..." << RESET << endl;
                break;
            }
        }

        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
        system("cls || clear");

    } while (spOpcion < 1 || spOpcion > 3);
}

void logAdm()
{
    char user[50], pass[50];
    int intentos = 4;

    accounts administrador1;
    strcpy(administrador1.adminU, "."); // admin1
    strcpy(administrador1.admP, ".");   // passord123

    do
    {
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
        cout << CYAN << "            ||                                                              ||" << RESET << endl;
        cout << CYAN << "            ||                     " << RESET << BOLD << "Acceso de Administrador                  "<< RESET << CYAN <<"||" << RESET << endl;
        cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
        cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
        cout << CYAN << "            ||           " << RESET << CYAN <<"|| " << RESET << WHITE << "Usuario: " << RESET;
        cin >> user;
        cout << CYAN << "            ||           " << RESET << CYAN <<"|| " << RESET << WHITE << "Contraseña: " << RESET;
        cin >> pass;
        cout << CYAN << BOLD << "            ||______________________________________________________________||" << RESET << endl;

        // Verificaci�n de credenciales del administrador
        if (strcmp(user, administrador1.adminU) == 0 && strcmp(pass, administrador1.admP) == 0)
        {
            cout << GREEN << BOLD << "                                 ***--Acceso concedido--***" << RESET << endl;
            MAdm();
        }
        else
        {
            cout << RED << "                ***--Intento fallido.  Usuario o contrasena incorrecta--***" << RESET << endl;
            cout << BOLD << RED << "                                  Intentos restantes: " << intentos - 1 << RESET << endl;

            intentos--;
        }
    } while (intentos > 0);
    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

    if (intentos == 0) {
        cout << RED << "                ***--Intento fallido.  Usuario o contrasena incorrecta--***" << RESET << endl;
        cout << "                     " << BOLD << UNDERLINE << RED << "*** Acceso bloqueado, saliendo del sistema ***" << RESET << endl;
        exit(0);
    }
}

void MAdm()
{
    readClt();
    readCMP();
    readGft();

    int op1, enteredCltid;

    do
    {
        system("cls || clear");
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
        cout << CYAN << "            ||                                                              ||" << RESET << endl;
        cout << CYAN << "            ||"<<RESET<<BOLD<<"                   BIENVENIDO ADMINISTRADOR                   "<<RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
        cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
        cout << BOLD << "            ||                "<<RESET<<CYAN<<"||***||"<<RESET<<" MENU PRINCIPAL "<<CYAN"||***||"<<CYAN<<CYAN"                ||" << RESET << endl;
        cout << CYAN << "            ||                    " << RESET <<CYAN<<"1. "<<RESET << WHITE << "Gestionar compras.                     "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                    " << RESET <<CYAN<<"2. "<<RESET << WHITE << "Gestionar clientes.                    "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                    " << RESET <<CYAN<<"3. "<<RESET << WHITE << "Gestionar recompensas.                 "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                    " << RESET <<CYAN<<"4. "<<RESET << WHITE << "Cerrar Sesion...                       "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << "\n                  [OPCION] --> " << RESET;

        cin >> op1;

        if (cin.fail() || cin.peek() != '\n') {
            cout << YELLOW << "                   Ingrese una opción válida. 1 - 4..." << RESET << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            continue;
        }

        switch (op1)
        {
        case 1:
            MDcmp(enteredCltid);
            break;
        case 2:
            MDclient();
            break;
        case 3:
            MDgft();
            break;
        case 4:
            system("cls");
            logAdm();
            break;
        default:
            cout << YELLOW << "                   Ingrese una opcion valida. 1 - 4..." << RESET << endl;
            break;
        }

        cout <<YELLOW<< "Enter para continuar..." <<RESET<< endl;
        cin.ignore();
        cin.get();

    } while (op1 != 4);
}

void MClt() //////////////////// CLIENTES
{
    readCMP();
    readGft();
    readClt();
    readCMP();

    int op2, pos = -1;
    int enteredCltid;
    system("cls || clear");

    cout << CYAN << "            ||==============================================================||" << RESET << endl;
    cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
    cout << CYAN << "            ||                                                              ||" << RESET << endl;
    cout << CYAN << "            ||"<<RESET<<BOLD<<"                      BIENVENIDO CLIENTE                      "<<RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
    cout << CYAN << "            ||          [ ID DE CLIENTE ] --> " << RESET; cin >> enteredCltid;
    cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
    pos = searchCltId(enteredCltid);
    cout << CYAN << "               Hola " << clt[pos].client_name <<" "<< clt[pos].client_lastname << endl;
    
    if (pos != -1) {
        do
        {
            cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
            cout << BOLD << "            ||                "<<RESET<<CYAN<<"||***||"<<RESET<<" MENU PRINCIPAL "<<CYAN"||***||"<<CYAN<<CYAN"                ||" << RESET << endl;
            cout << CYAN << "            ||                    " << RESET <<CYAN<<"1. "<<RESET << WHITE << "Canjear Puntos.                        "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                    " << RESET <<CYAN<<"2. "<<RESET << WHITE << "Consultar Puntos.                      "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                    " << RESET <<CYAN<<"3. "<<RESET << WHITE << "Historial de compras.                  "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                    " << RESET <<CYAN<<"4. "<<RESET << WHITE << "Cerrar Sesion...                       "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||==============================================================||" << RESET << endl;
            cout << CYAN << "\n                  [OPCION] --> " << RESET;

            cin >> op2;

            if (cin.fail() || cin.peek() != '\n') {
                cout << YELLOW << "                   Ingrese una opción válida. 1 - 4..." << RESET << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                continue;
            }

            switch (op2)
            {
            case 1:
                redeem();
                break;
            case 2:
                consPts(enteredCltid);
                break;
            case 3:
                mostrHstCMP(enteredCltid);
                break;
            case 4:
                system("cls || clear");
                break;
            default:
                cout << "Ingrese opciones validas. Sean de 1-4.." << endl;
                break;
            }
        } while (op2 != 4);
        
    } else {
        cout <<YELLOW<< "            Cliente no encontrado..." <<RESET<< endl;
    }

    cout << YELLOW << "Presiona Enter para continuar..." << RESET << endl;
    cin.ignore();
    cin.get();
    MClt();
}

void consPts(int enteredCltid)
{
    readClt();
    readCMP();
    system("cls || clear");
    
    cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
    cout << BOLD << "            ||                "<<RESET<<CYAN<<"||***||"<<RESET<<" MENU PRINCIPAL "<<CYAN"||***||"<<CYAN<<CYAN"                ||" << RESET << endl;
    cout << "                 ID del cliente a consultar sus puntos: " << enteredCltid << endl;

    // Consulta los puntos del cliente
    int puntosCliente = consultarPtsCliente(enteredCltid);

    if (puntosCliente != -1)
    {
        cout << "                 Puntos acumulados del cliente " << enteredCltid << ": " << puntosCliente << " pts" << endl;
    }
    else
    {
        cout << "                 Puntos no encontrados." << endl;
    }

    system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
    MClt();
}

void mostrHstCMP(int enteredCltid)
{
    int pos;

    do {
        cout << "ID de cliente: " <<enteredCltid<< endl;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "            Ingrese un ID válido, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }
        else
        {
            pos = searchCltId(enteredCltid);

            if (pos != -1) {
                showCmp(pos);
            }
        }
    } while (cin.fail() || cin.peek() != '\n');

    cin.get();
    system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
    MClt();
}

void MDclient()
{
    cliente currentClt;
    int pos, resp;
    int enteredClt_id;

    int optMdclt;
    cin.clear();

    system("cls || clear");

    cout << CYAN << "            ||==============================================================||" << RESET << endl;
    cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
    cout << CYAN << "            ||                                                              ||" << RESET << endl;
    cout << CYAN << "            ||"<<RESET<<BOLD<<"                   GESTION DE CLIENTES                        "<<RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
    cout << CYAN << "            ||               Cantidad de registros de Clientes: " << lastRegClt<<"           ||" << RESET << endl;
    cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
    cout << BOLD << "            ||                "<<RESET<<CYAN<<"||**||"<<RESET<<"                  "<<CYAN"||**||"<<CYAN<<CYAN"                ||" << RESET << endl;
    cout << CYAN << "            ||                   " << RESET <<CYAN<<"1. "<<RESET << WHITE << "Agregar cliente.                        "<< RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << "            ||                   " << RESET <<CYAN<<"2. "<<RESET << WHITE << "Buscar cliente.                         "<< RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << "            ||                   " << RESET <<CYAN<<"3. "<<RESET << WHITE << "Modificar cliente.                      "<< RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << "            ||                   " << RESET <<CYAN<<"4. "<<RESET << WHITE << "Eliminar cliente.                       "<< RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << "            ||                   " << RESET <<CYAN<<"5. "<<RESET << WHITE << "Mostrar Registro de clientes.                               "<< RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << "            ||                   " << RESET <<CYAN<<"6. "<<RESET << WHITE << "Volver...                               "<< RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << "            ||==============================================================||" << RESET << endl;
    cout << CYAN << "\n                  [OPCION] --> " << RESET;

    cin.ignore();
    cin >> optMdclt;
    
    cout <<GREEN<< "Presione Enter para continuar..." <<RESET<< endl;
    cin.get();


    switch (optMdclt)
    {
    case 1:
        agregarCliente(currentClt);
        break;

    case 2:
        searchMclt();
        break;
    case 3:
        modificarCliente(enteredClt_id);
        break;
    case 4:
        eliminarCliente(enteredClt_id);
        break;
    case 5:
        system("cls || clear");
        cout <<GREEN<< "Visualizando todos los registros..." <<RESET<< endl;
        showCltRegister();
        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
        break;
    case 6:
        MAdm();
        break;

    default:
        cout <<YELLOW<< "Ingrese una opcion valida. Del 1 - 5..." <<RESET<< endl;
        break;
    }
}

void agregarCliente(cliente currentClt)
{
    cin.clear();

    system("cls || clear");
    cout << CYAN << "            ||==============================================================||" << RESET << endl;
    cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
    cout << CYAN << "            ||                                                              ||" << RESET << endl;
    cout << CYAN << "            ||"<<RESET<<BOLD<<"                     AGREGAR CLIENTE                          "<<RESET<<CYAN<<"||" << RESET << endl;
    cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
    cout << BOLD << "            ||             "<<RESET<<CYAN<<"||*||"<<RESET<<" Ingrese los datos a añadir"<<CYAN"||*||"<<CYAN<<CYAN"            ||" << RESET << endl;
    cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
    currentClt.client_id = getLstCltID();

    currentClt.puntos = 0;

    if (currentClt.client_id == -1)
    {
        cerr <<YELLOW<< "Error al obtener el último ID. No se pudo agregar el cliente..." <<RESET<< endl;
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        return;
    }

    cout << CYAN << "            ||             " << RESET <<CYAN<<"ID: "<<RESET << currentClt.client_id << RESET<<CYAN<<"                                          ||" << RESET << endl;


    // Nombre del cliente
    do
    {
        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Nombre del cliente: "<<RESET;
        cin.getline(currentClt.client_name, sizeof(currentClt.client_name));

        if (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit))
        {
            cout <<YELLOW<<"Ingrese un nombre válido, solo con caracteres." <<RESET<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

    } while (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit));

    // Apellido del cliente
    do
    {
        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Apellido del cliente: "<<RESET;
        cin.getline(currentClt.client_lastname, sizeof(currentClt.client_lastname));

        if (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit))
        {
            cout <<YELLOW<< "Ingrese un apellido válido, solo con caracteres." <<RESET<<endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

    } while (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit));

    // E-mail del cliente
    do
    {
        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Email del cliente: "<<RESET;
        cin.getline(currentClt.client_mail, sizeof(currentClt.client_mail));

        if (strstr(currentClt.client_mail, "@gmail.com") == NULL)
        {
            cout <<YELLOW<< "El correo debe terminar en @gmail.com. Inténtelo de nuevo..." <<RESET<< endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        }

    } while (strstr(currentClt.client_mail, "@gmail.com") == NULL);

    // Teléfono del cliente
    do
    {
        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Teléfono del cliente XXXX-XXXX: "<<RESET;
        cin >> currentClt.client_telf;

        // Verificar si el formato del número de teléfono es correcto
        if (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999)
        {
            cout <<YELLOW<< "Ingrese un número telefónico válido. Use el formato XXXX-XXXX y solo incluya dígitos." <<RESET<< endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

    } while (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999);

    cout << CYAN << "            ||==============================================================||" << RESET << endl;

    addClt(currentClt);
    saveClt();
    // llama a la función guardar antes de cerrar la sesión
    cout << GREEN << "Presiona Enterpara continuar..." <<RESET<< endl;
    cin.ignore();
    MDclient();
}

void modificarCliente(int enteredClt_id)
{
    cliente currentClt;
    int pos, opModclt;

    system("cls || clear");
    cout << CYAN << "\n                [ID a Modificar] --> " << RESET;
    cin >> enteredClt_id;

    pos = searchCltId(enteredClt_id);

    currentClt.client_id = enteredClt_id;
    if (pos != -1)
    {
        do
        {
            cout << CYAN << "            ||==============================================================||" << RESET << endl;
            cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
            cout << CYAN << "            ||                                                              ||" << RESET << endl;
            cout << CYAN << "            ||"<<RESET<<BOLD<<"                   DATOS A MODIFICAR                        "<<RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
            cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
            cout << BOLD << "            ||                "<<RESET<<CYAN<<"||**||"<<RESET<<"                  "<<CYAN"||**||"<<CYAN<<CYAN"                ||" << RESET << endl;
            cout << CYAN << "            ||                   " << RESET <<CYAN<<"1. "<<RESET << WHITE << "Nombre.                         "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                   " << RESET <<CYAN<<"2. "<<RESET << WHITE << "Apellido.                          "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                   " << RESET <<CYAN<<"3. "<<RESET << WHITE << "Correo.                       "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                   " << RESET <<CYAN<<"4. "<<RESET << WHITE << "Telefono.                        "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                   " << RESET <<CYAN<<"5. "<<RESET << WHITE << "Todo el registro.                                "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||                   " << RESET <<CYAN<<"6. "<<RESET << WHITE << "Volver...                                "<< RESET<<CYAN<<"||" << RESET << endl;
            cout << CYAN << "            ||==============================================================||" << RESET << endl;
            cout << CYAN << "\n                  [OPCION] --> " << RESET;

            cin >> opModclt;

            if (cin.fail() || cin.peek()) {
                cout <<YELLOW<< "La opcion no puede ser caracter..." <<RESET<<endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');  
            } else {
                switch (opModclt)
                {
                case 1:
                    do {
                        cin.ignore();
                        cout << CYAN << "\n                [ Nuevo Nombre ] --> " << RESET;
                        cin.getline(currentClt.client_name, sizeof(currentClt.client_name));

                        copy(begin(clt[pos].client_lastname), end(clt[pos].client_lastname), begin(currentClt.client_lastname));
                        copy(begin(clt[pos].client_mail), end(clt[pos].client_mail), begin(currentClt.client_mail));
                        currentClt.client_telf = clt[pos].client_telf;

                        if (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit))
                        {
                            cout <<YELLOW<<"Ingrese un nombre válido, solo con caracteres."<< RESET << endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');                        
                        }

                    } while (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit));

                    uptdClt(currentClt, pos);// actualiza
                    saveClt();//guarda
                    break;
                case 2:
                    do {
                        cin.ignore();
                        cout << CYAN << "\n                [ Nuevo Apellido ] --> " << RESET;
                        cin.getline(currentClt.client_lastname, sizeof(currentClt.client_lastname));

                        copy(begin(clt[pos].client_name), end(clt[pos].client_name), begin(currentClt.client_name));
                        copy(begin(clt[pos].client_mail), end(clt[pos].client_mail), begin(currentClt.client_mail));
                        currentClt.client_telf = clt[pos].client_telf;

                        if (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit))
                        {
                            cout <<YELLOW<< "Ingrese un apellido válido, solo con caracteres." <<RESET<< endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }                    
                    } while (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit));

                    uptdClt(currentClt, pos);// actualiza
                    saveClt();//guarda
                    break;
                case 3:
                    do {
                        cin.ignore();
                        cout << CYAN << "\n                [ Nuevo Correo ] --> " << RESET;
                        cin.getline(currentClt.client_mail, sizeof(currentClt.client_mail));

                        copy(begin(clt[pos].client_name), end(clt[pos].client_name), begin(currentClt.client_name));
                        copy(begin(clt[pos].client_lastname), end(clt[pos].client_lastname), begin(currentClt.client_lastname));
                        currentClt.client_telf = clt[pos].client_telf;

                        if (strstr(currentClt.client_mail, "@gmail.com") == NULL)
                        {
                            cout <<YELLOW<< "El correo debe terminar en @gmail.com. Inténtelo de nuevo..." <<RESET<< endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                    } while (strstr(currentClt.client_mail, "@gmail.com") == NULL);

                    uptdClt(currentClt, pos);// actualiza
                    saveClt();//guarda
                    break;
                case 4:
                    do {
                        cin.ignore();
                        cout << CYAN << "\n                [ Nuevo Telefono ] --> " << RESET;
                        cin >> currentClt.client_telf;

                        copy(begin(clt[pos].client_name), end(clt[pos].client_name), begin(currentClt.client_name));
                        copy(begin(clt[pos].client_lastname), end(clt[pos].client_lastname), begin(currentClt.client_lastname));
                        copy(begin(clt[pos].client_mail), end(clt[pos].client_mail), begin(currentClt.client_mail));

                        if (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999)
                        {
                           cout <<YELLOW<< "Ingrese un número telefónico válido. Use el formato XXXX-XXXX y solo incluya dígitos." <<RESET<< endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999);

                    uptdClt(currentClt, pos);// actualiza
                    saveClt();//guarda
                    break;
                case 5:
                    cout << CYAN << "            ||==============================================================||" << RESET << endl;
                    cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
                    cout << CYAN << "            ||                                                              ||" << RESET << endl;
                    cout << CYAN << "            ||"<<RESET<<BOLD<<"                     MODIFICAR CLIENTE                          "<<RESET<<CYAN<<"||" << RESET << endl;
                    cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
                    cout << BOLD << "            ||             "<<RESET<<CYAN<<"||*||"<<RESET<<"Ingrese los datos a modificar del CLIENTE con el ID:"<<currentClt.client_id<<CYAN"||*||"<<CYAN<<CYAN"            ||" << RESET << endl;
                    cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
                    do
                    {
                        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Nombre del cliente: "<<RESET;
                        cin.ignore(); // Ignorar el carácter de nueva línea residual
                        cin.getline(currentClt.client_name, sizeof(currentClt.client_name));

                        if (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit))
                        {
                            cout <<YELLOW<< "Ingrese un nombre válido, solo con caracteres." <<RESET<< endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }

                    } while (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit));

                    do
                    {
                        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Apellido del cliente: "<<RESET;
                        cin.getline(currentClt.client_lastname, sizeof(currentClt.client_lastname));

                        if (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit))
                        {
                            cout <<YELLOW<< "Ingrese un apellido válido, solo con caracteres." <<RESET<< endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }

                    } while (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit));

                    do
                    {
                        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Email del cliente: "<<RESET;
                        cin.getline(currentClt.client_mail, sizeof(currentClt.client_mail));

                        if (strstr(currentClt.client_mail, "@gmail.com") == NULL)
                        {
                            cout <<YELLOW<< "El correo debe terminar en @gmail.com. Inténtelo de nuevo..." <<RESET<< endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');                        
                        }

                    } while (strstr(currentClt.client_mail, "@gmail.com") == NULL);

                    do
                    {
                        cout <<CYAN<<"            ||             "<< RESET <<CYAN<<"Teléfono del cliente XXXX-XXXX: "<<RESET;
                        cin >> currentClt.client_telf;

                        // Verificar si el formato del número de teléfono es correcto
                        if (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999)
                        {
                            cout <<YELLOW<< "Ingrese un número telefónico válido. Use el formato XXXX-XXXX y solo incluya dígitos." <<RESET<< endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999);

                    uptdClt(currentClt, pos);// actualiza
                    saveClt();//guarda
                    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                    break;
                case 6:
                    system("cls || clear");
                    cout << "Saliendo..." << endl;
                    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                    MDclient();
                    break;
                default:
                    cout <<YELLOW<< "Opción no válida. Por favor, inténtelo de nuevo" <<RESET<< endl;
                    break;
                }
            }
        } while (cin.fail() || cin.peek());
        
        saveClt();
    }
    else
    {
        cout <<RED<< "Registro inexistente" <<RESET<< endl;
    }
    system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
}

void eliminarCliente(int enteredClt_id)
{
    int pos, resp;
    cliente currentClt;

    system("cls || clear");

    if (lastRegClt == 0)
    {
        cout <<YELLOW<< "No hay nada que eliminar\n"<<RESET;
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        MDclient();
    }

    do {
        cout << CYAN << "\n                [ID del Cliente] --> " << RESET;
        cin >> enteredClt_id;

        pos = searchCltId(enteredClt_id);

        if (pos != -1)
        {
            showClt(pos);

            currentClt = getClt(pos);

            cout << "¿Realmente deseas "<<RED<<UNDERLINE<<"ELIMINAR"<<RESET" el cliente ?" << endl;
            cout << "Escriba "<<RED<<"1 para SI"<<RESET<<" o "<<GREEN<<"2 para NO"<<RESET<< endl;
            cout << CYAN << "\n                  [OPCION] --> " << RESET;

            cin >> resp;

            if (resp == 1)
            {
                delClt(pos);
                cout <<GREEN<<UNDERLINE<< "Registro eliminado...\n"<<RESET;
            }
            else
            {
                cout <<RED<< "Operacion cancelada...\n"<<RESET;
            }
            
        }
        else
        {
            cout <<YELLOW<< "Registro inexistente" <<RESET<< endl;
        }

    } while(resp !=1 && resp !=2);
    
    saveClt();
    MDclient();
}

void MDgft()
{
    gift currentGft;
    int gftPos, resp;
    int enteredGft_id;
    char enteredGft_name[50];

    int optMdGft;
    do {
        system("cls || clear");
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
        cout << CYAN << "            ||                                                              ||" << RESET << endl;
        cout << CYAN << "            ||"<<RESET<<BOLD<<"                   Gestion de Recompensas                     "<<RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
        cout << CYAN << "            ||               Cantidad de registros de Recompensas: " << lasTregGft<<"        ||" << RESET << endl;
        cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
        cout << BOLD << "            ||                "<<RESET<<CYAN<<"||**||"<<RESET<<"                  "<<CYAN"||**||"<<CYAN<<CYAN"                ||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"1. "<<RESET << WHITE << "Agregar recompensa.                     "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"2. "<<RESET << WHITE << "Buscar recompensa.                      "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"3. "<<RESET << WHITE << "Modificar recompensa.                   "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"4. "<<RESET << WHITE << "Eliminar recompensa.                    "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"5. "<<RESET << WHITE << "Mostrar Registro de recompensas.                               "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"6. "<<RESET << WHITE << "Volver...                               "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << "\n                  [OPCION] --> " << RESET;
        cin >> optMdGft;

        switch (optMdGft)
        {
        case 1:
            agregarRecompensa(currentGft);
            break;

        case 2:
            int opBsqGft;

            do
            {
                cout << "Busqueda de Recompensa:" << endl;
                cout << "1. ID." << endl;
                cout << "2. Nombre." << endl;
                cout << "3. Atras..." << endl;
                cout << "\n-->";
                cin >> opBsqGft;
                switch (opBsqGft) {
                    case 1:
                        system("cls || clear");
                        cout << "Buscar por ID de Recompensa: " << endl;
                        do {
                            cout << "ID a buscar: ";
                            cin >> enteredGft_id;

                            if (cin.fail() || cin.peek() != '\n') {
                                cout << "Ingrese un ID válido, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                            } else {
                                gftPos = searchGFTid(enteredGft_id);
                                if (gftPos != -1) {
                                    showGft(gftPos);
                                } else {
                                    cout << "Registro Inexistente" << endl;
                                }
                            }
                        } while(cin.fail() || cin.peek() != '\n');
                        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                        break;
                    case 2:
                        system("cls || clear");
                        cout << "Buscar por nombre de Recompensa: " << endl;
                        do {
                            cout << "Nombre a buscar: ";
                            cin.ignore();
                            cin.getline(enteredGft_name, sizeof(enteredGft_name));
                            if (any_of(enteredGft_name, enteredGft_name + strlen(enteredGft_name), ::isdigit)) {
                                cout << "Ingrese un nombre válido, solo con caracteres. Doble enter para intertar de nuevo..." << endl;
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                            }
                        } while (any_of(enteredGft_name, enteredGft_name + strlen(enteredGft_name), ::isdigit));
                        
                        searchGFTname(enteredGft_name, true);
                        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                        break;
                    case 3:
                        system("cls || clear");
                        cout << "Saliendo..." << endl;
                        MDgft();
                        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                        break;
                    default:
                        cout << "Opcion Invalida. Ingrese una opcion valida del 1 - 3" << endl;
                        break;
                    }
            } while (opBsqGft != 3);

            break;
        case 3:
            int opModfy;
            
            do {
                system("cls || clear");
                cout << "** Escribe el ID de la Recompensa a modificar **" << endl;
                cin >> enteredGft_id;

                gftPos = searchGFTid(enteredGft_id); // la funcion de busqueda se debe adaptar a GIFT

                currentGft.gft_id = enteredGft_id;

                if (gftPos != -1)
                {
                    do
                    {
                        cout << "Datos a modificar:" << endl;
                        cout << "1. Nombre." << endl;
                        cout << "2. Cantidad o Stock." << endl;
                        cout << "3. Puntos Necesarios." << endl;
                        cout << "4. Modificar todos los datos." << endl;
                        cout << "5. Atras..." << endl;
                        cout << "\n-->";
                        cin >> opModfy;

                        switch (opModfy)
                        {
                        case 1:
                        
                            cin.ignore();
                            cout << "Nuevo Nombre: ";
                            cin.getline(currentGft.gft_name, sizeof(currentGft.gft_name));

                            currentGft.gft_cant = gft[gftPos].gft_cant;
                            currentGft.gft_pts = gft[gftPos].gft_pts;

                            uptGFT(currentGft, gftPos);
                            saveGft();
                            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                            break;
                        case 2:
                            do {
                                cin.ignore();
                                cout << "Cantidad o Stock: ";
                                cin >> currentGft.gft_cant;

                                copy(begin(gft[gftPos].gft_name), end(gft[gftPos].gft_name), begin(currentGft.gft_name));
                                currentGft.gft_pts = gft[gftPos].gft_pts;
                                if (cin.fail() || cin.peek() != '\n') {
                                    cout << "Ingrese una cantidad válida, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
                                    cin.clear();
                                    cin.ignore(INT_MAX, '\n');
                                }
                            } while (cin.fail() || cin.peek() != '\n');
                            uptGFT(currentGft, gftPos);
                            saveGft();
                            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                            break;
                        case 3:
                            do {
                                cin.ignore();
                                cout << "Puntos Necesarios: ";
                                cin >> currentGft.gft_pts;

                                copy(begin(gft[gftPos].gft_name), end(gft[gftPos].gft_name), begin(currentGft.gft_name));
                                currentGft.gft_cant = gft[gftPos].gft_cant;
                                if (cin.fail() || cin.peek() != '\n') {
                                    cout << "Ingrese una cantidad válida, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
                                    cin.clear();
                                    cin.ignore(INT_MAX, '\n');
                                }
                            } while (cin.fail() || cin.peek() != '\n');
                            uptGFT(currentGft, gftPos);
                            saveGft();
                            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                            break;
                        case 4:
                            do
                            {
                                cin.ignore();
                                cout << "Nuevo Nombre: ";
                                cin.getline(currentGft.gft_name, sizeof(currentGft.gft_name));

                                if (any_of(currentGft.gft_name, currentGft.gft_name + strlen(currentGft.gft_name), ::isdigit))
                                {
                                    cout << "Ingrese un nombre válido, solo con caracteres. Doble enter para intentar de nuevo..." << endl;
                                    cin.clear();
                                    cin.ignore(INT_MAX, '\n');
                                }
                            } while (any_of(currentGft.gft_name, currentGft.gft_name + strlen(currentGft.gft_name), ::isdigit));

                                do {
                                    cin.ignore();
                                    cout << "Cantidad o Stock: ";
                                    cin >> currentGft.gft_cant;

                                    if (cin.fail() || cin.peek() != '\n') {
                                        cout << "Ingrese una cantidad válida, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                    }
                                } while (cin.fail() || cin.peek() != '\n');

                                do {
                                    cin.ignore();
                                    cout << "Puntos Necesarios: ";
                                    cin >> currentGft.gft_pts;

                                    if (cin.fail() || cin.peek() != '\n') {
                                        cout << "Ingrese una cantidad válida, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
                                        cin.clear();
                                        cin.ignore(INT_MAX, '\n');
                                    }
                                    uptGFT(currentGft, gftPos);
                                    saveGft();
                                } while (cin.fail() || cin.peek() != '\n');
                            break;
                        case 5:
                            system("cls || clear");
                            cout << "Saliendo..." << endl;
                            MDgft();
                            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                            break;
                        default:
                            cout << "Opcion no valida, 1 - 5..." << endl;
                            break;
                        }
                    }while (opModfy != 5);
                }
                else
                {
                    cout << "Registro inexistente" << endl;
                }

                if (cin.fail() || cin.peek() != '\n')
                {
                    cout << "Ingrese una ID válida. Doble enter para intentar de nuevo..." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
            } while ((cin.fail() || cin.peek() != '\n'));
            
            //////////////
            MDgft();
            saveGft();
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            break;
        case 4:
            system("cls || clear");
            if (lasTregGft == 0)
            {
                cout << "No hay nada que eliminar\n";
                break;
            }
            cout << "Escribe el ID de la recompensa: " << endl;
            cin >> enteredGft_id;
            gftPos = searchCltId(enteredGft_id); // busqueda de GFT
            if (gftPos != -1)
            {
                currentGft = getGft(gftPos);
                cout << "¿Realmente deseas eliminar la recompensa ?" << endl;
                cout << "Escriba 1 para SI o 2 para NO : ";
                cin >> resp;
                if (resp == 1)
                {
                    delGFT(gftPos);
                    cout << "Registro eliminado...\n";
                }
                else
                {
                    cout << "Operacion cancelada...\n";
                }
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            saveGft();
            break;
        case 5:
            system("cls || clear");
            cout << "Visualizando todos los registros..." << endl;
            showGftRegister();
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            break;
        case 6:
            MAdm();
            break;
        default:
            cout << "Ingrese una opcion valida. Del 1 - 5..." << endl;
            break;
        }
    } while (optMdGft != 6);
}

void agregarRecompensa(gift currentGft)
{
    cin.clear(); // Limpiar el buffer de entrada antes de getline

    system("cls || clear");
    cout << "** Ingrese los datos a añadir **" << endl;

    currentGft.gft_id = getLstGftID();

    if (currentGft.gft_id == -1) {
        cerr << "Error al obtener el último ID. No se pudo agregar la recompensa..." << endl;
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        return;
    }
    
    cout << "ID: " << currentGft.gft_id << endl;
            
    cout << "Nombre de la recompensa: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.getline(currentGft.gft_name, sizeof(currentGft.gft_name));
   
    do {
        cout << "Cantidad del producto: ";
        cin >> currentGft.gft_cant;
        if (currentGft.gft_cant >= 1000) {
            cout << "La cantidad debe tener menos de tres digitos." << endl;
        }

    } while (currentGft.gft_cant >= 1000);

            
    do {
        cout << "Puntos Necesarios: ";
        cin >> currentGft.gft_pts;
        if (currentGft.gft_pts >= 1000000000 || currentGft.gft_pts <= 100) {
            cout << "Los puntos deben estar entre 100 y 1,000,000,000." << endl;
        }

    } while (currentGft.gft_pts >= 1000000000 || currentGft.gft_pts <= 100);

    currentGft.gft_Mney = currentGft.gft_pts * 100;
    cout << "Precio: C$ " << currentGft.gft_Mney << endl;

    addGft(currentGft);
    saveGft();

    cout << GREEN << "Presiona Enter para continuar..." << RESET << endl;
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    MDgft();
}

void MDcmp(int enteredCltid)
{
    readCMP();
    string regreso;
    reg_compra currentCmp;
    int cmpOPt, cantPrd, pos;
    do
    {
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
        cout << CYAN << "            ||                                                              ||" << RESET << endl;
        cout << CYAN << "            ||                      " << RESET << BOLD << "GESTION DE COMPRAS                      "<< RESET << CYAN <<"||" << RESET << endl;
        cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
        cout <<CYAN << BOLD << "            ||               Cantidad de registros de compras: "<< lastREgCmp << "            ||" <<RESET<< endl;
        cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
        cout << BOLD << "            ||                "<<RESET<<CYAN<<"||**||"<<RESET<<"                  "<<CYAN"||**||"<<CYAN<<CYAN"                ||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"1. "<<RESET << WHITE << "Registro de compra.                     "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"2. "<<RESET << WHITE << "Historial de compras.                   "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                   " << RESET <<CYAN<<"3. "<<RESET << WHITE << "Volver...                              "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << "\n                  [OPCION] --> " << RESET;
        cin >> cmpOPt;

        switch (cmpOPt)
        {
        case 1:
           {
                system("cls || clear");
                cout << "\tRegistro de Compras" << endl;
                cout << "______________________________" << endl;
                cout << "** Ingrese los datos a añadir **" << endl;
                cout << "------------------------------" << endl;

                do {
                    cin.clear();
                    cout << "ID del cliente: ";
                    cin >> enteredCltid;
                    pos = searchCltId(enteredCltid);

                    if (cin.fail() || cin.peek() != '\n' || pos == -1) {
                        cerr << "Error: Cliente no encontrado o ID inválido. Intente de nuevo..." << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    } else {
                        reg_compra currentCmp;
                        currentCmp.clt.client_id = enteredCltid;

                        cout << "N* de Recibo: ";
                        cin >> currentCmp.cmpr_id;

                        cout << "Fecha de compra (dd-mm-yyyy): ";
                        cin >> currentCmp.fCmp.day >> currentCmp.fCmp.month >> currentCmp.fCmp.year;

                        do {
                            cout << "Cantidad de productos a facturar (ingrese uno por línea): ";
                            cin >> cantPrd;
                            if (cin.fail() || cin.peek() != '\n') {
                                cout << "Ingrese un ID válido, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
                                cin.clear();
                                cin.ignore(INT_MAX, '\n');
                            } else {
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                for (int i = 0; i < cantPrd; ++i) {
                                    cout << "Producto " << i + 1 << ": ";
                                    cin >> currentCmp.prodCmpr[i];
                                }
                            }

                        } while (cin.fail() || cin.peek() != '\n');

                        cout << "Monto de compra: C$ ";
                        cin >> currentCmp.cmpr_Sqty;

                        currentCmp.cmp_iva = currentCmp.cmpr_Sqty * 0.15;
                        cout << "Iva: " << currentCmp.cmp_iva << endl;

                        currentCmp.cmpr_Tqty = currentCmp.cmpr_Sqty + currentCmp.cmp_iva;
                        cout << "Total: C$ " << currentCmp.cmpr_Tqty << endl;

                        currentCmp.cmpr_pts = static_cast<int>(currentCmp.cmpr_Tqty / 100);
                        cout << "Puntos por compra: " << currentCmp.cmpr_pts << " pts" << endl;
                        cout << "||=========================||" << endl;

                        // Actualizar puntos directamente al agregar la compra
                        if (currentCmp.clt.client_id >= 0 && currentCmp.clt.client_id < lastRegClt)
                        {
                            clt[pos].puntos += currentCmp.cmpr_pts;
                        }

                        addCmp(currentCmp);
                        saveCMP();
                        saveClt();

                        cout << "Presiona enter para continuar...";
                        cin.ignore();
                        cin.get();
                    }
                } while (cin.fail() || cin.peek() != '\n' || pos == -1);
            }
            break;
        case 2:
            record();
            break;
        case 3:
            MAdm();
            break;           
        default:
            cout << "Ingrese una opcion valida. 1 - 3..." << endl;
            break;
        }
    } while (cmpOPt != 3);
}

void record()
{
    readClt();
    readCMP();
    int pos, enteredCltid;

    do {
        cout << "ID de cliente: " << endl;
        cin >> enteredCltid;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "Ingrese un ID válido, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } else {
            pos = searchCltId(enteredCltid);

            if (pos != -1) {
                showCmpRegister(enteredCltid);
            } else {
                cout << "Cliente no encontrado" << endl;
            }
        }
    } while (cin.fail() || cin.peek() != '\n');

    cin.get();
    MDcmp(enteredCltid);
}

void searchMclt()
{
    readClt();
    int options, pos;
    char enteredClt_name[50];
    char enteredClt_lstName[50];
    int enteredClt_id = 0;
    char enteredClt_mail[50];
    int enteredClt_telf;

    do
    { // borrar los cin.ignore
        system("cls || clear");
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << BOLD << "            ||-------------------------" << RESET << BOLD << "Echo-Exchange" << RESET << CYAN << BOLD << "------------------------||" << RESET <<endl;
        cout << CYAN << "            ||                                                              ||" << RESET << endl;
        cout << CYAN << "            ||"<<RESET<<BOLD<<"                       MENU DE BUSQUEDA                       "<<RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << BOLD << "            ||______________________________________________________________||" << endl;
        cout << CYAN << BOLD << "            ||--------------------------------------------------------------||" << endl;
        cout << BOLD << "            ||                "<<RESET<<CYAN<<"||*||"<<RESET<<"                    "<<CYAN"||*||"<<CYAN<<CYAN"                ||" << RESET << endl;
        cout << CYAN << "            ||                  " << RESET <<CYAN<<"1. "<<RESET << WHITE << "Nombre.                                  "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                  " << RESET <<CYAN<<"2. "<<RESET << WHITE << "Apellido.                                "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                  " << RESET <<CYAN<<"3. "<<RESET << WHITE << "ID.                                      "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                  " << RESET <<CYAN<<"4. "<<RESET << WHITE << "E-mail.                                  "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                  " << RESET <<CYAN<<"5. "<<RESET << WHITE << "Telefono.                                "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||                  " << RESET <<CYAN<<"6. "<<RESET << WHITE << "Volver...                                "<< RESET<<CYAN<<"||" << RESET << endl;
        cout << CYAN << "            ||==============================================================||" << RESET << endl;
        cout << CYAN << "\n                  [OPCION] --> " << RESET;
        cin >> options;

        switch (options) {
            case 1:
                system("cls || clear");
                cout << CYAN <<"                  ||*||"<<RESET<<BOLD<< "BUSCAR POR NOMBRE DEL CLIENTE"<<RESET<<CYAN<<"||*||"<<RESET<< endl;
                do {
                    cout << CYAN << "\n                [ NOMBRE A BUSCAR ] --> " << RESET;
                    cin.ignore();
                    cin.getline(enteredClt_name, sizeof(enteredClt_name));
                    if (any_of(enteredClt_name, enteredClt_name + strlen(enteredClt_name), ::isdigit)) {
                        cout <<YELLOW<< "Ingrese un nombre válido, solo con caracteres. Doble enter para intertar de nuevo..."<<RESET<< endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                } while (any_of(enteredClt_name, enteredClt_name + strlen(enteredClt_name), ::isdigit));

                searchCltname(enteredClt_name, true);
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            case 2:
                system("cls || clear");
                cout << CYAN <<"                  ||*||"<<RESET<<BOLD<< "BUSCAR POR APELLIDO DEL CLIENTE"<<RESET<<CYAN<<"||*||"<<RESET<< endl;
                do {
                    cout << CYAN << "\n                [ APELLIDO A BUSCAR ] --> " << RESET;
                    cin.ignore();
                    cin.getline(enteredClt_lstName, sizeof(enteredClt_lstName));
                    if (any_of(enteredClt_lstName, enteredClt_lstName + strlen(enteredClt_lstName), ::isdigit)) {
                        cout <<YELLOW<< "Ingrese un apellido válido, solo con caracteres. Doble enter para intertar de nuevo..." <<RESET<< endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                } while (any_of(enteredClt_lstName, enteredClt_lstName + strlen(enteredClt_lstName), ::isdigit));

                searchCltlstname(enteredClt_lstName, true);
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            case 3:
                system("cls || clear");
                cout << CYAN <<"                  ||*||"<<RESET<<BOLD<< "BUSCAR POR ID DEL CLIENTE"<<RESET<<CYAN<<"||*||"<<RESET<< endl;
                do {
                    cout << CYAN << "\n                [ ID A BUSCAR ] --> " << RESET;
                    cin >> enteredClt_id;

                    // Verificar si el ID ingresado contiene caracteres no numéricos
                    if (cin.fail() || cin.peek() != '\n') {
                        cout <<YELLOW<< "Ingrese un ID válido, solo con dígitos. Doble enter para intentar de nuevo..." <<RESET<< endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    } else {
                        // Realizar la búsqueda si el ID es válido
                        pos = searchCltId(enteredClt_id);
                        if (pos != -1) {
                            showClt(pos);
                        } else {
                            cout <<YELLOW<< "Registro Inexistente" <<RESET<< endl;
                        }
                    }
                } while (cin.fail() || cin.peek() != '\n');
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                break;
            case 4:
                system("cls || clear");
                cout << CYAN <<"                  ||*||"<<RESET<<BOLD<< "BUSCAR POR EL E-MAIL DEL CLIENTE"<<RESET<<CYAN<<"||*||"<<RESET<< endl;
                do {
                    cout << CYAN << "\n                [ E-MAIL A BUSCAR ] --> " << RESET;
                    cin.ignore();
                    cin.getline(enteredClt_mail, sizeof(enteredClt_mail));
                    if (strstr(enteredClt_mail, "@gmail.com") == NULL) {
                        cout << "El correo debe terminar en @gmail.com. Inténtelo de nuevo..." << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                } while ((strstr(enteredClt_mail, "@gmail.com") == NULL));

                searchCltmail(enteredClt_mail);
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            case 5:
                system("cls || clear");
                cout << CYAN <<"                  ||*||"<<RESET<<BOLD<< "BUSCAR POR TELEFONO DEL CLIENTE"<<RESET<<CYAN<<"||*||"<<RESET<< endl;
                cout << CYAN << "\n                [ TELEFONO A BUSCAR ] --> " << RESET;
                cin >> enteredClt_telf;
                pos = searchCltelf(enteredClt_telf);
                if (pos != -1) {
                    showClt(pos);
                } else {
                    cout << "Registro Inexistente" << endl;
                }
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                break;
            case 6:
                system("cls || clear");
                cout << "Saliendo..." << endl;
                MDclient();
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            default:
                cout << "Opcion Invalida. Ingrese una opcion valida del 1 - 7" << endl;
                break;
        }
    } while (options != 6);
}

void redeem() 
{
    int enteredClt_id, enteredGft_id, pos, gftPos;
    int qtyToRedeem;

    cout << "ID de cliente: ";
    cin >> enteredClt_id;

    if (cin.fail() || cin.peek() != '\n')
    {
        cerr <<YELLOW<<"Ingrese un Id de cliente valido..."<<RESET << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
        MClt();
        system("cls || clear");
        return;
    }

    pos = searchCltId(enteredClt_id);
    if (pos == -1) {
        cout << "Cliente Inexistente" << endl;
        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
        MClt();
        system("cls || clear");
        return;
    } else {
        showClt(pos);
    }

    // Mostrar recompensas disponibles
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "\tSeleccion de recompensas" << endl;
    showGftRegister();
    cout << "||=========================||" << endl;

    cout << "ID de la recompensa a canjear: ";
    cin >> enteredGft_id;

    if (cin.fail() || cin.peek() != '\n')
    {
        cerr << YELLOW << "ID de recompensa invalido..." << RESET << endl;
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
        MClt();
        system("cls || clear");
        return;

    }

    gftPos = searchGFTid(enteredGft_id);

    if (gftPos == -1) {
        cerr <<YELLOW<< "Recompensa Inexistente" <<RESET<< endl;
        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
        MClt();
        system("cls || clear");
        return;
    } else {
        showGft(gftPos);
    }

    char confirm;
    cout << "Desea canjear recompensas ? (y/n): ";
    cin >> confirm;

    if (tolower(confirm) != 'y') {
        cout <<YELLOW<< "Canje cancelado..." <<RESET<< endl;
        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
        MClt();
        system("cls || clear");
        return;
    }

    cout << "Cantidad de recompensa a canjear: ";
    cin >> qtyToRedeem;

    if (qtyToRedeem > 0 && qtyToRedeem <= gft[gftPos].gft_cant) {
        int totalPtsRequired = qtyToRedeem * gft[gftPos].gft_pts;

        if (clt[pos].puntos >= totalPtsRequired) {
            clt[pos].puntos -= totalPtsRequired;
            gft[gftPos].gft_cant -= qtyToRedeem;

            cout << GREEN << "Canje realizado exitosamente" << RESET << endl;
            showClt(pos);
            showGft(gftPos);
        } else {
            char payDifer;
            cout << YELLOW << "Puntos insuficientes. ¿Desea pagar la diferencia en efectivo? (y/n): ";
            cin >> payDifer;

            if (tolower(payDifer) == 'y') {
                int ptsRest = totalPtsRequired - clt[pos].puntos;
                float cashDifer = ptsRest * 100.0;

                cout << "Debe pagar la diferencia de C$ " <<UNDERLINE<< cashDifer <<RESET<< " en efectivo." << endl;
                clt[pos].puntos = 0;

            } else {
                cout <<YELLOW<< "Canje no realizado. Puntos insuficientes." <<RESET<< endl;
            }
        }
    } else {
        cout <<YELLOW<< "Canje no realizado. Verifique la cantidad de recompensas o sus puntos disponibles." <<RESET<< endl;
    }

    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
    MClt();
    system("cls || clear");
}

int consultarPtsCliente(int enteredCltid) {
    readClt();
    for (int i = 0; i < lastRegClt; i++) {
        if (clt[i].client_id == enteredCltid) {
            return clt[i].puntos;
        }
    }
    return -1;
}