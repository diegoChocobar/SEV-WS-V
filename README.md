# SEV-WS-V
Este proyecto parte de la base que tenemos en SEV_Tension, lo que moficamos es que toda la comunicacion se realiza mediante WebSocket.

Inicio de Proyecto: 14-12-2021

Version: 0.1
    Esta version contiene de base el soft anterior (comunicacion por HTTP->POST). 

Version: 0.2 --> 15-12-2021
    En esta version se encuentra funcionando:
     * Punto WiFi maesto.
     * Respuesta Ckeck Funcionamineto.
     * Envio de datos a traves de WebSocket hacia la pagina web.

Version 0.5 --> 03-05-2022
    En esta version trabajamos en:
     * Mejoramiento en la respuesta Check Funcionamiento.
     * Al entrar en modo Hold enviamos el dato de la tension.

Version 0.6 --> 03-05-2022
    En esta version trabajamos en:
     * Mejora en el vision de numeros en display.
     * Calibración desactivada.
     * Cambio en string Envio de datos.

Version 0.61 --> 04-05-2022
    En esta version trabajamos en:
     * Cambio en string Envio de datos.

Version 0.7 --> 13-09-2022
    En esta version trabajamos en:
     * Envio de Hold por websockets

Version 0.8 --> 19-09-2022
    En esta version trabajamos en:
     * Implementacion de funcion de disparo

Version 0.9 --> 23-09-2022
    En esta version trabajamos en:
      * Reemplazamos la Funcion HoldSet por Hold, ahora recibimos por websocket la orden para entrar en modo Hold
      * La calibracion esta desactivada

Version 1.0 --> 27-12-2022
    En esta version trabajamos en:
      * Limpiamos el codigo:
            - Se elimino todo lo referido a Disparo
            - Se eliminaron variable no utilizadas
      * La calibracion esta desactivada

Version 2.0 --> 26-01-2023
    En esta version trabajamos en:
     * Crear codigo para que la señal sea tratada con array y mejoramos asi el calculo
     * Todas las funciones fueron adaptadas para que funcionen.
     * Agregamos un panel de visualizacion para la calibracion
     * La calibracion se encuentra desactivada