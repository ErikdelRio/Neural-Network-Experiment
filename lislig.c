#include <stdio.h>
#include <stdlib.h>
#define layers 3 // Has to be int

typedef struct neuron{
  int num;
  struct neuron *nextNeuron;
  struct neuron *nextLayer;
} neuron;

neuron* createNeuralNetwork(int neuronsInLayers[layers]){
  int x, y,
    numLayers=layers/sizeof(int);
  neuron *init = malloc(sizeof(neuron));
  neuron *initLayer = init;
  neuron *currentNeuron = initLayer;

  for(x=0; x<numLayers; x++){
    for(y=0; y<neuronsInLayers[x]; y++){
      currentNeuron->nextNeuron = malloc(sizeof(neuron));
      currentNeuron = currentNeuron->nextNeuron;
    }
    if(x<numLayers-1){
      initLayer->nextLayer = malloc(sizeof(neuron));
      initLayer = initLayer->nextLayer;
      currentNeuron = initLayer;
    }
  }
  return init;
}
// while(neuer->nextNeuron!=NULL){
//   free(neuer->nextNeuron);
// }
void freeAll(neuron *neuer){
  if (neuer->nextNeuron!=NULL){
    freeAll(neuer->nextNeuron);
  }
  else if(neuer->nextLayer!=NULL){
    freeAll(neuer->nextLayer);
  }
  free(neuer);
  return;
}
neuron* findArr(neuron *neuer, int y){
  int cont;
  neuron *returnNeuron;

  returnNeuron = neuer;
  for(cont=0; cont<y; cont++){
    returnNeuron = returnNeuron->nextNeuron;
  }

  return returnNeuron;
}
neuron* findMatrix(neuron *neuer, int x, int y){
  int cont;
  neuron *returnNeuron;

  return returnNeuron = neuer;
  for(cont=0; cont<x; cont++){
    returnNeuron = returnNeuron->nextLayer;
  }

  returnNeuron = findArr(returnNeuron, y);
  return returnNeuron;
}

int suma(int length, int arrNum[length]){
  int i, sum=0;
  for(i=0; i<length; i++){
    sum += arrNum[i];
  }
  return sum;
}

int main(){
  // neuron *neurona = malloc(sizeof(neuron));

  // neurona->num = layers;
  //printf("%i\n", neurona->num);

  // free(neurona);

  // int vector[layers] = {2,3,4};
  // printf("%i %i", sizeof(layers), sizeof(int));

  int nums[3] = {1,2,3};

  printf("%i", suma(sizeof(nums)/sizeof(int),nums));
  getchar();
  return 0;
}
