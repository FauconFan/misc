import {
	IonBackButton,
	IonButtons,
	IonContent,
	IonHeader,
	IonPage,
	IonTitle,
	IonToolbar,
	IonButton
} from '@ionic/react';
import React from 'react';
import { RouteComponentProps } from 'react-router';

import { getData } from '../modules/Connection';
import { errorPage } from '../modules/Helpers';

import { CallNumber } from '@ionic-native/call-number/ngx';

// constructor(private callNumber: CallNumber) { }


interface AlloSpecPageProps extends RouteComponentProps<{
	id: string;
  }> {}

let mapInformations : Map<string, {'nom': string, 'description': string}> = new Map();

mapInformations.set('alloforce', {
	'nom' : 'AlloForce',
	'description' : 'Quand quelqu\'un a la flemme pour se lever et prendre un objet, il utilise la force de la liste pour le lui apporter.'
});

const AlloSpec: React.FC<AlloSpecPageProps> = ({match}) => {
	let _data = mapInformations.get(match.params.id)
	if (_data === undefined) {
		return (errorPage(-1));
	}

	let data = _data as {'nom': string, 'description': string};
	
	let dataRemote = getData();
	console.log(dataRemote);

	let callNumber = function (num : string) {
		(new CallNumber()).callNumber(num, true);
	}
	return (
		<IonPage>
		<IonHeader>
			<IonToolbar>
			<IonButtons slot="start">
				<IonBackButton defaultHref="/home" />
			</IonButtons>
			<IonTitle>{data['nom']}</IonTitle>
			</IonToolbar>
		</IonHeader>
		<IonContent className="ion-padding">
			<div>{data['description']}</div>
		</IonContent>
		<IonContent>
			<IonButton onClick={function(e) {callNumber("+33 6 88 18 64 31")}}>
				Appeler
			</IonButton>
		</IonContent>

		
		</IonPage>
	);
};
export default AlloSpec;
