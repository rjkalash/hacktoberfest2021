import qrcode
titulo=input('Title: ')
texto=input("what data do you want to enter \n ")
color_codigo=input("Code color (ingles): ")
color_fondo=input("Bacground color (ingles): ")
while True:
	porcentaje=input("The code error percent (L->7%,M->15%,Q->25%,H->30%): ")
	if (porcentaje.upper()=="L" or porcentaje.upper()=="M" or porcentaje.upper()=="Q" or porcentaje.upper()=="H"):
		break
if (porcentaje.upper()=="L"):
		qr = qrcode.QRCode(
	    	box_size=5,
	    	error_correction = qrcode.constants.ERROR_CORRECT_L,
	    	)
	    	
if (porcentaje.upper()=="M"):
		qr = qrcode.QRCode(
	    	box_size=5,
	    	error_correction = qrcode.constants.ERROR_CORRECT_M,
	   	)
	    	
if (porcentaje.upper()=="Q"):
		qr = qrcode.QRCode(
	    	box_size=5,
	    	error_correction = qrcode.constants.ERROR_CORRECT_Q,
	    	)
	    	
if (porcentaje.upper()=="H"):
		qr = qrcode.QRCode(
	    	box_size=5,
	    	error_correction = qrcode.constants.ERROR_CORRECT_H,
	    	)
	    	
	
qr.add_data(texto)
qr.make(fit=True)

img = qr.make_image(fill_color=color_codigo, back_color=color_fondo)
img.show()

opcion=input('¿Do you want to save it?(yes or no): ')
if(opcion.lower()=="yes" or opcion.lower()=="y"):
    img.save(titulo+".png")
else:
    print("coming out...")
