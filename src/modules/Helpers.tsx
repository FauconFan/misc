import React from 'react';
import {
	IonPage,
	IonHeader,
	IonTitle
} from '@ionic/react';

export function errorPage(_error: any) {
	return (
		<IonPage>
			<IonHeader>
				<IonTitle>Erreur</IonTitle>
			</IonHeader>
		</IonPage>
	);
}