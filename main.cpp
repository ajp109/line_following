#include "mbed.h"
#include "m3pi.h"
#include "robot.h"

m3pi platform;

static const float r = 0.041;
static const float dt = 0.005;

static inline float clamp(float val, float maxval) {
    if (val>=0) {
        return (val>maxval) ? maxval : val;
    }
    return -clamp(-val, maxval);
}

static void harness(void) {
    static Robot robot;
    static Line line;
    static float e = platform.line_position();
    float new_e = platform.line_position();
    float de_dt = (new_e - e) / dt;
    e = new_e;
    line.position = e;
    line.speed = de_dt;
    control(line, robot);
    float delta = clamp(r*robot.turnspeed, 1.0f);
    float speed = clamp(robot.speed, 1.0f-fabs(delta));
    platform.left_motor(speed+delta);
    platform.right_motor(speed-delta);
}

int main() {
    platform.sensor_auto_calibrate();
    static Ticker t;
    t.attach(harness, dt);
    while(1);
}
