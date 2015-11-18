#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "../include/u-gine.h"

int main(int argc, char* argv[]) {
	Screen::Instance().Open(800, 600, false);
	Renderer::Instance().SetOrigin(0, 0);
	
	double ang = 0;

	while ( Screen::Instance().IsOpened() != Screen::Instance().KeyPressed(GLFW_KEY_ESC)) {
		// TAREA: Pintar primitivas
		double x = (DegCos(ang) * 30) + Screen::Instance().GetMouseX();
		double y = -(DegSin(ang) * 30) + Screen::Instance().GetMouseY();

		//Titulo de la pantalla
		String dis = String::FromInt(Distance((Screen::Instance().GetWidth() / 2), (Screen::Instance().GetHeight() / 2) - 15, Screen::Instance().GetMouseX() - 15, 
												Screen::Instance().GetMouseY() - 15));
		String anguloTexto = String::FromInt(Angle(Screen::Instance().GetMouseX(), Screen::Instance().GetMouseY() - 15, x, y));
		Screen::Instance().SetTitle(String("Ángulo: ") + anguloTexto + String(" Distancia: ") + dis);

		//Cuadrado central
		Renderer::Instance().SetColor(255, 0, 0, 255);
		Renderer::Instance().DrawRect((Screen::Instance().GetWidth() / 2) - 10, (Screen::Instance().GetHeight() / 2) - 10, 20, 20);

		//Cuadrado del puntero del ratón
		Renderer::Instance().SetColor(0, 250, 0, 250);
		Renderer::Instance().DrawRect(Screen::Instance().GetMouseX() - 10 , Screen::Instance().GetMouseY() - 10, 20, 20);

		Renderer::Instance().SetColor(0, 0, 250, 250);
		Renderer::Instance().DrawEllipse(x , y, 10, 10);
		
		ang++;
		
		ang = WrapValue(ang, 360);

		// Refrescamos la pantalla
		Screen::Instance().Refresh();

		Renderer::Instance().Clear(1, 1, 1);
	}

	return 0;
}