#ifndef TRIGREC_H
#define TRIGREC_H

struct coefcs {
    double c;  // camp per al cosinus
    double s;  // camp per al sinus
};

void trigrec0(int k, double x, struct coefcs cfs[]);
void trigrec1(int k, double x, struct coefcs cfs[]);
void trigrec2(int k, double x, struct coefcs cfs[]);
void trigrec3(int k, double x, struct coefcs cfs[]);

#endif // TRIGREC_H
