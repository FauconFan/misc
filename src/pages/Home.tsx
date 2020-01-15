import {
  IonContent,
  IonHeader,
  IonPage,
  IonTitle,
  IonToolbar,
  IonList,
  IonItem,
  IonLabel,
  IonCard,
  IonButton,
  IonRefresher,
  IonRefresherContent} from '@ionic/react';
import React from 'react';
import { RouteComponentProps } from "react-router-dom";
import { CallNumber } from '@ionic-native/call-number/ngx';

import errorPage from '../modules/errorPage';
import getData from '../modules/getData';
import objToStrMap from '../modules/objToStrMap';

function callThisNumber(number : string) {
  (new CallNumber()).callNumber(number, true);
}

function genAlloDisplay(allo : any) {
  return (
    <div key={allo.name}>
      <h2>{allo.name}</h2>
      <p>{allo.description}</p>
      <IonButton expand="full" onClick={function(e) {callThisNumber(allo.numero)}}>Appeler (le {allo.numero})</IonButton>
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
      <IonCard>
        <img src={pahtToDomainPhoto} alt=""></img>
      </IonCard>
      {names_allos.map((allo) => {
        return genAlloDisplay(alloDomain.get(allo));
      })}
    </div>
  );
}

const Home: React.FC<RouteComponentProps> = (props) => {
  let _data = getData();
  if (_data == undefined) {
    return (errorPage());
  }

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

        <img src="assets/images/background_home.jpg" alt=""></img>

        <div>
          <p>Bonjour à tous.</p>
          <p>Nous avons le plaisir de vous présenter notre application afin de pouvoir nous appeler sans avoir à chercher notre numéro à chaque fois 😄.</p>
          <p>Nous vous invitons à choisir votre allo. Vous pouvez appuyez sur le bouton 'Appeler le +33...', cela appellera directement le numéro.</p>
          <p>Si vous avez ouvert l'application depuis longtemps (plus de 15 min), vous avez la possibilité de recharger les numéros de téléphone en slidant l'application vers le bas (de la même manière qu'une page web).</p>
        </div>
          
        <IonRefresher slot="fixed" onIonRefresh={() => {window.location.reload()}}>
          <IonRefresherContent pullingIcon="arrow-dropdown" pullingText="Tirer vers le bas pour mettre à jour" refreshingText="Mise à jour">
          </IonRefresherContent>
        </IonRefresher>
  
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
