import {
	IonBackButton,
	IonButtons,
	IonContent,
	IonHeader,
	IonPage,
	IonTitle,
	IonToolbar,
	IonCard,
	IonList,
	IonItem,
	IonLabel
  } from '@ionic/react';
  import React from 'react';

const AlloGeneral: React.FC = () => {
	return (
		<IonPage>
		<IonHeader>
			<IonToolbar>
			<IonButtons slot="start">
				<IonBackButton defaultHref="/" />
			</IonButtons>
			<IonTitle>Les Allôs</IonTitle>
			</IonToolbar>
		</IonHeader>
		<IonContent className="ion-padding">

			<IonCard>
				<img src="assets/images/background_phone.png" alt=""></img>
				<p>La grosse description du fonctionnement des allos</p>
			</IonCard>

			<IonList>
				<IonItem routerLink='/allos/alloforce'>
					<IonLabel>
					<h2>AlloForce</h2>
					</IonLabel>
				</IonItem>
			</IonList>

		</IonContent>
		</IonPage>
	);
};

export default AlloGeneral;