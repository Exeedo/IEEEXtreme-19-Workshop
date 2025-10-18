# Problem: https://csacademy.com/ieeextreme-practice/task/sierpinski
# Solution by: Osama Khallouf (Exeedo)

def solve(x, y, step=30):
    size = 3 * (1 << (step - 1))
    half = size >> 1
    if x == size:
        return 0
    if step == 1:
        return 1
    # T1
    if x <= half:
        return solve(x, y, step - 1)
    # T3
    if y > half:
        return solve(x - half, y - half, step - 1)
    # T2
    if x - y >= half:
        return solve(x - half, y, step - 1)

    return 0

q = int(input())
for _ in range(q):
    x, y = [int(i) for i in input().split()]
    print(solve(x, y))
