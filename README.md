# echo-exchange 
### Proyecto de Metodología y Programación Estructurada
###### // Nota
#### **Importante:**

- Añadir función para operar con los puntos: haga desgloses de los puntos a los clientes.
- Añadir función para desglose del inventario de recompensas.
###### // Fin de Nota

##### **Funciones:**

###### // Acceso al programa
- **void login():** Switch simple imprime 2 opciones de entrada al sistema 1.Admin. 2.Clientes/Trabajadores.
- **void log_adm():** Acceso estatico para el admin con ID y pass único.
- **void log_clt():** Acceso para clientes, este recibira información como el ID y pass directamente de la Struct. Accedera a un espacio con opciones limitadas en comparación al Admin. 
- **bool verification_clt():** Booleano envia la confirmación de acceso al Admin.
- **bool verification_adm():** Booleano envia la confirmación de acceso para los Clientes.

###### // Menus 
- **void Madmin():** Menu principal del Admin, aqui se encuentran acciones esenciales como el Crud de cliente y recompensas.
- **void Mdclient():** Menu de Crud de clientes.
- **void searchMclt():** Menu de busqueda de clientes, aqui se encuentran 6 opciones de busqueda. Por nombre, apellido, ID, E-mail, numero telefonico y la opcion de mostrar todos los registros.

###### // CRUD clientes

###### // Create
- **void addClt():** Hace un seguimiento al numero de clientes almacenados en el arreglo.
- **void initClt(int cltPos):** Inicializa los datos del cliente con valores nulos como "" ó '\0'

###### //Read
- **void showClt():** Muestra los datos del cliente según "int pos".
- **void searchCltname(char client_name[]):** Hace una comparación de los nombres con cadena de caracteres con el strcmp y si el el resultado es 0 imprime los datos del cliente buscado.
- **void searchCltlstname(int client_lstName[]):** Hace una comparación de los apellidos con cadena de caracteres con el strcmp y si el el resultado es 0 imprime los datos del cliente buscado.
- **int searchCltId(int client_id):** Hace una comparación de los ID con cadena de caracteres con el strcmp y si el el resultado es 0 imprime los datos del cliente buscado.
- **void searchCltmail(char client_mail[]):** Hace una comparación de los e-mails con cadena de caracteres con el strcmp y si el el resultado es 0 imprime los datos del cliente buscado.
- **int searchCltelf(char client_telf[]):** Hace una comparación de los numeros telefonicos con cadena de caracteres con el strcmp y si el el resultado es 0 imprime los datos del cliente buscado.

###### //Uptade
- **void uptdClt():** Modifica los datos guardados en el arreglo de clientes. Por medio de la posicion (i).

###### //Delete
- **void delClt():** Borra los datos guardados en el arreglo de clientes. Por medio de la posicion (i).

###### // Modulos de sistema
- **void clientS():**
- **void regPurchase():** Registro de compra, realizara el cambio de moneda a puntos el cambio será $5 = 1pts. 
- **void rewards():** Es un crud para las recompensas(arreglo donde se almacenan).
- **void redeem():** Realiza el intercambio de puntos a recompensas.
- **void checkPts():** Imprimira los puntos ahorrados por cada cliente.
- **void record():** Historial de compras realizadas se categorizará por día, mes o año.