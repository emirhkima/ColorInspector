void demarrage(){
	displayCenteredBigTextLine(6,"Bienvenue");
	sleep(2000);
	eraseDisplay();
	drawBmpfile(0,127,"Awake");
	sleep(2000);
}

task main()
{
	int x;

	SensorType[S1]=sensorEV3_Touch;
	SensorType[S2]=sensorEV3_Color;
	setSensorMode(S2,modeEV3Color_Color);
	SensorType[S3]=sensorSoundDB;
	setSoundVolume(100);
	while (true)/*numéro 1*/{
		
		if(getButtonPress(buttonRight)==1)/*Si la première touche du mot de passe est correcte*/{
		sleep(300);
		while(true)/*numéro 2*/{
			if(getButtonPress(buttonLeft)==1)/*Si le mot de passe est correct*/{
				
				sleep(300);
				demarrage();
				eraseDisplay(); /*Efface tout le contenu affiché sur l'écran avant le démarrage de l'application*/
				
				/*Tant que les capteurs ne sont pas pointés vers une couleur*/
				while(SensorValue[S1]==0 && SensorValue[S3]<10)
				{
					sleep(300);
					displayCenteredTextLine(5,"Allez-y !"); /*Un message est affiché pour les personnes daltoniennes*/
					playSoundFile("Instruction.rsf"); /*Une piste audio contenant les instructions est jouée pour les personnes non-voyantes*/
					sleep(300);
				}

				while (true){
					while(SensorValue[S1]==1 || SensorValue[S3]>10) /*Tant que les capteurs détectent une couleur*/
					{
						sleep(300);
						clearSounds(); /*Toute piste audio est interrompue*/
						eraseDisplay(); /*Efface tout le contenu affiché sur l'écran*/
						sleep(300);
						x=getColorName(S2); /*La variable x contient le nom de la couleur détectée*/

						if(x==0) /*Si aucune couleur n'est détectée*/
						{
							displayCenteredTextLine(6,"Aucune couleur"); /*Affichage d'une message "Aucune couleur*/
							playSoundFile("Aucune couleur.rsf"); /*Lecture d'une piste audio qui prévient de la détection d'aucune couleur par les capteurs*/
						}

						if(x==1) /*Si le noir est détectée*/
						{
							displayCenteredTextLine(6,"Noir"); /*On affiche "Noir" pour les personnes daltoniennes*/
							playSoundFile("noir.rsf"); /*Lecture de la piste audio correspondante à la couleur détectée*/
							moveMotorTarget(motorA,30,75); /*Rotation du disque vers le texte braille correspondant à la couleur détectée*/
							waitUntilMotorStop(motorA); /*Attend la fin de la rotation du moteur avant de continuer*/
							sleep(3000); /*Attend 3 secondes après la fin de la rotation du disque pour que la personne puisse lire le texte*/
							moveMotorTarget(motorA,330,75);
						}

						if(x==2) /*Si la couleur bleue est détectée*/
						{
							displayCenteredTextLine(6,"Bleu"); /*On affiche "Bleu" pour les personnes daltoniennes*/
							playSoundFile("bleu.rsf"); /*Lecture de la piste audio correspondante à la couleur détectée*/
							moveMotorTarget(motorA,90,75); /*Rotation du disque vers le texte braille correspondant à la couleur détectée*/
							waitUntilMotorStop(motorA); /*Attend la fin de la rotation du moteur avant de continuer*/
							sleep(3000); /*Attend 3 secondes après la fin de la rotation du disque pour que la personne puisse lire le texte*/
							moveMotorTarget(motorA,270,75); /*Reset du disque*/
						}

						if(x==3) /*Si la couleur verte est détectée*/
						{
							displayCenteredTextLine(6,"Vert"); /*On affiche "Vert" pour les personnes daltoniennes*/
							playSoundFile("vert.rsf"); /*Lecture de la piste audio correspondante à la couleur détectée*/
							moveMotorTarget(motorA,150,75); /*Rotation du disque vers le texte braille correspondant à la couleur détectée*/
							waitUntilMotorStop(motorA); /*Attend la fin de la rotation du moteur avant de continuer*/
							sleep(3000); /*Attend 3 secondes après la fin de la rotation du disque pour que la personne puisse lire le texte*/
							moveMotorTarget(motorA,230,75); /*Reset du disque*/
						}

						if(x==4) /*Si la couleur jaune est détectée*/
						{
							displayCenteredTextLine(6,"Jaune"); /*On affiche "Jaune" pour les personnes daltoniennes*/
							playSoundFile("jaune.rsf"); /*Lecture de la piste audio correspondante à la couleur détectée*/
							moveMotorTarget(motorA,210,75); /*Rotation du disque vers le texte braille correspondant à la couleur détectée*/
							waitUntilMotorStop(motorA); /*Attend la fin de la rotation du moteur avant de continuer*/
							sleep(3000); /*Attend 3 secondes après la fin de la rotation du disque pour que la personne puisse lire le texte*/
							moveMotorTarget(motorA,150,75); /*Reset du disque*/
						}

						if(x==5) /*Si la couleur rouge est détectée*/
						{
							displayCenteredTextLine(6,"Rouge"); /*On affiche "Rouge" pour les personnes daltoniennes*/
							playSoundFile("rouge.rsf"); /*Lecture de la piste audio correspondante à la couleur détectée*/
							moveMotorTarget(motorA,270,75); /*Rotation du disque vers le texte braille correspondant à la couleur détectée*/
							waitUntilMotorStop(motorA); /*Attend la fin de la rotation du moteur avant de continuer*/
							sleep(3000); /*Attend 3 secondes après la fin de la rotation du disque pour que la personne puisse lire le texte*/
							moveMotorTarget(motorA,90,75); /*Reset du disque*/
						}

						if(x==6) /*Si le blanc est détecté*/
						{
							displayCenteredTextLine(6,"Blanc"); /*On affiche "Blanc" pour les personnes daltoniennes*/
							playSoundFile("blanc.rsf"); /*Lecture de la piste audio correspondante à la couleur détectée*/
							moveMotorTarget(motorA,340,75); /*Rotation du disque vers le texte braille correspondant à la couleur détectée*/
							waitUntilMotorStop(motorA); /*Attend la fin de la rotation du moteur avant de continuer*/
							sleep(3000); /*Attend 3 secondes après la fin de la rotation du disque pour que la personne puisse lire le texte*/
							moveMotorTarget(motorA,20,75); /*Reset du disque*/
						}

						if(x==7) /*Si la couleur marron est détecté*/
						{
							displayCenteredTextLine(6,"Marron"); /*On affiche "Marron" pour les personnes daltoniennes*/
							playSoundFile("marron.rsf"); /*Lecture de la piste audio correspondante à la couleur détectée*/
							moveMotorTarget(motorA,360,75); /*Rotation du disque vers le texte braille correspondant à la couleur détectée*/
							/*Pas de reset nécessaire parce que le disque ne bouge pas*/
						}
					}
				}
			}
			
			if(getButtonPress(buttonUp)==1 || getButtonPress(buttonDown)==1 || getButtonPress(buttonRight)==1) /*Si la première touche du mot de passe est incorrecte*/
			{
				displayCenteredTextLine(6,"Mot de passe incorrect."); /*Affiche du texte "Mot de passe incorrect"*/
				playSoundFile("Error"); /*Lecture de la piste audio "Error"*/
				sleep(3000);
				stopAllTasks(); /*Shutdown de l'application*/
			}

		}
	}
		
		if(getButtonPress(buttonUp)==1 || getButtonPress(buttonDown)==1 || getButtonPress(buttonLeft)==1) /*Si la deuxième touche du mot de passe est incorrecte*/
		{
			displayCenteredTextLine(6,"Mot de passe incorrect."); /*Affiche du texte "Mot de passe incorrect"*/
			playSoundFile("Error"); /*Lecture de la piste audio "Error"*/
			sleep(3000);
			stopAllTasks(); /*Shutdown de l'application*/
		}
		
	}

}
