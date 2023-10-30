#include <iostream>
using namespace std;

void reg_compra();
void historial();
void chss_gft();
void client();
void regalo();
void showUsers();



int main() {
    int opt;

    cout << "1. reg_compra" << endl;
    cout << "2. historial" << endl;
    cout << "3. chss_gft" << endl;
    cout << "=================" << endl;
    cout << "4. client" << endl;
    cout << "5. regalo" << endl;
    cout << "6. showUser" << endl;
    cin >> opt;

    switch (opt)
    {
    case 1:
        reg_compra();
        break;
    case 2:
        historial();
        break;
    case 3:
        chss_gft();
        break;
    case 4:
        client();
        break;
    case 5:
        regalo();
        break;
    case 6:
        showUsers();
        break;
    
    default:
        cout << "Ingrese opt  valida" << endl;
        break;
    }
    return 0;
}

void reg_compra() {
    char opcion;
    
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

void historial() {
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

void chss_gft() {
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

void client() {
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tCRUD clientes" << endl;
    cout << "______________________________" << endl;
    cout << "------------------------------" << endl;
    cout << " Agregar - Editar - Eliminar " << endl;
    cout << "¿Desea volver Agregar, Editar, Eliminar clientes? (a/ e/ d): " << endl;
    cout << "a" << endl;
    cout << "=============================" << endl;
    cout << "Nombre del cliente:    Ivan Arguello" << endl;
    cout << "ID:    00071012" << endl;
    cout << "PASS:  iA071012" << endl;
    cout << "E-mail:    iArg@gmail.com" << endl;
    cout << "Telefono:  8899-1033" << endl;
    cout << "||=========================||" << endl;
    cout << "¿Desea volver al CRUD o salir al menu? (v/s): " << endl;
}

void regalo() {
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tCRUD regalos" << endl;
    cout << "______________________________" << endl;
    cout << "------------------------------" << endl;
    cout << " Agregar - Editar - Eliminar " << endl;
    cout << "¿Desea volver Agregar, Editar, Eliminar clientes? (a/ e/ d): " << endl;
    cout << "a" << endl;
    cout << "=============================" << endl;
    cout << "ID:    123" << endl;
    cout << "Cantidad:  2" << endl;
    cout << "Descuento del 20%" << endl;
    cout << "Puntos necesarios: 295" << endl;
    cout << "||=========================||" << endl;
    cout << "¿Desea volver al CRUD o salir al menu? (v/s): " << endl;

}

void showUsers() {
    cout << "||=========================||" << endl;
    cout << "--------Echo-Exchange--------" << endl;
    cout << "" << endl;
    cout << "\tRegistro de clientes" << endl;
    cout << "______________________________" << endl;
    cout << "------------------------------" << endl;
    cout << "Nombre del cliente:    Ivan Arguello" << endl;
    cout << "ID:    00071012" << endl;
    cout << "PASS:  iA071012" << endl;
    cout << "E-mail:    iArg@gmail.com" << endl;
    cout << "Telefono:  8899-1033" << endl;
    cout << "+++++++++++++++++++++++" << endl;
    cout << "Nombre del cliente:    Rodrigo Sarrias" << endl;
    cout << "ID:    00082123" << endl;
    cout << "PASS:  oB182123" << endl;
    cout << "E-mail:    rSarr@gmail.com" << endl;
    cout << "Telefono:  9910-2145" << endl;
    cout << "||=========================||" << endl;
    cout << "¿Desea mostrar los usuarios de nuevo o salir al menu? (v/s): " << endl;
}