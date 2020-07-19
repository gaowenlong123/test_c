import tensorflow as tf
from tensorflow import keras

# x = tf.random.normal([2,3])
#
# model = keras.Sequential([
#     keras.layers.Dense(2,activation='relu'),
#     keras.layers.Dense(2, activation='relu'),
#     keras.layers.Dense(2),
#
# ])
#
# model.build(input_shape=[None,3])
# model.summary()
#
# for p in model.trainable_variables:
#     print(p.name , p.shape)


# y = tf.constant([1,2,3,0,2])
# print(tf.one_hot(y,depth=2))



#sigmoid

a = tf.linspace(-2.,2,5)
# print(a)
# print(tf.sigmoid(a))


#softmax
# print(tf.nn.softmax(a)) #结果的和为１

# logits = tf.random.uniform([1,10],minval=-2,maxval=2)
#
# prob = tf.nn.softmax(logits,axis=1)
#
# print(tf.reduce_sum(prob,axis=1))


#计算交叉熵
# print(tf.losses.categorical_crossentropy([0,1,0,0,] , [0.25,0.25,0.25,0.25]))
#
#
# print(tf.losses.binary_crossentropy([0,1,0,0,] , [0.25,0.25,0.25,0.25]))

#ｔａｎｈ
print(tf.tanh(a))