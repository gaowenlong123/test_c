import tensorflow as tf
import numpy as np

# a = tf.random.normal([3,3])
# b = tf.ones([3,3])
# c = tf.zeros([3,3])
#
# mask = a > 0

#1
# print(tf.boolean_mask(a,mask))
#
# #2
# indices = tf.where(mask)
# print(indices)
# print(tf.gather_nd(a,indices))

# print(mask)
# print(tf.where(mask,b,c)) # 如果mask的对应位置为true，那么取A,反之取B



#根据坐标有目的的进行更新

# indices = tf.constant([[4],[3],[1],[7]])
# updates = tf.constant([9,10,11,12])
# shape = tf.constant([8])
# print(shape)
#
# print(tf.scatter_nd(indices,updates,shape)) #地板必须为shape(这样默认都为0)　，　可以把要更新的先取出来，减去自己清零，然后更新，再想加
#
#


#生成坐标系

# points =[]
# for y in np.linspace(-2,2,5):
#     for x in np.linspace(-2,2,5):
#         points.append([x,y])
#
# print(np.array(points))


y =tf.linspace(-2.,2,5)
x =tf.linspace(-2.,2,5)
point_x , point_y = tf.meshgrid(x,y)

print(point_x,point_y)

print(tf.stack([point_x,point_y],axis=2))

