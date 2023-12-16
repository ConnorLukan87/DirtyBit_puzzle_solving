import math


def deg_to_rad(deg):
    return deg * math.pi / 180.0


def x(hypot, theta):
    return hypot * math.cos(theta)


def y(hypot, theta):
    return hypot * math.sin(theta)




last_input = int(input())
while last_input != 0:
    num_directions = last_input
    avg_x = 0.0
    avg_y = 0.0
    direction_ends = []
    for i in range(num_directions):
        line = input().split()
        current_angle = float(line[3])
        current_angle = deg_to_rad(current_angle)
        current_x = float(line[0])
        current_y = float(line[1])

        j = 4
        while j < len(line):
            if line[j][0] == 'w':
                j += 1
                current_x += x(float(line[j]), current_angle)
                current_y += y(float(line[j]), current_angle)
            elif line[j][0] == 't':
                j += 1
                current_angle += deg_to_rad(float(line[j]))
            j += 1

        direction_ends.append((current_x, current_y))
        avg_x += current_x
        avg_y += current_y

    avg_x /= float(num_directions)
    avg_y /= float(num_directions)
    worst_distance = 0.0

    for direction_end in direction_ends:
        distance = math.sqrt((direction_end[0] - avg_x) ** 2 + (direction_end[1] - avg_y) ** 2)
        if distance > worst_distance:
            worst_distance = distance

    print(avg_x, avg_y, worst_distance)
    last_input = int(input())
