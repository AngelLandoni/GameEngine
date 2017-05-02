//
//  string_tools.cpp
//  GameEngine
//
//  Created by Angel Land on 14/1/16.
//  Copyright © 2016 Angel Land. All rights reserved.
//

#include "string_tools.hpp"

NAMESPACE_BEGIN( GameEngine );


std::vector<std::string> explode( const std::string& _s, char _token ){
  std::vector<std::string> result;
  std::string word;
  
  uint i=0;
  const uint lengthString = (uint)_s.length(  );
  
  while( i<=lengthString ){
    if( _s[i] == _token || i == lengthString ){
      result.push_back( word );
      word = "";
    }else
      word += _s[i];
    i++;
  }
  return result;
}


NAMESPACE_END( GameEngine );