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

    int numeroTicket = rand() % 9000 + 1000; // Número aleatorio de 4 digitos {{{{POSIBLE PREGUNTA}}}}
    int ventanaAsignada = rand() % 5 + 1;    // Ventana aleatoria entre 1 y 5 

    ofstream archivoTicket("ticket_de_atencion.txt");

    if (archivoTicket.is_open()) {
        archivoTicket << "TICKET DE ATENCION" << endl;
        archivoTicket << "Tipo de Paciente: " << (tipoP == 1 ? "Con Seguro" : "Regular") << endl; // {{{{POSIBLEMENTE CAMBIE ESTA PARTE PARA UTILIZAR OBJETOS}}}}
        archivoTicket << "dirigase a la ventana :" << ventanaAsignada << endl;
        archivoTicket.close();
        cout << "\n[+] Se ha generado su ticket en '1_ticket.txt'." << endl;
    } else {
        cout << "Error al crear el archivo del ticket." << endl;
        return 1;
    }

}