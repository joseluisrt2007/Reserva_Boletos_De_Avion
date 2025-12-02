#include "Menu.h"
#include <iostream>
#include <string>
#include <limits>
#include <chrono>
#include <thread>
using namespace std; 

// -------------------- Pantalla de inicio --------------------
void Menu::MostrarPantallaInicio() const
{
    system("mode con cols=200 lines=80"); // Ajusta tamaño de consola
    system("color F9"); // Fondo blanco con texto azul

    cout <<
               R"(                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                            ##              ##                                                                          
                        ####                  ####                                                                      
                        ####                  ####                                                                      
                      ##                    ##    ##                                                                    
                      ####    ######..  ######  ####                                                                    
                    ##            ########      ##  ##      ##                    ++++##++                              
                      mm    ##    ########                ##  ##  ##########--####::  ##  ######  ####..                
                        ##    ####    ####      ##  MM    ##  ##  ##  ####  --    ##  ##  ##  ##  MM                    
                          ##    ##      ##      --MM    MM######  ##    ##    ++  ##  ##  ##      ##                    
                      ##  ##                            ##      ######@@##    ####    ##    ####  ####                  
                  @@##  @@                        ##                                                                    
                    ##      ##              ##          ######  ######    @@##  ####--####  ##########                  
                          ##mm  ##      ##  ####        ######  ######    ####  ####..####  --##    ####                
                            ####mm##  MM######                                                                          
                                  ##  ##                                                                                
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
                                                                                                                        
)" << endl;

    this_thread::sleep_for(chrono::seconds(4)); // Pausa de 4 segundos
    system("color 07");   // Restablece colores
    system("cls");        // Limpia la pantalla
}

void Menu::MostrarMenuAdmin(){
    int opcion;
    Usuario usuario;
    string nombre;
    string correo;
    string password;
    do
    {
       
        cout << "1.Registrar Usuario" << endl;
        cout << "2.Registra Vuelos" << endl;
        cout << "3.Salir" <<endl;
        cout << "Seleccione una opción: "<< endl;
         if (!(cin >> opcion)) {
            // Manejar entrada inválida
            cout << "Entrada inválida. Limpiando el buffer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0; // Para que el bucle continúe
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

        switch (opcion)
        {
        case 1:
           
            cout << "nombre" << endl;
            cin >> nombre;
            cout << "correo" << endl;
            cin >> correo;
            cout << "password" << endl;
            cin >> password;
            usuario.RegistrarUsuario(nombre,correo,password);
            
            break;
        
        default:
            cout << "Ssliste con exito" ;
            opcion=3;
            break;
        };
    } while (opcion!=3);
    
};
// Función para mostrar el menú de la aplicación y manejar el flujo
void Menu::MostrarMenuPrincipal() {
    Usuario usuarioActual;
    Menu menu;
    int opcion;

    do {
        
       
        
        cout << "1. Iniciar Sesión" << endl;
        cout << "2. Salir de la Aplicación" << endl;
        cout << "Seleccione una opción: "<< endl;

        if (!(cin >> opcion)) {
            // Manejar entrada inválida
            cout << "Entrada inválida. Limpiando el buffer." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            opcion = 0; // Para que el bucle continúe
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Limpiar el buffer

        switch (opcion) {
        case 1: {
            cout << "\n--- INICIAR SESIÓN ---" << endl;
            int respuesta;
            respuesta=usuarioActual.IniciarSesion();
            if (respuesta ==1) {
                MostrarMenu();
                
            }
            else if (respuesta == 3 ){
                MostrarMenuAdmin();
            };
            
            break;
        }
       
        
        default:
           cout << "\nGracias por usar el sistema. Saliendo..." << endl;
            opcion=2;
            break;
        }

    } while (opcion != 2);
};
void Menu::MostrarMenu() const
{
	int opcionMenu;
	do {
		
		
		cout << "        Menú de Vuelos\n"
			<< "1 - Reservar vuelo(fecha,hora,origen,destino,no.avion)\n"
			<< "2 - Pagar boleto\n"
			<< "3 - Salir" << endl;

		cout << "Seleccione una opción: ";
		cin >> opcionMenu;

		switch (opcionMenu)
		{
		case 1:
			cout << "\n--- Reservar vuelo ---" << endl;
			
			cout << "Vuelo reservado (simulación)." << endl;
			
			cout << "Presione ENTER para continuar...";
			cin.ignore(); // Limpiar el buffer
			cin.get();
			break;
		case 2:
			cout << "\n--- Pagar boleto ---" << endl;
			cout << "Pago de boleto (simulación)." << endl;
			cout << "Presione ENTER para continuar...";
			cin.ignore();
			cin.get();
			break;
		case 3:
			cout << "\nSaliendo del menú..." << endl;
			break;
		default:
			cout << "\nOpción no válida. Intente de nuevo." << endl;
			cout << "Presione ENTER para continuar...";
			cin.ignore();
			cin.get();
			break;
		}
	} while (opcionMenu != 3);

}
