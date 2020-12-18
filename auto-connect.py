from requests import request 
from bs4 import BeautifulSoup as soup 
from threading import Timer

def check():
    rq = request("GET","http://172.16.0.1:8002/index.php?zone=wifi&redirurl=http%3A%2F%2Fwww.msftconnecttest.com%2Fredirect")
    content = soup(rq.content, "html.parser").text
    return content

if(check() != "You are connected."):
    rq = request("POST","http://172.16.0.1:8002/index.php?zone=wifi")
    content = soup(rq.content, "html.parser").text
    printf(content)
else:
    print(check())
