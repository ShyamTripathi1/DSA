// Time Complexity: O(N)
// Space Complexity: O(1)

function simpleArraySum(ar) {
    return ar.reduce((sum, num) => sum + num, 0);
}