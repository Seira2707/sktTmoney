import requests

def get_ticker_price(market):
    url = f"https://api.upbit.com/v1/ticker?markets={market}"
    headers = {"accept": "application/json"}
    response = requests.get(url, headers=headers)
    data = response.json()
    return data[0]['trade_price']


btc_price = get_ticker_price("KRW-BTC")
lsk_price = get_ticker_price("KRW-LSK")
neo_price = get_ticker_price("KRW-NEO")
mtl_price = get_ticker_price("KRW-MTL")
xrp_price = get_ticker_price("KRW-XRP")
eth_price = get_ticker_price("KRW-ETH")
qtum_price = get_ticker_price("KRW-QTUM")

print(f"비트코인 현재 가격{btc_price}")
print(f"이더리움 현재 가격{eth_price}")
print(f"네오 현재 가격{neo_price}")
print(f"퀌텀 현재 가격{qtum_price}")
print(f"메탈 현재 가격{mtl_price}")
print(f"리스크 현재 가격{lsk_price}")
print(f"리플 현재 가격{xrp_price}")

filePath = 'C:\\Users\\user\\Desktop\\Project1\\Project1\\UpBitApi.txt'
with open(filePath, "w") as f:
    f.write(str(btc_price))
    f.write("\n")
    f.write(str(eth_price))
    f.write("\n")
    f.write(str(neo_price))
    f.write("\n")
    f.write(str(qtum_price))
    f.write("\n")
    f.write(str(mtl_price))
    f.write("\n")
    f.write(str(lsk_price))
    f.write("\n")
    f.write(str(xrp_price))