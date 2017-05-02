#ifndef __BLUEPRINT_FILE_H__
#define __BLUEPRINT_FILE_H__

#include <iostream>
#include <string>
#include <fstream>

#include "helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

class File{
    // Nombre o direccion del archivo
    std::string name;
    // Datos cargados
    char* buffer;
    // Tamaño del archivo
    unsigned int length;
    // Si los datos fueron cargados
    bool isDataLoaded;
  public:
    File(  );
    File( const std::string _fileName );
    virtual ~File(  );
    // Carga el archivo si recivio del
    // constructor el nombre del archivo
    bool load(  );
    // Carga el archivo
    bool load( const std::string& _fileName );
    // Retorna el archivo en memoria
    char* getData(  ) const;
};

std::string getExtension( const std::string& _buffer );

NAMESPACE_END( GameEngine );

#endif
