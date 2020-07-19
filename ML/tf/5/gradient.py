import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np

# w = tf.constant(1.)
# x = tf.constant(2.)
#
# y=w*x
#
# with tf.GradientTape() as tape:
#     tape.watch([w])
#
#     y2 = x*w
#
# grad1 = tape.gradient(y,[w])
# print(grad1)
#
# with tf.GradientTape(persistent=True) as tape:  #需要包在里面，进行跟踪整个计算过程
#     tape.watch([w])
#
#     y3 = x * w
#
# grad2 = tape.gradient(y3, [w])
# print(grad2)
#
#
# grad3 = tape.gradient(y3, [w])
# print(grad3)


#二阶求导
# with tf.GradientTape() as t1:
#     with tf.GradientTape() as t2:
#         y = x*w + b
#
#     dy_dw , dy_db = t2.gradient(y,[w,b])
# d2y_dw2 = t1.gradient(dy_dw,[w])
#


#激活函数



#函数优化
from mpl_toolkits.mplot3d import Axes3D

def himmelblau(x):
    return (x[0]**2 + x[1] -11)** 2+(x[0] + x[1] ** 2 -7)**2

x = np.arange(-6,6,0.1)
y = np.arange(-6,6,0.1)

X,Y = np.meshgrid(x,y)

Z = himmelblau([X,Y])

fig = plt.figure("aaa")
# ax = fig.gca(projection='3d')
ax = Axes3D(fig)
ax.plot_surface(X,Y,Z)
ax.view_init(60,-30)
ax.set_xlabel('x')
ax.set_ylabel('y')
plt.show()

