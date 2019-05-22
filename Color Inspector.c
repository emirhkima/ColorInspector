void demarrage(){
													displayCenteredBigTextLine(6,"Bienvenue");
													sleep(2000);
													eraseDisplay();
													drawBmpfile(0,127,"Awake");
													sleep(2000);}

task main()
{
	int x;

	SensorType[S1]=sensorEV3_Touch;
	SensorType[S2]=sensorEV3_Color;
	setSensorMode(S2,modeEV3Color_Color);
	SensorType[S3]=sensorSoundDB;
	setSoundVolume(100);
	while (true)/*numéro 1*/{
				if(getButtonPress(buttonRight)==1)/*condition bouton droit*/{
							sleep(300);
							while(true)/*numéro 2*/{
										if(getButtonPress(buttonLeft)==1)/*condition bouton gauche*/{
													sleep(300);
													demarrage();
													eraseDisplay();
													while(SensorValue[S1]==0 && SensorValue[S3]<10)
													{
													sleep(300);
													displayCenteredTextLine(5,"Allez-y !");
													playSoundFile("Instruction.rsf");
													sleep(300);
													}

													while (true)/*numéro 3*/{
																while(SensorValue[S1]==1 || SensorValue[S3]>10)
																{
																		sleep(300);
																		clearSounds();
																		eraseDisplay();
																		sleep(300);
																		x=getColorName(S2);

																		if(x==0)
																		{
																				displayCenteredTextLine(6,"Aucune couleur");
																				playSoundFile("Aucune couleur.rsf");}

																		if(x==1)
																		{
																				displayCenteredTextLine(6,"Noir");
																				playSoundFile("noir.rsf");
																				moveMotorTarget(motorA,30,75);
																				waitUntilMotorStop(motorA);
																				sleep(3000);
																				moveMotorTarget(motorA,330,75);}

																		if(x==2)
																		{
																				displayCenteredTextLine(6,"Bleu");
																				playSoundFile("bleu.rsf");
																				moveMotorTarget(motorA,90,75);
																				waitUntilMotorStop(motorA);
																				sleep(3000);
																				moveMotorTarget(motorA,270,75);}

																		if(x==3)
																		{
																				displayCenteredTextLine(6,"Vert");
																				playSoundFile("vert.rsf");
																				moveMotorTarget(motorA,150,75);
																				waitUntilMotorStop(motorA);
																				sleep(3000);
																				moveMotorTarget(motorA,230,75);}

																		if(x==4)
																		{displayCenteredTextLine(6,"Jaune");
																			playSoundFile("jaune.rsf");
																			moveMotorTarget(motorA,210,75);
																			waitUntilMotorStop(motorA);
																			sleep(3000);
																			waitUntilMotorStop(motorA);
																			moveMotorTarget(motorA,150,75);}

																		if(x==5)
																		{
																				displayCenteredTextLine(6,"Rouge");
																				playSoundFile("rouge.rsf");
																				moveMotorTarget(motorA,270,75);
																				waitUntilMotorStop(motorA);
																				sleep(3000);
																				moveMotorTarget(motorA,90,75);}

																		if(x==6)
																		{
																				displayCenteredTextLine(6,"Blanc");
																				playSoundFile("blanc.rsf");
																				moveMotorTarget(motorA,340,75);
																				waitUntilMotorStop(motorA);
																				sleep(3000);
																				resetMotorEncoder(motorA);
																				moveMotorTarget(motorA,20,75);}

																		if(x==7)
																		{
																				displayCenteredTextLine(6,"Marron");
																				playSoundFile("marron.rsf");
																				moveMotorTarget(motorA,360,75);
																				}



															}//fermeture de la condition : capteur S1 appuyé

													}//fermeture du while(true) numéro 3

											}//fermeture de la condition : appuis sur le bouton gauche

											if(getButtonPress(buttonUp)==1 || getButtonPress(buttonDown)==1 || getButtonPress(buttonRight)==1){
													displayCenteredTextLine(6,"Mot de passe incorrect.");
													playSoundFile("Error");
													sleep(3000);
													stopAllTasks();
											}

									}//fermeture du while(true) numéro 2

							}//fermeture de la condition : appuis sur le bouton droit

							if(getButtonPress(buttonUp)==1 || getButtonPress(buttonDown)==1 || getButtonPress(buttonLeft)==1){
													displayCenteredTextLine(6,"Mot de passe incorrect.");
													playSoundFile("Error");
													sleep(3000);
													stopAllTasks();
							}

					}//fermeture du while(true) numéro 1

			}//fermeture task main
