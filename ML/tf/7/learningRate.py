from tensorflow.keras import datasets,layers,optimizers,Sequential,metrics
import tensorflow as tf
from tensorflow import keras


#动态调整learingRate
# opt = optimizers.SGD(learning_rate=0.2)
#
# for epoch in range(100):
#     opt.learing_rate = 0.2 * (100-epoch)/100



(x,y),(x_test,y_test) = datasets.mnist.load_data()
#
#
# x_train,x_val = tf.split(x,num_or_size_splits=[50000,10000])
# y_train,y_val = tf.split(y,num_or_size_splits=[50000,10000])


#交叉验证
# for epoch in range(500):
#     idx = tf.range(60000)
#     idx = tf.random.shuffle(idx)
#
#     x_train, y_train = tf.gather(x,idx[:50000]),tf.gather(y,idx[:50000])
#
#     x_val ,y_val = tf.gather(x,idx[-10000:]),tf.gather(y,idx[-10000:])
#
#     ...


# network.fit(db,epochs=6,validation_split=0.1,validation_freq=2)




#消除过拟合
