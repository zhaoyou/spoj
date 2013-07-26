function binarySearch(array, num, low, high) {
  var mid ;
  while(low <= high) {
    mid = low + parseInt((high - low)/2);
    if (array[mid] > num) high = mid - 1;
    else if (array[mid] < num) low = mid + 1;
    else return mid;
  }
  return -1;
}

function main() {
  var array = [3, 5, 7, 9 , 11, 19, 20, 30, 40 , 60, 70];
  var num = 60;
  console.log(binarySearch(array, num, 0, array.length - 1));
}

main();


