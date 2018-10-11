#include <stdio.h>
#include <stdlib.h>
#define layers 3 // Has to be int

typedef struct neuron{
  int num;
  struct neuron *nextNeuron;
  struct neuron *nextLayer;
} neuron;


void createNeuralNetwork(int neuronsInLayers[layers], int layer, neuron **init, neuron **initLayer){
  // Creates a dynamic Matrix
  (*init) = (struct neuron *)malloc(sizeof(struct neuron));
  (*init)->nextNeuron = NULL;
  (*init)->nextLayer = NULL;
  (*init)->num = 0;

  // neuronsInLayers[layer-1]--;
  if (--neuronsInLayers[layer-1]>0){
    createNeuralNetwork(neuronsInLayers, layer, &((*init)->nextNeuron), initLayer);
  } else if (layer<layers-1) {
    createNeuralNetwork(neuronsInLayers, ++layer, &((*initLayer)->nextLayer), &((*initLayer)->nextLayer));
  }
  return;
}
void freeAll(neuron *neuer){
  // Frees all nodes in a dynamic matrix
  if (neuer->nextNeuron!=NULL){
    freeAll(neuer->nextNeuron);
  }
  else if(neuer->nextLayer!=NULL){
    freeAll(neuer->nextLayer);
  }
  free(neuer);
  return;
}

neuron* findMat(neuron *neuer, int x, int y){
  // Finds a node in a dynamic matrix and returns it
  int cont;
  neuron *returnNeuron;

  returnNeuron = neuer;
  for(cont=0; cont<x; cont++){ // Encuentra el valor en x  ->
    returnNeuron = returnNeuron->nextLayer;
  }

  for(cont=0; cont<y; cont++){ // Encuentra el valor en y  |
    returnNeuron = returnNeuron->nextNeuron;   //          v
  }

  return returnNeuron;
}



int suma(int length, int arrNum[length]){
  int i, sum=0;
  for(i=0; i<length; i++){
    sum += arrNum[i];
  }
  return sum;
}
int main(int argc, char *argv[]){
  int vector[layers] = {2,3,2};
  neuron *init;
  createNeuralNetwork(vector, 1, &init, &init);

  findMat(init, 1, 1)->num = -3;

  printf("%i - ",findMat(init, 0, 0)->num);
  printf("%i",findMat(init, 1, 1)->num);

  freeAll(init);
  getchar();
  return 0;
}
