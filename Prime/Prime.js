/**
 * Find Prime of Number.
 * hadeser7@gmail.com
 */
function findPrime(num) {
  var array = [];
  for (var i = 2; i <= num; i++) {
    array[i] = true;
  }

  for (var j = 2; j < parseInt(Math.sqrt(num)); j++) {
    if (array[j]) {
      for (var k = j * j; k <= num; k = k + j) {
        array[k] = false;
      }
    }
  }

  for (var p = 2; p <= num; p++) {
    if (array[p])
      console.log(p);
  }
}

findPrime(97);

