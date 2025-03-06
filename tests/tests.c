#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "config.h" //configuracoes, como as constantes PID e SET_POIN
#include <unistd.h>

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
        double current_temp = 20.0; //temp inicial
        double integral = 0.0;
        double previous_error = 0.0;

        //simulacao do controle de temp.
        for (int i = 0; i < 100; i++)
        {
                //controlar a temp
                double control_signal = controlPID(current_temp, &integral, &previous_error);

                //ajustar a temp com base no sinal de controle
                current_temp += control_signal * 0.1; //modificar a temp com base no controle(fator de escala)

                //simular o sistema com uma pequena pausa

                printf("tempo: %d s | temperatura %.2f°c\n", i, current_temp);

                //atrasos de 1 segundo para a simulacao
                sleep(1);
        }

        return 0;
}
