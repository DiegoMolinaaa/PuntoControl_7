#include "Operaciones.h"
Operaciones::Operaciones() {};
Operaciones::Operaciones(fstream& fcont) {
	this->fcont.swap(fcont);
}
void Operaciones::escribir_o_leer(bool Escribir) {
	for (int i = 0; i < 6; ++i)
		if (Escribir) {
			Contacto cont("FALTA TELEFONO", "Nombre " + to_string(i), i);
			fcont.write(reinterpret_cast<const char*>(&cont), sizeof(Contacto));
		}
		else {
			Contacto cont;
			fcont.seekp(i * sizeof(Contacto));
			fcont.read(reinterpret_cast<char*>(&cont), sizeof(Contacto));
			cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
		}
}
void Operaciones::leer_el_3(Contacto & cont) {
	fcont.seekp(3 * sizeof(Contacto));
	fcont.read(reinterpret_cast<char*>(&cont), sizeof(Contacto));
	cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
}
void Operaciones::escribir_el_3(Contacto& cont) {
	// INSERTAR C�DIGO AQU�
	fcont.seekp(3 * sizeof(Contacto));
	// INSERTAR C�DIGO AQU�
	cont.establecerId(5000);
	// INSERTAR C�DIGO AQU�
	cont.establecerNombre("Nombre 5 -> 5000");
	// INSERTAR C�DIGO AQU�
	fcont.write(reinterpret_cast<const char*>(&cont), sizeof(Contacto));
}
void Operaciones::cambios() {
	Contacto cont;
	leer_el_3(cont);
	escribir_el_3(cont);
	leer_el_3(cont);
}