//
//  helpers.hpp
//  GameEngine
//
//  Created by Angel Land on 9/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_HELPERS_HPP__
#define __GAMEENGINE_HELPERS_HPP__

#ifndef NAMESPACE_BEGIN
#define NAMESPACE_BEGIN( name ); namespace name{
#endif

#ifndef NAMESPACE_END
#define NAMESPACE_END( name ); }
#endif

#define GLSL(version, shader)  "#version " #version "\n" #shader

typedef unsigned int uint;
typedef unsigned short ushort;

#endif /* __GAMEENGINE_HELPERS_HPP__ */
