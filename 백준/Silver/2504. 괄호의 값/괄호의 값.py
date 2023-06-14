s = input()
stack = []
ans = 0
cur = 1
for i in range(len(s)):
    c = s[i]
    if c == '(' :
        stack.append(c)
        cur *= 2
    if c == '[':
        stack.append(c)
        cur *= 3
    if c == ')':
        if len(stack) == 0 or stack[-1] == '[':
            print("0")
            exit(0)
        stack.pop()
        if s[i-1] == '(':
            ans += cur
        cur /= 2
    if c == ']':
        if len(stack) == 0 or stack[-1] == '(':
            print("0")
            exit(0)
        stack.pop()
        if s[i-1] == '[':
            ans += cur
        cur /= 3

if stack:
    print("0")
    exit(0)
print(int(ans))