/* 
 * File:    stm32_antiphase_pwm.hpp
 * version: ver01.00 (2019/06/27)
 * Author:  SIVA
 *
 * Created on 2019/06/27/, 20:55
 */

#ifndef STM32_ANTIPHASE_PWM_HPP_
#define STM32_ANTIPHASE_PWM_HPP_

#include "main.h"

class Stm32AntiphasePwm {
    private:
        TIM_HandleTypeDef *htim;
        uint32_t channel_a;
        uint32_t channel_b;

    public:
        Stm32AntiphasePwm(TIM_HandleTypeDef *htim, uint32_t channel_a, uint32_t channel_b);
        ~Stm32AntiphasePwm();

        int update_duty(double duty_rate);
};

class Stm32AntiphasePwmN : public Stm32AntiphasePwm {
    private:

    public:
        Stm32AntiphasePwmN(TIM_HandleTypeDef *htim, uint32_t channel_a, uint32_t channel_b);
        ~Stm32AntiphasePwmN();
};

#endif /* STM32_ANITPHASE_PWM_HPP_ */
