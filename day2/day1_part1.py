f = open("input.txt", "r")
data = f.read()

x, y = 0, 0
for l in data.splitlines():
    [direction, steps] = l.split()
    parsed_steps = int(steps)
    if direction == "forward":
        x = x + parsed_steps
        continue
    if direction == "down":
        y = y + parsed_steps
        continue
    if direction == "up":
        y = y - parsed_steps
        continue

print(x, y)
print(x * y)
