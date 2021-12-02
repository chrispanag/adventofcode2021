f = open("input.txt", "r")
data = f.read()

x, y, aim = 0, 0, 0
for l in data.splitlines():
    [direction, steps] = l.split()
    parsed_steps = int(steps)
    if direction == "forward":
        x = x + parsed_steps
        y = y + aim * parsed_steps
        continue
    if direction == "down":
        aim = aim + parsed_steps
        continue
    if direction == "up":
        aim = aim - parsed_steps
        continue

print(x, y)
print(x * y)
