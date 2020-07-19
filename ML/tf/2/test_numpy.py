import numpy as np


a = np.array([2,3,4])
# b = np.array([4.0,5.0,6.0])
# c = np.array([[1, 2], [3, 4]], dtype=complex)  # 指定数据类型
#
print(a , a.dtype ,type(a))
# print(b , b.dtype)
# print(c , c.dtype)
#
#
# #数组的常用函数
# print(np.arange(0,7,1,dtype=np.int16)) # 0为起点，间隔为1时可缺省(引起歧义下不可缺省)
# print(np.arange(0,10,2)) # 起点为0，不超过10，步长为2
# print(np.linspace(-1,2,5)) # 起点为-1，终点为2，取5个点
#
#
# print(np.ones((2,3,4),dtype=np.int16)) # 2页，3行，4列，全1，指定数据类型
# print(np.ones((1,3,4),dtype=np.int16)) # 2页，3行，4列，全1，指定数据类型
#
# print(np.zeros((2,3,4))) # 2页，3行，4列，全0
#
# print(np.empty((2,2,3))) # 2页，3行，3列 值取决于内存
#
# print(np.random.randint(0,3,(2,2,3))) # 大于等于0，小于3;  2页，2行3列的随机整数


# print(np.arange(1,6,2))
# print(np.arange(12))
# print(np.arange(12).reshape(3,4)) # 可以改变输出形状
# print(np.arange(24).reshape(2,3,4))# 2页，3行，4页



a = np.array([1,2,3,4])
b = np.arange(4)
print(a,b)
print(a-b)
print(a*b)
print(a**2)
print(2*np.sin(a))
print(a>2)
print(np.exp(a)) # 指数




## 矩阵运算（二维数组）
a = np.array([[1,2],[3,4]]) # 2行2列
b = np.arange(6).reshape((2,-1)) # 2行3列
print(a.dot(b)) # 2行3列










