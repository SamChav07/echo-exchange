#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// Definici�n de estructuras
const int MAX = 100;

struct accounts
{
    char adminU[50]; // "admin1"
    char admP[50];   // "password123"
};

struct empleado
{
    char nombre[20];
    char empU[50]; // "usuario1"
    char empP[50]; // "password123"
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
} fCmp;

struct reg_compra
{
    cliente clt;
    int cmpr_id;
    cmpr_fecha fCmp;
    float cmpr_qty; // monto de la compra
    int cmpr_pts;
} cmp;

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
void MDclient();   //--listo
void MDgift(); //vacio 
void searchMclt(); // menu de busqueda de cliente   //--listo

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
int searchCltId(char enteredClt_id[]);             // listo
int searchCltmail(char client_mail[]);      //--listo
int searchCltelf(char client_telf[]);       //--listo
// uptade
void uptdClt(cliente cliente, int i); // --listo
// delete
void delClt(int pos); // --listo

// create gft
void addGft(gift currentGft);
void initGft(int gftPos);

void addPurchase();

// funciones
void regPurchase(); // -------------pendiente
void MDrewards();   // -------------pendiente
void redeem();      // -------------pendiente
void checkPts();    // -------------pendiente
void record();      // ---------———----pendiente

// variables globales
char user[50], pass[50];
int intentos = 4;

int lastRegClt = 0;
int lasTregGft = 0;
int lastREgCmp = 0;
int proxIDclt = 123;

int idCmp = 321;

// codigos colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main()
{
    SuperAdmin();
    return 0;
}

void SuperAdmin()
{
    int spOpcion;
    int intentos = 3;

    cout << GREEN << "EEEE CCCC HH  HH OOOOOO     EEEE XX    XX CCCC HH  HH AAAAAA NN     NN GGGGGG  EEEE" << RESET << endl;
    cout << GREEN << "EE   CC   HH  HH OO  OO     EE    XX  XX  CC   HH  HH AA  AA NN NN  NN GG      EE" << RESET << endl;
    cout << GREEN << "EEEE CC   HHHHHH OO  OO === EEEE   XXXX   CC   HHHHHH AAAAAA NN  NN NN GG  GGG EEEE" << RESET << endl;
    cout << GREEN << "EE   CC   HH  HH OO  OO     EE    XX  XX  CC   HH  HH AA  AA NN   NNNN GG  GG  EE" << RESET << endl;
    cout << GREEN << "EEEE CCCC HH  HH OOOOOO     EEEE XX    XX CCCC HH  HH AA  AA NN    NNN GGGGGG  EEEE" << RESET << endl;
    cout << "Bienvenido Super-Admin" << endl;
    cout << "Que cuenta desea fijar en el dispositivo ?" << endl;
    cout << "1. Administrador." << endl;
    cout << "2. Cliente." << endl;
    cout << "3. Cerrar.";
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
        strcpy(administrador1.adminU, "admin1");
        strcpy(administrador1.admP, "password123");

        cout << "\n---Administrador---" << endl;
        cout << "-------------" << endl;
        cout << "Usuario: ";
        cin >> user;
        cout << "\nContrasena: ";
        cin >> pass;

        // Verificaci�n de credenciales del administrador
        if (strcmp(user, administrador1.adminU) == 0 && strcmp(pass, administrador1.admP) == 0)
        {
            int op1;
            cout << "\n***Acceso concedido***\n";
            cout << "Bienvenido Administrador" << endl;

            cout << "***--Opciones--***" << endl;
            cout << "1. Registrar compras." << endl;
            cout << "2. Gestionar clientes." << endl;
            cout << "3. Gestionar recompensas." << endl;
            cout << "4. Salir" << endl;
            cin >> op1;
            system("pause");

            switch (op1)
            {
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
                    logAdm();
                    break;
                default:
                    cout << "Ingrese opciones validas. Sean de 1-4..." << endl;
                    break;
            }
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

void logClt()
{
    do
    {
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
            cout << "\n***Acceso concedido***\n";

            cout << "\nBienvenido Empleado" << endl;
            cout << "\n***--Opciones--***" << endl;
            cout << "\n1.. Canjear puntos." << endl;
            cout << "\n2. Consultar puntos." << endl;
            cout << "\n3. Historial de compra." << endl;
            cout << "\n4. Salir." << endl;
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
                    record();
                    break;
                case 4:
                    system("cls");
                    logClt();
                    break;
                default:
                    cout << "Ingrese opciones v�lidas. Sean de 1-4.." << endl;
                    break;
            }

        } else
        {
            cout << "\n*** Intento fallido. Usuario o contrase�a incorrecta ***" << endl;
            cout << "Intentos restantes: " << intentos - 1 << endl;
            intentos--;
        }
    } while (intentos > 0);
    cout << "\n*** Intento fallido. Usuario o contrase�a incorrecta ***" << endl;
    cout << "***Acceso bloqueado, saliendo del sistema...***";
}

void MDclient()
{
    cliente currentClt;
    int pos, resp;
    char enteredClt_id;

    int optMdclt;
    cout << "Clientes" << endl;
    cout << "Cantidad de registros de clientes: " << lastRegClt << endl;
    cout << "***--Opciones--***" << endl;
    cout << "1. Agregar cliente." << endl;
    cout << "2. Buscar cliente." << endl;
    cout << "3. Modificar cliente." << endl;
    cout << "4. Eliminar cliente." << endl;
    cout << "5. Atras..." << endl;
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
        cout << "Apellido del cliente: " << endl;
        cout << "E-mail del cliente: " << endl;
        cout << "Telefono del cliente: " << endl;
        scanf(" %[^\n]", currentClt.client_name);
        scanf(" %[^\n]", currentClt.client_lastname);
        scanf(" %[^\n]", currentClt.client_mail);
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
        cout << "** Escribe el id del cliente a modificar **" << endl;
        cin >> enteredClt_id;
        pos = searchCltId(&enteredClt_id);
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
        pos = searchCltId(&enteredClt_id);
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
        logAdm();
        break;

    default:
        cout << "Ingrese una opcion valida. Del 1 - 5..." << endl;
        break;
    }
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
                searchCltId(reinterpret_cast<char *>(enteredClt_id));
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
                logAdm();
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

int searchCltname(char *enteredClt_name)
{
    int position = -1;
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

int searchCltlstname(char *enteredClt_lstName)
{
    int position = 0;
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

int searchCltId(char *enteredClt_id)
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

int searchCltmail(char *enteredClt_mail) // busq por mail
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

int searchCltelf(char enteredClt_telf[]) // busqueda por numero telef
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


void regPurchase() // -------------pendiente
{
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tRegistro de Compras" << endl;
    cout << "______________________________" << endl;
    cout << "------------------------------" << endl;
    cout << "ID:    00071012" << endl;
    cout << "Fecha de compra:   28-09-23" << endl;
    cout << "Monto de compra:   $ 200.00" << endl;
    cout << "Puntos por compra: 20" << endl;
    cout << "||=========================||" << endl;
    cout << "¿Desea volver a registrar otra compra o salir al menu? (v/s): " << endl;
}
void MDrewards()   // -------------pendiente
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
void redeem()      // -------------pendiente
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
void checkPts()    // -------------pendiente
{
    cout << "Visualizar puntos" << endl;
}
void record()
{
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tHistorial de compra" << endl;
    cout << "______________________________" << endl;
    cout << "------------------------------" << endl;
    cout << "Cliente:   Ivan Arguello" << endl;
    cout << "ID:    00071012" << endl;
    cout << "E-mail:    iArg@gmail.com" << endl;
    cout << "Telefono:  8899-1033" << endl;
    cout << "=============================" << endl;
    cout << "ID de compra:    00001" << endl;
    cout << "Fecha de compra:   28-09-23" << endl;
    cout << "Monto de compra:   $ 200.00" << endl;
    cout << "Puntos por compra: 20" << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "ID de compra:    00002" << endl;
    cout << "Fecha de compra:   30-09-23" << endl;
    cout << "Monto de compra:   $ 2,000.00" << endl;
    cout << "Puntos por compra: 200" << endl;
    cout << "+++++++++++++++++++++++++++++" << endl;
    cout << "ID de compra:    00003" << endl;
    cout << "Fecha de compra:   01-10-23" << endl;
    cout << "Monto de compra:   $ 2750.00" << endl;
    cout << "Puntos por compra: 275" << endl;
    cout << "=============================" << endl;
    cout << "Puntos totales acumulados: 495" << endl;
    cout << "Puntos actuales: 200" << endl;
    cout << "||=========================||" << endl;
    cout << "¿Desea mostrar de nuevo su historial o salir al menu? (v/s): " << endl;
}