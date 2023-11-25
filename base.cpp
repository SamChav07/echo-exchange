#include <iostream>
#include <cstring>
#include <string>

#include <cstdio>

#include <iomanip>
#include <unistd.h>

// libreria para all_of y ::isdigit
#include <algorithm>
#include <functional>
#include <cctype>

#include <fstream>

#include "structs.h"
#include "1_CRUDclt.cpp"
#include "2_CRUDgft.cpp"
#include "3_CRUDcmp.cpp"
#include "archivos.cpp"
using namespace std;

// LOG
void SuperAdmin();
void logAdm();
void logClt();

// menus
void MDclient(); //--listo
void MDcmp();
void MDgft();      // en proceso
void searchMclt(); // menu de busqueda de cliente   //--listo

void MAdm();
void MClt();

// funciones
void record();
void redeem();   // -------------pendiente
void checkPts(); // -------------pendiente




// variables globales
char user[50], pass[50];
int intentos = 4;







int opPtsGft(int enteredGft_id);

// codigos colores ANSI
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

int main()
{
    readClt();
    SuperAdmin();
    return 0;
}

void SuperAdmin()
{
    int spOpcion;

    do
    {
        system("cls || clear");
        cout << GREEN << "EEEE  CCCC  HH  HH  OOOOOO     EEEE  XX    XX  CCCC  HH  HH  AAAAAA  NN     NN  GGGGGG   EEEE" << RESET << endl;
        cout << GREEN << "EE    CC    HH  HH  OO  OO     EE     XX  XX   CC    HH  HH  AA  AA  NN NN  NN  GG       EE" << RESET << endl;
        cout << GREEN << "EEEE  CC    HHHHHH  OO  OO === EEEE    XXXX    CC    HHHHHH  AAAAAA  NN  NN NN  GG  GGG  EEEE" << RESET << endl;
        cout << GREEN << "EE    CC    HH  HH  OO  OO     EE     XX  XX   CC    HH  HH  AA  AA  NN   NNNN  GG  GG   EE" << RESET << endl;
        cout << GREEN << "EEEE  CCCC  HH  HH  OOOOOO     EEEE  XX    XX  CCCC  HH  HH  AA  AA  NN    NNN  GGGGGG   EEEE" << RESET << endl;

        cout << "||==================================================||" << endl;
        cout << "Bienvenido Super-Admin" << endl;
        cout << "Que cuenta desea fijar en el dispositivo ?" << endl;
        cout << "1. Administrador." << endl;
        cout << "2. Cliente." << endl;
        cout << "3. Cerrar." << endl;
        cout << "||==================================================||" << endl;
        cout << "\n --> ";
        cin >> spOpcion;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "Digite una de las opciones. Doble enter para intentar de nuevo..." << endl;
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
                cout << "--Gracias, por usar el sistema Echo-Exchange--" << endl;
                exit(0);
                break;
            default:
                cout << "Ingrese una opcion valida. 1 - 3..." << endl;
                break;
            }
        }

    } while (spOpcion < 1 || spOpcion > 3);
}

void logAdm()
{
    do
    {
        accounts administrador1;
        strcpy(administrador1.adminU, "."); // admin1
        strcpy(administrador1.admP, ".");   // password123

        cout << "\n---Administrador---" << endl;
        cout << "-------------" << endl;
        cout << "Usuario: ";
        cin >> user;
        cout << "\nContrasena: ";
        cin >> pass;

        // Verificaci�n de credenciales del administrador
        if (strcmp(user, administrador1.adminU) == 0 && strcmp(pass, administrador1.admP) == 0)
        {
            cout << "\n***Acceso concedido***\n";
            MAdm();
        }
        else
        {
            cout << "*** Intento fallido. Usuario o contrasena incorrecta ***" << endl;
            cout << "Intentos restantes: \n"
                 << intentos - 1 << endl;

            intentos--;
        }
    } while (intentos > 0);
    cout << "*** Intento fallido. Usuario o contrasena incorrecta ***" << endl;
    cout << "***Acceso bloqueado, saliendo del sistema...***";
}

void MAdm()
{
    int op1;
    do
    {
        system("cls || clear");
        cout << "Bienvenido Administrador" << endl;

        cout << "***--Opciones--***" << endl;
        cout << "1. Gestionar compras." << endl;
        cout << "2. Gestionar clientes." << endl;
        cout << "3. Gestionar recompensas." << endl;
        cout << "4. Cerrar Sesion" << endl;
        cout << "\n --> ";
        cin >> op1;
        system("pause");

        switch (op1)
        {
        case 1:
            MDcmp();
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
            cout << "Ingrese opciones validas. Sean de 1-4..." << endl;
            break;
        }
    } while (op1 != 4);
}

int opPtsGft(int enteredGft_id)
{
    int gftPos = -1;

    // Buscar el artículo por ID
    for (int i = 0; i < lasTregGft; ++i)
    {
        if (gft[gftPos].gft_id == enteredGft_id)
        {
            gftPos = i;
            break;
        }
    }

    if (gftPos != -1)
    {
        // Mostrar la cantidad existente del artículo
        cout << "Cantidad existente del artículo con ID " << gft[gftPos].gft_id << ": " << gft[gftPos].gft_cant << endl;

        // Solicitar al usuario la cantidad que desea tomar
        int cantidadTomar;
        cout << "Ingrese la cantidad que desea tomar: ";
        cin >> cantidadTomar;

        // Verificar si la cantidad es válida
        if (cantidadTomar <= gft[gftPos].gft_cant)
        {
            // Realizar la operación de resta
            gft[gftPos].gft_cant -= cantidadTomar;
            cout << "Operación exitosa. Se tomaron " << cantidadTomar << " unidades del artículo con ID " << gft[gftPos].gft_id << endl;
        }
        else
        {
            cout << "La cantidad ingresada es mayor que la cantidad existente. Operación cancelada." << endl;
        }
    }
    else
    {
        cout << "Registro Inexistente" << endl;
    }

    return 0;
}

void MClt() //////////////////// CLIENTES
{
    readCMP();
    readGft();
    readClt();
    int op2, pos;
    int i;
    int enteredClt_id;
    system("cls || clear");
    cout << "\nBienvenido Cliente" << endl;
    cout << "Ingrese su Id: ";
    cin >> enteredClt_id;
    pos = searchCltId(enteredClt_id);
    if (pos != -1) {
        do
        {
            cout << "\n***--Opciones--***" << endl;
            cout << "\n1.. Canjear puntos." << endl;
            cout << "\n2. Consultar puntos." << endl;
            cout << "\n3. Historial de compra." << endl;
            cout << "\n4. Refrescar Rtrn." << endl;
            cout << "\n --> ";
            cin >> op2;
            system("pause");

            switch (op2)
            {
            case 1:
                redeem();
                break;
            case 2:
                checkPts();
                break;
            case 3: // historial detenido
                /*cout << "ID de cliente: ";
                cin.ignore();
                cout << "" << endl;
                cin >> enteredClt_id;
                searCmpFID(enteredClt_id);
                showCmpRegister(i);
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                MClt();
                system("cls || clear");*/
                break;
            case 4:
                system("cls");
                MClt();
                break;
            default:
                cout << "Ingrese opciones validas. Sean de 1-4.." << endl;
                break;
            }
        } while (op2 != 4);
        
    } else {
        cout << "Registro inexistente" << endl;
    }
    system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
    MDclient();
}

void MDclient()
{
    readClt();

    cliente currentClt;
    int pos, resp;
    int enteredClt_id;

    int optMdclt;
    cin.clear();
    system("cls || clear");
    cout << "Clientes" << endl;
    cout << "Cantidad de registros de clientes: " << lastRegClt << endl;
    cout << "***--Opciones--***" << endl;
    cout << "1. Agregar cliente." << endl;
    cout << "2. Buscar cliente." << endl;
    cout << "3. Modificar cliente." << endl;
    cout << "4. Eliminar cliente." << endl;
    cout << "5. Atras..." << endl;
    cout << "\n --> ";
    cin.ignore();
    cin >> optMdclt;
    system("pause");

    switch (optMdclt)
    {
    case 1:
        system("cls || clear");
        cout << "** Ingrese los datos a añadir **" << endl;
        system("cls || clear");
        currentClt.client_id = getLstCltID();

        if (currentClt.client_id == -1)
        {
            cerr << "Error al obtener el último ID. No se pudo agregar el cliente..." << endl;
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            return;
        }

        cout << "ID: " << currentClt.client_id << endl;

        // Nombre del cliente
        do
        {
            cout << "Nombre del cliente: ";
            cin.ignore(); // Ignorar el carácter de nueva línea residual
            cin.getline(currentClt.client_name, sizeof(currentClt.client_name));
            if (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit))
            {
                cout << "Ingrese un nombre válido, solo con caracteres." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

        } while (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit));

        // Apellido del cliente
        do
        {
            cout << "Apellido del cliente: ";
            cin.getline(currentClt.client_lastname, sizeof(currentClt.client_lastname));
            if (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit))
            {
                cout << "Ingrese un apellido válido, solo con caracteres." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

        } while (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit));

        // E-mail del cliente
        do
        {
            cout << "E-mail del cliente: ";
            cin.getline(currentClt.client_mail, sizeof(currentClt.client_mail));
            if (strstr(currentClt.client_mail, "@gmail.com") == NULL)
            {
                cout << "El correo debe terminar en @gmail.com. Inténtelo de nuevo..." << endl;
                cin.clear();
                cin.ignore(INT_MAX, '\n');
            }

        } while (strstr(currentClt.client_mail, "@gmail.com") == NULL);

        // Teléfono del cliente
        do
        {
            cout << "Teléfono del cliente XXXX-XXXX: ";
            cin >> currentClt.client_telf;

            // Verificar si el formato del número de teléfono es correcto
            if (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999)
            {
                cout << "Ingrese un número telefónico válido. Use el formato XXXX-XXXX y solo incluya dígitos." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

        } while (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999);

        addClt(currentClt);
        saveClt();
        // saveCSVdata(); // llama a la función guardar antes de cerrar la sesión
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        MDclient();
        break;

    case 2:
        searchMclt();
        break;
    case 3:
        system("cls || clear");
        int opModclt;
        cout << "** Escribe el ID del cliente a modificar **" << endl;
        cin >> enteredClt_id;
        pos = searchCltId(enteredClt_id);
        currentClt.client_id = enteredClt_id;
        if (pos != -1)
        {
            do
            {
                cout << "Datos a modificar:" << endl;
                cout << "1. Nombre." << endl;
                cout << "2. Apellido." << endl;
                cout << "3. Correo." << endl;
                cout << "4. Teléfono." << endl;
                cout << "5. Todo el registro." << endl;
                cout << "6. Volver..." << endl;
                cout << "Opción: ";
                cin >> opModclt;
                if (cin.fail()) {
                    cout << "La opcion no puede ser caracter..." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');  
                }
                switch (opModclt)
                {
                case 1:
                    do {
                        cin.ignore();
                        cout << "Nuevo nombre: ";
                        cin.getline(currentClt.client_name, sizeof(currentClt.client_name));
                        copy(begin(clt[pos].client_lastname), end(clt[pos].client_lastname), begin(currentClt.client_lastname));
                        copy(begin(clt[pos].client_mail), end(clt[pos].client_mail), begin(currentClt.client_mail));
                        currentClt.client_telf = clt[pos].client_telf;

                        if (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit))
                        {
                            cout << "Ingrese un nombre válido, solo con caracteres." << endl;
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
                        cout << "Nuevo apellido: ";
                        cin.getline(currentClt.client_lastname, sizeof(currentClt.client_lastname));
                        copy(begin(clt[pos].client_name), end(clt[pos].client_name), begin(currentClt.client_name));
                        copy(begin(clt[pos].client_mail), end(clt[pos].client_mail), begin(currentClt.client_mail));
                        currentClt.client_telf = clt[pos].client_telf;
                        if (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit))
                        {
                            cout << "Ingrese un apellido válido, solo con caracteres." << endl;
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
                        cout << "Nuevo correo: ";
                        cin.getline(currentClt.client_mail, sizeof(currentClt.client_mail));
                        copy(begin(clt[pos].client_name), end(clt[pos].client_name), begin(currentClt.client_name));
                        copy(begin(clt[pos].client_lastname), end(clt[pos].client_lastname), begin(currentClt.client_lastname));
                        currentClt.client_telf = clt[pos].client_telf;
                        if (strstr(currentClt.client_mail, "@gmail.com") == NULL)
                        {
                            cout << "El correo debe terminar en @gmail.com. Inténtelo de nuevo..." << endl;
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
                        cout << "Nuevo telefono: ";
                        cin >> currentClt.client_telf;
                        copy(begin(clt[pos].client_name), end(clt[pos].client_name), begin(currentClt.client_name));
                        copy(begin(clt[pos].client_lastname), end(clt[pos].client_lastname), begin(currentClt.client_lastname));
                        copy(begin(clt[pos].client_mail), end(clt[pos].client_mail), begin(currentClt.client_mail));

                        if (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999)
                        {
                            cout << "Ingrese un número telefónico válido. Use el formato XXXX-XXXX y solo incluya dígitos." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                    } while (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999);
                    uptdClt(currentClt, pos);// actualiza
                    saveClt();//guarda
                    break;
                case 5:
                    do
                    {
                        cout << "Nombre del cliente: ";
                        cin.ignore(); // Ignorar el carácter de nueva línea residual
                        cin.getline(currentClt.client_name, sizeof(currentClt.client_name));
                        if (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit))
                        {
                            cout << "Ingrese un nombre válido, solo con caracteres." << endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                    } while (any_of(currentClt.client_name, currentClt.client_name + strlen(currentClt.client_name), ::isdigit));

                    do
                    {
                        cout << "Apellido del cliente: ";
                        cin.getline(currentClt.client_lastname, sizeof(currentClt.client_lastname));
                        if (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit))
                        {
                            cout << "Ingrese un apellido válido, solo con caracteres." << endl;
                            cin.clear();
                            cin.ignore(INT_MAX, '\n');
                        }
                    } while (any_of(currentClt.client_lastname, currentClt.client_lastname + strlen(currentClt.client_lastname), ::isdigit));

                    do
                    {
                        cout << "E-mail del cliente: ";
                        cin.getline(currentClt.client_mail, sizeof(currentClt.client_mail));
                        if (strstr(currentClt.client_mail, "@gmail.com") == NULL)
                        {
                        cout << "El correo debe terminar en @gmail.com. Inténtelo de nuevo..." << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        }
                    } while (strstr(currentClt.client_mail, "@gmail.com") == NULL);

                    do
                    {
                        cout << "Teléfono del cliente XXXX-XXXX: ";
                        cin >> currentClt.client_telf;

                        // Verificar si el formato del número de teléfono es correcto
                        if (currentClt.client_telf < 10000000 || currentClt.client_telf > 99999999)
                        {
                            cout << "Ingrese un número telefónico válido. Use el formato XXXX-XXXX y solo incluya dígitos." << endl;
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
                    cout << "Opción no válida. Por favor, inténtelo de nuevo" << endl;
                    break;
                }
            } while(opModclt != 6 || cin.fail());
            saveClt();
        }
        else
        {
            cout << "Registro inexistente" << endl;
        }
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        break;
    case 4:
        system("cls || clear");
        if (lastRegClt == 0)
        {
            cout << "No hay nada que eliminar\n";
            break;
        }
        do {
            cout << "Escribe el ID del cliente: " << endl;
            cin >> enteredClt_id;
            pos = searchCltId(enteredClt_id);
            if (pos != -1)
            {
                currentClt = getClt(pos);
                cout << "¿Realmente deseas eliminar el cliente ?" << endl;
                cout << "Escriba 1 para SI o 2 para NO : ";
                cin >> resp;
                if (resp == 1)
                {
                    delClt(pos);
                    cout << "Registro eliminado...\n";
                }
            else
            {
                cout << "Operacion cancelada...\n";
            }
            
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
        } while(resp !=1 && resp !=2);
        saveClt();
        MDclient();
        break;
    case 5:
        MAdm();
        break;

    default:
        cout << "Ingrese una opcion valida. Del 1 - 5..." << endl;
        break;
    }
}

void MDgft()
{
    readGft();

    gift currentGft;
    int gftPos, resp;
    int enteredGft_id;
    char enteredGft_name[50];

    int optMdGft;
    do {
        system("cls || clear");
        cout << "RECOMPENSAS" << endl;
        cout << "Cantidad de registros de Recompensas: " << lasTregGft << endl; // arreglar segun sus datos
        cout << "***--Opciones--***" << endl;
        cout << "1. Agregar recompensa." << endl;
        cout << "2. Buscar recompensa." << endl;
        cout << "3. Modificar recompensa." << endl;
        cout << "4. Eliminar recompensa." << endl;
        cout << "5. Atras..." << endl;
        cout << "\n --> ";
        cin >> optMdGft;

        switch (optMdGft)
        {
        case 1:
            system("cls || clear");
            cout << "** Ingrese los datos a añadir **" << endl;
            system("cls || clear");
            currentGft.gft_id = getLstGftID();
            if (currentGft.gft_id == -1)
            {
                cerr << "Error al obtener el último ID. No se pudo agregar la recompensa..." << endl;system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                return;
            }
            cout << "ID: " << currentGft.gft_id << endl;

            // Nombre del cliente    este no lleva restricciones porque el nombre puede ser un modelo MXi98S2
            do
            {
                cout << "Nombre de la recompensa: ";
                cin.getline(currentGft.gft_name, sizeof(currentGft.gft_name));

                if (strlen(currentGft.gft_name) < 5)
                {
                    cout << "\nEl nombre es demasiado corto! Minimo 5 caracteres." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                else if (strlen(currentGft.gft_name) > 49)
                {
                    cout << "El nombre es demasiado largo! Maximo 50 caracteres." << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
            } while (strlen(currentGft.gft_name) < 5 || strlen(currentGft.gft_name) > 49);

            // Cantidad de la recomp
            do
            {
                cout << "Cantidad del producto: ";
                cin >> currentGft.gft_cant;
                if (currentGft.gft_cant >= 1000)
                {
                    cout << "La cantidad debe tener menos de tres digitos!" << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
            } while (currentGft.gft_cant >= 1000);

            // pts necesarios
            do
            {
                cout << "Puntos Necesarios: ";
                cin >> currentGft.gft_pts;
                if (currentGft.gft_pts >= 1000000000)
                {
                    cout << "Los puntos no pueden ser mayor a 1,000,000,000" << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
                else if (currentGft.gft_pts <= 100)
                {
                    cout << "Los puntos no pueden ser menor a 100" << endl;
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                }
            } while ((currentGft.gft_pts >= 1000000000) || (currentGft.gft_pts <= 100));

            addGft(currentGft);
            saveGft();
            // llama a la función guardar antes de cerrar la sesión
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            MDgft();
            break;

        case 2:
            int opBsqGft;

            do
            {
                cout << "Busqueda de Recompensa:" << endl;
                cout << "1. ID." << endl;
                cout << "2. Nombre." << endl;
                cout << "3. Todos los registros." << endl;
                cout << "4. Atras..." << endl;
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
                        cout << "Visualizando todos los registros..." << endl;
                        showGftRegister();
                        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                        break;
                    case 4:
                        system("cls || clear");
                        cout << "Saliendo..." << endl;
                        MDgft();
                        system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                        break;
                    default:
                        cout << "Opcion Invalida. Ingrese una opcion valida del 1 - 4" << endl;
                        break;
                    }
            } while (opBsqGft != 4);

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
            MAdm();
            break;
        default:
            cout << "Ingrese una opcion valida. Del 1 - 5..." << endl;
            break;
        }
    } while (optMdGft != 5);
}

void MDcmp()
{
    readClt();
    readCMP();
    string regreso;
    reg_compra currentCmp;
    int cmpOPt;
    do
    {
        system("cls || clear");
        cout << "Modulo Compra" << endl;
        cout << "**OPCIONES**" << endl;
        cout << "1. Registro de compra." << endl;
        cout << "2. Historial de compras." << endl;
        cout << "3. Atras..." << endl;
        cout << "\n --> ";
        cin >> cmpOPt;

        switch (cmpOPt)
        {
        case 1:
            system("cls || clear");
            cout << "\tRegistro de Compras" << endl;
            cout << "______________________________" << endl;
            cout << "** Ingrese los datos a añadir **" << endl;
            cout << "------------------------------" << endl;
            system("cls || clear");
            cout << "ID del cliente: ";
            cin >> currentCmp.clt.client_id;

            cout << "N* de Recibo: ";
            cin >> currentCmp.cmpr_id;

            cout << "Fecha de compra: ";
            cin >> currentCmp.fCmp.day;
            cout << "-";
            cin >> currentCmp.fCmp.month;
            cout << "-";
            cin >> currentCmp.fCmp.year;

            cout << "Productos facturados: ";
                for (int i = 0; i < 10; ++i) {
                cin >> currentCmp.prodCmpr[i];
                }

            cout << "Monto de compra: C$ ";
            cin >> currentCmp.cmpr_Sqty;

            currentCmp.cmp_iva = currentCmp.cmpr_Sqty * 0.15;
            cout << "Iva: " << currentCmp.cmp_iva << endl;

            currentCmp.cmpr_Tqty = currentCmp.cmpr_Sqty + currentCmp.cmp_iva;
            cout << "Total: C$ " << currentCmp.cmpr_Tqty << endl;

            currentCmp.cmpr_pts = currentCmp.cmpr_Tqty / 180;
            cout << "Puntos por compra: " << currentCmp.cmpr_pts << " pts" << endl;
            cout << "||=========================||" << endl;
                // cout << "¿Desea volver a registrar otra compra o salir al menu? (v/s): " << endl;

            addCmp(currentCmp);
            saveCMP();
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            break;
        case 2:
            record();
            break;
        case 3:
            MAdm();
            break;
        }
    } while (cmpOPt != 3);
}

void record()
{
    
    int pos, enteredCltid;
    do {
        cout << "ID de cliente: " << endl;
        cin >> enteredCltid;

        if (cin.fail() || cin.peek() != '\n') {
            cout << "Ingrese un ID válido, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
        } 
        else
        { 
            pos = searchCltId(enteredCltid);

            if (pos != -1) {
                showCmpRegister(enteredCltid, pos);
            }
            else
            {
                cout << "Cliente no encontrado" << endl;
            }
        }
    } while (cin.fail() || cin.peek() != '\n');
    cin.get();
    MDcmp();
    system("cls || clear");
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
        cout << "** Menu de busqueda **" << endl;
        cout << "1. Nombre." << endl;
        cout << "2. Apellido." << endl;
        cout << "3. Id." << endl;
        cout << "4. E-mail." << endl;
        cout << "5. Telefono." << endl;
        cout << "6. Mostrar todos los registros." << endl;
        cout << "7. Atras..." << endl;
        cout << "\n --> ";

        cin >> options;

        switch (options) {
            case 1:
                system("cls || clear");
                cout << "Buscar por nombre de Cliente" << endl;
                do {
                    cout << "Nombre a buscar: ";
                    cin.ignore();
                    cin.getline(enteredClt_name, sizeof(enteredClt_name));
                    if (any_of(enteredClt_name, enteredClt_name + strlen(enteredClt_name), ::isdigit)) {
                        cout << "Ingrese un nombre válido, solo con caracteres. Doble enter para intertar de nuevo..."
                             << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                } while (any_of(enteredClt_name, enteredClt_name + strlen(enteredClt_name), ::isdigit));

                searchCltname(enteredClt_name, true);
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            case 2:
                system("cls || clear");
                cout << "Buscar por apellido de Cliente" << endl;
                do {
                    cout << "Apellido a buscar: ";
                    cin.ignore();
                    cin.getline(enteredClt_lstName, sizeof(enteredClt_lstName));
                    if (any_of(enteredClt_lstName, enteredClt_lstName + strlen(enteredClt_lstName), ::isdigit)) {
                        cout << "Ingrese un apellido válido, solo con caracteres. Doble enter para intertar de nuevo..." << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    }
                } while (any_of(enteredClt_lstName, enteredClt_lstName + strlen(enteredClt_lstName), ::isdigit));

                searchCltlstname(enteredClt_lstName, true);
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            case 3:
                system("cls || clear");
                cout << "Buscar por id de Cliente" << endl;
                do {
                    cout << "ID a buscar: ";
                    cin >> enteredClt_id;

                    // Verificar si el ID ingresado contiene caracteres no numéricos
                    if (cin.fail() || cin.peek() != '\n') {
                        cout << "Ingrese un ID válido, solo con dígitos. Doble enter para intentar de nuevo..." << endl;
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                    } else {
                        // Realizar la búsqueda si el ID es válido
                        pos = searchCltId(enteredClt_id);
                        if (pos != -1) {
                            showClt(pos);
                        } else {
                            cout << "Registro Inexistente" << endl;
                        }
                    }
                } while (cin.fail() || cin.peek() != '\n');
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            case 4:
                system("cls || clear");
                cout << "Buscar por e-mail de Cliente" << endl;
                do {
                    cout << "E-mail a buscar: ";
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
                cout << "Buscar por telefono de Cliente" << endl;
                cout << "Telefono a buscar: ";
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
                cout << "Visualizando todos los registros..." << endl;
                showCltRegister();
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                break;
            case 7:
                system("cls || clear");
                cout << "Saliendo..." << endl;
                MDclient();
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");

                break;
            default:
                cout << "Opcion Invalida. Ingrese una opcion valida del 1 - 7" << endl;
                break;
        }
    } while (options != 7);
}

void MDrewards() // -------------pendiente
{
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tCRUD rewards" << endl;
    cout << "______________________________" << endl;
    cout << "------------------------------" << endl;
    cout << " Agregar - Editar - Eliminar " << endl;
    cout << "¿Desea volver Agregar, Editar, Eliminar recompensas? (a/ e/ d): " << endl;
    cout << "a" << endl;
    cout << "=============================" << endl;
    cout << "ID-gft:    00190" << endl;
    cout << "Nombre de la recompensa:    MX log S2" << endl;
    cout << "Cantidad:    02" << endl;
    cout << "Puntos necesarios:  320 pts" << endl;
    cout << "||=========================||" << endl;
    cout << "¿Desea volver al CRUD o salir al menu? (v/s): " << endl;
}
void redeem() // -------------pendiente
{
    int i, pos, gftPos, OPT;
    int enteredClt_id, enteredGft_id;
    cout << "ID de cliente: ";
    cin.ignore();
    cout << "" << endl;
    cin >> enteredClt_id;
    pos = searchCltId(enteredClt_id);
    if (pos != -1)
    {
        showClt(pos);
    }
    else
    {
        cout << "Registro Inexistente" << endl;
    }
    searCmpFID(enteredClt_id);
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tSeleccion de recompensas" << endl;
    showGftRegister();
    cout << "||=========================||" << endl;
    cout << "ID de la recompensa a canjear:";
    cin >> enteredGft_id;
    gftPos = searchGFTid(enteredGft_id);
    if (gftPos != -1)
    {
        showGft(gftPos);
    }
    else
    {
        cout << "Registro Inexistente" << endl;
    }

    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
    MClt();
    system("cls || clear");
}
void checkPts() // -------------pendiente
{
    for (int i = 0; i < lastREgCmp; i++) 
    {
        int cltId = cmp[i].clt.client_id;
        int ptsEarn = cmp[i].cmpr_pts;
        //hst.cmpr_ptsTot[cltId] += ptsEarn;
    }
}