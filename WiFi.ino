

// Connect to WiFi
void wifiConnect(){
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {delay(1000); Serial.println("Connecting...");}
  Serial.println("Connected to the WiFi network");
}

void wifiRequest(){
  HTTPClient http;
  http.begin(apiUrl);
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0) {
    String payload = http.getString();
    Serial.println("API Response:");
    Serial.println(payload);
    wifiExtract(payload);
  } 
  else {
    Serial.print("Error in HTTP request: ");
    Serial.println(httpResponseCode);
  }

  http.end();
}

void wifiExtract(String payload){
    DeserializationError error = deserializeJson(doc, payload);
    if (error) {Serial.print("deserializeJson() failed: "); Serial.println(error.c_str()); return;}

    // Extract specific data
    drinks = (const char*)doc["drinks"][0]["strDrink"] ;
    inst = (const char*)doc["drinks"][0]["strInstructions"];
    Serial.print("drinks: "); Serial.println(drinks);
    Serial.print("instructions: "); Serial.println(inst);

    for(int i=1;i<=15;i++){
      //"ingredient"+ str(i);
      ingredients[i] = (const char*)doc["drinks"][0]["strIngredient" + String(i)];
      quantity[i] = (const char*)doc["drinks"][0]["strMeasure" + String(i)];
    }
} 



