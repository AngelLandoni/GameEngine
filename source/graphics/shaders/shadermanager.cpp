//
//  shadermanager.cpp
//  GameEngine
//
//  Created by Angel Land on 11/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "shadermanager.hpp"

NAMESPACE_BEGIN( GameEngine );

ShaderManager::ShaderManager(  ){  }

ShaderManager::~ShaderManager(  ){
  const uint shadersLength = (uint)_mShaders.size(  );
  uint i=0;
  while (i<shadersLength){
    Shader* item = _mShaders[i];
    if( item == nullptr )
      delete item;
    i++;
  }
}

ShaderManager& ShaderManager::getInstance(  ){
  static ShaderManager instance;
  return instance;
}

Shader* ShaderManager::operator[](const uint _index){
  return _mShaders[_index];
}

Shader* ShaderManager::createProgram(const std::string &_programName,
                                     const std::string &_fileName ){
  uint i = 0;
  const uint lengthVector = (uint)_mShaders.size(  );
  
  while( i<lengthVector ){
    if( _mShadersNames[i] == _programName )
      return _mShaders[i];
    i++;
  }
  
  Shader* newshader = new Shader(  );
  newshader->load( _fileName );
  
  _mShaders.push_back( newshader );
  _mShadersNames.push_back( _programName );
  
  return newshader;
}

Shader* ShaderManager::createProgram(const std::string& _programName,
                      const std::string& _vertex,
                      const std::string& _fragment){
  uint i = 0;
  const uint lengthVector = (uint)_mShaders.size(  );
  
  while( i<lengthVector ){
    if( _mShadersNames[i] == _programName )
      return _mShaders[i];
    i++;
  }

  Shader* newshader = new Shader(  );
  newshader->create( _vertex,_fragment );
  
  _mShaders.push_back( newshader );
  _mShadersNames.push_back( _programName );
  
  return newshader;
}

Shader* ShaderManager::get(const std::string &_programName){
  uint i = 0;
  const uint lengthVector = (uint)_mShaders.size(  );
  
  while( i<lengthVector ){
    if( _mShadersNames[i] == _programName )
      return _mShaders[i];
    i++;
  }
  
  return nullptr;
}

uint ShaderManager::getLength(  ){
  return (uint)_mShaders.size(  );
}

bool ShaderManager::remove(const std::string &_programName){
  uint i = 0;
  const uint lengthVector = (uint)_mShaders.size(  );
  
  while( i<lengthVector ){
    if( _mShadersNames[i] == _programName ){
      _mShadersNames.erase( _mShadersNames.begin(  )+i );
      delete _mShaders[i];
      _mShaders.erase( _mShaders.begin( ) + i );
      return true;
    }
    i++;
  }
  return false;
}

std::vector<Shader*> ShaderManager::getShaders(){
  return _mShaders;
}

NAMESPACE_END( GameEngine );