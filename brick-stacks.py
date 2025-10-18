# // Problem: https://csacademy.com/ieeextreme-practice/task/brick-stacks
# // Solution by: Osama Khallouf (Exeedo)

def print_ans(stacks):
    print(len(stacks))
    for stack in stacks:
        print(len(stack), end=' ')
        for element in stack:
            print(element, end=' ')
        print()

def test(s):
    # can we divide the bricks into s stacks?
    for i in range(n):
        if i+s >= n:
            break
        if (arr[i] - arr[i+s] < x):
            return False
    return True

def distribute(s):
    # distribute bricks into s stacks
    stacks = [[] for _ in range(s)]
    for i in range(n):
        stacks[i % s].append(arr[i])
    return stacks

def solve():
    arr.sort(reverse=True)
    l = 1
    r = n
    md = 0
    s = 0
    while l <= r:
        md = (r+l) // 2
        if test(md):
            s = md
            r = md - 1
        else:
            l = md + 1
    stacks = distribute(s)
    print_ans(stacks)

n,x = [int(i) for i in input().split()]
arr = [int(i) for i in input().split()]
solve()
