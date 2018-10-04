#include <stdio.h>

typedef struct neurona{
  float weight;
  float bias;
  float init;
  float res;
} neurona;

float max (float num){
  float maxim = 0;
  if(num>0)
    maxim = num;
  return maxim;
}
int forwardFeeding (float in[2]){
  neurona neuralN[2][2];
  int cont, layers, pos, cNeuron;

  // Inicializar valores
  for (cont=0; cont<2; cont++){
    neuralN[0][cont].init = in[cont];
    neuralN[0][cont].weight = 0;
    neuralN[0][cont].bias = 0;
    neuralN[0][cont].res = 0;
  }

  // Inicializar weights y biases
  for(cont=0; cont<2; cont++){
    neuralN[1][cont].weight = 1.6 * (cont+1);
    neuralN[1][cont].bias = 1 * (cont+1);
  }

  // int layers[2]={2,2};
  //Forward Feeding
  for(layers=1; layers<2; layers++){
    // printf("%i\n", neurons[0][cont]+neurons[1][cont]);
    for(pos=0; pos<2; pos++){
      for(cNeuron=0; cNeuron<2; cNeuron++){
        // printf("%f %f\n", neuralN[0][cNeuron].init, neuralN[1][pos].weight);
        neuralN[1][pos].res += neuralN[0][cNeuron].init * neuralN[1][pos].weight;
      }
      neuralN[1][pos].res = max(neuralN[1][pos].res - neuralN[1][pos].bias);
      // printf("Bias: %f Res: %f\n", neuralN[1][pos].bias, neuralN[1][pos].res);
    }
  }

  printf("\nNums:%f %f\n", neuralN[1][0].res, neuralN[1][1].res);
  return neuralN[1][0].res;
}
int main(){
  float inputs[] = {1.5, 1.4};

  neurona chida;
  chida.weight = 1;
  chida.bias = 2;
  // printf("%i %i", chida.weight, chida.bias);
  forwardFeeding( (float[]){1,2,3});
  getchar();
  return 0;
}
