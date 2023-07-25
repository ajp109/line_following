struct Line {
    float position;
    float speed;
    Line() {
        position = speed = 0.0;
    }
};

struct Robot {
    float speed;
    float turnspeed;
    Robot() {
        speed = turnspeed = 0.0;
    }
};

void control(Line const & line, Robot & robot);
