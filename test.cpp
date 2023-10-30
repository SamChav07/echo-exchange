#include <iostream>
using namespace std;

void mainmenu();
void searchmenu();

void login()
{
    string password;
    string username;
    int login = 0;
    do
    {

        cout << "Bienvenido a Echo-Exchange " << endl;
        cout << "Escriba su usuario: " << endl;
        cin >> username;
        cout << "Escriba su contraseña: " << endl;
        cin >> password;

        if (username == "Admin" && password == "admPass007")
        {

            cout << "Acceso concedidio" << endl;
            login = 1;
            mainmenu();
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
        } 
        else if (username == "User1" && password == "12345")
        {
            cout << "Acceso concedidio" << endl;
            login = 1;
            searchmenu();
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
        }
        else
        {
            cout << "Acceso denegado..." << endl;
            cout << "*** Presione enter para volver a introdocir las credenciales ***" << endl;
            system("pause || read -p 'Presiona Enter para continuar...' -n 1 -s");
            system("cls || clear");
        }

    } while (login != 1);
}