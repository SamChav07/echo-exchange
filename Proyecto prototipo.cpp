#include <iostream>
#include <string>
#include <cstring> 
using namespace std;

// Definición de estructuras
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
};

struct cliente {
    char client_name[20];
    int client_id;
    char client_mail[50];
    char client_telf[15];
};

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

struct historial {
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
void admin();
void regPurchase();
void clientS();
void redeem();
void rewards();
void checkPts();
void record();

// CRUD
void createClt();
void readClt();
void uptdClt();
void delClt();

// Login
int validacion;
char user[50];
char pass[50];

int main()
{
    login();
    return 0;
}

// Función del Menu principal
void login() {
    int intentos = 3;

    cout << "Bienvenido al sistema EchoExchange" << endl;
    cout << "\nSeleccione una opcion para entrar al sistema:\n";
    cout << "1. Administrador\n";
    cout << "2. Empleado\n";
    cout << "3. Gestionar credenciales de acceso.\n";
    cout << "4. Salir del sistema.\n";

    int opcion;
    cin >> opcion;

    switch (opcion) {
        case 1: // Acceso al menú del administrador
            
			do {
                accounts administrador1;
                strcpy(administrador1.adminU, "admin1");
                strcpy(administrador1.admP, "password123");

                cout << "\n---Administrador---" << endl;
                cout << "-------------" << endl;
                cout << "Usuario: ";
                cin >> user;
                cout << "\nContraseña: ";
                cin >> pass;

                // Verificación de credenciales del administrador
                if (strcmp(user, administrador1.adminU) == 0 && strcmp(pass, administrador1.admP) == 0) {
                    int op1;
                    cout<<"\n***Acceso concedido***\n";
                    cout<< "\nBienvenido Administrador" << endl;
                    cout << "\n***--Opciones--***" << endl;
                    cout << "\n1. Registrar compras." << endl;
                    cout << "\n2. Clientes." << endl;
                    cout << "\n3. Recompensas." << endl;
                    cout << "\n4. Salir" << endl;
                    cin >> op1;
                    system("pause");

                    switch (op1) {
                        case 1:
                            regPurchase();
                            break;
                        case 2:
                            clientS();
                            break;
                        case 3:
                            rewards();
                            break;
                        case 4:
                        	system("cls");
                            login();
                            break;
                        default:
                            cout << "Ingrese opciones válidas. Sean de 1-4..." << endl;
                            break;
                    }
                } else {
					cout << "*** Intento fallido. Usuario o contraseña incorrecta ***" << endl;
                    cout << "Intentos restantes: \n" << intentos-1 << endl;
                    
                    intentos--;
                }  
            	}while (intentos > 0);
				cout << "*** Intento fallido. Usuario o contraseña incorrecta ***" << endl;
            	cout<<"***Acceso bloqueado, saliendo del sistema...***";
            break;
        case 2: // Acceso al menú de empleado
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
    			
    			 // Verificación de credenciales del cliente
    			if (strcmp(user, empleado1.empU) == 0 && strcmp(pass, empleado1.empP) == 0)
   				{
        		int op2;
        			cout<<"\n***Acceso concedido***\n";
        			
    				cout << "\nBienvenido Empleado" << endl;
    				cout << "\n***--Opciones--***" << endl;
    				cout << "\n1. Canjear puntos." << endl;
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
    						login();
        					break;
    					default:
        					cout << "Ingrese opciones válidas. Sean de 1-4.." << endl;
        					break;
    				}
        		
    			} else {
                    cout << "\n*** Intento fallido. Usuario o contraseña incorrecta ***" << endl;
                    cout << "Intentos restantes: " << intentos-1 << endl;
                    intentos--;
    			}
    		}while (intentos > 0);
				cout << "\n*** Intento fallido. Usuario o contraseña incorrecta ***" << endl;
            	cout<<"***Acceso bloqueado, saliendo del sistema...***";
            break;
        case 3: // Menú de gestión de credenciales
        	
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
            cout << "---Gracias por utilizar el sistema EchoExchange, que tenga un buen día---" << endl;
            break;
        default:
            cout << "Ingrese una opción válida." << endl;
            break;
    }
}

// Funciones utilizables del menú de administrador
void regPurchase()
{
    // Implementa la funcionalidad de registro de compras
}

void clientS()
{
    // Implementa la funcionalidad de gestión de clientes
}

void rewards()
{
    // Implementa la funcionalidad de gestión de recompensas
}

// Funciones utilizables del menú del empleado
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
