import {
	IonBackButton,
	IonButtons,
	IonContent,
	IonHeader,
	IonPage,
	IonTitle,
	IonToolbar,
	IonList,
	IonItem
} from '@ionic/react';
import React from 'react';
import { RouteComponentProps } from 'react-router';

interface PresentPolePageProps extends RouteComponentProps<{
	id: string;
  }> {}

let mapInformations : Map<string, {'nom': string, 'names': string[], 'description': string}> = new Map();

mapInformations.set('restreint', {
	'nom' : 'Restreint',
	'names' : ['Augustin Crépin', 'Suzanne Guitton', 'Emma Cariou', 'Paul Marrand', 'Maelle Nicolas'],
	'description' : "C'est le bureau restreint."
});

const PresentPole: React.FC<PresentPolePageProps> = ({match}) => {
	let _data = mapInformations.get(match.params.id)
	if (_data === undefined) {
		return (
			<IonPage>
				<IonHeader>
					<IonTitle>Erreur</IonTitle>
				</IonHeader>
			</IonPage>
		);
	}
	let data = _data as {'nom': string, 'names': string[], 'description': string};

	return (
	  <IonPage>
		<IonHeader>
		  <IonToolbar>
			<IonButtons slot="start">
				<IonBackButton defaultHref="/home" />
			</IonButtons>
			<IonTitle>Présentation du pôle {data['nom']}</IonTitle>
		  </IonToolbar>
		</IonHeader>
		<IonContent className="ion-padding">
			<IonList>
				{data['names'].map((name, index) => {
					return (
						<IonItem>
							<h3>{name}</h3>
						</IonItem>
					);
				})}
			</IonList>
			<div>{data['description']}</div>
		</IonContent>
	  </IonPage>
	);
};
export default PresentPole;
