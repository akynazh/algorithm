import heapq

nums = []
heapq.heappush(nums, 3)
heapq.heappush(nums, 4)
heapq.heappush(nums, 1)
heapq.heappush(nums, 6)
# heapq.heapify(nums)
print(nums)

while len(nums) != 0:
    print(heapq.heappop(nums))
print(nums)

# nums = [3, 8, 1]
# heapq.heapify(nums)
# while len(nums) != 0:
#     print(heapq.heappop(nums))
# print(nums)

# import collections

# dt = collections.OrderedDict()
# dt["a"] = 1
# dt["b"] = 2
# dt["c"] = 3

# for k, v in dt.items():
#     print(k, v)

# dt.pop("a")
# dt["a"] = 1

# dt.popitem(last=False)
# for k, v in dt.items():
#     print(k, v)
