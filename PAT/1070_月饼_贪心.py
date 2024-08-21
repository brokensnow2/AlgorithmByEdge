N, D = map(int, input().split())
inventory = list(map(float, input().split()))
prices = list(map(float, input().split()))
# rate = [prices[i]/inventory[i] for i in range(N)]

class mooncake(object):
    def __init__(self, inventory :float, price :float) -> None:
        self.inventory = inventory
        self.price = price
        self.rate = price / inventory

mooncakes = []
for i in range(N):
    mooncakes.append(mooncake(inventory[i], prices[i]))

mooncakes.sort(key = lambda x : x.rate, reverse=True)

sum = 0

for i in range(N):
    if D > mooncakes[i].inventory:
            sum += mooncakes[i].price
            D -= mooncakes[i].inventory
    else:
        sum += D * mooncakes[i].rate
        D = 0
        break

print(f"{sum :.2f}")