# Jules-Prove-VVL

El gimnasio cuenta con aproximadamente 30 entrenadores, aunque dicho número no es exacto (puede haber algunos más o menos, dependiendo de la época del año). De cada uno se registra cédula, nombre, salario base y el año en que comenzó a trabajar en el gimnasio. Puede ocurrir que algún entrenador no tenga socios asignados durante algún período de tiempo, pero en cualquier caso se mantiene registrado en el sistema. En cuanto a los socios, no existe cota máxima para la cantidad de socios que se pueden inscribir en el gimnasio. 

Hay dos tipos de socios: comunes y becados. De todos se registra cédula, nombre, valor de la cuota base y domicilio. Los socios comunes tienen un extra que abonan según qué tanto asistan al gimnasio, mientras que de los becados se registra el porcentaje de descuento de su beca, junto con la fecha en que le fue otorgada la misma. Todo socio tiene asignado un solo entrenador. 

El cálculo de la cuota mensual de cada socio varía según el mes y el tipo de socio, a saber:

Socio común: Si su extra supera el valor de su cuota base, abona únicamente el valor del extra. Si su extra es hasta el 75% de su cuota base, abona la suma de ambos y si su extra es de hasta el 25% de la cuota base, abona el valor de la cuota base más la mitad del valor del extra. Si es el mes 1 (enero) o 2 (febrero), se le descuenta un 20% al total de la cuota por tratarse de meses con poca asistencia al gimnasio. 
Socio becado: Si la fecha en que le fue otorgada su beca es posterior al 28/2/2025, su cuota mensual corresponde a la cuota base menos el porcentaje de descuento que posee. Si la beca le fue otorgada hasta el 28/2/2025 inclusive, entonces corresponde a la cuota base menos la mitad del porcentaje de descuento que posee. Si es el mes 1 (enero) o 2 (febrero), se le descuenta un 30% al total de la cuota por tratarse de meses con poca asistencia.

Requerimiento 1

Registrar un nuevo entrenador, verificando que no exista otra persona con la misma cédula
Entrada:
Entrenador
Salida:
Entrenador registrado en el sistema
Proceso:
Si la cédula del entrenador se encuentra en el diccionario de Entrenadores
     Error: Ese entrenador ya existe
Sino 
     Si la cédula del entrenador se encuentra en el diccionario de Socios
         Error: Ya existe un socio con esa cedula
     Sino
         Agregar el entrenador en el diccionario de Entrenadores
     FinSi
FinSi


Requerimiento 2
 
Registrar un nuevo socio, dados sus datos y la cédula del entrenador a asignarle, verificando que no exista otra persona con la misma cédula. También se debe verificar que el entrenador que se le va a asignar efectivamente exista.
Entrada:
Socio
Salida:
Socio registrado en el sistema
Proceso:
Si la cédula del socio se encuentra en el diccionario de Socios
     Error: Ese socio ya existe
Sino 
 Si la cédula del Socio se encuentra en el diccionario de Entrenadores
     Error: ya existe entrenador con esa cedula 
 Sino
    Si la cédula del entrenador se encuentra en el diccionario de Entrenadores
         Agregar el entrenador al socio
         Agregar el socio en el diccionario de Socios
    Sino
        Error: Entrenador no existe
    FinSi
  FinSi
FinSi


Requerimiento 3

Listar todos los entrenadores registrados. No se pide ningún orden en particular para este listado. De cada entrenador se listará cédula, nombre, salario base y año de comienzo. Los datos de un mismo entrenador se listarán en una misma línea. 
Entrada:
Iterador
Salida:
Iterador con todos los entrenadores registrados 
Proceso:
Si el diccionario de entrenadores está vacío                                                                                    
    Error:No hay entrenadores registrados 
Sino 
     Para cada entrenador 
       cargar entrenador en el iterador 
     FinPara
     Devolver: El iterador
FinSi


Requerimiento 4

Listar datos básicos de todos los socios registrados. Este listado se realizará ordenado por cédula, de menor a mayor. De cada socio se listará únicamente cédula, nombre y tipo de socio. Los datos de un mismo socio se listarán en una misma línea. 
Entrada:
Iterador
Salida:
Iterador cargado
Proceso:
Si el diccionario de socios está vacío                                                                                    
    Error:No hay socios registrados 
Sino 
     Para cada socio
       Cargar socio en el iterador 
     FinPara
     Devolver: El iterador
FinSi


Requerimiento 5

Listar un socio en detalle. Dada la cédula del socio, listar todos sus datos, incluyendo también el tipo del socio, verificando que el socio con esa cédula efectivamente exista. También se deben listar los datos de su entrenador asignado. 
Entrada:
Cédula del socio 
Salida:
Información del socio e información de su entrenador 
Proceso:
Si el socio no está en el diccionario de Socios
   Error: “No existe un socio con esa cedula”
Sino 
   Devolver: Información del Socio y la información de su Entrenador 
FinSi


Requerimiento 6

Dados un mes (número entero entre 1 y 12) y la cédula de un socio, calcular el monto de su cuota mensual correspondiente a ese mes, verificando que el socio efectivamente exista. 
Entrada:
Mes entre 1 al 12 y cédula de un Socio
Salida:
Monto de su cuota mensual correspondiente a ese mes
Proceso:
Si la cédula del socio no se encuentra en el diccionario de Socios
     Error: Ese socio no existe
Sino 
     Calcula su cuota mensual de manera polimórfica para ese mes
FinSi


Requerimiento 7

Dado un mes (número entero entre 1 y 12), calcular el monto total a percibir por el gimnasio por concepto de cobro de cuota mensual a todos sus socios en dicho mes. 
Entrada:
Un número de mes entre 1 y 12 
Salida:
Total de cobro a final del mes a recibir por el gimnasio 
Proceso:
Si el diccionario de socios está vacío
  Devolver 0
Sino
  Para cada socio
    Calcular su cuota mensual de manera polimórfica para ese mes y sumar en un monto
  FinPara
  Devolver monto
FinSi


Requerimiento 8

Dada una fecha, contar cuántos de los socios becados actualmente registrados son tales que su beca fue otorgada después de esa fecha.  
Entrada:
Fecha
Salida:
Cantidad de socios becados luego de esa fecha 
Proceso:
Si el diccionario de socios está vacío
  Devolver: 0 
 Sino
   Para cada socio en el diccionario de socios
     Si el socio es becado
         Si fue becado luego de la fecha dada 
             Sumar uno al contador 
         FinSI
     FinSi
   FinPara
   Devolver: contador 
FinSI


Requerimiento 9

Dado un año (número entero mayor que cero), contar cuántos de los entrenadores actualmente registrados entraron a trabajar al gimnasio a partir de dicho año. Devolver además el promedio de salarios base de todos ellos. 
Entrada:
Número entero mayor a 0
Salida:
Cantidad de entrenador y promedio de salario base de los entrenadores 
Proceso:
Si el diccionario de entrenadores está vacío
   devolver:0 y 0
Sino
  Para cada entrenador en el diccionario de entrenadores 
     Sumar uno al contador y sumar su salario base al monto 
  FinPara
  Si contador es 0
         Devolver: Contador y 0
  Sino
         Devolver: contador y monto/contador
  FinSi
FinSI


Requerimiento 10

Dado un mes (número entero entre 1 y 12), listar en detalle los datos del socio cuya cuota mensual haya sido la más alta de todo el gimnasio en dicho mes, verificando que haya al menos un socio registrado. Si hay dos o más socios con la cuota más alta, alcanza con listar cualquiera de ellos.
Entrada:
Un número de mes entre 1 y 12 
Salida:
Socio con mayor cuota en el mes
Proceso:
Si el diccionario de socios está vacío
     Error: No hay socios
Sino
       Calcular cuota mensual de manera polimórfica para ese mes del primer socio que se encuentre y acumularlo como socio con mayor couta
       Para cada socio posterior al primero
           Calcular su cuota mensual de manera polimórfica para ese mes y acumularlo en un segundo monto
           Si el segundo monto es mayor al anteriormente acumulado
                    Acumular al socio actual con mayor cuota
           FinSi
       FinPara
       Devolver: Socio con mayor cuota
FinSi

