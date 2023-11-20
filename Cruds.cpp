

void addGft(gift currentGft)
{
    if (lasTregGft < MAX)
    {
        gft[lasTregGft] = currentGft;
        lasTregGft++;
        idCmp++;
    }
    else
    {
        cout << "Recompensas esta en Maxima capacidad..." << endl;
    }
}
void initGft(int gftPos)
{
    gft[pos].gft_id = 0;

    strncpy(gft[pos].gft_name, "", sizeof(gft[pos].gft_name));

    gft[pos].gft_cant = 0;

    gft[pos].gft_pts = 0;
}

void showGft(int pos)
{
    system("cls || clear");
    cout << "====================================" << endl;
    cout << "ID: ";
    cout << gft[pos].gft_id << endl;
    cout << "Nombre: ";
    cout << gft[pos].gft_name << endl;
    cout << "Cantidad: ";
    cout << gft[pos].gft_cant << endl;
    cout << "Puntos Necesarios: ";
    cout << gft[pos].gft_pts << endl;

    system("pause || read -p 'Presiona enter para continuar...' -n 1 -s");
    system("cls || clear");
}

void showGftRegister() 
{
    system("cls || clear");
    if (lasTregGft == 0)
    {
        cout << "No hay Recompenas registradas" << endl;
        return;
    }
    cout << "Registro de Recompensas: " << endl;
    cout << "====================================" << endl;

    for (int i = 0; i < lasTregGft; i++)
    {
        cout << "Recompensa #" << i + 1 << endl;
        showGft(i);
    }
    cout << "====================================" << endl;
    cout << "Ultimo registro..." << endl;
}

gift getGft(int pos)
{
    return gft[pos];
}

void searchGFTname(char *enteredGft_name) 
{
    int position = 0;
    for (int i = 0; i < lasTregGft; i++)
    {
        if (strcmp(enteredGft_name, gft[i].gft_name) == 0)
        {
            cout << "====" << endl;
            showGft(i);
            position++;
        }

        if (position == 0)
        {
            cout << "No se encontraron resultados..." << endl;
        }
    }
}

int searchGFTid(int entered_id)
{
    int position = 0;
    for (int i = 0; i < lasTregGft; i++)
    {
        if (entered_id == (gft[i].gft_id))
        {
            cout << "====" << endl;
            showGft(i);
            position++;
        }

        if (position == 0)
        {
            cout << "No se encontraron resultados..." << endl;   
        }
    }
}

void uptGFT(gift gift, int i)
{
    gft[pos] = currentGft;
}

void delGFT(int pos)
{
    if (pos == lasTregGft)
    {
        cout << "No hay registros..." << endl;
        return;
    }
    for (int i = pos; i < lasTregGft - 1; i++)
    {
        gft[i] = gft[i + 1];
    }
    lasTregGft--;
    idCmp--;
    initGft(lasTregGft)
}