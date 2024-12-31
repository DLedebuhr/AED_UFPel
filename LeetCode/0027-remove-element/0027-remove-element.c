int removeElement(int* nums, int numsSize, int val) {
  
    int k = 0;
    int i;

    for (i = 0; i < numsSize; i++) {
        
        if (nums[i] == val) {

            continue;

        } else {

            nums[k] = nums[i];
            
            k++; 

        }
    }

    return (k);

}