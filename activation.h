#include<math.h>

struct activation {
    double (*f) (double);
    double (*d) (double);
};

typedef struct activation activation;


double calculate_extreme(activation * actv, double learn_rate) {
    double x = 0;
    double slope = actv->d(x);
    double req_slope = .01>learn_rate?learn_rate:.01;
    while(abs(slope) > req_slope) {
        x -= slope*learn_rate;
        slope = actv->d(x);
    }    

    return x;
}