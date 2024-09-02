#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Tarea {
    string nombre;
    bool urgente;
    bool importante;
};

string clasificarTarea(bool urgente, bool importante) {
    if (urgente && importante) {
        return "Hacer ahora";
    } else if (urgente) {
        return "Delegar";
    } else if (importante) {
        return "Planificar";
    } else {
        return "Eliminar";
    }
}

int main() {
    int numTareas;
    vector<Tarea> tareas;

    cout << "Ingrese la cantidad de tareas: ";
    cin >> numTareas;
    cin.ignore(); // Limpiar el buffer de entrada

    for (int i = 0; i < numTareas; i++) {
        Tarea tarea;
        cout << "Ingrese el nombre de la tarea " << (i + 1) << ": ";
        getline(cin, tarea.nombre);

        cout << "¿Es urgente? (1 para sí, 0 para no): ";
        cin >> tarea.urgente;

        cout << "¿Es importante? (1 para sí, 0 para no): ";
        cin >> tarea.importante;
        cin.ignore(); // Limpiar el buffer de entrada

        tareas.push_back(tarea);
    }

    cout << "\nClasificación de tareas:\n";
    for (const auto& tarea : tareas) {
        string resultado = clasificarTarea(tarea.urgente, tarea.importante);
        cout << "Tarea: " << tarea.nombre << " - " << resultado << endl;
    }

    return 0;
}
