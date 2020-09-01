from tensorflow.keras import datasets,layers,optimizers,Sequential,metrics
import tensorflow as tf
from tensorflow import keras
from ML.tf.Con8.ResNet import resnet18
import os

os.environ['TF_CPP_MIN_LOG_LEVEL'] = '2'

tf.random.set_seed(2345)


"""
[bathsize , 宽 ， 高  ， 通道数 ]

权值共享（就是卷积核在一张图片滑动时不变），滑动窗口，来达到一个参数量减少的情况
bathsize : 几张图片




1：减低batch size
2: 减少 resblock
3: Google CoLab


"""

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


    model = resnet18()
    model.build(input_shape=(None,32,32,3))

    opt = optimizers.Adam(lr=1e-3)


    for epoch in range(50):

        for step , (x,y) in enumerate(db):

            with tf.GradientTape() as tape:

                logits = model(x)

                y_onehot = tf.one_hot(y,depth=100)

                loss = tf.reduce_mean(tf.losses.categorical_crossentropy(y_onehot,logits,from_logits=True))


            grads = tape.gradient(loss,model.trainable_variables)

            opt.apply_gradients(zip(grads,model.trainable_variables))


            if step%100 == 0:
                print(loss)

        total = 0
        total_correct =0

        #进行测试
        for x,y in db_test:

            logit = model(x)
            prob = tf.nn.softmax(logit,axis=1)

            pred = tf.argmax(prob,axis=1)
            pred = tf.cast(pred,dtype=tf.int32)

            corret = tf.cast(tf.equal(pred,y),dtype=tf.int32)

            corret = tf.reduce_sum(corret)

            total += x.shape[0]
            total_correct += int(corret)

        print("acc",total_correct/total)