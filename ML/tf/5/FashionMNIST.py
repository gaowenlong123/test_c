from tensorflow.keras import datasets,layers,optimizers,Sequential,metrics
import tensorflow as tf
from tensorflow import keras

a = zip([1,2,3],[4,5,6])
b = zip([1,2,3],[4,5,6])

for i in zip(a):
    print(i)

for i in zip(*b):
    print(i)

bathsize = 128

# map预处理
def preprocess(x,y):
    x = tf.cast(x,dtype=tf.float32)/255.
    y = tf.cast(y,dtype=tf.int32)
    return x,y


(x,y) , (x_test,y_test) = datasets.fashion_mnist.load_data()

print(x,y,x_test,y_test)


db = tf.data.Dataset.from_tensor_slices((x,y)) #得到一个该数据集的迭代器，方便操作而不是一个一个的取
db = db.map(preprocess).shuffle(10000).batch(bathsize)

db_test = tf.data.Dataset.from_tensor_slices((x_test,y_test)) #得到一个该数据集的迭代器，方便操作而不是一个一个的取
db_test = db_test.map(preprocess).batch(bathsize)



db_iter = iter(db)
sample = next(db_iter)
print(sample)


model = Sequential(
    [
        layers.Dense(256, activation=tf.nn.relu), # 784 -> 256
        layers.Dense(128, activation=tf.nn.relu),
        layers.Dense(64, activation=tf.nn.relu),
        layers.Dense(32, activation=tf.nn.relu),
        layers.Dense(10, activation=tf.nn.relu),
    ]
)

model.build(input_shape=[None,28*28])
model.summary()


opt = optimizers.Adam(lr=1e-3)

for epoch in range(30):
    for step,(x,y) in enumerate(db):

        x = tf.reshape(x, [-1,28*28])

        with tf.GradientTape() as tape:
            logits = model(x)           #前向传播

            loss = tf.reduce_mean(tf.losses.MSE(tf.one_hot(y,depth=10),logits))
            loss2 = tf.reduce_mean(tf.losses.categorical_crossentropy(tf.one_hot(y,depth=10),logits,from_logits=True))

        grads = tape.gradient(loss2, model.trainable_variables)

        opt.apply_gradients(zip(grads, model.trainable_variables)) #更新权重


        if step %100 ==0:
            print(epoch,step,"loss",float(loss2),float(loss))


    total=0
    # test
    for x,y in db_test:
        x = tf.reshape(x,[-1,28*28])

        logits = model(x)

        prob = tf.nn.softmax(logits,axis=1)

        pred = tf.argmax(prob,axis=1)
        pred = tf.cast(pred,dtype=tf.int32)

        corret = tf.equal(pred,y)
        corret = tf.reduce_sum(tf.cast(corret,dtype=tf.int32))

        total += int(corret)

    print(total)