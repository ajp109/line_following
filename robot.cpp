#include "robot.h"

void control(Line const & line, Robot &robot) {
    robot.speed = 0.3;      // metres per second, between 0 and 1
    robot.turnspeed = 0;    // radians per second, between -25 and +25 ish
}
