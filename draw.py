# read n integers from file
# and print them on a plot:

import matplotlib.pyplot as plt

def draw():
    with open('numbers.txt', 'r') as file:
        numbers = file.readlines()
    numbers = [int(x) for x in numbers]
    plt.plot(numbers)
    plt.show()

draw()


