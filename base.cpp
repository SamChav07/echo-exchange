#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <cstring>
using namespace std;

// Definicion de estructuras
const int MAX = 100;

struct accounts {
    char adminU[50];     // "00017"
    char admP[50];       // "admPass007"
};

struct empleado {
    char nombre[20];
    char empU[50];      // "00016"
    char empP[50];    // "enployee123"
    string empmail;
    string emptel;
}emp;

struct cliente {
    char client_name[20];
    char client_lastname[20];
    int client_id;
    char client_mail[50];
    char client_telf[15];
}clt[MAX];

struct cmpr_fecha {
    int day;
    int month;
    int year;
}fCmp;

struct reg_compra {
    cliente clt;
    int cmpr_id;
    cmpr_fecha fCmp;
    float cmpr_qty; // monto de la compra
    int cmpr_pts;
}cmp;

struct historial {
    reg_compra r_cmpr;
    int cmpr_ptsTot;
}hst;

struct gift {
    int gft_cant;
    string gft_name;
    int gft_pts;
}gft;
// fin de struct

// LOG
void login(); // --ready

// menus
void MDclient(); //--listo
void searchMclt(); // menu de busqueda de cliente   //--listo

// CRUD clt
// create
void addClt(cliente currentClt); //--listo
void initClt(int cltPos); //--listo
// read
void showClt(); //--listo
void showCltRegister();
cliente getClt(int pos);
int searchCltname(char client_name[]);  //--listo
int searchCltlstname(char *client_lstName); //--listo
int searchCltId(int client_id); //listo
int searchCltmail(char client_mail[]);  //--listo
int searchCltelf(char client_telf[]);   //--listo
// uptade
void uptdClt(cliente cliente, int i); // --listo
// delete
void delClt ();  // --listo

void addPurchase();

// funciones
void regPurchase(); // -------------pendiente
void MDrewards(); // -------------pendiente
void redeem();  // -------------pendiente
void checkPts();    // -------------pendiente
void record();  // -------------pendiente
// falkta 

// variables globales
int lastRegClt = 0;
int proxIDclt = 123;
int lastRegCmp = 0;
int idCmp = 321;

int main()
{
    login();
    return 0;
}

void login() {
    int intentos = 3;
    string user, pass;
    cout << "Bienvenido al sistema EchoExchange" << endl;
    cout << "\nSeleccione una opcion para entrar al sistema:\n";
    cout << "1. Administrador\n";
    cout << "2. Empleado\n";
    cout << "3. Gestionar credenciales de acceso.\n";
    cout << "4. Salir del sistema.\n";

    int opcion;
    cin >> opcion;

    switch (opcion) {
        case 1: // Acceso al men� del administrador

            do {
                accounts administrador1;
                strcpy(administrador1.adminU, "admin1");
                strcpy(administrador1.admP, "password123");

                cout << "\n---Administrador---" << endl;
                cout << "-------------" << endl;
                cout << "Usuario: ";
                cin >> user;
                cout << "\nContrasena: ";
                cin >> pass;

                // Verificaci�n de credenciales del administrador
                if (reinterpret_cast<const char *>(user, administrador1.adminU) == 0 && strcmp(pass, administrador1.admP) == 0) {
                    int op1;
                    cout<<"\n***Acceso concedido***\n";
                    cout << "Bienvenido Administrador" << endl;

                    cout << "***--Opciones--***" << endl;
                    cout << "1. Registrar compras." << endl;
                    cout << "2. Gestionar clientes." << endl;
                    cout << "3. Gestionar recompensas." << endl;
                    cout << "4. Salir" << endl;
                    cin >> op1;
                    system("pause");

                    switch (op1) {
                        case 1:
                            regPurchase();
                            break;
                        case 2:
                            MDclient();
                            break;
                        case 3:
                            MDrewards();
                            break;
                        case 4:
                            system("cls");
                            login();
                            break;
                        default:
                            cout <<"Ingrese opciones validas. Sean de 1-4..." << endl;
                            break;
                    }
                } else {
                    cout << "*** Intento fallido. Usuario o contrasena incorrecta ***" << endl;
                    cout << "Intentos restantes: \n" << intentos-1 << endl;

                    intentos--;
                }
            }while (intentos > 0);
            cout << "*** Intento fallido. Usuario o contrasena incorrecta ***" << endl;
            cout<<"***Acceso bloqueado, saliendo del sistema...***";
            break;
        case 2: // Acceso al men� de empleado
            do{
                empleado empleado1;
                strcpy(empleado1.empU, "usuario1");
                strcpy(empleado1.empP, "password123");

                int intentos = 4;

                cout << "---Empleado---" << endl;
                cout << "-------------" << endl;

                cout << "\nUsuario: ";
                cin >> user;
                cout << "\nContrasena: ";
                cin >> pass;

                // Verificaci�n de credenciales del cliente
                if (strcmp(user, empleado1.empU) == 0 && strcmp(pass, empleado1.empP) == 0)
                {
                    reg_compra currentCmp;
                    int op2;
                    cout<<"\n***Acceso concedido***\n";

                    cout << "\nBienvenido Empleado" << endl;
                    cout << "\n***--Opciones--***" << endl;
                    cout << "\n1. Registrar compra." << endl;
                    cout << "\n2. Canjear puntos." << endl;
                    cout << "\n3. Consultar puntos." << endl;
                    cout << "\n4. Historial de compra." << endl;
                    cout << "\n5. Salir." << endl;
                    cin >> op2;
                    system("pause");

                    switch (op2)
                    {
                        case 1:
                            system("cls || clear");
                            cout << "** Ingrese los datos de la compra **" << endl;
                            system("cls || clear");
                            
                            cout << "ID de la compra" << endl;
                            cout << "Nombre del cliente: " << endl;
                            cout << "Apellido del cliente: " << endl;
                            cout << "E-mail del cliente: " << endl;
                            cout << "Telefono del cliente: " << endl;
                
                            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                            break;
                            regPurchase();
                            break;
                        case 2:
                            redeem();
                            break;
                        case 3:
                            checkPts();
                            break;
                        case 4:
                            record();
                            break;
                        case 5:
                            system("cls");
                            login();
                            break;
                        default:
                            cout << "Ingrese opciones v�lidas. Sean de 1-4.." << endl;
                            break;
                    }

                } else {
                    cout << "\n*** Intento fallido. Usuario o contrase�a incorrecta ***" << endl;
                    cout << "Intentos restantes: " << intentos-1 << endl;
                    intentos--;
                }
            }while (intentos > 0);
            cout << "\n*** Intento fallido. Usuario o contrase�a incorrecta ***" << endl;
            cout<<"***Acceso bloqueado, saliendo del sistema...***";
            break;
        case 3: // Men� de gesti�n de credenciales

            do {
                cout<< "\n***ADMINISTRADOR DE CREDENCIALES***"<<endl;
                cout<<"\n1.Gestionar administradores."<<endl;
                cout<<"2. Gestionar usuarios"<<endl;
                cout<<"3. Salir a menu principal"<<endl;
                cout<<"Digite una opcion: ";
                cin>>opcion;

                switch(opcion){
                    case 1:


                        break;
                    case 2:


                        break;
                    case 3:


                        break;
                    default:


                        break;
                }

            } while (opcion!=3 );

            break;
        case 4:
            cout << "---Gracias por utilizar el sistema EchoExchange, que tenga un buen dia---" << endl;
            break;
        default:
            cout << "Ingrese una opcion valida." << endl;
            break;
    }
}



void Mdclient()
{
    cliente currentClt;
    int actions, pos, resp;
    char enteredClt_id;


    int optMdclt;
    cout << "Clientes" << endl;
    cout << "Cantidad de registros de clientes: " << lastRegClt <<endl;
    cout << "***--Opciones--***" << endl;
    cout << "1. Agregar cliente." << endl;
    cout << "2. Buscar cliente." << endl;
    cout << "3. Modificar cliente." << endl;
    cout << "4. Eliminar cliente." << endl;
    cout << "5. Salir..." << endl;
    cin >> optMdclt;
    system("pause");

    switch (optMdclt)
    {
    case 1:
        system("cls || clear");
        cout << "** Ingrese los datos a añadir **" << endl;
        system("cls || clear");
        currentClt.client_id = proxIDclt;
        cout << "ID: " << proxIDclt <<  endl;
        cout << "Nombre del cliente: " << endl;
        cout << "Apellido del cliente: " << endl;
        cout << "E-mail del cliente: " << endl;
        cout << "Telefono del cliente: " << endl;
        scanf(" %[^\n]", currentClt.client_name);
        scanf(" %[^\n]", currentClt.client_lastname);
        scanf(" %[^\n]", currentClt.client_mail);
        scanf(" %[^\n]", currentClt.client_telf);

        addClt(currentClt);
        system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        break;
    case 2:
        searchMclt();
        break;
    case 3:
        system("cls || clear");
            cout << "** Escribe el id del cliente a modificar **" << endl;
            cin >> enteredClt_id;
            pos = searchCltId(enteredClt_id);
            if (pos != -1) {
                system("cls || clear");
                showClt(pos);
                cout << "Datos a modificar: " << endl;
                cout << "Nombre del cliente: " << endl;
                cout << "Apellido del cliente: " << endl;
                cout << "E-mail del cliente: " << endl;
                cout << "Telefono del cliente: " << endl;
                scanf(" %[^\n]", currentClt.client_name);
                scanf(" %[^\n]", currentClt.client_lastname);
                scanf(" %[^\n]", currentClt.client_mail);
                scanf(" %[^\n]", currentClt.client_telf);

                cout << "Registro actualizado...\n";
                system("cls || clear");
                uptdClt(currentClt, pos);
            } else {
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
        cout << "Escribe el ID del cliente: " << endl;
        cin >> enteredClt_id;
        pos = searchCltId(enteredClt_id);
        if (pos != -1) {
            currentClt = getClt(pos);
            cout << "¿Realmente deseas eliminar el cliente ?" << endl;
            cout << "Escriba 1 para SI o 2 para NO : ";
            cin >> resp;
            if (resp == 1) {
                delClt(int pos);
                cout << "Registro eliminado...\n";
            } else {
                cout << "Operacion cancelada...\n";
            }
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
        } else {
            cout << "Registro inexistente" << endl;
        }
        break;
    case 5:
        log();
        break;

    default:
        cout << "Ingrese una opcion valida. Del 1 - 5..." << endl;
        break;
    }
}

void addClt(cliente currentClt)
{
    if (lastRegClt < MAX) {
        clt[lastRegClt] = currentClt;
        lastRegClt++;
    } else { cout << "Clientes esta en MAXima capacidad..." << endl; }
    
}

void initClt(int pos) // inicializa los datos del cliente
{
    clt[pos].client_id[sizeof(clt[pos].client_id) - 1] = '\0';
    strcpy(clt[pos].client_name, "", sizeof(clt[pos].client_name));
    strcpy(clt[pos].client_lastName, "", sizeof(clt[pos].client_lastName));
    strcpy(clt[pos].client_mail, "", sizeof(clt[pos].client_mail));
    strcpy(clt[pos].client_telf, "", sizeof(clt[pos].client_telf));
}

void searchMclt()
{
    int options, pos;
    char enteredClt_name[20];
    char enteredClt_lstName[20];
    int enteredClt_id = 0;
    char enteredClt_mail[50];
    char enteredClt_telf[15];

    do
    {
        system("cls || clear");
        cout << "** Menu de busqueda **" << endl;
        cout << "1. Nombre." << endl;
        cout << "2. Apellido." << endl;
        cout << "3. Id." << endl;
        cout << "4. E-mail." << endl;
        cout << "5. Telefono." << endl;
        cout << "6. Mostrar todos los registros." << endl;
        cout << "7. Cerrar Sesion." << endl;
        cout << "Seleccione una opcion: ";
        cin >> options;

        switch (options)
        {
        case 1:
            system("cls || clear");
            cout << "Buscar por nombre de Cliente" << endl;
            cout << "Nombre a buscar: ";
            cin.ignore(); // limpia la entrada
            cin.getline(enteredClt_name, sizeof(enteredClt_name));
            searchCltname(reinterpret_cast<char *>(&enteredClt_name));
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 2:
            system("cls || clear");
            cout << "Buscar por apellido de Cliente" << endl;
            cout << "Apellido a buscar: ";
            cin.ignore();
            cin.getline(enteredClt_lstName, sizeof(enteredClt_lstName));
            searchCltlstname(&enteredClt_lstName[20]);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 3:
            system("cls || clear");
            cout << "Buscar por id de Cliente" << endl;
            cout << "ID a buscar: ";
            cin.ignore();
            cin >> enteredClt_id;
            searchCltId(*reinterpret_cast<char *>(enteredClt_id));
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 4:
            system("cls || clear");
            cout << "Buscar por e-mail de Cliente" << endl;
            cout << "E-mail a buscar: ";
            cin.ignore();
            cin.getline(enteredClt_mail, sizeof(enteredClt_mail));
            searchCltmail(&enteredClt_mail[50]);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 5:
            system("cls || clear");
            cout << "Buscar por telefono de Cliente" << endl;
            cout << "Telefono a buscar: ";
            cin.ignore();
            cin.getline(enteredClt_telf, sizeof(enteredClt_telf));
            searchCltelf(&enteredClt_telf[15]);
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        case 6:
            system("cls || clear");
            cout << "Visualizando todos los registros..." << endl;
            showCltRegister();
            system("cls || clear");
            break;
        case 7:
            system("cls || clear");
            cout << "Saliendo..." << endl;
            login();
            system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
            system("cls || clear");
            break;
        default:
            cout << "Opcion Invalida. Ingrese una opcion valida del 1 - 7" << endl;
            break;
        }

    } while (options != 9);
}

void showClt(int pos) // muestra los datos del cliente en X posición
{
    cout << "====================================" << endl;
    cout << "ID: " << clt[pos].client_id << endl;
    cout << "Nombre: " << clt[pos].client_name << endl;
    cout << "Apellido: " << clt[pos].client_lastname << endl;
    cout << "E-mail: " << clt[pos].client_mail << endl;
    cout << "Telefono: " << clt[pos].client_telf << endl;
    cout << "====================================" << endl;
}

void showCltRegister()
{
    system("cls || clear");
    if (lastRegClt == 0)
    {
        cout << "No hay registros" << endl;
        return;
    }
    cout << "Registro de Clientes: " << endl;
    cout << "====================================" << endl;

    for (int i = 0; i < lastRegClt; i++)
    {
        cout << "Cliente #" << i + 1 << endl;
        showClt(i);
    }
    cout << "====================================" << endl;
    cout << "Ultimo registro..." << endl;
}

cliente getClt(int pos)
{
    return clt[pos];
}

int searchCltname(const char* enteredClt_name)
{
    int position = 0;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (strcmp(enteredClt_name, clt[i].client_name) == 0)
        {
            cout << "=========================" << endl;
            showClt(i);
            position++;
        } 
    }

    if (position == 0)
    {
        cout << "No se encontraron resultados" << endl;
    }
    return position;
}

int searchCltlstname(const char* enteredClt_lstName)
{
    int position = -1;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (strcmp(enteredClt_lstName, clt[i].client_lastname) == 0)
        {
            cout << "=========================" << endl;
            showClt(i);
            position++;
        } 
    }

    if (position == 0) 
    {
        cout << "No se encontraron resultados" << endl;
    }
    return position;
}

int searchCltId(const char* enteredClt_id)
{
    int position = -1;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (strcmp(enteredClt_id, reinterpret_cast<const char *>(clt[i].client_id)) == 0)
        {
            cout << "=========================" << endl;
            showClt(i);
            position++;
        } 
    }

    if (position == 0) 
    {
        cout << "No se encontraron resultados" << endl;
    }
    return position;
}

int searchCltmail(const char* enteredClt_mail) // busq por mail
{
    int position = -1;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (strcmp(enteredClt_mail, clt[i].client_mail) == 0)
        {
            cout << "=========================" << endl;
            showClt(i);
            position++;
        } 
    }

    if (position == 0) 
    {
        cout << "No se encontraron resultados" << endl;
    }
    return position;
}

int searchCltelf(char enteredClt_telf) // busqueda por numero telef
{
    int position = -1;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (strcmp(reinterpret_cast<const char *>(enteredClt_telf), clt[i].client_telf) == 0)
        {
            cout << "=========================" << endl;
            showClt(i);
            position++;
        } 
    }

    if (position == 0) 
    {
        cout << "No se encontraron resultados" << endl;
    }
    return position;
}

void uptdClt(cliente currentClt, int pos)
{
    clt[pos] = currentClt;
}

void delClt(int pos)
{
    if (pos == lastRegClt)
    {
        cout << "No hay registros " << endl;
        return;
    }
    for (int i = pos; i < lastRegClt - 1; i++)
    {
        clt[i] = clt[i + 1];
    }
    lastRegClt--;
    initClt(lastRegClt);
}
