function findPrime(num) {
  var dist = [];
  for(var i = 0; i <= num; i++) {
    dist[true];
  }

  var inner_len = parseInt(Math.sqrt(num));

  console.log("inner_len", inner_len);

  for (var j = 2; j < inner_len; j+=1) {
    if(dist[j]) {
      if(isPrime(j)) {
        dist[j]  = false;
        for(var k = j * j; j < sum; k+=j) {
          dist[k] = false;
        }
      }
    } else {
      console.log("*****************: " , j);
    }
  }

  for(var p = 2; p < num; p++) {
    if (!dist[p]) {
      console.log(p + "\t");
    }
  }
}

function isPrime(n) {
  if(n==2) {
    return true;
  }

  for (var i = 2; i < n; i+=1) {
    if (n%i == 0 && n !=i) return false;
  }
  return true;
}

findPrime(100);

//console.log(isPrime(8));
