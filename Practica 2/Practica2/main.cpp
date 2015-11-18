#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "../include/u-gine.h"

int main(int argc, char* argv[]) {
	Screen::Instance().Open(800, 600, false);
	// TAREA: Cargar la imagen “data/ball.png”
	// TAREA: Centrar imagen
	while (Screen::Instance().IsOpened() /* TAREA: Salida con ESC */) {
		// TAREA: Actualizar ángulo y escala de la imagen
		// TAREA: Limpiar pantalla y dibujar la imagen
		// Refrescamos la pantalla
		Screen::Instance().Refresh();
	}
	ResourceManager::Instance().FreeResources();
	return 0;
}