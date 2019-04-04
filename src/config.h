/* NOTE:
 * This file is generated by CMake using config.h.in template. Any changes made
 * to config.h will be lost at compile time. Please edit config.h.in file.
 */
#ifndef  config_h_INC
#define  config_h_INC

#include "protocol.h"

#define         CS_TYPE             ''
#define         SESSION_NUM         1
#define         ANIMAL_NAME         "k3"

// Pins etc.
#define         ROTARY_ENC_A                2 
#define         ROTARY_ENC_B                3 
#define         TONE_PIN                    8
#define         LED_PIN                     9
#define         SHOCK_PIN                   10

// These pins are more than 7.
#define         CAMERA_TTL_PIN              10
#define         PUFF_PIN                    11
#define         IMAGING_TRIGGER_PIN         13

#define         SENSOR_PIN                  A5

#define         TONE_FREQ                   4500

#define         PUFF_DURATION               50
#define         TONE_DURATION               50
#define         LED_DURATION                50

#define         MOTION1_PIN                 6
#define         MOTION2_PIN                 7


// Motion detection based on motor
#define         MOTOR_OUT              A1

// What kind of stimulus is given.
#define         SOUND                   0
#define         LIGHT                   1
#define         MIXED                   2

#endif /* end of include guard: config_h_INC */
