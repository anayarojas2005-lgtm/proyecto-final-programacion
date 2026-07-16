#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    srand(time(0));
    int tipoP;

    cout << "    SIMULACION DE ATENCION HOSPITALARIA    " << endl;

    cout << "Tipo de Paciente:" << endl;
    cout << "1. Paciente con Seguro" << endl;
    cout << "2. Paciente Regular" << endl;
    cout << "Seleccione una opcion (1 o 2): ";
    cin >> tipoP;

    // PRIMER TXT: GENERACION DE TICKET PARA ATENCION EN VENTANA

    int numTicket = rand() % 9000 + 1000; 
    int ventanaAsignada = rand() % 5 + 1;    

    ofstream archivoTicket("ticket_de_atencion.txt");

    if (archivoTicket.is_open()) {
        archivoTicket << "TICKET DE ATENCION" << endl;
        archivoTicket << "Tipo de Paciente: " << (tipoP == 1 ? "Con Seguro" : "Regular") << endl; 
        archivoTicket << "Numero de Ticket: " << numTicket << endl;
        archivoTicket << "dirijase a la ventana :" << ventanaAsignada << endl;
        archivoTicket.close();
        cout << "\nSe ha generado su ticket en 'ticket_de_atencion.txt'." << endl;
    } else {
        cout << "Error al crear el archivo del ticket." << endl;
        return 1;
    }

    // ATENCION EN VENTANA
    
    int ventanaN;
    cout << "\ningrese el numero de ventana asignado para continuar: ";
    cin >> ventanaN;

    while (ventanaN != ventanaAsignada) {
        cout << "Numero incorrecto. Su ticket indica la Ventana " << ventanaAsignada << ". Intente de nuevo: ";
        cin >> ventanaN;
    }

    //REGISTRO DE PACIENTE

    string nombre;
    int dni, edad;
    cin.ignore();
    cout << "\nVENTANA Nº:" << ventanaAsignada << "\nDATOS DEL PACIENTE:\n" << endl;
    cout << "Ingrese su Nombre Completo: ";
    getline(cin, nombre);
    cout << "Ingrese su DNI: ";
    cin>>dni;
    cout << "Ingrese su Edad: ";
    cin>>edad;

    int consultorioAsignado = rand() % 10 + 1;

    ofstream archivoDatos("ficha_del_paciente.txt");
    if (archivoDatos.is_open()) {
        archivoDatos << "DATOS DEL PACIENTE:" << endl;
        archivoDatos << "Nombre: " << nombre << endl;
        archivoDatos << "DNI: " << dni << endl;
        archivoDatos << "Edad: " << edad << endl;
        archivoDatos << "Tipo: " << (tipoP == 1 ? "Con Seguro" : "Regular") << endl;
        archivoDatos << "Consultorio Asignado: Consultorio " << consultorioAsignado << endl;
        archivoDatos.close();
        cout << "\nDatos registrados en 'ficha_del_paciente.txt'." << endl;
        cout << "Dirijase al Consultorio: " << consultorioAsignado << endl;
    }

    //CONSULTORIO Y RECETA
    
    int consultorioN;
    cout << "\ningrese al consultorio asignado para continuar: ";
    cin >> consultorioN;

    while (consultorioN != consultorioAsignado) {
        cout << "consultorio incorrecto. revise su ficha " << consultorioAsignado<<endl;
        cin >> consultorioN;
    }
    cout << "     CONSULTORIO " << consultorioAsignado << endl;
    cout << "Seleccione sus sintomas (ingrese los numeros uno por uno, o 0 para finalizar):" << endl;
    cout << "1. Fiebre alta" << endl;
    cout << "2. Dolor de cabeza" << endl;
    cout << "3. Tos / Infeccion de garganta" << endl;
    cout << "4. Dolor estomacal" << endl;

    int opcionSintoma;
    string listaSintomas = "";
    string listaMedicamentos = "";

    //generacion de receta

    do {
        cout << "Ingrese numero de sintoma (0 para terminar): ";
        cin >> opcionSintoma;

        switch (opcionSintoma) {
            case 1:
                listaSintomas += "- Fiebre alta\n";
                listaMedicamentos += "- Paracetamol 500mg (Cada 8 horas)\n";
                break;
            case 2:
                listaSintomas += "- Dolor de cabeza\n";
                listaMedicamentos += "- Ibuprofeno 400mg (Cada 8 horas)\n";
                break;
            case 3:
                listaSintomas += "- Tos / Infeccion de garganta\n";
                listaMedicamentos += "- Jarabe para la tos / Amoxicilina 500mg\n";
                break;
            case 4:
                listaSintomas += "- Dolor estomacal\n";
                listaMedicamentos += "- Bismutol / Ansiolitico digestivo\n";
                break;
            case 0:
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcionSintoma != 0);

    // SIN SINTOMAS
    if (listaSintomas == "") {
        listaSintomas = "- Sin sintomas registrados\n";
        listaMedicamentos = "- Reposo y observación\n";
    }

    ofstream archivoReceta("receta_medica.txt");
    if (archivoReceta.is_open()) {
        archivoReceta << " RECETA MEDICA " << endl;
        archivoReceta << "Paciente: " << nombre << endl;
        archivoReceta << "DNI: " << dni << endl;
        archivoReceta << "Consultorio: " << consultorioAsignado << endl;
        archivoReceta << "\nSintomas Presentados:\n" << listaSintomas;
        archivoReceta << "\nMedicamentos Recetados:\n" << listaMedicamentos;
        archivoReceta.close();
        cout << "\nConsulta finalizada. Receta generada con exito en 'receta_medica.txt'." << endl;
    }

    return 0;



}