print("FBS")
print("A fasting blood sugar (FBS) level is the result of a blood sample taken after a patient fasts for at least eight hours.")
fbs = int(input("Please enter your FBS: "))
if fbs < 100:
    print("A fasting blood sugar level less than 100 mg/dL (5.6 mmol/L) is normal")
elif fbs <= 125 and fbs >= 100:
    print(" A fasting blood sugar level from 100 to 125 mg/dL (5.6 to 6.9 mmol/L) is considered prediabetes.")
else:
    print("If it's 126 mg/dL (7 mmol/L) or higher on two separate tests, you have diabetes.")
