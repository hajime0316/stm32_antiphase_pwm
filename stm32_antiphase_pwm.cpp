/* 
 * File:    stm32_antiphase_pwm.cpp
 * version: ver01.00 (2019/06/27)
 * Author:  SIVA
 *
 * Created on 2019/06/27, 21:20
 */

#include "stm32_antiphase_pwm.hpp"

Stm32AntiphasePwm::Stm32AntiphasePwm(const TIM_HandleTypeDef *htim) {
    this->htim = htim;
    htim->Instance->CCR1 = PWM_DUTY_ZERO;
    htim->Instance->CCR2 = PWM_DUTY_ZERO;
}
Stm32AntiphasePwm::~Stm32AntiphasePwm() {

}

int Stm32AntiphasePwm::update_duty(double duty_rate){
    int retval = 0;
    
    if(duty_rate > 1) {
        duty_rate = 1;
        retval = 1;
    }
    else if(duty_rate < -1) {
        duty_rate = -1;
        retval = 1;
    }
    
    double difference;
    difference = PWM_DUTY_MAX * duty_rate;
    htim->Instance->CCR1 = PWM_DUTY_ZERO + difference;
    htim->Instance->CCR2 = PWM_DUTY_ZERO - difference;

    return retval;
}