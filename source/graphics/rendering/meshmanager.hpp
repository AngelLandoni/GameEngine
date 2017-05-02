//
//  meshmanager.hpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_MODELMANAGER_HPP__
#define __GAMEENGINE_MODELMANAGER_HPP__

#include <vector>
#include <fstream>

#include <map>

#include "../../utils/file.hpp"

#include "../../utils/helpers.hpp"
#include "../../utils/string_tools.hpp"

#include "mesh.hpp"

NAMESPACE_BEGIN( GameEngine );

#define MeshManagerInstance MeshManager::getInstance(  )

struct MeshData{
  std::vector<glm::vec3> _mVertices;
  std::vector<glm::vec2> _mUVs;
  std::vector<glm::vec3> _mNormals;
  std::vector<GLushort> _mIndices;
};

class MeshManager{
  std::vector<Mesh*> _mMeshs;
  std::vector<std::string> _mMeshsNames;
public:
  static MeshManager& getInstance(  );

  Mesh* load(const std::string& _name,
              const std::string& _path );
  Mesh* makeQuad( const std::string& _name );
  Mesh* get( const std::string& _name );
private:
  MeshManager(  );
  virtual ~MeshManager(  );
  MeshData loadOBJ( const std::string& _path );
  
  MeshData _makeQuad(  );
};

NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_MODELMANAGER_HPP__ */
