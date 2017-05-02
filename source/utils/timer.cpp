//
//  timer.cpp
//  MushRoom
//
//  Created by Angel Land on 28/12/15.
//  Copyright © 2015 Angel Land. All rights reserved.
//

#include "timer.hpp"

NAMESPACE_BEGIN( GameEngine );

Timer::Timer(  ){}
Timer::~Timer(  ){}

void Timer::init(  ){
  _mSStart = _mTimerPrev = std::chrono::high_resolution_clock::now(  );
}

void Timer::reset(  ){
  _mSStart = std::chrono::high_resolution_clock::now(  );
}

double Timer::elapsed( ){
  return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - _mSStart ).count() / 1000.0f;
}

double Timer::delta( ){
  auto timeCurrent = std::chrono::high_resolution_clock::now();
  auto timeDiff = std::chrono::duration_cast< std::chrono::milliseconds >( timeCurrent - _mTimerPrev );
  
  double delta = timeDiff.count();
  
  delta /= 1000000000;
  
  _mTimerPrev = timeCurrent;
  return delta;
}

NAMESPACE_END( GameEngine );