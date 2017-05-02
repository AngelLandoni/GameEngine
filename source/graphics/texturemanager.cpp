//
//  texturemanager.cpp
//  MushRoom
//
//  Created by Angel Land on 3/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "texturemanager.hpp"

NAMESPACE_BEGIN( GameEngine );

TextureManager::TextureManager(  ){  }

TextureManager::~TextureManager(  ){
  const uint texturesLength = (uint)_mTextures.size(  );
  uint i=0;
  while (i<texturesLength){
    Texture* item = _mTextures[i];
    if( item != nullptr )
      delete item;
    i++;
  }
}

TextureManager& TextureManager::getInstance(  ){
  static TextureManager instance;
  return instance;
}

Texture* TextureManager::load(const std::string &_name, const std::string &_path){
  uint i=0;
  const uint lengthVector = (uint)_mTexturesNames.size(  );
  
  while( i<lengthVector ){
    if( _mTexturesNames[i] == _name )
      return _mTextures[i];
    i++;
  }
  
  _mTexturesNames.push_back( _name );
  Texture* newTexture = new Texture(  );
  newTexture->_mPath = _path;
  
  // search format
  std::string format;
  i=0;
  const uint pathlength = (uint)_path.length(  );
  while( i<pathlength ){
    if( _path[i] == '.' ){
      i++;
      while( i<pathlength ){
        format.push_back( _path[i] );
        i++;
      }
      break;
    }
    i++;
  }
  
  std::ifstream file( _path.c_str(),std::ifstream::binary );
  
  if( format == "tga" || format == "TGA" ){
    // Cargo los datos de la cabezera en
    TGAHeader* head = getTGAHead( file );
    // Obtengo el ancho
    memcpy( &newTexture->_mWidth,&head->width[0],2 );
    // Obtengo el alto
    memcpy( &newTexture->_mHeight,&head->height[0],2 );
    // Obtengo el bpp
    newTexture->_mBpp = (unsigned char)head->pixelSize;
    // Seteo el tamaño de los pixeles de la imagen
    newTexture->_mDataSize = newTexture->_mWidth*newTexture->_mHeight*( newTexture->_mBpp/8 );
    // Seteo los datos
    newTexture->_mImageData = new GLubyte[ newTexture->_mDataSize ];
    file.read( (char*)newTexture->_mImageData,newTexture->_mDataSize );
    
    // No flip?
    /*
    if( newTexture->_mBpp == 32 ){
      flipRGBAData( newTexture->_mImageData,newTexture->_mDataSize );
      flipRGBAData(newTexture->_mImageData, newTexture->_mDataSize);
    }else if( newTexture->_mBpp == 24 ){
      flipRGBData( newTexture->_mImageData,newTexture->_mDataSize );
    }*/
    
    delete head;
  }
  
  _mTextures.push_back( newTexture );
  
  glGenTextures( 1 , &newTexture->_mTextureID );
  glBindTexture( GL_TEXTURE_2D ,newTexture->_mTextureID );
  
  // Comportamiento de la textura
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
  
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  
  
  
  if(  newTexture->_mBpp == 32 )
    glTexImage2D(GL_TEXTURE_2D ,
                 0,
                 GL_RGBA,
                 newTexture->_mWidth,
                 newTexture->_mHeight,
                 0,
                 GL_BGRA,
                 GL_UNSIGNED_BYTE,
                 newTexture->_mImageData );
  else if(  newTexture->_mBpp == 24 )
    glTexImage2D( GL_TEXTURE_2D ,
                 0,
                 GL_RGBA,
                 newTexture->_mWidth,
                 newTexture->_mHeight,
                 0,
                 GL_BGR,
                 GL_UNSIGNED_BYTE,
                 newTexture->_mImageData );
  
  delete newTexture->_mImageData;
  newTexture->_mImageData = nullptr;
  

  glHint(GL_GENERATE_MIPMAP_HINT, GL_FASTEST);
  glGenerateMipmap(GL_TEXTURE_2D);
  
  glBindTexture(GL_TEXTURE_2D, 0);
  
  return newTexture;
}

Texture* TextureManager::loadCubeMap(
                                     const std::string& _name,
                                     const std::vector<std::string>& _paths){
  uint i=0;
  const uint lengthVector = (uint)_mTexturesNames.size(  );
  
  while( i<lengthVector ){
    if( _mTexturesNames[i] == _name )
      return _mTextures[i];
    i++;
  }
  
  _mTexturesNames.push_back( _name );
  Texture* newTexture = new Texture(  );
  newTexture->_mPath = "cubeMap";
 
  std::string format;
  i=0;
  const uint pathlength = (uint)_paths[0].length(  );
  while( i<pathlength ){
    if( _paths[0][i] == '.' ){
      i++;
      while( i<pathlength ){
        format.push_back( _paths[0][i] );
        i++;
      }
      break;
    }
    i++;
  }
  
  const uint numPaths = (uint)_paths.size(  );

  glGenTextures(1, &newTexture->_mTextureID);
  glBindTexture(GL_TEXTURE_CUBE_MAP, newTexture->_mTextureID);
  i=0;
  while( i<numPaths ){
    std::ifstream file( _paths[i].c_str(),std::ifstream::binary );
    
    if( !file.is_open() )
      std::cout<<"Error on loading: "<<_paths[i].c_str()<<std::endl;
      
    if( format == "tga" || format == "TGA" ){
      // Cargo los datos de la cabezera en
      TGAHeader* head = getTGAHead( file );
      // Obtengo el ancho
      memcpy( &newTexture->_mWidth,&head->width[0],2 );
      // Obtengo el alto
      memcpy( &newTexture->_mHeight,&head->height[0],2 );
      // Obtengo el bpp
      newTexture->_mBpp = (unsigned char)head->pixelSize;
      // Seteo el tamaño de los pixeles de la imagen
      newTexture->_mDataSize = newTexture->_mWidth*newTexture->_mHeight*( newTexture->_mBpp/8 );
      // Seteo los datos
      newTexture->_mImageData = new GLubyte[ newTexture->_mDataSize ];
      file.read( (char*)newTexture->_mImageData,newTexture->_mDataSize );
      
      /*if( newTexture->_mBpp == 32 )
        flipRGBAData( newTexture->_mImageData,newTexture->_mDataSize );
      else if( newTexture->_mBpp == 24 )
        flipRGBData( newTexture->_mImageData,newTexture->_mDataSize );*/
      
      delete head;
    }

    glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, newTexture->_mWidth, newTexture->_mHeight, 0, GL_BGR, GL_UNSIGNED_BYTE, newTexture->_mImageData);
    
    
    i++;
  }
  
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
  glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
  
  
  _mTextures.push_back(newTexture);
  
  return newTexture;
}

Texture* TextureManager::get(const std::string& _name){
  uint i=0;
  const uint lengthvector = (uint)_mTexturesNames.size(  );
  while( i<lengthvector ){
    if( _mTexturesNames[i] == _name )
      return _mTextures[i];
    i++;
  }
  return nullptr;
}

TGAHeader* TextureManager::getTGAHead( std::ifstream& _file ){
  if( !_file )
    return NULL;
  TGAHeader* head = new TGAHeader;
  _file.read( (char*)head,sizeof( TGAHeader ) );
  return head;
}

NAMESPACE_END( GameEngine );




