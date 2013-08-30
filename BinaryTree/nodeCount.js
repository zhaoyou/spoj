
var BinaryTreeNode = function(v, left, right) {
  this.v = v;
  this.left = left;
  this.right = right;
}

function count(root) {
  if (root == null) {
    return 0;
  }

  console.log(root.v);
  return count(root.left) + count(root.right) + 1;
}

function getDepth(root) {
  if (root == null) {
    return 0;
  }

  var depthLeft = getDepth(root.left);
  var depthRight = getDepth(root.right);
  return depthLeft > depthRight ? (depthLeft + 1) : (depthRight + 1)
}

function main() {
  var n3 = new BinaryTreeNode(3, null, null);
  var n4 = new BinaryTreeNode(4, null, null);

  var n5 = new BinaryTreeNode(5, null, null);
  var n6 = new BinaryTreeNode(6, null, null);

  var n1 = new BinaryTreeNode(1, n3, n4);
  var n2 = new BinaryTreeNode(2, n5, n6);

  var root = new BinaryTreeNode(0, n1, n2);

  var num = count(root);

  console.log('NodeCount: ' + num);
  console.log('NodeDepth: ' + getDepth(root));
}

main();
