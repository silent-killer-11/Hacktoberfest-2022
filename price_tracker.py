import requests
from bs4 import BeautifulSoup
from dotenv import load_dotenv
import time
import os
from datetime import datetime
from dhooks import Webhook

load_dotenv()
URL_FLIPKART = os.environ.get("URL_FLIPKART")
URL_AMAZON = os.environ.get("URL_AMAZON")
WEBHOOK_URL = os.environ.get("WEBHOOK_URL")
hook = Webhook(WEBHOOK_URL)

user_agent = {"User-Agent" : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/79.0.3945.117 Safari/537.36'}

def flipkart():
    req = requests.get(URL_FLIPKART, headers=user_agent)
    htmlContent = req.content
    soup = BeautifulSoup(htmlContent, 'html.parser')
    new_flipkart_price = (soup.find("div", class_="_30jeq3 _16Jk6d")).get_text().replace("₹","INR. ")
    if os.path.exists('flipkart_price.txt'):
        print("Exists")
        f = open('flipkart_price.txt',"r+")
        old_price = f.read()
        f.close()
        if(old_price!=new_flipkart_price):
            print("Old Flipkart Price : ",old_price)
            print("New Flipkart Price = ",new_flipkart_price)
            content=("**Hey Subham**, \n**Price has been changed in Flipkart** \n_OLD PRICE_ = {} \n_NEW PRICE_ = {} ".format(old_price,new_flipkart_price))
            hook.send(content)
            f = open('flipkart_price.txt',"r+")
            f.write(str(new_flipkart_price))
            f.close()
        else:
            print("Same price")
    else:
        f = open('flipkart_price.txt', 'w')
        f.write(str(new_flipkart_price))
        f.close()

def amazon():
    req = requests.get(URL_AMAZON, headers=user_agent)
    htmlContent = req.content
    try:
        soup = BeautifulSoup(htmlContent, 'html.parser')
        new_amazon_price = (soup.find("span", class_="a-offscreen")).get_text().replace("₹","INR. ")
        if os.path.exists('amazon_price.txt'):
            print("Exists")
            f = open('amazon_price.txt',"r+")
            old_price = f.read()
            f.close()
            if(old_price!=new_amazon_price):
                print("Old Amazon Price : ",old_price)
                print("New Amazon Price = ",new_amazon_price)
                content=("**Hey Subham**, \n**Price has been changed in Amazon** \n_OLD PRICE_ = {} \n_NEW PRICE_ = {} ".format(old_price,new_amazon_price))
                hook.send(content)
                f = open('amazon_price.txt',"r+")
                f.write(str(new_amazon_price))
                f.close()
            else:
                print("Same price")
        else:
            f = open('amazon_price.txt', 'w')
            f.write(str(new_flipkart_price))
            f.close()
    except:
        print("Amazon data couldn't be fetched :( ")

if __name__=="__main__":
    print("Welcome to Price Tracker")
    while True:
        now = datetime.now()
        time = now.strftime("%I:%M")
        time.sleep(10)
        print(time)
        if(time=="12:00" or time=="06:00"):
            flipkart()
            amazon()
