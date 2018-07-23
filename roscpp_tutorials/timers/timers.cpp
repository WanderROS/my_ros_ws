/*
 * Copyright (C) 2008, Morgan Quigley and Willow Garage, Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *   * Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *   * Neither the names of Stanford University or Willow Garage, Inc. nor the
 * names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

// %Tag(FULLTEXT)%
#include "ros/ros.h"
#include <ros/console.h>
#include <signal.h>
/**
 * This tutorial demonstrates the use of timer callbacks.
 */

class Foo {
public:
  void callback(const ros::TimerEvent &event) { ROS_INFO("Foo call back!"); }
  void operator()(const ros::TimerEvent &event) { ROS_INFO("Foo functor!"); }
};

void call_wallback(const ros::WallTimerEvent &event) {

  ROS_INFO("wall timer!");
  // ros::shutdown();
}
void callback1(const ros::TimerEvent &event) {

  double sec = 0;
  sec = ros::Time::now().toSec();
  //  ROS_WARN("last real :%f",sec);
  sec = event.current_real.toSec();
  ROS_DEBUG("Hello %s", "World");
  ROS_DEBUG_STREAM("Hello "
                   << "World");
  // ROS_WARN("last expected :%f",sec);
  // ROS_INFO("Callback 1 triggered");
}

void callback2(const ros::TimerEvent &) { ROS_INFO("Callback 2 triggered"); }

void mySigIntHandler(int sig) {
  ROS_ERROR("CTRL -C !");
  ros::shutdown();
}

int main(int argc, char **argv) {
  //,ros::init_options::NoSigintHandler
  ros::init(argc, argv, "talker");
  ros::NodeHandle n("/mynamespace");
  ros::NodeHandle n2("/mynamespace2");
  signal(SIGINT, mySigIntHandler);
  /**
   * Timers allow you to get a callback at a specified rate.  Here we create
   * two timers at different rates as a demonstration.
   */
  // %Tag(CREATE_TIMERS)%

  ros::Timer timer1 = n.createTimer(ros::Duration(1.0), callback1);

  ros::Timer timer2 = n.createTimer(ros::Duration(1.0), callback2, true);
  // %EndTag(CREATE_TIMERS)%
  Foo foo_object;
  ros::Timer timer3 =
      n.createTimer(ros::Duration(1.0), &Foo::callback, &foo_object);
  ros::Timer timer4 = n.createTimer(ros::Duration(1.0), Foo());
  timer1.setPeriod(ros::Duration(2.0));

  // wall-clock
  ros::WallTimer timer5 =
      n2.createWallTimer(ros::WallDuration(10), call_wallback);

  ros::MultiThreadedSpinner spinner(4); // use 4 threads

  spinner.spin();

  return 0;
}
// %EndTag(FULLTEXT)%
