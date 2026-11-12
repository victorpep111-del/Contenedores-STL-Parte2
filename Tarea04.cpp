#include <bits/stdc++.h>
using namespace std;

class Estudiante {
private:
    string nombre;
    int Nacimiento;
    float promedioGPA;
    float presupuesto;
public:
    Estudiante(string nombre, int Nacimiento, float promedioGPA, float presupuesto) {
        this->nombre = nombre;
        this->Nacimiento = Nacimiento;
        this->promedioGPA = promedioGPA;
        this->presupuesto = presupuesto;
    }

    string getNombre() const { return nombre; }
    int getAnioNacimiento() const { return Nacimiento; }
    float getGPA() const { return promedioGPA; }
    float getPresupuesto() const { return presupuesto; }
    float getIndiceUniversitario() const { return abs(promedioGPA - 3.0f) * presupuesto; }
};

void Insertar(vector<Estudiante>& estudiantes) {
    string nombre;
    int Nacimiento;
    float promedioGPA;
    float presupuesto;
    cout << "1. Inserte una estudiante al final" << endl;
    cout << "2. Inserte una estudiante en un indice especifico" << endl;
    int opcion;
    cin >> opcion;

    cout << " Ingrese  el nombre, anio de nacimiento, promedio GPA y presupuesto del estudiante: "<<endl;
    cin >> nombre >> Nacimiento >> promedioGPA >> presupuesto;
    Estudiante estudianteNuevo(nombre, Nacimiento, promedioGPA, presupuesto);

    if(opcion == 1) {
        estudiantes.push_back(estudianteNuevo);
    } else if(opcion == 2) {
        int indice;
        cout << "Ingrese el indice donde desea insertar al estudiante: ";
        cin >> indice;
        if(indice >= 0 && indice < estudiantes.size()) {
            estudiantes.insert(estudiantes.begin() + indice, estudianteNuevo);
        } else {
            cout << "Indice fuera de rango" << endl;
        }
    }
}

void Eliminar(vector<Estudiante>& estudiantes) {
    if(estudiantes.empty()) {
        cout << "El vector esta vacio" << endl;
        return;
    }
    cout << "1. Eliminar el ultimo estudiante" << endl;
    cout << "2. Eliminar un estudiante en un indice especifico" << endl;
    int opcion;
    cin >> opcion;
    if(opcion == 1) {
        estudiantes.pop_back();
    } else if(opcion == 2) {
        int indice;
        cout << "Ingrese el indice del estudiante que desea eliminar: ";
        cin >> indice;
        if(indice >= 0 && indice < estudiantes.size()) {
            estudiantes.erase(estudiantes.begin() + indice);
        } else {
            cout << "Indice fuera de rango" << endl;
        }
    }
}

void Actualizar(vector<Estudiante>& estudiantes) {
    if(estudiantes.empty()) {
        cout << "El vector esta vacio" << endl;
        return;
    }
    int indice;
    cout << "Ingrese el indice del estudiante que desea actualizar: ";
    cin >> indice;
    if(indice >= 0 && indice < estudiantes.size()) {
        string nombre;
        int Nacimiento;
        float promedioGPA;
        float presupuesto;
        cout << "Ingrese el nuevo nombre, anio de nacimiento, promedio GPA y presupuesto del estudiante: \n";
        cin >> nombre >> Nacimiento >> promedioGPA >> presupuesto;
        estudiantes[indice] = Estudiante(nombre, Nacimiento, promedioGPA, presupuesto);
    } else {
        cout << "Indice fuera de rango" << endl;
    }
}

void Ordenar(vector<Estudiante>& estudiantes) {
    cout << "1. Por anio de nacimiento" << endl;
    cout << "2. Por promedio GPA" << endl;
    cout << "3. Por presupuesto" << endl;
    cout << "4. Por indice universitario" << endl;
    int opcion;
    cin >> opcion;

    switch(opcion) {
        case 1:
            sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b)
            { return a.getAnioNacimiento() < b.getAnioNacimiento();});
            break;
        case 2:
            sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b)
            { return a.getGPA() < b.getGPA();});
            break;
        case 3:
            sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b)
            { return a.getPresupuesto() < b.getPresupuesto();});
            break;
        case 4:
            sort(estudiantes.begin(), estudiantes.end(), [](const Estudiante& a, const Estudiante& b)
            { return a.getIndiceUniversitario() < b.getIndiceUniversitario();});
            break;
        default:
            cout << "Opcion invalida" << endl;
    }
}

void Imprimir(const vector<Estudiante>& estudiantes) {
    if(estudiantes.empty()) {
        cout << "El vector esta vacio" << endl;
        return;
    }
    cout << "Nombre, Anio de Nacimiento, GPA, Presupuesto, Indice Universitario" << endl;
    for (const Estudiante& estudiante : estudiantes) {
        cout << estudiante.getNombre() << ", "
             << estudiante.getAnioNacimiento() << ", "
             << estudiante.getGPA() << ", "
             << estudiante.getPresupuesto() << ", "
             << estudiante.getIndiceUniversitario() << endl;
    }
}

void Menu(vector<Estudiante>& estudiantes) {
    int opcion;
    do{
    cout << "1. Ingresar estudiante" << endl;
    cout << "2. Eliminar estudiante" << endl;
    cout << "3. Actualizar estudiante" << endl;
    cout << "4. Ordenar" << endl;
    cout << "5. Imprimir el contenido del vector" << endl;
    cout << "6. Salir" << endl;
    if (!(cin >> opcion)) {
            break;
        }

        switch (opcion) {
            case 1: Insertar(estudiantes); break;
            case 2: Eliminar(estudiantes); break;
            case 3: Actualizar(estudiantes); break;
            case 4: Ordenar(estudiantes); break;
            case 5: Imprimir(estudiantes); break;
            case 6: cout << "Saliendo..." << endl; break;
            default: cout << "Opcion invalida" << endl; break;
        }
    } while (opcion != 6);
}

int main(){
    //freopen("pruebas.txt", "r", stdin);
    vector <Estudiante> estudiantes;
    Menu(estudiantes);

    return 0;
}
