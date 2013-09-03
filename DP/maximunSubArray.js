
function getMaxSubArraySum(array) {
  var max_ending_here = max_so_far = array[0];
  var start = 0;
  var end = 0;
  for (var i = 1; i < array.length; i++) {
    if (max_ending_here < 0) {
      max_ending_here = array[i];
      start = i;
    } else {
      max_ending_here += array[i];
    }

    if (max_ending_here > max_so_far) {
      max_so_far = max_ending_here;
      end = i;
    }
  }

  console.log("max_subarray_sum", max_so_far, " from : " , start, " to ", end);
}

getMaxSubArraySum([0, 1, -2, 3, 10, -4, 7, 2, -5]);
