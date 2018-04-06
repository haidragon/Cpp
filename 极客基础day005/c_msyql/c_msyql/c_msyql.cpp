// c_msyql.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 1. 包含头文件和库文件
// 1.1 将mysql的include目录设置到项目的包含目录中.
#include <mysql.h>

#pragma comment(lib,"msyql\\lib\\libmysql.lib")



int main(int argc,char** argv)
{
	// 2. 初始化mysql库
	mysql_library_init(argc,argv,nullptr );

	// 3. 初始化msyql对象
	MYSQL mysql = { 0 };
	MYSQL* _this = &mysql;
	mysql_init( _this );

	// 4. 使用msyql对象连接到数据库
	mysql_real_connect( _this ,
		"192.168.40.129" ,
		"root" ,
		"123456" ,
		"15pbChatroom" ,
		3306 ,
		0 , 0 );
	if( mysql_errno( _this ) != 0 ) {
		printf( "连接到mysql失败:%s\n" ,
			mysql_error( _this ) );
		return 0;
	}

	// 5. 执行msyql语句
	mysql_query( _this , "SET NAMES GBK" );
	char sql[ 300 ];
	sprintf_s( sql , 300 ,
		"insert into 用户表(name,height,age,classroomid) values(\"%s\",%lf,%d,%d);" ,
		"如花" , 1.8 , 18 , 2 );

	mysql_query( _this , sql );

	// 6. 解析msyql语句返回结果集
	mysql_query( _this , "select * from 用户表;" );
	MYSQL_RES*   res = NULL;
	MYSQL_FIELD* pField = NULL;
	int nNumOfField = 0;
	// mysql_store_result :		取出包含全部行结果集
	// 取出结果集(只能取出一行结果集)
	//res = mysql_use_result( _this );
	res = mysql_use_result(_this);
	if( res == NULL ) {
		printf( "连接到mysql失败:%s\n" ,
			mysql_error( _this ) );
		return 0;
	}
	// 6.1 解析结果集中的列
	// 6.1.1 获取列的个数
	nNumOfField = mysql_num_fields( res );
	// 6.1.2 获取每列的名字
	for( int i = 0; i < nNumOfField; ++i ) {
		// 每次循环都会得到一个字段
		pField = mysql_fetch_field( res );
		printf( "%s | " , pField->name );
	}
	printf( "\n" );

	// 6.2 解析结果集中的行
	do {
		// 结果集中的每一行实际是用一个指针数组保存的
		// 数组中的每个元素都是一个字符串指针, 每个指针
		// 指向一行中的列的文本
		MYSQL_ROW pRow = mysql_fetch_row( res );
		for( int i = 0; i < nNumOfField; ++i ) {
			if( pRow[ i ] != nullptr ) {
				printf( "%s | " , pRow[ i ] );
			}
			else {
				printf( "(NULL) | " );
			}
		}
		printf( "\n" );
		mysql_free_result( res );//释放结果集
	} while( (res = mysql_use_result(_this)) != NULL );


	mysql_library_end( );
    return 0;
}

