#{filter},{generate}
from pymongo import MongoClient
from work import plot
from work import connectMongo


collection = connectMongo()	

a = list(collection.find({},{u'somedata.price',u'somedata.trade_type',u'somedata.tid'}))

ask = []
bid = []
tid = []

for e in a:
	if 'somedata' in e.keys():
		for price in  e['somedata']:
		  if price['trade_type'] == 'ask':
#			print price['price'] , price['trade_type'], price['tid']
			ask.append(price['price'])

		  else:
#			print price['price'] , price['trade_type'] , price['tid']
			bid.append(price['price'])
			
#	print ''

print len(bid) , len(ask) , len(bid)-len(ask)
_graph = plot(ask,bid)
