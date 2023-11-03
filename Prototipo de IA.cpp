#include <iostream>
#include <string>
using namespace std;

// Definici�n de estructuras
struct accounts {
    struct client;
    int admin_id = 00017;
    string adm_pass = "admPass007";
} acsts;

struct cmpr_fecha {
    int day;
    int month;
    int year;
};

struct reg_compra {
    int cmpr_id;
    cmpr_fecha cmpr_f;
    float cmpr_qty; // monto de la compra
    int cmpr_pts;
};

struct client {
    char client_name[20];
    string client_pass = "clientPass123"; // Contrase�a predeterminada para los clientes
    int client_id = 00016;
    string client_mail;
    string client_telf;
} clt;

struct historial {
    client clt;
    reg_compra r_cmpr;
    int cmpr_ptsTot;
};

struct gift {
    int gft_cant;
    string gft_name;
    int gft_pts;
};

// Prototipos de funciones a utilizar
void login();
bool log_clt();
bool log_adm();
void admin();
void regPurchase();
void clientS();
void redeem();
void rewards();
void checkPts();
void record();
bool compareStrings(const string& str1, const string& str2);

// CRUD
void createClt();
void readClt();
void uptdClt();
void delClt();

// LOG
int user;
string pass;

int main()
{
    login();
    return 0;
}

// Funci�n del Menu principal
void login() {
    int intentos = 3;
    bool inicioSesionExitoso = false;

    cout << "Hola" << endl;
    cout << "Bienvenido al sistema EchoExchange" << endl;
    cout << "Ingrese su tipo de usuario:\n(1) Para Administrador\n(2) Para Cliente\n";

    while (intentos > 0 && !inicioSesionExitoso) {
        int opt;
        cin >> opt;

        switch (opt) {
            case 1:
                if (log_adm()) {
                    inicioSesionExitoso = true;
                    admin();
                }
                break;
            case 2:
                if (log_clt()) {
                    inicioSesionExitoso = true;
                    clientS();
                }
                break;
            default:
                cout << "Ingrese un numero valido. 1-2..." << endl;
                break;
        }

        if (!inicioSesionExitoso) {
            intentos--; // Reduzca los intentos solo si no se ha iniciado sesi�n correctamente
            if (intentos > 0) {
                cout << "*** Intento fallido. Usuario o contrasena incorrecta ***" << endl;
                cout << "Intentos restantes: " << intentos << endl;
            } else {
                cout << "*** Acceso Bloqueado. Te quedaste sin intentos ***" << endl;
            }
        }
    }
}

// Ingreso del cliente
bool log_clt() {
    int intentos = 3;

    cout << "---Cliente---" << endl;
    cout << "-------------" << endl;

    cout << "\nUsuario: ";
    int inputUser;
    cin >> inputUser;
    cout << "\nContrasena: ";
    string inputPass;
    cin >> inputPass;

    // Verificaci�n de credenciales del cliente
    if (inputUser == clt.client_id && compareStrings(inputPass, clt.client_pass)) {
        cout << "\n*** Inicio de sesion exitoso ***" << endl;
        return true;
    }

    cout << "*** Intento fallido. Usuario o contrasena incorrecta ***" << endl;
    cout << "Intentos restantes: " << intentos - 1 << endl;
    return false;
}

// Ingreso del Administrador
bool log_adm() {
    int intentos = 3;

    cout << "---Administrador---" << endl;
    cout << "-------------" << endl;

    cout << "\nUsuario: ";
    int inputUser;
    cin >> inputUser;
    cout << "\nContrasena: ";
    string inputPass;
    cin >> inputPass;

    // Verificaci�n de credenciales del administrador
    if (inputUser == acsts.admin_id && compareStrings(inputPass, acsts.adm_pass)) {
        cout << "\n*** Inicio de sesion exitoso ***" << endl;
        return true;
    }

    cout << "*** Intento fallido. Usuario o contrasena incorrecta ***" << endl;
    cout << "Intentos restantes: " << intentos - 1 << endl;
    return false;
}

// Funci�n para comparar cadenas de caracteres de manera segura
bool compareStrings(const string& str1, const string& str2) {
    return str1 == str2;
}

// Men� del administrador
void admin()
{
    int opt1;

    cout << "Bienvenido Administrador" << endl;

    cout << "***--Opciones--***" << endl;
    cout << "1. Registrar compras." << endl;
    cout << "2. Clientes." << endl;
    cout << "3. Recompensas." << endl;
    cout << "4. Salir" << endl;
    cin >> opt1;
    system("pause");

    switch (opt1)
    {
    case 1:
        regPurchase();
        break;
    case 2:
        client();
        break;
    case 3:
        rewards();
        break;
    case 4:
        login();
        break;

    default:
        cout << "Ingrese opciones validas. Sean de 1-4..." << endl;
        break;
    }
}

// Funciones utilizables del men� de administrador
void regPurchase()
{
    // Implementa la funcionalidad de registro de compras
}

void client()
{
    // Implementa la funcionalidad de gesti�n de clientes
}

void rewards()
{
    // Implementa la funcionalidad de gesti�n de recompensas
}

// Men� del cliente
void clientS()
{
    int opt2;

    cout << "Bienvenido Usuario1" << endl;
    cout << "***--Opciones--***" << endl;
    cout << "1. Canjear puntos." << endl;
    cout << "2. Consultar puntos." << endl;
    cout << "3. Historial de compra." << endl;
    cout << "4. Salir." << endl;
    cin >> opt2;
    system("pause");

    switch (opt2)
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
        login();
        break;

    default:
        cout << "Ingrese opciones validas. Sean de 1-4.." << endl;
        break;
    }
}

// Funciones utilizables del men� de cliente
void redeem()
{
    // Implementa la funcionalidad de canjear puntos
}

void checkPts()
{
    // Implementa la funcionalidad de consultar puntos
}

void record()
{
    // Implementa la funcionalidad de historial de compras
}
