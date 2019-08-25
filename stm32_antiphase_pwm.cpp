/* 
 * File:    stm32_antiphase_pwm.cpp
 * version: ver01.00 (2019/06/27)
 * Author:  SIVA
 *
 * Created on 2019/06/27, 21:20
 */

#include "stm32_antiphase_pwm.hpp"

static void set_ccr_register(TIM_HandleTypeDef *htim, uint32_t channel,uint32_t pulse);

Stm32AntiphasePwm::Stm32AntiphasePwm(TIM_HandleTypeDef *htim, uint32_t channel_a, uint32_t channel_b) {
    this->htim = htim;
    this->channel_a = channel_a;
    this->channel_b = channel_b;

    set_ccr_register(htim, channel_a, PWM_DUTY_ZERO);
    set_ccr_register(htim, channel_b, PWM_DUTY_ZERO);

    HAL_TIM_PWM_Start(htim, channel_a);
    HAL_TIM_PWM_Start(htim, channel_b);
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
    set_ccr_register(htim, channel_a, PWM_DUTY_ZERO + difference);
    set_ccr_register(htim, channel_b, PWM_DUTY_ZERO - difference);

    return retval;
}

void set_ccr_register(TIM_HandleTypeDef *htim, uint32_t channel,uint32_t pulse)
{
    switch (channel)
    {
    case TIM_CHANNEL_1:
        htim->Instance->CCR1 = pulse;
        break;

    case TIM_CHANNEL_2:
        htim->Instance->CCR2 = pulse;
        break;

    case TIM_CHANNEL_3:
        htim->Instance->CCR3 = pulse;
        break;

    case TIM_CHANNEL_4:
        htim->Instance->CCR4 = pulse;
        break;

    default:
        break;
    }

    return;
}
