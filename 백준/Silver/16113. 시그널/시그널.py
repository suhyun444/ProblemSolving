res = ['######...######','#####','#.####.#.####.#',"#.#.##.#.######",'###....#..#####',
       '###.##.#.##.###','######.#.##.###','#....#....#####','######.#.######','###.##.#.######']
n = int(input())
m = n // 5
s = input()
temp = ''
for i in range(m):
    for j in range(5):
        temp = temp + s[i + j * m]
temp = temp.split('.....')
for digit in temp:
    if temp == '':
        continue
    for i in range(len(res)):
        if digit == res[i]:
            print(i,end='')

