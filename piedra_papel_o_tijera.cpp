#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <limits>

using namespace std;

// Estructura para almacenar el marcador
struct Marcador {
    int usuario = 0;
    int computadora = 0;
    int empates = 0;
};

// Prototipos de funciones para mantener el código organizado
void mostrarMenu();
int obtenerEleccionUsuario();
void determinarGanador(int usuario, int computadora, Marcador &marcador, const string opciones[]);
void mostrarMarcador(const Marcador &marcador);

int main() {
    // Configurar la semilla aleatoria basada en el tiempo actual
    srand(static_cast<unsigned int>(time(0)));

    const string opciones[] = {"Piedra", "Papel", "Tijera"};
    Marcador marcador;
    char jugarDeNuevo;

    cout << "===========================================" << endl;
    cout << "  ¡Bienvenido a Piedra, Papel o Tijera!   " << endl;
    cout << "===========================================" << endl;

    do {
        mostrarMenu();
        int eleccionUsuario = obtenerEleccionUsuario();
        int eleccionComputadora = rand() % 3;

        cout << "\n-------------------------------------------" << endl;
        cout << "-> Tu elegiste: " << opciones[eleccionUsuario] << endl;
        cout << "-> La computadora eligio: " << opciones[eleccionComputadora] << endl;
        cout << "-------------------------------------------" << endl;

        determinarGanador(eleccionUsuario, eleccionComputadora, marcador, opciones);
        mostrarMarcador(marcador);

        cout << "\n¿Quieres jugar otra ronda? (s/n): ";
        cin >> jugarDeNuevo;

    } while (jugarDeNuevo == 's' || jugarDeNuevo == 'S');

    cout << "\n===========================================" << endl;
    cout << "  ¡Gracias por jugar! Programa finalizado. " << endl;
    cout << "===========================================" << endl;

    return 0;
}

void mostrarMenu() {
    cout << "\nElige tu jugada:" << endl;
    cout << "0. Piedra" << endl;
    cout << "1. Papel" << endl;
    cout << "2. Tijera" << endl;
}

int obtenerEleccionUsuario() {
    int eleccion;
    while (true) {
        cout << "Introduce el numero de tu eleccion (0-2): ";
        cin >> eleccion;

        // Validar si la entrada no es un número o está fuera de rango
        if (cin.fail() || eleccion < 0 || eleccion > 2) {
            cin.clear(); // Limpiar el estado de error de cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar la entrada incorrecta
            cout << "Entrada no valida. Por favor, ingresa un numero entre 0 y 2.\n" << endl;
        } else {
            return eleccion;
        }
    }
}

void determinarGanador(int usuario, int computadora, Marcador &marcador, const string opciones[]) {
    if (usuario == computadora) {
        cout << "Resultado: ¡Es un empate! 🤝" << endl;
        marcador.empates++;
    } 
    else if ((usuario == 0 && computadora == 2) || // Piedra vence a Tijera
             (usuario == 1 && computadora == 0) || // Papel vence a Piedra
             (usuario == 2 && computadora == 1)) {  // Tijera vence a Papel
        cout << "Resultado: ¡Ganaste esta ronda! 🎉" << endl;
        marcador.usuario++;
    } 
    else {
        cout << "Resultado: ¡La computadora gana esta ronda! 🤖" << endl;
        marcador.computadora++;
    }
}

void mostrarMarcador(const Marcador &marcador) {
    cout << "\n========== MARCADOR ACTUAL ==========" << endl;
    cout << "  Usuario: " << marcador.usuario << "  |  Computadora: " << marcador.computadora << "  |  Empates: " << marcador.empates << endl;
    cout << "=====================================" << endl;
}
