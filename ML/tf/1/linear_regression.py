# 线性问题
# y = wx + b

from tensorflow import test
import numpy as np


def compute_err_for_line_given_points(b,w,points):
    totalError = 0

    for i in range(0 , len(points)):
        x = points[i,0]
        y = points[i,1]

        totalError += ( y - (w*x +b))**2

    return totalError / float(len(points))




def step_gradient(b, w, points , learningRate):
    b_gradient = 0
    w_gradient = 0

    num = float(len(points))

    for i in range(0 , len(points)):
        x = points[i,0]
        y = points[i,1]

        print(b_gradient)
        b_gradient += (2/ num) * ((w*x + b) - y)

        w_gradient += (2 / num) * x * ((w * x + b) - y)

    w_new = w - (learningRate * w_gradient)
    b_new = b - (learningRate * b_gradient)

    return [b_new,w_new]


def gradient_descent_runner(points,starting_b,starting_w,learningRate,num_times):
    b = starting_b
    w = starting_w

    for i in range(num_times):
        b, w = step_gradient(b,w,np.array(points),learningRate)

    return [b, w]

def run():
    points = np.genfromtxt("data.csv",delimiter=" ")

    learningRate = 0.00001

    init_b = 0
    init_w = 0

    num_times = 10000

    err_1 = compute_err_for_line_given_points(init_b,init_w,points)

    [b,w] = gradient_descent_runner(points,init_b,init_w,learningRate,num_times)

    err_2 = compute_err_for_line_given_points(b,w,points)

    print("err_1=",err_1," err_2=",err_2)



if __name__ == '__main__':
    run()