#!/bin/node


/**
 * Bubble Sort.
 *
 * zhaoyou@gmail.com (zhaoyou)
 */

function main() {
  var datas = [3, 7, 4, 2, 8,  9 ];
  console.log(SelectionSort(datas));
}

function swap(data, from , to) {
  var temp = data[from];
  data[from] = data[to];
  data[to] = temp;
}

function SelectionSort(datas) {
  var i = j = minIndex = count = 0;
  var len = datas.length;
  for (i = 0; i < len; i++) {
    minIndex = i;
    for (j = i + 1; j < len; j++) {
      count ++;
      if (datas[i] > datas[j]) {
        minIndex = j;
      }
    }
    swap(datas, i, minIndex);
  }

  console.log("loop count: ", count);
  return datas;
}

main();
