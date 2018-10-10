#include <stdio.h>
#include <stdlib.h>
#define layers 3 // Has to be int

typedef struct neuron{
  int num;
  struct neuron *nextNeuron;
  struct neuron *nextLayer;
} neuron;

// neuron* createNeuralNetwork(int neuronsInLayers[layers]){
//   // Creates a dynamic matrix
//   int x, y,
//     numLayers = layers/sizeof(int);
//   neuron *init = malloc(sizeof(neuron)); // Don't touch this in progress
//   neuron *initLayer = init;              // This,
//   neuron *currentNeuron = initLayer;     // And this is okay
//
//   for(x=0; x<numLayers; x++){
//     for(y=0; y<neuronsInLayers[x]; y++){
//       currentNeuron->nextNeuron = malloc(sizeof(neuron));
//       currentNeuron = currentNeuron->nextNeuron;
//     }
//     if(x<numLayers-1){
//       initLayer->nextLayer = malloc(sizeof(neuron));
//       initLayer = initLayer->nextLayer;
//       currentNeuron = initLayer;
//     }
//   }
//   return init;
// }

void createNeuralNetwork(int neuronsInLayers[layers], int layer, neuron **init){
  // int numLayers = layers/sizeof(int);
  // neuron *init;

  (*init) = (struct neuron*)malloc(sizeof(struct neuron));
  (*init)->nextNeuron = NULL;
  (*init)->nextLayer = NULL;
  (*init)->num = 0;

  neuronsInLayers[layer-1]--;
  if (neuronsInLayers[layer-1]>0){
    createNeuralNetwork(neuronsInLayers, layer, &((*init)->nextNeuron));
  } else if (layer<layers-1) {
    createNeuralNetwork(neuronsInLayers, ++layer, &((*init)->nextLayer));
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


neuron* findArr(neuron *neuer, int y){
  // Finds a node in a dynamic array and returns it
  int cont;
  neuron *returnNeuron;

  returnNeuron = neuer;
  for(cont=0; cont<y; cont++){
    returnNeuron = returnNeuron->nextNeuron;
  }

  return returnNeuron;
}
neuron* findMatrix(neuron *neuer, int x, int y){
  // Finds a node in a dynamic matrix and returns it
  int cont;
  neuron *returnNeuron;

  returnNeuron = neuer;
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

void detente(char caracter){
  printf("%c",caracter);

  getchar();
  fflush(stdin);
  return;
}
int main(int argc, char *argv[]){
  // neuron *neurona = malloc(sizeof(neuron));

  // neurona->num = layers;
  //printf("%i\n", neurona->num);

  // free(neurona);
  detente('1');

  int vector[layers] = {2,3,2};
  neuron *init;
  createNeuralNetwork(vector, 0, &init);
  
  detente('2');
  detente('3');

  findMatrix(init, 1, 1)->num = 4;

  printf("%i - ",findMatrix(init, 0, 0)->num);
  detente('4');

  printf("%i",findMatrix(init, 1, 1)->num);
  detente('5');

  freeAll(init);
  detente('6');

  // printf("%i %i", sizeof(layers), sizeof(int));

  // int nums[3] = {1,2,3};
  //
  // printf("%i", suma(sizeof(nums)/sizeof(int),nums));

  // neuron *init;
  //
  // init = malloc(sizeof(neuron));
  // init->nextNeuron = NULL;
  // init->nextLayer = NULL;
  // init->num = NULL;
  //
  // console.log()
  // free(init);
  getchar();
  return 0;
}
