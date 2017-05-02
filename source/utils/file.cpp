#include "file.hpp"

NAMESPACE_BEGIN( GameEngine );
//-----------------------------------------------------------------
File::File(  ){
  name = "";
  buffer = NULL;
  isDataLoaded = false;
}
//-----------------------------------------------------------------
File::File( const std::string _fileName ){
    name = _fileName;
}
//-----------------------------------------------------------------
File::~File(  ){
  delete buffer;
}
//-----------------------------------------------------------------
bool File::load(  ){
  if( name == "" )
    return false;

  FILE *file;
  // Abro el archivo de forma binaria
  file = fopen( name.c_str(), "rb" );

  if( !file ){
    std::cout<<"Error on load file: "<<name<<std::endl;
    return false;
  }

  // Calculo el tamaño del archivo
  fseek( file, 0, SEEK_END );
  length = ( unsigned int )ftell( file );
  fseek(file, 0, SEEK_SET);

  // Reservo memoria
  buffer = (char *)malloc( length+1 );
  if ( !buffer ){
    fprintf(stderr, "Memory error!");
    fclose(file);
  }

  // Cargo los datos en el buffer
  fread( buffer, length, 1, file );
  fclose( file );

  buffer[length] = '\0';

  isDataLoaded = true;
  return true;
}

bool File::load( const std::string& _fileName ){
  if( _fileName == "" )
    return false;
  // Seteo el nombre del archivo
  name = _fileName;
  // Cargo el archivo
  load(  );
  return true;
}

char* File::getData(  ) const{
  return buffer;
}
//-----------------------------------------------------------------
std::string getExtension( const std::string& _buffer ){
  std::string format;
  uint i=0;
  const uint bufferlength = (uint)_buffer.length(  );
  
  while( i<bufferlength ){
    if( _buffer[i] == '.' ){
      i++;
      while( i<bufferlength ){
        format.push_back( _buffer[i] );
        i++;
      }
      break;
    }
    i++;
  }
  
  return format;
}
//-----------------------------------------------------------------
NAMESPACE_END( GameEngine );
