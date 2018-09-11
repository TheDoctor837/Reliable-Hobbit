###################################################
#
#       Ian McNulty
#       09/06/2018
#       Price Evaluation
#       Gives final price, based on local tax, 
#   location, and initial price
#
###################################################

# Function for final price
def price(meal, tax = 0, tip = 0):
    price = meal + (meal*(tax/100)) + (meal*(tip/100))
    return price

# Main function
def give_price():

# Ask for initial listed price of meal
    initial_price = float(input("What is the initial price of your order? "))
    
# Asks for sales tax in state
    sales_tax = float(input("Enter the local tax rate. "))

# Asks whether you went to a restaurant or a store
    ask = input("\nDid you go to a restaurant or a store? ")

#  For Restaurants:
    if ask == "restaurant" or ask == "Restaurant" or ask == "r" or ask == "R":
        tip_amount = float(input("Enter the tip percentage. "))
        final_price = float(price(initial_price, sales_tax, tip_amount))
#  For Stores:
    elif ask == "store" or ask == "Store" or ask == "s" or ask == "S":
        print("Your price is coming right up!")
        final_price = float(price(initial_price, sales_tax))
#  If there is no actual answer it loops back to start
    else:
        print("\nPlease type restaurant or store".upper())
        give_price()

# This will give the final price
    return final_price

# This will print the final price
print("\nYour final price is " + str(round(give_price(),2)))