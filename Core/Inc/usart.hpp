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
	static constexpr uint32_t BUFFER_SIZE = 128;	// 2
	char buffer_[BUFFER_SIZE] = {};
	uint32_t rp_;
	uint32_t wp_;

public:
  inline UsartBuffer()
  : rp_(0)
  , wp_(0)
  {
  }
  bool enqueue(char data){
	  if(((wp_ - rp_) & (BUFFER_SIZE-1)) == (BUFFER_SIZE-1)){
		  return false;
	  }
	  buffer_[wp_] = data;
	  inc_wp();
	  return true;
  }
  void inc_wp(){
	  wp_ = (++wp_) & (BUFFER_SIZE-1);
  }
  void inc_rp(){
	  rp_ = (++rp_) & (BUFFER_SIZE-1);
  }
  bool pop(char & data){
	  if(rp_ == wp_){
		  data = 0;
	  }
	  data = buffer_[rp_];
	  inc_rp();
  }

};

}
#endif /* __USART_H_ */

