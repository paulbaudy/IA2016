----------------------------------------
-          MEMBRES DE L'EQUIPE         -
----------------------------------------

BAUDY Paul  - BAUP17019504
COCQ Elodie - COCE16529404


-----------------------------------------
-	FONCTIONNALITES AJOUTEES	-
-----------------------------------------

>>> 3.2 : L'agent ajout� est une serveuse du saloon qui tente de r�cup�rer les p�pites de Bob.

>>> 3.4.1 : Une interface graphique 
> R�alis�e avec Qt. Elle affiche l'�tat de d�part mais aussi celui tout au long de l'ex�cution.
> Elle permet surtout de modifier l'ensemble des param�tres des agents:
On peut d�finir de nombreuses donn�es comme l'�tat de d�part de chaque agent (dans Options), mais aussi 
les attributs de chaque personnage, comme le niveau de fatigue, le nombre de p�pites, etc.
> Les messages �chang�s ne sont plus sur console mais bien int�gr�s � l'interface
graphique, avec le nom des agents en couleur.

>>> 3.4.2 : Multi-threading
> Parall�lisation des updates des agents gr�ce aux threads : l'affichage du texte n'est plus forc�ment
dans le m�me ordre mais cela rajoute du r�alisme.

>>> Autres ajouts :
> Carte du monde : affichage des localisations des agents
> Ex�cution Step-By-Step ou Automatique : dans les Options, il est possible de d�finir le nombre
d'it�rations souhait�es pour l'application. Il est aussi possible de l'ex�cuter en mode pas � pas,
pour pouvoir suivre plus facilement ce qu'il se passe. Attention toutefois, l'horloge du programme 
n'est pas mis en pause: si on attend trop longtemps pour le pas suivant, Bob n'attendra plus Jessica.
> Reset by default : il est possible de r�initialiser l'ensemble des donn�es par d�faut. Cette option 
est disponible dans l'onglet File.



