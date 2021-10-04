def remove_duplicates(lista):
  lista2=[]
  for item in lista:
    if item not in lista2:
      lista2.append(item)
      
  return lista2
print(remove_duplicates([1,2,3,4]))
