//
//  testcube.hpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_TESTCUBE_HPP__
#define __GAMEENGINE_TESTCUBE_HPP__

#include "../../../utils/helpers.hpp"
#include "../../../object.hpp"
#include "../mesh.hpp"

NAMESPACE_BEGIN( GameEngine );

class TestCube : public Mesh , public Object{
public:
  TestCube(  );
  virtual ~TestCube(  );
};


NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_TESTCUBE_HPP__ */
