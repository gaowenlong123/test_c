import tensorflow as tf


# a = tf.random.normal([4,28,28,3])
# b = tf.reshape(a, [4,784,3])
# print(b)
# print(tf.reshape(b,[4,-1,3])) # -1系统帮我计算　同上
# print(tf.reshape(b,[4,-1]))
#


# a = tf.random.normal([4,3,2,1])
# print(tf.transpose(a,perm=[3,2,1,0]))
# print(tf.transpose(a))



# a = tf.random.normal([4,10,5])
# b= tf.expand_dims(a,axis=0)
# print(b)
#
# print(tf.squeeze(b,axis=0))

# broadcasting





# a = tf.ones([2,3,4])
# b = tf.random.normal([4])    #broadcasting 没有真正将数据写入内存，高效
# print(b)
# print(a+b)


a = tf.ones([2,2])
b = tf.fill([2,2],2.)
print(a+b)
print(a-b)
print(a*b)
print(a/b)

print(a//b)
print(a%b)

print(a)
print(tf.math.log(a))
print(tf.math.exp(a))

print(tf.math.log(8.)/tf.math.log(2.))


print(tf.pow(b,3))
print(b**3)

print(tf.sqrt(b))




print(a@b)

print(tf.matmul(a,b))


# c = tf.fill([4,2,3],2.)       ??????
# d = tf.fill([2,3],2.)
# dd = tf.broadcast_to(d,[4,2,3])
# print(tf.matmul(dd,c))