
#include <stdio.h>

struct Item {
  char id[5];
  int weight;
  int value;
  float density;
};

void fractionalKnapsack(Item items[], int n, int W);

int main(void) {
  //variables
  int i, j;

  //list items
  Item items[3] = {
    {"i1",  10, 60, 0},//w,v
    {"i2", 20, 100, 0},
    {"i3",  30, 120, 0},
  };

  //temp item
  Item temp;

  //number of items
  int n = 3;

  //max weight limit of knapsack
  int W = 50;

  //compute desity = (value/weight)
  for(i = 0; i < n; i++) {
    items[i].density = float(items[i].value) / items[i].weight;
  }

  //sort by density in descending order
  for(i = 1; i < n; i++) {
    for(j = 0; j < n - i; j++) {
      if(items[j+1].density > items[j].density) {
        temp = items[j+1];
        items[j+1] = items[j];
        items[j] = temp;
      }
    }
  }

  fractionalKnapsack(items, n, W);

  return 0;
}

void fractionalKnapsack(Item items[], int n, int W) {
  int i, wt;
  float value;

  float totalWeight = 0, totalBenefit = 0;

  for(i = 0; i < n; i++) {
    if(items[i].weight + totalWeight <= W) {

      totalWeight += items[i].weight;
      totalBenefit += items[i].value;

      printf("Selected Item: %s\tWeight: %d\tValue: %d\tTotal Weight: %f\tTotal Benefit: %f\n", items[i].id, items[i].weight, items[i].value, totalWeight, totalBenefit);

    } else {
      wt = (W - totalWeight);
      value = wt * (float(items[i].value) / items[i].weight);

      totalWeight += wt;
      totalBenefit += value;

      printf("Selected Item: %s\tWeight: %d\tValue: %f\tTotal Weight: %f\tTotal Benefit: %f\n", items[i].id, wt, value, totalWeight, totalBenefit);

      break;
    }
  }

  printf("Total Weight: %f\n", totalWeight);
  printf("Total Benefit: %f\n", totalBenefit);
}
