# Problem: https://csacademy.com/ieeextreme-practice/task/icarus
# Solution by: Osama Khallouf (Exeedo)

s = input()
count_u = s.count('U')
count_r = s.count('R')

n = max(count_r, count_u) + 1
if count_r == 0 or count_u == 0:
    n = 2

start = 1
end = n
if count_r >= count_u:
    start = n
    end = 1

print(f"{n} {start} {end}")
for node in range(1, n):
    print(f"0 {node+1}")
print("0 0")