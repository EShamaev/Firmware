/*This file is part of the Maslow Control Software.

The Maslow Control Software is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Maslow Control Software is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the Maslow Control Software.  If not, see <http://www.gnu.org/licenses/>.

Copyright 2014-2017 Bar Smith*/

#ifndef system_h
#define system_h

typedef struct {
  byte stop;                  // Stop flag.
  byte pause;                 // Pause flag.
  byte rcvdMotorSettings;     // Motor Settings Status Flag
  byte rcvdKinematicSettings; // Kinematics Settings Status Flag
  float xPosition;            // Cartessian position of XY axes
  float yPosition;            // Cached because calculating position is intensive
  float steps[3];             // Encoder position of axes
} system_t;
extern system_t sys;
extern Axis leftAxis;
extern Axis rightAxis;
extern Axis zAxis;
extern RingBuffer incSerialBuffer;
extern Kinematics kinematics;

bool machineReady();
void finalizeMachineSettings();
void  calibrateChainLengths(String);
void  updateKinematicsSettings(const String&);
void  updateMotorSettings(const String&);
void  setupAxes();
int   getPCBVersion();

#endif