//
//  texturemanager.hpp
//  MushRoom
//
//  Created by Angel Land on 3/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __MUSHROOM_TEXTUREMANAGER_HPP__
#define __MUSHROOM_TEXTUREMANAGER_HPP__

#include <string>
#include <map>
#include <vector>

#include "../../extern/glew/glew.h"

#include "../utils/helpers.hpp"
#include "texture.hpp"

NAMESPACE_BEGIN( GameEngine );

#define TextureManagerInstance TextureManager::getInstance()

/* Estructura de carga para los archivos TGA */
struct TGAHeader{
  char idLength; // Tamaño del campo id
  // Si es 0 no contiene mapa de colores
  // Si es 1 contiene mapa de colores
  // 2-127 para Truevision 128-255 para desarrolladores
  char colorMapType;
  // Si es 0 no se encuentra informacion
  // de la imagen
  // Si es 1 el mapeo de colores esta descomprimido
  //
  char imageType; // Compresion y tipo de colores
  char colorMapSpecification[5]; // Descibre el mapa de colores
  char xOrigin[2]; // 2 bytes origen de la imagen en x
  char yOrigin[2]; // 2 bytes origne de la imagen en y
  char width[2];  // 2 bytes ancho en pixeles
  char height[2]; // 2 bytes alto en pixeles
  char pixelSize; // 1 byte Tamaño del pixel
  char imageDescriptor; // 1 byte WTF?
};

/* Estructura de carga para los archivos BMP */
struct BMPHeader{
  /* CABEZERA DEL ARCHIVO */
  char type[2]; // Se supone que tiene que ser "BM"
  char fileSize[4]; // Tamaño de todo el bmp 4 bytes
  char reserved[4]; // Siempre es 0
  char offsetImageData[4]; // Inicio de los datos de la imagen en bytes 4 bytes
  /* DATOS DE LA IMAGEN */
  char imageHeadSize[4]; // Tamaño de la estructura de la imagen ( esta )
  char width[4];  // ancho de la imagen
  char height[4]; // alto de la imagen
  char planes[2]; // Numero de colores planos
  char bpp[2]; // Numero de bits por pixel
  char compression[4]; // Formato de compresion
  char imgSize[4];
  char xResolution[4], yResolution[4];
  char colours[4];
  char importantColours[4];
};

class TextureManager{
  std::vector<Texture*> _mTextures;
  std::vector<std::string> _mTexturesNames;
public:
  TextureManager(  );
  virtual ~TextureManager(  );
  
  static TextureManager& getInstance(  );
  
  Texture* load(const std::string& _name,
                const std::string& _path );
  
  Texture* loadCubeMap(const std::string& _name,
                       const std::vector<std::string>& _paths);
  
  Texture* get(const std::string& _name);
  
  TGAHeader* getTGAHead( std::ifstream& _file );
}

NAMESPACE_END( GameEngine );

#endif /* __MUSHROOM_TEXTUREMANAGER_HPP__ */
