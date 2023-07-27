#include "robot.h"

void control(Line const & line, Robot &robot) {
    /* Available information:
        line.position
            The position of the line relative to the robot, arbitrary units, between -1 and +1
        line.speed
            The rate of change of the line position with respect to time
    */
    robot.speed = 0.1;      // metres per second, between 0 and 1
    robot.turnspeed = 0;    // radians per second, between -25 and +25 ish
}
