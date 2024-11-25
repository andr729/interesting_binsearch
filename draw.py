# read n integers from file
# and print them on a plot:

import matplotlib.pyplot as plt

def draw():
    with open('numbers.txt', 'r') as file:
        numbers = file.readlines()
    numbers = [[int(n) for n in line.split()] for line in numbers]
    numbers_ranges = [(min(l), max(l)) for l in numbers]

    print(numbers_ranges)
    plt.plot(numbers_ranges)
    plt.show()

draw()


