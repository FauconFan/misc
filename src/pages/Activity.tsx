import {
	IonBackButton,
	IonButtons,
	IonContent,
	IonHeader,
	IonPage,
	IonTitle,
	IonToolbar
  } from '@ionic/react';
  import React from 'react';
  
  const Activity: React.FC = () => {
	return (
	  <IonPage>
		<IonHeader>
		  <IonToolbar>
			<IonButtons slot="start">
				<IonBackButton defaultHref="/home" />
			</IonButtons>
			<IonTitle>Activités sur le campus</IonTitle>
		  </IonToolbar>
		</IonHeader>
		<IonContent className="ion-padding">

		</IonContent>
	  </IonPage>
	);
  };
  export default Activity;
  
  