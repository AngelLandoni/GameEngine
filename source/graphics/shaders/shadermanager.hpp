//
//  shadermanager.hpp
//  GameEngine
//
//  Created by Angel Land on 11/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

/*
 * Cambiar la carga de shades al shader manager
 * para optimizar RAM.
 */

#ifndef __GAMEENGINE_SHADERMANAGER_HPP__
#define __GAMEENGINE_SHADERMANAGER_HPP__

#include <string>
#include <vector>

#include "../../utils/helpers.hpp"

#include "shader.hpp"

NAMESPACE_BEGIN( GameEngine );

#define ShaderManagerInstance ShaderManager::getInstance(  )

class ShaderManager{
  std::vector<Shader*> _mShaders;
  std::vector<std::string> _mShadersNames;
public:
  static ShaderManager& getInstance(  );
  
  Shader* operator[](const uint _index);
  
  Shader* createProgram(const std::string& _programName,
                        const std::string& _fileName );
  
  Shader* createProgram(const std::string& _programName,
                        const std::string& _vertex,
                        const std::string& _fragment);
  
  Shader* get( const std::string& _nameProgram );
  std::vector<Shader*> getShaders(  );
  
  uint getLength(  );

  bool remove( const std::string& _programName  );
protected:
  ShaderManager(  );
  virtual ~ShaderManager(  );
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_SHADERMANAGER_HPP__ */
