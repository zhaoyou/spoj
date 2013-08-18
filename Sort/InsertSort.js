#!/bin/node


/**
 * Insertion Sort.
 *
 * zhaoyou@gmail.com (zhaoyou)
 */

function main() {
  var datas = [3, 7, 4, 2, 8,  9 ];
  //console.log(InsertSort(datas));
  console.log(insertSort(datas));
}

function swap(data, from , to) {
  var temp = data[from];
  data[from] = data[to];
  data[to] = temp;
}

function InsertSort(datas) {
  var i, j, temp;
  var len = datas.length;
  for (i = 1; i < len; i++) {
    if ( datas[i] < datas[i-1]) {
      temp = datas[i];
      j = i;

      while (j > 0 && datas[j - 1] > temp) {
        datas[j] = datas[j-1];
        j--;
      }
      datas[j] = temp;
    }
  }

  return datas;
}

function insertSort(datas) {
  var len = datas.length;
  for (var i = 1; i < len; i++) {
    for (var k = i ; k > 0 , datas[k] < datas[k - 1] ; k--) {
      swap(datas, k, k-1);
    }
  }
  return datas;
}

main();
