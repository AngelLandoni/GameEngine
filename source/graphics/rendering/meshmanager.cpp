//
//  meshmanager.cpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "meshmanager.hpp"

NAMESPACE_BEGIN( GameEngine );
//-----------------------------------------------------------------------
MeshManager::MeshManager(  ){  }
//-----------------------------------------------------------------------
MeshManager::~MeshManager(  ){
  for( Mesh* i: _mMeshs ) if( i != nullptr )
    delete i;
}
//-----------------------------------------------------------------------
MeshManager& MeshManager::getInstance(  ){
  static MeshManager instance;
  return instance;
}
//-----------------------------------------------------------------------
Mesh* MeshManager::load(const std::string& _name, const std::string& _path){
  uint i=0;
  const uint lengthvector = (uint) _mMeshsNames.size(  );
  
  Mesh* preloadMesh = nullptr;
  preloadMesh = get( _name );
  if( preloadMesh != nullptr )
    return preloadMesh;
 
  // search format
  std::string format = getExtension( _path );
  
  Mesh* newmesh = new Mesh(  );
  
  // OBJ BEGIN
  if( format == "obj" || format == "OBJ" ){
    MeshData m = loadOBJ( _path );
    
    std::vector<float> v,uv,n;
    
    for( i=0;i<=m._mVertices.size(  );i++ ){
      v.push_back( m._mVertices[i].x );
      v.push_back( m._mVertices[i].y );
      v.push_back( m._mVertices[i].z );
    }
    newmesh->setVertices( v );
    
    for( i=0;i<=m._mUVs.size(  );i++ ){
      uv.push_back( m._mUVs[i].x );
      uv.push_back( m._mUVs[i].y );
    }
    newmesh->setUVs( uv );
    
    const uint nLength = (uint)m._mNormals.size(  );
    for( i=0;i<nLength; i++){
      n.push_back( m._mNormals[i].x );
      n.push_back( m._mNormals[i].y );
      n.push_back( m._mNormals[i].z );
    }
    newmesh->setNormals( n );
    
    
    newmesh->setColors( {
      1.0f,1.0f,1.0f,1.0f,
      1.0f,1.0f,0.0f,1.0f,
      1.0f,0.0f,0.0f,1.0f,
      1.0f,1.0f,0.0f,1.0f,
      1.0f,0.0f,0.0f,1.0f,
      1.0f,1.0f,0.0f,1.0f
    } );
    
    newmesh->setIndices( m._mIndices );
    
    newmesh->init(  );
  }
  // OBJ END

  _mMeshsNames.push_back( _name );
  _mMeshs.push_back( newmesh );
  
  return newmesh;
}
//-----------------------------------------------------------------------
Mesh* MeshManager::makeQuad(const std::string &_name){
  uint i=0;
  const uint lengthvector = (uint) _mMeshsNames.size(  );
  
  while( i<lengthvector ){
    if( _mMeshsNames[i] == _name )
      return _mMeshs[i];
    i++;
  }

  Mesh* newmesh = new Mesh(  );

  MeshData m = _makeQuad();
  
  std::vector<float> v,uv,n;
  
  for( i=0;i<=m._mVertices.size(  );i++ ){
    v.push_back( m._mVertices[i].x );
    v.push_back( m._mVertices[i].y );
    v.push_back( m._mVertices[i].z );
  }
  newmesh->setVertices( v );
  
  for( i=0;i<=m._mUVs.size(  );i++ ){
    uv.push_back( m._mUVs[i].x );
    uv.push_back( m._mUVs[i].y );
  }
  newmesh->setUVs( uv );
  
  const uint nLength = (uint)m._mNormals.size(  );
  for( i=0;i<nLength; i++){
    n.push_back( m._mNormals[i].x );
    n.push_back( m._mNormals[i].y );
    n.push_back( m._mNormals[i].z );
  }
  newmesh->setNormals( n );
  
  
  newmesh->setColors( {
    1.0f,1.0f,1.0f,1.0f,
    1.0f,1.0f,0.0f,1.0f,
    1.0f,0.0f,0.0f,1.0f,
    1.0f,1.0f,0.0f,1.0f,
    1.0f,0.0f,0.0f,1.0f,
    1.0f,1.0f,0.0f,1.0f
  } );
  
  newmesh->setIndices( m._mIndices );
  newmesh->init(  );
  
  _mMeshsNames.push_back( _name );
  _mMeshs.push_back( newmesh );
  
  return newmesh;
}
//-----------------------------------------------------------------------
Mesh* MeshManager::get(const std::string &_name){
  uint i=0;
  const uint lengthvector = (uint) _mMeshsNames.size(  );
  
  while( i<lengthvector ){
    if( _mMeshsNames[i] == _name )
      return _mMeshs[i];
    i++;
  }
  return nullptr;
}
//-----------------------------------------------------------------------
MeshData MeshManager::loadOBJ( const std::string& _path ){
  uint i=0,j=0;
  bool found=false;
  MeshData finalObject;
  
  std::vector<glm::vec3> tempVertices;
  std::vector<glm::vec2> tempUVs;
  std::vector<glm::vec3> tempNormals;
  
  std::vector<uint> tempVerticesIndices;
  std::vector<uint> tempUVsIndices;
  std::vector<uint> tempNormalsIndices;
  
  std::ifstream infile( _path.c_str(  ) );
  
  if( !infile.is_open() ){
    std::cout<<"Error on load file: "<<_path<<std::endl;
    std::cout.flush();
  }
  
  std::string line;
  while (std::getline(infile, line)){
    if( line[0] == '#' || line[0] == 'o' || line[0] == 's' )
      continue;
    
    if( line[0] == 'v' && line[1] == ' ' ){
      std::vector<std::string> parse = explode( line,' ' );
      tempVertices.push_back( glm::vec3(
                                        std::atof(parse[1].c_str(  )),
                                        std::atof(parse[2].c_str(  )),
                                        std::atof(parse[3].c_str(  ))
                                        ));
    }else if( line[0] == 'v' && line[1] == 't' ){
      std::vector<std::string> parse = explode( line,' ' );
      tempUVs.push_back(glm::vec2(
                                  std::atof( parse[1].c_str(  ) ),
                                  std::atof( parse[2].c_str(  ) )
                                  ));
    }else if( line[0] == 'v' && line[1] == 'n' ){
      std::vector<std::string> parse = explode( line,' ' );
      tempNormals.push_back(glm::vec3(
                                      std::atof( parse[1].c_str(  ) ),
                                      std::atof( parse[2].c_str(  ) ),
                                      std::atof( parse[3].c_str(  ) )
                                      ));
    }else if( line[0] == 'f' ){
      std::vector<std::string> parse = explode( line,' ' );
      for( i=1;i<=3;i++ ){
        std::vector<std::string> indices = explode(parse[i],'/');
        tempVerticesIndices.push_back( std::atoi(indices[0].c_str())-1 );
        tempUVsIndices.push_back( std::atoi(indices[1].c_str())-1 );
        tempNormalsIndices.push_back( std::atoi(indices[2].c_str())-1 );
      }
    }
  }

  const uint indicesLength = (uint)tempVerticesIndices.size(  );
  
  i=0;
  while( i<indicesLength ){
    // Selecciono los pares de datos que corresponden entre si
    glm::vec3 tempVertex = tempVertices[ tempVerticesIndices[i] ];
    glm::vec2 tempUv = tempUVs[ tempUVsIndices[i] ];
    tempUv.y = 1 - tempUv.y;
    glm::vec3 tempNormal = tempNormals[ tempNormalsIndices[i] ];
    // end
    
    const uint finalObjectLength = (uint)finalObject._mVertices.size(  );
    
    found =  false;
    j=0;
    while( j<finalObjectLength ){
      if(finalObject._mVertices[j] == tempVertex &&
         finalObject._mUVs[j] == tempUv &&
         finalObject._mNormals[j] == tempNormal ){
        
        finalObject._mIndices.push_back( j );
        found = true;
        break;
      }
      j++;
    }
    
    if( !found ){
      finalObject._mVertices.push_back( tempVertex );
      finalObject._mUVs.push_back( tempUv );
      finalObject._mNormals.push_back( tempNormal );
      
      ushort newindex = finalObject._mVertices.size(  )-1;
      
      finalObject._mIndices.push_back( newindex );

      tempVerticesIndices[j] = newindex;
      tempUVsIndices[j] = newindex;
      tempNormalsIndices[j] = newindex;
    }

    i++;
  }

  return finalObject;
}
//-----------------------------------------------------------------------
MeshData MeshManager::_makeQuad(  ){
  MeshData finalObject;
  
  finalObject._mVertices.push_back({ -1.0, -1.0,  1.0 });
  finalObject._mVertices.push_back({ 1.0, -1.0,  1.0 });
  finalObject._mVertices.push_back({ 1.0,  1.0,  1.0 });
  finalObject._mVertices.push_back({ -1.0,  1.0,  1.0 });
  
  finalObject._mUVs.push_back({0,1});
  finalObject._mUVs.push_back({1,1});
  finalObject._mUVs.push_back({1,0});
  finalObject._mUVs.push_back({0,0});
  
  
  finalObject._mNormals.push_back({0,0,1});
  finalObject._mNormals.push_back({0,0,1});
  
  finalObject._mIndices = {0,1,2,
                           2,3,0};
  
  return finalObject;
}
//-----------------------------------------------------------------------










NAMESPACE_END( GameEngine );