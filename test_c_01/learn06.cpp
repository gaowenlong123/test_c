//文件的操作


//文件型指针变量
FILE *fp;   //指向FILE类型结构体的指针变量

//fp = fopne("H:\\a.txt","rb");  //二进制的形式打开  。w写 a追加

fclose(fp);


//文件的读写（顺序读写

//字符读写函数         写fgetc    读fputc
//字符串读写函数       fgets    fputs
//数据块读写函数       freed    fwrite
//格式化读写函数       fscanf   fprinf



//随机读写
fseek(文件类型指针 ， 位移量 ，起始点)

ftell(文件类型指针)  //返回当前位置，相对于文件开头的位移量

ferror()  //出错检查
