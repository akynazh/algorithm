def find_single_number(nums):
    result = 0
    for num in nums:
        result ^= num
    return result

arr = [1, 1, 2, 2, 3, 3, 4]

print(find_single_number(arr))
