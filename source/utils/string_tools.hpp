//
//  string_tools.hpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_STRING_HPP__
#define __GAMEENGINE_STRING_HPP__

#include "helpers.hpp"

#include <string>
#include <vector>

NAMESPACE_BEGIN( GameEngine );

std::vector<std::string> explode( const std::string& _s, char _token );


NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_STRING_HPP__ */
