struct point {
    int x;
    int y;
    point * next_point_x;
    point * next_point_y;
};

struct axis_point
{
    int value;
    axis_point * next_axis_point;
    point * point;
};


struct origin {
    axis_point * x;
    axis_point * y;    
};

typedef struct point point;
typedef struct axis_point axis_point;
typedef struct origin origin;

