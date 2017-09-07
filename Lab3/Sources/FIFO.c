/*
 * FIFO.c
 *
 *  Created on: Aug 31, 2017
 *      Author: macro
 */

#include "types.h"
#include "FIFO.h"

#define FIFO_SIZE 256

void FIFO_Init(TFIFO * const FIFO){

 FIFO->NbBytes=0;	//Set R, W, Size position
 FIFO->read = 0;
 FIFO->write = 0;
 FIFO->Buffer[FIFO_SIZE];
}


bool FIFO_Put(TFIFO * const FIFO, const uint8_t data){

      if(FIFO->write+1 == FIFO->read){
	  if((FIFO->write + 1 == FIFO->NbBytes) && (FIFO->read == 0)){
	      return (0); //Check if full
	  }
  }else{
      FIFO->Buffer[FIFO->write] = data;
      FIFO->write++;
      FIFO->NbBytes++;
      if(FIFO->write==FIFO_SIZE){
	  FIFO->write = 0;
      }
      return (1);
  }
}




bool FIFO_Get(TFIFO * const FIFO, uint8_t * const dataPtr){

      if(FIFO->read != FIFO->write){

	  *dataPtr = FIFO->Buffer[FIFO->read];

	  if(FIFO->read == FIFO_SIZE){

	      FIFO->read = 0;
	  }
	  FIFO->read++;
	  FIFO->NbBytes--;

	  return (1);
	}else{
	  return(0); //If read and write are same, there is no data
	  }
}





