#include <SPI.h>
#include <SD.h>
#define CS 4
File myFile;

void setup() {
  Serial.begin(115200);
  if (!SD.begin(CS)) {
  Serial.println("SD Card Tidak Terdeteksi!");
  while (1);
  }
  Serial.println("SD Card Berhasil Terdeteksi.!");
}

void loop(){
kirimdata();
delay(5000);
bacadata();
delay(5000);
}
  
void kirimdata() {
  //KIRIM DATA KE SD CARD
    int datarandom=random(0,100);
    int datarandom2=random(0,100);
    
    myFile = SD.open("data.txt", FILE_WRITE);
    if (myFile) {
      Serial.println("Kirim Data ke SD Card");
      myFile.print("DATA :"); myFile.print(datarandom); 
      myFile.print(" | DATA2 :"); myFile.print(datarandom2); 
      myFile.println();
      myFile.close();
      Serial.println("Kirim Sukses.!");
      } else {
      // if the file didn't open, print an error:
      Serial.println("error opening data.txt");
      }
  }

  void bacadata(){
    myFile = SD.open("data.txt");
    if (myFile) {
      Serial.println("data.txt:");
      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());
      }
      // close the file:
      myFile.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("error opening data.txt");
    }
  }
