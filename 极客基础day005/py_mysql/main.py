# encoding:utf-8
import pymysql

# 1. 连接到mysql服务器
con = pymysql.connect(host='192.168.40.129',
                port = 3306,
                user = 'root',
                passwd='123456',
                db='15pbchatroom',
                charset='utf8mb4',  # 编码
                cursorclass=pymysql.cursors.DictCursor  # 游标类型
                )

# 2. 执行语句
# 2.1 得到游标对象
cursor = con.cursor()
cursor.execute('insert into 用户表(name,height,age,classroomid) values("%s",%lf,%d,%d)'%('大哥',1.5,18,2))
# 插入或更新数据时,需要执行commit提交语句.
cursor.execute('commit;')

cursor.execute('select * from 用户表;')

# 3. 解析结果集
for row in cursor.fetchall(): # 得到一个列表,列表中的而每个元素是字典对象
    # 遍历字典对象的所有元素,字典保存的元素
    # 就是以列为键的名字,键对应的值就是列的内容
    for key, value in row.items():
        print value , ' ',
    print


