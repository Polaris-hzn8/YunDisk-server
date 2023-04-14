# HTTP协议

---

### 一、web服务器处理请求

#### 1.静态请求

客户端访问服务器的静态网页, 不涉及任何数据的处理, 如下面的URL:

```http
http://localhsot/login.html
```

#### 2.动态请求

客户端会将数据提交给服务器

```http
# 使用get方式提交数据得到的url
http://localhost/login?user=zhang3&passwd=123456&age=12&sex=man
	- http: 协议
	- localhost: 域名
	- /login: 服务器端要处理的指令
	- ? : 连接符, 后边的内容是客户端给服务器提交的数据
	- & : 分隔符
动态的url如何找服务器端处理的指令?
- 去掉协议
- 去掉域名/IP
- 去掉端口
- 去掉?和它后边的内容
# 如果看到的是请求行, 如何找处理指令?
POST /upload/UploadAction HTTP/1.1
GET /?username=tom&phone=123&email=hello%40qq.com&date=2018-01-01&sex=male&class=3&rule=on HTTP/1.1
1. 找请求行的第二部分
	- 如果是post, 处理指令就是请求行的第二部分
	- 如果是get, 处理指令就是请求行的第二部分, ? 以前的内容
```



### 二、http协议请求与响应

#### 1.请求消息(Request)

客户端(浏览器)发送给服务器的数据格式，请求分为四部分: 请求行, 请求头, 空行, 请求数据 

- 请求行: 说明请求类型, 要访问的资源, 以及使用的http版本
- 请求头: 说明服务器要使用的附加信息
- 空行: 空行是必须要有的, 即使没有请求数据
- 请求数据: 也叫主体, 可以添加任意的其他数据

##### （1）Get方式提交数据

1. 第1行: 请求行
2. 第2-9行:   请求头(键值对)
3. 第10行: 空行
4. get方式提交数据, 没有第四部分, 提交的数据在请求行的第二部分, 提交的数据会全部显示在地址栏中

```http
GET /?username=tom&phone=123&email=hello%40qq.com&date=2018-01-01&sex=male&class=3&rule=on HTTP/1.1
Host: 192.168.26.52:6789
Connection: keep-alive
Cache-Control: max-age=0
Upgrade-Insecure-Requests: 1
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.67 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8
Accept-Encoding: gzip, deflate
Accept-Language: zh,zh-CN;q=0.9,en;q=0.8
```

##### （2）Post方式提交数据

1. 第1行: 请求行
2. 第2 -12行: 请求头 (键值对)
3. 第13行: 空行
4. 第14行: 提交的数据

```http
POST / HTTP/1.1
Host: 192.168.26.52:6789
Connection: keep-alive
Content-Length: 84
Cache-Control: max-age=0
Upgrade-Insecure-Requests: 1
Origin: null
Content-Type: application/x-www-form-urlencoded
User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/70.0.3538.67 Safari/537.36
Accept: text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8
Accept-Encoding: gzip, deflate
Accept-Language: zh,zh-CN;q=0.9,en;q=0.8

username=tom&phone=123&email=hello%40qq.com&date=2018-01-01&sex=male&class=3&rule=on
```

#### 2.响应消息(Response)

服务器给客户端发送的数据，四部分: 状态行, 消息报头, 空行, 响应正文

- 状态行: 包括http协议版本号, 状态码, 状态信息
- 消息报头: 说明客户端要使用的一些附加信息
- 空行: 空行是必须要有的
- 响应正文: 服务器返回给客户端的文本信息

1. 第一行:状态行
2. 第2 -11行: 响应头(消息报头)
3. 第12行: 空行
4. 第13-18行: 服务器给客户端回复的数据

```http
HTTP/1.1 200 Ok
Server: micro_httpd
Date: Fri, 18 Jul 2014 14:34:26 GMT
/* 告诉浏览器发送的数据是什么类型 */
Content-Type: text/plain; charset=iso-8859-1 (必选项)
/* 发送的数据的长度 */
Content-Length: 32  
Location:url
Content-Language: zh-CN
Last-Modified: Fri, 18 Jul 2014 08:36:36 GMT
Connection: close

#include <stdio.h>
int main(void)
{
    printf("hello world!\n");
    return 0;
}
```

#### 3.http状态码

状态代码有三位数字组成，第一个数字定义了响应的类别，共分五种类别:

- 1xx：指示信息--表示请求已接收，继续处理
- 2xx：成功--表示请求已被成功接收、理解、接受
- 3xx：重定向--要完成请求必须进行更进一步的操作
- 4xx：客户端错误--请求有语法错误或请求无法实现
- 5xx：服务器端错误--服务器未能实现合法的请求

