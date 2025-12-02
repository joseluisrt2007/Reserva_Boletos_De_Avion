#pragma once
#include <string>
#include "Usuario.h"

// No se usa 'using namespace std;' en el encabezado.

class Menu
{
	//atributos
private:

	//métodos
public:
	// Declaración de la función para mostrar el menú
	void MostrarMenuAdmin();
	void MostrarMenu() const;
	void MostrarMenuPrincipal();
	void MostrarPantallaInicio() const;

};
