#ifndef UGINE_IMAGE_H
#define UGINE_IMAGE_H

#include "string.h"
#include "types.h"

class Image {
public:
    Image(const String& filename, uint16 hframes = 1, uint16 vframes = 1);
	virtual ~Image();

    virtual bool IsValid() const { return gltex != 0; } //Comprueba que el new generado es válido
    virtual const String& GetFilename() const { return filename; } //Nombre fichero imagen pasado
    virtual uint32 GetNumFrames() const { return hframes * vframes; }
    virtual uint16 GetHFrames() const { return hframes; }
    virtual uint16 GetVFrames() const { return vframes; }
    virtual uint16 GetWidth() const { return width / hframes; } //Ancho de textura
    virtual uint16 GetHeight() const { return height / vframes; } //Alto de textura. Si no es potencia de 2, devuelven el tamaño original de la imagen
    virtual void SetHandle(int32 handlex, int32 handley) { this->handlex = handlex; this->handley = handley; } //Cuando pintamos una imagen en una coordenada, el punto 0,0 es el handle
    virtual void SetMidHandle() { SetHandle(GetWidth()/2, GetHeight()/2); } //Si queremos llevar el handle al centro de la imagen, lo usamos
    virtual int32 GetHandleX() const { return handlex; }
    virtual int32 GetHandleY() const { return handley; }
    virtual void Bind() const;
    virtual double GetLastU() const { return lastU; } //Cuando tenemos una imagen que no es potencia de 2, esta funcion devuelve la coordenada (por ej.) 100/128
    virtual double GetLastV() const { return lastV; } //Cuando tenemos una imagen que no es potencia de 2, esta funcion devuelve la coordenada (por ej.) 100/128
protected:
    virtual uint32 GetTexId() const { return gltex; }
private:
    String filename;
    uint16 hframes, vframes;
    uint16 width, height; //Ancho y alto de la imagen
    int32 handlex, handley;
    uint32 gltex;
    double lastU, lastV; //alto de imagen/ancho de imagen
};

#endif
