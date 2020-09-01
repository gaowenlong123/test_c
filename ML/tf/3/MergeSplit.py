import tensorflow as tf

# 合并与分割
# a = tf.ones([4,35,Con8])
# b = tf.ones([2,35,Con8])
#
# c = tf.concat([a,b],axis=0) #非合并项要相等
#
# a = tf.ones([4,35,Con8])
# b = tf.ones([4,35,Con8])
# c = tf.stack([a,b],axis=1) #所有项要相等,创建一个新的维度
# print(c)
#
#
# e = tf.ones([2,4,35,Con8])
# print(len(tf.unstack(e,axis=2)))   #把该项全部打散
#
# print(len(tf.split(e, axis=3,num_or_size_splits=2))) #平均分为两个
#
# print(len(tf.split(e, axis=3,num_or_size_splits=[2,2,4]))) #依次分为2,2,4
#
#


#数据统计

# a = tf.ones([2,2])
# print(tf.norm(a))  # 默认二范式
# print(tf.sqrt(tf.reduce_sum(tf.square(a))))
#
# print(tf.norm(a,ord=2,axis=1)) #在维度１上求二范式
#
# print(tf.norm(a,ord=1,axis=1)) #在维度１上求一范式
#
# print(tf.norm(a,ord=1)) #求所有的一范式



# reduce  是一个降维的过程

b = tf.random.normal([4,10])
# print(tf.reduce_mean(b)) #在所有维度上求均值
# print(tf.reduce_min(b))
# print(tf.reduce_max(b))
#
#
# print(tf.reduce_mean(b,axis=1)) #在维度1上求均值
# print(tf.reduce_min(b,axis=1))
# print(tf.reduce_max(b,axis=1))



#返回在某个维度上最大值的位置，默认是０
# print(tf.argmax(b,axis=1))
# print(tf.argmin(b,axis=1))


# a = tf.constant([1,2,3,4,5])
# b = tf.range(5)
#
# print(tf.equal(a,b))
# print(tf.cast(tf.equal(a,b),dtype=tf.int32))


# a = tf.constant([1,2,3,4,5,5])
# print(tf.unique(a)) # 前面不充重复　，后面是原式的不重复式子的索引







# 排序

# a = tf.random.shuffle(tf.range(5))
# print(a)
# print(tf.sort(a,direction="DESCENDING"))
# print(tf.sort(a)) #默认是正序
#
# print(tf.argsort(a,direction="DESCENDING")) #得到索引
# print(tf.argsort(a))#默认是正序
#
#
#
#
# b = tf.constant([[4,6,Con8],[9,4,7],[4,5,11]])
# print(b)
#
# res = tf.math.top_k(b,2) #只取最大的前两个
# print(res.indices)        # 拿到索引
# print(res.values)              # 拿到值


#填充
# a = tf.reshape(tf.range(9), [3,3])
# print(tf.pad(a,[[0,0] , [0,0]])) #行，列
#
# print(tf.pad(a,[[2,2] , [2,2]]))
#
#
# b = tf.random.normal([4,28,28,3])
# print(tf.pad(b,[[0,0],[2,2],[3,3],[0,0]]))


#复制
# a = tf.reshape(tf.range(9), [3,3])
#
# print(tf.tile(a,[1,2]))
# print(tf.tile(a,[2,2]))
# print(tf.tile(a,[1,0]))
#
# print(tf.broadcast_to(a,[2,3,3]))



#裁剪
# a = tf.range(10)
# print(tf.maximum(a,2))
# print(tf.minimum(a,Con8))
#
# print(tf.clip_by_value(a,2,Con8))


# a = a-5
# print(tf.nn.relu(a))
# print(tf.maximum(a,0))
#



#向量是有方向的，不能直接裁剪，需要等比例的放缩
# a = tf.random.normal([2,2],mean=10)
#
# tf.norm(a)
#
# aa = tf.clip_by_norm(a,15) #希望整体放缩到１５之内
# print(aa)
# print(tf.norm(aa))  #所有二范式也接近１５





# tf.clip_by_global_norm(grads,15) # 不只是裁剪一个梯度，而是将全部的梯度一起缩小








