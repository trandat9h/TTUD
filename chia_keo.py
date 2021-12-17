count = 0

for x2 in range(1, 30):
    for x3 in range(1, 15):
        for x4 in range(1, 20):
            for x5 in range(1, 12):
                if x2+x3 == 6 and 2 * x2 + 4 * x3 + 3 * x4 + 5 * x5 == 60:
                    count = count + 1

print(count)
