#include "mbed.h"
#include "m3pi.h"
#include "robot.h"

m3pi platform;

float dt = 0.005;

static void harness(void) {
    static Robot robot;
    static Line line;
    static float e = platform.line_position();
    static const float r = 0.041;
    float new_e = platform.line_position();
    float de_dt = (new_e - e) / dt;
    e = new_e;
    float speed = 0.0, turn = 0.0;
    line.position = e;
    line.speed = de_dt;
    control(line, robot);
    platform.left_motor(robot.speed+r*robot.turnspeed);
    platform.right_motor(robot.speed-r*robot.turnspeed);
}

int main() {
    platform.sensor_auto_calibrate();
    static Ticker t;
    t.attach(harness, dt);
    while(1);
}
