// time: O(nlogk)
// space: O(n)

class MinHeap {
  constructor() {
    // Initialize an empty array to represent the heap
    this.arr = [];
  }

  minHeapify(index) {
    // Maintain the heap property by comparing the current node with its children
    let smallest = index;
    const leftChildIndex = 2 * index + 1;
    const rightChildIndex = 2 * index + 2;

    if (
      leftChildIndex < this.arr.length &&
      this.arr[leftChildIndex][1] < this.arr[smallest][1]
    )
      smallest = leftChildIndex;

    if (
      rightChildIndex < this.arr.length &&
      this.arr[rightChildIndex][1] < this.arr[smallest][1]
    )
      smallest = rightChildIndex;

    if (smallest !== index) {
      // Swap the elements and recursively heapify the affected sub-tree
      [this.arr[smallest], this.arr[index]] = [
        this.arr[index],
        this.arr[smallest],
      ];
      this.minHeapify(smallest);
    }
  }

  insert(pair) {
    // Add a new element to the heap and bubble it up to maintain the heap property
    this.arr.push(pair);
    this.bubbleUp(this.arr.length - 1);
  }

  bubbleUp(index) {
    // Move the newly inserted element up until the heap property is restored
    let parentIndex = Math.floor((index - 1) / 2);
    while (index > 0 && this.arr[index][1] < this.arr[parentIndex][1]) {
      [this.arr[index], this.arr[parentIndex]] = [
        this.arr[parentIndex],
        this.arr[index],
      ];
      index = parentIndex;
      parentIndex = Math.floor((index - 1) / 2);
    }
  }

  pop() {
    // Remove the smallest element (root) and re-heapify the heap
    if (this.arr.length === 1) return this.arr.pop();
    const min = this.arr[0];
    this.arr[0] = this.arr.pop();
    this.minHeapify(0);
    return min;
  }

  size() {
    // Return the size of the heap
    return this.arr.length;
  }

  getMinHeap() {
    // Return the internal array representing the heap
    return this.arr;
  }
}

var topKFrequent = function (nums, k) {
  const freq = {};

  // Build frequency map for the input numbers
  for (let x of nums) {
    if (freq[x] === undefined) freq[x] = 1;
    else freq[x]++;
  }

  const myMinHeap = new MinHeap();

  // Insert elements into the min-heap and maintain the top k frequent elements
  for (let key in freq) {
    myMinHeap.insert([key, freq[key]]);
    if (myMinHeap.size() > k) myMinHeap.pop();
  }

  // Extract the elements from the heap to form the result array
  return myMinHeap.getMinHeap().map((pair) => parseInt(pair[0]));
};
