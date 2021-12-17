count = 0
arr = [-1 for i in range(0, 11)]
table ={}


def checkResult():
    x1 = arr[1]*1000000+arr[2]*100000+arr[3]*11000+arr[4]*100+arr[5]*10+arr[6]
    x2 = arr[3]*1000000+arr[7]*100000+arr[1]*10000+arr[4]*1000+arr[8]*100+ 19
    if x1 -x2 == 2681431:
        return True
    else:
        return False


def check(k, index):
    if k == 1 or k == 3:
        if index == 0:
            return False
    if index in table:
        return False
    return True


def _try(k):
    if k == 9:
        if checkResult():
            global count
            count = count + 1
        return

    for index in range(0, 10):
        if check(k, index):
            arr[k] = index
            table[k] = 1
            _try(k+1)
            arr[k] = -1
            del(table[k])


_try(1)

print(count)

