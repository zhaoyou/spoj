
/**
 * count
 */
function coinCount(count, coins) {
  var min = [];
  for(var i = 0; i <= count; i++) {
    min[i] = Number.MAX_VALUE;
  }

  min[0] = 0;

  for (var j = 1; j <= count; j++) {
    for (var k = 0; k < coins.length; k++) {
      if (coins[k] <= j && min[j-coins[k]] + 1 < min[j]) {
        min[j] = min[j-coins[k]] + 1;
      }
    }
  }
  console.log(count + " total min count: " + min[count]);
}

/**
 *
 */
function longIncSubqueue(array, len) {
  var dist = [];
  var t = 1;
  for (var j = 0; j < len; j++) {
    dist[j] = 1;
    for (var k = 0; k < j; k++) {
      if (array[j] >= array[k] && dist[k] + 1 > dist[j]) {
        dist[j] = dist[k] + 1;
      }
    }
    if (t < dist[j]) t = dist[j];
  }

  console.log(array + " longIncSubqueue: " + t);
}

function main() {
  var coins = [1, 3, 5];
  for (var i = 0 ; i <= 11; i++) {
    coinCount(i, coins);
  }

  longIncSubqueue([5,3,4,8,6,7], 6);
}

main();
