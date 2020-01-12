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
				<IonItem key='restreint' routerLink='/present/restreint'>
					<IonLabel>
					<h2>Bureau restreint</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='anim' routerLink='/present/anim'>
					<IonLabel>
					<h2>Pôle Animation</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='inte' routerLink='/present/inte'>
					<IonLabel>
					<h2>Pôle Intégration</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='bar' routerLink='/present/bar'>
					<IonLabel>
					<h2>Pôle Bar</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='relex' routerLink='/present/relex'>
					<IonLabel>
					<h2>Pôle Relex</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='com' routerLink='/present/com'>
					<IonLabel>
					<h2>Pôle Communication</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='fip' routerLink='/present/fip'>
					<IonLabel>
					<h2>Respo' FIP</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='bdi' routerLink='/present/bdi'>
					<IonLabel>
					<h2>Le BDI</h2>
					</IonLabel>
				</IonItem>
				<IonItem key='actif' routerLink='/present/actif'>
					<IonLabel>
					<h2>Les membres actifs</h2>
					</IonLabel>
				</IonItem>
			</IonList>

		</IonContent>
	  </IonPage>
	);
};
export default PresentGeneral;
