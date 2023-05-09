function sortedArrayToBST(nums: number[]): TreeNode | null {
    return sortedArrayToBst(0, nums.length - 1, nums);
}

function sortedArrayToBst(left: number, right: number, nums: number[]): TreeNode | null {
    if (left > right) {
        return null;
    }
    const mid = left + Math.floor((right - left) / 2);
    const root = new TreeNode(nums[mid]);
    root.left = sortedArrayToBst(left, mid - 1, nums);
    root.right = sortedArrayToBst(mid + 1, right, nums);
    return root;
}
