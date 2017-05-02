//
//  testcube.cpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "testcube.hpp"

NAMESPACE_BEGIN( GameEngine );

TestCube::TestCube(  ){
  Mesh(  );
  Object(  );

  setVertices({
    -1.0, -1.0,  1.0,
    1.0, -1.0,  1.0,
    -1.0, 1.0,  1.0,
    1.0, 1.0,  1.0,
    // back
    -1.0, -1.0,  -1.0,
    1.0, -1.0,  -1.0,
    -1.0, 1.0,  -1.0,
    1.0, 1.0, -1.0,
  });
  
  setIndices( {
    // top
    2, 3, 6,
    3, 6, 7,
    // back
    0, 4, 1,
    4, 1, 5,
    // bottom
    4, 6, 5,
    5, 6, 7,
    // left
    0, 2, 4,
    2, 4, 6,
    // right
    1, 3, 5,
    5, 3, 7,
    
    0, 1, 2,
    1, 2, 3,
    
  } );
  
  setColors( {
    1.0f,1.0f,1.0f,1.0f,
    1.0f,1.0f,0.0f,1.0f,
    1.0f,0.0f,0.0f,1.0f,
    1.0f,1.0f,0.0f,1.0f,
    0.0f,1.0f,1.0f,1.0f,
    0.0f,0.0f,1.0f,1.0f,
    1.0f,0.1f,0.0f,1.0f,
    0.0f,1.0f,0.0f,1.0f
  } );
  
  setUVs({
    0.0f,0.0f,
    1.0f,0.0f,
    0.0f,1.0f,
    1.0f,1.0f,
    
    0.0f,0.0f,
    1.0f,0.0f,
    0.0f,1.0f,
    1.0f,1.0f,
    
  });
  
}

TestCube::~TestCube(  ){}

NAMESPACE_END( GameEngine );