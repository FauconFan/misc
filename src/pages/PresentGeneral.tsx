import {
	IonBackButton,
	IonButtons,
	IonContent,
	IonHeader,
	IonPage,
	IonTitle,
	IonToolbar,
	IonList,
	IonItem,
	IonLabel
} from '@ionic/react';
import React from 'react';

const PresentGeneral: React.FC = () => {
	return (
	  <IonPage>
		<IonHeader>
		  <IonToolbar>
			<IonButtons slot="start">
				<IonBackButton defaultHref="/home" />
			</IonButtons>
			<IonTitle>Présentation de la liste</IonTitle>
		  </IonToolbar>
		</IonHeader>
		<IonContent className="ion-padding">

			<IonList>
				<IonItem routerLink='/present/restreint'>
					<IonLabel>
					<h2>Pôle restreint</h2>
					</IonLabel>
				</IonItem>
			</IonList>

		</IonContent>
	  </IonPage>
	);
};
export default PresentGeneral;
