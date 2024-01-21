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
#ifndef __USART_H_
#define __USART_H_

namespace usart
{

class UsartBuffer
{
private:
	const int BUFFER_SIZE = 128;
	char buffer_[BUFFER_SIZE];
	int rp_;
	int wp_;

public:
  inline UsartBuffer():
  buffer({})
  {
  }

};

}
#endif /* __USART_H_ */

