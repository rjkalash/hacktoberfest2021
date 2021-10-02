import math
V = float(input("Enter the storage capacity:"))
Pi = float(input("Enter the operating internal pressure:"))
fs = float(input("Enter the factor of safety:"))
Sut = float(input("Enter the ultimate tensile strength of the material:"))
# Calculating diameter and length of the cylinder
x = (3*V)/(2*3.14)
Di = (round(pow(x,1/3),1))*1000
L = 2*Di
# Calculating Tc (Thickness of cylindrical portion), Th (Thickness of
hemispherical ends)
tensile_stress = Sut/fs
Tc = math.ceil((Pi*Di)/(2*tensile_stress))
Th = math.ceil((Pi*Di)/(4*tensile_stress))
print("Diameter of Cylindrical portion is:",Di,"mm")
print("Length of Cylindrical Portion is:",L,"mm")
print("Thickness of cylindrical portion is:",Tc,"mm")
print("Thickness of hemispherical ends is:",Th,"mm")
