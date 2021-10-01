import urllib.request
import urllib.error
import time
from multiprocessing import Pool
import sys
import os

start = time.time()
countries = ['us', 'hk', 'ch'] 
file = open('link', 'r')

country = 0

urls = file.readlines()

#print(urls)


def checkurl(url):
    global country
    try:
        conn = urllib.request.urlopen("https://" + url)
    except urllib.error.HTTPError as e:
        if e.code == 403:
            print("FORBIDDEN " + url)
            country = country + 1
            os.system("windscribe connect " + countries[country%3])
            
            checkurl(url)
        print('HTTPError: {}'.format(e.code) + ', ' + url)

    else:
        print('good' + ', ' + url)
        with open("result.txt", "w") as result:
                result.write("LINK IS HERE: " + url)
        sys.exit(1)


if __name__ == "__main__":
    p = Pool(processes=40)
    result = p.map(checkurl, urls)

print("done in : ", time.time()-start)