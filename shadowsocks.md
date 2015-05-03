shadowsocks的配置方法
1.下载python-pip，用来下载shadowsocks，命令sudo apt-get install python-pip
2.下载shadowsocks,命令sudo pip install shadowsocks
3.You can use a configuration file instead of command line arguments.

Create a config file /etc/shadowsocks.json. Example:

{
    "server":"my_server_ip",
	"server_port":8388,
    "local_address": "127.0.0.1",
	"local_port":1080,
	"password":"mypassword",
	"timeout":300,
	"method":"aes-256-cfb",
	"fast_open": false
}
4.在浏览器上设置代理，如火狐上get add-ons 搜autoprosy安装后设置edit socks5
5.开shadowsocks，命令sslocal -c /etc/shadowsocks.json
