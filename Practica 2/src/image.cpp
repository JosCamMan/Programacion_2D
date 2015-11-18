#include "../include/image.h"
#include "../include/glinclude.h"
#include "../include/math.h"
#include "../include/renderer.h"

#include <math.h>
#include <stdlib.h>

// TAREA: Declarar funciones de stb_image.c
extern "C" {
	uint8* stbi_load(const char*, int*, int*, int*, int);
	void stbi_image_free(void*);
}


Image::Image(const String &filename, uint16 hframes, uint16 vframes) {
	this->filename = filename;
	this->hframes = hframes;
	this->vframes = vframes;
	width = 0;
	height = 0;
	handlex = 0;
	handley = 0;
	gltex = 0;
	lastU = 1.0;
	lastV = 1.0;

	// TAREA: Cargar el buffer de la imagen
	int w, h;
	uint8* buffer = stbi_load(filename.ToCString(), &w, &h, NULL, 4);	

	// Generamos la textura
	if ( buffer ) {
		// TAREA: Generar la textura de OpenGL
		width = static_cast<uint16>(w);
		height = static_cast<uint16>(h);
		gltex = Renderer::Instance().GenImage(buffer, width, height);
		stbi_image_free(buffer);
	}
}

Image::~Image() {
	Renderer::Instance().DeleteImage(gltex);
}

void Image::Bind() const {
	// TAREA: Establecer la textura actual
	if (gltex != 0) {
		Renderer::Instance().Image().BindImage(gltex);
	}
}

