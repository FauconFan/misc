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
	'nom' : 'restreint',
	'names' : ['Augustin Crépin', 'Suzanne Guitton', 'Emma Cariou', 'Paul Marrand', 'Maelle Nicolas'],
	'description' : "C'est l'organe central de la liste, le chef de file de cette formidable formation : le Bureau Restreint! Ils sont beaux, compétents et déterminés pour bien mener la vie étudiante du campus!"
});

mapInformations.set('anim', {
	'nom' : 'Pôle Anim',
	'names' : ['Alexandre Morvan', 'Amandine Hervy', 'Hazem Benslimane', 'Niels Haëntjens'],
	'description' : "Ce corps d'élite en organisation d'événements a été entraîné par les plus grands : le Pôle Anim'! Et ils sont venus à Plouzané pour vous préparer des soirées inoubliables!"
});

mapInformations.set('inte', {
	'nom' : 'Pôle Inté',
	'names' : ['Nicolas Sainte-Rose', 'Pierre Gaillard', 'Kamil Mahmal', 'Maxence Nesme', 'Corentin Herman'],
	'description' : "Ces valeureux organisateurs de gros événements sont responsables de mettre au point un cursus sans faille pour former la prochaine promotion d'Atlantes : la méthode Pôle Inté'!"
});

mapInformations.set('bar', {
	'nom' : 'Pôle Bar',
	'names' : ['Victor Macé', 'Lucie Lavigne', 'Louis Klein', 'Armand Douce', 'Hugo Ssi Yan Kai'],
	'description' : "Vague à l'âme, problèmes de coeur ou autres faiblesses de mental? Une équipe de choc est là pour vous accueillir et vous réconforter au bar du foyer : le Pôle Bar!"
});

mapInformations.set('relex', {
	'nom' : 'Pôle Relex',
	'names' : ['Ghislain Lizée', 'Agathe Fernandes', 'Mattéo Chevallier', 'Marie Dubost'],
	'description' : "Cette fine équipe de chercheurs de trésors vous fera profiter de ses trouvailles, résultats d'âpres recherches et d'aventures palpitantes! Elle est connue sous le nom de Pôle Relex!"
});

mapInformations.set('com', {
	'nom' : 'Pôle Com',
	'names' : ['Nicolas Dieryck', 'Emile Brouard', 'Théo Tembou', 'Corentin Hubert', 'Valéry Boire'],
	'description' : "Hérauts de la liste, portes-parole de la pensée commune des listeux... Vous les entendez parler souvent! Ils tiennent les Atlantes au courants des différents événements de la vie étudiante! Tendez l'oreille et attendez d'entendre le Pôle Com'!"
});

mapInformations.set('fip', {
	'nom' : 'Respo\'FIP',
	'names' : ['Tanh Huy Le'],
	'description' : "D'anciennes légendes parlent d'un peuple nomade, connu pour être soudé, et dont les talents de chorale ont traversé les siècles... Cette tribu à l'éléphant rose est représentée par un de ses éminents membres : le Respo'FIP!"
});

mapInformations.set('bdi', {
	'nom' : 'BDI',
	'names' : ['Rayhane Resgui', 'Ismail El Hadrami', 'Rostom Zitoun', 'Luana Maria Siqueira', 'Sami Rmili'],
	'description' : "A Plouzané on forme l'élite de la Bretagne. Et cette élite est recrutée à l'échelle internationale! Pour représenter ces représentants étrangers, une équipe unique : le BDI!"
});

mapInformations.set('actif', {
	'nom' : 'Membres Actifs',
	'names' : ['Augustin Jaujay', 'Philippine Launay', 'Arthur Doré', 'Florent Thebaut', 'Joseph Priou', 'David Eytan', 'Benjamin Paillette', 'Carla Chevillard', 'Félix Thomann', 'Maëlys Durrieu', 'Marc Tourneux', 'Yasmine Diouri'],
	'description' : "Aucune liste n'est jamais parvenue à la réussite si elle ne pouvait pas compter sur une base de ferventes et dévouées personnes pour l'aider à surmonter tous les défits de la campagne et de son mandat... Elle peut remercier les Membres Actifs!"
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
				<IonBackButton defaultHref="/present" />
			</IonButtons>
			<IonTitle>Présentation du pôle {data['nom']}</IonTitle>
		  </IonToolbar>
		</IonHeader>
		<IonContent className="ion-padding">
			<IonList>
				{data['names'].map((name, index) => {
					return (
						<IonItem key={name}>
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
