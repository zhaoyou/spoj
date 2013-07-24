#!/bin/node


/**
 * Bubble Sort.
 *
 * zhaoyou@gmail.com (zhaoyou)
 */

function main() {
  var datas = [3, 7, 4, 2, 8,  9 ];
  console.log(bubbleSort(datas));
}

function bubbleSort(datas) {
  var i = j = temp = count = 0;
  var len = datas.length;
  for (i = 0; i < len; i++) {
    var dataNotChange = true;
    for (j = i + 1; j < len; j++) {
      count ++;
      if (datas[i] > datas[j]) {
        temp = datas[i];
        datas[i] = datas[j];
        datas[j] = temp;
        dataNotChange = false;
      }
    }

    if (dataNotChange) {
      break;
    }
  }

  console.log("loop count: ", count);
  return datas;
}

main();
