#!/bin/node


/**
 * Quick Sort.
 *
 * zhaoyou@gmail.com (zhaoyou)
 */

function main() {
  var datas = [3, 7, 4, 2, 8,  9 , 10, 5, 6, 1];
  QuickSort(datas, 0, datas.length - 1);
  console.log(datas);
}

function swap(data, from , to) {
  var temp = data[from];
  data[from] = data[to];
  data[to] = temp;
}

function QuickSort(datas, low, high) {

    if (low >= high) return;
    var pivot = unitSort(datas, low, high);
    QuickSort(datas, low, pivot-1);
    QuickSort(datas, pivot + 1, high);
}

//  2, 5, 3, 4
function unitSort(array, low, high) {
  var key = array[low];
  while(low < high) {

    while(array[high] >= key && low < high) {
      high--;
    }
    array[low] = array[high];

    while(array[low] <= key && low < high) {
      low++;
    }
    array[high] = array[low];
    console.log("low, high", array[low], array[high]);
  }

  array[high] = key;
  return high;
}

main();
