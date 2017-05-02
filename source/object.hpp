//
//  object.hpp
//  GameEngine
//
//  Created by Angel Land on 27/12/15.
//  Copyright © 2015 Angel Land. All rights reserved.
//

#ifndef __MUSHROOM_OBJECT_HPP__
#define __MUSHROOM_OBJECT_HPP__

#include <atomic>

#include "utils/helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

class Object{
protected:
  // ID unico del objeto
  std::atomic<unsigned int> _mId;
public:
  Object(  );
  virtual ~Object(  );
  virtual unsigned int getId(  );
  virtual unsigned int getNumObjects(  ) const;
  // VARS
  static std::atomic< unsigned int > numberObjects;
};


NAMESPACE_END( GameEngine );

#endif /* object_hpp */
