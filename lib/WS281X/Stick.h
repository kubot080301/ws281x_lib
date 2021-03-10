#include "Neo_Patterns.h"

void Stick1_Complete();
void Stick2_Complete();
void Stick3_Complete();
void Stick4_Complete();

Neo_Patterns Stick1(16, 5, NEO_GRB + NEO_KHZ800, &Stick1_Complete);
Neo_Patterns Stick2(25, 6, NEO_GRB + NEO_KHZ800, &Stick2_Complete);
Neo_Patterns Stick2(25, 7, NEO_GRB + NEO_KHZ800, &Stick3_Complete);
Neo_Patterns Stick2(25, 8, NEO_GRB + NEO_KHZ800, &Stick4_Complete);


void Stick1_Complete()
{
  
}

void Stick2_Complete()
{
   
}

void Stick3_Complete()
{
   
}

void Stick4_Complete()
{
   
}