from tensorflow.keras import datasets,layers,optimizers,Sequential,metrics
import tensorflow as tf
from tensorflow import keras

tf.random.set_seed(2345)


"""
[bathsize , 宽 ， 高  ， 通道数 ]

权值共享（就是卷积核在一张图片滑动时不变），滑动窗口，来达到一个参数量减少的情况
bathsize : 几张图片

"""

"""
输入 [4, 32, 32, 3]  四张 三通道的 32X 32 的图片

确定卷积核的尺寸，进行所有通道的图片卷积，得到 [ 4, 32 , 32 ,  1 ]  (为什么是1，因为把所以通道信息都压缩到一个图片上了)
同时也确定的核的数量，即就有多少个这样的操作   [ 4, 32 , 32 , 64 ]


这个搞如果每个卷积核相同，那么每一个会不会也相同？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？？

在用strides=2进行减半 
=>  [3 , 16 ,16 ,64 ]

"""
conv_layers = [
    layers.Conv2D(64, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.Conv2D(64, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.MaxPool2D(pool_size=[2,2],strides=2,padding='same'),

    layers.Conv2D(128, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.Conv2D(128, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.MaxPool2D(pool_size=[2,2],strides=2,padding='same'),

    layers.Conv2D(256, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.Conv2D(256, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.MaxPool2D(pool_size=[2,2],strides=2,padding='same'),

    layers.Conv2D(512, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.Conv2D(512, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.MaxPool2D(pool_size=[2, 2], strides=2, padding='same'),

    layers.Conv2D(512, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.Conv2D(512, kernel_size=[3, 3], padding='same', activation=tf.nn.relu),
    layers.MaxPool2D(pool_size=[2, 2], strides=2, padding='same'),

]

bathsize =32


def preprocess(x,y):
    x = 2 * tf.cast(x,dtype=tf.float32)/255. - 1.0
    y = tf.cast(y,dtype=tf.int32)
    return x,y

(x,y),(x_test,y_test) = datasets.cifar100.load_data()
y = tf.squeeze(y,axis=1)
y_test = tf.squeeze(y_test,axis=1)


db = tf.data.Dataset.from_tensor_slices((x,y)) #得到一个该数据集的迭代器，方便操作而不是一个一个的取
db = db.map(preprocess).shuffle(10000).batch(bathsize)

db_test = tf.data.Dataset.from_tensor_slices((x_test,y_test)) #得到一个该数据集的迭代器，方便操作而不是一个一个的取
db_test = db_test.map(preprocess).batch(bathsize)


if __name__ == '__main__':

    conv_net = Sequential(
        conv_layers
    )


    #全链接网络
    fc_net = Sequential(
        [
            layers.Dense(256,activation=tf.nn.relu),
            layers.Dense(128, activation=tf.nn.relu),
            layers.Dense(100, activation=tf.nn.relu),

        ]
    )

    conv_net.build(input_shape=[None,32,32,3])
    fc_net.build(input_shape=[None,512])

    opt = optimizers.Adam(lr=1e-4)
    val = conv_net.trainable_variables + fc_net.trainable_variables


    for epoch in range(50):

        for step , (x,y) in enumerate(db):

            with tf.GradientTape() as tape:

                out = conv_net(x)

                out = tf.reshape(out, [-1,512])

                logits = fc_net(out)

                y_onehot = tf.one_hot(y,depth=100)

                loss = tf.reduce_mean(tf.losses.categorical_crossentropy(y_onehot,logits,from_logits=True))


            grads = tape.gradient(loss,val)

            opt.apply_gradients(zip(grads,val))


            if step%100 == 0:
                print(loss)

        total = 0
        total_correct =0

        #进行测试
        for x,y in db_test:
            out = conv_net(x)
            out = tf.reshape(out,[-1,512])

            logit = fc_net(out)
            prob = tf.nn.softmax(logit,axis=1)

            pred = tf.argmax(prob,axis=1)
            pred = tf.cast(pred,dtype=tf.int32)

            corret = tf.cast(tf.equal(pred,y),dtype=tf.int32)

            corret = tf.reduce_sum(corret)

            total += x.shape[0]
            total_correct += int(corret)

        print("acc",total_correct/total)