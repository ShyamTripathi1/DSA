typedef enum PointerSide 
{
    LEFT    = (unsigned int)(0u),
    RIGHT   = (unsigned int)(1u)
} pointer_side_t;

typedef struct NumberStruct
{
    int num;
    int index;
} number_t;

static int compatePointers(const void* first_ptr, const void* second_ptr) 
{
    return ( ((number_t*)first_ptr)->num - ((number_t*)second_ptr)->num );
}

static int* twoSum(int* nums, size_t nums_size, int target, int* return_size) 
{
    int* result = NULL;

    number_t numbers[nums_size];

    int left_ptr    = 0u;
    int right_ptr   = 0u;

    int sum = 0u;

    size_t iterator = 0u;

    if(nums == NULL || nums_size <= 0u)
    {
        goto end_of_function;
    }

    for(iterator = 0u; iterator < nums_size; iterator++) 
    {
        numbers[iterator].num   = nums[iterator];
        numbers[iterator].index = iterator;
    }

    qsort(numbers, nums_size, sizeof(number_t), compatePointers);

    right_ptr = (nums_size - 1u);

    while(left_ptr < right_ptr) 
    {
        sum = (numbers[left_ptr].num + numbers[right_ptr].num);

        if(sum == target) 
        {
            *return_size = 2u;

            result = (int*)malloc(*return_size * sizeof(int));

            result[LEFT]    = numbers[left_ptr].index;
            result[RIGHT]   = numbers[right_ptr].index;

            goto end_of_function;
        } 
        else if(sum < target) 
        {
            left_ptr++;
        } 
        else 
        {
            right_ptr--;
        }
    }

    *return_size = 0u;
    result = NULL;

end_of_function:
    return result;
}
