#ifndef ENCODERS_H
#define ENCODERS_H

extern volatile long countLeft;
extern volatile long countRight;

void setupEncoder();

void IRAM_ATTR addLeft();
void IRAM_ATTR addRight();

#endif