import tensorflow as tf
import numpy as np


def func(x):

    z = tf.math.sin(x[...,0]) + tf.math.sin(x[...,1])

    return z


x = tf.linspace(0.,2*3.14,500)
y = tf.linspace(0.,2*3.14,500)

point_x,point_y = tf.meshgrid(x,y)

points = tf.stack([point_x,point_y],axis=2)

print(points)

z = func(points)
print(z)


