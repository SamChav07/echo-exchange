#include <iostream>
#include <cstring>
#include <string>

#include <unistd.h>
#include "gotox.cpp"
using namespace std;

// Definici�n de estructuras
const int MAX = 100;

struct accounts
{
    char adminU[50]; // "00017"
    char admP[50];   // "admPass007"
};

struct empleado
{
    char nombre[20];
    char empU[50]; // "00016"
    char empP[50]; // "enployee123"
    string empmail;
    string emptel;
} emp;

struct cliente
{
    char client_name[20];
    char client_lastname[20];
    int client_id;
    char client_mail[50];
    char client_telf[15];
} clt[MAX];

struct cmpr_fecha
{
    int day;
    int month;
    int year;
} fCmp[MAX];

struct reg_compra
{
    cliente clt;
    int cmpr_id;
    cmpr_fecha fCmp;
    float cmpr_qty; // monto de la compra
    int cmpr_pts;
} cmp[MAX];

struct historial
{
    reg_compra r_cmpr;
    int cmpr_ptsTot;
} hst;

struct gift
{
    int gft_id;
    int gft_cant;
    char gft_name[50];
    int gft_pts;
} gft[MAX];
// fin de struct

// LOG
void SuperAdmin();
void logAdm();
void logClt();

// menus
void MDclient(); //--listo
void MDcmp();
void MDgift();     // vacio
void searchMclt(); // menu de busqueda de cliente   //--listo

void MAdm();
void MClt();

// CRUD clt
// create
void addClt(cliente currentClt); //--listo
void initClt(int cltPos);        //--listo
// read
void showClt(int pos); //--listo
void showCltRegister();
cliente getClt(int pos);
int searchCltname(char client_name[]);      //--listo
int searchCltlstname(char *client_lstName); //--listo
int searchCltId(int enteredClt_id);         // listo
int searchCltmail(char client_mail[]);      //--listo
int searchCltelf(char client_telf[]);       //--listo
// uptade
void uptdClt(cliente cliente, int i); // --listo
// delete
void delClt(int pos); // --listo

// compra
void addCmp(reg_compra currentCmp);
void showCmpRegister(int i);
void showCmp(int pos);
reg_compra getCmp(int pos);
int searCmpFID(int entered_id);

// create gft
void addGft(gift currentGft);
void initGft(int gftPos);

// funciones
void MDrewards(); // -------------pendiente
void redeem();    // -------------pendiente
void checkPts();  // -------------pendiente

// variables globales
char user[50], pass[50];
int intentos = 4;

int lastRegClt = 0;
int lasTregGft = 0;
int lastREgCmp = 0;
int proxIDclt = 123;

int idCmp = 321;

// codigos colores ANSI
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"

int main()
{
    SuperAdmin();
    return 0;
}

void SuperAdmin()
{
    int spOpcion;
    int intentos = 3;

    cout << GREEN << "EEEE  CCCC  HH  HH  OOOOOO     EEEE  XX    XX  CCCC  HH  HH  AAAAAA  NN     NN  GGGGGG   EEEE" << RESET << endl;
    cout << GREEN << "EE    CC    HH  HH  OO  OO     EE     XX  XX   CC    HH  HH  AA  AA  NN NN  NN  GG       EE" << RESET << endl;
    cout << GREEN << "EEEE  CC    HHHHHH  OO  OO === EEEE    XXXX    CC    HHHHHH  AAAAAA  NN  NN NN  GG  GGG  EEEE" << RESET << endl;
    cout << GREEN << "EE    CC    HH  HH  OO  OO     EE     XX  XX   CC    HH  HH  AA  AA  NN   NNNN  GG  GG   EE" << RESET << endl;
    cout << GREEN << "EEEE  CCCC  HH  HH  OOOOOO     EEEE  XX    XX  CCCC  HH  HH  AA  AA  NN    NNN  GGGGGG   EEEE" << RESET << endl;
    gotoxy(13, 6);
    cout << "||==================================================||" << endl;
    cout << "Bienvenido Super-Admin" << endl;
    cout << "Que cuenta desea fijar en el dispositivo ?" << endl;
    cout << "1. Administrador." << endl;
    cout << "2. Cliente." << endl;
    cout << "3. Cerrar." << endl;
    cout << "||==================================================||" << endl;
    cout << "\n --> ";
    cin >> spOpcion;
    switch (spOpcion)
    {
        case 1:
            logAdm();
            break;
        case 2:
            logClt();
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
                MDrewards();
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

void logClt()
{
    do
    {
        empleado empleado1;
        strcpy(empleado1.empU, "usuario1");
        strcpy(empleado1.empP, "password123");

        int intentos = 4;

        cout << "---Cliente---" << endl;
        cout << "-------------" << endl;

        cout << "\nUsuario: ";
        cin >> user;
        cout << "\nContrasena: ";
        cin >> pass;

        // Verificaci�n de credenciales del cliente
        if (strcmp(user, empleado1.empU) == 0 && strcmp(pass, empleado1.empP) == 0)
        {
            cout << "\n***Acceso concedido***\n";
            MClt();
        }
        else
        {
            cout << "\n*** Intento fallido. Usuario o contrase�a incorrecta ***" << endl;
            cout << "Intentos restantes: " << intentos - 1 << endl;
            intentos--;
        }
    } while (intentos > 0);
    cout << "\n*** Intento fallido. Usuario o contrase�a incorrecta ***" << endl;
    cout << "***Acceso bloqueado, saliendo del sistema...***";
}

void MClt()
{
    int op2;
    do
    {
        cout << "\nBienvenido Empleado" << endl;
        cout << "\n***--Opciones--***" << endl;
        cout << "\n1.. Canjear puntos." << endl;
        cout << "\n2. Consultar puntos." << endl;
        cout << "\n3. Historial de compra." << endl;
        cout << "\n4. Cerrar Sesion." << endl;
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
            case 3:
                ///debe enseñar las compras segun su ID
                break;
            case 4:
                system("cls");
                logClt();
                break;
            default:
                cout << "Ingrese opciones validas. Sean de 1-4.." << endl;
                break;
        }
    } while (op2 != 4);
}

void MDclient()
{
    cliente currentClt;
    int pos, resp;
    int enteredClt_id;

    int optMdclt;
    cout << "Clientes" << endl;
    cout << "Cantidad de registros de clientes: " << lastRegClt << endl;
    cout << "***--Opciones--***" << endl;
    cout << "1. Agregar cliente." << endl;
    cout << "2. Buscar cliente." << endl;
    cout << "3. Modificar cliente." << endl;
    cout << "4. Eliminar cliente." << endl;
    cout << "5. Atras..." << endl;
    cout << "\n --> ";
    cin >> optMdclt;
    system("pause");

    switch (optMdclt)
    {
        case 1:
            system("cls || clear");
            cout << "** Ingrese los datos a añadir **" << endl;
            system("cls || clear");
            currentClt.client_id = proxIDclt;
            cout << "ID: " << proxIDclt << endl;
            cout << "Nombre del cliente: " << endl;
            scanf(" %[^\n]", currentClt.client_name);
            cout << "Apellido del cliente: " << endl;
            scanf(" %[^\n]", currentClt.client_lastname);
            cout << "E-mail del cliente: " << endl;
            scanf(" %[^\n]", currentClt.client_mail);
            cout << "Telefono del cliente: " << endl;
            scanf(" %[^\n]", currentClt.client_telf);

            addClt(currentClt);
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            MDclient();
            break;
        case 2:
            searchMclt();
            break;
        case 3:
            system("cls || clear");
            cout << "** Escribe el ID del cliente a modificar **" << endl;
            cin >> enteredClt_id;
            pos = searchCltId(enteredClt_id);
            if (pos != -1)
            {
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
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            MDclient();
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
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            }
            else
            {
                cout << "Registro inexistente" << endl;
            }
            break;
        case 5:
            MAdm();
            break;

        default:
            cout << "Ingrese una opcion valida. Del 1 - 5..." << endl;
            break;
    }
}

void MDcmp()
{
    reg_compra currentCmp;
    int enteredClt_id;
    int cmpOPt;
    do
    {
        cout << "Modulo Compra" << endl;
        cout << "**OPCIONES**" << endl;
        cout << "1. Registro de compra." << endl;
        cout << "2. Historial de compras." << endl;
        cout << "3. Atras..." << endl;
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
                cout << "ID de compra: ";
                cin >> currentCmp.cmpr_id;
                cout << "Fecha de compra: ";
                cin >> currentCmp.fCmp.day;
                cin >> currentCmp.fCmp.month;
                cin >> currentCmp.fCmp.year;
                cout << "Monto de compra: $ ";
                cin >> currentCmp.cmpr_qty;
                currentCmp.cmpr_pts = currentCmp.cmpr_qty / 5;
                cout << "Puntos por compra: " << currentCmp.cmpr_pts << " pts" << endl;
                cout << "||=========================||" << endl;
                cout << "¿Desea volver a registrar otra compra o salir al menu? (v/s): " << endl;

                addCmp(currentCmp);
                system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
                break;
            case 2:
                cout << "ID de cliente: ";
                cin.ignore();
                cout << "" << endl;
                cin >> enteredClt_id;
                searCmpFID(enteredClt_id);
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                showCmpRegister(0);
                system("cls || clear");
                break;
            case 3:
                MAdm();
                break;
        }
    } while (cmpOPt != 3);
}

void MDgift()
{
    gift currentGft;
    int pos, resp;
}

void addClt(cliente currentClt)
{
    if (lastRegClt < MAX)
    {
        clt[lastRegClt] = currentClt;
        lastRegClt++;
        proxIDclt++;
    }
    else
    {
        cout << "Clientes esta en Maxima capacidad..." << endl;
    }
}

void addGft(gift currentGft)
{
    if (lasTregGft < MAX)
    {
        gft[lasTregGft] = currentGft;
        lasTregGft++;
    }
    else
    {
        cout << "Recompensas esta en Maxima capacidad..." << endl;
    }
}

void initClt(int pos) // inicializa los datos del cliente
{
    clt[pos].client_id = 0;

    strncpy(clt[pos].client_name, "", sizeof(clt[pos].client_name));
    clt[pos].client_name[sizeof(clt[pos].client_name) - 1] = '\0';

    strncpy(clt[pos].client_lastname, "", sizeof(clt[pos].client_lastname));
    clt[pos].client_lastname[sizeof(clt[pos].client_lastname) - 1] = '\0';

    strncpy(clt[pos].client_mail, "", sizeof(clt[pos].client_mail));
    clt[pos].client_mail[sizeof(clt[pos].client_mail) - 1] = '\0';

    strncpy(clt[pos].client_telf, "", sizeof(clt[pos].client_telf));
    clt[pos].client_telf[sizeof(clt[pos].client_telf) - 1] = '\0';
}

/*void initGft(int gftPos)
{
    gft[pos].gft_id = 0;

    strncpy(gft[pos].client_name, "", sizeof(clt[pos].client_name));
    clt[pos].client_name[sizeof(clt[pos].client_name) - 1] = '\0';
}*/

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
        cout << "7. Atras..." << endl;
        cout << "\n --> ";

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
                searchCltId(enteredClt_id);
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
                MDclient();
                system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
                system("cls || clear");
                break;
            default:
                cout << "Opcion Invalida. Ingrese una opcion valida del 1 - 7" << endl;
                break;
        }

    } while (options != 7);
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

int searchCltname(char *enteredClt_name) //funcion de busqueda por caracter prueba
{
    int position = 0;
    for (int i = 0; i <= lastRegClt; i++)
    {
        if (strchr(clt[i].client_name, *enteredClt_name) != nullptr )
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

int searchCltlstname(char *enteredClt_lstName)
{
    int position = 0; // Inicializar en 0
    for (int i = 0; i <= lastRegClt; i++)
    {
        if (strchr(clt[i].client_lastname, *enteredClt_lstName) != nullptr )
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

int searchCltId(int enteredClt_id)
{
    int position = 0;
    for (int i = 0; i <= lastRegClt; i++)
    {
        if (enteredClt_id == (clt[i].client_id))
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

int searchCltmail(char *enteredClt_mail) // busq por mail
{
    int position = 0;
    for (int i = 0; i <= lastRegClt; i++)
    {
        if (strchr(clt[i].client_mail, *enteredClt_mail) != nullptr )
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

int searchCltelf(char enteredClt_telf[]) // busqueda por numero telef
{
    int position = 0;
    for (int i = 0; i <= lastRegClt; i++)
    {
        if (enteredClt_telf == (clt[i].client_telf))
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

void showCmpRegister(int i) // pendiente
{
    system("cls || clear");
    if (lastREgCmp == 0)
    {
        cout << "No hay registros" << endl;
        return;
    }
    cout << "Registro de de compras: " << endl;
    cout << "====================================" << endl;

    for (int i = 0; i < lastREgCmp; i++)
    {
        cout << "Compra #" << i + 1 << endl;
        showCmp(i);
    }
    cout << "====================================" << endl;
    cout << "Ultimo registro..." << endl;
}

void showCmp(int pos) // muestra los datos del cliente en X posición
{
    cout << "====================================" << endl;
    cout << "ID de compra: " << cmp[pos].cmpr_id << endl;
    cout << "Fecha de compra: " << cmp[pos].fCmp.day << " - " << cmp[pos].fCmp.month << " - " << cmp[pos].fCmp.year << endl;
    cout << "Monto de compra: $ " << cmp[pos].cmpr_qty << endl;
    cout << "Puntos por compra: " << cmp[pos].cmpr_pts << " pts" << endl;
    cout << "====================================" << endl;
}

reg_compra getCmp(int pos)
{
    return cmp[pos];
}

int searCmpFID(int entered_id)
{
    int position = -1;
    for (int i = 0; i < lastRegClt; i++)
    {
        if (entered_id == (clt[i].client_id))
        {
            cout << "=========================" << endl;
            showCmpRegister(i);
            position++;
        }
    }
    if (position == -1)
    {
        cout << "No se encontraron resultados" << endl;
    }
    return position;
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
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tSeleccion de recompensas" << endl;
    cout << "______________________________" << endl;
    cout << "------------------------------" << endl;
    cout << "Puntos actuales:   495" << endl;
    cout << "=======================" << endl;
    cout << "ID:    123" << endl;
    cout << "Cantidad:  2" << endl;
    cout << "Descuento del 20%" << endl;
    cout << "Puntos necesarios: 295" << endl;
    cout << "+++++++++++++++++++++++" << endl;
    cout << "ID:    234" << endl;
    cout << "Cantidad:  3" << endl;
    cout << "Producto Gratis" << endl;
    cout << "Puntos necesarios: 500" << endl;
    cout << "+++++++++++++++++++++++" << endl;
    cout << "ID:    345" << endl;
    cout << "Cantidad:  1" << endl;
    cout << "Bonus" << endl;
    cout << "Puntos necesarios: 700" << endl;
    cout << "=======================" << endl;
    cout << "Elija su recompensa: \n(escriba el ID correspondiente)" << endl;
    cout << "ID:    123" << endl;
    cout << "***Transaccion exitosa***" << endl;
    cout << "||=========================||" << endl;
    cout << "¿Desea volver a mostrar de nuevo su historial o salir al menu? (v/s): " << endl;
}
void checkPts() // -------------pendiente
{
    cout << "Visualizar puntos" << endl;
}
