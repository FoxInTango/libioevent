/*
 * libioevent
 *
 * Copyright (C) 2021 FoxInTango <foxintango@yeah.net>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 */
#ifndef _IO_SOCKET_H_foxintango
#define _IO_SOCKET_H_foxintango

#include <libcpp/libcpp.h>

namespaceBegin(foxintango)

typedef int IO_SOCKET_TYPE;

const IO_SOCKET_TYPE IO_SOCKET_TYPE_UDP     = 0x00000000;
const IO_SOCKET_TYPE IO_SOCKET_TYPE_TCP     = 0x00000001;
const IO_SOCKET_TYPE IO_SOCKET_TYPE_UNIX    = 0x00000010;
const IO_SOCKET_TYPE IO_SOCKET_TYPE_NETLINK = 0x00000100;

const int IO_SOCKET_TLS_FLAG     = 0x10000000;

class IOSocket {
public:
public:
    IOSocket();
   ~IOSocket();
public:
   int read();
   int write();
};

// SSL Socket https://wiki.openssl.org/index.php/Simple_TLS_Server
//            https://wiki.openssl.org/index.php/Category:Examples
//            https://halfrost.com/https-extensions/
//            https://www.cnblogs.com/jiangzhaowei/p/9341466.html
//            https://www.jianshu.com/p/527cc683b2be
//            https://blog.csdn.net/mrpre/article/details/77867439

/** tls 扩展 SNI  https://blog.csdn.net/justinzengTM/article/details/105346262
 *  SNI扩展是用来解决一台服务器绑定多个域名，申请了多张证书，在建立连接的身份验证阶段服务器因为不知道客户端浏览器访问的是哪个域名，所以无法判断该发送哪个证书的问题。即服务器使用到了“虚拟主机”的场景
 *  https://www.cnblogs.com/sxiszero/p/11153112.html
 *  https://blog.csdn.net/danielzhou1025/article/details/114115151 SSL_set_cipher_list
 *  https://strawberrytree.top/blog/2020/09/17/%E4%BD%BF%E7%94%A8openssl%E4%BD%BF%E7%94%A8%E5%A4%96%E9%83%A8psk%E8%BF%9B%E8%A1%8C%E6%8F%A1%E6%89%8B%EF%BC%88tls1-3%EF%BC%89/
 *  双向认证：SSL_CTX_load_verify_locations
 *  https://blog.csdn.net/wangsifu2009/article/details/7569566
 *  https://www.cnblogs.com/lsdb/p/9391979.html
 *  双向认证模式:
 *  https://blog.csdn.net/u013919153/article/details/78616737
 * 
 *  https://halfrost.com/https-begin/
 *  https://strawberrytree.top/blog/2020/09/28/%E4%BD%BF%E7%94%A8openssl%E5%86%85%E7%BD%AE%E7%9A%84%E5%AF%86%E7%A0%81%E7%AE%97%E6%B3%95%E5%AE%9A%E4%B9%89%E6%96%B0%E7%9A%84%E5%8A%A0%E5%AF%86%E5%A5%97%E4%BB%B6-tls1-3/
 */

/**
 * cer 用于存储公钥证书的文件格式
 */

namespaceEnd
#endif
