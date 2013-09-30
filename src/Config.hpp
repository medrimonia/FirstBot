#ifndef CONFIG_HPP
#define CONFIG_HPP

/* 0 -> No print
 * 1 -> Print tagged image
 * 2 -> Print main analysis
 * 3 -> Print all
 */
#define DETAIL_LEVEL 0 

/* The part of the image corresponding to a color needed to say that an object
 * of this color has been seen.
 */
#define DETECTION_PART_THRESHOLD 0.04

/* Threshold for stopping when green is locked */
#define TOO_CLOSE_THRESHOLD 0.5

/* The maximal dist to center for an object to be considered as locked
 */
#define ANGLE_THRESHOLD 0.2

#define BACKWARD_SPEED -0.5
#define FORWARD_SPEED   0.5

//#define HIGH_QUALITY

#ifdef HIGH_QUALITY
  #define FRAME_WIDTH  640
  #define FRAME_HEIGHT 480
#else
  #define FRAME_WIDTH  160
  #define FRAME_HEIGHT 120
#endif

#endif
