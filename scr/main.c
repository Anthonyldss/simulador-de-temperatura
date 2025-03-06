#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

//funcao PID

 double controlPID(double current_temp, double *integral, double *previous_error)
{
        double error = SET_POINT - current_temp;
        *integral += error;
        double derivative = error - *previous_error;

        //calculo do PID
        double output = Kp * error + Ki * (*integral) + Kd * derivative;

        *previous_error = error;
        return output;  
}
int main()
{

}
