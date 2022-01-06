if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    max = arr[0]
    res = -101
    index = 1
    while index < len(arr):
    	if (arr[index] != res and arr[index] != max):
    		if arr[index] > max:
    			res = max
    			max = arr[index]
    		elif arr[index] > res:
    			res = arr[index]
    	index += 1
    print(res)
