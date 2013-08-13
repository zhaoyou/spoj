/**
 * Find str contains substr.
 * hadeser7@gmail.com
 */
function search(str, substr, p) {
  var n = str.length;
  var m = substr.length;
  var j = 0;
  for(var i = 0; i < n; i++) {
    while(j > 0 && substr[j] != str[i]) {
      j = p[j-1];
    }
    if (substr[j] == str[i]) {
      j += 1;
    }

    if (j == m) {
      console.log('find str contains substr index => ', i +1 - m);
      j = p[j-1];
    }
  }
}

/**
 * Pre_handler for substr.
 * hadeser7@gmail.com
 */
function pre_search(substr) {
  var m = substr.length;
  var p = [];
  p[0] = 0;
  var j = 0;

  for (var i = 1; i < m ; i++) {
    while( j > 0 && substr[j] != substr[i]) { j = p[j];}
    if (substr[j] == substr[i]) { j = j + 1;}
    p[i] = j;
  }

  console.log(p);
  return p;
}

search("abababacabab", "abab", pre_search("abab"));
