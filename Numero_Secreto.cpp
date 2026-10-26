#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    // Inicializar la semilla de números aleatorios
    srand(static_cast<unsigned int>(time(0)));
    
    char jugarDeNuevo;

    do {
        limpiarPantalla();
        
        // Generar número secreto entre 1 y 100
        int numeroSecreto = rand() % 100 + 1;
        int intentoUsuario = 0;
        int intentosMaximos = 7; // Límite de vidas para darle emoción
        int intentosRealizados = 0;
        bool gano = false;

        cout << "=================================================" << endl;
        cout << "   ¡BIENVENIDO AL JUEGO DEL NUMERO SECRETO!      " << endl;
        cout << "=================================================" << endl;
        cout << " He pensado un numero entre 1 y 100." << endl;
        cout << " Tienes " << intentosMaximos << " intentos para adivinarlo. ¡Suerte!" << endl;
        cout << "=================================================" << endl;

        while (intentosRealizados < intentosMaximos) {
            cout << "\n[Intento " << (intentosRealizados + 1) << "/" << intentosMaximos << "] Ingrese su numero: ";
            cin >> intentoUsuario;

            // Validación de entrada por si ingresan texto o letras
            if (cin.fail() || intentoUsuario < 1 || intentoUsuario > 100) {
                cout << "-> Error: Por favor ingresa un numero valido entre 1 y 100." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue; // Repite el mismo intento sin penalizar las vidas
            }

            intentosRealizados++;

            if (intentoUsuario == numeroSecreto) {
                gano = true;
                break; // Rompe el bucle si adivinó
            } else if (intentoUsuario < numeroSecreto) {
                cout << "-> Pista: El numero secreto es MAS ALTO (↑)." << endl;
            } else {
                cout << "-> Pista: El numero secreto es MAS BAJO (↓)." << endl;
            }
        }

        // Resultados finales de la partida
        cout << "\n=================================================" << endl;
        if (gano) {
            cout << " 🎉 ¡FELICIDADES! ¡ADIVINASTE EL NUMERO! 🎉" << endl;
            cout << " Lo lograste en " << intentosRealizados << " intentos." << endl;
        } else {
            cout << " ❌ ¡OH NO! Te has quedado sin intentos. ❌" << endl;
            cout << " El numero secreto era el: " << numeroSecreto << endl;
        }
        cout << "=================================================" << endl;

        cout << "\n¿Quieres jugar una nueva partida? (s/n): ";
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    limpiarPantalla();
    cout << "=================================================" << endl;
    cout << " ¡Gracias por jugar! Codigo listo para tu entrega." << endl;
    cout << "=================================================" << endl;

    return 0;
}
