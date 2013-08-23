import os
import numpy as np
import matplotlib.mlab as mlab
import matplotlib.pyplot as plt
from  pymongo import MongoClient


def connectMongo():
 client = MongoClient
 client = MongoClient('localhost', 27017)
 db = client.test
 collection = db.trades
 return collection

def removeDocuments():

 client = MongoClient
 client = MongoClient('localhost', 27017)
 db = client.test
 collection = db.trades
 collection.drop()


def plot(bid,ask):

#    fig = plt.figure()
    ax1 = plt.subplot2grid((2,4), (0,0), colspan=4)
	
    Ys_1 = map(float,bid)
    Ys_2 = map(float,ask)

    bid_mean = np.mean(Ys_1)
    bid_std  = np.std(Ys_1)
    ask_mean = np.mean(Ys_2)
    ask_std  = np.std(Ys_2)

    
    print  '***********'
    print 'bid_mu '+str(bid_mean)+' bid_std '+str(bid_std)
    print 'ask_mu '+str(ask_mean)+' ask_std '+str(ask_std)
    print  '***********'
    N = len(Ys_1)
    ind = np.arange(N)
    
    N2 = len(Ys_2)
    ind2 = np.arange(N2)    

    ax1.grid(True)
    ax1 = plt.title('Bid - Ask')
    ax1 = plt.scatter(ind,Ys_1,color = 'b')
    ax1 = plt.scatter(ind2,Ys_2,color = 'r')
#    ax1 = plt.scatter([min(Ys_2), max(Ys_2), 0, len(Ys_2)])
   

    ax2 = plt.subplot2grid((2,4), (1, 0),colspan = 4) 
    n, bins, patches = ax2.hist(Ys_1, 20, facecolor='blue', alpha=0.75)
    n, bins, patches = ax2.hist(Ys_2, 20, facecolor='red', alpha=0.75)
    bincenters = 0.2*(bins[1:]+bins[:-1])
#    y = mlab.normpdf( bincenters, bid_mean, bid_std)
#    l = ax2.plot(bincenters, y, 'r--', linewidth=1)
    
    minval = np.min(Ys_1)
    maxval = np.max(Ys_1)
    ax2.set_xlim(minval, maxval)
    ax2.grid(True)
   
#    ax3 = plt.subplot2grid((2,4), (1, 2),colspan = 2)
#    n, bins, patches = ax3.hist(Ys_2, 20, facecolor='red', alpha=0.75)
#    bincenters = 0.2*(bins[1:]+bins[:-1])
#    y = mlab.normpdf( bincenters, ask_mean, ask_std)
#    l = ax3.plot(bincenters, y, 'r--', linewidth=1)

#    minval2 = np.min(Ys_2)	
#    maxval2 = np.max(Ys_2)
#    ax3.set_xlim(minval2, maxval2)
#    ax3.grid(True)
 
    savepath = os.path.join('test')
    plt.savefig(savepath)
