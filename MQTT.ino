void initMQTT() 
{
  MQTT.setServer(BROKER_MQTT, BROKER_PORT);
  MQTT.setCallback(mqtt_callback); 
}


void mqtt_callback(char* topic, byte* payload, unsigned int length){
  String msg;
    for(int i = 0; i < length; i++) 
    {
       char c = (char)payload[i];
       msg += c;
    } 

    if (msg == "1"){// Vermelho
      digitalWrite(portRed, HIGH);
      digitalWrite(portGreen, LOW);
      digitalWrite(portBlue, LOW);
    }else if (msg == "2"){// Verde
      digitalWrite(portRed, LOW);
      digitalWrite(portGreen, HIGH);
      digitalWrite(portBlue, LOW);
    }else if (msg == "3"){// Azul
      digitalWrite(portRed, LOW);
      digitalWrite(portGreen, LOW);
      digitalWrite(portBlue, HIGH);
    }else if (msg == "4"){// Roxo
      digitalWrite(portRed, HIGH);
      digitalWrite(portGreen, LOW);
      digitalWrite(portBlue, HIGH);
    }else if (msg == "5"){// Marron
      digitalWrite(portRed, HIGH);
      digitalWrite(portGreen, HIGH);
      digitalWrite(portBlue, LOW);
    }else if (msg == "6"){// Ciano
      digitalWrite(portRed, LOW);
      digitalWrite(portGreen, HIGH);
      digitalWrite(portBlue, HIGH);
    }else if (msg == "restart"){
      ESP.reset();
    }

    Serial.print("Mensagem Recebida: ");
    Serial.println(msg);
}
