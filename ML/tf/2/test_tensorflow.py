import tensorflow as tf
import numpy as np
from tensorflow.keras import layers
# a=tf.constant(1)
# b=tf.constant(1.0)
# c=tf.constant(2.0 ,dtype=tf.double)
# d = tf.constant(True)
# print(a)
# print(b)
# print(c)
# print(d)
#
#
# with tf.device("cpu"):
#     cpu_a = tf.constant([1])
#
# with tf.device('gpu'):
#     gpu_b = tf.range(4)
#
# print(cpu_a.device)
# print(gpu_b.device)
#
# # cpu_aa = cpu_a.gpu()
# # print(cpu_aa.device)
#
#
# numpy_b = gpu_b.numpy()
# print(type(numpy_b) , numpy_b.shape , numpy_b.ndim)
#
# tf_b = tf.rank(numpy_b)
# print(tf_b,type(tf_b))
#
#
# temp = tf.ones([3,4,2])
# print(temp)
# tf_c = tf.rank(temp)
# print(tf_c)
#
#
# print(tf.is_tensor(tf_c))
#


#convert
# a = np.arange(5)
# aa = tf.convert_to_tensor(a)
# print(aa)
#
# bb = tf.convert_to_tensor(a,dtype=tf.int32)
# print(bb)
#
# cc = tf.cast(bb,dtype=tf.float32)
# print(cc)
#
#
# bool = tf.constant([0,1])
# bool = tf.cast(bool,dtype=tf.bool)
# print(bool)



#create
# na = tf.convert_to_tensor(np.ones([1,3]))
# b = tf.convert_to_tensor(np.zeros([2,3]))
# nc = tf.convert_to_tensor([[2,2],[2,2]])
# print(nc)
#
# a = tf.zeros([])
# b = tf.zeros([3])
# c = tf.zeros([2,2])
# print(a)
# print(b)
# print(c)

# a = tf.fill([2,2],9.)
# print(a)

# a = tf.random.normal([2,2],mean=1,stddev=1) # N(1,1)正态分布
# print(a)
#
# b = tf.random.truncated_normal([2,2],mean=0,stddev=1) #截取正态分布某个区域
# print(b)
#
# c = tf.random.uniform([2,2],minval=0,maxval=100) #均匀分布
# print(c)

# idx = tf.range(10)
# idx = tf.random.shuffle(idx) #打散
# print(idx)
#
# a = tf.random.normal([10,784])
# b = tf.random.uniform([10],maxval=10,dtype=tf.int32)
# print(a)
# print(b)
#
# a = tf.gather(a,idx) #根据索引重新排序
# b = tf.gather(b,idx)
# print(a)
# print(b)

# x = tf.random.normal([4,784])
# print(x)
#
#
# net = layers.Dense(5)
#
# net.build((4,784))
# net(x)
#
# print(net.kernel)
# print(net.kernel.shape)
#
# print(net.bias)



# a = tf.random.normal([4,28,28,3])
#
# print(a[1].shape)
# print(a[1,2].shape)
# print(a[1,2,4].shape)
#
# print(a[-2:])
# print(a[-2])
#
# print(a[-2,1,:,:])
#
# print(a[:,:,:,2])
#
# print(a[::1,:,:,:])  # start : end : step
#
# print(a[::1,:14,-14:,:]) #:14 从开始到１4
#
# print(a[3::-2,:,:,:])
#
#
# print(a[1,::,::,::])
# print(a[1,...])  # 同上面
# print(a[...,1])



# a = tf.random.normal([4,35,8])
# print(tf.gather(a,axis=0,indices=[2,3]))
# print(tf.gather(a,axis=1,indices=[3,2,4,10]))
#
# print(tf.gather_nd(a,[0,4,3]))
#
# print(tf.gather_nd(a,[[0,4,1], [0,4,2]]))


a = tf.random.normal([4,28,28,3])
print(tf.boolean_mask(a,mask=[True,True,False],axis=3))
a = tf.ones([2,3,4])
print(tf.boolean_mask(a,mask=[[True,False,False],[False,True,True]])) # 只要第零行的第一个，第二行的第２，３的样本
