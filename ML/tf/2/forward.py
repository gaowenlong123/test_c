import  tensorflow as tf
from  tensorflow import  keras
from  tensorflow.keras import datasets


(x,y),_ = datasets.mnist.load_data()

x = tf.convert_to_tensor(x,dtype=tf.float32) / 255.
y = tf.convert_to_tensor(y,dtype=tf.int32)

train_db = tf.data.Dataset.from_tensor_slices((x,y)).batch(128)
train_iter = iter(train_db)

sample = next(train_iter)

w1 = tf.Variable(tf.random.truncated_normal([784,256],stddev=0.1))
b1 = tf.Variable(tf.zeros([256]))

w2 = tf.Variable(tf.random.truncated_normal([256,128],stddev=0.1))
b2 = tf.Variable(tf.zeros([128]))

w3 = tf.Variable(tf.random.truncated_normal([128,10],stddev=0.1))
b3 = tf.Variable(tf.zeros([10]))

lr = 1e-3

# h1 = x@w + b1
for step, (x,y) in enumerate(train_db):
    x = tf.reshape(x,[-1,28*28])

    with tf.GradientTape() as tape:
        h1 = x@w1 + b1
        h1 = tf.nn.relu(h1)
        h2 = h1@w2 + b2
        h2 = tf.nn.relu(h2)
        out = h2@w3 + b3


        y_hot = tf.one_hot(y,depth=10)

        loss = tf.square(y_hot - out)
        loss = tf.reduce_mean(loss)


    grads = tape.gradient(loss , [w1,b1,w2,b2,w3,b3])

    # w1 = w1 - lr*grads[0]
    w1.assign_sub( lr*grads[0])
    b1.assign_sub( lr*grads[1])
    w2.assign_sub( lr*grads[2])
    b2.assign_sub( lr*grads[3])
    w3.assign_sub( lr*grads[4])
    b3.assign_sub( lr*grads[5])


    if step % 100 == 0:
        print(step , "loss = " , float(loss))