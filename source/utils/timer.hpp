//
//  timer.hpp
//  GameEngine
//
//  Created by Angel Land on 28/12/15.
//  Copyright © 2015 Angel Land. All rights reserved.
//

#ifndef __GAMEENGINE_TIMER_HPP__
#define __GAMEENGINE_TIMER_HPP__

#include <chrono>

#include "helpers.hpp"

NAMESPACE_BEGIN( GameEngine );

class Timer{
protected:
  std::chrono::time_point< std::chrono::high_resolution_clock > _mSStart,_mTimerPrev;
public:
  Timer( );
  virtual ~Timer(  );
  void init(  );

  void reset(  );
  double elapsed(  );
  double delta(  );

  double getCurrentTime(  );
  
};


NAMESPACE_END( GameEngine );

#endif /* __GAMEENGINE_TIMER_HPP__ */
