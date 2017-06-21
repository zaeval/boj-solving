che = [x for x in range(1, 10001)]


def binarySearch(item):
    first = 0
    last = len(che) - 1
    found = False

    while first <= last and not found:
        midpoint = (first + last) // 2
        if che[midpoint] == item:
            found = True
            del che[midpoint]
        else:
            if item < che[midpoint]:
                last = midpoint - 1
            else:
                first = midpoint + 1

    return found


def self_num():
    for item in che:
        temp = item
        while temp < 10000:
            temp += temp // 10000 + temp % 10000 // 1000 + temp % 1000 // 100 + temp % 100 // 10 + temp % 10
            binarySearch(temp)

self_num()

for item in che:
    print(item)
