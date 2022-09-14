/*
 * BIT_MATH.h
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BET(VAR,BITNO) VAR |= (1<< (BITNO))
#define CLR_BET(VAR,BITNO) VAR &= ~(1<< (BITNO))
#define TOG_BET(VAR,BITNO) VAR ^= (1<< (BITNO))
#define GET_BET(VAR,BITNO) (VAR >> (BITNO) & 0x01)


#endif /* BIT_MATH_H_ */