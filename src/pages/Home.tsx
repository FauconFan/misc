import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonCard,
  IonButton,
  IonRefresher,
  IonRefresherContent,
  IonText,
  IonToggle} from '@ionic/react';
import React from 'react';
import { RouteComponentProps } from "react-router-dom";
import { CallNumber } from '@ionic-native/call-number/ngx';

import errorPage from '../modules/errorPage';
import getData from '../modules/getData';
import objToStrMap from '../modules/objToStrMap';

const namesOfIndex : string[] = [
  "Les allos shotguns",
  "Les allos éphémères",
  "Les allos funs",
  "Les allos bouffe",
  "Les allos force"
];

function callThisNumber(number : string) {
  (new CallNumber()).callNumber(number, true);
}

function genAlloDisplay(allo : any) {
  let contentButton = "Appeler (le " + allo.numero + ")";

  if (allo.prix > 0) {
    contentButton += " - " + allo.prix.toString() + " €";
  }

  return (
    <div key={allo.name}>
      <h2>{allo.name}</h2>
      <p>{allo.description}</p>
      <IonButton expand="full" onClick={function() {callThisNumber(allo.numero)}}>{contentButton}</IonButton>
    </div>
  );
}

function genAlloDomainDisplay(_alloDomain : any, index : number) {
  let names_allos = [];
  for (let key in _alloDomain) {
    names_allos.push(key);
  }
  let key = "_alloDomain" + index.toString();

  let alloDomain = objToStrMap(_alloDomain);

  let pahtToDomainPhoto = "assets/images/allo_" + index.toString() + ".jpg";

  return (
    <div key={key}>
      <h1 className="ion-text-center">{namesOfIndex[index]}</h1>
      <IonCard>
        <img src={pahtToDomainPhoto} alt=""></img>
      </IonCard>
      {names_allos.map((allo) => {
        return genAlloDisplay(alloDomain.get(allo));
      })}
    </div>
  );
}

function switchDarkMode(def: boolean = false) {
  const _el = document.querySelector('#root');
  const el = _el as HTMLInputElement;
  if (def || el.style.getPropertyValue('--ion-background-color') != "black") {
    el.style.setProperty('--ion-background-color', 'black');
    el.style.setProperty('--ion-text-color', 'white');
  }
  else {
    el.style.setProperty('--ion-background-color', 'white');
    el.style.setProperty('--ion-text-color', 'black');
  }
}

const Home: React.FC<RouteComponentProps> = () => {
  let _data = getData();
  if (_data == undefined) {
    return (errorPage());
  }

  switchDarkMode(true);

  let data = _data as Map<string, any>;

  return (
    <IonPage>
      <IonHeader>
        <IonToolbar>
          <IonTitle>
            La Ker des Étoiles
          </IonTitle>
        </IonToolbar>
      </IonHeader>
      <IonContent className="ion-padding">
          
        <IonRefresher slot="fixed" onIonRefresh={() => {window.location.reload()}}>
          <IonRefresherContent pullingIcon="arrow-dropdown" pullingText="Tirer vers le bas pour mettre à jour" refreshingText="Mise à jour">
          </IonRefresherContent>
        </IonRefresher>

        <IonCard>
          <img src="assets/images/background_home.jpg" alt=""></img>
        </IonCard>

      <IonText>
        <div>
          <p>Bonjour à tous.</p>
          <p>Nous avons le plaisir de vous présenter notre application afin de pouvoir nous appeler sans avoir à chercher notre numéro à chaque fois 😄.</p>
          <p>Nous vous invitons à choisir votre allo. Vous pouvez appuyez sur le bouton 'Appeler le 0...', cela appellera directement le numéro.</p>
          <p>Pour le paiement des allos (si il y a), cela se fera sur Lydia à réception de la livraison.</p>
          <h2>Notes sur l'application</h2>
          <p>Si vous avez ouvert l'application depuis longtemps (plus de 15 min), vous avez la possibilité de recharger les numéros de téléphone en slidant l'application vers le bas (de la même manière qu'une page web).</p>
        </div>
      </IonText>

        <IonButton color="secondary" expand="full" onClick={() => {switchDarkMode();}}>Switch Dark Mode</IonButton>
  
        {
          data.get('allos').map((alloDomain : any, index : number) => {
            return genAlloDomainDisplay(alloDomain, index);
          })
        }

      </IonContent>
    </IonPage>
  );
};

export default Home;
