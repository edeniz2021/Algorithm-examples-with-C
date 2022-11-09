#ifndef _UTIL_H_
#define _UTIL_H_

#define CLOSE_ENOUGH 0.001

/* Example decision tree - see the HW2 description */
int dt0(int t, double p, double h, char s, int w);

char dt1a(float x,float y,float z,float t);
char dt1b(float x,float y,float z,float t);

double dt2a(double x1,double x2,double x3,int x4,int x5);
double dt2b(double x1,double x2,double x3,int x4,int x5);

/* Write the prototype of the functions implementing the decision trees for the third problem */

void dt3a(double s,double n,float w,float b,int g,char c,int type,int con);
void dt3b(double s,double n,float w,float b,int g,char c,int type,int con);

#endif /* _UTIL_H_ */
