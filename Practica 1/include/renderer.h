#ifndef UGINE_RENDERER_H
#define UGINE_RENDERER_H

#include "string.h"
#include "types.h"

class Font;
class Image;

class Renderer {
public:
    enum BlendMode {
		SOLID,
		ALPHA,
		MULTIPLICATIVE,
		ADDITIVE
	};

    static const Renderer& Instance() { if ( !renderer ) renderer = new Renderer(); return *renderer; }

    virtual void SetBlendMode(BlendMode blendMode) const; //Modo de mezclar colores
    virtual void SetColor(uint8 r, uint8 g, uint8 b, uint8 a) const;
    virtual void SetOrigin(double x, double y) const;
    virtual void Clear(uint8 r = 0, uint8 g = 0, uint8 b = 0) const; //Limpia fondo de pantalla
    virtual void DrawPoint(double x, double y) const; //Pinta un punto
    virtual void DrawLine(double x1, double y1, double x2, double y2) const; //Pinta una l�nea
    virtual void DrawRect(double x, double y, double width, double height) const; //Pinta un rect�ngulo
    virtual void DrawEllipse(double x, double y, double xradius, double yradius) const; //Pinta una elipse
    //virtual void DrawImage(const Image* image, double x, double y, uint32 frame = 0, double width = 0.0f, double height = 0.0f, double ang = 0) const;
    //virtual void DrawTiledImage(const Image* image, double x, double y, double width, double height, double offsetx = 0, double offsety = 0) const;
    //virtual void DrawText(const Font* font, const String& text, double x, double y) const;
protected:
    Renderer() {}
private:
    static Renderer* renderer;
};

#endif
