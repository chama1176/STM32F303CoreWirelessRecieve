/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : usart.h
  * @brief          : Header library for uart data receive.
  ******************************************************************************
  * @attention
  *
  * @Chama1176 All rights reserved.
  *
  *
  ******************************************************************************
  */
/* USER CODE END Header */


/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __CORE_WIRELESS_CONTROL_RX_H_
#define __CORE_WIRELESS_CONTROL_RX_H_

#include "usart.hpp"

class CoreWirelessControlRx
{
private:
	UsartBuffer *usart_;
	int16_t axis_[5] = {};
	bool buttons_[8] = {};
	char test_;

public:
  CoreWirelessControlRx(UsartBuffer * usart)
  {
	  usart_ = usart;
  }
  bool parse(){

    // parse when buffer has new line code
    if(usart_->nl_count() <= 0){
    	return false;
    }
    char data[40] = {};
    uint32_t len = usart_->get_line(data, 40);
    if(len < 35){
     return false;
    }
    uint32_t idx = 0;
    while(1){
	  if(len < idx + 35){
		 return false;
	  }
	  if(data[idx] == '0' && data[idx+1] == '0' && data[idx+34] == '\r') {
        test_ = 'k';
	    return true;
	  } else{
		++idx;
		continue;
	  }
	}
	return true;
  }
  uint8_t test(){
	  char tmp = test_;
	  test_ = '\r';
	  return tmp;
  }

};


#endif /* __CORE_WIRELESS_CONTROL_RX_H_ */

