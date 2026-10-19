#include <math.h>
#include "trigrec.h"
#define PI 3.14159265358979323846

void trigrec0 (int k, double x, struct coefcs cfs[]) {
    cfs[0].c=1;
    cfs[0].s=0;
    for(int j=1; j<k+1; j++){
        cfs[j].c=cos(j*x);
        cfs[j].s=sin(j*x);
    }
}

void trigrec1 (int k, double x, struct coefcs cfs[]) {
    cfs[0].c=1;
    cfs[0].s=0;

    cfs[1].c=cos(x);
    cfs[1].s=sin(x);
    for(int j=1; j<k; j++){
        cfs[j+1].c=2*cfs[1].c*cfs[j].c - cfs[j-1].c;
        cfs[j+1].s=2*cfs[1].c*cfs[j].s - cfs[j-1].s;
    }
}

void trigrec2 (int k, double x, struct coefcs cfs[]) {
    cfs[0].c=1;
    cfs[0].s=0;

    cfs[1].c=cos(x);
    cfs[1].s=sin(x);

    for(int j=1; j<k; j++){
        cfs[j+1].c=cfs[1].c*cfs[j].c - cfs[1].s*cfs[j].s;
        cfs[j+1].s=cfs[1].s*cfs[j].c + cfs[1].c*cfs[j].s;
    }
}

void trigrec3 (int k, double x, struct coefcs cfs[]) {
    double t;
    double delta_c, delta_s;
    
    delta_c=-2*sin(x/2)*sin(x/2); //no pow n%2 ? -1:1, no trunc floor
    t=2*delta_c;
    delta_s = ((int)floor(x / PI) % 2 ? -1 : 1) * sqrt(-delta_c * (2 + delta_c));

    
    cfs[0].c=1;
    cfs[0].s=0;
    
    for(int j=1; j<k+1; j++){
        cfs[j].c=cfs[j-1].c + delta_c;
        delta_c=t*cfs[j].c + delta_c;

        cfs[j].s=cfs[j-1].s + delta_s;
        delta_s=t*cfs[j].s + delta_s;
    }
}