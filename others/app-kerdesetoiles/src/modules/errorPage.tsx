import React from 'react';
import {
	IonPage,
	IonHeader,
	IonTitle,
	IonContent,
	IonCard,
	IonToolbar
} from '@ionic/react';

function errorPage() {
	return (
		<IonPage>
			<IonHeader>
				<IonToolbar>
					<IonTitle>Erreur Loading page</IonTitle>
				</IonToolbar>
			</IonHeader>
			<IonContent className="ion-padding">
				<IonCard>
					We're sorry to tell you the application is not able to load informations.
				</IonCard>
			</IonContent>
		</IonPage>
	);
}

export default errorPage;
