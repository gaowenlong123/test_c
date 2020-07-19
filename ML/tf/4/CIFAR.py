from tensorflow.keras import datasets
import tensorflow as tf


(x,y) , (x_test,y_test) = datasets.cifar10.load_data()

print(x,y,x_test,y_test)

print(x.min())
print(y.max())



db = tf.data.Dataset.from_tensor_slices(x_test) #得到一个该数据集的迭代器，方便操作而不是一个一个的取
it = iter(db)
print(next(it))


db = tf.data.Dataset.from_tensor_slices((y_test,x_test)) #得到一个该数据集的迭代器，方便操作而不是一个一个的取
print(next(iter(db))[1])



# map预处理
def preprocess(x,y):
    x = tf.cast(x,dtype=tf.float32)/255.
    y = tf.cast(y,dtype=tf.int32)

    y =tf.one_hot(y,depth=10)

    return x,y

db2 = db.map(preprocess)
print(next(iter(db2))[1])


# batch
db3 =db.batch(32)
print(next(iter(db3))[1])


db4 =db.repeat(2) #迭代两次就退出，０是永远迭代
print(next(iter(db4))[1])


