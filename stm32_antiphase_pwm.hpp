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
        const TIM_HandleTypeDef *htim;

    public:
        Stm32AntiphasePwm(const TIM_HandleTypeDef *htim);
        ~Stm32AntiphasePwm();

        int update_duty(double duty_rate);
};

#endif /* STM32_ANITPHASE_PWM_HPP_ */
