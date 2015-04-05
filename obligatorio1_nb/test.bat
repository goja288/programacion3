@echo off
echo Corriendo 1. TestGonza
principal.exe < Test\TestGonza\test00_gonza.in > Test\TestGonza\Salidas\test00_gonza.sal
principal.exe < Test\TestGonza\test01_gonza.in > Test\TestGonza\Salidas\test01_gonza.sal
principal.exe < Test\TestGonza\test02_gonza.in > Test\TestGonza\Salidas\test02_gonza.sal
principal.exe < Test\TestGonza\test03_gonza.in > Test\TestGonza\Salidas\test03_gonza.sal
move test00_gonza1_abb.txt Test\TestGonza\Salidas\
move test00_gonza1_cola.txt Test\TestGonza\Salidas\
move test00_gonza1_pila.txt Test\TestGonza\Salidas\
move test00_gonza2_abb.txt Test\TestGonza\Salidas\
move test00_gonza2_cola.txt Test\TestGonza\Salidas\
move test00_gonza2_pila.txt Test\TestGonza\Salidas\
move test01_gonza1_abb.txt Test\TestGonza\Salidas\
move test01_gonza1_cola.txt Test\TestGonza\Salidas\
move test01_gonza1_pila.txt Test\TestGonza\Salidas\
move test01_gonza2_abb.txt Test\TestGonza\Salidas\
move test01_gonza2_cola.txt Test\TestGonza\Salidas\
move test01_gonza2_pila.txt Test\TestGonza\Salidas\
move test02_gonza1_abb.txt Test\TestGonza\Salidas\
move test02_gonza1_cola.txt Test\TestGonza\Salidas\
move test02_gonza1_pila.txt Test\TestGonza\Salidas\
move test02_gonza2_abb.txt Test\TestGonza\Salidas\
move test02_gonza2_cola.txt Test\TestGonza\Salidas\
move test02_gonza2_pila.txt Test\TestGonza\Salidas\
move test03_gonza1_abb.txt Test\TestGonza\Salidas\
move test03_gonza1_cola.txt Test\TestGonza\Salidas\
move test03_gonza1_pila.txt Test\TestGonza\Salidas\
move test03_gonza2_abb.txt Test\TestGonza\Salidas\
move test03_gonza2_cola.txt Test\TestGonza\Salidas\
move test03_gonza2_pila.txt Test\TestGonza\Salidas\

echo Corriendo 2. Arbol
principal.exe < Test\Arbol\MAX\Arbol1MAX.in > Test\Arbol\MAX\Salidas\Arbol1MAX.sal
principal.exe < Test\Arbol\MAX\Arbol2MAX.in > Test\Arbol\MAX\Salidas\Arbol2MAX.sal
principal.exe < Test\Arbol\MAX\Arbol3MAX.in > Test\Arbol\MAX\Salidas\Arbol3MAX.sal
principal.exe < Test\Arbol\MAX\Arbol4MAX.in > Test\Arbol\MAX\Salidas\Arbol4MAX.sal
principal.exe < Test\Arbol\MAX\Arbol5MAX.in > Test\Arbol\MAX\Salidas\Arbol5MAX.sal
principal.exe < Test\Arbol\MAX\Arbol6MAX.in > Test\Arbol\MAX\Salidas\Arbol6MAX.sal
principal.exe < Test\Arbol\MAX\Arbol7MAX.in > Test\Arbol\MAX\Salidas\Arbol7MAX.sal
principal.exe < Test\Arbol\min\Arbol1min.in > Test\Arbol\min\Salidas\Arbol1min.sal
principal.exe < Test\Arbol\min\Arbol2min.in > Test\Arbol\min\Salidas\Arbol2min.sal
principal.exe < Test\Arbol\min\Arbol3min.in > Test\Arbol\min\Salidas\Arbol3min.sal
principal.exe < Test\Arbol\min\Arbol4min.in > Test\Arbol\min\Salidas\Arbol4min.sal
principal.exe < Test\Arbol\min\Arbol5min.in > Test\Arbol\min\Salidas\Arbol5min.sal
principal.exe < Test\Arbol\min\Arbol6min.in > Test\Arbol\min\Salidas\Arbol6min.sal
principal.exe < Test\Arbol\min\Arbol7min.in > Test\Arbol\min\Salidas\Arbol7min.sal

echo Corriendo 3. Letra
principal.exe < Test\Letra\Letra.in > Test\Letra\Letra.sal
move ejemplo_abb.txt Test\Letra\Salidas\
move ejemplo_cola.txt Test\Letra\Salidas\
move ejemplo_pila.txt Test\Letra\Salidas\

echo Corriendo 4. Persistencia
principal.exe < Test\Persistencia\Persistencia.in > Test\Persistencia\Salidas\Persistencia.sal
move Persistencia_abb.txt Test\Persistencia\Salidas\
move Persistencia_cola.txt Test\Persistencia\Salidas\
move Persistencia_pila.txt Test\Persistencia\Salidas\

echo Corriendo 5. TestsPriViejos
principal.exe < Test\TestsPriViejos\prueba1.in > Test\TestsPriViejos\Salidas\prueba1.sal
principal.exe < Test\TestsPriViejos\prueba3.in > Test\TestsPriViejos\Salidas\prueba3.sal
principal.exe < Test\TestsPriViejos\prueba4.in > Test\TestsPriViejos\Salidas\prueba4.sal
principal.exe < Test\TestsPriViejos\prueba5.in > Test\TestsPriViejos\Salidas\prueba5.sal
principal.exe < Test\TestsPriViejos\prueba6.in > Test\TestsPriViejos\Salidas\prueba6.sal
principal.exe < Test\TestsPriViejos\prueba8.in > Test\TestsPriViejos\Salidas\prueba8.sal
principal.exe < Test\TestsPriViejos\prueba9.in > Test\TestsPriViejos\Salidas\prueba9.sal
principal.exe < Test\TestsPriViejos\prueba10.in > Test\TestsPriViejos\Salidas\prueba10.sal
move prueba1_abb.txt Test\TestsPriViejos\Salidas\
move prueba1_cola.txt Test\TestsPriViejos\Salidas\
move prueba1_pila.txt Test\TestsPriViejos\Salidas\
move prueba3_abb.txt Test\TestsPriViejos\Salidas\
move prueba3_cola.txt Test\TestsPriViejos\Salidas\
move prueba3_pila.txt Test\TestsPriViejos\Salidas\
move prueba4_abb.txt Test\TestsPriViejos\Salidas\
move prueba4_cola.txt Test\TestsPriViejos\Salidas\
move prueba4_pila.txt Test\TestsPriViejos\Salidas\
move prueba5_abb.txt Test\TestsPriViejos\Salidas\
move prueba5_cola.txt Test\TestsPriViejos\Salidas\
move prueba5_pila.txt Test\TestsPriViejos\Salidas\
move prueba6_abb.txt Test\TestsPriViejos\Salidas\
move prueba6_cola.txt Test\TestsPriViejos\Salidas\
move prueba6_pila.txt Test\TestsPriViejos\Salidas\
move prueba8_abb.txt Test\TestsPriViejos\Salidas\
move prueba8_cola.txt Test\TestsPriViejos\Salidas\
move prueba8_pila.txt Test\TestsPriViejos\Salidas\
move prueba9_abb.txt Test\TestsPriViejos\Salidas\
move prueba9_cola.txt Test\TestsPriViejos\Salidas\
move prueba9_pila.txt Test\TestsPriViejos\Salidas\
move prueba10_abb.txt Test\TestsPriViejos\Salidas\
move prueba10_cola.txt Test\TestsPriViejos\Salidas\
move prueba10_pila.txt Test\TestsPriViejos\Salidas\

echo Corriendo 6. TestsPubViejos
principal.exe < Test\TestsPubViejos\prueba1.in > Test\TestsPubViejos\Salidas\prueba1.sal
principal.exe < Test\TestsPubViejos\prueba2.in > Test\TestsPubViejos\Salidas\prueba2.sal
principal.exe < Test\TestsPubViejos\prueba3.in > Test\TestsPubViejos\Salidas\prueba3.sal
principal.exe < Test\TestsPubViejos\prueba4.in > Test\TestsPubViejos\Salidas\prueba4.sal
move prueba1_abb.txt Test\TestsPubViejos\Salidas\
move prueba1_cola.txt Test\TestsPubViejos\Salidas\
move prueba1_pila.txt Test\TestsPubViejos\Salidas\
move prueba2_abb.txt Test\TestsPubViejos\Salidas\
move prueba2_cola.txt Test\TestsPubViejos\Salidas\
move prueba2_pila.txt Test\TestsPubViejos\Salidas\
move prueba3_abb.txt Test\TestsPubViejos\Salidas\
move prueba3_cola.txt Test\TestsPubViejos\Salidas\
move prueba3_pila.txt Test\TestsPubViejos\Salidas\
move prueba4_abb.txt Test\TestsPubViejos\Salidas\
move prueba4_cola.txt Test\TestsPubViejos\Salidas\
move prueba4_pila.txt Test\TestsPubViejos\Salidas\

echo Corriendo 7. TestPub
principal.exe < Test\TestPub\prueba1.in > Test\TestPub\Salidas\prueba1.sal
principal.exe < Test\TestPub\prueba8.in > Test\TestGonza\Salidas\prueba8.sal
move prueba1_1_abb.txt Test\TestPub\Salidas\
move prueba1_1_cola.txt Test\TestPub\Salidas\
move prueba1_1_pila.txt Test\TestPub\Salidas\
move prueba1_2_abb.txt Test\TestPub\Salidas\
move prueba1_2_cola.txt Test\TestPub\Salidas\
move prueba1_2_pila.txt Test\TestPub\Salidas\

move prueba8_1_abb.txt Test\TestPub\Salidas\
move prueba8_1_cola.txt Test\TestPub\Salidas\
move prueba8_1_pila.txt Test\TestPub\Salidas\
move prueba8_2_abb.txt Test\TestPub\Salidas\
move prueba8_2_cola.txt Test\TestPub\Salidas\
move prueba8_2_pila.txt Test\TestPub\Salidas\


echo Tirando los DIFF

echo Corriendo DIFF 1. TestGonza
echo [4]********************************************************************************
fc Test\TestGonza\test00_gonza.out Test\TestGonza\Salidas\test00_gonza.sal
fc Test\TestGonza\test01_gonza.out Test\TestGonza\Salidas\test01_gonza.sal
fc Test\TestGonza\test02_gonza.out Test\TestGonza\Salidas\test02_gonza.sal
fc Test\TestGonza\test03_gonza.out Test\TestGonza\Salidas\test03_gonza.sal
echo [6]********************************************************************************
fc Test\TestGonza\test00_gonza1_abb.txt Test\TestGonza\Salidas\test00_gonza1_abb.txt
fc Test\TestGonza\test00_gonza1_cola.txt Test\TestGonza\Salidas\test00_gonza1_cola.txt
fc Test\TestGonza\test00_gonza1_pila.txt Test\TestGonza\Salidas\test00_gonza1_pila.txt
fc Test\TestGonza\test00_gonza2_abb.txt Test\TestGonza\Salidas\test00_gonza2_abb.txt
fc Test\TestGonza\test00_gonza2_cola.txt Test\TestGonza\Salidas\test00_gonza2_cola.txt
fc Test\TestGonza\test00_gonza2_pila.txt Test\TestGonza\Salidas\test00_gonza2_pila.txt
echo [6]********************************************************************************
fc Test\TestGonza\test01_gonza1_abb.txt Test\TestGonza\Salidas\test01_gonza1_abb.txt
fc Test\TestGonza\test01_gonza1_cola.txt Test\TestGonza\Salidas\test01_gonza1_cola.txt
fc Test\TestGonza\test01_gonza1_pila.txt Test\TestGonza\Salidas\test01_gonza1_pila.txt
fc Test\TestGonza\test01_gonza2_abb.txt Test\TestGonza\Salidas\test01_gonza2_abb.txt
fc Test\TestGonza\test01_gonza2_cola.txt Test\TestGonza\Salidas\test01_gonza2_cola.txt
fc Test\TestGonza\test01_gonza2_pila.txt Test\TestGonza\Salidas\test01_gonza2_pila.txt
echo [6]********************************************************************************
fc Test\TestGonza\test02_gonza1_abb.txt Test\TestGonza\Salidas\test02_gonza1_abb.txt
fc Test\TestGonza\test02_gonza1_cola.txt Test\TestGonza\Salidas\test02_gonza1_cola.txt
fc Test\TestGonza\test02_gonza1_pila.txt Test\TestGonza\Salidas\test02_gonza1_pila.txt
fc Test\TestGonza\test02_gonza2_abb.txt Test\TestGonza\Salidas\test02_gonza2_abb.txt
fc Test\TestGonza\test02_gonza2_cola.txt Test\TestGonza\Salidas\test02_gonza2_cola.txt
fc Test\TestGonza\test02_gonza2_pila.txt Test\TestGonza\Salidas\test02_gonza2_pila.txt
echo [6]********************************************************************************
fc Test\TestGonza\test03_gonza1_abb.txt Test\TestGonza\Salidas\test03_gonza1_abb.txt
fc Test\TestGonza\test03_gonza1_cola.txt Test\TestGonza\Salidas\test03_gonza1_cola.txt
fc Test\TestGonza\test03_gonza1_pila.txt Test\TestGonza\Salidas\test03_gonza1_pila.txt
fc Test\TestGonza\test03_gonza2_abb.txt Test\TestGonza\Salidas\test03_gonza2_abb.txt
fc Test\TestGonza\test03_gonza2_cola.txt Test\TestGonza\Salidas\test03_gonza2_cola.txt
fc Test\TestGonza\test03_gonza2_pila.txt Test\TestGonza\Salidas\test03_gonza2_pila.txt


echo Corriendo DIFF 2. Arbol
echo [7]********************************************************************************
fc Test\Arbol\MAX\Arbol1MAX.out Test\Arbol\MAX\Salidas\Arbol1MAX.sal
fc Test\Arbol\MAX\Arbol2MAX.out Test\Arbol\MAX\Salidas\Arbol2MAX.sal
fc Test\Arbol\MAX\Arbol3MAX.out Test\Arbol\MAX\Salidas\Arbol3MAX.sal
fc Test\Arbol\MAX\Arbol4MAX.out Test\Arbol\MAX\Salidas\Arbol4MAX.sal
fc Test\Arbol\MAX\Arbol5MAX.out Test\Arbol\MAX\Salidas\Arbol5MAX.sal
fc Test\Arbol\MAX\Arbol6MAX.out Test\Arbol\MAX\Salidas\Arbol6MAX.sal
fc Test\Arbol\MAX\Arbol7MAX.out Test\Arbol\MAX\Salidas\Arbol7MAX.sal
echo [7]********************************************************************************
fc Test\Arbol\min\Arbol1min.out Test\Arbol\min\Salidas\Arbol1min.sal
fc Test\Arbol\min\Arbol2min.out Test\Arbol\min\Salidas\Arbol2min.sal
fc Test\Arbol\min\Arbol3min.out Test\Arbol\min\Salidas\Arbol3min.sal
fc Test\Arbol\min\Arbol4min.out Test\Arbol\min\Salidas\Arbol4min.sal
fc Test\Arbol\min\Arbol5min.out Test\Arbol\min\Salidas\Arbol5min.sal
fc Test\Arbol\min\Arbol6min.out Test\Arbol\min\Salidas\Arbol6min.sal
fc Test\Arbol\min\Arbol7min.out Test\Arbol\min\Salidas\Arbol7min.sal

echo Corriendo DIFF 3. Letra
echo [4]********************************************************************************
fc Test\Letra\Letra.out Test\Letra\Letra.sal
fc Test\Letra\ejemplo_abb.txt.out Test\Letra\Salidas\ejemplo_abb.txt
fc Test\Letra\ejemplo_cola.txt.out Test\Letra\Salidas\ejemplo_cola.txt
fc Test\Letra\ejemplo_pila.txt.out Test\Letra\Salidas\ejemplo_pila.txt

echo Corriendo DIFF 4. Persistencia
echo [4]********************************************************************************
fc Test\Persistencia\Persistencia.out Test\Persistencia\Salidas\Persistencia.sal
fc Test\Persistencia\Persistencia_abb.txt.out Test\Persistencia\Salidas\Persistencia_abb.txt
fc Test\Persistencia\Persistencia_cola.txt.out Test\Persistencia\Salidas\Persistencia_cola.txt
fc Test\Persistencia\Persistencia_pila.txt.out Test\Persistencia\Salidas\Persistencia_pila.txt

echo Corriendo DIFF 5. TestsPriViejos
echo [8]********************************************************************************
fc Test\TestsPriViejos\prueba1.out Test\TestsPriViejos\Salidas\prueba1.sal
fc Test\TestsPriViejos\prueba3.out Test\TestsPriViejos\Salidas\prueba3.sal
fc Test\TestsPriViejos\prueba4.out Test\TestsPriViejos\Salidas\prueba4.sal
fc Test\TestsPriViejos\prueba5.out Test\TestsPriViejos\Salidas\prueba5.sal
fc Test\TestsPriViejos\prueba6.out Test\TestsPriViejos\Salidas\prueba6.sal
fc Test\TestsPriViejos\prueba8.out Test\TestsPriViejos\Salidas\prueba8.sal
fc Test\TestsPriViejos\prueba9.out Test\TestsPriViejos\Salidas\prueba9.sal
fc Test\TestsPriViejos\prueba10.out Test\TestsPriViejos\Salidas\prueba10.sal
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba1_abb.out Test\TestsPriViejos\Salidas\prueba1_abb.txt
fc Test\TestsPriViejos\prueba1_cola.out Test\TestsPriViejos\Salidas\prueba1_cola.txt
fc Test\TestsPriViejos\prueba1_pila.out Test\TestsPriViejos\Salidas\prueba1_pila.txt
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba3_abb.out Test\TestsPriViejos\Salidas\prueba3_abb.txt
fc Test\TestsPriViejos\prueba3_cola.out Test\TestsPriViejos\Salidas\prueba3_cola.txt
fc Test\TestsPriViejos\prueba3_pila.out Test\TestsPriViejos\Salidas\prueba3_pila.txt
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba4_abb.out Test\TestsPriViejos\Salidas\prueba4_abb.txt
fc Test\TestsPriViejos\prueba4_cola.out Test\TestsPriViejos\Salidas\prueba4_cola.txt
fc Test\TestsPriViejos\prueba4_pila.out Test\TestsPriViejos\Salidas\prueba4_pila.txt
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba5_abb.out Test\TestsPriViejos\Salidas\prueba5_abb.txt
fc Test\TestsPriViejos\prueba5_cola.out Test\TestsPriViejos\Salidas\prueba5_cola.txt
fc Test\TestsPriViejos\prueba5_pila.out Test\TestsPriViejos\Salidas\prueba5_pila.txt
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba6_abb.out Test\TestsPriViejos\Salidas\prueba6_abb.txt
fc Test\TestsPriViejos\prueba6_cola.out Test\TestsPriViejos\Salidas\prueba6_cola.txt
fc Test\TestsPriViejos\prueba6_pila.out Test\TestsPriViejos\Salidas\prueba6_pila.txt
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba8_abb.out Test\TestsPriViejos\Salidas\prueba8_abb.txt
fc Test\TestsPriViejos\prueba8_cola.out Test\TestsPriViejos\Salidas\prueba8_cola.txt
fc Test\TestsPriViejos\prueba8_pila.out Test\TestsPriViejos\Salidas\prueba8_pila.txt
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba9_abb.out Test\TestsPriViejos\Salidas\prueba9_abb.txt
fc Test\TestsPriViejos\prueba9_cola.out Test\TestsPriViejos\Salidas\prueba9_cola.txt
fc Test\TestsPriViejos\prueba9_pila.out Test\TestsPriViejos\Salidas\prueba9_pila.txt
echo [3]********************************************************************************
fc Test\TestsPriViejos\prueba10_abb.out Test\TestsPriViejos\Salidas\prueba10_abb.txt
fc Test\TestsPriViejos\prueba10_cola.out Test\TestsPriViejos\Salidas\prueba10_cola.txt
fc Test\TestsPriViejos\prueba10_pila.out Test\TestsPriViejos\Salidas\prueba10_pila.txt

echo Corriendo DIFF 6. TestsPubViejos
echo [4]********************************************************************************
fc Test\TestsPubViejos\prueba1.out Test\TestsPubViejos\Salidas\prueba1.sal
fc Test\TestsPubViejos\prueba2.out Test\TestsPubViejos\Salidas\prueba2.sal
fc Test\TestsPubViejos\prueba3.out Test\TestsPubViejos\Salidas\prueba3.sal
fc Test\TestsPubViejos\prueba4.out Test\TestsPubViejos\Salidas\prueba4.sal
echo [3]********************************************************************************
fc Test\TestsPubViejos\prueba1_abb.out Test\TestsPubViejos\Salidas\prueba1_abb.txt
fc Test\TestsPubViejos\prueba1_cola.out Test\TestsPubViejos\Salidas\prueba1_cola.txt
fc Test\TestsPubViejos\prueba1_pila.out Test\TestsPubViejos\Salidas\prueba1_pila.txt
echo [3]********************************************************************************
fc Test\TestsPubViejos\prueba2_abb.out Test\TestsPubViejos\Salidas\prueba2_abb.txt
fc Test\TestsPubViejos\prueba2_cola.out Test\TestsPubViejos\Salidas\prueba2_cola.txt
fc Test\TestsPubViejos\prueba2_pila.out Test\TestsPubViejos\Salidas\prueba2_pila.txt
echo [3]********************************************************************************
fc Test\TestsPubViejos\prueba3_abb.out Test\TestsPubViejos\Salidas\prueba3_abb.txt
fc Test\TestsPubViejos\prueba3_cola.out Test\TestsPubViejos\Salidas\prueba3_cola.txt
fc Test\TestsPubViejos\prueba3_pila.out Test\TestsPubViejos\Salidas\prueba3_pila.txt
echo [3]********************************************************************************
fc Test\TestsPubViejos\prueba4_abb.out Test\TestsPubViejos\Salidas\prueba4_abb.txt
fc Test\TestsPubViejos\prueba4_cola.out Test\TestsPubViejos\Salidas\prueba4_cola.txt
fc Test\TestsPubViejos\prueba4_pila.out Test\TestsPubViejos\Salidas\prueba4_pila.txt



echo Corriendo DIFF 7. TestPub
echo [2]********************************************************************************
fc Test\TestPub\prueba1.out Test\TestPub\Salidas\prueba1.sal
fc Test\TestPub\prueba8.out Test\TestGonza\Salidas\prueba8.sal
echo [12]********************************************************************************
fc Test\TestPub\prueba1_1_abb.out Test\TestPub\Salidas\prueba1_1_abb.txt
fc Test\TestPub\prueba1_1_cola.out Test\TestPub\Salidas\prueba1_1_cola.txt
fc Test\TestPub\prueba1_1_pila.out Test\TestPub\Salidas\prueba1_1_pila.txt
fc Test\TestPub\prueba1_2_abb.out Test\TestPub\Salidas\prueba1_2_abb.txt
fc Test\TestPub\prueba1_2_cola.out Test\TestPub\Salidas\prueba1_2_cola.txt
fc Test\TestPub\prueba1_2_pila.out Test\TestPub\Salidas\prueba1_2_pila.txt
fc Test\TestPub\prueba8_1_abb.out Test\TestPub\Salidas\prueba8_1_abb.txt
fc Test\TestPub\prueba8_1_cola.out Test\TestPub\Salidas\prueba8_1_cola.txt
fc Test\TestPub\prueba8_1_pila.out Test\TestPub\Salidas\prueba8_1_pila.txt
fc Test\TestPub\prueba8_2_abb.out Test\TestPub\Salidas\prueba8_2_abb.txt
fc Test\TestPub\prueba8_2_cola.out Test\TestPub\Salidas\prueba8_2_cola.txt
fc Test\TestPub\prueba8_2_pila.out Test\TestPub\Salidas\prueba8_2_pila.txt


echo FIN
